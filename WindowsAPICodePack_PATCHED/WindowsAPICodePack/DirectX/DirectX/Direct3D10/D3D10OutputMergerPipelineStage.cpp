// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10OutputMergerPipelineStage.h"
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

BlendState^ OutputMergerPipelineStage::GetBlendState([System::Runtime::InteropServices::Out] ColorRgba  %outBlendFactor, [System::Runtime::InteropServices::Out] UInt32 %outSampleMask)
{
    ID3D10BlendState* tempoutBlendState;
    UINT tempoutSampleMask;

    vector<FLOAT> tempoutBlendFactor(4);

    Parent->GetInterface<ID3D10Device>()->OMGetBlendState(&tempoutBlendState, &tempoutBlendFactor[0], &tempoutSampleMask);
    
    outSampleMask = tempoutSampleMask;

    outBlendFactor = ColorRgba(&tempoutBlendFactor[0]);

    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);
}

DepthStencilState^ OutputMergerPipelineStage::GetDepthStencilState([System::Runtime::InteropServices::Out] UInt32 %outStencilRef)
{
    ID3D10DepthStencilState* tempoutDepthStencilState;
    UINT tempoutStencilRef;

    Parent->GetInterface<ID3D10Device>()->OMGetDepthStencilState(&tempoutDepthStencilState, &tempoutStencilRef);

    outStencilRef = tempoutStencilRef;

    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);
}

ReadOnlyCollection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargets(UInt32 numViews, [System::Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView)
{
    vector<ID3D10RenderTargetView*> tempoutRenderTargetViews(numViews);
    ID3D10DepthStencilView* tempoutDepthStencilView;
    
    Parent->GetInterface<ID3D10Device>()->OMGetRenderTargets(static_cast<UINT>(numViews), &tempoutRenderTargetViews[0], &tempoutDepthStencilView);
    
    outDepthStencilView = tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);

    return CommonUtils::GetCollection<RenderTargetView, ID3D10RenderTargetView>(numViews, tempoutRenderTargetViews);
}

ReadOnlyCollection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargets(UInt32 numViews)
{
    vector<ID3D10RenderTargetView*> tempoutRenderTargetViews(numViews);
    
    Parent->GetInterface<ID3D10Device>()->OMGetRenderTargets(static_cast<UINT>(numViews), &tempoutRenderTargetViews[0], NULL);
    
    return CommonUtils::GetCollection<RenderTargetView, ID3D10RenderTargetView>(numViews, tempoutRenderTargetViews);
}

 DepthStencilView^ OutputMergerPipelineStage::GetDepthStencilView()
{
    ID3D10DepthStencilView* tempoutDepthStencilView;
    
    Parent->GetInterface<ID3D10Device>()->OMGetRenderTargets(0, NULL, &tempoutDepthStencilView);
    
    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

void OutputMergerPipelineStage::SetBlendState(BlendState^ blendState, ColorRgba blendFactor, UInt32 SampleMask)
{

    pin_ptr<FLOAT> belndAarray = &blendFactor.Red;

    Parent->GetInterface<ID3D10Device>()->OMSetBlendState(
        blendState ? blendState->GetInterface<ID3D10BlendState>() : NULL, 
        belndAarray, 
        static_cast<UINT>(SampleMask));
}

void OutputMergerPipelineStage::SetDepthStencilState(DepthStencilState^ depthStencilState, UInt32 stencilRef)
{
    Parent->GetInterface<ID3D10Device>()->OMSetDepthStencilState(
        depthStencilState ? depthStencilState->GetInterface<ID3D10DepthStencilState>() : NULL, 
        stencilRef);
}

void OutputMergerPipelineStage::SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView)
{
    vector<ID3D10RenderTargetView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<RenderTargetView, ID3D10RenderTargetView>(renderTargetViews, itemsVector);

    Parent->GetInterface<ID3D10Device>()->OMSetRenderTargets(
        count, 
        count == 0 ? NULL : &itemsVector[0], 
        depthStencilView == nullptr ? NULL : depthStencilView->GetInterface<ID3D10DepthStencilView>());
}

void OutputMergerPipelineStage::SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews)
{
    SetRenderTargets(renderTargetViews, nullptr);
}
