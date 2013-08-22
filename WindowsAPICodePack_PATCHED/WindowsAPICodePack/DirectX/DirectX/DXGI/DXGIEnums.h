//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI { 

/// <summary>
/// Options for presenting frames to the output.
/// <para>(Also see DirectX SDK: DXGI_PRESENT)</para>
/// </summary>
[Flags]
public enum class PresentFlag  : UInt32
{
    /// <summary>
    /// Present a frame from each buffer (starting with the current buffer) to the output.
    /// </summary>
    Default = 0,
    /// <summary>
    /// Present a frame from the current buffer to the output. Use this flag to exploit the vertical-blank synchronization during presentation, without sequencing the buffers in the chain as normal.
    /// <para>(Also see DirectX SDK: DXGI_PRESENT_DO_NOT_SEQUENCE)</para>
    /// </summary>
    DoNotSequence = DXGI_PRESENT_DO_NOT_SEQUENCE,
    /// <summary>
    /// Discard pending presentations; for subsequent presentations, present a frame from each buffer (starting with the first buffer) to the output.
    /// <para>(Also see DirectX SDK: DXGI_PRESENT_RESTART)</para>
    /// </summary>
    DoNotRestart = DXGI_PRESENT_RESTART,
    /// <summary>
    /// Do not present the frame to the output. The status of the swapchain will be tested and appropriate errors returned. Test is only intended for use when switching from the idle state; do not use it to determine when to switch to the idle state as doing so can leave the swapchain unable to exit fullscreen mode.
    /// <para>(Also see DirectX SDK: DXGI_PRESENT_TEST)</para>
    /// </summary>
    Test = DXGI_PRESENT_TEST,
};
/// <summary>
/// Options for enumerating display modes.
/// <para>(Also see DirectX SDK: DXGI_ENUM_MODES)</para>
/// </summary>
public enum class EnumModes  : UInt32
{
    /// <summary>
    /// Include all modes.
    /// </summary>
    Default = 0,
    /// <summary>
    /// Include interlaced modes.
    /// <para>(Also see DirectX SDK: DXGI_ENUM_MODES_INTERLACED)</para>
    /// </summary>
    Interlaced = DXGI_ENUM_MODES_INTERLACED,
    /// <summary>
    /// Include stretched-scaling modes.
    /// <para>(Also see DirectX SDK: DXGI_ENUM_MODES_SCALING)</para>
    /// </summary>
    Scaling = DXGI_ENUM_MODES_SCALING,
};
/// <summary>
/// Flags for surface and resource creation options.
/// <para>(Also see DirectX SDK: DXGI_USAGE)</para>
/// </summary>
[Flags]
public enum class UsageOption  : UInt32
{
    /// <summary>
    /// No flags specified.
    /// </summary>
    Unspecified = 0,
    /// <summary>
    /// Use the surface or resource as a back buffer.
    /// <para>(Also see DirectX SDK: DXGI_USAGE_BACK_BUFFER)</para>
    /// </summary>
    BackBuffer = DXGI_USAGE_BACK_BUFFER,
    /// <summary>
    /// This flag is for internal use only.
    /// <para>(Also see DirectX SDK: DXGI_USAGE_DISCARD_ON_PRESENT)</para>
    /// </summary>
    DiscardOnPresent = DXGI_USAGE_DISCARD_ON_PRESENT,
    /// <summary>
    /// Use the surface or resource for reading only.
    /// <para>(Also see DirectX SDK: DXGI_USAGE_READ_ONLY)</para>
    /// </summary>
    ReadOnly = DXGI_USAGE_READ_ONLY,
    /// <summary>
    /// Use the surface or resource as an output render target.
    /// <para>(Also see DirectX SDK: DXGI_USAGE_RENDER_TARGET_OUTPUT)</para>
    /// </summary>
    RenderTargetOutput = DXGI_USAGE_RENDER_TARGET_OUTPUT,
    /// <summary>
    /// Use the surface or resource as an input to a shader.
    /// <para>(Also see DirectX SDK: DXGI_USAGE_SHADER_INPUT)</para>
    /// </summary>
    ShaderInput = DXGI_USAGE_SHADER_INPUT,
    /// <summary>
    /// Share the surface or resource.
    /// <para>(Also see DirectX SDK: DXGI_USAGE_SHARED)</para>
    /// </summary>
    Shared = DXGI_USAGE_SHARED,
};
/// <summary>
/// Identifies if an adapter is local or remote.
/// <para>(Also see DirectX SDK: DXGI_ADAPTER_FLAG)</para>
/// </summary>
public enum class AdapterFlag  : UInt32
{
    /// <summary>
    /// Specifies no flags.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_FLAG_NONE)</para>
    /// </summary>
    None = DXGI_ADAPTER_FLAG_NONE,
    /// <summary>
    /// Indicates that the adapter is a remote adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_FLAG_REMOTE)</para>
    /// </summary>
    Remote = DXGI_ADAPTER_FLAG_REMOTE,
};
/// <summary>
/// Resource data formats which includes fully-typed and typeless formats. There is a collection of format modifiers at the bottom of the page,     that more fully describes each format type.
/// <para>(Also see DirectX SDK: DXGI_FORMAT)</para>
/// </summary>
public enum class Format  : UInt32
{
    /// <summary>
    /// The format is not known.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_UNKNOWN)</para>
    /// </summary>
    Unknown = DXGI_FORMAT_UNKNOWN,
    /// <summary>
    /// A four-component, 128-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32A32_TYPELESS)</para>
    /// </summary>
    R32G32B32A32_TYPELESS = DXGI_FORMAT_R32G32B32A32_TYPELESS,
    /// <summary>
    /// A four-component, 128-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32A32_FLOAT)</para>
    /// </summary>
    R32G32B32A32_FLOAT = DXGI_FORMAT_R32G32B32A32_FLOAT,
    /// <summary>
    /// A four-component, 128-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32A32_UINT)</para>
    /// </summary>
    R32G32B32A32_UINT = DXGI_FORMAT_R32G32B32A32_UINT,
    /// <summary>
    /// A four-component, 128-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32A32_SINT)</para>
    /// </summary>
    R32G32B32A32_SINT = DXGI_FORMAT_R32G32B32A32_SINT,
    /// <summary>
    /// A three-component, 96-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32_TYPELESS)</para>
    /// </summary>
    R32G32B32_TYPELESS = DXGI_FORMAT_R32G32B32_TYPELESS,
    /// <summary>
    /// A three-component, 96-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32_FLOAT)</para>
    /// </summary>
    R32G32B32_FLOAT = DXGI_FORMAT_R32G32B32_FLOAT,
    /// <summary>
    /// A three-component, 96-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32_UINT)</para>
    /// </summary>
    R32G32B32_UINT = DXGI_FORMAT_R32G32B32_UINT,
    /// <summary>
    /// A three-component, 96-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32B32_SINT)</para>
    /// </summary>
    R32G32B32_SINT = DXGI_FORMAT_R32G32B32_SINT,
    /// <summary>
    /// A four-component, 64-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16B16A16_TYPELESS)</para>
    /// </summary>
    R16G16B16A16_TYPELESS = DXGI_FORMAT_R16G16B16A16_TYPELESS,
    /// <summary>
    /// A four-component, 64-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16B16A16_FLOAT)</para>
    /// </summary>
    R16G16B16A16_FLOAT = DXGI_FORMAT_R16G16B16A16_FLOAT,
    /// <summary>
    /// A four-component, 64-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16B16A16_UNORM)</para>
    /// </summary>
    R16G16B16A16_UNORM = DXGI_FORMAT_R16G16B16A16_UNORM,
    /// <summary>
    /// A four-component, 64-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16B16A16_UINT)</para>
    /// </summary>
    R16G16B16A16_UINT = DXGI_FORMAT_R16G16B16A16_UINT,
    /// <summary>
    /// A four-component, 64-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16B16A16_SNORM)</para>
    /// </summary>
    R16G16B16A16_SNORM = DXGI_FORMAT_R16G16B16A16_SNORM,
    /// <summary>
    /// A four-component, 64-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16B16A16_SINT)</para>
    /// </summary>
    R16G16B16A16_SINT = DXGI_FORMAT_R16G16B16A16_SINT,
    /// <summary>
    /// A two-component, 64-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32_TYPELESS)</para>
    /// </summary>
    R32G32_TYPELESS = DXGI_FORMAT_R32G32_TYPELESS,
    /// <summary>
    /// A two-component, 64-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32_FLOAT)</para>
    /// </summary>
    R32G32_FLOAT = DXGI_FORMAT_R32G32_FLOAT,
    /// <summary>
    /// A two-component, 64-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32_UINT)</para>
    /// </summary>
    R32G32_UINT = DXGI_FORMAT_R32G32_UINT,
    /// <summary>
    /// A two-component, 64-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G32_SINT)</para>
    /// </summary>
    R32G32_SINT = DXGI_FORMAT_R32G32_SINT,
    /// <summary>
    /// A two-component, 64-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32G8X24_TYPELESS)</para>
    /// </summary>
    R32G8X24_TYPELESS = DXGI_FORMAT_R32G8X24_TYPELESS,
    /// <summary>
    /// A 32-bit floating-point component, and two unsigned-integer components (with an additional 32 bits).
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_D32_FLOAT_S8X24_UINT)</para>
    /// </summary>
    D32_FLOAT_S8X24_UINT = DXGI_FORMAT_D32_FLOAT_S8X24_UINT,
    /// <summary>
    /// A 32-bit floating-point component, and two typeless components (with an additional 32 bits).
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS)</para>
    /// </summary>
    R32_FLOAT_X8X24_TYPELESS = DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS,
    /// <summary>
    /// A 32-bit typeless component, and two unsigned-integer components (with an additional 32 bits).
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_X32_TYPELESS_G8X24_UINT)</para>
    /// </summary>
    X32_TYPELESS_G8X24_UINT = DXGI_FORMAT_X32_TYPELESS_G8X24_UINT,
    /// <summary>
    /// A four-component, 32-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R10G10B10A2_TYPELESS)</para>
    /// </summary>
    R10G10B10A2_TYPELESS = DXGI_FORMAT_R10G10B10A2_TYPELESS,
    /// <summary>
    /// A four-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R10G10B10A2_UNORM)</para>
    /// </summary>
    R10G10B10A2_UNORM = DXGI_FORMAT_R10G10B10A2_UNORM,
    /// <summary>
    /// A four-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R10G10B10A2_UINT)</para>
    /// </summary>
    R10G10B10A2_UINT = DXGI_FORMAT_R10G10B10A2_UINT,
    /// <summary>
    /// A three-component, 32-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R11G11B10_FLOAT)</para>
    /// </summary>
    R11G11B10_FLOAT = DXGI_FORMAT_R11G11B10_FLOAT,
    /// <summary>
    /// A three-component, 32-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8B8A8_TYPELESS)</para>
    /// </summary>
    R8G8B8A8_TYPELESS = DXGI_FORMAT_R8G8B8A8_TYPELESS,
    /// <summary>
    /// A four-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8B8A8_UNORM)</para>
    /// </summary>
    R8G8B8A8_UNORM = DXGI_FORMAT_R8G8B8A8_UNORM,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized integer sRGB format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8B8A8_UNORM_SRGB)</para>
    /// </summary>
    R8G8B8A8_UNORM_SRGB = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
    /// <summary>
    /// A four-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8B8A8_UINT)</para>
    /// </summary>
    R8G8B8A8_UINT = DXGI_FORMAT_R8G8B8A8_UINT,
    /// <summary>
    /// A three-component, 32-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8B8A8_SNORM)</para>
    /// </summary>
    R8G8B8A8_SNORM = DXGI_FORMAT_R8G8B8A8_SNORM,
    /// <summary>
    /// A three-component, 32-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8B8A8_SINT)</para>
    /// </summary>
    R8G8B8A8_SINT = DXGI_FORMAT_R8G8B8A8_SINT,
    /// <summary>
    /// A two-component, 32-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16_TYPELESS)</para>
    /// </summary>
    R16G16_TYPELESS = DXGI_FORMAT_R16G16_TYPELESS,
    /// <summary>
    /// A two-component, 32-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16_FLOAT)</para>
    /// </summary>
    R16G16_FLOAT = DXGI_FORMAT_R16G16_FLOAT,
    /// <summary>
    /// A two-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16_UNORM)</para>
    /// </summary>
    R16G16_UNORM = DXGI_FORMAT_R16G16_UNORM,
    /// <summary>
    /// A two-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16_UINT)</para>
    /// </summary>
    R16G16_UINT = DXGI_FORMAT_R16G16_UINT,
    /// <summary>
    /// A two-component, 32-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16_SNORM)</para>
    /// </summary>
    R16G16_SNORM = DXGI_FORMAT_R16G16_SNORM,
    /// <summary>
    /// A two-component, 32-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16G16_SINT)</para>
    /// </summary>
    R16G16_SINT = DXGI_FORMAT_R16G16_SINT,
    /// <summary>
    /// A single-component, 32-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32_TYPELESS)</para>
    /// </summary>
    R32_TYPELESS = DXGI_FORMAT_R32_TYPELESS,
    /// <summary>
    /// A single-component, 32-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_D32_FLOAT)</para>
    /// </summary>
    D32_FLOAT = DXGI_FORMAT_D32_FLOAT,
    /// <summary>
    /// A single-component, 32-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32_FLOAT)</para>
    /// </summary>
    R32_FLOAT = DXGI_FORMAT_R32_FLOAT,
    /// <summary>
    /// A single-component, 32-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32_UINT)</para>
    /// </summary>
    R32_UINT = DXGI_FORMAT_R32_UINT,
    /// <summary>
    /// A single-component, 32-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R32_SINT)</para>
    /// </summary>
    R32_SINT = DXGI_FORMAT_R32_SINT,
    /// <summary>
    /// A two-component, 32-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R24G8_TYPELESS)</para>
    /// </summary>
    R24G8_TYPELESS = DXGI_FORMAT_R24G8_TYPELESS,
    /// <summary>
    /// A 32-bit z-buffer format that uses 24 bits for the depth channel and 8 bits for the stencil channel.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_D24_UNORM_S8_UINT)</para>
    /// </summary>
    D24_UNORM_S8_UINT = DXGI_FORMAT_D24_UNORM_S8_UINT,
    /// <summary>
    /// A 32-bit format, that contains a 24 bit, single-component, unsigned-normalized integer, with an additional typeless 8 bits.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R24_UNORM_X8_TYPELESS)</para>
    /// </summary>
    R24_UNORM_X8_TYPELESS = DXGI_FORMAT_R24_UNORM_X8_TYPELESS,
    /// <summary>
    /// A 32-bit format, that contains a 24 bit, single-component, typeless format,  with an additional 8 bit unsigned integer component.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_X24_TYPELESS_G8_UINT)</para>
    /// </summary>
    X24_TYPELESS_G8_UINT = DXGI_FORMAT_X24_TYPELESS_G8_UINT,
    /// <summary>
    /// A two-component, 16-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8_TYPELESS)</para>
    /// </summary>
    R8G8_TYPELESS = DXGI_FORMAT_R8G8_TYPELESS,
    /// <summary>
    /// A two-component, 16-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8_UNORM)</para>
    /// </summary>
    R8G8_UNORM = DXGI_FORMAT_R8G8_UNORM,
    /// <summary>
    /// A two-component, 16-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8_UINT)</para>
    /// </summary>
    R8G8_UINT = DXGI_FORMAT_R8G8_UINT,
    /// <summary>
    /// A two-component, 16-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8_SNORM)</para>
    /// </summary>
    R8G8_SNORM = DXGI_FORMAT_R8G8_SNORM,
    /// <summary>
    /// A two-component, 16-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8_SINT)</para>
    /// </summary>
    R8G8_SINT = DXGI_FORMAT_R8G8_SINT,
    /// <summary>
    /// A single-component, 16-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16_TYPELESS)</para>
    /// </summary>
    R16_TYPELESS = DXGI_FORMAT_R16_TYPELESS,
    /// <summary>
    /// A single-component, 16-bit floating-point format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16_FLOAT)</para>
    /// </summary>
    R16_FLOAT = DXGI_FORMAT_R16_FLOAT,
    /// <summary>
    /// A single-component, 16-bit unsigned-normalized integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_D16_UNORM)</para>
    /// </summary>
    D16_UNORM = DXGI_FORMAT_D16_UNORM,
    /// <summary>
    /// A single-component, 16-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16_UNORM)</para>
    /// </summary>
    R16_UNORM = DXGI_FORMAT_R16_UNORM,
    /// <summary>
    /// A single-component, 16-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16_UINT)</para>
    /// </summary>
    R16_UINT = DXGI_FORMAT_R16_UINT,
    /// <summary>
    /// A single-component, 16-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16_SNORM)</para>
    /// </summary>
    R16_SNORM = DXGI_FORMAT_R16_SNORM,
    /// <summary>
    /// A single-component, 16-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R16_SINT)</para>
    /// </summary>
    R16_SINT = DXGI_FORMAT_R16_SINT,
    /// <summary>
    /// A single-component, 8-bit typeless format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8_TYPELESS)</para>
    /// </summary>
    R8_TYPELESS = DXGI_FORMAT_R8_TYPELESS,
    /// <summary>
    /// A single-component, 8-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8_UNORM)</para>
    /// </summary>
    R8_UNORM = DXGI_FORMAT_R8_UNORM,
    /// <summary>
    /// A single-component, 8-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8_UINT)</para>
    /// </summary>
    R8_UINT = DXGI_FORMAT_R8_UINT,
    /// <summary>
    /// A single-component, 8-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8_SNORM)</para>
    /// </summary>
    R8_SNORM = DXGI_FORMAT_R8_SNORM,
    /// <summary>
    /// A single-component, 8-bit signed-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8_SINT)</para>
    /// </summary>
    R8_SINT = DXGI_FORMAT_R8_SINT,
    /// <summary>
    /// A single-component, 8-bit unsigned-integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_A8_UNORM)</para>
    /// </summary>
    A8_UNORM = DXGI_FORMAT_A8_UNORM,
    /// <summary>
    /// A single-component, 1-bit unsigned-normalized integer format. 2.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R1_UNORM)</para>
    /// </summary>
    R1_UNORM = DXGI_FORMAT_R1_UNORM,
    /// <summary>
    /// A four-component, 32-bit floating-point format. 2.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R9G9B9E5_SHAREDEXP)</para>
    /// </summary>
    R9G9B9E5_SHAREDEXP = DXGI_FORMAT_R9G9B9E5_SHAREDEXP,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized integer format. 3
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R8G8_B8G8_UNORM)</para>
    /// </summary>
    R8G8_B8G8_UNORM = DXGI_FORMAT_R8G8_B8G8_UNORM,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized integer format. 3
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_G8R8_G8B8_UNORM)</para>
    /// </summary>
    G8R8_G8B8_UNORM = DXGI_FORMAT_G8R8_G8B8_UNORM,
    /// <summary>
    /// Four-component typeless block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC1_TYPELESS)</para>
    /// </summary>
    BC1_TYPELESS = DXGI_FORMAT_BC1_TYPELESS,
    /// <summary>
    /// Four-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC1_UNORM)</para>
    /// </summary>
    BC1_UNORM = DXGI_FORMAT_BC1_UNORM,
    /// <summary>
    /// Four-component block-compression format for sRGB data.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC1_UNORM_SRGB)</para>
    /// </summary>
    BC1_UNORM_SRGB = DXGI_FORMAT_BC1_UNORM_SRGB,
    /// <summary>
    /// Four-component typeless block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC2_TYPELESS)</para>
    /// </summary>
    BC2_TYPELESS = DXGI_FORMAT_BC2_TYPELESS,
    /// <summary>
    /// Four-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC2_UNORM)</para>
    /// </summary>
    BC2_UNORM = DXGI_FORMAT_BC2_UNORM,
    /// <summary>
    /// Four-component block-compression format for sRGB data.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC2_UNORM_SRGB)</para>
    /// </summary>
    BC2_UNORM_SRGB = DXGI_FORMAT_BC2_UNORM_SRGB,
    /// <summary>
    /// Four-component typeless block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC3_TYPELESS)</para>
    /// </summary>
    BC3_TYPELESS = DXGI_FORMAT_BC3_TYPELESS,
    /// <summary>
    /// Four-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC3_UNORM)</para>
    /// </summary>
    BC3_UNORM = DXGI_FORMAT_BC3_UNORM,
    /// <summary>
    /// Four-component block-compression format for sRGB data.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC3_UNORM_SRGB)</para>
    /// </summary>
    BC3_UNORM_SRGB = DXGI_FORMAT_BC3_UNORM_SRGB,
    /// <summary>
    /// One-component typeless block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC4_TYPELESS)</para>
    /// </summary>
    BC4_TYPELESS = DXGI_FORMAT_BC4_TYPELESS,
    /// <summary>
    /// One-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC4_UNORM)</para>
    /// </summary>
    BC4_UNORM = DXGI_FORMAT_BC4_UNORM,
    /// <summary>
    /// One-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC4_SNORM)</para>
    /// </summary>
    BC4_SNORM = DXGI_FORMAT_BC4_SNORM,
    /// <summary>
    /// Two-component typeless block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC5_TYPELESS)</para>
    /// </summary>
    BC5_TYPELESS = DXGI_FORMAT_BC5_TYPELESS,
    /// <summary>
    /// Two-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC5_UNORM)</para>
    /// </summary>
    BC5_UNORM = DXGI_FORMAT_BC5_UNORM,
    /// <summary>
    /// Two-component block-compression format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC5_SNORM)</para>
    /// </summary>
    BC5_SNORM = DXGI_FORMAT_BC5_SNORM,
    /// <summary>
    /// A three-component, 16-bit unsigned-normalized integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B5G6R5_UNORM)</para>
    /// </summary>
    B5G6R5_UNORM = DXGI_FORMAT_B5G6R5_UNORM,
    /// <summary>
    /// A four-component, 16-bit unsigned-normalized integer format that supports 1-bit alpha.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B5G5R5A1_UNORM)</para>
    /// </summary>
    B5G5R5A1_UNORM = DXGI_FORMAT_B5G5R5A1_UNORM,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized integer format that supports 8-bit alpha.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B8G8R8A8_UNORM)</para>
    /// </summary>
    B8G8R8A8_UNORM = DXGI_FORMAT_B8G8R8A8_UNORM,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized integer format.
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B8G8R8X8_UNORM)</para>
    /// </summary>
    B8G8R8X8_UNORM = DXGI_FORMAT_B8G8R8X8_UNORM,
    /// <summary>
    /// A four-component, 32-bit format that supports 2-bit alpha. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM)</para>
    /// </summary>
    R10G10B10_XR_BIAS_A2_UNORM = DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM,
    /// <summary>
    /// A four-component, 32-bit typeless format that supports 8-bit alpha. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B8G8R8A8_TYPELESS)</para>
    /// </summary>
    B8G8R8A8_TYPELESS = DXGI_FORMAT_B8G8R8A8_TYPELESS,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized standard RGB format that supports 8-bit alpha. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B8G8R8A8_UNORM_SRGB)</para>
    /// </summary>
    B8G8R8A8_UNORM_SRGB = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
    /// <summary>
    /// A four-component, 32-bit typeless format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B8G8R8X8_TYPELESS)</para>
    /// </summary>
    B8G8R8X8_TYPELESS = DXGI_FORMAT_B8G8R8X8_TYPELESS,
    /// <summary>
    /// A four-component, 32-bit unsigned-normalized standard RGB format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_B8G8R8X8_UNORM_SRGB)</para>
    /// </summary>
    B8G8R8X8_UNORM_SRGB = DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,
    /// <summary>
    /// A typeless block-compression format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC6H_TYPELESS)</para>
    /// </summary>
    BC6H_TYPELESS = DXGI_FORMAT_BC6H_TYPELESS,
    /// <summary>
    /// A block-compression format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC6H_UF16)</para>
    /// </summary>
    BC6H_UF16 = DXGI_FORMAT_BC6H_UF16,
    /// <summary>
    /// A block-compression format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC6H_SF16)</para>
    /// </summary>
    BC6H_SF16 = DXGI_FORMAT_BC6H_SF16,
    /// <summary>
    /// A typeless block-compression format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC7_TYPELESS)</para>
    /// </summary>
    BC7_TYPELESS = DXGI_FORMAT_BC7_TYPELESS,
    /// <summary>
    /// A block-compression format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC7_UNORM)</para>
    /// </summary>
    BC7_UNORM = DXGI_FORMAT_BC7_UNORM,
    /// <summary>
    /// A block-compression format. 4
    /// <para>(Also see DirectX SDK: DXGI_FORMAT_BC7_UNORM_SRGB)</para>
    /// </summary>
    BC7_UNORM_SRGB = DXGI_FORMAT_BC7_UNORM_SRGB,

};
/// <summary>
/// Flags that indicate how the back buffers should be rotated to fit the physical rotation of a monitor.
/// <para>(Also see DirectX SDK: DXGI_MODE_ROTATION)</para>
/// </summary>
public enum class ModeRotation  : UInt32
{
    /// <summary>
    /// Unspecified rotation.
    /// <para>(Also see DirectX SDK: DXGI_MODE_ROTATION_UNSPECIFIED)</para>
    /// </summary>
    Unspecified = DXGI_MODE_ROTATION_UNSPECIFIED,
    /// <summary>
    /// Specifies no rotation.
    /// <para>(Also see DirectX SDK: DXGI_MODE_ROTATION_IDENTITY)</para>
    /// </summary>
    Identity = DXGI_MODE_ROTATION_IDENTITY,
    /// <summary>
    /// Specifies 90 degrees of rotation.
    /// <para>(Also see DirectX SDK: DXGI_MODE_ROTATION_ROTATE90)</para>
    /// </summary>
    Rotate90 = DXGI_MODE_ROTATION_ROTATE90,
    /// <summary>
    /// Specifies 180 degrees of rotation.
    /// <para>(Also see DirectX SDK: DXGI_MODE_ROTATION_ROTATE180)</para>
    /// </summary>
    Rotate180 = DXGI_MODE_ROTATION_ROTATE180,
    /// <summary>
    /// Specifies 270 degrees of rotation.
    /// <para>(Also see DirectX SDK: DXGI_MODE_ROTATION_ROTATE270)</para>
    /// </summary>
    Rotate270 = DXGI_MODE_ROTATION_ROTATE270,
};
/// <summary>
/// Flags indicating how an image is stretched to fit a given monitor's resolution.
/// <para>(Also see DirectX SDK: DXGI_MODE_SCALING)</para>
/// </summary>
public enum class ModeScaling  : UInt32
{
    /// <summary>
    /// Unspecified scaling.
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCALING_UNSPECIFIED)</para>
    /// </summary>
    Unspecified = DXGI_MODE_SCALING_UNSPECIFIED,
    /// <summary>
    /// Specifies no scaling. The image is centered on the display. This flag is typically used for a fixed-dot-pitch display (such as an LED display).
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCALING_CENTERED)</para>
    /// </summary>
    Centered = DXGI_MODE_SCALING_CENTERED,
    /// <summary>
    /// Specifies stretched scaling.
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCALING_STRETCHED)</para>
    /// </summary>
    Stretched = DXGI_MODE_SCALING_STRETCHED,
};
/// <summary>
/// Flags indicating the method the raster uses to create an image on a surface.
/// <para>(Also see DirectX SDK: DXGI_MODE_SCANLINE_ORDER)</para>
/// </summary>
public enum class ModeScanlineOrder  : UInt32
{
    /// <summary>
    /// Scanline order is unspecified.
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED)</para>
    /// </summary>
    Unspecified = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
    /// <summary>
    /// The image is created from the first scanline to the last without skipping any.
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE)</para>
    /// </summary>
    Progressive = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE,
    /// <summary>
    /// The image is created beginning with the upper field.
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST)</para>
    /// </summary>
    UpperFieldFirst = DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST,
    /// <summary>
    /// The image is created beginning with the lower field.
    /// <para>(Also see DirectX SDK: DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST)</para>
    /// </summary>
    LowerFieldFirst = DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST,
};
/// <summary>
/// Flags indicating the memory location of a resource.
/// <para>(Also see DirectX SDK: DXGI_RESIDENCY)</para>
/// </summary>
public enum class Residency  : UInt32
{
    /// <summary>
    /// The resource is located in video memory.
    /// <para>(Also see DirectX SDK: DXGI_RESIDENCY_FULLY_RESIDENT)</para>
    /// </summary>
    FullyResident = DXGI_RESIDENCY_FULLY_RESIDENT,
    /// <summary>
    /// At least some of the resource is located in CPU memory.
    /// <para>(Also see DirectX SDK: DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY)</para>
    /// </summary>
    ResidentInSharedMemory = DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY,
    /// <summary>
    /// At least some of the resource has been paged out to the hard drive.
    /// <para>(Also see DirectX SDK: DXGI_RESIDENCY_EVICTED_TO_DISK)</para>
    /// </summary>
    EvictedToDisk = DXGI_RESIDENCY_EVICTED_TO_DISK,
};
/// <summary>
/// Options for swap-chain behavior.
/// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_FLAG)</para>
/// </summary>
[Flags]
public enum class SwapChainFlag  : UInt32
{
    /// <summary>
    /// No flags.
    /// </summary>
    None = 0,
    /// <summary>
    /// Turn off automatic image rotation; that is, do not perform a rotation when transfering the contents of the front buffer to the monitor.         Use this flag to avoid a bandwidth penalty when an application expects to handle rotation. This option is only valid during full-screen mode.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_FLAG_NONPREROTATED)</para>
    /// </summary>
    NonPrerotated = DXGI_SWAP_CHAIN_FLAG_NONPREROTATED,
    /// <summary>
    /// Set this flag to enable an application to switch modes by calling SwapChain.ResizeTarget.         When switching from windowed to full-screen mode, the display mode (or monitor resolution) will be changed to match the dimensions of the application window.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH)</para>
    /// </summary>
    AllowModeSwitch = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH,
    /// <summary>
    /// Set this flag to enable an application to render using GDI on a swap chain or a surface.         This will allow the application to call GetDC on the 0th back buffer or a surface.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE)</para>
    /// </summary>
    GdiCompatible = DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE,
};
/// <summary>
/// Options for handling pixels in a display surface after calling SwapChain.Present.
/// <para>(Also see DirectX SDK: DXGI_SWAP_EFFECT)</para>
/// </summary>
public enum class SwapEffect  : UInt32
{
    /// <summary>
    /// Use this flag to indicate that the contents of the back buffer are discarded after calling SwapChain.Present.         This flag is valid for a swap chain with more than one back buffer, although, an application only has read and write access to buffer 0.         Use this flag to enable the display driver to select the most efficient presentation technique for the swap chain.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_EFFECT_DISCARD)</para>
    /// </summary>
    Discard = DXGI_SWAP_EFFECT_DISCARD,
    /// <summary>
    /// Use this flag to indicate that the contents of the back buffer are not discarded after calling SwapChain.Present.         Use this option to present the contents of the swap chain in order, from the first buffer (buffer 0) to the last buffer.         This flag cannot be used with multisampling.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_EFFECT_SEQUENTIAL)</para>
    /// </summary>
    Sequential = DXGI_SWAP_EFFECT_SEQUENTIAL,
};

/// <summary>
/// Flags for making window association with a surface.
/// </summary>
[Flags]
public enum class MakeWindowAssociationFlags : UInt32
{
    /// <summary>
    /// Prevent DXGI from monitoring an applications message queue;  this makes DXGI unable to respond to mode changes.
    /// <para>(Also see DirectX SDK: DXGI_MWA_NO_WINDOW_CHANGES)</para>
    /// </summary>
    NoWindowChanges = DXGI_MWA_NO_WINDOW_CHANGES,

    /// <summary>
    /// Prevent DXGI from responding to an alt-enter sequence.
    /// <para>(Also see DirectX SDK: DXGI_MWA_NO_ALT_ENTER)</para>
    /// </summary>        
    NoAltEnter = DXGI_MWA_NO_ALT_ENTER,

    /// <summary>
    /// Prevent DXGI from responding to a print-screen key.
    /// <para>(Also see DirectX SDK: DXGI_MWA_NO_PRINT_SCREEN)</para>
    /// </summary>        
    NoPrintScreen = DXGI_MWA_NO_PRINT_SCREEN ,
};

/// <summary>
/// CPU read-write flags. These flags can be combined with a logical OR.
/// </summary>
[Flags]
public enum class MapOption : UInt32
{
    /// <summary>
    /// Unspecified.
    /// </summary>
    Unspecified  = 0L,
    /// <summary>
    /// Allow CPU read access.
    /// <para>(Also see DirectX SDK: DXGI_MAP_READ)</para>
    /// </summary>
    Read = DXGI_MAP_READ,

    /// <summary>
    /// Allow CPU write access.
    /// <para>(Also see DirectX SDK: DXGI_MAP_WRITE)</para>
    /// </summary>
    Write = DXGI_MAP_WRITE,

    /// <summary>
    /// Discard the previous contents of a resource when it is mapped.
    /// <para>(Also see DirectX SDK: DXGI_MAP_DISCARD)</para>
    /// </summary>
    Discard = DXGI_MAP_DISCARD,
};

/// <summary>
/// Resource Priorities.
/// </summary>
[Flags]
public enum class ResourcePriority : UInt32
{
    /// <summary>
    /// <para>(Also see DirectX SDK:  DXGI_RESOURCE_PRIORITY_MINIMUM )</para>
    /// </summary>
    Minimum = DXGI_RESOURCE_PRIORITY_MINIMUM, 

    /// <summary>
    /// <para>(Also see DirectX SDK:  DXGI_RESOURCE_PRIORITY_LOW )</para>
    /// </summary>
    Low = DXGI_RESOURCE_PRIORITY_LOW, 

    /// <summary>
    /// <para>(Also see DirectX SDK:  DXGI_RESOURCE_PRIORITY_NORMAL )</para>
    /// </summary>
    Normal = DXGI_RESOURCE_PRIORITY_NORMAL, 
    
    /// <summary>
    /// <para>(Also see DirectX SDK:  DXGI_RESOURCE_PRIORITY_HIGH )</para>
    /// </summary>
    High = DXGI_RESOURCE_PRIORITY_HIGH, 

    /// <summary>
    /// <para>(Also see DirectX SDK:  DXGI_RESOURCE_PRIORITY_MAXIMUM )</para>
    /// </summary>
    Maximum = DXGI_RESOURCE_PRIORITY_MAXIMUM
};
} } } }
