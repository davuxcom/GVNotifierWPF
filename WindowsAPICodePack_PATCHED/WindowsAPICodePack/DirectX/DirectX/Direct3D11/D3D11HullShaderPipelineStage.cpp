// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11HullShaderPipelineStage.h"

#include "D3D11DepthStencilView.h"
#include "D3D11RenderTargetView.h"
#include "D3D11UnorderedAccessView.h"
#include "D3D11Resource.h"
#include "D3D11Buffer.h"
#include "D3D11SamplerState.h"
#include "D3D11ComputeShader.h"
#include "D3D11ClassInstance.h"
#include "D3D11ShaderResourceView.h"
#include "D3D11DomainShader.h"
#include "D3D11CommandList.h"
#include "D3D11GeometryShader.h"
#include "D3D11HullShader.h"
#include "D3D11InputLayout.h"
#include "D3D11BlendState.h"
#include "D3D11DepthStencilState.h"
#include "D3D11PixelShader.h"
#include "D3D11RasterizerState.h"
#include "D3D11VertexShader.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

ReadOnlyCollection<D3DBuffer^>^ HullShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    vector<ID3D11Buffer*> tempoutConstantBuffers(numBuffers);
    Parent->GetInterface<ID3D11DeviceContext>()->HSGetConstantBuffers(static_cast<UINT>(startSlot), static_cast<UINT>(numBuffers), &tempoutConstantBuffers[0]);
        
    return CommonUtils::GetCollection<D3DBuffer, ID3D11Buffer>(numBuffers, tempoutConstantBuffers);
}

ReadOnlyCollection<SamplerState^>^ HullShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    vector<ID3D11SamplerState*> tempoutSamplers(numSamplers);

    Parent->GetInterface<ID3D11DeviceContext>()->HSGetSamplers(static_cast<UINT>(startSlot), static_cast<UINT>(numSamplers), &tempoutSamplers[0]);

    return CommonUtils::GetCollection<SamplerState, ID3D11SamplerState>(numSamplers, tempoutSamplers);
}

HullShader^ HullShaderPipelineStage::GetShader(UInt32 numClassInstances, [System::Runtime::InteropServices::Out] ReadOnlyCollection<ClassInstance^>^ %outClassInstances)
{
    ID3D11HullShader* tempShader = NULL;

    UINT tempoutNumClassInstances = static_cast<UINT>(numClassInstances);
    vector<ID3D11ClassInstance*> tempoutClassInstances(numClassInstances); 

    Parent->GetInterface<ID3D11DeviceContext>()->HSGetShader(
        &tempShader, 
        numClassInstances == 0 ? NULL : &(tempoutClassInstances[0]), 
        &tempoutNumClassInstances);

    outClassInstances = CommonUtils::GetCollection<ClassInstance, ID3D11ClassInstance>(
        tempoutNumClassInstances, tempoutClassInstances);

    return tempShader == NULL ? nullptr : gcnew HullShader(tempShader);
}


HullShader^ HullShaderPipelineStage::GetShader()
{
    ID3D11HullShader* tempShader = NULL;

    UINT tempoutNumClassInstances = 0;

    Parent->GetInterface<ID3D11DeviceContext>()->HSGetShader(
        &tempShader, 
        NULL, 
        &tempoutNumClassInstances);

    return tempShader == NULL ? nullptr : gcnew HullShader(tempShader);
}

ReadOnlyCollection<ShaderResourceView^>^ HullShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    vector<ID3D11ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->GetInterface<ID3D11DeviceContext>()->HSGetShaderResources(static_cast<UINT>(startSlot), static_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return CommonUtils::GetCollection<ShaderResourceView, ID3D11ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void HullShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{
    vector<ID3D11Buffer*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D11Buffer>(constantBuffers, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->HSSetConstantBuffers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void HullShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    vector<ID3D11SamplerState*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<SamplerState, ID3D11SamplerState>(samplers, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->HSSetSamplers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void HullShaderPipelineStage::SetShader(HullShader^ shader, IEnumerable<ClassInstance^>^ classInstances)
{
    vector<ID3D11ClassInstance*> classInstancesVector;

    UINT count = classInstances == nullptr ? 0 :
        CommonUtils::FillIUnknownsVector<ClassInstance,ID3D11ClassInstance>(classInstances, classInstancesVector);

    Parent->GetInterface<ID3D11DeviceContext>()->HSSetShader(
        shader == nullptr ? NULL : shader->GetInterface<ID3D11HullShader>(), 
        count == 0 ? NULL : &(classInstancesVector[0]), 
        count);
}

void HullShaderPipelineStage::SetShader(HullShader^ shader)
{
    SetShader(shader, nullptr);
}

void HullShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    vector<ID3D11ShaderResourceView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<ShaderResourceView, ID3D11ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->HSSetShaderResources(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

