//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11PipelineStage.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

/// <summary>
/// Compute Shader pipeline stage. 
/// </summary>
public ref class ComputeShaderPipelineStage : PipelineStage
{
public:
    /// <summary>
    /// Get the constant buffers used by the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSGetConstantBuffers)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin retrieving constant buffers from (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).</param>
    /// <param name="numBuffers">Number of buffers to retrieve (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - startSlot).</param>
    /// <returns>A collection of constant buffer objects (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/> to be returned by the method.</returns>
    ReadOnlyCollection<D3DBuffer^>^ GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers);

    /// <summary>
    /// Get an array of sampler state objects from the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSGetSamplers)</para>
    /// </summary>
    /// <param name="startSlot">Index into a zero-based array to begin getting samplers from (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1).</param>
    /// <param name="numSamplers">Number of samplers to get from a device context. Each pipeline stage has a total of 16 sampler slots available (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - startSlot).</param>
    /// <returns>A collection of sampler-state objects (see <see cref="SamplerState"/>)<seealso cref="SamplerState"/>.</returns>
    ReadOnlyCollection<SamplerState^>^ GetSamplers(UInt32 startSlot, UInt32 numSamplers);

    /// <summary>
    /// Get the compute shader currently set on the device.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSGetShader)</para>
    /// </summary>
    /// <param name="numClassInstances">The number of class-instances to retrieve.</param>
    /// <param name="outClassInstances">Returns a collection of class instances (see <see cref="ClassInstance"/>)<seealso cref="ClassInstance"/>.</param>
    /// <returns>A Compute shader object (see <see cref="ComputeShader"/>)<seealso cref="ComputeShader"/>.</returns>
    ComputeShader^ GetShader(UInt32 numClassInstances, [System::Runtime::InteropServices::Out] ReadOnlyCollection<ClassInstance^>^ %outClassInstances);


    /// <summary>
    /// Get the compute shader currently set on the device.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSGetShader)</para>
    /// </summary>
    /// <returns>A Compute shader object (see <see cref="ComputeShader"/>)<seealso cref="ComputeShader"/>.</returns>
    ComputeShader^ GetShader();

    /// <summary>
    /// Get the compute-shader resources.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSGetShaderResources)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin getting shader resources from (ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1).</param>
    /// <param name="numViews">The number of resources to get from the device. Up to a maximum of 128 slots are available for shader resources (ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - startSlot).</param>
    /// <returns>A collection of shader resource view objects to be returned by the device.</returns>
    ReadOnlyCollection<ShaderResourceView^>^ GetShaderResources(UInt32 startSlot, UInt32 numViews);

    /// <summary>
    /// Gets an array of views for an unordered resource.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSGetUnorderedAccessViews)</para>
    /// </summary>
    /// <param name="startSlot">Index of the first element in the zero-based array to return (ranges from 0 to D3D11_PS_CS_UAV_REGISTER_COUNT - 1).</param>
    /// <param name="numUAVs">Number of views to get (ranges from 0 to D3D11_PS_CS_UAV_REGISTER_COUNT - startSlot).</param>
    /// <returns>A collection of Unorderd Access Views (see <see cref="UnorderedAccessView"/>)<seealso cref="UnorderedAccessView"/> to get.</returns>
    ReadOnlyCollection<UnorderedAccessView^>^ GetUnorderedAccessViews(UInt32 startSlot, UInt32 numUAVs);

    /// <summary>
    /// Set the constant buffers used by the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSSetConstantBuffers)</para>
    /// </summary>
    /// <param name="startSlot">Index into the zero-based array to begin setting constant buffers to (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).</param>
    /// <param name="constantBuffers">A collection of constant buffers (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/> being given to the device.</param>
    void SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers);

    /// <summary>
    /// Set an array of sampler states to the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSSetSamplers)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin setting samplers to (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1).</param>
    /// <param name="samplers">A collection of sampler-state objects (see <see cref="SamplerState"/>)<seealso cref="SamplerState"/>.</param>
    void SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers);

    /// <summary>
    /// Set a compute shader to the device.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSSetShader)</para>
    /// </summary>
    /// <param name="computeShader">A compute shader (see <see cref="ComputeShader"/>)<seealso cref="ComputeShader"/>. Passing in NULL disables the shader for this pipeline stage.</param>
    /// <param name="classInstances">A collection of class-instance objects (see <see cref="ClassInstance"/>)<seealso cref="ClassInstance"/>. Each interface used by a shader must have a corresponding class instance or the shader will get disabled. 
    /// Set to NULL if the shader does not use any interfaces.</param>
    void SetShader(ComputeShader^ computeShader, IEnumerable<ClassInstance^>^ classInstances);

    /// <summary>
    /// Set a compute shader to the device.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSSetShader)</para>
    /// </summary>
    void SetShader(ComputeShader^ computeShader);

    /// <summary>
    /// Bind an array of shader resources to the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSSetShaderResources)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin setting shader resources to (ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1).</param>
    /// <param name="shaderResourceViews">Collection of shader resource view objects to set to the device.</param>
    void SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews);

    /// <summary>
    /// Sets an array of views for an unordered resource.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::CSSetUnorderedAccessViews)</para>
    /// </summary>
    /// <param name="startSlot">Index of the first element in the zero-based array to begin setting.</param>
    /// <param name="unorderedAccessViews">A collection of Unordered Access Views (see <see cref="UnorderedAccessView"/>)<seealso cref="UnorderedAccessView"/> to be set by the method.</param>
    /// <param name="initialCounts">Number of objects in the array.</param>
    void SetUnorderedAccessViews(UInt32 startSlot, IEnumerable<UnorderedAccessView^>^ unorderedAccessViews, array<UInt32>^ initialCounts);
protected:
    ComputeShaderPipelineStage() {}
internal:
    ComputeShaderPipelineStage(DeviceContext^ parent) : PipelineStage(parent)
    {
    }
};
} } } }
