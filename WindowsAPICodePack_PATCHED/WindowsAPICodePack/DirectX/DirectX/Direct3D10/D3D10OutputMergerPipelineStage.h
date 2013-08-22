//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10PipelineStage.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

/// <summary>
/// OutputMerger pipeline stage. 
/// </summary>
public ref class OutputMergerPipelineStage : PipelineStage
{
public:

    /// <summary>
    /// Get the blend state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMGetBlendState)</para>
    /// </summary>
    /// <param name="blendFactor">Array of blend factors containing four entries; one for each RGBA component.</param>
    /// <param name="sampleMask">A sample mask.</param>
    /// <returns>A blend-state object (see <see cref="BlendState"/>)<seealso cref="BlendState"/>.</returns>
    BlendState^ GetBlendState([System::Runtime::InteropServices::Out] ColorRgba %blendFactor, [System::Runtime::InteropServices::Out] UInt32 %sampleMask);

    /// <summary>
    /// Gets the depth-stencil state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMGetDepthStencilState)</para>
    /// </summary>
    /// <param name="stencilRef">The stencil reference value used in the depth-stencil test.</param>
    /// <returns>A depth-stencil state object (see <see cref="DepthStencilState"/>)<seealso cref="DepthStencilState"/> to be filled with information from the device.</returns>
    DepthStencilState^ GetDepthStencilState([System::Runtime::InteropServices::Out] UInt32 %stencilRef);

    /// <summary>
    /// Get pointers to the resources bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMGetRenderTargets)</para>
    /// </summary>
    /// <param name="numViews">Number of render targets to retrieve.</param>
    /// <returns>A collection of ID3D10RenderTargetViews which represent render target views.</returns>
    ReadOnlyCollection<RenderTargetView^>^ GetRenderTargets(UInt32 numViews);

    /// <summary>
    /// Get the resources bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMGetRenderTargets)</para>
    /// </summary>
    /// <param name="numViews">Number of render targets to retrieve.</param>
    /// <param name="outDepthStencilView">Retrieves a depth-stencil view.</param>
    /// <returns>A collection of ID3D10RenderTargetViews which represent render target views.</returns>
    ReadOnlyCollection<RenderTargetView^>^ GetRenderTargets(UInt32 numViews, [System::Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView);

    /// <summary>
    /// Get the depth stencil view bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMGetRenderTargets)</para>
    /// </summary>
    /// <returns>The depth-stencil view bound to the output-merger stage.</returns>
    DepthStencilView^ GetDepthStencilView();

    /// <summary>
    /// Set the blend state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMSetBlendState)</para>
    /// </summary>
    /// <param name="blendState">A blend-state interface (see <see cref="BlendState"/>)<seealso cref="BlendState"/>. Passing in NULL implies a default blend state. See remarks for further details.</param>
    /// <param name="blendFactor">Four components array of blend factors, one for each RGBA component. This requires a blend state object that specifies the BlendFactor option.</param>
    /// <param name="sampleMask">32-bit sample coverage. The default value is 0xffffffff.</param>
    /// <remarks>
    /// <para>
    /// Passing in null for the blend-state interface indicates to the runtime to set a default blending state. 
    /// See the DX SDK (ID3D10Device::OMSetBlendState) for more details about the default blending state.
    /// </para>
    /// <para>
    /// A sample mask determines which samples get updated in all the active render targets. 
    /// The mapping of bits in a sample mask to samples in a multisample render target is 
    /// the responsibility of an individual application. 
    /// A sample mask is always applied; it is independent of whether multisampling is enabled, 
    /// and does not depend on whether an application uses multisample render targets.
    /// </para>
    /// </remarks>
    void SetBlendState(BlendState^ blendState, ColorRgba blendFactor, UInt32 sampleMask);

    /// <summary>
    /// Sets the depth-stencil state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMSetDepthStencilState)</para>
    /// </summary>
    /// <param name="depthStencilState">A depth-stencil state interface (see <see cref="DepthStencilState"/>)<seealso cref="DepthStencilState"/> to bind to the device. Set this to NULL to use the default state listed in DepthStencilDescription.</param>
    /// <param name="stencilRef">Reference value to perform against when doing a depth-stencil test.</param>
    void SetDepthStencilState(DepthStencilState^ depthStencilState, UInt32 stencilRef);

    /// <summary>
    /// Bind one or more render targets atomically and the depth-stencil buffer to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMSetRenderTargets)</para>
    /// </summary>
    /// <param name="renderTargetViews">A collection of render targets (see <see cref="RenderTargetView"/>)<seealso cref="RenderTargetView"/> to bind to the device (ranges between 0 and D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT). 
    /// If this parameter is null, no render targets are bound.</param>
    /// <param name="depthStencilView">A depth-stencil view (see <see cref="DepthStencilView"/>)<seealso cref="DepthStencilView"/> to bind to the device. 
    /// If this parameter is null, the depth-stencil state is not bound.</param>
    void SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView);

    /// <summary>
    /// Bind one or more render targets atomically and the depth-stencil buffer to the output-merger stage.
    /// The depth-stencil state is not bound.
    /// <para>(Also see DirectX SDK: ID3D10Device::OMSetRenderTargets)</para>
    /// </summary>
    /// <param name="renderTargetViews">A collection of render targets (see <see cref="RenderTargetView"/>)<seealso cref="RenderTargetView"/> to bind to the device (ranges between 0 and D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT). 
    /// If this parameter is null, no render targets are bound.</param>
    void SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews);

internal:
    OutputMergerPipelineStage() {}
internal:
    OutputMergerPipelineStage(D3DDevice^ parent) : PipelineStage(parent)
    {
    }
};
} } } }
