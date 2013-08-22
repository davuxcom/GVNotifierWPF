// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectConstantBuffer.h"

#include "D3D10Buffer.h"
#include "D3D10ShaderResourceView.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

D3DBuffer^ EffectConstantBuffer::GetConstantBuffer()
{
    ID3D10Buffer* tempoutConstantBuffer = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectConstantBuffer>()->GetConstantBuffer(&tempoutConstantBuffer));
    return tempoutConstantBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutConstantBuffer);
}

ShaderResourceView^ EffectConstantBuffer::GetTextureBuffer()
{
    ID3D10ShaderResourceView* tempoutTextureBuffer = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectConstantBuffer>()->GetTextureBuffer(&tempoutTextureBuffer));
    return tempoutTextureBuffer == NULL ? nullptr : gcnew ShaderResourceView(tempoutTextureBuffer);
}

void EffectConstantBuffer::SetConstantBuffer(D3DBuffer^ constantBuffer)
{

    CommonUtils::CheckNull(constantBuffer, "constantBuffer");

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectConstantBuffer>()->SetConstantBuffer(constantBuffer->GetInterface<ID3D10Buffer>()));
}

void EffectConstantBuffer::SetTextureBuffer(ShaderResourceView^ textureBuffer)
{

    CommonUtils::CheckNull(textureBuffer, "textureBuffer");

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectConstantBuffer>()->SetTextureBuffer(textureBuffer->GetInterface<ID3D10ShaderResourceView>()));
}

