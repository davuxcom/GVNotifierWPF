//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10PipelineStage.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

/// <summary>
/// Pixel Shader pipeline stage. 
/// </summary>
public ref class PixelShaderPipelineStage : PipelineStage
{
public:
    /// <summary>
    /// Get the constant buffers used by the pixel shader pipeline stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSGetConstantBuffers)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin retrieving constant buffers from (ranges from 0 to D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).</param>
    /// <param name="numBuffers">Number of buffers to retrieve (ranges from 0 to D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - startSlot).</param>
    /// <returns>Collection of constant buffer objects (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/> to be returned by the method.</returns>
    ReadOnlyCollection<D3DBuffer^>^ GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers);

    /// <summary>
    /// Get an array of sampler states from the pixel shader pipeline stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSGetSamplers)</para>
    /// </summary>
    /// <param name="startSlot">Index into a zero-based array to begin getting samplers from (ranges from 0 to D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1).</param>
    /// <param name="numSamplers">Number of samplers to get from a device context. Each pipeline stage has a total of 16 sampler slots available (ranges from 0 to D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - startSlot).</param>
    /// <returns>Collection of sampler-state objects (see <see cref="SamplerState"/>)<seealso cref="SamplerState"/> to be returned by the device.</returns>
    ReadOnlyCollection<SamplerState^>^ GetSamplers(UInt32 startSlot, UInt32 numSamplers);

    /// <summary>
    /// Get the pixel shader currently set on the device.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSGetShader)</para>
    /// </summary>
    /// <returns>A pixel shader (see <see cref="PixelShader"/>)<seealso cref="PixelShader"/> to be returned by the method.</returns>
    PixelShader^ GetShader();

    /// <summary>
    /// Get the pixel shader resources.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSGetShaderResources)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin getting shader resources from (ranges from 0 to D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1).</param>
    /// <param name="numViews">The number of resources to get from the device. Up to a maximum of 128 slots are available for shader resources (ranges from 0 to D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - startSlot).</param>
    /// <returns>Collection of shader resource view objects to be returned by the device.</returns>
    ReadOnlyCollection<ShaderResourceView^>^ GetShaderResources(UInt32 startSlot, UInt32 numViews);

    /// <summary>
    /// Set the constant buffers used by the pixel shader pipeline stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSSetConstantBuffers)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin setting constant buffers to (ranges from 0 to D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).</param>
    /// <param name="constantBuffers">Collection of constant buffers (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/> being given to the device.</param>
    void SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers);

    /// <summary>
    /// Set an array of sampler states to the pixel shader pipeline stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSSetSamplers)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin setting samplers to (ranges from 0 to D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1).</param>
    /// <param name="samplers">A collection of sampler-state objects (see <see cref="SamplerState"/>)<seealso cref="SamplerState"/>. See Remarks.</param>
    void SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers);

    /// <summary>
    /// Sets a pixel shader to the device.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSSetShader)</para>
    /// </summary>
    /// <param name="pixelShader">A pixel shader (see <see cref="PixelShader"/>)<seealso cref="PixelShader"/>. 
    /// Passing in null disables the shader for this pipeline stage.</param>
    void SetShader(PixelShader^ pixelShader);

    /// <summary>
    /// Bind an array of shader resources to the pixel shader stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::PSSetShaderResources)</para>
    /// </summary>
    /// <param name="startSlot">Index into the device's zero-based array to begin setting shader resources to (ranges from 0 to D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1).</param>
    /// <param name="shaderResourceViews">Collection of shader resource view objects to set to the device.</param>
    void SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews);
protected:
    PixelShaderPipelineStage() {}
internal:
    PixelShaderPipelineStage(D3DDevice^ parent) : PipelineStage(parent)
    {
    }
};
} } } }
