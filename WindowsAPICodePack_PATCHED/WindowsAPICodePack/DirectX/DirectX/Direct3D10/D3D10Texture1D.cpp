// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Texture1D.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Texture1DDescription Texture1D::Description::get()
{
    Texture1DDescription desc;
    pin_ptr<Texture1DDescription> ptr = &desc;

    GetInterface<ID3D10Texture1D>()->GetDesc((D3D10_TEXTURE1D_DESC*)ptr);
    return desc;
}

IntPtr Texture1D::Map(UInt32 subresourceIndex, D3D10::Map type, MapFlag flags)
{
    void* tempoutData = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Texture1D>()->Map(static_cast<UINT>(subresourceIndex), static_cast<D3D10_MAP>(type), static_cast<UINT>(flags), &tempoutData));
    return IntPtr(tempoutData);
}

void Texture1D::Unmap(UInt32 subresourceIndex)
{
    GetInterface<ID3D10Texture1D>()->Unmap(static_cast<UINT>(subresourceIndex));
}

