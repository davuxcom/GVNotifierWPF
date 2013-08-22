// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10PixelShaderPipelineStage.h"
#include "D3D10DepthStencilView.h"
#include "D3D10RenderTargetView.h"
#include "D3D10Resource.h"
#include "D3D10Buffer.h"
#include "D3D10SamplerState.h"
#include "D3D10ShaderResourceView.h"
#include "D3D10GeometryShader.h"
#include "D3D10InputLayout.h"
#include "D3D10BlendState.h"
#include "D3D10DepthStencilState.h"
#include "D3D10PixelShader.h"
#include "D3D10RasterizerState.h"
#include "D3D10VertexShader.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

ReadOnlyCollection<D3DBuffer^>^ PixelShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    vector<ID3D10Buffer*> tempoutConstantBuffers(numBuffers);
    Parent->GetInterface<ID3D10Device>()->PSGetConstantBuffers(static_cast<UINT>(startSlot), static_cast<UINT>(numBuffers), &tempoutConstantBuffers[0]);
        
    return CommonUtils::GetCollection<D3DBuffer, ID3D10Buffer>(numBuffers, tempoutConstantBuffers);
}

ReadOnlyCollection<SamplerState^>^ PixelShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    vector<ID3D10SamplerState*> tempoutSamplers(numSamplers);
    Parent->GetInterface<ID3D10Device>()->PSGetSamplers(static_cast<UINT>(startSlot), static_cast<UINT>(numSamplers), &tempoutSamplers[0]);

    return CommonUtils::GetCollection<SamplerState, ID3D10SamplerState>(numSamplers, tempoutSamplers);
}

PixelShader^ PixelShaderPipelineStage::GetShader()
{
    ID3D10PixelShader* tempShader = NULL;

    Parent->GetInterface<ID3D10Device>()->PSGetShader(
        &tempShader);

    return tempShader == NULL ? nullptr : gcnew PixelShader(tempShader);
}

ReadOnlyCollection<ShaderResourceView^>^ PixelShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    vector<ID3D10ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->GetInterface<ID3D10Device>()->PSGetShaderResources(static_cast<UINT>(startSlot), static_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return CommonUtils::GetCollection<ShaderResourceView, ID3D10ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void PixelShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{
    vector<ID3D10Buffer*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D10Buffer>(constantBuffers, itemsVector);

    Parent->GetInterface<ID3D10Device>()->PSSetConstantBuffers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void PixelShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    vector<ID3D10SamplerState*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<SamplerState, ID3D10SamplerState>(samplers, itemsVector);

    Parent->GetInterface<ID3D10Device>()->PSSetSamplers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void PixelShaderPipelineStage::SetShader(PixelShader^ shader)
{
    Parent->GetInterface<ID3D10Device>()->PSSetShader(
        shader == nullptr ? NULL : shader->GetInterface<ID3D10PixelShader>());
}

void PixelShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    vector<ID3D10ShaderResourceView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<ShaderResourceView, ID3D10ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->GetInterface<ID3D10Device>()->PSSetShaderResources(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

