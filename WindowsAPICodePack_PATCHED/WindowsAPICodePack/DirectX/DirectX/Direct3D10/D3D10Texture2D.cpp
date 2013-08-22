// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Texture2D.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Texture2DDescription Texture2D::Description::get()
{
    D3D10_TEXTURE2D_DESC desc = {0};

    GetInterface<ID3D10Texture2D>()->GetDesc(&desc);
    return Texture2DDescription(desc);
}

MappedTexture2D Texture2D::Map(UInt32 subresourceIndex, D3D10::Map type, MapFlag flags)
{
    D3D10_MAPPED_TEXTURE2D texture = {0};
    
    CommonUtils::VerifyResult(GetInterface<ID3D10Texture2D>()->Map(
        subresourceIndex, static_cast<D3D10_MAP>(type), 
        static_cast<UINT>(flags), &texture));
    
    return MappedTexture2D(texture);
}

void Texture2D::Unmap(UInt32 subresourceIndex)
{
    GetInterface<ID3D10Texture2D>()->Unmap(static_cast<UINT>(subresourceIndex));
}
