// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "WICBitmap.h"
#include "WICBitmapLock.h"
#include "WICImagingfactory.h"

extern "C"
{
    const GUID GUID_WICPixelFormatDontCare = {0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x00};
}

using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::WindowsImagingComponent;
using namespace System::Runtime::InteropServices;


void WICBitmap::SetResolution( BitmapResolution resolution )
{
    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmap>()->SetResolution(resolution.DpiX, resolution.DpiY) );
}

WICBitmapLock^ WICBitmap::Lock(BitmapRectangle lockRectangle, BitmapLockFlags flags)
{
    pin_ptr<BitmapRectangle> rect = &lockRectangle;
    IWICBitmapLock * lock = NULL;

    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmap>()->Lock((WICRect*) rect, static_cast<DWORD>(flags), &lock));

    return lock ? gcnew WICBitmapLock(lock) : nullptr;
}

void WICBitmap::SaveToFile(ImagingFactory^ imagingFactory, System::Guid containerFormat, System::String^ fileName)
{
    cli::array<unsigned char>^ containerFormatBytes = containerFormat.ToByteArray();
    pin_ptr<unsigned char> containerFormatGuidPtr = &containerFormatBytes[0];

    IWICBitmapEncoder *pEncoder = NULL;
    IWICBitmapFrameEncode *pFrameEncode = NULL;
    IWICStream *pStream = NULL;
    
    IWICImagingFactory* pWICFactory = imagingFactory->GetInterface<IWICImagingFactory>();
    IWICBitmap* bitmap = GetInterface<IWICBitmap>();
    
    try
    {
        unsigned int sc_bitmapWidth, sc_bitmapHeight;
        bitmap->GetSize(&sc_bitmapWidth, &sc_bitmapHeight);

        HRESULT hr = pWICFactory->CreateStream(&pStream);

        WICPixelFormatGUID format = GUID_WICPixelFormatDontCare;
        pin_ptr<const WCHAR> filename = PtrToStringChars(fileName);
        
        CommonUtils::VerifyResult(pStream->InitializeFromFilename(filename, GENERIC_WRITE));

        GUID guid =  *((GUID*)containerFormatGuidPtr);
        CommonUtils::VerifyResult(pWICFactory->CreateEncoder(guid, NULL, &pEncoder));

        CommonUtils::VerifyResult(pEncoder->Initialize(pStream, WICBitmapEncoderNoCache));

        CommonUtils::VerifyResult(pEncoder->CreateNewFrame(&pFrameEncode, NULL));

        CommonUtils::VerifyResult(pFrameEncode->Initialize(NULL));

        CommonUtils::VerifyResult(pFrameEncode->SetSize(sc_bitmapWidth, sc_bitmapHeight));

        CommonUtils::VerifyResult(pFrameEncode->SetPixelFormat(&format));

        CommonUtils::VerifyResult(pFrameEncode->WriteSource(bitmap, NULL));

        CommonUtils::VerifyResult(pFrameEncode->Commit());

        CommonUtils::VerifyResult(pEncoder->Commit());
    }
    finally
    {
        if (pEncoder) 
            pEncoder->Release();

        if (pFrameEncode)
            pFrameEncode->Release();

        if (pStream)
            pStream->Release();
    }
}