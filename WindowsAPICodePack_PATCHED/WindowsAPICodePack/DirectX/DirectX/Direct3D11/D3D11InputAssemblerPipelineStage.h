//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11PipelineStage.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

/// <summary>
/// InputAssembler pipeline stage. 
/// </summary>
public ref class InputAssemblerPipelineStage : PipelineStage
{
public:
    /// <summary>
    /// Get the index buffer that is bound to the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IAGetIndexBuffer)</para>
    /// </summary>
    /// <param name="outFormat">The format of the data in the index buffer (see <see cref="Format"/>)<seealso cref="Format"/>. These formats provide the size and type of the data in the buffer. The only formats allowed for index buffer data are 16-bit (Format_R16_UINT) and 32-bit (Format_R32_UINT) integers.</param>
    /// <param name="outOffset">Offset (in bytes) from the start of the index buffer, to the first index to use.</param>
    /// <returns>An index buffer returned by the method (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/>.</returns>
    D3DBuffer^ GetIndexBuffer( [System::Runtime::InteropServices::Out] Format %outFormat, [System::Runtime::InteropServices::Out] UInt32 %outOffset);

    /// <summary>
    /// Get the input-layout object that is bound to the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IAGetInputLayout)</para>
    /// </summary>
    /// <returns>The input-layout object (see <see cref="InputLayout"/>)<seealso cref="InputLayout"/>, which describes the input buffers that will be read by the IA stage.</returns>
    InputLayout^ GetInputLayout();

    /// <summary>
    /// Get information about the primitive type, and data order that describes input data for the input assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IAGetPrimitiveTopology)</para>
    /// </summary>
    /// <returns>The type of primitive, and ordering of the primitive data (see <see cref="PrimitiveTopology"/>)<seealso cref="PrimitiveTopology"/>.</returns>
    PrimitiveTopology GetPrimitiveTopology();

    /// <summary>
    /// Get the vertex buffers bound to the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IAGetVertexBuffers)</para>
    /// </summary>
    /// <param name="startSlot">The input slot of the first vertex buffer to get. The first vertex buffer is explicitly bound to the start slot; this causes each additional vertex buffer in the array to be implicitly bound to each subsequent input slot. There are 16 input slots.</param>
    /// <param name="numBuffers">The number of vertex buffers to get starting at the offset. The number of buffers (plus the starting slot) cannot exceed the total number of IA-stage input slots.</param>
    /// <param name="strides">A collection of stride values returned by the method; one stride value for each buffer in the vertex-buffer array. Each stride value is the size (in bytes) of the elements that are to be used from that vertex buffer.</param>
    /// <param name="offsets">A collection of offset values returned by the method; one offset value for each buffer in the vertex-buffer array. Each offset is the number of bytes between the first element of a vertex buffer and the first element that will be used.</param>
    /// <returns>A collection of vertex buffers returned by the method (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/>.</returns>
    ReadOnlyCollection<D3DBuffer^>^ GetVertexBuffers(UInt32 startSlot, UInt32 numBuffers, [System::Runtime::InteropServices::Out] array<UInt32>^ %strides, [System::Runtime::InteropServices::Out] array<UInt32>^ %offsets);

    /// <summary>
    /// Bind an index buffer to the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IASetIndexBuffer)</para>
    /// </summary>
    /// <param name="indexBuffer">A D3DBuffer object, that contains indices. The index buffer must have been created with the indexBuffer flag.</param>
    /// <param name="format">A Format that specifies the format of the data in the index buffer. The only formats allowed for index buffer data are 16-bit (Format_R16_UINT) and 32-bit (Format_R32_UINT) integers.</param>
    /// <param name="offset">Offset (in bytes) from the start of the index buffer to the first index to use.</param>
    /// <remarks>Calling this method using a buffer that is currently bound for writing (i.e. bound to the stream output pipeline stage) will effectively 
    /// bind null instead because a buffer cannot be bound as both an input and an output at the same time.</remarks>
    void SetIndexBuffer(D3DBuffer^ indexBuffer, Format format, UInt32 offset);

    /// <summary>
    /// Bind an input-layout object to the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IASetInputLayout)</para>
    /// </summary>
    /// <param name="inputLayout">The input-layout object (see <see cref="InputLayout"/>)<seealso cref="InputLayout"/>, which describes the input buffers that will be read by the IA stage.</param>
    void SetInputLayout(InputLayout^ inputLayout);

    /// <summary>
    /// Bind information about the primitive type, and data order that describes input data for the input assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IASetPrimitiveTopology)</para>
    /// </summary>
    /// <param name="topology">The type of primitive and ordering of the primitive data (see <see cref="PrimitiveTopology"/>)<seealso cref="PrimitiveTopology"/>.</param>
    void SetPrimitiveTopology(PrimitiveTopology topology);

    /// <summary>
    /// Bind an array of vertex buffers to the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::IASetVertexBuffers)</para>
    /// </summary>
    /// <param name="startSlot">The first input slot for binding. The first vertex buffer is explicitly bound to the start slot; this causes each additional vertex buffer in the array to be implicitly bound to each subsequent input slot. There are 16 input slots (ranges from 0 to D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1).</param>
    /// <param name="vertexBuffers">A collection of vertex buffers (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/>. 
    /// The number of buffers (plus the starting slot) cannot exceed the total number of IA-stage input slots (ranges from 0 to D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - startSlot).
    /// The vertex buffers must have been created with the VertexBuffer flag.</param>
    /// <param name="strides">An array of stride values; one stride value for each buffer in the vertex-buffer array. Each stride is the size (in bytes) of the elements that are to be used from that vertex buffer.</param>
    /// <param name="offsets">An array of offset values; one offset value for each buffer in the vertex-buffer array. Each offset is the number of bytes between the first element of a vertex buffer and the first element that will be used.</param>
    void SetVertexBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ vertexBuffers, array<UInt32>^ strides, array<UInt32>^ offsets);
protected:
    InputAssemblerPipelineStage() {}
internal:
    InputAssemblerPipelineStage(DeviceContext^ parent) : PipelineStage(parent)
    {
    }
};
} } } }
