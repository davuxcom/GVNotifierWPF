// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11DeviceContext.h"

#include "D3D11Asynchronous.h"
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
#include "D3D11Predicate.h"
#include "D3D11GeometryShader.h"
#include "D3D11HullShader.h"
#include "D3D11InputLayout.h"
#include "D3D11BlendState.h"
#include "D3D11DepthStencilState.h"
#include "D3D11PixelShader.h"
#include "D3D11RasterizerState.h"
#include "D3D11VertexShader.h"

#include "D3D11ComputeShaderPipelineStage.h"
#include "D3D11DomainShaderPipelineStage.h"
#include "D3D11GeometryShaderPipelineStage.h"
#include "D3D11HullShaderPipelineStage.h"
#include "D3D11InputAssemblerPipelineStage.h"
#include "D3D11OutputMergerPipelineStage.h"
#include "D3D11PixelShaderPipelineStage.h"
#include "D3D11RasterizerPipelineStage.h"
#include "D3D11StreamOutputPipelineStage.h"
#include "D3D11VertexShaderPipelineStage.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

void DeviceContext::Begin(Asynchronous^ asyncData)
{
    GetInterface<ID3D11DeviceContext>()->Begin(asyncData->GetInterface<ID3D11Asynchronous>());
}

void DeviceContext::ClearDepthStencilView(DepthStencilView^ depthStencilView, ClearFlag clearFlags, Single depth, Byte stencil)
{
    GetInterface<ID3D11DeviceContext>()->ClearDepthStencilView(depthStencilView->GetInterface<ID3D11DepthStencilView>(), static_cast<UINT>(clearFlags), static_cast<FLOAT>(depth), static_cast<UINT8>(stencil));
}

void DeviceContext::ClearRenderTargetView(RenderTargetView^ renderTargetView, ColorRgba colorRgba)
{
    pin_ptr<ColorRgba> rgba = &colorRgba;
    GetInterface<ID3D11DeviceContext>()->ClearRenderTargetView(renderTargetView->GetInterface<ID3D11RenderTargetView>(), (float*)rgba);
}

void DeviceContext::ClearState()
{
    GetInterface<ID3D11DeviceContext>()->ClearState();
}

void DeviceContext::ClearUnorderedAccessViewFloat(UnorderedAccessView^ unorderedAccessView, array<Single>^ values)
{
    if (values == nullptr)
    {
        throw gcnew ArgumentNullException("values");
    }
    if (values->Length != 4)
    {
        throw gcnew ArgumentOutOfRangeException("values", "Array length must be 4.");
    }

    pin_ptr<FLOAT> arr = &values[0];

    GetInterface<ID3D11DeviceContext>()->ClearUnorderedAccessViewFloat(unorderedAccessView->GetInterface<ID3D11UnorderedAccessView>(), arr);
}

void DeviceContext::ClearUnorderedAccessViewUint(UnorderedAccessView^ unorderedAccessView, array<UInt32>^ values)
{
    if (values == nullptr)
    {
        throw gcnew ArgumentNullException("values");
    }
    if (values->Length != 4)
    {
        throw gcnew ArgumentOutOfRangeException("values", "Array length must be 4.");
    }

    pin_ptr<UINT> arr = &values[0];

    GetInterface<ID3D11DeviceContext>()->ClearUnorderedAccessViewUint(unorderedAccessView->GetInterface<ID3D11UnorderedAccessView>(), arr);
}

void DeviceContext::CopyResource(D3DResource^ destinationResource, D3DResource^ sourceResource)
{
    GetInterface<ID3D11DeviceContext>()->CopyResource(destinationResource->GetInterface<ID3D11Resource>(), sourceResource->GetInterface<ID3D11Resource>());
}

void DeviceContext::CopySubresourceRegion(D3DResource^ destinationResource, UInt32 destinationSubresource, UInt32 DstX, UInt32 DstY, UInt32 DstZ, D3DResource^ sourceResource, UInt32 sourceSubresource, Box SrcBox)
{
    pin_ptr<Box> boxPtr = &SrcBox;
    GetInterface<ID3D11DeviceContext>()->CopySubresourceRegion(destinationResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(destinationSubresource), static_cast<UINT>(DstX), static_cast<UINT>(DstY), static_cast<UINT>(DstZ), sourceResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(sourceSubresource), (D3D11_BOX*)boxPtr);
}

void DeviceContext::CopySubresourceRegion(D3DResource^ destinationResource, UInt32 destinationSubresource, UInt32 DstX, UInt32 DstY, UInt32 DstZ, D3DResource^ sourceResource, UInt32 sourceSubresource)
{
    GetInterface<ID3D11DeviceContext>()->CopySubresourceRegion(destinationResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(destinationSubresource), static_cast<UINT>(DstX), static_cast<UINT>(DstY), static_cast<UINT>(DstZ), sourceResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(sourceSubresource), NULL);
}
void DeviceContext::Dispatch(UInt32 threadGroupCountX, UInt32 threadGroupCountY, UInt32 threadGroupCountZ)
{
    GetInterface<ID3D11DeviceContext>()->Dispatch(static_cast<UINT>(threadGroupCountX), static_cast<UINT>(threadGroupCountY), static_cast<UINT>(threadGroupCountZ));
}

void DeviceContext::DispatchIndirect(D3DBuffer^ bufferForArgs, UInt32 alignedOffsetForArgs)
{
    GetInterface<ID3D11DeviceContext>()->DispatchIndirect(bufferForArgs->GetInterface<ID3D11Buffer>(), static_cast<UINT>(alignedOffsetForArgs));
}

void DeviceContext::Draw(UInt32 vertexCount, UInt32 startVertexLocation)
{
    GetInterface<ID3D11DeviceContext>()->Draw(static_cast<UINT>(vertexCount), static_cast<UINT>(startVertexLocation));
}

void DeviceContext::DrawAuto()
{
    GetInterface<ID3D11DeviceContext>()->DrawAuto();
}

void DeviceContext::DrawIndexed(UInt32 indexCount, UInt32 startIndexLocation, Int32 baseVertexLocation)
{
    GetInterface<ID3D11DeviceContext>()->DrawIndexed(static_cast<UINT>(indexCount), static_cast<UINT>(startIndexLocation), safe_cast<INT>(baseVertexLocation));
}

void DeviceContext::DrawIndexedInstanced(UInt32 IndexCountPerInstance, UInt32 InstanceCount, UInt32 StartIndexLocation, Int32 BaseVertexLocation, UInt32 StartInstanceLocation)
{
    GetInterface<ID3D11DeviceContext>()->DrawIndexedInstanced(static_cast<UINT>(IndexCountPerInstance), static_cast<UINT>(InstanceCount), static_cast<UINT>(StartIndexLocation), safe_cast<INT>(BaseVertexLocation), static_cast<UINT>(StartInstanceLocation));
}

void DeviceContext::DrawIndexedInstancedIndirect(D3DBuffer^ BufferForArgs, UInt32 AlignedByteOffsetForArgs)
{
    GetInterface<ID3D11DeviceContext>()->DrawIndexedInstancedIndirect(BufferForArgs->GetInterface<ID3D11Buffer>(), static_cast<UINT>(AlignedByteOffsetForArgs));
}

void DeviceContext::DrawInstanced(UInt32 VertexCountPerInstance, UInt32 InstanceCount, UInt32 StartVertexLocation, UInt32 StartInstanceLocation)
{
    GetInterface<ID3D11DeviceContext>()->DrawInstanced(static_cast<UINT>(VertexCountPerInstance), static_cast<UINT>(InstanceCount), static_cast<UINT>(StartVertexLocation), static_cast<UINT>(StartInstanceLocation));
}

void DeviceContext::DrawInstancedIndirect(D3DBuffer^ BufferForArgs, UInt32 AlignedByteOffsetForArgs)
{
    GetInterface<ID3D11DeviceContext>()->DrawInstancedIndirect(BufferForArgs->GetInterface<ID3D11Buffer>(), static_cast<UINT>(AlignedByteOffsetForArgs));
}

void DeviceContext::End(Asynchronous^ Async)
{
    GetInterface<ID3D11DeviceContext>()->End(Async->GetInterface<ID3D11Asynchronous>());
}

void DeviceContext::ExecuteCommandList(CommandList^ _CommandList, Boolean RestoreContextState)
{
    GetInterface<ID3D11DeviceContext>()->ExecuteCommandList(_CommandList->GetInterface<ID3D11CommandList>(), safe_cast<BOOL>(RestoreContextState));
}

void DeviceContext::FinishCommandList(Boolean RestoreDeferredContextState, [System::Runtime::InteropServices::Out] CommandList^ %outCommandList)
{
    ID3D11CommandList* tempoutCommandList;
    CommonUtils::VerifyResult(GetInterface<ID3D11DeviceContext>()->FinishCommandList(safe_cast<BOOL>(RestoreDeferredContextState), &tempoutCommandList));
    outCommandList = gcnew CommandList(tempoutCommandList);
}

void DeviceContext::Flush()
{
    GetInterface<ID3D11DeviceContext>()->Flush();
}

void DeviceContext::GenerateMips(ShaderResourceView^ shaderResourceView)
{
    GetInterface<ID3D11DeviceContext>()->GenerateMips(shaderResourceView->GetInterface<ID3D11ShaderResourceView>());
}

UInt32 DeviceContext::ContextFlags::get()
{
    return GetInterface<ID3D11DeviceContext>()->GetContextFlags();
}

void DeviceContext::GetData(Asynchronous^ asyncData, IntPtr data, UInt32 dataSize, AsyncGetDataFlag flags)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11DeviceContext>()->GetData(asyncData->GetInterface<ID3D11Asynchronous>(), data.ToPointer(), static_cast<UINT>(dataSize), static_cast<UINT>(flags)));
}

void DeviceContext::GetPredication([System::Runtime::InteropServices::Out] D3DPredicate^ %outPredicate, [System::Runtime::InteropServices::Out] Boolean %outPredicateValue)
{
    ID3D11Predicate* tempoutPredicate;
    BOOL tempoutPredicateValue;
    GetInterface<ID3D11DeviceContext>()->GetPredication(&tempoutPredicate, &tempoutPredicateValue);
    outPredicate = gcnew D3DPredicate(tempoutPredicate);
    outPredicateValue = tempoutPredicateValue != 0;
}

Single DeviceContext::GetResourceMinLOD(D3DResource^ Resource)
{
    float returnValue = GetInterface<ID3D11DeviceContext>()->GetResourceMinLOD(Resource->GetInterface<ID3D11Resource>());
    return safe_cast<Single>(returnValue);
}

DeviceContextType DeviceContext::GetType()
{
    D3D11_DEVICE_CONTEXT_TYPE returnValue = GetInterface<ID3D11DeviceContext>()->GetType();
    return safe_cast<DeviceContextType>(returnValue);
}

void DeviceContext::Map(D3DResource^ resource, UInt32 subresource, D3D11::Map mapType, D3D11::MapFlag mapFlags, MappedSubresource mappedResource)
{
    D3D11_MAPPED_SUBRESOURCE mappedRes;
    mappedResource.CopyTo(&mappedRes);

    CommonUtils::VerifyResult(GetInterface<ID3D11DeviceContext>()->Map(
        resource->GetInterface<ID3D11Resource>(), 
        subresource, 
        static_cast<D3D11_MAP>(mapType), 
        static_cast<UINT>(mapFlags), 
        &mappedRes));
}

void DeviceContext::SetPredication(D3DPredicate^ D3DPredicate, Boolean PredicateValue)
{
    GetInterface<ID3D11DeviceContext>()->SetPredication(D3DPredicate->GetInterface<ID3D11Predicate>(), PredicateValue ? 1 : 0);
}

void DeviceContext::ResolveSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, D3DResource^ sourceResource, UInt32 sourceSubresource, Format format)
{
    GetInterface<ID3D11DeviceContext>()->ResolveSubresource(destinationResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(destinationSubresource), sourceResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(sourceSubresource), static_cast<DXGI_FORMAT>(format));
}

void DeviceContext::SetResourceMinLOD(D3DResource^ Resource, Single MinLOD)
{
    GetInterface<ID3D11DeviceContext>()->SetResourceMinLOD(Resource->GetInterface<ID3D11Resource>(), MinLOD);
}

void DeviceContext::Unmap(D3DResource^ resource, UInt32 subresource)
{
    GetInterface<ID3D11DeviceContext>()->Unmap(resource->GetInterface<ID3D11Resource>(), subresource);
}

void DeviceContext::UpdateSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, IntPtr SrcData, UInt32 SrcRowPitch, UInt32 SrcDepthPitch, Box DstBox)
{
    pin_ptr<Box> boxPtr = &DstBox;;
    GetInterface<ID3D11DeviceContext>()->UpdateSubresource(destinationResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(destinationSubresource), (D3D11_BOX*)boxPtr, reinterpret_cast<LPVOID>(SrcData.ToPointer()), static_cast<UINT>(SrcRowPitch), static_cast<UINT>(SrcDepthPitch));
}

void DeviceContext::UpdateSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, IntPtr SrcData, UInt32 SrcRowPitch, UInt32 SrcDepthPitch)
{
    GetInterface<ID3D11DeviceContext>()->UpdateSubresource(destinationResource->GetInterface<ID3D11Resource>(), static_cast<UINT>(destinationSubresource), NULL, reinterpret_cast<LPVOID>(SrcData.ToPointer()), static_cast<UINT>(SrcRowPitch), static_cast<UINT>(SrcDepthPitch));
}

// The pipeline stage accessors
ComputeShaderPipelineStage^ DeviceContext::CS::get() 
{ 
    if (m_CS == nullptr) 
        m_CS = gcnew ComputeShaderPipelineStage(this); 
    
    return m_CS; 
}

DomainShaderPipelineStage^ DeviceContext::DS::get() 
{ 
    if (m_DS == nullptr) 
        m_DS = gcnew DomainShaderPipelineStage(this); 
    
    return m_DS; 
}

GeometryShaderPipelineStage^ DeviceContext::GS::get() 
{ 
    if (m_GS == nullptr) 
        m_GS = gcnew GeometryShaderPipelineStage(this); 
    
    return m_GS; 
}

HullShaderPipelineStage^ DeviceContext::HS::get() 
{ 
    if (m_HS == nullptr) 
        m_HS = gcnew HullShaderPipelineStage(this); 
    
    return m_HS; 
}

InputAssemblerPipelineStage^ DeviceContext::IA::get() 
{ 
    if (m_IA == nullptr) 
        m_IA = gcnew InputAssemblerPipelineStage(this); 
    
    return m_IA; 
}

OutputMergerPipelineStage^ DeviceContext::OM::get() 
{ 
    if (m_OM == nullptr) 
        m_OM = gcnew OutputMergerPipelineStage(this); 
    
    return m_OM; 
}

PixelShaderPipelineStage^ DeviceContext::PS::get() 
{ 
    if (m_PS == nullptr) 
        m_PS = gcnew PixelShaderPipelineStage(this); 
    
    return m_PS; 
}

RasterizerPipelineStage^ DeviceContext::RS::get() 
{ 
    if (m_RS == nullptr) 
        m_RS = gcnew RasterizerPipelineStage(this); 
    
    return m_RS; 
}

StreamOutputPipelineStage^ DeviceContext::SO::get() 
{ 
    if (m_SO == nullptr) 
        m_SO = gcnew StreamOutputPipelineStage(this); 
    
    return m_SO; 
}

VertexShaderPipelineStage^ DeviceContext::VS::get() 
{ 
    if (m_VS == nullptr) 
        m_VS = gcnew VertexShaderPipelineStage(this); 
    
    return m_VS; 
}
