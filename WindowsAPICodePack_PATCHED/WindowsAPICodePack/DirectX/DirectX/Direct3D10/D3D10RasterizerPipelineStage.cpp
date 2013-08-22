// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10RasterizerPipelineStage.h"
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

ReadOnlyCollection<D3dRect>^ RasterizerPipelineStage::GetScissorRects(UInt32 maxNumberOfRects)
{
    UINT tempoutNumRects = static_cast<UINT>(maxNumberOfRects);
    vector<D3D10_RECT> rects(maxNumberOfRects);

    Parent->GetInterface<ID3D10Device>()->RSGetScissorRects(&tempoutNumRects, &rects[0]);

    List<D3dRect>^ collection = gcnew List<D3dRect>();
    for (UINT i = 0; i < tempoutNumRects; i++)
    {
        collection->Add(D3dRect(rects[i]));
    }

    return gcnew ReadOnlyCollection<D3dRect>(collection);
}

RasterizerState^ RasterizerPipelineStage::GetState()
{
    ID3D10RasterizerState* tempoutRasterizerState;
    Parent->GetInterface<ID3D10Device>()->RSGetState(&tempoutRasterizerState);
    
    return tempoutRasterizerState == NULL ? nullptr : gcnew RasterizerState(tempoutRasterizerState);
}

ReadOnlyCollection<Viewport>^ RasterizerPipelineStage::GetViewports(UInt32 maxNumberOfViewports)
{
    UINT numViewports = static_cast<UINT>(maxNumberOfViewports);
    vector<D3D10_VIEWPORT> viewports(numViewports);

    Parent->GetInterface<ID3D10Device>()->RSGetViewports(&numViewports, &viewports[0]);

    IList<Viewport>^ collection = gcnew List<Viewport>((int)numViewports);

    for (UINT i = 0; i < numViewports; i++)
    {
        collection->Add(Viewport(viewports[i]));
    }

    return gcnew ReadOnlyCollection<Viewport>(collection);
}

void RasterizerPipelineStage::SetScissorRects(IEnumerable<D3dRect>^ rects)
{
    vector<D3D10_RECT> rectsVector;

    UINT numRects = CommonUtils::FillValStructsVector<D3dRect, D3D10_RECT>(rects, rectsVector);

    Parent->GetInterface<ID3D10Device>()->RSSetScissorRects(
        numRects, 
        numRects == 0 ? NULL : &rectsVector[0]);
}

void RasterizerPipelineStage::SetState(RasterizerState^ rasterizerState)
{
    Parent->GetInterface<ID3D10Device>()->RSSetState(
        rasterizerState == nullptr ? NULL : rasterizerState->GetInterface<ID3D10RasterizerState>());
}

void RasterizerPipelineStage::SetViewports(IEnumerable<Viewport>^ viewports)
{
    vector<D3D10_VIEWPORT> portsVector;

    UINT numPorts = CommonUtils::FillValStructsVector<Viewport, D3D10_VIEWPORT>(viewports, portsVector);

    Parent->GetInterface<ID3D10Device>()->RSSetViewports(
        numPorts, 
        numPorts == 0 ? NULL : &portsVector[0]);
}

