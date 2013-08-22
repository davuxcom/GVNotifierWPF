// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11RasterizerPipelineStage.h"

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
#include "D3D11GeometryShader.h"
#include "D3D11HullShader.h"
#include "D3D11InputLayout.h"
#include "D3D11BlendState.h"
#include "D3D11DepthStencilState.h"
#include "D3D11PixelShader.h"
#include "D3D11RasterizerState.h"
#include "D3D11VertexShader.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

ReadOnlyCollection<D3dRect>^ RasterizerPipelineStage::GetScissorRects(UInt32 maxNumberOfRects)
{
    UINT tempoutNumRects = static_cast<UINT>(maxNumberOfRects);
    vector<D3D11_RECT> rects(maxNumberOfRects);

    Parent->GetInterface<ID3D11DeviceContext>()->RSGetScissorRects(&tempoutNumRects, &rects[0]);

    List<D3dRect>^ collection = gcnew List<D3dRect>();
    for (UINT i = 0; i < tempoutNumRects; i++)
    {
        collection->Add(D3dRect(rects[i]));
    }

    return gcnew ReadOnlyCollection<D3dRect>(collection);
}

RasterizerState^ RasterizerPipelineStage::GetState()
{
    ID3D11RasterizerState* tempoutRasterizerState;
    Parent->GetInterface<ID3D11DeviceContext>()->RSGetState(&tempoutRasterizerState);
    
    return tempoutRasterizerState == NULL ? nullptr : gcnew RasterizerState(tempoutRasterizerState);
}

ReadOnlyCollection<Viewport>^ RasterizerPipelineStage::GetViewports(UInt32 maxNumberOfViewports)
{
    UINT numViewports = static_cast<UINT>(maxNumberOfViewports);
    vector<D3D11_VIEWPORT> viewports(numViewports);

    Parent->GetInterface<ID3D11DeviceContext>()->RSGetViewports(&numViewports, &viewports[0]);

    IList<Viewport>^ collection = gcnew List<Viewport>((int)numViewports);

    for (UINT i = 0; i < numViewports; i++)
    {
        collection->Add(Viewport(viewports[i]));
    }

    return gcnew ReadOnlyCollection<Viewport>(collection);
}

void RasterizerPipelineStage::SetScissorRects(IEnumerable<D3dRect>^ rects)
{

    vector<D3D11_RECT> rectsVector;

    UINT numRects = CommonUtils::FillValStructsVector<D3dRect, D3D11_RECT>(rects, rectsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->RSSetScissorRects(
        numRects, 
        numRects == 0 ? NULL : &rectsVector[0]);
}

void RasterizerPipelineStage::SetState(RasterizerState^ rasterizerState)
{
    Parent->GetInterface<ID3D11DeviceContext>()->RSSetState(
        rasterizerState == nullptr ? NULL : rasterizerState->GetInterface<ID3D11RasterizerState>());
}

void RasterizerPipelineStage::SetViewports(IEnumerable<Viewport>^ viewports)
{

    vector<D3D11_VIEWPORT> portsVector;

    UINT numPorts = CommonUtils::FillValStructsVector<Viewport, D3D11_VIEWPORT>(viewports, portsVector);

    Parent->GetInterface<ID3D11DeviceContext>()->RSSetViewports(
        numPorts, 
        numPorts == 0 ? NULL : &portsVector[0]);
}

