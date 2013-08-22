// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Include.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;
using namespace msclr::interop;

void Include::Close(IntPtr data)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Include>()->Close(data.ToPointer()));
}

IntPtr Include::Open(IncludeType includeType, String^ fileName, IntPtr parentData, [System::Runtime::InteropServices::Out] UInt32 % bytes)
{
    void* tempoutData = NULL;    
    UINT tempSize;

    IntPtr ptr = Marshal::StringToHGlobalAnsi(fileName);

    try
    {
        CommonUtils::VerifyResult(GetInterface<ID3D10Include>()->Open(
            static_cast<D3D10_INCLUDE_TYPE>(includeType), 
            static_cast<char*>(ptr.ToPointer()), 
            static_cast<LPCVOID>(parentData.ToPointer()), 
            (LPCVOID*)&tempoutData, 
            &tempSize));
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }

    bytes = tempSize;
    return IntPtr(tempoutData);
}

