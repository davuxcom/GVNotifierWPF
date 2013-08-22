// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11InputAssemblerPipelineStage.h"

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

D3DBuffer^ InputAssemblerPipelineStage::GetIndexBuffer([System::Runtime::InteropServices::Out] Format %outFormat, [System::Runtime::InteropServices::Out] UInt32 %outOffset)
{
    ID3D11Buffer* tempoutIndexBuffer;
    DXGI_FORMAT tempoutFormat;
    UINT tempoutOffset;
    
    Parent->GetInterface<ID3D11DeviceContext>()->IAGetIndexBuffer(&tempoutIndexBuffer, &tempoutFormat, &tempoutOffset);
        
    outFormat = static_cast<Format>(tempoutFormat);
    outOffset = tempoutOffset;

    return tempoutIndexBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutIndexBuffer);
}

InputLayout^ InputAssemblerPipelineStage::GetInputLayout()
{
    ID3D11InputLayout* tempoutInputLayout;
    Parent->GetInterface<ID3D11DeviceContext>()->IAGetInputLayout(&tempoutInputLayout);

    return tempoutInputLayout == NULL ? nullptr : gcnew InputLayout(tempoutInputLayout);
}

PrimitiveTopology InputAssemblerPipelineStage::GetPrimitiveTopology()
{
    D3D11_PRIMITIVE_TOPOLOGY tempoutTopology;
    Parent->GetInterface<ID3D11DeviceContext>()->IAGetPrimitiveTopology(&tempoutTopology);
    
    return safe_cast<PrimitiveTopology>(tempoutTopology);
}

ReadOnlyCollection<D3DBuffer^>^ InputAssemblerPipelineStage::GetVertexBuffers(UInt32 startSlot, UInt32 numBuffers, [System::Runtime::InteropServices::Out] array<UInt32>^ %outStrides, [System::Runtime::InteropServices::Out] array<UInt32>^ %outOffsets)
{

    vector<ID3D11Buffer*> buffers(numBuffers);
    vector<UInt32> strides(numBuffers);
    vector<UInt32> offsets(numBuffers);

    Parent->GetInterface<ID3D11DeviceContext>()->IAGetVertexBuffers(
        static_cast<UINT>(startSlot), 
        static_cast<UINT>(numBuffers), 
        numBuffers > 0 ? &buffers[0] : NULL,
        numBuffers > 0 ? &strides[0] : NULL, 
        numBuffers > 0 ? &offsets[0] : NULL);

    outStrides = gcnew array<UInt32>(numBuffers); 
    outOffsets = gcnew array<UInt32>(numBuffers); 

    if (numBuffers > 0)
    {
        pin_ptr<UINT> pinStrides = &outStrides[0];
        memcpy(pinStrides, &strides[0], sizeof(UINT) * numBuffers);

        pin_ptr<UINT> pinOffsets = &outOffsets[0];
        memcpy(pinOffsets, &offsets[0], sizeof(UINT) * numBuffers);
    }
    
    return CommonUtils::GetCollection<D3DBuffer, ID3D11Buffer>(numBuffers, buffers);
}

void InputAssemblerPipelineStage::SetIndexBuffer(D3DBuffer^ indexBuffer, Format format, UInt32 offset)
{
    Parent->GetInterface<ID3D11DeviceContext>()->IASetIndexBuffer(
        indexBuffer ? indexBuffer->GetInterface<ID3D11Buffer>() : NULL,
        static_cast<DXGI_FORMAT>(format), 
        static_cast<UINT>(offset));
}

void InputAssemblerPipelineStage::SetInputLayout(InputLayout^ inputLayout)
{
    Parent->GetInterface<ID3D11DeviceContext>()->IASetInputLayout(
        inputLayout ? inputLayout->GetInterface<ID3D11InputLayout>() : NULL);
}

void InputAssemblerPipelineStage::SetPrimitiveTopology(PrimitiveTopology topology)
{
    Parent->GetInterface<ID3D11DeviceContext>()->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(topology));
}

void InputAssemblerPipelineStage::SetVertexBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ vertexBuffers, array<UInt32>^ strides, array<UInt32>^ offsets)
{
    vector<ID3D11Buffer*> itemsVector;
    UINT count = CommonUtils::FillIUnknownsVector<D3DBuffer, ID3D11Buffer>(vertexBuffers, itemsVector);

    if (count > 0 && (count != strides->Length) || (count != offsets->Length))
    {
        throw gcnew InvalidOperationException("Invalid array lengths; vertexBuffers, strides and offsets sizes must be equal.");
    }
    pin_ptr<UINT> stridesArray = (count > 0 ? stridesArray = &strides[0] : nullptr); 

    pin_ptr<UINT> offsetsArray = (count > 0 ? offsetsArray = &offsets[0] : nullptr);

    Parent->GetInterface<ID3D11DeviceContext>()->IASetVertexBuffers(
        static_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &itemsVector[0],
        stridesArray,
        offsetsArray);
}

