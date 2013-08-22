// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Texture3D.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Texture3DDescription Texture3D::Description::get()
{
    Texture3DDescription desc;
    pin_ptr<Texture3DDescription> ptr = &desc;

    GetInterface<ID3D10Texture3D>()->GetDesc((D3D10_TEXTURE3D_DESC*)ptr);
    return desc;
}

MappedTexture3D Texture3D::Map(UInt32 subresourceIndex, D3D10::Map type, MapFlag flags)
{
    D3D10_MAPPED_TEXTURE3D texture = {0};
    CommonUtils::VerifyResult(GetInterface<ID3D10Texture3D>()->Map(
        subresourceIndex, 
        static_cast<D3D10_MAP>(type), 
        static_cast<UINT>(flags), 
        &texture));

    return MappedTexture3D(texture);
}

void Texture3D::Unmap(UInt32 subresourceIndex)
{
    GetInterface<ID3D10Texture3D>()->Unmap(static_cast<UINT>(subresourceIndex));
}
