// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11ComputeShaderPipelineStage.h"

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

ReadOnlyCollection<SamplerState^>^ ComputeShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    vector<ID3D11SamplerState*> tempoutSamplers(numSamplers);
    Parent->GetInterface<ID3D11DeviceContext>()->CSGetSamplers(static_cast<UINT>(startSlot), static_cast<UINT>(numSamplers), &tempoutSamplers[0]);

    return CommonUtils::GetCollection<SamplerState, ID3D11SamplerState>(numSamplers, tempoutSamplers);
}

void ComputeShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    vector<ID3D11SamplerState*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<SamplerState, ID3D11SamplerState>(samplers, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->CSSetSamplers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

ReadOnlyCollection<D3DBuffer^>^ ComputeShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    vector<ID3D11Buffer*> tempoutConstantBuffers(numBuffers);
    Parent->GetInterface<ID3D11DeviceContext>()->CSGetConstantBuffers(static_cast<UINT>(startSlot), static_cast<UINT>(numBuffers), &tempoutConstantBuffers[0]);
        
    return CommonUtils::GetCollection<D3DBuffer, ID3D11Buffer>(numBuffers, tempoutConstantBuffers);
}

void ComputeShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{
    vector<ID3D11Buffer*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D11Buffer>(constantBuffers, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->CSSetConstantBuffers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

ComputeShader^ ComputeShaderPipelineStage::GetShader(UInt32 numClassInstances, [System::Runtime::InteropServices::Out] ReadOnlyCollection<ClassInstance^>^ %outClassInstances)
{
    ID3D11ComputeShader* tempoutComputeShader = NULL;

    UINT tempoutNumClassInstances = static_cast<UINT>(numClassInstances);
    vector<ID3D11ClassInstance*> tempoutClassInstances(numClassInstances); 

    Parent->GetInterface<ID3D11DeviceContext>()->CSGetShader(
        &tempoutComputeShader, 
        tempoutNumClassInstances == 0 ? NULL : &(tempoutClassInstances[0]), 
        &tempoutNumClassInstances
        );

    outClassInstances = CommonUtils::GetCollection<ClassInstance, ID3D11ClassInstance>(tempoutNumClassInstances, tempoutClassInstances);

    return tempoutComputeShader == NULL ? nullptr : gcnew ComputeShader(tempoutComputeShader);
}


ComputeShader^ ComputeShaderPipelineStage::GetShader()
{
    ID3D11ComputeShader* tempoutComputeShader = NULL;

    UINT tempoutNumClassInstances = 0;

    Parent->GetInterface<ID3D11DeviceContext>()->CSGetShader(
        &tempoutComputeShader, 
        NULL,
        &tempoutNumClassInstances
        );

    return tempoutComputeShader == NULL ? nullptr : gcnew ComputeShader(tempoutComputeShader);
}

void ComputeShaderPipelineStage::SetShader(ComputeShader^ shader, IEnumerable<ClassInstance^>^ classInstances)
{
    vector<ID3D11ClassInstance*> classInstancesVector;

    UINT count = classInstances == nullptr ? 0 :
        CommonUtils::FillIUnknownsVector<ClassInstance,ID3D11ClassInstance>(classInstances, classInstancesVector);

    Parent->GetInterface<ID3D11DeviceContext>()->CSSetShader(
        shader == nullptr ? NULL : shader->GetInterface<ID3D11ComputeShader>(), 
        count == 0 ? NULL : &(classInstancesVector[0]), 
        count);
}

void ComputeShaderPipelineStage::SetShader(ComputeShader^ shader)
{
    SetShader(shader, nullptr);
}

ReadOnlyCollection<ShaderResourceView^>^ ComputeShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    vector<ID3D11ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->GetInterface<ID3D11DeviceContext>()->CSGetShaderResources(static_cast<UINT>(startSlot), static_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return CommonUtils::GetCollection<ShaderResourceView, ID3D11ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void ComputeShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    vector<ID3D11ShaderResourceView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<ShaderResourceView, ID3D11ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->CSSetShaderResources(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

ReadOnlyCollection<UnorderedAccessView^>^ ComputeShaderPipelineStage::GetUnorderedAccessViews(UInt32 startSlot, UInt32 numUAVs)
{
    vector<ID3D11UnorderedAccessView*> views(numUAVs);

    Parent->GetInterface<ID3D11DeviceContext>()->CSGetUnorderedAccessViews(
        static_cast<UINT>(startSlot), static_cast<UINT>(numUAVs), &views[0]);
    
    return CommonUtils::GetCollection<UnorderedAccessView, ID3D11UnorderedAccessView>(numUAVs, views);
}

void ComputeShaderPipelineStage::SetUnorderedAccessViews(UInt32 startSlot, IEnumerable<UnorderedAccessView^>^ unorderedAccessViews, array<UInt32>^ initialCounts)
{
    vector<ID3D11UnorderedAccessView*> itemsVector;
    UINT count = CommonUtils::FillIUnknownsVector<UnorderedAccessView, ID3D11UnorderedAccessView>(unorderedAccessViews, itemsVector);

    
    if (count > 0 && count != initialCounts->Length)
    {
        throw gcnew InvalidOperationException("Both unorderedAccessViews and initialCounts sizes must be equal.");
    }

    pin_ptr<UINT> countArray;
    if (count > 0) 
        countArray = &initialCounts[0];

    Parent->GetInterface<ID3D11DeviceContext>()->CSSetUnorderedAccessViews(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &itemsVector[0],
        countArray);
}
