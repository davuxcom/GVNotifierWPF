//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

/// <summary>
/// Setting a feature-mask flag will cause a rendering-operation method to do some extra task when called.
/// </summary>
[Flags]
public enum class DebugFeature  : UInt32
{
    /// <summary>
    /// Application will wait for the GPU to finish processing the rendering operation before continuing.
    /// <para>(Also see DirectX SDK: D3D10_DEBUG_FEATURE_FINISH_PER_RENDER_OP)</para>
    /// </summary>
    FinishPerRenderOperation = D3D10_DEBUG_FEATURE_FINISH_PER_RENDER_OP,
    /// <summary>
    /// Runtime will additionally call ID3D10Device.Flush.
    /// <para>(Also see DirectX SDK: D3D10_DEBUG_FEATURE_FLUSH_PER_RENDER_OP)</para>
    /// </summary>
    FlushPerRenderOperation = D3D10_DEBUG_FEATURE_FLUSH_PER_RENDER_OP,
    /// <summary>
    /// Runtime will call SwapChain.Present. Presentation of render buffers will occur according to the settings established by prior calls to Debug.SetSwapChain and ID3D110Debug.SetPresentPerRenderOpDelay.
    /// <para>(Also see DirectX SDK: D3D10_DEBUG_FEATURE_PRESENT_PER_RENDER_OP)</para>
    /// </summary>
    PresentPerRenderOperation = D3D10_DEBUG_FEATURE_PRESENT_PER_RENDER_OP,
};
/// <summary>
/// Optional flags that control the behavior of Asynchronous.GetData.
/// <para>(Also see DirectX SDK: D3D10_ASYNC_GETDATA_FLAG)</para>
/// </summary>
public enum class AsyncGetDataFlag  : UInt32
{
    /// <summary>
    /// Undefined flag 
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Do not flush the command buffer. This can potentially cause an infinite loop if GetData is continually called until it returns S_OK as there may still be commands in the command buffer that need to be processed in order for GetData to return S_OK. Since the commands in the command buffer are not flushed they will not be processed and therefore GetData will never return S_OK.
    /// <para>(Also see DirectX SDK: D3D10_ASYNC_GETDATA_DONOTFLUSH)</para>
    /// </summary>
    DoNotFlush = D3D10_ASYNC_GETDATA_DONOTFLUSH,
};

/// <summary>
/// Identifies how to bind a resource to the pipeline.
/// <para>(Also see DirectX SDK: D3D10_BIND_FLAG)</para>
/// </summary>
[Flags]
public enum class BindFlag  : UInt32
{
    /// <summary>
    /// Undefined binding flags
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Bind a buffer as a vertex buffer to the input-assembler stage.
    /// <para>(Also see DirectX SDK: D3D10_BIND_VERTEX_BUFFER)</para>
    /// </summary>
    VertexBuffer = D3D10_BIND_VERTEX_BUFFER,
    /// <summary>
    /// Bind a buffer as an index buffer to the input-assembler stage.
    /// <para>(Also see DirectX SDK: D3D10_BIND_INDEX_BUFFER)</para>
    /// </summary>
    IndexBuffer = D3D10_BIND_INDEX_BUFFER,
    /// <summary>
    /// Bind a buffer as a constant buffer to a shader stage; this flag may NOT be combined with any other bind flag.
    /// <para>(Also see DirectX SDK: D3D10_BIND_CONSTANT_BUFFER)</para>
    /// </summary>
    ConstantBuffer = D3D10_BIND_CONSTANT_BUFFER,
    /// <summary>
    /// Bind a buffer or texture to a shader stage; this flag cannot be used with the WriteNoOverwrite flag.
    /// <para>(Also see DirectX SDK: D3D10_BIND_SHADER_RESOURCE)</para>
    /// </summary>
    ShaderResource = D3D10_BIND_SHADER_RESOURCE,
    /// <summary>
    /// Bind an output buffer for the stream-output stage.
    /// <para>(Also see DirectX SDK: D3D10_BIND_STREAM_OUTPUT)</para>
    /// </summary>
    StreamOutput = D3D10_BIND_STREAM_OUTPUT,
    /// <summary>
    /// Bind a texture as a render target for the output-merger stage.
    /// <para>(Also see DirectX SDK: D3D10_BIND_RENDER_TARGET)</para>
    /// </summary>
    RenderTarget = D3D10_BIND_RENDER_TARGET,
    /// <summary>
    /// Bind a texture as a depth-stencil target for the output-merger stage.
    /// <para>(Also see DirectX SDK: D3D10_BIND_DEPTH_STENCIL)</para>
    /// </summary>
    DepthStencil = D3D10_BIND_DEPTH_STENCIL,
};
/// <summary>
/// Blend options. A blend option identifies the data source and an optional pre-blend operation.
/// <para>(Also see DirectX SDK: D3D10_BLEND)</para>
/// </summary>
public enum class Blend  : UInt32
{
    /// <summary>
    /// The data source is the color black (0, 0, 0, 0). No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_ZERO)</para>
    /// </summary>
    Zero = D3D10_BLEND_ZERO,
    /// <summary>
    /// The data source is the color white (1, 1, 1, 1). No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_ONE)</para>
    /// </summary>
    One = D3D10_BLEND_ONE,
    /// <summary>
    /// The data source is color data (RGB) from a pixel shader. No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_SRC_COLOR)</para>
    /// </summary>
    SourceColor = D3D10_BLEND_SRC_COLOR,
    /// <summary>
    /// The data source is color data (RGB) from a pixel shader. The pre-blend operation inverts the data, generating 1 - RGB.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_SRC_COLOR)</para>
    /// </summary>
    InverseSourceColor = D3D10_BLEND_INV_SRC_COLOR,
    /// <summary>
    /// The data source is alpha data (A) from a pixel shader. No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_SRC_ALPHA)</para>
    /// </summary>
    SourceAlpha = D3D10_BLEND_SRC_ALPHA,
    /// <summary>
    /// The data source is alpha data (A) from a pixel shader. The pre-blend operation inverts the data, generating 1 - A.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_SRC_ALPHA)</para>
    /// </summary>
    InverseSourceAlpha = D3D10_BLEND_INV_SRC_ALPHA,
    /// <summary>
    /// The data source is alpha data from a rendertarget. No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DEST_ALPHA)</para>
    /// </summary>
    DestinationAlpha = D3D10_BLEND_DEST_ALPHA,
    /// <summary>
    /// The data source is alpha data from a rendertarget. The pre-blend operation inverts the data, generating 1 - A.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_DEST_ALPHA)</para>
    /// </summary>
    InverseDestinationAlpha = D3D10_BLEND_INV_DEST_ALPHA,
    /// <summary>
    /// The data source is color data from a rendertarget. No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DEST_COLOR)</para>
    /// </summary>
    DestinationColor = D3D10_BLEND_DEST_COLOR,
    /// <summary>
    /// The data source is color data from a rendertarget. The pre-blend operation inverts the data, generating 1 - RGB.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_DEST_COLOR)</para>
    /// </summary>
    InverseDestinationColor = D3D10_BLEND_INV_DEST_COLOR,
    /// <summary>
    /// The data source is alpha data from a pixel shader. The pre-blend operation clamps the data to 1 or less.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_SRC_ALPHA_SAT)</para>
    /// </summary>
    SourceAlphaSat = D3D10_BLEND_SRC_ALPHA_SAT,
    /// <summary>
    /// The data source is the blend factor set with Device.OMSetBlendState. No pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_BLEND_FACTOR)</para>
    /// </summary>
    BlendFactor = D3D10_BLEND_BLEND_FACTOR,
    /// <summary>
    /// The data source is the blend factor set with Device.OMSetBlendState. The pre-blend operation inverts the blend factor, generating 1 - blend_factor.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_BLEND_FACTOR)</para>
    /// </summary>
    InverseBlendFactor = D3D10_BLEND_INV_BLEND_FACTOR,
    /// <summary>
    /// The data sources are both color data output by a pixel shader. There is no pre-blend operation. This options supports dual-source color blending.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_SRC1_COLOR)</para>
    /// </summary>
    Source1Color = D3D10_BLEND_SRC1_COLOR,
    /// <summary>
    /// The data sources are both color data output by a pixel shader. The pre-blend operation inverts the data, generating 1 - RGB. This options supports dual-source color blending.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_SRC1_COLOR)</para>
    /// </summary>
    InverseSource1Color = D3D10_BLEND_INV_SRC1_COLOR,
    /// <summary>
    /// The data sources are alpha data output by a pixel shader. There is no pre-blend operation. This options supports dual-source color blending.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_SRC1_ALPHA)</para>
    /// </summary>
    Source1Alpha = D3D10_BLEND_SRC1_ALPHA,
    /// <summary>
    /// The data sources are alpha data output by a pixel shader. The pre-blend operation inverts the data, generating 1 - A. This options supports dual-source color blending.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_INV_SRC1_ALPHA)</para>
    /// </summary>
    InverseSource1Alpha = D3D10_BLEND_INV_SRC1_ALPHA,
};
/// <summary>
/// RGB or alpha blending operation.
/// <para>(Also see DirectX SDK: D3D10_BLEND_OP)</para>
/// </summary>
public enum class BlendOperation  : UInt32
{
    /// <summary>
    /// Add source 1 and source 2.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_OP_ADD)</para>
    /// </summary>
    Add = D3D10_BLEND_OP_ADD,
    /// <summary>
    /// Subtract source 1 from source 2.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_OP_SUBTRACT)</para>
    /// </summary>
    Subtract = D3D10_BLEND_OP_SUBTRACT,
    /// <summary>
    /// Subtract source 2 from source 1.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_OP_REV_SUBTRACT)</para>
    /// </summary>
    ReverseSubtract = D3D10_BLEND_OP_REV_SUBTRACT,
    /// <summary>
    /// Find the minimum of source 1 and source 2.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_OP_MIN)</para>
    /// </summary>
    Min = D3D10_BLEND_OP_MIN,
    /// <summary>
    /// Find the maximum of source 1 and source 2.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_OP_MAX)</para>
    /// </summary>
    Max = D3D10_BLEND_OP_MAX,
};
/// <summary>
/// These flags identify constant-buffer-data types.
/// <para>(Also see DirectX SDK: D3D10_CBUFFER_TYPE)</para>
/// </summary>
public enum class ConstantBufferType  : UInt32
{
    /// <summary>
    /// A buffer containing scalar constants.
    /// <para>(Also see DirectX SDK: D3D10_CT_CBUFFER)</para>
    /// </summary>
    ConstantBuffer = D3D10_CT_CBUFFER,
    /// <summary>
    /// A buffer containing texture data.
    /// <para>(Also see DirectX SDK: D3D10_CT_TBUFFER)</para>
    /// </summary>
    TextureBuffer = D3D10_CT_TBUFFER,
};
/// <summary>
/// Specifies the parts of the depth stencil to clear. Usually used with Device.ClearDepthStencilView.
/// <para>(Also see DirectX SDK: D3D10_CLEAR_FLAG)</para>
/// </summary>
public enum class ClearFlag  : UInt32
{
    /// <summary>
    /// Undefined
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Clear the depth buffer.
    /// <para>(Also see DirectX SDK: D3D10_CLEAR_DEPTH)</para>
    /// </summary>
    Depth = D3D10_CLEAR_DEPTH,
    /// <summary>
    /// Clear the stencil buffer.
    /// <para>(Also see DirectX SDK: D3D10_CLEAR_STENCIL)</para>
    /// </summary>
    Stencil = D3D10_CLEAR_STENCIL,
};
/// <summary>
/// Identify which components of each pixel of a render target are writable during blending.
/// <para>(Also see DirectX SDK: D3D10_COLOR_WRITE_ENABLE)</para>
/// </summary>
[Flags]
public enum class ColorWriteEnable  : Byte
{
    /// <summary>
    /// Undefined mask.
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Allow data to be stored in the red component.
    /// <para>(Also see DirectX SDK: D3D10_COLOR_WRITE_ENABLE_RED)</para>
    /// </summary>
    Red = D3D10_COLOR_WRITE_ENABLE_RED,
    /// <summary>
    /// Allow data to be stored in the green component.
    /// <para>(Also see DirectX SDK: D3D10_COLOR_WRITE_ENABLE_GREEN)</para>
    /// </summary>
    Green = D3D10_COLOR_WRITE_ENABLE_GREEN,
    /// <summary>
    /// Allow data to be stored in the blue component.
    /// <para>(Also see DirectX SDK: D3D10_COLOR_WRITE_ENABLE_BLUE)</para>
    /// </summary>
    Blue = D3D10_COLOR_WRITE_ENABLE_BLUE,
    /// <summary>
    /// Allow data to be stored in the alpha component.
    /// <para>(Also see DirectX SDK: D3D10_COLOR_WRITE_ENABLE_ALPHA)</para>
    /// </summary>
    Alpha = D3D10_COLOR_WRITE_ENABLE_ALPHA,
    /// <summary>
    /// Allow data to be stored in all components.
    /// <para>(Also see DirectX SDK: D3D10_COLOR_WRITE_ENABLE_ALL)</para>
    /// </summary>
    All = D3D10_COLOR_WRITE_ENABLE_ALL,
};
/// <summary>
/// Comparison options.
/// <para>(Also see DirectX SDK: D3D10_COMPARISON_FUNC)</para>
/// </summary>
public enum class ComparisonFunction : UInt32
{
    /// <summary>
    /// Never pass the comparison.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_NEVER)</para>
    /// </summary>
    Never = D3D10_COMPARISON_NEVER,
    /// <summary>
    /// If the source data is less than the destination data, the comparison passes.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_LESS)</para>
    /// </summary>
    Less = D3D10_COMPARISON_LESS,
    /// <summary>
    /// If the source data is equal to the destination data, the comparison passes.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_EQUAL)</para>
    /// </summary>
    Equal = D3D10_COMPARISON_EQUAL,
    /// <summary>
    /// If the source data is less than or equal to the destination data, the comparison passes.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_LESS_EQUAL)</para>
    /// </summary>
    LessEqual = D3D10_COMPARISON_LESS_EQUAL,
    /// <summary>
    /// If the source data is greater than the destination data, the comparison passes.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_GREATER)</para>
    /// </summary>
    Greater = D3D10_COMPARISON_GREATER,
    /// <summary>
    /// If the source data is not equal to the destination data, the comparison passes.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_NOT_EQUAL)</para>
    /// </summary>
    NotEqual = D3D10_COMPARISON_NOT_EQUAL,
    /// <summary>
    /// If the source data is greater than or equal to the destination data, the comparison passes.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_GREATER_EQUAL)</para>
    /// </summary>
    GreaterEqual = D3D10_COMPARISON_GREATER_EQUAL,
    /// <summary>
    /// Always pass the comparison.
    /// <para>(Also see DirectX SDK: D3D10_COMPARISON_ALWAYS)</para>
    /// </summary>
    Always = D3D10_COMPARISON_ALWAYS,
};


/// <summary>
/// Performance counter types.
/// <para>(Also see DirectX SDK: D3D10_COUNTER)</para>
/// </summary>
public enum class Counter : UInt32
{
    /// <summary>
    /// Percentage of the time that the GPU is idle.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_GPU_IDLE)</para>
    /// </summary>
    GpuIdle = D3D10_COUNTER_GPU_IDLE,
    /// <summary>
    /// Percentage of the time that the GPU does vertex processing.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_VERTEX_PROCESSING)</para>
    /// </summary>
    VertexProcessing = D3D10_COUNTER_VERTEX_PROCESSING,
    /// <summary>
    /// Percentage of the time that the GPU does geometry processing.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_GEOMETRY_PROCESSING)</para>
    /// </summary>
    GeometryProcessing = D3D10_COUNTER_GEOMETRY_PROCESSING,
    /// <summary>
    /// Percentage of the time that the GPU does pixel processing.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_PIXEL_PROCESSING)</para>
    /// </summary>
    PixelProcessing = D3D10_COUNTER_PIXEL_PROCESSING,
    /// <summary>
    /// Percentage of the time that the GPU does other processing (not vertex, geometry, or pixel processing).
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_OTHER_GPU_PROCESSING)</para>
    /// </summary>
    OtherGpuProcessing = D3D10_COUNTER_OTHER_GPU_PROCESSING,
    /// <summary>
    /// Percentage of bandwidth used on a host adapter. Value returned by Asynchronous.GetData between 0.0 and 1.0 when using this counter.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION)</para>
    /// </summary>
    HostAdapterBandwidthUtilization = D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION,
    /// <summary>
    /// Percentage of bandwidth used by the local video memory. Value returned by Asynchronous.GetData between 0.0 and 1.0 when using this counter
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION)</para>
    /// </summary>
    LocalVidmemBandwidthUtilization = D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION,
    /// <summary>
    /// Percentage of throughput used for vertices. Value returned by Asynchronous.GetData between 0.0 and 1.0 when using this counter
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION)</para>
    /// </summary>
    VertexThroughputUtilization = D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION,
    /// <summary>
    /// Percentage of throughput used for triangle setup. Value returned by Asynchronous.GetData between 0.0 and 1.0 when using this counter
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION)</para>
    /// </summary>
    TriangleSetupThroughputUtilization = D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION,
    /// <summary>
    /// Percentage of throughput used for the fillrate. Value returned by Asynchronous.GetData between 0.0 and 1.0 when using this counter.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION)</para>
    /// </summary>
    FillRateThroughputUtilization = D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION,
    /// <summary>
    /// Percentage of time that a vertex shader spends sampling resources.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_VS_MEMORY_LIMITED)</para>
    /// </summary>
    VertexShaderMemoryLimited = D3D10_COUNTER_VS_MEMORY_LIMITED,
    /// <summary>
    /// Percentage of time that a vertex shader spends doing computations.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_VS_COMPUTATION_LIMITED)</para>
    /// </summary>
    VertexShaderComputationLimited = D3D10_COUNTER_VS_COMPUTATION_LIMITED,
    /// <summary>
    /// Percentage of time that a geometry shader spends sampling resources.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_GS_MEMORY_LIMITED)</para>
    /// </summary>
    GeometryShaderMemoryLimited = D3D10_COUNTER_GS_MEMORY_LIMITED,
    /// <summary>
    /// Percentage of time that a geometry shader spends doing computations.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_GS_COMPUTATION_LIMITED)</para>
    /// </summary>
    GeometryShaderComputationLimited = D3D10_COUNTER_GS_COMPUTATION_LIMITED,
    /// <summary>
    /// Percentage of time that a pixel shader spends sampling resources.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_PS_MEMORY_LIMITED)</para>
    /// </summary>
    PixelShaderMemoryLimited = D3D10_COUNTER_PS_MEMORY_LIMITED,
    /// <summary>
    /// Percentage of time that a pixel shader spends doing computations.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_PS_COMPUTATION_LIMITED)</para>
    /// </summary>
    PixelShaderComputationLimited = D3D10_COUNTER_PS_COMPUTATION_LIMITED,
    /// <summary>
    /// Percentage of vertex data that was read from the vertex cache. For example, if 6 vertices were added to the cache and 3 of them were read from the cache, then the hit rate would be 0.5.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE)</para>
    /// </summary>
    PostTransformCacheHitRate = D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE,
    /// <summary>
    /// Percentage of texel data that was read from the vertex cache. For example, if 6 texels were added to the cache and 3 of them were read from the cache, then the hit rate would be 0.5.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_TEXTURE_CACHE_HIT_RATE)</para>
    /// </summary>
    TextureCacheHitRate = D3D10_COUNTER_TEXTURE_CACHE_HIT_RATE,
    /// <summary>
    /// Start of the device-dependent counters.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_DEVICE_DEPENDENT_0)</para>
    /// </summary>
    DeviceDependent0 = D3D10_COUNTER_DEVICE_DEPENDENT_0,
};
/// <summary>
/// Data type of a performance counter.
/// <para>(Also see DirectX SDK: D3D10_COUNTER_TYPE)</para>
/// </summary>
public enum class CounterType  : UInt32
{
    /// <summary>
    /// 32-bit floating point.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_TYPE_FLOAT32)</para>
    /// </summary>
    Float32 = D3D10_COUNTER_TYPE_FLOAT32,
    /// <summary>
    /// 16-bit unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_TYPE_UINT16)</para>
    /// </summary>
    Uint16 = D3D10_COUNTER_TYPE_UINT16,
    /// <summary>
    /// 32-bit unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_TYPE_UINT32)</para>
    /// </summary>
    Uint32 = D3D10_COUNTER_TYPE_UINT32,
    /// <summary>
    /// 64-bit unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_TYPE_UINT64)</para>
    /// </summary>
    Uint64 = D3D10_COUNTER_TYPE_UINT64,
};

/// <summary>
/// Specifies the types of CPU access allowed for a resource.
/// <para>(Also see DirectX SDK: D3D10_CPU_ACCESS_FLAG)</para>
/// </summary>
[Flags]
public enum class CpuAccessFlag  : UInt32
{
    /// <summary>
    /// Unspecified
    /// </summary>
    Unspecified = 0,
    /// <summary>
    /// The resource is to be mappable so that the CPU can change its contents. Resources created with this flag cannot be set as outputs of the pipeline and must be created with either dynamic or staging usage.
    /// <para>(Also see DirectX SDK: D3D10_CPU_ACCESS_WRITE)</para>
    /// </summary>
    Write = D3D10_CPU_ACCESS_WRITE,
    /// <summary>
    /// The resource is to be mappable so that the CPU can read its contents. Resources created with this flag cannot be set as either inputs or outputs to the pipeline and must be created with staging usage.
    /// <para>(Also see DirectX SDK: D3D10_CPU_ACCESS_READ)</para>
    /// </summary>
    Read = D3D10_CPU_ACCESS_READ,
};
/// <summary>
/// Device creation flags.
/// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_FLAG)</para>
/// </summary>
[Flags]
public enum class CreateDeviceFlag  : UInt32
{
    /// <summary>
    /// No flags set.
    /// </summary>
    Default = 0,
    /// <summary>
    /// Create a single-threaded device.
    /// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_SINGLETHREADED)</para>
    /// </summary>
    SingleThreaded = D3D10_CREATE_DEVICE_SINGLETHREADED,
    /// <summary>
    /// Create a device that supports the debug layer.
    /// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_DEBUG)</para>
    /// </summary>
    Debug = D3D10_CREATE_DEVICE_DEBUG,
    /// <summary>
    /// Create both a software (REF) and hardware (HAL) version of the device simultaneously, which allows an application to switch to a reference device to enable debugging. See SwitchToRef Object for more information.
    /// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_SWITCH_TO_REF)</para>
    /// </summary>
    SwitchToRef = D3D10_CREATE_DEVICE_SWITCH_TO_REF,
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS)</para>
    /// </summary>
    PreventInternalThreadingOptimizations = D3D10_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_ALLOW_NULL_FROM_MAP)</para>
    /// </summary>
    AllowNullFromMap = D3D10_CREATE_DEVICE_ALLOW_NULL_FROM_MAP,
    /// <summary>
    /// Create a device with BGRA support
    /// <para>(Also see DirectX SDK: D3D10_CREATE_DEVICE_BGRA_SUPPORT)</para>
    /// </summary>
    SupportBGRA = D3D10_CREATE_DEVICE_BGRA_SUPPORT,
};
/// <summary>
/// Indicates triangles facing a particular direction are not drawn.
/// <para>(Also see DirectX SDK: D3D10_CULL_MODE)</para>
/// </summary>
public enum class CullMode  : UInt32
{
    /// <summary>
    /// Always draw all triangles.
    /// <para>(Also see DirectX SDK: D3D10_CULL_NONE)</para>
    /// </summary>
    None = D3D10_CULL_NONE,
    /// <summary>
    /// Do not draw triangles that are front-facing.
    /// <para>(Also see DirectX SDK: D3D10_CULL_FRONT)</para>
    /// </summary>
    Front = D3D10_CULL_FRONT,
    /// <summary>
    /// Do not draw triangles that are back-facing.
    /// <para>(Also see DirectX SDK: D3D10_CULL_BACK)</para>
    /// </summary>
    Back = D3D10_CULL_BACK,
};
/// <summary>
/// Identify the portion of a depth-stencil buffer for writing depth data.
/// <para>(Also see DirectX SDK: D3D10_DEPTH_WRITE_MASK)</para>
/// </summary>
[Flags]
public enum class DepthWriteMask  : UInt32
{
    /// <summary>
    /// Turn off writes to the depth-stencil buffer.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_WRITE_MASK_ZERO)</para>
    /// </summary>
    Zero = D3D10_DEPTH_WRITE_MASK_ZERO,
    /// <summary>
    /// Turn on writes to the depth-stencil buffer.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_WRITE_MASK_ALL)</para>
    /// </summary>
    All = D3D10_DEPTH_WRITE_MASK_ALL,
};

/// <summary>
/// A value that identifies a portion of the depth-stencil buffer for reading stencil data.
/// </summary>
[Flags]
public enum class StencilReadMask  : Byte
{
    /// <summary>
    /// Zero.
    /// </summary>
    Zero = 0,
    /// <summary>
    /// Default Read Mask.
    /// <para>(Also see DirectX SDK: D3D10_DEFAULT_STENCIL_READ_MASK)</para>
    /// </summary>
    Default = D3D10_DEFAULT_STENCIL_READ_MASK,
};

/// <summary>
/// A value that identifies a portion of the depth-stencil buffer for writing stencil data.
/// </summary>
[Flags]
public enum class StencilWriteMask  : Byte
{
    /// <summary>
    /// Zero.
    /// </summary>
    Zero = 0,
    /// <summary>
    /// Default write Mask.
    /// <para>(Also see DirectX SDK: D3D10_DEFAULT_STENCIL_READ_MASK)</para>
    /// </summary>
    Default = D3D10_DEFAULT_STENCIL_WRITE_MASK,
};

/// <summary>
/// Effect device-state types.
/// <para>(Also see DirectX SDK: D3D10_DEVICE_STATE_TYPES)</para>
/// </summary>
public enum class DeviceStateTypes  : UInt32
{
    /// <summary>
    /// Stream-output buffer.
    /// <para>(Also see DirectX SDK: D3D10_DST_SO_BUFFERS)</para>
    /// </summary>
    StreamOutputBuffers = D3D10_DST_SO_BUFFERS,
    /// <summary>
    /// Render target.
    /// <para>(Also see DirectX SDK: D3D10_DST_OM_RENDER_TARGETS)</para>
    /// </summary>
    OutputMergeRenderTargets = D3D10_DST_OM_RENDER_TARGETS,
    /// <summary>
    /// Depth-stencil state.
    /// <para>(Also see DirectX SDK: D3D10_DST_OM_DEPTH_STENCIL_STATE)</para>
    /// </summary>
    OutputMergerDepthStencilState = D3D10_DST_OM_DEPTH_STENCIL_STATE,
    /// <summary>
    /// Blend state.
    /// <para>(Also see DirectX SDK: D3D10_DST_OM_BLEND_STATE)</para>
    /// </summary>
    OutputMergerBlendState = D3D10_DST_OM_BLEND_STATE,
    /// <summary>
    /// Vertex shader.
    /// <para>(Also see DirectX SDK: D3D10_DST_VS)</para>
    /// </summary>
    VertexShader = D3D10_DST_VS,
    /// <summary>
    /// Vertex shader sampler.
    /// <para>(Also see DirectX SDK: D3D10_DST_VS_SAMPLERS)</para>
    /// </summary>
    VertexShaderSamplers = D3D10_DST_VS_SAMPLERS,
    /// <summary>
    /// Vertex shader resource.
    /// <para>(Also see DirectX SDK: D3D10_DST_VS_SHADER_RESOURCES)</para>
    /// </summary>
    VertexShaderShaderResources = D3D10_DST_VS_SHADER_RESOURCES,
    /// <summary>
    /// Vertex shader constant buffer.
    /// <para>(Also see DirectX SDK: D3D10_DST_VS_CONSTANT_BUFFERS)</para>
    /// </summary>
    VertexShaderConstantBuffers = D3D10_DST_VS_CONSTANT_BUFFERS,
    /// <summary>
    /// Geometry shader.
    /// <para>(Also see DirectX SDK: D3D10_DST_GS)</para>
    /// </summary>
    GeometryShader = D3D10_DST_GS,
    /// <summary>
    /// Geometry shader sampler.
    /// <para>(Also see DirectX SDK: D3D10_DST_GS_SAMPLERS)</para>
    /// </summary>
    GeometryShaderSamplers = D3D10_DST_GS_SAMPLERS,
    /// <summary>
    /// Geometry shader resource.
    /// <para>(Also see DirectX SDK: D3D10_DST_GS_SHADER_RESOURCES)</para>
    /// </summary>
    GeometryShaderShaderResources = D3D10_DST_GS_SHADER_RESOURCES,
    /// <summary>
    /// Geometry shader constant buffer.
    /// <para>(Also see DirectX SDK: D3D10_DST_GS_CONSTANT_BUFFERS)</para>
    /// </summary>
    GeometryShaderConstantBuffers = D3D10_DST_GS_CONSTANT_BUFFERS,
    /// <summary>
    /// Pixel shader.
    /// <para>(Also see DirectX SDK: D3D10_DST_PS)</para>
    /// </summary>
    PixelShader = D3D10_DST_PS,
    /// <summary>
    /// Pixel shader sampler.
    /// <para>(Also see DirectX SDK: D3D10_DST_PS_SAMPLERS)</para>
    /// </summary>
    PixelShaderSamplers = D3D10_DST_PS_SAMPLERS,
    /// <summary>
    /// Pixel shader resource.
    /// <para>(Also see DirectX SDK: D3D10_DST_PS_SHADER_RESOURCES)</para>
    /// </summary>
    PixelShaderResources = D3D10_DST_PS_SHADER_RESOURCES,
    /// <summary>
    /// Pixel shader constant buffer.
    /// <para>(Also see DirectX SDK: D3D10_DST_PS_CONSTANT_BUFFERS)</para>
    /// </summary>
    PixelShaderConstantBuffers = D3D10_DST_PS_CONSTANT_BUFFERS,
    /// <summary>
    /// Input-assembler vertex buffer.
    /// <para>(Also see DirectX SDK: D3D10_DST_IA_VERTEX_BUFFERS)</para>
    /// </summary>
    InputAssemblerVertexBuffers = D3D10_DST_IA_VERTEX_BUFFERS,
    /// <summary>
    /// Input-assembler index buffer.
    /// <para>(Also see DirectX SDK: D3D10_DST_IA_INDEX_BUFFER)</para>
    /// </summary>
    InputAssemblerIndexBuffer = D3D10_DST_IA_INDEX_BUFFER,
    /// <summary>
    /// Input-assembler input layout.
    /// <para>(Also see DirectX SDK: D3D10_DST_IA_INPUT_LAYOUT)</para>
    /// </summary>
    InputAssemblerInputLayout = D3D10_DST_IA_INPUT_LAYOUT,
    /// <summary>
    /// Input-assembler primitive topology.
    /// <para>(Also see DirectX SDK: D3D10_DST_IA_PRIMITIVE_TOPOLOGY)</para>
    /// </summary>
    InputAssemblerPrimitiveTopology = D3D10_DST_IA_PRIMITIVE_TOPOLOGY,
    /// <summary>
    /// Viewport.
    /// <para>(Also see DirectX SDK: D3D10_DST_RS_VIEWPORTS)</para>
    /// </summary>
    RasterizerStateViewports = D3D10_DST_RS_VIEWPORTS,
    /// <summary>
    /// Scissor rectangle.
    /// <para>(Also see DirectX SDK: D3D10_DST_RS_SCISSOR_RECTS)</para>
    /// </summary>
    RasterizerStateScissorRects = D3D10_DST_RS_SCISSOR_RECTS,
    /// <summary>
    /// Rasterizer state.
    /// <para>(Also see DirectX SDK: D3D10_DST_RS_RASTERIZER_STATE)</para>
    /// </summary>
    RasterizerState = D3D10_DST_RS_RASTERIZER_STATE,
    /// <summary>
    /// Predication state.
    /// <para>(Also see DirectX SDK: D3D10_DST_PREDICATION)</para>
    /// </summary>
    Predication = D3D10_DST_PREDICATION,
};
/// <summary>
/// The device-driver type.
/// <para>(Also see DirectX SDK: D3D10_DRIVER_TYPE)</para>
/// </summary>
public enum class DriverType  : UInt32
{
    /// <summary>
    /// A hardware device; commonly called a HAL device.
    /// <para>(Also see DirectX SDK: D3D10_DRIVER_TYPE_HARDWARE)</para>
    /// </summary>
    Hardware = D3D10_DRIVER_TYPE_HARDWARE,
    /// <summary>
    /// A reference device; commonly called a REF device.
    /// <para>(Also see DirectX SDK: D3D10_DRIVER_TYPE_REFERENCE)</para>
    /// </summary>
    Reference = D3D10_DRIVER_TYPE_REFERENCE,
    /// <summary>
    /// A NULL device; which is a reference device without render capability.
    /// <para>(Also see DirectX SDK: D3D10_DRIVER_TYPE_NULL)</para>
    /// </summary>
    Null = D3D10_DRIVER_TYPE_NULL,
    /// <summary>
    /// Reserved for later use.
    /// <para>(Also see DirectX SDK: D3D10_DRIVER_TYPE_SOFTWARE)</para>
    /// </summary>
    Software = D3D10_DRIVER_TYPE_SOFTWARE,
};
/// <summary>
/// Specifies how to access a resource used in a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION)</para>
/// </summary>
public enum class DepthStencilViewDimension  : UInt32
{
    /// <summary>
    /// The resource will be accessed according to its type as determined from the actual instance this enumeration is paired with when the depth-stencil view is created.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_DSV_DIMENSION_UNKNOWN,
    /// <summary>
    /// The resource will be accessed as a 1D texture.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_DSV_DIMENSION_TEXTURE1D,
    /// <summary>
    /// The resource will be accessed as an array of 1D textures.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_TEXTURE1DARRAY)</para>
    /// </summary>
    Texture1DArray = D3D10_DSV_DIMENSION_TEXTURE1DARRAY,
    /// <summary>
    /// The resource will be accessed as a 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_DSV_DIMENSION_TEXTURE2D,
    /// <summary>
    /// The resource will be accessed as an array of 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_TEXTURE2DARRAY)</para>
    /// </summary>
    Texture2DArray = D3D10_DSV_DIMENSION_TEXTURE2DARRAY,
    /// <summary>
    /// The resource will be accessed as a 2D texture with multisampling.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_TEXTURE2DMS)</para>
    /// </summary>
    Texture2DMultiSample = D3D10_DSV_DIMENSION_TEXTURE2DMS,
    /// <summary>
    /// The resource will be accessed as an array of 2D textures with multisampling.
    /// <para>(Also see DirectX SDK: D3D10_DSV_DIMENSION_TEXTURE2DMSARRAY)</para>
    /// </summary>
    Texture2DMultiSampleArray = D3D10_DSV_DIMENSION_TEXTURE2DMSARRAY,
};


/// <summary>
/// Determines the fill mode to use when rendering triangles.
/// <para>(Also see DirectX SDK: D3D10_FILL_MODE)</para>
/// </summary>
public enum class FillMode  : UInt32
{
    /// <summary>
    /// Undefined.
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Draw lines connecting the vertices. Adjacent vertices are not drawn.
    /// <para>(Also see DirectX SDK: D3D10_FILL_WIREFRAME)</para>
    /// </summary>
    Wireframe = D3D10_FILL_WIREFRAME,
    /// <summary>
    /// Fill the triangles formed by the vertices. Adjacent vertices are not drawn.
    /// <para>(Also see DirectX SDK: D3D10_FILL_SOLID)</para>
    /// </summary>
    Solid = D3D10_FILL_SOLID,
};
/// <summary>
/// Filtering options during texture sampling.
/// <para>(Also see DirectX SDK: D3D10_FILTER)</para>
/// </summary>
public enum class Filter
{
    /// <summary>
    /// Use point sampling for minification, magnification, and mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_MAG_MIP_POINT)</para>
    /// </summary>
    MinMagMipPoint = D3D10_FILTER_MIN_MAG_MIP_POINT,
    /// <summary>
    /// Use point sampling for minification and magnification; use linear interpolation for mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR)</para>
    /// </summary>
    MinMagPointMipLinear = D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR,
    /// <summary>
    /// Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT)</para>
    /// </summary>
    MinPointMagLinearMipPoint = D3D10_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT,
    /// <summary>
    /// Use point sampling for minification; use linear interpolation for magnification and mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_POINT_MAG_MIP_LINEAR)</para>
    /// </summary>
    MinPointMagMipLinear = D3D10_FILTER_MIN_POINT_MAG_MIP_LINEAR,
    /// <summary>
    /// Use linear interpolation for minification; use point sampling for magnification and mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_LINEAR_MAG_MIP_POINT)</para>
    /// </summary>
    MinLinearMagMipPoint = D3D10_FILTER_MIN_LINEAR_MAG_MIP_POINT,
    /// <summary>
    /// Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR)</para>
    /// </summary>
    MinLinearMagPointMipLinear = D3D10_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
    /// <summary>
    /// Use linear interpolation for minification and magnification; use point sampling for mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_MAG_LINEAR_MIP_POINT)</para>
    /// </summary>
    MinMagLinearMipPoint = D3D10_FILTER_MIN_MAG_LINEAR_MIP_POINT,
    /// <summary>
    /// Use linear interpolation for minification, magnification, and mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_MIN_MAG_MIP_LINEAR)</para>
    /// </summary>
    MinMagMipLinear = D3D10_FILTER_MIN_MAG_MIP_LINEAR,
    /// <summary>
    /// Use anisotropic interpolation for minification, magnification, and mip-level sampling.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_ANISOTROPIC)</para>
    /// </summary>
    Anisotropic = D3D10_FILTER_ANISOTROPIC,
    /// <summary>
    /// Use point sampling for minification, magnification, and mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_MAG_MIP_POINT)</para>
    /// </summary>
    ComparisonMinMagMipPoint = D3D10_FILTER_COMPARISON_MIN_MAG_MIP_POINT,
    /// <summary>
    /// Use point sampling for minification and magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR)</para>
    /// </summary>
    ComparisonMinMagPointMipLinear = D3D10_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR,
    /// <summary>
    /// Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT)</para>
    /// </summary>
    ComparisonMinPointMagLinearMipPoint = D3D10_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT,
    /// <summary>
    /// Use point sampling for minification; use linear interpolation for magnification and mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR)</para>
    /// </summary>
    ComparisonMinPointMagMipLinear = D3D10_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR,
    /// <summary>
    /// Use linear interpolation for minification; use point sampling for magnification and mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT)</para>
    /// </summary>
    ComparisonMinLinearMagMipPoint = D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT,
    /// <summary>
    /// Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR)</para>
    /// </summary>
    ComparisonMinLinearMagPointMipLinear = D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
    /// <summary>
    /// Use linear interpolation for minification and magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT)</para>
    /// </summary>
    ComparisonMinMagLinearMipPoint = D3D10_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT,
    /// <summary>
    /// Use linear interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR)</para>
    /// </summary>
    ComparisonMinMagMipLinear = D3D10_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR,
    /// <summary>
    /// Use anisotropic interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_COMPARISON_ANISOTROPIC)</para>
    /// </summary>
    ComparisonAnisotropic = D3D10_FILTER_COMPARISON_ANISOTROPIC,
    /// <summary>
    /// For use in pixel shaders with textures that have the R1_UNORM format.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_TEXT_1BIT)</para>
    /// </summary>
    Text1bit = D3D10_FILTER_TEXT_1BIT,
};
/// <summary>
/// Types of magnification or minification sampler filters.
/// <para>(Also see DirectX SDK: D3D10_FILTER_TYPE)</para>
/// </summary>
public enum class FilterType  : UInt32
{
    /// <summary>
    /// Point filtering used as a texture magnification or minification filter. The texel with coordinates nearest to the desired pixel value is used. The texture filter to be used between mipmap levels is nearest-point mipmap filtering. The rasterizer uses the color from the texel of the nearest mipmap texture.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_TYPE_POINT)</para>
    /// </summary>
    Point = D3D10_FILTER_TYPE_POINT,
    /// <summary>
    /// Bilinear interpolation filtering used as a texture magnification or minification filter. A weighted average of a 2 x 2 area of texels surrounding the desired pixel is used. The texture filter to use between mipmap levels is trilinear mipmap interpolation. The rasterizer linearly interpolates pixel color, using the texels of the two nearest mipmap textures.
    /// <para>(Also see DirectX SDK: D3D10_FILTER_TYPE_LINEAR)</para>
    /// </summary>
    Linear = D3D10_FILTER_TYPE_LINEAR,
};
/// <summary>
/// Which resources are supported for a given format and given device.
/// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT)</para>
/// </summary>
[Flags]
public enum class FormatSupport  : UInt32
{
    /// <summary>
    /// Buffer resources supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_BUFFER)</para>
    /// </summary>
    Buffer = D3D10_FORMAT_SUPPORT_BUFFER,
    /// <summary>
    /// Vertex buffers supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_IA_VERTEX_BUFFER)</para>
    /// </summary>
    InputAssemblerVertexBuffer = D3D10_FORMAT_SUPPORT_IA_VERTEX_BUFFER,
    /// <summary>
    /// Index buffers supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_IA_INDEX_BUFFER)</para>
    /// </summary>
    InputAssemblerIndexBuffer = D3D10_FORMAT_SUPPORT_IA_INDEX_BUFFER,
    /// <summary>
    /// Streaming output buffers supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_SO_BUFFER)</para>
    /// </summary>
    StreamOutputBuffer = D3D10_FORMAT_SUPPORT_SO_BUFFER,
    /// <summary>
    /// 1D texture resources supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_FORMAT_SUPPORT_TEXTURE1D,
    /// <summary>
    /// 2D texture resources supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_FORMAT_SUPPORT_TEXTURE2D,
    /// <summary>
    /// 3D texture resources supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_TEXTURE3D)</para>
    /// </summary>
    Texture3D = D3D10_FORMAT_SUPPORT_TEXTURE3D,
    /// <summary>
    /// Cube texture resources supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_TEXTURECUBE)</para>
    /// </summary>
    TextureCube = D3D10_FORMAT_SUPPORT_TEXTURECUBE,
    /// <summary>
    /// The intrinsic HLSL function load is supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_SHADER_LOAD)</para>
    /// </summary>
    ShaderLoad = D3D10_FORMAT_SUPPORT_SHADER_LOAD,
    /// <summary>
    /// The intrinsic HLSL functions Sample supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_SHADER_SAMPLE)</para>
    /// </summary>
    ShaderSample = D3D10_FORMAT_SUPPORT_SHADER_SAMPLE,
    /// <summary>
    /// The intrinsic HLSL functions SampleCmp and SampleCmpLevelZero are supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_COMPARISON)</para>
    /// </summary>
    ShaderSampleComparison = D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_COMPARISON,
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_MONO_TEXT)</para>
    /// </summary>
    ShaderSampleMonoText = D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_MONO_TEXT,
    /// <summary>
    /// Mipmaps are supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_MIP)</para>
    /// </summary>
    Mip = D3D10_FORMAT_SUPPORT_MIP,
    /// <summary>
    /// Automatic generation of mipmaps is supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_MIP_AUTOGEN)</para>
    /// </summary>
    MipAutoGeneration = D3D10_FORMAT_SUPPORT_MIP_AUTOGEN,
    /// <summary>
    /// Rendertargets are supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_RENDER_TARGET)</para>
    /// </summary>
    RenderTarget = D3D10_FORMAT_SUPPORT_RENDER_TARGET,
    /// <summary>
    /// Blend operations supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_BLENDABLE)</para>
    /// </summary>
    Blendable = D3D10_FORMAT_SUPPORT_BLENDABLE,
    /// <summary>
    /// Depth stencils supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_DEPTH_STENCIL)</para>
    /// </summary>
    DepthStencil = D3D10_FORMAT_SUPPORT_DEPTH_STENCIL,
    /// <summary>
    /// CPU locking supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_CPU_LOCKABLE)</para>
    /// </summary>
    CpuLockable = D3D10_FORMAT_SUPPORT_CPU_LOCKABLE,
    /// <summary>
    /// Multisampling resolution supported.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE)</para>
    /// </summary>
    MultiSampleResolve = D3D10_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE,
    /// <summary>
    /// Format can be displayed on screen.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_DISPLAY)</para>
    /// </summary>
    Display = D3D10_FORMAT_SUPPORT_DISPLAY,
    /// <summary>
    /// Format cannot be cast to another format.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_CAST_WITHIN_BIT_LAYOUT)</para>
    /// </summary>
    CastWithinBitLayout = D3D10_FORMAT_SUPPORT_CAST_WITHIN_BIT_LAYOUT,
    /// <summary>
    /// Format can be used as a multisampled rendertarget.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET)</para>
    /// </summary>
    MultiSampleRendertarget = D3D10_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET,
    /// <summary>
    /// Format can be used as a multisampled texture and read into a shader with the load function.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_MULTISAMPLE_LOAD)</para>
    /// </summary>
    MultiSampleLoad = D3D10_FORMAT_SUPPORT_MULTISAMPLE_LOAD,
    /// <summary>
    /// Format can be used with the gather function. This value is available in DirectX 10.1 or higher.
    /// <para>(Also see DirectX SDK: D3D10_FORMAT_SUPPORT_SHADER_GATHER)</para>
    /// </summary>
    ShaderGather = D3D10_FORMAT_SUPPORT_SHADER_GATHER,
};
/// <summary>
/// Flags for indicating the location of an include file.
/// <para>(Also see DirectX SDK: D3D10_INCLUDE_TYPE)</para>
/// </summary>
public enum class IncludeType  : UInt32
{
    /// <summary>
    /// The local directory.
    /// <para>(Also see DirectX SDK: D3D10_INCLUDE_LOCAL)</para>
    /// </summary>
    Local = D3D10_INCLUDE_LOCAL,
    /// <summary>
    /// The system directory.
    /// <para>(Also see DirectX SDK: D3D10_INCLUDE_SYSTEM)</para>
    /// </summary>
    System = D3D10_INCLUDE_SYSTEM,
};
/// <summary>
/// Type of data contained in an input slot.
/// <para>(Also see DirectX SDK: D3D10_INPUT_CLASSIFICATION)</para>
/// </summary>
public enum class InputClassification  : UInt32
{
    /// <summary>
    /// Input data is per-vertex data.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_PER_VERTEX_DATA)</para>
    /// </summary>
    PerVertexData = D3D10_INPUT_PER_VERTEX_DATA,
    /// <summary>
    /// Input data is per-instance data.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_PER_INSTANCE_DATA)</para>
    /// </summary>
    PerInstanceData = D3D10_INPUT_PER_INSTANCE_DATA,
};
/// <summary>
/// Identifies a resource to be accessed for reading and writing by the CPU. Applications may combine one or more of these flags.
/// <para>(Also see DirectX SDK: D3D10_MAP)</para>
/// </summary>
public enum class Map : UInt32
{
    /// <summary>
    /// Resource is mapped for reading. The resource must have been created with read access (see <see cref="Read"/>)<seealso cref="Read"/>.
    /// <para>(Also see DirectX SDK: D3D10_MAP_READ)</para>
    /// </summary>
    Read = D3D10_MAP_READ,
    /// <summary>
    /// Resource is mapped for writing. The resource must have been created with write access (see <see cref="Write"/>)<seealso cref="Write"/>.
    /// <para>(Also see DirectX SDK: D3D10_MAP_WRITE)</para>
    /// </summary>
    Write = D3D10_MAP_WRITE,
    /// <summary>
    /// Resource is mapped for reading and writing. The resource must have been created with read and write access (see Read and Write).
    /// <para>(Also see DirectX SDK: D3D10_MAP_READ_WRITE)</para>
    /// </summary>
    ReadWrite = D3D10_MAP_READ_WRITE,
    /// <summary>
    /// Resource is mapped for writing; the previous contents of the resource will be undefined. The resource must have been created with write access (see <see cref="Write"/>)<seealso cref="Write"/>.
    /// <para>(Also see DirectX SDK: D3D10_MAP_WRITE_DISCARD)</para>
    /// </summary>
    WriteDiscard = D3D10_MAP_WRITE_DISCARD,
    /// <summary>
    /// Resource is mapped for writing; the existing contents of the resource cannot be overwritten. This flag is only valid on vertex and index buffers. The resource must have been created with write access (see <see cref="Write"/>)<seealso cref="Write"/>. Cannot be used on a resource created with the ConstantBuffer flag.
    /// <para>(Also see DirectX SDK: D3D10_MAP_WRITE_NO_OVERWRITE)</para>
    /// </summary>
    WriteNoOverwrite = D3D10_MAP_WRITE_NO_OVERWRITE,
};
/// <summary>
/// Specifies how the CPU should respond when Map is called on a resource being used by the GPU.
/// <para>(Also see DirectX SDK: D3D10_MAP_FLAG)</para>
/// </summary>
[Flags]
public enum class MapFlag  : UInt32
{
    /// <summary>
    /// Unspecified flag
    /// </summary>
    Unspecified = 0,

    /// <summary>
    /// Specifies that Map should return E_WASSTILLRENDERING when the GPU blocks the CPU from accessing a resource.
    /// <para>(Also see DirectX SDK: D3D10_MAP_FLAG_DO_NOT_WAIT)</para>
    /// </summary>
    DoNotWait = D3D10_MAP_FLAG_DO_NOT_WAIT,
};

/// <summary>
/// Categories of debug messages. This will identify the category of a message when retrieving a message with InfoQueue.GetMessage and when adding a message with InfoQueue.AddMessage. When creating an info queue filter, these values can be used to allow or deny any categories of messages to pass through the storage and retrieval filters.
/// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY)</para>
/// </summary>
public enum class MessageCategory  : UInt32
{
    /// <summary>
    /// User defined message. See InfoQueue.AddMessage.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_APPLICATION_DEFINED)</para>
    /// </summary>
    ApplicationDefined = D3D10_MESSAGE_CATEGORY_APPLICATION_DEFINED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_MISCELLANEOUS)</para>
    /// </summary>
    Miscellaneous = D3D10_MESSAGE_CATEGORY_MISCELLANEOUS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_INITIALIZATION)</para>
    /// </summary>
    Initialization = D3D10_MESSAGE_CATEGORY_INITIALIZATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_CLEANUP)</para>
    /// </summary>
    Cleanup = D3D10_MESSAGE_CATEGORY_CLEANUP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_COMPILATION)</para>
    /// </summary>
    Compilation = D3D10_MESSAGE_CATEGORY_COMPILATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_STATE_CREATION)</para>
    /// </summary>
    StateCreation = D3D10_MESSAGE_CATEGORY_STATE_CREATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_STATE_SETTING)</para>
    /// </summary>
    StateSetting = D3D10_MESSAGE_CATEGORY_STATE_SETTING,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_STATE_GETTING)</para>
    /// </summary>
    StateGetting = D3D10_MESSAGE_CATEGORY_STATE_GETTING,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_RESOURCE_MANIPULATION)</para>
    /// </summary>
    ResourceManipulation = D3D10_MESSAGE_CATEGORY_RESOURCE_MANIPULATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_CATEGORY_EXECUTION)</para>
    /// </summary>
    Execution = D3D10_MESSAGE_CATEGORY_EXECUTION,
};
/// <summary>
/// Debug messages for setting up an info-queue filter; use these messages to allow or deny message categories to pass through the storage and retrieval filters. These IDs are used by methods such as InfoQueue.GetMessage or InfoQueue.AddMessage.
/// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID)</para>
/// </summary>
public enum class MessageId  : UInt32
{
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_MESSAGE_ID_UNKNOWN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_HAZARD)</para>
    /// </summary>
    DeviceIasetvertexbuffersHazard = D3D10_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_HAZARD)</para>
    /// </summary>
    DeviceIasetindexbufferHazard = D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_HAZARD)</para>
    /// </summary>
    DeviceVssetshaderresourcesHazard = D3D10_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_HAZARD)</para>
    /// </summary>
    DeviceVssetconstantbuffersHazard = D3D10_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_HAZARD)</para>
    /// </summary>
    DeviceGssetshaderresourcesHazard = D3D10_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_HAZARD)</para>
    /// </summary>
    DeviceGssetconstantbuffersHazard = D3D10_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_HAZARD)</para>
    /// </summary>
    DevicePssetshaderresourcesHazard = D3D10_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_HAZARD)</para>
    /// </summary>
    DevicePssetconstantbuffersHazard = D3D10_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_OMSETRENDERTARGETS_HAZARD)</para>
    /// </summary>
    DeviceOmsetrendertargetsHazard = D3D10_MESSAGE_ID_DEVICE_OMSETRENDERTARGETS_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SOSETTARGETS_HAZARD)</para>
    /// </summary>
    DeviceSosettargetsHazard = D3D10_MESSAGE_ID_DEVICE_SOSETTARGETS_HAZARD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_STRING_FROM_APPLICATION)</para>
    /// </summary>
    StringFromApplication = D3D10_MESSAGE_ID_STRING_FROM_APPLICATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_THIS)</para>
    /// </summary>
    CorruptedThis = D3D10_MESSAGE_ID_CORRUPTED_THIS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER1)</para>
    /// </summary>
    CorruptedParameter1 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER1,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER2)</para>
    /// </summary>
    CorruptedParameter2 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER2,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER3)</para>
    /// </summary>
    CorruptedParameter3 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER3,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER4)</para>
    /// </summary>
    CorruptedParameter4 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER4,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER5)</para>
    /// </summary>
    CorruptedParameter5 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER5,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER6)</para>
    /// </summary>
    CorruptedParameter6 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER6,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER7)</para>
    /// </summary>
    CorruptedParameter7 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER7,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER8)</para>
    /// </summary>
    CorruptedParameter8 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER8,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER9)</para>
    /// </summary>
    CorruptedParameter9 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER9,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER10)</para>
    /// </summary>
    CorruptedParameter10 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER10,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER11)</para>
    /// </summary>
    CorruptedParameter11 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER11,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER12)</para>
    /// </summary>
    CorruptedParameter12 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER12,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER13)</para>
    /// </summary>
    CorruptedParameter13 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER13,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER14)</para>
    /// </summary>
    CorruptedParameter14 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER14,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_PARAMETER15)</para>
    /// </summary>
    CorruptedParameter15 = D3D10_MESSAGE_ID_CORRUPTED_PARAMETER15,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CORRUPTED_MULTITHREADING)</para>
    /// </summary>
    CorruptedMultithreading = D3D10_MESSAGE_ID_CORRUPTED_MULTITHREADING,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY)</para>
    /// </summary>
    MessageReportingOutofmemory = D3D10_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_IASETINPUTLAYOUT_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    IasetinputlayoutUnbinddeletingobject = D3D10_MESSAGE_ID_IASETINPUTLAYOUT_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_IASETVERTEXBUFFERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    IasetvertexbuffersUnbinddeletingobject = D3D10_MESSAGE_ID_IASETVERTEXBUFFERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_IASETINDEXBUFFER_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    IasetindexbufferUnbinddeletingobject = D3D10_MESSAGE_ID_IASETINDEXBUFFER_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_VSSETSHADER_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    VssetshaderUnbinddeletingobject = D3D10_MESSAGE_ID_VSSETSHADER_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_VSSETSHADERRESOURCES_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    VssetshaderresourcesUnbinddeletingobject = D3D10_MESSAGE_ID_VSSETSHADERRESOURCES_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_VSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    VssetconstantbuffersUnbinddeletingobject = D3D10_MESSAGE_ID_VSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_VSSETSAMPLERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    VssetsamplersUnbinddeletingobject = D3D10_MESSAGE_ID_VSSETSAMPLERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_GSSETSHADER_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    GssetshaderUnbinddeletingobject = D3D10_MESSAGE_ID_GSSETSHADER_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_GSSETSHADERRESOURCES_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    GssetshaderresourcesUnbinddeletingobject = D3D10_MESSAGE_ID_GSSETSHADERRESOURCES_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_GSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    GssetconstantbuffersUnbinddeletingobject = D3D10_MESSAGE_ID_GSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_GSSETSAMPLERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    GssetsamplersUnbinddeletingobject = D3D10_MESSAGE_ID_GSSETSAMPLERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SOSETTARGETS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    SosettargetsUnbinddeletingobject = D3D10_MESSAGE_ID_SOSETTARGETS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PSSETSHADER_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    PssetshaderUnbinddeletingobject = D3D10_MESSAGE_ID_PSSETSHADER_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PSSETSHADERRESOURCES_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    PssetshaderresourcesUnbinddeletingobject = D3D10_MESSAGE_ID_PSSETSHADERRESOURCES_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    PssetconstantbuffersUnbinddeletingobject = D3D10_MESSAGE_ID_PSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PSSETSAMPLERS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    PssetsamplersUnbinddeletingobject = D3D10_MESSAGE_ID_PSSETSAMPLERS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_RSSETSTATE_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    RssetstateUnbinddeletingobject = D3D10_MESSAGE_ID_RSSETSTATE_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_OMSETBLENDSTATE_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    OmsetblendstateUnbinddeletingobject = D3D10_MESSAGE_ID_OMSETBLENDSTATE_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_OMSETDEPTHSTENCILSTATE_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    OmsetdepthstencilstateUnbinddeletingobject = D3D10_MESSAGE_ID_OMSETDEPTHSTENCILSTATE_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_OMSETRENDERTARGETS_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    OmsetrendertargetsUnbinddeletingobject = D3D10_MESSAGE_ID_OMSETRENDERTARGETS_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPREDICATION_UNBINDDELETINGOBJECT)</para>
    /// </summary>
    SetpredicationUnbinddeletingobject = D3D10_MESSAGE_ID_SETPREDICATION_UNBINDDELETINGOBJECT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_GETPRIVATEDATA_MOREDATA)</para>
    /// </summary>
    GetprivatedataMoredata = D3D10_MESSAGE_ID_GETPRIVATEDATA_MOREDATA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA)</para>
    /// </summary>
    SetprivatedataInvalidfreedata = D3D10_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPRIVATEDATA_INVALIDIUNKNOWN)</para>
    /// </summary>
    SetprivatedataInvalidiunknown = D3D10_MESSAGE_ID_SETPRIVATEDATA_INVALIDIUNKNOWN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPRIVATEDATA_INVALIDFLAGS)</para>
    /// </summary>
    SetprivatedataInvalidflags = D3D10_MESSAGE_ID_SETPRIVATEDATA_INVALIDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS)</para>
    /// </summary>
    SetprivatedataChangingparams = D3D10_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY)</para>
    /// </summary>
    SetprivatedataOutofmemory = D3D10_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    CreatebufferUnrecognizedformat = D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDSAMPLES)</para>
    /// </summary>
    CreatebufferInvalidsamples = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDSAMPLES,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDUSAGE)</para>
    /// </summary>
    CreatebufferUnrecognizedusage = D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDUSAGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDBINDFLAGS)</para>
    /// </summary>
    CreatebufferUnrecognizedbindflags = D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDCPUACCESSFLAGS)</para>
    /// </summary>
    CreatebufferUnrecognizedcpuaccessflags = D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDMISCFLAGS)</para>
    /// </summary>
    CreatebufferUnrecognizedmiscflags = D3D10_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDCPUACCESSFLAGS)</para>
    /// </summary>
    CreatebufferInvalidcpuaccessflags = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDBINDFLAGS)</para>
    /// </summary>
    CreatebufferInvalidbindflags = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDINITIALDATA)</para>
    /// </summary>
    CreatebufferInvalidinitialdata = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDINITIALDATA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDDIMENSIONS)</para>
    /// </summary>
    CreatebufferInvaliddimensions = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDMIPLEVELS)</para>
    /// </summary>
    CreatebufferInvalidmiplevels = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDMIPLEVELS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDMISCFLAGS)</para>
    /// </summary>
    CreatebufferInvalidmiscflags = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDARG_RETURN)</para>
    /// </summary>
    CreatebufferInvalidargReturn = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreatebufferOutofmemoryReturn = D3D10_MESSAGE_ID_CREATEBUFFER_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_NULLDESC)</para>
    /// </summary>
    CreatebufferNulldesc = D3D10_MESSAGE_ID_CREATEBUFFER_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDCONSTANTBUFFERBINDINGS)</para>
    /// </summary>
    CreatebufferInvalidconstantbufferbindings = D3D10_MESSAGE_ID_CREATEBUFFER_INVALIDCONSTANTBUFFERBINDINGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBUFFER_LARGEALLOCATION)</para>
    /// </summary>
    CreatebufferLargeallocation = D3D10_MESSAGE_ID_CREATEBUFFER_LARGEALLOCATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    Createtexture1dUnrecognizedformat = D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_UNSUPPORTEDFORMAT)</para>
    /// </summary>
    Createtexture1dUnsupportedformat = D3D10_MESSAGE_ID_CREATETEXTURE1D_UNSUPPORTEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDSAMPLES)</para>
    /// </summary>
    Createtexture1dInvalidsamples = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDSAMPLES,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDUSAGE)</para>
    /// </summary>
    Createtexture1dUnrecognizedusage = D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDUSAGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDBINDFLAGS)</para>
    /// </summary>
    Createtexture1dUnrecognizedbindflags = D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDCPUACCESSFLAGS)</para>
    /// </summary>
    Createtexture1dUnrecognizedcpuaccessflags = D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDMISCFLAGS)</para>
    /// </summary>
    Createtexture1dUnrecognizedmiscflags = D3D10_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDCPUACCESSFLAGS)</para>
    /// </summary>
    Createtexture1dInvalidcpuaccessflags = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDBINDFLAGS)</para>
    /// </summary>
    Createtexture1dInvalidbindflags = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDINITIALDATA)</para>
    /// </summary>
    Createtexture1dInvalidinitialdata = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDINITIALDATA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDDIMENSIONS)</para>
    /// </summary>
    Createtexture1dInvaliddimensions = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDMIPLEVELS)</para>
    /// </summary>
    Createtexture1dInvalidmiplevels = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDMIPLEVELS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDMISCFLAGS)</para>
    /// </summary>
    Createtexture1dInvalidmiscflags = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDARG_RETURN)</para>
    /// </summary>
    Createtexture1dInvalidargReturn = D3D10_MESSAGE_ID_CREATETEXTURE1D_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    Createtexture1dOutofmemoryReturn = D3D10_MESSAGE_ID_CREATETEXTURE1D_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_NULLDESC)</para>
    /// </summary>
    Createtexture1dNulldesc = D3D10_MESSAGE_ID_CREATETEXTURE1D_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE1D_LARGEALLOCATION)</para>
    /// </summary>
    Createtexture1dLargeallocation = D3D10_MESSAGE_ID_CREATETEXTURE1D_LARGEALLOCATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    Createtexture2dUnrecognizedformat = D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_UNSUPPORTEDFORMAT)</para>
    /// </summary>
    Createtexture2dUnsupportedformat = D3D10_MESSAGE_ID_CREATETEXTURE2D_UNSUPPORTEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDSAMPLES)</para>
    /// </summary>
    Createtexture2dInvalidsamples = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDSAMPLES,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDUSAGE)</para>
    /// </summary>
    Createtexture2dUnrecognizedusage = D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDUSAGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDBINDFLAGS)</para>
    /// </summary>
    Createtexture2dUnrecognizedbindflags = D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDCPUACCESSFLAGS)</para>
    /// </summary>
    Createtexture2dUnrecognizedcpuaccessflags = D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDMISCFLAGS)</para>
    /// </summary>
    Createtexture2dUnrecognizedmiscflags = D3D10_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDCPUACCESSFLAGS)</para>
    /// </summary>
    Createtexture2dInvalidcpuaccessflags = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDBINDFLAGS)</para>
    /// </summary>
    Createtexture2dInvalidbindflags = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDINITIALDATA)</para>
    /// </summary>
    Createtexture2dInvalidinitialdata = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDINITIALDATA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDDIMENSIONS)</para>
    /// </summary>
    Createtexture2dInvaliddimensions = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDMIPLEVELS)</para>
    /// </summary>
    Createtexture2dInvalidmiplevels = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDMIPLEVELS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDMISCFLAGS)</para>
    /// </summary>
    Createtexture2dInvalidmiscflags = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDARG_RETURN)</para>
    /// </summary>
    Createtexture2dInvalidargReturn = D3D10_MESSAGE_ID_CREATETEXTURE2D_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    Createtexture2dOutofmemoryReturn = D3D10_MESSAGE_ID_CREATETEXTURE2D_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_NULLDESC)</para>
    /// </summary>
    Createtexture2dNulldesc = D3D10_MESSAGE_ID_CREATETEXTURE2D_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE2D_LARGEALLOCATION)</para>
    /// </summary>
    Createtexture2dLargeallocation = D3D10_MESSAGE_ID_CREATETEXTURE2D_LARGEALLOCATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    Createtexture3dUnrecognizedformat = D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_UNSUPPORTEDFORMAT)</para>
    /// </summary>
    Createtexture3dUnsupportedformat = D3D10_MESSAGE_ID_CREATETEXTURE3D_UNSUPPORTEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDSAMPLES)</para>
    /// </summary>
    Createtexture3dInvalidsamples = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDSAMPLES,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDUSAGE)</para>
    /// </summary>
    Createtexture3dUnrecognizedusage = D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDUSAGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDBINDFLAGS)</para>
    /// </summary>
    Createtexture3dUnrecognizedbindflags = D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDCPUACCESSFLAGS)</para>
    /// </summary>
    Createtexture3dUnrecognizedcpuaccessflags = D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDMISCFLAGS)</para>
    /// </summary>
    Createtexture3dUnrecognizedmiscflags = D3D10_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDCPUACCESSFLAGS)</para>
    /// </summary>
    Createtexture3dInvalidcpuaccessflags = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDCPUACCESSFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDBINDFLAGS)</para>
    /// </summary>
    Createtexture3dInvalidbindflags = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDBINDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDINITIALDATA)</para>
    /// </summary>
    Createtexture3dInvalidinitialdata = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDINITIALDATA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDDIMENSIONS)</para>
    /// </summary>
    Createtexture3dInvaliddimensions = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDMIPLEVELS)</para>
    /// </summary>
    Createtexture3dInvalidmiplevels = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDMIPLEVELS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDMISCFLAGS)</para>
    /// </summary>
    Createtexture3dInvalidmiscflags = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDARG_RETURN)</para>
    /// </summary>
    Createtexture3dInvalidargReturn = D3D10_MESSAGE_ID_CREATETEXTURE3D_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    Createtexture3dOutofmemoryReturn = D3D10_MESSAGE_ID_CREATETEXTURE3D_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_NULLDESC)</para>
    /// </summary>
    Createtexture3dNulldesc = D3D10_MESSAGE_ID_CREATETEXTURE3D_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATETEXTURE3D_LARGEALLOCATION)</para>
    /// </summary>
    Createtexture3dLargeallocation = D3D10_MESSAGE_ID_CREATETEXTURE3D_LARGEALLOCATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    CreateshaderresourceviewUnrecognizedformat = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC)</para>
    /// </summary>
    CreateshaderresourceviewInvaliddesc = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT)</para>
    /// </summary>
    CreateshaderresourceviewInvalidformat = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS)</para>
    /// </summary>
    CreateshaderresourceviewInvaliddimensions = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE)</para>
    /// </summary>
    CreateshaderresourceviewInvalidresource = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_TOOMANYOBJECTS)</para>
    /// </summary>
    CreateshaderresourceviewToomanyobjects = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDARG_RETURN)</para>
    /// </summary>
    CreateshaderresourceviewInvalidargReturn = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreateshaderresourceviewOutofmemoryReturn = D3D10_MESSAGE_ID_CREATESHADERRESOURCEVIEW_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    CreaterendertargetviewUnrecognizedformat = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT)</para>
    /// </summary>
    CreaterendertargetviewUnsupportedformat = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC)</para>
    /// </summary>
    CreaterendertargetviewInvaliddesc = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT)</para>
    /// </summary>
    CreaterendertargetviewInvalidformat = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS)</para>
    /// </summary>
    CreaterendertargetviewInvaliddimensions = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE)</para>
    /// </summary>
    CreaterendertargetviewInvalidresource = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_TOOMANYOBJECTS)</para>
    /// </summary>
    CreaterendertargetviewToomanyobjects = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDARG_RETURN)</para>
    /// </summary>
    CreaterendertargetviewInvalidargReturn = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreaterendertargetviewOutofmemoryReturn = D3D10_MESSAGE_ID_CREATERENDERTARGETVIEW_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT)</para>
    /// </summary>
    CreatedepthstencilviewUnrecognizedformat = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC)</para>
    /// </summary>
    CreatedepthstencilviewInvaliddesc = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT)</para>
    /// </summary>
    CreatedepthstencilviewInvalidformat = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS)</para>
    /// </summary>
    CreatedepthstencilviewInvaliddimensions = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE)</para>
    /// </summary>
    CreatedepthstencilviewInvalidresource = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_TOOMANYOBJECTS)</para>
    /// </summary>
    CreatedepthstencilviewToomanyobjects = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDARG_RETURN)</para>
    /// </summary>
    CreatedepthstencilviewInvalidargReturn = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreatedepthstencilviewOutofmemoryReturn = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY)</para>
    /// </summary>
    CreateinputlayoutOutofmemory = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS)</para>
    /// </summary>
    CreateinputlayoutToomanyelements = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT)</para>
    /// </summary>
    CreateinputlayoutInvalidformat = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT)</para>
    /// </summary>
    CreateinputlayoutIncompatibleformat = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT)</para>
    /// </summary>
    CreateinputlayoutInvalidslot = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS)</para>
    /// </summary>
    CreateinputlayoutInvalidinputslotclass = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH)</para>
    /// </summary>
    CreateinputlayoutSteprateslotclassmismatch = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE)</para>
    /// </summary>
    CreateinputlayoutInvalidslotclasschange = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE)</para>
    /// </summary>
    CreateinputlayoutInvalidstepratechange = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT)</para>
    /// </summary>
    CreateinputlayoutInvalidalignment = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC)</para>
    /// </summary>
    CreateinputlayoutDuplicatesemantic = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE)</para>
    /// </summary>
    CreateinputlayoutUnparseableinputsignature = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC)</para>
    /// </summary>
    CreateinputlayoutNullsemantic = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT)</para>
    /// </summary>
    CreateinputlayoutMissingelement = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_NULLDESC)</para>
    /// </summary>
    CreateinputlayoutNulldesc = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY)</para>
    /// </summary>
    CreatevertexshaderOutofmemory = D3D10_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE)</para>
    /// </summary>
    CreatevertexshaderInvalidshaderbytecode = D3D10_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE)</para>
    /// </summary>
    CreatevertexshaderInvalidshadertype = D3D10_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY)</para>
    /// </summary>
    CreategeometryshaderOutofmemory = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE)</para>
    /// </summary>
    CreategeometryshaderInvalidshaderbytecode = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE)</para>
    /// </summary>
    CreategeometryshaderInvalidshadertype = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputOutofmemory = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidshaderbytecode = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidshadertype = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidnumentries = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputOutputstreamstrideunused = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDDECL)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputUnexpecteddecl = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDDECL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_EXPECTEDDECL)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputExpecteddecl = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_EXPECTEDDECL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputOutputslot0expected = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidoutputslot = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputOnlyoneelementperslot = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidcomponentcount = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidstartcomponentandcomponentcount = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidgapdefinition = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputRepeatedoutput = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputInvalidoutputstreamstride = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputMissingsemantic = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputMaskmismatch = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputCanthaveonlygaps = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputDecltoocomplex = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputMissingoutputsignature = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY)</para>
    /// </summary>
    CreatepixelshaderOutofmemory = D3D10_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE)</para>
    /// </summary>
    CreatepixelshaderInvalidshaderbytecode = D3D10_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE)</para>
    /// </summary>
    CreatepixelshaderInvalidshadertype = D3D10_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE)</para>
    /// </summary>
    CreaterasterizerstateInvalidfillmode = D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE)</para>
    /// </summary>
    CreaterasterizerstateInvalidcullmode = D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP)</para>
    /// </summary>
    CreaterasterizerstateInvaliddepthbiasclamp = D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS)</para>
    /// </summary>
    CreaterasterizerstateInvalidslopescaleddepthbias = D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_TOOMANYOBJECTS)</para>
    /// </summary>
    CreaterasterizerstateToomanyobjects = D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_NULLDESC)</para>
    /// </summary>
    CreaterasterizerstateNulldesc = D3D10_MESSAGE_ID_CREATERASTERIZERSTATE_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK)</para>
    /// </summary>
    CreatedepthstencilstateInvaliddepthwritemask = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC)</para>
    /// </summary>
    CreatedepthstencilstateInvaliddepthfunc = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP)</para>
    /// </summary>
    CreatedepthstencilstateInvalidfrontfacestencilfailop = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP)</para>
    /// </summary>
    CreatedepthstencilstateInvalidfrontfacestencilzfailop = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP)</para>
    /// </summary>
    CreatedepthstencilstateInvalidfrontfacestencilpassop = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC)</para>
    /// </summary>
    CreatedepthstencilstateInvalidfrontfacestencilfunc = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP)</para>
    /// </summary>
    CreatedepthstencilstateInvalidbackfacestencilfailop = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP)</para>
    /// </summary>
    CreatedepthstencilstateInvalidbackfacestencilzfailop = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP)</para>
    /// </summary>
    CreatedepthstencilstateInvalidbackfacestencilpassop = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC)</para>
    /// </summary>
    CreatedepthstencilstateInvalidbackfacestencilfunc = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_TOOMANYOBJECTS)</para>
    /// </summary>
    CreatedepthstencilstateToomanyobjects = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_NULLDESC)</para>
    /// </summary>
    CreatedepthstencilstateNulldesc = D3D10_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND)</para>
    /// </summary>
    CreateblendstateInvalidsrcblend = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND)</para>
    /// </summary>
    CreateblendstateInvaliddestblend = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP)</para>
    /// </summary>
    CreateblendstateInvalidblendop = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA)</para>
    /// </summary>
    CreateblendstateInvalidsrcblendalpha = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA)</para>
    /// </summary>
    CreateblendstateInvaliddestblendalpha = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA)</para>
    /// </summary>
    CreateblendstateInvalidblendopalpha = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK)</para>
    /// </summary>
    CreateblendstateInvalidrendertargetwritemask = D3D10_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_TOOMANYOBJECTS)</para>
    /// </summary>
    CreateblendstateToomanyobjects = D3D10_MESSAGE_ID_CREATEBLENDSTATE_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEBLENDSTATE_NULLDESC)</para>
    /// </summary>
    CreateblendstateNulldesc = D3D10_MESSAGE_ID_CREATEBLENDSTATE_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDFILTER)</para>
    /// </summary>
    CreatesamplerstateInvalidfilter = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDFILTER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSU)</para>
    /// </summary>
    CreatesamplerstateInvalidaddressu = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSU,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSV)</para>
    /// </summary>
    CreatesamplerstateInvalidaddressv = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSV,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSW)</para>
    /// </summary>
    CreatesamplerstateInvalidaddressw = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMIPLODBIAS)</para>
    /// </summary>
    CreatesamplerstateInvalidmiplodbias = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMIPLODBIAS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXANISOTROPY)</para>
    /// </summary>
    CreatesamplerstateInvalidmaxanisotropy = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXANISOTROPY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDCOMPARISONFUNC)</para>
    /// </summary>
    CreatesamplerstateInvalidcomparisonfunc = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDCOMPARISONFUNC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMINLOD)</para>
    /// </summary>
    CreatesamplerstateInvalidminlod = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMINLOD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXLOD)</para>
    /// </summary>
    CreatesamplerstateInvalidmaxlod = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXLOD,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_TOOMANYOBJECTS)</para>
    /// </summary>
    CreatesamplerstateToomanyobjects = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_TOOMANYOBJECTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATESAMPLERSTATE_NULLDESC)</para>
    /// </summary>
    CreatesamplerstateNulldesc = D3D10_MESSAGE_ID_CREATESAMPLERSTATE_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDQUERY)</para>
    /// </summary>
    CreatequeryorpredicateInvalidquery = D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDQUERY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDMISCFLAGS)</para>
    /// </summary>
    CreatequeryorpredicateInvalidmiscflags = D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDMISCFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_UNEXPECTEDMISCFLAG)</para>
    /// </summary>
    CreatequeryorpredicateUnexpectedmiscflag = D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_UNEXPECTEDMISCFLAG,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_NULLDESC)</para>
    /// </summary>
    CreatequeryorpredicateNulldesc = D3D10_MESSAGE_ID_CREATEQUERYORPREDICATE_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNRECOGNIZED)</para>
    /// </summary>
    DeviceIasetprimitivetopologyTopologyUnrecognized = D3D10_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNRECOGNIZED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNDEFINED)</para>
    /// </summary>
    DeviceIasetprimitivetopologyTopologyUndefined = D3D10_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNDEFINED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_IASETVERTEXBUFFERS_INVALIDBUFFER)</para>
    /// </summary>
    IasetvertexbuffersInvalidbuffer = D3D10_MESSAGE_ID_IASETVERTEXBUFFERS_INVALIDBUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_OFFSET_TOO_LARGE)</para>
    /// </summary>
    DeviceIasetvertexbuffersOffsetTooLarge = D3D10_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_OFFSET_TOO_LARGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceIasetvertexbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_IASETINDEXBUFFER_INVALIDBUFFER)</para>
    /// </summary>
    IasetindexbufferInvalidbuffer = D3D10_MESSAGE_ID_IASETINDEXBUFFER_INVALIDBUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_FORMAT_INVALID)</para>
    /// </summary>
    DeviceIasetindexbufferFormatInvalid = D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_FORMAT_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_TOO_LARGE)</para>
    /// </summary>
    DeviceIasetindexbufferOffsetTooLarge = D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_TOO_LARGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_UNALIGNED)</para>
    /// </summary>
    DeviceIasetindexbufferOffsetUnaligned = D3D10_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_UNALIGNED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_VIEWS_EMPTY)</para>
    /// </summary>
    DeviceVssetshaderresourcesViewsEmpty = D3D10_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_VIEWS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_VSSETCONSTANTBUFFERS_INVALIDBUFFER)</para>
    /// </summary>
    VssetconstantbuffersInvalidbuffer = D3D10_MESSAGE_ID_VSSETCONSTANTBUFFERS_INVALIDBUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceVssetconstantbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSSETSAMPLERS_SAMPLERS_EMPTY)</para>
    /// </summary>
    DeviceVssetsamplersSamplersEmpty = D3D10_MESSAGE_ID_DEVICE_VSSETSAMPLERS_SAMPLERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_VIEWS_EMPTY)</para>
    /// </summary>
    DeviceGssetshaderresourcesViewsEmpty = D3D10_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_VIEWS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_GSSETCONSTANTBUFFERS_INVALIDBUFFER)</para>
    /// </summary>
    GssetconstantbuffersInvalidbuffer = D3D10_MESSAGE_ID_GSSETCONSTANTBUFFERS_INVALIDBUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceGssetconstantbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSSETSAMPLERS_SAMPLERS_EMPTY)</para>
    /// </summary>
    DeviceGssetsamplersSamplersEmpty = D3D10_MESSAGE_ID_DEVICE_GSSETSAMPLERS_SAMPLERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SOSETTARGETS_INVALIDBUFFER)</para>
    /// </summary>
    SosettargetsInvalidbuffer = D3D10_MESSAGE_ID_SOSETTARGETS_INVALIDBUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SOSETTARGETS_OFFSET_UNALIGNED)</para>
    /// </summary>
    DeviceSosettargetsOffsetUnaligned = D3D10_MESSAGE_ID_DEVICE_SOSETTARGETS_OFFSET_UNALIGNED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_VIEWS_EMPTY)</para>
    /// </summary>
    DevicePssetshaderresourcesViewsEmpty = D3D10_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_VIEWS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PSSETCONSTANTBUFFERS_INVALIDBUFFER)</para>
    /// </summary>
    PssetconstantbuffersInvalidbuffer = D3D10_MESSAGE_ID_PSSETCONSTANTBUFFERS_INVALIDBUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DevicePssetconstantbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSSETSAMPLERS_SAMPLERS_EMPTY)</para>
    /// </summary>
    DevicePssetsamplersSamplersEmpty = D3D10_MESSAGE_ID_DEVICE_PSSETSAMPLERS_SAMPLERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_INVALIDVIEWPORT)</para>
    /// </summary>
    DeviceRssetviewportsInvalidviewport = D3D10_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_INVALIDVIEWPORT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_INVALIDSCISSOR)</para>
    /// </summary>
    DeviceRssetscissorrectsInvalidscissor = D3D10_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_INVALIDSCISSOR,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CLEARRENDERTARGETVIEW_DENORMFLUSH)</para>
    /// </summary>
    ClearrendertargetviewDenormflush = D3D10_MESSAGE_ID_CLEARRENDERTARGETVIEW_DENORMFLUSH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_DENORMFLUSH)</para>
    /// </summary>
    CleardepthstencilviewDenormflush = D3D10_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_DENORMFLUSH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID)</para>
    /// </summary>
    CleardepthstencilviewInvalid = D3D10_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_IAGETVERTEXBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceIagetvertexbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_IAGETVERTEXBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSGETSHADERRESOURCES_VIEWS_EMPTY)</para>
    /// </summary>
    DeviceVsgetshaderresourcesViewsEmpty = D3D10_MESSAGE_ID_DEVICE_VSGETSHADERRESOURCES_VIEWS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSGETCONSTANTBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceVsgetconstantbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_VSGETCONSTANTBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_VSGETSAMPLERS_SAMPLERS_EMPTY)</para>
    /// </summary>
    DeviceVsgetsamplersSamplersEmpty = D3D10_MESSAGE_ID_DEVICE_VSGETSAMPLERS_SAMPLERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSGETSHADERRESOURCES_VIEWS_EMPTY)</para>
    /// </summary>
    DeviceGsgetshaderresourcesViewsEmpty = D3D10_MESSAGE_ID_DEVICE_GSGETSHADERRESOURCES_VIEWS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSGETCONSTANTBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceGsgetconstantbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_GSGETCONSTANTBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GSGETSAMPLERS_SAMPLERS_EMPTY)</para>
    /// </summary>
    DeviceGsgetsamplersSamplersEmpty = D3D10_MESSAGE_ID_DEVICE_GSGETSAMPLERS_SAMPLERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SOGETTARGETS_BUFFERS_EMPTY)</para>
    /// </summary>
    DeviceSogettargetsBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_SOGETTARGETS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSGETSHADERRESOURCES_VIEWS_EMPTY)</para>
    /// </summary>
    DevicePsgetshaderresourcesViewsEmpty = D3D10_MESSAGE_ID_DEVICE_PSGETSHADERRESOURCES_VIEWS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSGETCONSTANTBUFFERS_BUFFERS_EMPTY)</para>
    /// </summary>
    DevicePsgetconstantbuffersBuffersEmpty = D3D10_MESSAGE_ID_DEVICE_PSGETCONSTANTBUFFERS_BUFFERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_PSGETSAMPLERS_SAMPLERS_EMPTY)</para>
    /// </summary>
    DevicePsgetsamplersSamplersEmpty = D3D10_MESSAGE_ID_DEVICE_PSGETSAMPLERS_SAMPLERS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RSGETVIEWPORTS_VIEWPORTS_EMPTY)</para>
    /// </summary>
    DeviceRsgetviewportsViewportsEmpty = D3D10_MESSAGE_ID_DEVICE_RSGETVIEWPORTS_VIEWPORTS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RSGETSCISSORRECTS_RECTS_EMPTY)</para>
    /// </summary>
    DeviceRsgetscissorrectsRectsEmpty = D3D10_MESSAGE_ID_DEVICE_RSGETSCISSORRECTS_RECTS_EMPTY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_GENERATEMIPS_RESOURCE_INVALID)</para>
    /// </summary>
    DeviceGeneratemipsResourceInvalid = D3D10_MESSAGE_ID_DEVICE_GENERATEMIPS_RESOURCE_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSUBRESOURCE)</para>
    /// </summary>
    CopysubresourceregionInvaliddestinationsubresource = D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESUBRESOURCE)</para>
    /// </summary>
    CopysubresourceregionInvalidsourcesubresource = D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCEBOX)</para>
    /// </summary>
    CopysubresourceregionInvalidsourcebox = D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCEBOX,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCE)</para>
    /// </summary>
    CopysubresourceregionInvalidsource = D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSTATE)</para>
    /// </summary>
    CopysubresourceregionInvaliddestinationstate = D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSTATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESTATE)</para>
    /// </summary>
    CopysubresourceregionInvalidsourcestate = D3D10_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESTATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCE)</para>
    /// </summary>
    CopyresourceInvalidsource = D3D10_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYRESOURCE_INVALIDDESTINATIONSTATE)</para>
    /// </summary>
    CopyresourceInvaliddestinationstate = D3D10_MESSAGE_ID_COPYRESOURCE_INVALIDDESTINATIONSTATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCESTATE)</para>
    /// </summary>
    CopyresourceInvalidsourcestate = D3D10_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCESTATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSUBRESOURCE)</para>
    /// </summary>
    UpdatesubresourceInvaliddestinationsubresource = D3D10_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONBOX)</para>
    /// </summary>
    UpdatesubresourceInvaliddestinationbox = D3D10_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONBOX,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSTATE)</para>
    /// </summary>
    UpdatesubresourceInvaliddestinationstate = D3D10_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSTATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_INVALID)</para>
    /// </summary>
    DeviceResolvesubresourceDestinationInvalid = D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_SUBRESOURCE_INVALID)</para>
    /// </summary>
    DeviceResolvesubresourceDestinationSubresourceInvalid = D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_SUBRESOURCE_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_INVALID)</para>
    /// </summary>
    DeviceResolvesubresourceSourceInvalid = D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_SUBRESOURCE_INVALID)</para>
    /// </summary>
    DeviceResolvesubresourceSourceSubresourceInvalid = D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_SUBRESOURCE_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_FORMAT_INVALID)</para>
    /// </summary>
    DeviceResolvesubresourceFormatInvalid = D3D10_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_FORMAT_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_BUFFER_MAP_INVALIDMAPTYPE)</para>
    /// </summary>
    BufferMapInvalidmaptype = D3D10_MESSAGE_ID_BUFFER_MAP_INVALIDMAPTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_BUFFER_MAP_INVALIDFLAGS)</para>
    /// </summary>
    BufferMapInvalidflags = D3D10_MESSAGE_ID_BUFFER_MAP_INVALIDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_BUFFER_MAP_ALREADYMAPPED)</para>
    /// </summary>
    BufferMapAlreadymapped = D3D10_MESSAGE_ID_BUFFER_MAP_ALREADYMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_BUFFER_MAP_DEVICEREMOVED_RETURN)</para>
    /// </summary>
    BufferMapDeviceremovedReturn = D3D10_MESSAGE_ID_BUFFER_MAP_DEVICEREMOVED_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_BUFFER_UNMAP_NOTMAPPED)</para>
    /// </summary>
    BufferUnmapNotmapped = D3D10_MESSAGE_ID_BUFFER_UNMAP_NOTMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_MAP_INVALIDMAPTYPE)</para>
    /// </summary>
    Texture1dMapInvalidmaptype = D3D10_MESSAGE_ID_TEXTURE1D_MAP_INVALIDMAPTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_MAP_INVALIDSUBRESOURCE)</para>
    /// </summary>
    Texture1dMapInvalidsubresource = D3D10_MESSAGE_ID_TEXTURE1D_MAP_INVALIDSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_MAP_INVALIDFLAGS)</para>
    /// </summary>
    Texture1dMapInvalidflags = D3D10_MESSAGE_ID_TEXTURE1D_MAP_INVALIDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_MAP_ALREADYMAPPED)</para>
    /// </summary>
    Texture1dMapAlreadymapped = D3D10_MESSAGE_ID_TEXTURE1D_MAP_ALREADYMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_MAP_DEVICEREMOVED_RETURN)</para>
    /// </summary>
    Texture1dMapDeviceremovedReturn = D3D10_MESSAGE_ID_TEXTURE1D_MAP_DEVICEREMOVED_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_UNMAP_INVALIDSUBRESOURCE)</para>
    /// </summary>
    Texture1dUnmapInvalidsubresource = D3D10_MESSAGE_ID_TEXTURE1D_UNMAP_INVALIDSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE1D_UNMAP_NOTMAPPED)</para>
    /// </summary>
    Texture1dUnmapNotmapped = D3D10_MESSAGE_ID_TEXTURE1D_UNMAP_NOTMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_MAP_INVALIDMAPTYPE)</para>
    /// </summary>
    Texture2dMapInvalidmaptype = D3D10_MESSAGE_ID_TEXTURE2D_MAP_INVALIDMAPTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_MAP_INVALIDSUBRESOURCE)</para>
    /// </summary>
    Texture2dMapInvalidsubresource = D3D10_MESSAGE_ID_TEXTURE2D_MAP_INVALIDSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_MAP_INVALIDFLAGS)</para>
    /// </summary>
    Texture2dMapInvalidflags = D3D10_MESSAGE_ID_TEXTURE2D_MAP_INVALIDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_MAP_ALREADYMAPPED)</para>
    /// </summary>
    Texture2dMapAlreadymapped = D3D10_MESSAGE_ID_TEXTURE2D_MAP_ALREADYMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_MAP_DEVICEREMOVED_RETURN)</para>
    /// </summary>
    Texture2dMapDeviceremovedReturn = D3D10_MESSAGE_ID_TEXTURE2D_MAP_DEVICEREMOVED_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_UNMAP_INVALIDSUBRESOURCE)</para>
    /// </summary>
    Texture2dUnmapInvalidsubresource = D3D10_MESSAGE_ID_TEXTURE2D_UNMAP_INVALIDSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE2D_UNMAP_NOTMAPPED)</para>
    /// </summary>
    Texture2dUnmapNotmapped = D3D10_MESSAGE_ID_TEXTURE2D_UNMAP_NOTMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_MAP_INVALIDMAPTYPE)</para>
    /// </summary>
    Texture3dMapInvalidmaptype = D3D10_MESSAGE_ID_TEXTURE3D_MAP_INVALIDMAPTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_MAP_INVALIDSUBRESOURCE)</para>
    /// </summary>
    Texture3dMapInvalidsubresource = D3D10_MESSAGE_ID_TEXTURE3D_MAP_INVALIDSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_MAP_INVALIDFLAGS)</para>
    /// </summary>
    Texture3dMapInvalidflags = D3D10_MESSAGE_ID_TEXTURE3D_MAP_INVALIDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_MAP_ALREADYMAPPED)</para>
    /// </summary>
    Texture3dMapAlreadymapped = D3D10_MESSAGE_ID_TEXTURE3D_MAP_ALREADYMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_MAP_DEVICEREMOVED_RETURN)</para>
    /// </summary>
    Texture3dMapDeviceremovedReturn = D3D10_MESSAGE_ID_TEXTURE3D_MAP_DEVICEREMOVED_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_UNMAP_INVALIDSUBRESOURCE)</para>
    /// </summary>
    Texture3dUnmapInvalidsubresource = D3D10_MESSAGE_ID_TEXTURE3D_UNMAP_INVALIDSUBRESOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_TEXTURE3D_UNMAP_NOTMAPPED)</para>
    /// </summary>
    Texture3dUnmapNotmapped = D3D10_MESSAGE_ID_TEXTURE3D_UNMAP_NOTMAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CHECKFORMATSUPPORT_FORMAT_DEPRECATED)</para>
    /// </summary>
    CheckformatsupportFormatDeprecated = D3D10_MESSAGE_ID_CHECKFORMATSUPPORT_FORMAT_DEPRECATED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CHECKMULTISAMPLEQUALITYLEVELS_FORMAT_DEPRECATED)</para>
    /// </summary>
    CheckmultisamplequalitylevelsFormatDeprecated = D3D10_MESSAGE_ID_CHECKMULTISAMPLEQUALITYLEVELS_FORMAT_DEPRECATED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETEXCEPTIONMODE_UNRECOGNIZEDFLAGS)</para>
    /// </summary>
    SetexceptionmodeUnrecognizedflags = D3D10_MESSAGE_ID_SETEXCEPTIONMODE_UNRECOGNIZEDFLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETEXCEPTIONMODE_INVALIDARG_RETURN)</para>
    /// </summary>
    SetexceptionmodeInvalidargReturn = D3D10_MESSAGE_ID_SETEXCEPTIONMODE_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETEXCEPTIONMODE_DEVICEREMOVED_RETURN)</para>
    /// </summary>
    SetexceptionmodeDeviceremovedReturn = D3D10_MESSAGE_ID_SETEXCEPTIONMODE_DEVICEREMOVED_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_SIMULATING_INFINITELY_FAST_HARDWARE)</para>
    /// </summary>
    RefSimulatingInfinitelyFastHardware = D3D10_MESSAGE_ID_REF_SIMULATING_INFINITELY_FAST_HARDWARE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_THREADING_MODE)</para>
    /// </summary>
    RefThreadingMode = D3D10_MESSAGE_ID_REF_THREADING_MODE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_UMDRIVER_EXCEPTION)</para>
    /// </summary>
    RefUmdriverException = D3D10_MESSAGE_ID_REF_UMDRIVER_EXCEPTION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_KMDRIVER_EXCEPTION)</para>
    /// </summary>
    RefKmdriverException = D3D10_MESSAGE_ID_REF_KMDRIVER_EXCEPTION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_HARDWARE_EXCEPTION)</para>
    /// </summary>
    RefHardwareException = D3D10_MESSAGE_ID_REF_HARDWARE_EXCEPTION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_ACCESSING_INDEXABLE_TEMP_OUT_OF_RANGE)</para>
    /// </summary>
    RefAccessingIndexableTempOutOfRange = D3D10_MESSAGE_ID_REF_ACCESSING_INDEXABLE_TEMP_OUT_OF_RANGE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_PROBLEM_PARSING_SHADER)</para>
    /// </summary>
    RefProblemParsingShader = D3D10_MESSAGE_ID_REF_PROBLEM_PARSING_SHADER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_OUT_OF_MEMORY)</para>
    /// </summary>
    RefOutOfMemory = D3D10_MESSAGE_ID_REF_OUT_OF_MEMORY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_REF_INFO)</para>
    /// </summary>
    RefInfo = D3D10_MESSAGE_ID_REF_INFO,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEXPOS_OVERFLOW)</para>
    /// </summary>
    DeviceDrawVertexposOverflow = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEXPOS_OVERFLOW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAWINDEXED_INDEXPOS_OVERFLOW)</para>
    /// </summary>
    DeviceDrawindexedIndexposOverflow = D3D10_MESSAGE_ID_DEVICE_DRAWINDEXED_INDEXPOS_OVERFLOW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAWINSTANCED_VERTEXPOS_OVERFLOW)</para>
    /// </summary>
    DeviceDrawinstancedVertexposOverflow = D3D10_MESSAGE_ID_DEVICE_DRAWINSTANCED_VERTEXPOS_OVERFLOW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAWINSTANCED_INSTANCEPOS_OVERFLOW)</para>
    /// </summary>
    DeviceDrawinstancedInstanceposOverflow = D3D10_MESSAGE_ID_DEVICE_DRAWINSTANCED_INSTANCEPOS_OVERFLOW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INSTANCEPOS_OVERFLOW)</para>
    /// </summary>
    DeviceDrawindexedinstancedInstanceposOverflow = D3D10_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INSTANCEPOS_OVERFLOW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INDEXPOS_OVERFLOW)</para>
    /// </summary>
    DeviceDrawindexedinstancedIndexposOverflow = D3D10_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INDEXPOS_OVERFLOW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_SHADER_NOT_SET)</para>
    /// </summary>
    DeviceDrawVertexShaderNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_SHADER_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND)</para>
    /// </summary>
    DeviceShaderLinkageSemanticnameNotFound = D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERINDEX)</para>
    /// </summary>
    DeviceShaderLinkageRegisterindex = D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERINDEX,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_COMPONENTTYPE)</para>
    /// </summary>
    DeviceShaderLinkageComponenttype = D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_COMPONENTTYPE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERMASK)</para>
    /// </summary>
    DeviceShaderLinkageRegistermask = D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERMASK,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SYSTEMVALUE)</para>
    /// </summary>
    DeviceShaderLinkageSystemvalue = D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SYSTEMVALUE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS)</para>
    /// </summary>
    DeviceShaderLinkageNeverwrittenAlwaysreads = D3D10_MESSAGE_ID_DEVICE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_NOT_SET)</para>
    /// </summary>
    DeviceDrawVertexBufferNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_INPUTLAYOUT_NOT_SET)</para>
    /// </summary>
    DeviceDrawInputlayoutNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_INPUTLAYOUT_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_NOT_SET)</para>
    /// </summary>
    DeviceDrawConstantBufferNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_TOO_SMALL)</para>
    /// </summary>
    DeviceDrawConstantBufferTooSmall = D3D10_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_TOO_SMALL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_SAMPLER_NOT_SET)</para>
    /// </summary>
    DeviceDrawSamplerNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_SAMPLER_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_SHADERRESOURCEVIEW_NOT_SET)</para>
    /// </summary>
    DeviceDrawShaderresourceviewNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_SHADERRESOURCEVIEW_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VIEW_DIMENSION_MISMATCH)</para>
    /// </summary>
    DeviceDrawViewDimensionMismatch = D3D10_MESSAGE_ID_DEVICE_DRAW_VIEW_DIMENSION_MISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL)</para>
    /// </summary>
    DeviceDrawVertexBufferStrideTooSmall = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_TOO_SMALL)</para>
    /// </summary>
    DeviceDrawVertexBufferTooSmall = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_TOO_SMALL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_NOT_SET)</para>
    /// </summary>
    DeviceDrawIndexBufferNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_FORMAT_INVALID)</para>
    /// </summary>
    DeviceDrawIndexBufferFormatInvalid = D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_FORMAT_INVALID,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_TOO_SMALL)</para>
    /// </summary>
    DeviceDrawIndexBufferTooSmall = D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_TOO_SMALL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_GS_INPUT_PRIMITIVE_MISMATCH)</para>
    /// </summary>
    DeviceDrawGsInputPrimitiveMismatch = D3D10_MESSAGE_ID_DEVICE_DRAW_GS_INPUT_PRIMITIVE_MISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_RETURN_TYPE_MISMATCH)</para>
    /// </summary>
    DeviceDrawResourceReturnTypeMismatch = D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_RETURN_TYPE_MISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_POSITION_NOT_PRESENT)</para>
    /// </summary>
    DeviceDrawPositionNotPresent = D3D10_MESSAGE_ID_DEVICE_DRAW_POSITION_NOT_PRESENT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_NOT_SET)</para>
    /// </summary>
    DeviceDrawOutputStreamNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_BOUND_RESOURCE_MAPPED)</para>
    /// </summary>
    DeviceDrawBoundResourceMapped = D3D10_MESSAGE_ID_DEVICE_DRAW_BOUND_RESOURCE_MAPPED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_INVALID_PRIMITIVETOPOLOGY)</para>
    /// </summary>
    DeviceDrawInvalidPrimitivetopology = D3D10_MESSAGE_ID_DEVICE_DRAW_INVALID_PRIMITIVETOPOLOGY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_OFFSET_UNALIGNED)</para>
    /// </summary>
    DeviceDrawVertexOffsetUnaligned = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_OFFSET_UNALIGNED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_STRIDE_UNALIGNED)</para>
    /// </summary>
    DeviceDrawVertexStrideUnaligned = D3D10_MESSAGE_ID_DEVICE_DRAW_VERTEX_STRIDE_UNALIGNED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_OFFSET_UNALIGNED)</para>
    /// </summary>
    DeviceDrawIndexOffsetUnaligned = D3D10_MESSAGE_ID_DEVICE_DRAW_INDEX_OFFSET_UNALIGNED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_OFFSET_UNALIGNED)</para>
    /// </summary>
    DeviceDrawOutputStreamOffsetUnaligned = D3D10_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_OFFSET_UNALIGNED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_LD_UNSUPPORTED)</para>
    /// </summary>
    DeviceDrawResourceFormatLdUnsupported = D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_LD_UNSUPPORTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_UNSUPPORTED)</para>
    /// </summary>
    DeviceDrawResourceFormatSampleUnsupported = D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_UNSUPPORTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_C_UNSUPPORTED)</para>
    /// </summary>
    DeviceDrawResourceFormatSampleCUnsupported = D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_C_UNSUPPORTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_MULTISAMPLE_UNSUPPORTED)</para>
    /// </summary>
    DeviceDrawResourceMultisampleUnsupported = D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_MULTISAMPLE_UNSUPPORTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_SO_TARGETS_BOUND_WITHOUT_SOURCE)</para>
    /// </summary>
    DeviceDrawSoTargetsBoundWithoutSource = D3D10_MESSAGE_ID_DEVICE_DRAW_SO_TARGETS_BOUND_WITHOUT_SOURCE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_SO_STRIDE_LARGER_THAN_BUFFER)</para>
    /// </summary>
    DeviceDrawSoStrideLargerThanBuffer = D3D10_MESSAGE_ID_DEVICE_DRAW_SO_STRIDE_LARGER_THAN_BUFFER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING)</para>
    /// </summary>
    DeviceDrawOmRenderTargetDoesNotSupportBlending = D3D10_MESSAGE_ID_DEVICE_DRAW_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0)</para>
    /// </summary>
    DeviceDrawOmDualSourceBlendingCanOnlyHaveRenderTarget_0 = D3D10_MESSAGE_ID_DEVICE_DRAW_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT)</para>
    /// </summary>
    DeviceRemovalProcessAtFault = D3D10_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT)</para>
    /// </summary>
    DeviceRemovalProcessPossiblyAtFault = D3D10_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT)</para>
    /// </summary>
    DeviceRemovalProcessNotAtFault = D3D10_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_INVALIDARG_RETURN)</para>
    /// </summary>
    DeviceOpenSharedResourceInvalidargReturn = D3D10_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_INVALIDARG_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    DeviceOpenSharedResourceOutofmemoryReturn = D3D10_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_BADINTERFACE_RETURN)</para>
    /// </summary>
    DeviceOpenSharedResourceBadinterfaceReturn = D3D10_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_BADINTERFACE_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_VIEWPORT_NOT_SET)</para>
    /// </summary>
    DeviceDrawViewportNotSet = D3D10_MESSAGE_ID_DEVICE_DRAW_VIEWPORT_NOT_SET,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC)</para>
    /// </summary>
    CreateinputlayoutTrailingDigitInSemantic = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC)</para>
    /// </summary>
    CreategeometryshaderwithstreamoutputTrailingDigitInSemantic = D3D10_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_DENORMFLUSH)</para>
    /// </summary>
    DeviceRssetviewportsDenormflush = D3D10_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_DENORMFLUSH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_OMSETRENDERTARGETS_INVALIDVIEW)</para>
    /// </summary>
    OmsetrendertargetsInvalidview = D3D10_MESSAGE_ID_OMSETRENDERTARGETS_INVALIDVIEW,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_SETTEXTFILTERSIZE_INVALIDDIMENSIONS)</para>
    /// </summary>
    DeviceSettextfiltersizeInvaliddimensions = D3D10_MESSAGE_ID_DEVICE_SETTEXTFILTERSIZE_INVALIDDIMENSIONS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_SAMPLER_MISMATCH)</para>
    /// </summary>
    DeviceDrawSamplerMismatch = D3D10_MESSAGE_ID_DEVICE_DRAW_SAMPLER_MISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH)</para>
    /// </summary>
    CreateinputlayoutTypeMismatch = D3D10_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_BLENDSTATE_GETDESC_LEGACY)</para>
    /// </summary>
    BlendstateGetdescLegacy = D3D10_MESSAGE_ID_BLENDSTATE_GETDESC_LEGACY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SHADERRESOURCEVIEW_GETDESC_LEGACY)</para>
    /// </summary>
    ShaderresourceviewGetdescLegacy = D3D10_MESSAGE_ID_SHADERRESOURCEVIEW_GETDESC_LEGACY,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEQUERY_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreatequeryOutofmemoryReturn = D3D10_MESSAGE_ID_CREATEQUERY_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATEPREDICATE_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreatepredicateOutofmemoryReturn = D3D10_MESSAGE_ID_CREATEPREDICATE_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATECOUNTER_OUTOFRANGE_COUNTER)</para>
    /// </summary>
    CreatecounterOutofrangeCounter = D3D10_MESSAGE_ID_CREATECOUNTER_OUTOFRANGE_COUNTER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATECOUNTER_SIMULTANEOUS_ACTIVE_COUNTERS_EXHAUSTED)</para>
    /// </summary>
    CreatecounterSimultaneousActiveCountersExhausted = D3D10_MESSAGE_ID_CREATECOUNTER_SIMULTANEOUS_ACTIVE_COUNTERS_EXHAUSTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATECOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER)</para>
    /// </summary>
    CreatecounterUnsupportedWellknownCounter = D3D10_MESSAGE_ID_CREATECOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATECOUNTER_OUTOFMEMORY_RETURN)</para>
    /// </summary>
    CreatecounterOutofmemoryReturn = D3D10_MESSAGE_ID_CREATECOUNTER_OUTOFMEMORY_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATECOUNTER_NONEXCLUSIVE_RETURN)</para>
    /// </summary>
    CreatecounterNonexclusiveReturn = D3D10_MESSAGE_ID_CREATECOUNTER_NONEXCLUSIVE_RETURN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CREATECOUNTER_NULLDESC)</para>
    /// </summary>
    CreatecounterNulldesc = D3D10_MESSAGE_ID_CREATECOUNTER_NULLDESC,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CHECKCOUNTER_OUTOFRANGE_COUNTER)</para>
    /// </summary>
    CheckcounterOutofrangeCounter = D3D10_MESSAGE_ID_CHECKCOUNTER_OUTOFRANGE_COUNTER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_CHECKCOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER)</para>
    /// </summary>
    CheckcounterUnsupportedWellknownCounter = D3D10_MESSAGE_ID_CHECKCOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_SETPREDICATION_INVALID_PREDICATE_STATE)</para>
    /// </summary>
    SetpredicationInvalidPredicateState = D3D10_MESSAGE_ID_SETPREDICATION_INVALID_PREDICATE_STATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_BEGIN_UNSUPPORTED)</para>
    /// </summary>
    QueryBeginUnsupported = D3D10_MESSAGE_ID_QUERY_BEGIN_UNSUPPORTED,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PREDICATE_BEGIN_DURING_PREDICATION)</para>
    /// </summary>
    PredicateBeginDuringPredication = D3D10_MESSAGE_ID_PREDICATE_BEGIN_DURING_PREDICATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_BEGIN_DUPLICATE)</para>
    /// </summary>
    QueryBeginDuplicate = D3D10_MESSAGE_ID_QUERY_BEGIN_DUPLICATE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_BEGIN_ABANDONING_PREVIOUS_RESULTS)</para>
    /// </summary>
    QueryBeginAbandoningPreviousResults = D3D10_MESSAGE_ID_QUERY_BEGIN_ABANDONING_PREVIOUS_RESULTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_PREDICATE_END_DURING_PREDICATION)</para>
    /// </summary>
    PredicateEndDuringPredication = D3D10_MESSAGE_ID_PREDICATE_END_DURING_PREDICATION,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_END_ABANDONING_PREVIOUS_RESULTS)</para>
    /// </summary>
    QueryEndAbandoningPreviousResults = D3D10_MESSAGE_ID_QUERY_END_ABANDONING_PREVIOUS_RESULTS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_END_WITHOUT_BEGIN)</para>
    /// </summary>
    QueryEndWithoutBegin = D3D10_MESSAGE_ID_QUERY_END_WITHOUT_BEGIN,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_GETDATA_INVALID_DATASIZE)</para>
    /// </summary>
    QueryGetdataInvalidDatasize = D3D10_MESSAGE_ID_QUERY_GETDATA_INVALID_DATASIZE,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_GETDATA_INVALID_FLAGS)</para>
    /// </summary>
    QueryGetdataInvalidFlags = D3D10_MESSAGE_ID_QUERY_GETDATA_INVALID_FLAGS,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_QUERY_GETDATA_INVALID_CALL)</para>
    /// </summary>
    QueryGetdataInvalidCall = D3D10_MESSAGE_ID_QUERY_GETDATA_INVALID_CALL,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_PS_OUTPUT_TYPE_MISMATCH)</para>
    /// </summary>
    DeviceDrawPsOutputTypeMismatch = D3D10_MESSAGE_ID_DEVICE_DRAW_PS_OUTPUT_TYPE_MISMATCH,
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_GATHER_UNSUPPORTED)</para>
    /// </summary>
    DeviceDrawResourceFormatGatherUnsupported = D3D10_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_GATHER_UNSUPPORTED,
};
/// <summary>
/// Debug message severity levels for an information queue.
/// <para>(Also see DirectX SDK: D3D10_MESSAGE_SEVERITY)</para>
/// </summary>
public enum class MessageSeverity  : UInt32
{
    /// <summary>
    /// Defines some type of corruption which has occured.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_SEVERITY_CORRUPTION)</para>
    /// </summary>
    Corruption = D3D10_MESSAGE_SEVERITY_CORRUPTION,
    /// <summary>
    /// Defines an error message.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_SEVERITY_ERROR)</para>
    /// </summary>
    Error = D3D10_MESSAGE_SEVERITY_ERROR,
    /// <summary>
    /// Defines a warning message.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_SEVERITY_WARNING)</para>
    /// </summary>
    Warning = D3D10_MESSAGE_SEVERITY_WARNING,
    /// <summary>
    /// Defines an information message.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE_SEVERITY_INFO)</para>
    /// </summary>
    Info = D3D10_MESSAGE_SEVERITY_INFO,
};
/// <summary>
/// These flags identify shader parameters that use system-value semantics.
/// <para>(Also see DirectX SDK: D3D10_NAME)</para>
/// </summary>
public enum class Name  : UInt32
{
    /// <summary>
    /// This parameter does not use a predefined system-value semantic.
    /// <para>(Also see DirectX SDK: D3D10_NAME_UNDEFINED)</para>
    /// </summary>
    Undefined = D3D10_NAME_UNDEFINED,
    /// <summary>
    /// This parameter contains position data.
    /// <para>(Also see DirectX SDK: D3D10_NAME_POSITION)</para>
    /// </summary>
    Position = D3D10_NAME_POSITION,
    /// <summary>
    /// This parameter contains clip-distance data.
    /// <para>(Also see DirectX SDK: D3D10_NAME_CLIP_DISTANCE)</para>
    /// </summary>
    ClipDistance = D3D10_NAME_CLIP_DISTANCE,
    /// <summary>
    /// This parameter contains cull distance data.
    /// <para>(Also see DirectX SDK: D3D10_NAME_CULL_DISTANCE)</para>
    /// </summary>
    CullDistance = D3D10_NAME_CULL_DISTANCE,
    /// <summary>
    /// This parameter contains a render-target-array index.
    /// <para>(Also see DirectX SDK: D3D10_NAME_RENDER_TARGET_ARRAY_INDEX)</para>
    /// </summary>
    RenderTargetArrayIndex = D3D10_NAME_RENDER_TARGET_ARRAY_INDEX,
    /// <summary>
    /// This parameter contains a viewport-array index.
    /// <para>(Also see DirectX SDK: D3D10_NAME_VIEWPORT_ARRAY_INDEX)</para>
    /// </summary>
    ViewportArrayIndex = D3D10_NAME_VIEWPORT_ARRAY_INDEX,
    /// <summary>
    /// This parameter contains a vertex ID.
    /// <para>(Also see DirectX SDK: D3D10_NAME_VERTEX_ID)</para>
    /// </summary>
    VertexId = D3D10_NAME_VERTEX_ID,
    /// <summary>
    /// This parameter contains a primitive ID.
    /// <para>(Also see DirectX SDK: D3D10_NAME_PRIMITIVE_ID)</para>
    /// </summary>
    PrimitiveId = D3D10_NAME_PRIMITIVE_ID,
    /// <summary>
    /// This parameter contains a instance ID.
    /// <para>(Also see DirectX SDK: D3D10_NAME_INSTANCE_ID)</para>
    /// </summary>
    InstanceId = D3D10_NAME_INSTANCE_ID,
    /// <summary>
    /// This parameter contains data that identifies whether or not the primitive faces the camera.
    /// <para>(Also see DirectX SDK: D3D10_NAME_IS_FRONT_FACE)</para>
    /// </summary>
    IsFrontFace = D3D10_NAME_IS_FRONT_FACE,
    /// <summary>
    /// This parameter a sampler-array index.
    /// <para>(Also see DirectX SDK: D3D10_NAME_SAMPLE_INDEX)</para>
    /// </summary>
    SampleIndex = D3D10_NAME_SAMPLE_INDEX,
    /// <summary>
    /// This parameter contains render-target data.
    /// <para>(Also see DirectX SDK: D3D10_NAME_TARGET)</para>
    /// </summary>
    Target = D3D10_NAME_TARGET,
    /// <summary>
    /// This parameter contains depth data.
    /// <para>(Also see DirectX SDK: D3D10_NAME_DEPTH)</para>
    /// </summary>
    Depth = D3D10_NAME_DEPTH,
    /// <summary>
    /// This parameter contains alpha-coverage data.
    /// <para>(Also see DirectX SDK: D3D10_NAME_COVERAGE)</para>
    /// </summary>
    Coverage = D3D10_NAME_COVERAGE,
};
/// <summary>
/// Primitive type, which determines how the data that makes up object geometry is organized.
/// <para>(Also see DirectX SDK: D3D10_PRIMITIVE)</para>
/// </summary>
public enum class Primitive  : UInt32
{
    /// <summary>
    /// The type is undefined.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_UNDEFINED)</para>
    /// </summary>
    Undefined = D3D10_PRIMITIVE_UNDEFINED,
    /// <summary>
    /// The data is organized in a point list.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_POINT)</para>
    /// </summary>
    Point = D3D10_PRIMITIVE_POINT,
    /// <summary>
    /// The data is organized in a line list.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_LINE)</para>
    /// </summary>
    Line = D3D10_PRIMITIVE_LINE,
    /// <summary>
    /// The data is organized in a triangle list.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TRIANGLE)</para>
    /// </summary>
    Triangle = D3D10_PRIMITIVE_TRIANGLE,
    /// <summary>
    /// The data is organized in a line list with adjacency data.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_LINE_ADJ)</para>
    /// </summary>
    LineAdj = D3D10_PRIMITIVE_LINE_ADJ,
    /// <summary>
    /// The data is organized in a triangle list with adjacency data.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TRIANGLE_ADJ)</para>
    /// </summary>
    TriangleAdj = D3D10_PRIMITIVE_TRIANGLE_ADJ,
};
/// <summary>
/// How the pipeline interprets vertex data that is bound to the input-assembler stage. These primitive types determine how the vertex data is rendered on screen.
/// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY)</para>
/// </summary>
public enum class PrimitiveTopology  : UInt32
{
    /// <summary>
    /// The IA stage has not been initialized with a primitive topology. The IA stage will not function properly unless a primitive topology is defined.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED)</para>
    /// </summary>
    Undefined = D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED,
    /// <summary>
    /// Interpret the vertex data as a collection of points.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_POINTLIST)</para>
    /// </summary>
    PointList = D3D10_PRIMITIVE_TOPOLOGY_POINTLIST,
    /// <summary>
    /// Interpret the vertex data as a collection of lines.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_LINELIST)</para>
    /// </summary>
    LineList = D3D10_PRIMITIVE_TOPOLOGY_LINELIST,
    /// <summary>
    /// Interpret the vertex data as a line strip.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP)</para>
    /// </summary>
    LineStrip = D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP,
    /// <summary>
    /// Interpret the vertex data as a collection of triangles.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST)</para>
    /// </summary>
    TriangleList = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    /// <summary>
    /// Interpret the vertex data as a triangle strip.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP)</para>
    /// </summary>
    TriangleStrip = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
    /// <summary>
    /// Interpret the vertex data as collection of lines with adjacency data.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ)</para>
    /// </summary>
    LineListAdj = D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ,
    /// <summary>
    /// Interpret the vertex data as line strip with adjacency data.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ)</para>
    /// </summary>
    LineStripAdj = D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ,
    /// <summary>
    /// Interpret the vertex data as collection of triangles with adjacency data.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ)</para>
    /// </summary>
    TriangleListAdj = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ,
    /// <summary>
    /// Interpret the vertex data as triangle strip with adjacency data.
    /// <para>(Also see DirectX SDK: D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ)</para>
    /// </summary>
    TriangleStripAdj = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ,
};

/// <summary>
/// Query types.
/// <para>(Also see DirectX SDK: D3D10_QUERY)</para>
/// </summary>
public enum class Query : UInt32
{
    /// <summary>
    /// Determines whether or not the GPU is finished processing commands. When the GPU is finished processing commands Asynchronous.GetData will return S_OK, and pData will point to a BOOL with a value of TRUE. When using this type of query, Asynchronous.Begin is disabled.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_EVENT)</para>
    /// </summary>
    Event = D3D10_QUERY_EVENT,
    /// <summary>
    /// Get the number of samples that passed the depth and stencil tests in between Asynchronous.Begin and Asynchronous.End. Asynchronous.GetData returns a UINT64. If a depth or stencil test is disabled, then each of those tests will be counted as a pass.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_OCCLUSION)</para>
    /// </summary>
    Occlusion = D3D10_QUERY_OCCLUSION,
    /// <summary>
    /// Get a timestamp value where Asynchronous.GetData returns a UINT64. This kind of query is only useful if two timestamp queries are done in the middle of a TimestampDisjoint query. The difference of two timestamps can be used to determine how many ticks have elapsed, and the TimestampDisjoint query will determine if that difference is a reliable value and also has a value that shows how to convert the number of ticks into seconds. See QueryDataTimestampDisjoint. When using this type of query, Asynchronous.Begin is disabled.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_TIMESTAMP)</para>
    /// </summary>
    Timestamp = D3D10_QUERY_TIMESTAMP,
    /// <summary>
    /// Determines whether or not a Timestamp is returning reliable values, and also gives the frequency of the processor enabling you to convert the number of elapsed ticks into seconds. Asynchronous.GetData will return a QueryDataTimestampDisjoint. This type of query should only be invoked once per frame or less.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_TIMESTAMP_DISJOINT)</para>
    /// </summary>
    TimestampDisjoint = D3D10_QUERY_TIMESTAMP_DISJOINT,
    /// <summary>
    /// Get pipeline statistics, such as the number of pixel shader invocations in between Asynchronous.Begin and Asynchronous.End. Asynchronous.GetData will return a QueryDataPipelineStatistics.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_PIPELINE_STATISTICS)</para>
    /// </summary>
    PipelineStatistics = D3D10_QUERY_PIPELINE_STATISTICS,
    /// <summary>
    /// Similar to Occlusion, except Asynchronous.GetData returns a BOOL indicating whether or not any samples passed the depth and stencil tests - TRUE meaning at least one passed, FALSE meaning none passed.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_OCCLUSION_PREDICATE)</para>
    /// </summary>
    OcclusionPredicate = D3D10_QUERY_OCCLUSION_PREDICATE,
    /// <summary>
    /// Get streaming output statistics, such as the number of primitives streamed out in between Asynchronous.Begin and Asynchronous.End. Asynchronous.GetData will return a QueryDataStreamOuputStatistics structure.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_SO_STATISTICS)</para>
    /// </summary>
    StreamOuputStatistics = D3D10_QUERY_SO_STATISTICS,
    /// <summary>
    /// Determines whether or not any of the streaming output buffers overflowed in between Asynchronous.Begin and Asynchronous.End. Asynchronous.GetData returns a BOOL - TRUE meaning there was an overflow, FALSE meaning there was not an overflow. If streaming output writes to multiple buffers, and one of the buffers overflows, then it will stop writing to all the output buffers. When an overflow is detected by Direct3D it is prevented from happening - no memory is corrupted. This predication may be used in conjunction with an SO_STATISTICS query so that when an overflow occurs the SO_STATISTIC query will let the application know how much memory was needed to prevent an overflow.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_SO_OVERFLOW_PREDICATE)</para>
    /// </summary>
    StreamOuputOverflowPredicate = D3D10_QUERY_SO_OVERFLOW_PREDICATE,
};
/// <summary>
/// Flags that describe miscellaneous query behavior.
/// <para>(Also see DirectX SDK: D3D10_QUERY_MISC_FLAG)</para>
/// </summary>
[Flags]
public enum class QueryMiscFlag  : UInt32
{
    /// <summary>
    /// No flags.
    /// </summary>
    None = 0,
    /// <summary>
    /// Tell the hardware that if it is not yet sure if something is hidden or not to draw it anyway. This is only used with an occlusion predicate. Predication data cannot be returned to your application via Asynchronous.GetData when using this flag.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_MISC_PREDICATEHINT)</para>
    /// </summary>
    PredicateHint = D3D10_QUERY_MISC_PREDICATEHINT,
};
/// <summary>
/// Option(s) for raising an error to a non-continuable exception.
/// <para>(Also see DirectX SDK: D3D10_RAISE_FLAG)</para>
/// </summary>
[Flags]
public enum class RaiseFlag  : UInt32
{
    /// <summary>
    /// No flags.
    /// </summary>
    None = 0,
    /// <summary>
    /// Raise an internal driver error to a non-continuable exception.
    /// <para>(Also see DirectX SDK: D3D10_RAISE_FLAG_DRIVER_INTERNAL_ERROR)</para>
    /// </summary>
    DriverInternalError = D3D10_RAISE_FLAG_DRIVER_INTERNAL_ERROR,
};
/// <summary>
/// The register component types, usually used in SignatureParameterDescription.
/// <para>(Also see DirectX SDK: D3D10_REGISTER_COMPONENT_TYPE)</para>
/// </summary>
public enum class RegisterComponentType  : UInt32
{
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D10_REGISTER_COMPONENT_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_REGISTER_COMPONENT_UNKNOWN,
    /// <summary>
    /// 32-bit unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_REGISTER_COMPONENT_UINT32)</para>
    /// </summary>
    Uint32 = D3D10_REGISTER_COMPONENT_UINT32,
    /// <summary>
    /// 32-bit signed integer.
    /// <para>(Also see DirectX SDK: D3D10_REGISTER_COMPONENT_SINT32)</para>
    /// </summary>
    Sint32 = D3D10_REGISTER_COMPONENT_SINT32,
    /// <summary>
    /// 32-bit floating-point number.
    /// <para>(Also see DirectX SDK: D3D10_REGISTER_COMPONENT_FLOAT32)</para>
    /// </summary>
    Float32 = D3D10_REGISTER_COMPONENT_FLOAT32,
};
/// <summary>
/// Identifies the type of resource being used.
/// <para>(Also see DirectX SDK: D3D10_RESOURCE_DIMENSION)</para>
/// </summary>
public enum class ResourceDimension  : UInt32
{
    /// <summary>
    /// Resource is of unknown type.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_DIMENSION_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_RESOURCE_DIMENSION_UNKNOWN,
    /// <summary>
    /// Resource is a buffer.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_DIMENSION_BUFFER)</para>
    /// </summary>
    Buffer = D3D10_RESOURCE_DIMENSION_BUFFER,
    /// <summary>
    /// Resource is a 1D texture.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_DIMENSION_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_RESOURCE_DIMENSION_TEXTURE1D,
    /// <summary>
    /// Resource is a 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_DIMENSION_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_RESOURCE_DIMENSION_TEXTURE2D,
    /// <summary>
    /// Resource is a 3D texture.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_DIMENSION_TEXTURE3D)</para>
    /// </summary>
    Texture3D = D3D10_RESOURCE_DIMENSION_TEXTURE3D,
};
/// <summary>
/// Identifies other, less common options for resources.
/// <para>(Also see DirectX SDK: D3D10_RESOURCE_MISC_FLAG)</para>
/// </summary>
[Flags]
public enum class ResourceMiscFlag  : UInt32
{
    /// <summary>
    /// Undefined
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Enables an application to call Device.GenerateMips on a texture resource. The resource must be created with the bind flags that specify that the resource is a render target and a shader resource.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_MISC_GENERATE_MIPS)</para>
    /// </summary>
    GenerateMips = D3D10_RESOURCE_MISC_GENERATE_MIPS,
    /// <summary>
    /// Enables the sharing of resource data between two or more Direct3D devices. The only resources that can be shared are 2D non-mipmapped textures.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_MISC_SHARED)</para>
    /// </summary>
    Shared = D3D10_RESOURCE_MISC_SHARED,
    /// <summary>
    /// Enables an application to create a cube texture from a Texture2DArray that contains 6 textures.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_MISC_TEXTURECUBE)</para>
    /// </summary>
    TextureCube = D3D10_RESOURCE_MISC_TEXTURECUBE,
    /// <summary>
    /// TBD
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX)</para>
    /// </summary>
    SharedKeyedMutex = D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX,
    /// <summary>
    /// Enables a surface to be used for GDI interoperability.  Setting this flag enables rendering on the surface via Surface1.GetDC.
    /// <para>(Also see DirectX SDK: D3D10_RESOURCE_MISC_GDI_COMPATIBLE)</para>
    /// </summary>
    GdiCompatible = D3D10_RESOURCE_MISC_GDI_COMPATIBLE,
};
/// <summary>
/// The return type of a resource. See ShaderInputBindDescription.
/// <para>(Also see DirectX SDK: D3D10_RESOURCE_RETURN_TYPE)</para>
/// </summary>
public enum class ResourceReturnType  : UInt32
{
    /// <summary>
    /// Unsigned integer value normalized to a value between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D10_RETURN_TYPE_UNORM)</para>
    /// </summary>
    Unorm = D3D10_RETURN_TYPE_UNORM,
    /// <summary>
    /// Signed integer value normalized to a value between -1 and 1.
    /// <para>(Also see DirectX SDK: D3D10_RETURN_TYPE_SNORM)</para>
    /// </summary>
    Snorm = D3D10_RETURN_TYPE_SNORM,
    /// <summary>
    /// Signed integer.
    /// <para>(Also see DirectX SDK: D3D10_RETURN_TYPE_SINT)</para>
    /// </summary>
    Sint = D3D10_RETURN_TYPE_SINT,
    /// <summary>
    /// Unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_RETURN_TYPE_UINT)</para>
    /// </summary>
    Uint = D3D10_RETURN_TYPE_UINT,
    /// <summary>
    /// Floating-point number.
    /// <para>(Also see DirectX SDK: D3D10_RETURN_TYPE_FLOAT)</para>
    /// </summary>
    Float = D3D10_RETURN_TYPE_FLOAT,
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D10_RETURN_TYPE_MIXED)</para>
    /// </summary>
    Mixed = D3D10_RETURN_TYPE_MIXED,
};
/// <summary>
/// Specifies how to access a resource used in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION)</para>
/// </summary>
public enum class RenderTargetViewDimension  : UInt32
{
    /// <summary>
    /// The resource will be accessed according to its type as determined from the actual instance this enumeration is paired with when the render-target view is created.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_RTV_DIMENSION_UNKNOWN,
    /// <summary>
    /// The resource will be accessed as a buffer.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_BUFFER)</para>
    /// </summary>
    Buffer = D3D10_RTV_DIMENSION_BUFFER,
    /// <summary>
    /// The resource will be accessed as a 1D texture.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_RTV_DIMENSION_TEXTURE1D,
    /// <summary>
    /// The resource will be accessed as an array of 1D textures.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE1DARRAY)</para>
    /// </summary>
    Texture1DArray = D3D10_RTV_DIMENSION_TEXTURE1DARRAY,
    /// <summary>
    /// The resource will be accessed as a 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_RTV_DIMENSION_TEXTURE2D,
    /// <summary>
    /// The resource will be accessed as an array of 2D textures.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE2DARRAY)</para>
    /// </summary>
    Texture2DArray = D3D10_RTV_DIMENSION_TEXTURE2DARRAY,
    /// <summary>
    /// The resource will be accessed as a 2D texture with multisampling.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE2DMS)</para>
    /// </summary>
    Texture2DMultiSample = D3D10_RTV_DIMENSION_TEXTURE2DMS,
    /// <summary>
    /// The resource will be accessed as an array of 2D textures with multisampling.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE2DMSARRAY)</para>
    /// </summary>
    Texture2DMultiSampleArray = D3D10_RTV_DIMENSION_TEXTURE2DMSARRAY,
    /// <summary>
    /// The resource will be accessed as a 3D texture.
    /// <para>(Also see DirectX SDK: D3D10_RTV_DIMENSION_TEXTURE3D)</para>
    /// </summary>
    Texture3D = D3D10_RTV_DIMENSION_TEXTURE3D,
};
/// <summary>
/// These flags identify constant-buffer properties.
/// <para>(Also see DirectX SDK: D3D10_SHADER_CBUFFER_FLAGS)</para>
/// </summary>
public enum class ShaderConstantBufferFlags  : UInt32
{
    /// <summary>
    /// No flags
    /// </summary>
    None = 0,
    /// <summary>
    /// Bind the constant buffer to an input slot defined in HLSL code (instead of letting the compiler choose the input slot).
    /// <para>(Also see DirectX SDK: D3D10_CBF_USERPACKED)</para>
    /// </summary>
    UserPacked = D3D10_CBF_USERPACKED,
};
/// <summary>
/// Shader register types.
/// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REGTYPE)</para>
/// </summary>
public enum class ShaderDebugRegisterType  : UInt32
{
    /// <summary>
    /// Input register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_INPUT)</para>
    /// </summary>
    Input = D3D10_SHADER_DEBUG_REG_INPUT,
    /// <summary>
    /// Output register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_OUTPUT)</para>
    /// </summary>
    Output = D3D10_SHADER_DEBUG_REG_OUTPUT,
    /// <summary>
    /// Constant buffer register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_CBUFFER)</para>
    /// </summary>
    ConstantBuffer = D3D10_SHADER_DEBUG_REG_CBUFFER,
    /// <summary>
    /// Texture buffer register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_TBUFFER)</para>
    /// </summary>
    TextureBuffer = D3D10_SHADER_DEBUG_REG_TBUFFER,
    /// <summary>
    /// Temporary register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_TEMP)</para>
    /// </summary>
    Temp = D3D10_SHADER_DEBUG_REG_TEMP,
    /// <summary>
    /// Collection of temporary registers.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_TEMPARRAY)</para>
    /// </summary>
    TempArray = D3D10_SHADER_DEBUG_REG_TEMPARRAY,
    /// <summary>
    /// Texture register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_TEXTURE)</para>
    /// </summary>
    Texture = D3D10_SHADER_DEBUG_REG_TEXTURE,
    /// <summary>
    /// Sampler register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_SAMPLER)</para>
    /// </summary>
    Sampler = D3D10_SHADER_DEBUG_REG_SAMPLER,
    /// <summary>
    /// Immediate constant buffer register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_IMMEDIATECBUFFER)</para>
    /// </summary>
    ImmediateConstantBuffer = D3D10_SHADER_DEBUG_REG_IMMEDIATECBUFFER,
    /// <summary>
    /// Literal register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_LITERAL)</para>
    /// </summary>
    Literal = D3D10_SHADER_DEBUG_REG_LITERAL,
    /// <summary>
    /// Unused register.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_REG_UNUSED)</para>
    /// </summary>
    Unused = D3D10_SHADER_DEBUG_REG_UNUSED,
};
/// <summary>
/// Scope types.
/// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPETYPE)</para>
/// </summary>
public enum class ShaderDebugScopetype  : UInt32
{
    /// <summary>
    /// Global scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_GLOBAL)</para>
    /// </summary>
    Global = D3D10_SHADER_DEBUG_SCOPE_GLOBAL,
    /// <summary>
    /// Block scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_BLOCK)</para>
    /// </summary>
    Block = D3D10_SHADER_DEBUG_SCOPE_BLOCK,
    /// <summary>
    /// For loop scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_FORLOOP)</para>
    /// </summary>
    ForLoop = D3D10_SHADER_DEBUG_SCOPE_FORLOOP,
    /// <summary>
    /// Structure scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_STRUCT)</para>
    /// </summary>
    Struct = D3D10_SHADER_DEBUG_SCOPE_STRUCT,
    /// <summary>
    /// Function parameter scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_FUNC_PARAMS)</para>
    /// </summary>
    FuncParams = D3D10_SHADER_DEBUG_SCOPE_FUNC_PARAMS,
    /// <summary>
    /// State block scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_STATEBLOCK)</para>
    /// </summary>
    Stateblock = D3D10_SHADER_DEBUG_SCOPE_STATEBLOCK,
    /// <summary>
    /// Name space scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_NAMESPACE)</para>
    /// </summary>
    Namespace = D3D10_SHADER_DEBUG_SCOPE_NAMESPACE,
    /// <summary>
    /// Annotation scope.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_SCOPE_ANNOTATION)</para>
    /// </summary>
    Annotation = D3D10_SHADER_DEBUG_SCOPE_ANNOTATION,
};
/// <summary>
/// TBD
/// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_VARTYPE)</para>
/// </summary>
public enum class ShaderDebugVartype  : UInt32
{
    /// <summary>
    /// TBD
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_VAR_VARIABLE)</para>
    /// </summary>
    Variable = D3D10_SHADER_DEBUG_VAR_VARIABLE,
    /// <summary>
    /// TBD
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DEBUG_VAR_FUNCTION)</para>
    /// </summary>
    Function = D3D10_SHADER_DEBUG_VAR_FUNCTION,
};
/// <summary>
/// These flags identify shader-input options.
/// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_FLAGS)</para>
/// </summary>
[Flags]
public enum class ShaderInputFlags  : UInt32
{
    /// <summary>
    /// Assign a shader input to a register based on the register assignment in the HLSL code (instead of letting the compiler choose the register).
    /// <para>(Also see DirectX SDK: D3D10_SIF_USERPACKED)</para>
    /// </summary>
    UserPacked = D3D10_SIF_USERPACKED,
    /// <summary>
    /// Use a comparison sampler, which uses the SampleCmp (DirectX HLSL Texture Object) and SampleCmpLevelZero (DirectX HLSL Texture Object) sampling functions.
    /// <para>(Also see DirectX SDK: D3D10_SIF_COMPARISON_SAMPLER)</para>
    /// </summary>
    ComparisonSampler = D3D10_SIF_COMPARISON_SAMPLER,
    /// <summary>
    /// A 2-bit value for encoding texture components.
    /// <para>(Also see DirectX SDK: D3D10_SIF_TEXTURE_COMPONENT_0)</para>
    /// </summary>
    TextureComponent0 = D3D10_SIF_TEXTURE_COMPONENT_0,
    /// <summary>
    /// A 2-bit value for encoding texture components.
    /// <para>(Also see DirectX SDK: D3D10_SIF_TEXTURE_COMPONENT_1)</para>
    /// </summary>
    TextureComponent1 = D3D10_SIF_TEXTURE_COMPONENT_1,
    /// <summary>
    /// A 2-bit value for encoding texture components.
    /// <para>(Also see DirectX SDK: D3D10_SIF_TEXTURE_COMPONENTS)</para>
    /// </summary>
    TextureComponents = D3D10_SIF_TEXTURE_COMPONENTS,
};
/// <summary>
/// These flags identify a shader-resource type.
/// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_TYPE)</para>
/// </summary>
public enum class ShaderInputType  : UInt32
{
    /// <summary>
    /// The shader resource is a constant buffer.
    /// <para>(Also see DirectX SDK: D3D10_SIT_CBUFFER)</para>
    /// </summary>
    ConstantBuffer = D3D10_SIT_CBUFFER,
    /// <summary>
    /// The shader resource is a texture buffer.
    /// <para>(Also see DirectX SDK: D3D10_SIT_TBUFFER)</para>
    /// </summary>
    TextureBuffer = D3D10_SIT_TBUFFER,
    /// <summary>
    /// The shader resource is a texture.
    /// <para>(Also see DirectX SDK: D3D10_SIT_TEXTURE)</para>
    /// </summary>
    Texture = D3D10_SIT_TEXTURE,
    /// <summary>
    /// The shader resource is a sampler.
    /// <para>(Also see DirectX SDK: D3D10_SIT_SAMPLER)</para>
    /// </summary>
    Sampler = D3D10_SIT_SAMPLER,
};
/// <summary>
/// These flags identify the shader-variable class.
/// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_CLASS)</para>
/// </summary>
public enum class ShaderVariableClass  : UInt32
{
    /// <summary>
    /// The shader variable is a scalar.
    /// <para>(Also see DirectX SDK: D3D10_SVC_SCALAR)</para>
    /// </summary>
    Scalar = D3D10_SVC_SCALAR,
    /// <summary>
    /// The shader variable is a vector.
    /// <para>(Also see DirectX SDK: D3D10_SVC_VECTOR)</para>
    /// </summary>
    Vector = D3D10_SVC_VECTOR,
    /// <summary>
    /// The shader variable is a row-major matrix.
    /// <para>(Also see DirectX SDK: D3D10_SVC_MATRIX_ROWS)</para>
    /// </summary>
    MatrixRows = D3D10_SVC_MATRIX_ROWS,
    /// <summary>
    /// The shader variable is a column-major matrix.
    /// <para>(Also see DirectX SDK: D3D10_SVC_MATRIX_COLUMNS)</para>
    /// </summary>
    MatrixColumns = D3D10_SVC_MATRIX_COLUMNS,
    /// <summary>
    /// The shader variable is an object.
    /// <para>(Also see DirectX SDK: D3D10_SVC_OBJECT)</para>
    /// </summary>
    Object = D3D10_SVC_OBJECT,
    /// <summary>
    /// The shader variable is a structure.
    /// <para>(Also see DirectX SDK: D3D10_SVC_STRUCT)</para>
    /// </summary>
    Struct = D3D10_SVC_STRUCT,
};
/// <summary>
/// Flags that indicate information about a shader variable; these flags are returned using a reflection object.
/// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_FLAGS)</para>
/// </summary>
[Flags]
public enum class ShaderVariableFlags  : UInt32
{
    /// <summary>
    /// Undefined
    /// </summary>
    Undefined = 0,
    /// <summary>
    /// Indicates that the registers assigned to this shader variable were explicitly declared in shader code (instead of automatically assigned by the compiler).
    /// <para>(Also see DirectX SDK: D3D10_SVF_USERPACKED)</para>
    /// </summary>
    UserPacked = D3D10_SVF_USERPACKED,
    /// <summary>
    /// Indicates that this variable is used by this shader. This value confirms that a particular shader variable (which can be common to many different shaders) is indeed used by a particular shader.
    /// <para>(Also see DirectX SDK: D3D10_SVF_USED)</para>
    /// </summary>
    Used = D3D10_SVF_USED,
};
/// <summary>
/// These flags identify the shader-variable type.
/// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_TYPE)</para>
/// </summary>
public enum class ShaderVariableType  : UInt32
{
    /// <summary>
    /// The variable is a void pointer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_VOID)</para>
    /// </summary>
    Void = D3D10_SVT_VOID,
    /// <summary>
    /// The variable is a boolean.
    /// <para>(Also see DirectX SDK: D3D10_SVT_BOOL)</para>
    /// </summary>
    Bool = D3D10_SVT_BOOL,
    /// <summary>
    /// The variable is a integer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_INT)</para>
    /// </summary>
    Int = D3D10_SVT_INT,
    /// <summary>
    /// The variable is a floating-point number.
    /// <para>(Also see DirectX SDK: D3D10_SVT_FLOAT)</para>
    /// </summary>
    Float = D3D10_SVT_FLOAT,
    /// <summary>
    /// The variable is a string.
    /// <para>(Also see DirectX SDK: D3D10_SVT_STRING)</para>
    /// </summary>
    String = D3D10_SVT_STRING,
    /// <summary>
    /// The variable is a texture.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE)</para>
    /// </summary>
    Texture = D3D10_SVT_TEXTURE,
    /// <summary>
    /// The variable is a 1D texture.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_SVT_TEXTURE1D,
    /// <summary>
    /// The variable is a 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_SVT_TEXTURE2D,
    /// <summary>
    /// The variable is a 3D texture.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE3D)</para>
    /// </summary>
    Texture3D = D3D10_SVT_TEXTURE3D,
    /// <summary>
    /// The variable is a texture cube.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURECUBE)</para>
    /// </summary>
    TextureCube = D3D10_SVT_TEXTURECUBE,
    /// <summary>
    /// The variable is a sampler.
    /// <para>(Also see DirectX SDK: D3D10_SVT_SAMPLER)</para>
    /// </summary>
    Sampler = D3D10_SVT_SAMPLER,
    /// <summary>
    /// The variable is a pixel shader.
    /// <para>(Also see DirectX SDK: D3D10_SVT_PIXELSHADER)</para>
    /// </summary>
    PixelShader = D3D10_SVT_PIXELSHADER,
    /// <summary>
    /// The variable is a vertex shader.
    /// <para>(Also see DirectX SDK: D3D10_SVT_VERTEXSHADER)</para>
    /// </summary>
    VertexShader = D3D10_SVT_VERTEXSHADER,
    /// <summary>
    /// The variable is an unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_UINT)</para>
    /// </summary>
    Uint = D3D10_SVT_UINT,
    /// <summary>
    /// The variable is an 8-bit unsigned integer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_UINT8)</para>
    /// </summary>
    Uint8 = D3D10_SVT_UINT8,
    /// <summary>
    /// The variable is a geometry shader.
    /// <para>(Also see DirectX SDK: D3D10_SVT_GEOMETRYSHADER)</para>
    /// </summary>
    GeometryShader = D3D10_SVT_GEOMETRYSHADER,
    /// <summary>
    /// The variable is a rasterizer-state object.
    /// <para>(Also see DirectX SDK: D3D10_SVT_RASTERIZER)</para>
    /// </summary>
    Rasterizer = D3D10_SVT_RASTERIZER,
    /// <summary>
    /// The variable is a depth-stencil-state object.
    /// <para>(Also see DirectX SDK: D3D10_SVT_DEPTHSTENCIL)</para>
    /// </summary>
    DepthStencil = D3D10_SVT_DEPTHSTENCIL,
    /// <summary>
    /// The variable is a blend-state object.
    /// <para>(Also see DirectX SDK: D3D10_SVT_BLEND)</para>
    /// </summary>
    Blend = D3D10_SVT_BLEND,
    /// <summary>
    /// The variable is a buffer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_BUFFER)</para>
    /// </summary>
    Buffer = D3D10_SVT_BUFFER,
    /// <summary>
    /// The variable is a constant buffer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_CBUFFER)</para>
    /// </summary>
    ConstantBuffer = D3D10_SVT_CBUFFER,
    /// <summary>
    /// The variable is a texture buffer.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TBUFFER)</para>
    /// </summary>
    TextureBuffer = D3D10_SVT_TBUFFER,
    /// <summary>
    /// The variable is a 1D-texture array.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE1DARRAY)</para>
    /// </summary>
    Texture1DArray = D3D10_SVT_TEXTURE1DARRAY,
    /// <summary>
    /// The variable is a 2D-texture array.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE2DARRAY)</para>
    /// </summary>
    Texture2DArray = D3D10_SVT_TEXTURE2DARRAY,
    /// <summary>
    /// The variable is a render-target view.
    /// <para>(Also see DirectX SDK: D3D10_SVT_RENDERTARGETVIEW)</para>
    /// </summary>
    RenderTargetView = D3D10_SVT_RENDERTARGETVIEW,
    /// <summary>
    /// The variable is a depth-stencil view.
    /// <para>(Also see DirectX SDK: D3D10_SVT_DEPTHSTENCILVIEW)</para>
    /// </summary>
    DepthStencilView = D3D10_SVT_DEPTHSTENCILVIEW,
    /// <summary>
    /// The variable is a 2D-multisampled texture.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE2DMS)</para>
    /// </summary>
    Texture2DMultipSample = D3D10_SVT_TEXTURE2DMS,
    /// <summary>
    /// The variable is a 2D-multisampled-texture array.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURE2DMSARRAY)</para>
    /// </summary>
    Texture2DMultiSampleArray = D3D10_SVT_TEXTURE2DMSARRAY,
    /// <summary>
    /// The variable is a texture-cube array.
    /// <para>(Also see DirectX SDK: D3D10_SVT_TEXTURECUBEARRAY)</para>
    /// </summary>
    TextureCubeArray = D3D10_SVT_TEXTURECUBEARRAY,
};
/// <summary>
/// These flags identify the type of resource that will be viewed.
/// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION)</para>
/// </summary>
public enum class ShaderResourceViewDimension  : UInt32
{
    /// <summary>
    /// The type is unknown.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_SRV_DIMENSION_UNKNOWN,
    /// <summary>
    /// The resource is a buffer.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_BUFFER)</para>
    /// </summary>
    Buffer = D3D10_SRV_DIMENSION_BUFFER,
    /// <summary>
    /// The resource is a 1D texture.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_SRV_DIMENSION_TEXTURE1D,
    /// <summary>
    /// The resource is an array of 1D textures.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE1DARRAY)</para>
    /// </summary>
    Texture1DArray = D3D10_SRV_DIMENSION_TEXTURE1DARRAY,
    /// <summary>
    /// The resource is a 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_SRV_DIMENSION_TEXTURE2D,
    /// <summary>
    /// The resource is an array of 2D textures.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE2DARRAY)</para>
    /// </summary>
    Texture2DArray = D3D10_SRV_DIMENSION_TEXTURE2DARRAY,
    /// <summary>
    /// The resource is a multisampling 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE2DMS)</para>
    /// </summary>
    Texture2DMultiSample = D3D10_SRV_DIMENSION_TEXTURE2DMS,
    /// <summary>
    /// The resource is an array of multisampling 2D textures.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE2DMSARRAY)</para>
    /// </summary>
    Texture2DMultiSampleArray = D3D10_SRV_DIMENSION_TEXTURE2DMSARRAY,
    /// <summary>
    /// The resource is a 3D texture.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURE3D)</para>
    /// </summary>
    Texture3D = D3D10_SRV_DIMENSION_TEXTURE3D,
    /// <summary>
    /// The resource is a cube texture.
    /// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION_TEXTURECUBE)</para>
    /// </summary>
    TextureCube = D3D10_SRV_DIMENSION_TEXTURECUBE,
};
/// <summary>
/// These flags identify the type of resource that will be viewed.
/// <para>(Also see DirectX SDK: D3D10_SRV_DIMENSION1)</para>
/// </summary>
public enum class ShaderResourceViewDimension1  : UInt32
{
    /// <summary>
    /// The type is unknown.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D10_1_SRV_DIMENSION_UNKNOWN,
    /// <summary>
    /// The resource is a buffer.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_BUFFER)</para>
    /// </summary>
    Buffer = D3D10_1_SRV_DIMENSION_BUFFER,
    /// <summary>
    /// The resource is a 1D texture.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE1D)</para>
    /// </summary>
    Texture1D = D3D10_1_SRV_DIMENSION_TEXTURE1D,
    /// <summary>
    /// The resource is an array of 1D textures.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE1DARRAY)</para>
    /// </summary>
    Texture1DArray = D3D10_1_SRV_DIMENSION_TEXTURE1DARRAY,
    /// <summary>
    /// The resource is a 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE2D)</para>
    /// </summary>
    Texture2D = D3D10_1_SRV_DIMENSION_TEXTURE2D,
    /// <summary>
    /// The resource is an array of 2D textures.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE2DARRAY)</para>
    /// </summary>
    Texture2DArray = D3D10_1_SRV_DIMENSION_TEXTURE2DARRAY,
    /// <summary>
    /// The resource is a multisampling 2D texture.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE2DMS)</para>
    /// </summary>
    Texture2DMultiSample = D3D10_1_SRV_DIMENSION_TEXTURE2DMS,
    /// <summary>
    /// The resource is an array of multisampling 2D textures.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE2DMSARRAY)</para>
    /// </summary>
    Texture2DMultiSampleArray = D3D10_1_SRV_DIMENSION_TEXTURE2DMSARRAY,
    /// <summary>
    /// The resource is a 3D texture.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURE3D)</para>
    /// </summary>
    Texture3D = D3D10_1_SRV_DIMENSION_TEXTURE3D,
    /// <summary>
    /// The resource is a cube texture.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURECUBE)</para>
    /// </summary>
    TextureCube = D3D10_1_SRV_DIMENSION_TEXTURECUBE,
    /// <summary>
    /// The resource is an array of cube textures.
    /// <para>(Also see DirectX SDK: D3D10_1_SRV_DIMENSION_TEXTURECUBEARRAY)</para>
    /// </summary>
    TextureCubeArray = D3D10_1_SRV_DIMENSION_TEXTURECUBEARRAY,
};
/// <summary>
/// The stencil operations that can be performed during depth-stencil testing.
/// <para>(Also see DirectX SDK: D3D10_STENCIL_OP)</para>
/// </summary>
public enum class StencilOperation  : UInt32
{
    /// <summary>
    /// Keep the existing stencil data.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_KEEP)</para>
    /// </summary>
    Keep = D3D10_STENCIL_OP_KEEP,
    /// <summary>
    /// Set the stencil data to 0.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_ZERO)</para>
    /// </summary>
    Zero = D3D10_STENCIL_OP_ZERO,
    /// <summary>
    /// Set the stencil data to the reference value set by calling Device.OMSetDepthStencilState.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_REPLACE)</para>
    /// </summary>
    Replace = D3D10_STENCIL_OP_REPLACE,
    /// <summary>
    /// Increment the stencil value by 1, and clamp the result.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_INCR_SAT)</para>
    /// </summary>
    IncrementSat = D3D10_STENCIL_OP_INCR_SAT,
    /// <summary>
    /// Decrement the stencil value by 1, and clamp the result.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_DECR_SAT)</para>
    /// </summary>
    DecrementSat = D3D10_STENCIL_OP_DECR_SAT,
    /// <summary>
    /// Invert the stencil data.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_INVERT)</para>
    /// </summary>
    Invert = D3D10_STENCIL_OP_INVERT,
    /// <summary>
    /// Increment the stencil value by 1, and wrap the result if necessary.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_INCR)</para>
    /// </summary>
    Increment = D3D10_STENCIL_OP_INCR,
    /// <summary>
    /// Increment the stencil value by 1, and wrap the result if necessary.
    /// <para>(Also see DirectX SDK: D3D10_STENCIL_OP_DECR)</para>
    /// </summary>
    Decrement = D3D10_STENCIL_OP_DECR,
};
/// <summary>
/// The different faces of a cube texture.
/// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE)</para>
/// </summary>
public enum class TexturecubeFace  : UInt32
{
    /// <summary>
    /// Positive X face.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE_POSITIVE_X)</para>
    /// </summary>
    PositiveX = D3D10_TEXTURECUBE_FACE_POSITIVE_X,
    /// <summary>
    /// Negative X face.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE_NEGATIVE_X)</para>
    /// </summary>
    NegativeX = D3D10_TEXTURECUBE_FACE_NEGATIVE_X,
    /// <summary>
    /// Positive Y face.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE_POSITIVE_Y)</para>
    /// </summary>
    PositiveY = D3D10_TEXTURECUBE_FACE_POSITIVE_Y,
    /// <summary>
    /// Negative Y face.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE_NEGATIVE_Y)</para>
    /// </summary>
    NegativeY = D3D10_TEXTURECUBE_FACE_NEGATIVE_Y,
    /// <summary>
    /// Positive Z face.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE_POSITIVE_Z)</para>
    /// </summary>
    PositiveZ = D3D10_TEXTURECUBE_FACE_POSITIVE_Z,
    /// <summary>
    /// Negative Z face.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURECUBE_FACE_NEGATIVE_Z)</para>
    /// </summary>
    NegativeZ = D3D10_TEXTURECUBE_FACE_NEGATIVE_Z,
};
/// <summary>
/// Identify a technique for resolving texture coordinates that are outside of the boundaries of a texture.
/// <para>(Also see DirectX SDK: D3D10_TEXTURE_ADDRESS_MODE)</para>
/// </summary>
public enum class TextureAddressMode  : UInt32
{
    /// <summary>
    /// Tile the texture at every integer junction. For example, for u values between 0 and 3, the texture is repeated three times.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE_ADDRESS_WRAP)</para>
    /// </summary>
    Wrap = D3D10_TEXTURE_ADDRESS_WRAP,
    /// <summary>
    /// Flip the texture at every integer junction. For u values between 0 and 1, for example, the texture is addressed normally; between 1 and 2, the texture is flipped (mirrored); between 2 and 3, the texture is normal again; and so on.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE_ADDRESS_MIRROR)</para>
    /// </summary>
    Mirror = D3D10_TEXTURE_ADDRESS_MIRROR,
    /// <summary>
    /// Texture coordinates outside the range [0.0, 1.0] are set to the texture color at 0.0 or 1.0, respectively.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE_ADDRESS_CLAMP)</para>
    /// </summary>
    Clamp = D3D10_TEXTURE_ADDRESS_CLAMP,
    /// <summary>
    /// Texture coordinates outside the range [0.0, 1.0] are set to the border color specified in SamplerDescription or HLSL code.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE_ADDRESS_BORDER)</para>
    /// </summary>
    Border = D3D10_TEXTURE_ADDRESS_BORDER,
    /// <summary>
    /// Similar to Mirror and Clamp. Takes the absolute value of the texture coordinate (thus, mirroring around 0), and then clamps to the maximum value.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE_ADDRESS_MIRROR_ONCE)</para>
    /// </summary>
    MirrorOnce = D3D10_TEXTURE_ADDRESS_MIRROR_ONCE,
};
/// <summary>
/// Identifies expected resource use during rendering. The usage directly reflects whether a resource is accessible by the CPU and/or the GPU.
/// <para>(Also see DirectX SDK: D3D10_USAGE)</para>
/// </summary>
public enum class Usage  : UInt32
{
    /// <summary>
    /// A resource that requires read and write access by the GPU. This is likely to be the most common usage choice.
    /// <para>(Also see DirectX SDK: D3D10_USAGE_DEFAULT)</para>
    /// </summary>
    Default = D3D10_USAGE_DEFAULT,
    /// <summary>
    /// A resource that can only be read by the GPU. It cannot be written by the GPU, and cannot be accessed at all by the CPU. This type of resource must be initialized when it is created, since it cannot be changed after creation.
    /// <para>(Also see DirectX SDK: D3D10_USAGE_IMMUTABLE)</para>
    /// </summary>
    Immutable = D3D10_USAGE_IMMUTABLE,
    /// <summary>
    /// A resource that is accessible by both the GPU and the CPU (write only). A dynamic resource is a good choice for a resource that will be updated by the CPU at least once per frame. If your data is laid exactly the way the resource stores it, use Device.UpdateSubresource; otherwise, use a Map method. You can write to a dynamic resource on the GPU using Device.CopyResource or Device.CopySubresourceRegion.
    /// <para>(Also see DirectX SDK: D3D10_USAGE_DYNAMIC)</para>
    /// </summary>
    Dynamic = D3D10_USAGE_DYNAMIC,
    /// <summary>
    /// A resource that supports data transfer (copy) from the GPU to the CPU.
    /// <para>(Also see DirectX SDK: D3D10_USAGE_STAGING)</para>
    /// </summary>
    Staging = D3D10_USAGE_STAGING,
};
} } } }
