// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Asynchronous.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

void Asynchronous::Begin()
{
    GetInterface<ID3D10Asynchronous>()->Begin();
}

void Asynchronous::End()
{
    GetInterface<ID3D10Asynchronous>()->End();
}

void Asynchronous::GetData(IntPtr data, UInt32 dataSize, AsyncGetDataFlag flags)
{

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Asynchronous>()->GetData(data.ToPointer(), static_cast<UINT>(dataSize), static_cast<UINT>(flags)));
}
UInt32 Asynchronous::GetDataSize()
{
    UINT returnValue = GetInterface<ID3D10Asynchronous>()->GetDataSize();
    return returnValue;
}

