//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10PipelineStage.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

/// <summary>
/// StreamOutput pipeline stage. 
/// </summary>
public ref class StreamOutputPipelineStage : PipelineStage
{
public:

    /// <summary>
    /// Get the target output buffers for the stream-output stage of the pipeline.
    /// <para>(Also see DirectX SDK: ID3D10Device::SOGetTargets)</para>
    /// </summary>
    /// <param name="numBuffers">Number of buffers to get.</param>
    /// <param name="offsets">Output array of offsets to the output buffers from ppBuffers, one offset for each buffer. The offset values are in bytes.</param>
    /// <returns>A collection of output buffers (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/> to be retrieved from the device.</returns>
    ReadOnlyCollection<D3DBuffer^>^ GetTargets(UInt32 numBuffers, [System::Runtime::InteropServices::Out] array<UInt32>^ % offsets);

    /// <summary>
    /// Set the target output buffers for the stream-output stage of the pipeline.
    /// <para>(Also see DirectX SDK: ID3D10Device::SOSetTargets)</para>
    /// </summary>
    /// <param name="targets">The collection of output buffers (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/> to bind to the device. 
    /// The buffers must have been created with the <b>StreamOutput</b> flag.
    /// A maximum of four output buffers can be set. If less than four are defined by the call, the remaining buffer slots are set to NULL.</param>
    /// <param name="offsets">Array of offsets to the output buffers from ppBuffers, 
    /// one offset for each buffer. The offset values must be in bytes.</param>
    void SetTargets(IEnumerable<D3DBuffer^>^ targets, array<UInt32>^ offsets);
protected:
    StreamOutputPipelineStage() {}
internal:
    StreamOutputPipelineStage(D3DDevice^ parent) : PipelineStage(parent)
    {
    }
};
} } } }
