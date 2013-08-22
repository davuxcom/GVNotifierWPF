// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10VertexShaderPipelineStage.h"
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

#include <vector>
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

ReadOnlyCollection<D3DBuffer^>^ VertexShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    vector<ID3D10Buffer*> items(numBuffers);

    Parent->GetInterface<ID3D10Device>()->VSGetConstantBuffers(static_cast<UINT>(startSlot), static_cast<UINT>(numBuffers), &(items[0]));

    return CommonUtils::GetCollection<D3DBuffer, ID3D10Buffer>(numBuffers, items);
}

ReadOnlyCollection<SamplerState^>^ VertexShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    vector<ID3D10SamplerState*> samplersVector(numSamplers);
    Parent->GetInterface<ID3D10Device>()->VSGetSamplers(static_cast<UINT>(startSlot), static_cast<UINT>(numSamplers), &samplersVector[0]);

    return CommonUtils::GetCollection<SamplerState, ID3D10SamplerState>(numSamplers, samplersVector);
}

VertexShader^ VertexShaderPipelineStage::GetShader()
{
    ID3D10VertexShader* tempShader = NULL;

    Parent->GetInterface<ID3D10Device>()->VSGetShader(
        &tempShader);

    return tempShader == NULL ? nullptr : gcnew VertexShader(tempShader);
}

ReadOnlyCollection<ShaderResourceView^>^ VertexShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    vector<ID3D10ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->GetInterface<ID3D10Device>()->VSGetShaderResources(static_cast<UINT>(startSlot), static_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return CommonUtils::GetCollection<ShaderResourceView, ID3D10ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void VertexShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{

    vector<ID3D10Buffer*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D10Buffer>(constantBuffers, itemsVector);

    Parent->GetInterface<ID3D10Device>()->VSSetConstantBuffers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void VertexShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    vector<ID3D10SamplerState*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<SamplerState, ID3D10SamplerState>(samplers, itemsVector);

    Parent->GetInterface<ID3D10Device>()->VSSetSamplers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void VertexShaderPipelineStage::SetShader(VertexShader^ vertexShader)
{
    Parent->GetInterface<ID3D10Device>()->VSSetShader(
        vertexShader == nullptr ? NULL : vertexShader->GetInterface<ID3D10VertexShader>());
}

void VertexShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    vector<ID3D10ShaderResourceView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<ShaderResourceView, ID3D10ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->GetInterface<ID3D10Device>()->VSSetShaderResources(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}
