// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11StreamOutputPipelineStage.h"

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

ReadOnlyCollection<D3DBuffer^>^ StreamOutputPipelineStage::GetTargets(UInt32 numBuffers)
{
    vector <ID3D11Buffer*> tempoutSOTargets(numBuffers);
    Parent->GetInterface<ID3D11DeviceContext>()->SOGetTargets(static_cast<UINT>(numBuffers), &(tempoutSOTargets[0]));
        
    return CommonUtils::GetCollection<D3DBuffer, ID3D11Buffer>(numBuffers, tempoutSOTargets);
}

void StreamOutputPipelineStage::SetTargets(IEnumerable<D3DBuffer^>^ targets, array<UInt32>^ offsets)
{
    vector<ID3D11Buffer*> itemsVector;
    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D11Buffer>(targets, itemsVector);

    if (count > 0 && (count != offsets->Length))
    {
        throw gcnew InvalidOperationException("Both targets and offsets sizes must be equal.");
    }

    pin_ptr<UINT> offsetsArray = (count > 0 ? offsetsArray = &offsets[0] : nullptr);

    Parent->GetInterface<ID3D11DeviceContext>()->SOSetTargets(
        count, 
        count == 0 ? NULL : &itemsVector[0],
        offsetsArray);
}

