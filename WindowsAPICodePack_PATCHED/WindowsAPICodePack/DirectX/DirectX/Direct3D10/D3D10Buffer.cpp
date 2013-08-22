// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Buffer.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

BufferDescription D3DBuffer::Description::get()
{
    D3D10_BUFFER_DESC desc = {0};
    GetInterface<ID3D10Buffer>()->GetDesc(&desc);
    
    return BufferDescription(desc);
}

IntPtr D3DBuffer::Map(D3D10::Map type, MapFlag flags)
{
    void* tempoutData;    
    CommonUtils::VerifyResult(GetInterface<ID3D10Buffer>()->Map(static_cast<D3D10_MAP>(type), static_cast<UINT>(flags), &tempoutData));    
    
    return IntPtr(tempoutData);
}

void D3DBuffer::Unmap()
{
    GetInterface<ID3D10Buffer>()->Unmap();
}

