// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10StreamOutputPipelineStage.h"

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

ReadOnlyCollection<D3DBuffer^>^ StreamOutputPipelineStage::GetTargets(UInt32 numBuffers, [System::Runtime::InteropServices::Out] array<UInt32>^ % offsets)
{
    vector <ID3D10Buffer*> tempoutSOTargets(numBuffers);

    offsets = gcnew array<UInt32>(numBuffers);
    pin_ptr<UINT> arr = &offsets[0];
    Parent->GetInterface<ID3D10Device>()->SOGetTargets(static_cast<UINT>(numBuffers), &(tempoutSOTargets[0]), arr);
        
    return CommonUtils::GetCollection<D3DBuffer, ID3D10Buffer>(numBuffers, tempoutSOTargets);
}

void StreamOutputPipelineStage::SetTargets(IEnumerable<D3DBuffer^>^ targets, array<UInt32>^ offsets)
{
    vector<ID3D10Buffer*> itemsVector;
    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D10Buffer>(targets, itemsVector);

    if (count > 0 && count != offsets->Length)
    {
        throw gcnew InvalidOperationException("Both targets and offsets sizes must be equal.");
    }

    pin_ptr<UINT> offsetsArray = (count > 0 ? offsetsArray = &offsets[0] : nullptr);

    Parent->GetInterface<ID3D10Device>()->SOSetTargets(
        count, 
        count > 0 ? &itemsVector[0] : NULL,
        offsetsArray);
}

