// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "WICBitmapLock.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::WindowsImagingComponent;
using namespace System::Runtime::InteropServices;


IntPtr WICBitmapLock::GetDataPointer([System::Runtime::InteropServices::Out] UInt32 % bufferSize)
{
    BYTE * data = NULL;
    UINT size;
    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmapLock>()->GetDataPointer( &size, &data ) );

    bufferSize = size;

    return IntPtr(data);
}

array<unsigned char>^ WICBitmapLock::CopyData()
{
    BYTE * data = NULL;
    UINT bufferSize;
    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmapLock>()->GetDataPointer( &bufferSize, &data ) );

    if (bufferSize > 0 && data != NULL)
    {
        array<unsigned char>^ pixels = gcnew array<unsigned char>(bufferSize);
        pin_ptr<unsigned char> pixelsPtr = &pixels[0];
        ::memcpy(pixelsPtr, data, bufferSize);

        return pixels;
    }

    return nullptr;

    
}

BitmapSize WICBitmapLock::Size::get()
{
    UINT width;
    UINT height;
    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmapLock>()->GetSize( &width, & height ) );

    return BitmapSize( width, height );
}

Guid WICBitmapLock::PixelFormat::get()
{
    cli::array<unsigned char>^ bytes = gcnew cli::array<unsigned char>(16);
    pin_ptr<unsigned char> guid = &bytes[0];
    
    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmapLock>()->GetPixelFormat((WICPixelFormatGUID*) guid ) );
        
    return System::Guid( bytes );
}

UInt32 WICBitmapLock::Stride::get()
{
    UINT stride;
    CommonUtils::VerifyResult( 
        GetInterface<IWICBitmapLock>()->GetStride(&stride) );

    return stride;
}
