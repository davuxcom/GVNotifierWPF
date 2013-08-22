// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11OutputMergerPipelineStage.h"

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

BlendState^ OutputMergerPipelineStage::GetBlendState([System::Runtime::InteropServices::Out] ColorRgba  % outBlendFactor, [System::Runtime::InteropServices::Out] UInt32 %outSampleMask)
{
    ID3D11BlendState* tempoutBlendState;
    UINT tempoutSampleMask;

    vector<FLOAT> tempoutBlendFactor(4);

    Parent->GetInterface<ID3D11DeviceContext>()->OMGetBlendState(&tempoutBlendState, &tempoutBlendFactor[0], &tempoutSampleMask);
    
    outSampleMask = static_cast<UInt32>(tempoutSampleMask);

    outBlendFactor = ColorRgba(&tempoutBlendFactor[0]);

    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);
}

BlendState^ OutputMergerPipelineStage::GetBlendState()
{
    ID3D11BlendState* tempoutBlendState;
    UINT tempoutSampleMask;

    vector<FLOAT> tempoutBlendFactor(4);

    Parent->GetInterface<ID3D11DeviceContext>()->OMGetBlendState(&tempoutBlendState, &tempoutBlendFactor[0], &tempoutSampleMask);
    
    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);
}

DepthStencilState^ OutputMergerPipelineStage::GetDepthStencilState([System::Runtime::InteropServices::Out] UInt32 %outStencilRef)
{
    ID3D11DepthStencilState* tempoutDepthStencilState;
    UINT tempoutStencilRef;

    Parent->GetInterface<ID3D11DeviceContext>()->OMGetDepthStencilState(&tempoutDepthStencilState, &tempoutStencilRef);

    outStencilRef = tempoutStencilRef;

    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);
}


DepthStencilState^ OutputMergerPipelineStage::GetDepthStencilState()
{
    ID3D11DepthStencilState* tempoutDepthStencilState;
    UINT tempoutStencilRef;

    Parent->GetInterface<ID3D11DeviceContext>()->OMGetDepthStencilState(&tempoutDepthStencilState, &tempoutStencilRef);

    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);
}

ReadOnlyCollection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargets(UInt32 numViews, [System::Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView)
{
    vector<ID3D11RenderTargetView*> tempoutRenderTargetViews(numViews);
    ID3D11DepthStencilView* tempoutDepthStencilView;
    
    Parent->GetInterface<ID3D11DeviceContext>()->OMGetRenderTargets(static_cast<UINT>(numViews), &tempoutRenderTargetViews[0], &tempoutDepthStencilView);
    
    outDepthStencilView = tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);

    return CommonUtils::GetCollection<RenderTargetView, ID3D11RenderTargetView>(numViews, tempoutRenderTargetViews);
}

ReadOnlyCollection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargets(UInt32 numViews)
{
    vector<ID3D11RenderTargetView*> tempoutRenderTargetViews(numViews);
    
    Parent->GetInterface<ID3D11DeviceContext>()->OMGetRenderTargets(static_cast<UINT>(numViews), &tempoutRenderTargetViews[0], NULL);
    
    return CommonUtils::GetCollection<RenderTargetView, ID3D11RenderTargetView>(numViews, tempoutRenderTargetViews);
}

 DepthStencilView^ OutputMergerPipelineStage::GetDepthStencilView()
{
    ID3D11DepthStencilView* tempoutDepthStencilView;
    
    Parent->GetInterface<ID3D11DeviceContext>()->OMGetRenderTargets(0, NULL, &tempoutDepthStencilView);
    
    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

ReadOnlyCollection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargetsAndUnorderedAccessViews(
    UInt32 numViews, [System::Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView, UInt32 UAVstartSlot, UInt32 numUAVs, [System::Runtime::InteropServices::Out] ReadOnlyCollection<UnorderedAccessView^>^ %outUnorderedAccessViews)
{
    vector<ID3D11RenderTargetView*> tempoutRenderTargetViews(numViews);
    ID3D11DepthStencilView* tempoutDepthStencilView;
    vector<ID3D11UnorderedAccessView*> tempoutUnorderedAccessView(numUAVs);
    
    Parent->GetInterface<ID3D11DeviceContext>()->OMGetRenderTargetsAndUnorderedAccessViews(
        static_cast<UINT>(numViews), &tempoutRenderTargetViews[0], &tempoutDepthStencilView,
        static_cast<UINT>(UAVstartSlot), static_cast<UINT>(numUAVs), &tempoutUnorderedAccessView[0]);
    
    outDepthStencilView = tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
    
    outUnorderedAccessViews = CommonUtils::GetCollection<UnorderedAccessView, ID3D11UnorderedAccessView>(numUAVs, tempoutUnorderedAccessView);

    return CommonUtils::GetCollection<RenderTargetView, ID3D11RenderTargetView>(numViews, tempoutRenderTargetViews);
}

ReadOnlyCollection<UnorderedAccessView^>^ OutputMergerPipelineStage::GetUnorderedAccessViews(UInt32 UAVstartSlot, UInt32 numUAVs)
{
    vector<ID3D11UnorderedAccessView*> tempoutUnorderedAccessView(numUAVs);
    
    Parent->GetInterface<ID3D11DeviceContext>()->OMGetRenderTargetsAndUnorderedAccessViews(
        0, NULL, NULL,
        static_cast<UINT>(UAVstartSlot), static_cast<UINT>(numUAVs), &tempoutUnorderedAccessView[0]);
    
    return CommonUtils::GetCollection<UnorderedAccessView, ID3D11UnorderedAccessView>(numUAVs, tempoutUnorderedAccessView);
}

void OutputMergerPipelineStage::SetBlendState(BlendState^ blendState, ColorRgba blendFactor, UInt32 SampleMask)
{

    pin_ptr<FLOAT> belndAarray = &blendFactor.Red;

    Parent->GetInterface<ID3D11DeviceContext>()->OMSetBlendState(
        blendState ? blendState->GetInterface<ID3D11BlendState>() : NULL, 
        belndAarray, 
        static_cast<UINT>(SampleMask));
}

void OutputMergerPipelineStage::SetDepthStencilState(DepthStencilState^ depthStencilState, UInt32 stencilRef)
{
    Parent->GetInterface<ID3D11DeviceContext>()->OMSetDepthStencilState(
        depthStencilState ? depthStencilState->GetInterface<ID3D11DepthStencilState>() : NULL, 
        stencilRef);
}

void OutputMergerPipelineStage::SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView)
{
    vector<ID3D11RenderTargetView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<RenderTargetView, ID3D11RenderTargetView>(renderTargetViews, itemsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->OMSetRenderTargets(
        count, 
        count == 0 ? NULL : &itemsVector[0], 
        depthStencilView == nullptr ? NULL : depthStencilView->GetInterface<ID3D11DepthStencilView>());
}

void OutputMergerPipelineStage::SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews)
{
    SetRenderTargets(renderTargetViews, nullptr);
}

void OutputMergerPipelineStage::SetRenderTargetsAndUnorderedAccessViews(
    IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView, UInt32 UAVstartSlot, 
    IEnumerable<UnorderedAccessView^>^ unorderedAccessViews, array<UInt32>^ UAVInitialCounts)
{
    if ((unorderedAccessViews != nullptr && UAVInitialCounts == nullptr) || 
        (unorderedAccessViews == nullptr && UAVInitialCounts != nullptr))
    {
        throw gcnew InvalidOperationException("Both unorderedAccessViews and UAVInitialCounts must be set together. Neither one can be null if the other is not null.");        
    }
    

    vector<ID3D11RenderTargetView*> itemsVector;
    UINT count = CommonUtils::FillIUnknownsVector<RenderTargetView, ID3D11RenderTargetView>(renderTargetViews, itemsVector);

    if (unorderedAccessViews != nullptr && (count != UAVInitialCounts->Length))
    {
        throw gcnew InvalidOperationException("Both unorderedAccessViews and UAVInitialCounts sizes must be equal.");
    }
    vector<ID3D11UnorderedAccessView*> UAVVector;
    UINT UAVcount = CommonUtils::FillIUnknownsVector<UnorderedAccessView, ID3D11UnorderedAccessView>(unorderedAccessViews, UAVVector);

    pin_ptr<UINT> countArray;
    if (UAVcount > 0) 
        countArray = &UAVInitialCounts[0];

    Parent->GetInterface<ID3D11DeviceContext>()->OMSetRenderTargetsAndUnorderedAccessViews(
        count, 
        count == 0 ? NULL : &itemsVector[0], 
        depthStencilView == nullptr ? NULL : depthStencilView->GetInterface<ID3D11DepthStencilView>(),
        static_cast<UINT>(UAVstartSlot), 
        UAVcount,
        UAVcount == 0 ? NULL : &UAVVector[0],
        countArray);
}

