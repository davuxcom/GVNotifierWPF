//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace msclr::interop;

using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;

    namespace D3D11 = Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 { 

/// <summary>
/// Describes the blend state for a render target.
/// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC)</para>
/// </summary>
public value struct RenderTargetBlendDescription 
{
public:
    /// <summary>
    /// Enable (or disable) blending.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.BlendEnable)</para>
    /// </summary>
    Boolean BlendEnable;
    /// <summary>
    /// This blend option specifies the first RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.SrcBlend)</para>
    /// </summary>
    Blend SourceBlend;
    /// <summary>
    /// This blend option specifies the second RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.DestBlend)</para>
    /// </summary>
    Blend DestinationBlend;
    /// <summary>
    /// This blend operation defines how to combine the RGB data sources.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.BlendOp)</para>
    /// </summary>
    D3D11::BlendOperation BlendOperation;
    /// <summary>
    /// This blend option specifies the first alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.SrcBlendAlpha)</para>
    /// </summary>
    Blend SourceBlendAlpha;
    /// <summary>
    /// This blend option specifies the second alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.DestBlendAlpha)</para>
    /// </summary>
    Blend DestinationBlendAlpha;
    /// <summary>
    /// This blend operation defines how to combine the alpha data sources.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.BlendOpAlpha)</para>
    /// </summary>
    D3D11::BlendOperation BlendOperationAlpha;
    /// <summary>
    /// A write mask.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.RenderTargetWriteMask)</para>
    /// </summary>
    ColorWriteEnable RenderTargetWriteMask;
};
/// <summary>
/// Describes the blend state.
/// <para>(Also see DirectX SDK: D3D11_BLEND_DESC)</para>
/// </summary>
public value struct BlendDescription 
{
public:
    /// <summary>
    /// Determines whether or not to use alpha-to-coverage as a multisampling technique when setting a pixel to a rendertarget.
    /// <para>(Also see DirectX SDK: D3D11_BLEND_DESC.AlphaToCoverageEnable)</para>
    /// </summary>
    Boolean AlphaToCoverageEnable;
    /// <summary>
    /// Set to TRUE to enable independent blending in simultaneous render targets.
    /// <para>(Also see DirectX SDK: D3D11_BLEND_DESC.IndependentBlendEnable)</para>
    /// </summary>
    Boolean IndependentBlendEnable;
    /// <summary>
    /// A collection of render-target-blend descriptions (see <see cref="RenderTargetBlendDescription"/>)<seealso cref="RenderTargetBlendDescription"/>; these correspond to the eight rendertargets that can be set to the output-merger stage at one time.
    /// <para>(Also see DirectX SDK: D3D11_BLEND_DESC.RenderTarget)</para>
    /// </summary>
    property array<RenderTargetBlendDescription>^ RenderTarget
    {
        array<RenderTargetBlendDescription>^ get()
        {
            if (renderTarget == nullptr)
            {
                renderTarget  = gcnew array<RenderTargetBlendDescription>(RenderTargetArrayLength);
            }

            return renderTarget;
        }
    }
internal:
    BlendDescription(const D3D11_BLEND_DESC& blendDescription)
    {
        AlphaToCoverageEnable = blendDescription.AlphaToCoverageEnable != 0;
        IndependentBlendEnable = blendDescription.IndependentBlendEnable != 0;

        renderTarget = gcnew array<RenderTargetBlendDescription>(RenderTargetArrayLength);
        pin_ptr<RenderTargetBlendDescription> renderTargetPtr = &renderTarget[0];

        memcpy(renderTargetPtr, blendDescription.RenderTarget, sizeof(D3D11_RENDER_TARGET_BLEND_DESC) * RenderTargetArrayLength);
    }

    void CopyTo(D3D11_BLEND_DESC* blendDescription)
    {
        blendDescription->AlphaToCoverageEnable = AlphaToCoverageEnable ? 1 :0;
        blendDescription->IndependentBlendEnable = IndependentBlendEnable ? 1 :0;

        if (renderTarget != nullptr)
        {
            pin_ptr<RenderTargetBlendDescription> renderTargetPtr = &renderTarget[0];
            memcpy(blendDescription->RenderTarget, renderTargetPtr, sizeof(D3D11_RENDER_TARGET_BLEND_DESC) * RenderTargetArrayLength);
        }
        else
        {
            ZeroMemory(blendDescription->RenderTarget, sizeof(D3D11_RENDER_TARGET_BLEND_DESC) * RenderTargetArrayLength);
        }
    }
private:
    literal int RenderTargetArrayLength = 8;
    array<RenderTargetBlendDescription>^ renderTarget;
};
/// <summary>
/// Defines a 3D box.
/// <para>(Also see DirectX SDK: D3D11_BOX)</para>
/// </summary>
public value struct Box 
{
public:
    /// <summary>
    /// The x position of the left hand side of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.left)</para>
    /// </summary>
    UInt32 Left;
    /// <summary>
    /// The y position of the top of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.top)</para>
    /// </summary>
    UInt32 Top;
    /// <summary>
    /// The z position of the front of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.front)</para>
    /// </summary>
    UInt32 Front;
    /// <summary>
    /// The x position of the right hand side of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.right)</para>
    /// </summary>
    UInt32 Right;
    /// <summary>
    /// The y position of the bottom of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.bottom)</para>
    /// </summary>
    UInt32 Bottom;
    /// <summary>
    /// The z position of the back of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.back)</para>
    /// </summary>
    UInt32 Back;
public:
    static Boolean operator == ( Box a, Box b )
    {
        return 
            (a.Back == b.Back)  &&
            (a.Bottom == b.Bottom)  &&
            (a.Front == b.Front)  &&
            (a.Left == b.Left)  &&
            (a.Right == b.Right)  &&
            (a.Top == b.Top);
    }

    static Boolean operator != ( Box a, Box b )
    {
        return !(a == b);
    }

internal:
    Box(const D3D11_BOX& nBox)
    {
        Left = nBox.left;
        Top = nBox.top;
        Front = nBox.front;
        Right = nBox.right;
        Bottom = nBox.bottom;
        Back = nBox.back;
    }
};
/// <summary>
/// Describes a raw buffer resource.
/// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV)</para>
/// </summary>
public value struct BufferExShaderResourceView 
{
public:
    /// <summary>
    /// The index of the first element to be accessed by the view.
    /// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV.FirstElement)</para>
    /// </summary>
    UInt32 FirstElement;
    /// <summary>
    /// The number of elements in the resource.
    /// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV.NumElements)</para>
    /// </summary>
    UInt32 NumElements;
    /// <summary>
    /// Options for binding a raw buffer (see <see cref="BufferExShaderResourceViewFlag"/>)<seealso cref="BufferExShaderResourceViewFlag"/>
    /// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV.Flags)</para>
    /// </summary>
    BufferExShaderResourceViewFlag Flags;
};
/// <summary>
/// Describes a buffer resource.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC)</para>
/// </summary>
public value struct BufferDescription 
{
public:
    /// <summary>
    /// Size of the buffer in bytes.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.ByteWidth)</para>
    /// </summary>
    UInt32 ByteWidth;
    /// <summary>
    /// Identify how the buffer is expected to be read from and written to. Frequency of update is a key factor. The most common value is typically Usage_DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.Usage)</para>
    /// </summary>
    D3D11::Usage Usage;
    /// <summary>
    /// Identify how the buffer will be bound to the pipeline. Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// CPU access flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> or 0 if no CPU access is necessary. Flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Miscellaneous flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> or 0 if unused. Flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;
    /// <summary>
    /// The size of the structure (in bytes) when it represents a structured buffer.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.StructureByteStride)</para>
    /// </summary>
    UInt32 StructureByteStride;

internal:
    BufferDescription (const D3D11_BUFFER_DESC& desc)
    {
        ByteWidth = desc.ByteWidth;
        Usage = static_cast<D3D11::Usage>(desc.Usage);
        BindFlags = static_cast<D3D11::BindFlag>(desc.BindFlags);
        CpuAccessFlags = static_cast<D3D11::CpuAccessFlag>(desc.CPUAccessFlags);
        StructureByteStride = desc.StructureByteStride;
        MiscFlags = static_cast<D3D11::ResourceMiscFlag>(desc.MiscFlags);

    }

    void CopyTo(D3D11_BUFFER_DESC* desc)
    {
        desc->ByteWidth = ByteWidth;
        desc->Usage = static_cast<D3D11_USAGE>(Usage);
        desc->BindFlags = static_cast<UINT>(BindFlags);
        desc->CPUAccessFlags = static_cast<UINT>(CpuAccessFlags);
        desc->StructureByteStride = StructureByteStride;
        desc->MiscFlags = static_cast<UINT>(MiscFlags);
    }


};
/// <summary>
/// Specifies the elements in a buffer resource to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_RTV)</para>
/// </summary>
public value struct BufferRenderTargetView 
{
public:
    /// <summary>
    /// Number of bytes between the beginning of the buffer and the first element to access.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_RTV.ElementOffset)</para>
    /// </summary>
    UInt32 ElementOffset;
    /// <summary>
    /// The width of each element (in bytes). This can be determined from the format stored in the render-target-view description.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_RTV.ElementWidth)</para>
    /// </summary>
    UInt32 ElementWidth;
};
/// <summary>
/// Specifies the elements in a buffer resource to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_SRV)</para>
/// </summary>
public value struct BufferShaderResourceView
{
public:
    /// <summary>
    /// The offset of the first element in the view to access, relative to element 0.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_SRV.ElementOffset)</para>
    /// </summary>
    UInt32 ElementOffset;
    /// <summary>
    /// The total number of elements in the view.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_SRV.ElementWidth)</para>
    /// </summary>
    UInt32 ElementWidth;
};
/// <summary>
/// Describes a unordered-access buffer resource.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV)</para>
/// </summary>
public value struct BufferUnorderedAccessView 
{
public:
    /// <summary>
    /// The zero-based index of the first element to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV.FirstElement)</para>
    /// </summary>
    UInt32 FirstElement;
    /// <summary>
    /// The number of elements in the resource.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV.NumElements)</para>
    /// </summary>
    UInt32 NumElements;
    /// <summary>
    /// View options for the resource (see <see cref="BufferUnorderedAccessViewFlag"/>)<seealso cref="BufferUnorderedAccessViewFlag"/>.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV.Flags)</para>
    /// </summary>
    BufferUnorderedAccessViewFlag Flags;
};
/// <summary>
/// Describes an HLSL class instance.
/// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC)</para>
/// </summary>
public value struct ClassInstanceDescription 
{
public:
    /// <summary>
    /// The instance ID of an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.InstanceId)</para>
    /// </summary>
    UInt32 InstanceId;
    /// <summary>
    /// The instance index of an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.InstanceIndex)</para>
    /// </summary>
    UInt32 InstanceIndex;
    /// <summary>
    /// The type ID of an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.TypeId)</para>
    /// </summary>
    UInt32 TypeId;
    /// <summary>
    /// Describes the constant buffer associated with an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.ConstantBuffer)</para>
    /// </summary>
    UInt32 ConstantBuffer;
    /// <summary>
    /// The base constant buffer offset associated with an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.BaseConstantBufferOffset)</para>
    /// </summary>
    UInt32 BaseConstantBufferOffset;
    /// <summary>
    /// The base texture associated with an HLSL class; the default value is 127.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.BaseTexture)</para>
    /// </summary>
    UInt32 BaseTexture;
    /// <summary>
    /// The base sampler associated with an HLSL class; the default value is 15.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.BaseSampler)</para>
    /// </summary>
    UInt32 BaseSampler;
    /// <summary>
    /// True if the class was created; the default value is false.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.Created)</para>
    /// </summary>
    Boolean Created;
};

/// <summary>
/// Describes a counter.
/// <para>(Also see DirectX SDK: D3D11_COUNTER_DESC)</para>
/// </summary>
public value struct CounterDescription 
{
public:
    /// <summary>
    /// Type of counter (see <see cref="D3D11::Counter"/>)<seealso cref="D3D11::Counter"/>.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_DESC.Counter)</para>
    /// </summary>
    D3D11::Counter Counter;
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_DESC.MiscFlags)</para>
    /// </summary>
    UInt32 MiscFlags;
internal:
    CounterDescription(const D3D11_COUNTER_DESC& desc)
    {
        Counter = static_cast<D3D11::Counter>(desc.Counter);
        MiscFlags = desc.MiscFlags;
    }
    
    void CopyTo(D3D11_COUNTER_DESC* desc)
    {
        desc->Counter = static_cast<D3D11_COUNTER>(Counter);
        desc->MiscFlags = MiscFlags;
    }
};

/// <summary>
/// Information about the video card's performance counter capabilities.
/// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO)</para>
/// </summary>
public value struct CounterInformation
{
public:
    /// <summary>
    /// Largest device-dependent counter ID that the device supports. If none are supported, this value will be 0. Otherwise it will be greater than or equal to DeviceDependent_0.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO.LastDeviceDependentCounter)</para>
    /// </summary>
    D3D11::Counter LastDeviceDependentCounter;
    /// <summary>
    /// Number of counters that can be simultaneously supported.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO.NumSimultaneousCounters)</para>
    /// </summary>
    UInt32 NumSimultaneousCounters;
    /// <summary>
    /// Number of detectable parallel units that the counter is able to discern. Values are 1 ~ 4. Use NumDetectableParallelUnits to interpret the values of the VERTEX_PROCESSING, GEOMETRY_PROCESSING, PIXEL_PROCESSING, and OTHER_GPU_PROCESSING counters.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO.NumDetectableParallelUnits)</para>
    /// </summary>;
    Byte NumDetectableParallelUnits;

internal: 
    CounterInformation(const D3D11_COUNTER_INFO& info)
    {
        LastDeviceDependentCounter = static_cast<D3D11::Counter>(info.LastDeviceDependentCounter);
        NumSimultaneousCounters = info.NumSimultaneousCounters;
        NumDetectableParallelUnits = info.NumDetectableParallelUnits;
    }
};


/// <summary>
/// Stencil operations that can be performed based on the results of stencil test.
/// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC)</para>
/// </summary>
public value struct DepthStencilOperationDescription 
{
public:
    /// <summary>
    /// The stencil operation to perform when stencil testing fails.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilFailOp)</para>
    /// </summary>
    StencilOperation StencilFailOperation;
    /// <summary>
    /// The stencil operation to perform when stencil testing passes and depth testing fails.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilDepthFailOp)</para>
    /// </summary>
    StencilOperation StencilDepthFailOperation;
    /// <summary>
    /// The stencil operation to perform when stencil testing and depth testing both pass.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilPassOp)</para>
    /// </summary>
    StencilOperation StencilPassOperation;
    /// <summary>
    /// A function that compares stencil data against existing stencil data. The function options are listed in ComparisonFunction.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilFunc)</para>
    /// </summary>
    ComparisonFunction StencilFunction;
};
/// <summary>
/// Specifies the subresources from an array of 1D textures to use in a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV)</para>
/// </summary>
public value struct Texture1DArrayDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresources from an array of 1D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV)</para>
/// </summary>
public value struct Texture1DArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresources from an array of 1D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV)</para>
/// </summary>
public value struct Texture1DArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Describes an array of unordered-access 1D texture resources.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV)</para>
/// </summary>
public value struct Texture1DArrayUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The zero-based index of the first array slice to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// The number of slices in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource from a 1D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_DSV)</para>
/// </summary>
public value struct Texture1DDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 1D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_RTV)</para>
/// </summary>
public value struct Texture1DRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 1D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_SRV)</para>
/// </summary>
public value struct Texture1DShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Describes a unordered-access 1D texture resource.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_UAV)</para>
/// </summary>
public value struct Texture1DUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_UAV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresources from an array of multisampled 2D textures for a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_DSV)</para>
/// </summary>
public value struct Texture2DMultiSampleArrayDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresources from a an array of multisampled 2D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_RTV)</para>
/// </summary>
public value struct Texture2DMultiSampleArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresources from an array of multisampled 2D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_SRV)</para>
/// </summary>
public value struct Texture2DMultiSampleArrayShaderResourceView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource from a multisampled 2D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_DSV)</para>
/// </summary>
public value struct Texture2DMultiSampleDepthStencilView 
{
public:
    /// <summary>
    /// Unused.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_DSV.UnusedField_NothingToDefine)</para>
    /// </summary>
    UInt32 UnusedField;
};
/// <summary>
/// Specifies the subresource from a multisampled 2D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_RTV)</para>
/// </summary>
public value struct Texture2DMultiSampleRenderTargetView 
{
public:
    /// <summary>
    /// Integer of any value.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_RTV.UnusedField_NothingToDefine)</para>
    /// </summary>
    UInt32 UnusedField;
};
/// <summary>
/// Specifies the subresources from a multisampled 2D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_SRV)</para>
/// </summary>
public value struct Texture2DMultiSampleShaderResourceView 
{
public:
    /// <summary>
    /// Integer of any value.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_SRV.UnusedField_NothingToDefine)</para>
    /// </summary>
    UInt32 UnusedField;
};
/// <summary>
/// Specifies the subresources from an array 2D textures that are accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV)</para>
/// </summary>
public value struct Texture2DArrayDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresources from an array of 2D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV)</para>
/// </summary>
public value struct Texture2DArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures in the array to use in the render target view, starting from FirstArraySlice.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresources from an array of 2D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV)</para>
/// </summary>
public value struct Texture2DArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Describes an array of unordered-access 2D texture resources.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV)</para>
/// </summary>
public value struct Texture2DArrayUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The zero-based index of the first array slice to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// The number of slices in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource from a 2D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_DSV)</para>
/// </summary>
public value struct Texture2DDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 2D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_RTV)</para>
/// </summary>
public value struct Texture2DRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 2D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_SRV)</para>
/// </summary>
public value struct Texture2DShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Describes a unordered-access 2D texture resource.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_UAV)</para>
/// </summary>
public value struct Texture2DUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_UAV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresources from a 3D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV)</para>
/// </summary>
public value struct Texture3DRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// First depth level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV.FirstWSlice)</para>
    /// </summary>
    UInt32 FirstWSlice;
    /// <summary>
    /// Number of depth levels to use in the render-target view, starting from FirstWSlice. A value of -1 indicates all of the slices along the w axis, starting from FirstWSlice.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV.WSize)</para>
    /// </summary>
    UInt32 WSize;
};
/// <summary>
/// Specifies the subresources from a 3D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX3D_SRV)</para>
/// </summary>
public value struct Texture3DShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Describes a unordered-access 3D texture resource.
/// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV)</para>
/// </summary>
public value struct Texture3DUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The zero-based index of the first depth slice to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV.FirstWSlice)</para>
    /// </summary>
    UInt32 FirstWSlice;
    /// <summary>
    /// The number of depth slices.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV.WSize)</para>
    /// </summary>
    UInt32 WSize;
};
/// <summary>
/// Specifies the subresources from an array of cube textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV)</para>
/// </summary>
public value struct TextureCubeArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Index of the first 2D texture to use.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.First2DArrayFace)</para>
    /// </summary>
    UInt32 First2DArrayFace;
    /// <summary>
    /// Number of cube textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.NumCubes)</para>
    /// </summary>
    UInt32 NumCubes;
};
/// <summary>
/// Specifies the subresource from a cube texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEXCUBE_SRV)</para>
/// </summary>
public value struct TextureCubeShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Describes a 1D texture.
/// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC)</para>
/// </summary>
public value struct Texture1DDescription 
{
public:
    /// <summary>
    /// Texture width (in texels).
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView. Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.Usage)</para>
    /// </summary>
    D3D11::Usage Usage;
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR. For a 1D texture, the allowable values are: ShaderResource, RenderTarget and DepthStencil.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;
};
/// <summary>
/// Describes a 2D texture.
/// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC)</para>
/// </summary>
public value struct Texture2DDescription 
{
public:
    /// <summary>
    /// Texture width (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// Texture height (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView. Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Number of textures in the texture array.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// Structure that specifies multisampling parameters for the texture. See SampleDescription.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.SampleDesc)</para>
    /// </summary>
    DXGI::SampleDescription SampleDescription;
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Usage)</para>
    /// </summary>
    D3D11::Usage Usage;
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;
};
/// <summary>
/// Describes a 3D texture.
/// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC)</para>
/// </summary>
public value struct Texture3DDescription 
{
public:
    /// <summary>
    /// Texture width (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// Texture height (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// Texture depth (in texels)
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Depth)</para>
    /// </summary>
    UInt32 Depth;
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Texture1DShaderResourceView. Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Usage)</para>
    /// </summary>
    D3D11::Usage Usage;
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;
};
/// <summary>
/// Specifies the subresources of a texture that are accessible from a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct DepthStencilViewDescription 
{
public:
    /// <summary>
    /// Resource data  format (see <see cref="Format"/>)<seealso cref="Format"/>. See remarks for allowable formats.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// Type of resource (see <see cref="DepthStencilViewDimension"/>)<seealso cref="DepthStencilViewDimension"/>. Specifies how a depth-stencil resource will be accessed; the value is stored in the union in this structure.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    DepthStencilViewDimension ViewDimension;
    /// <summary>
    /// A value that describes whether the texture is read only.  Pass 0 to specify that it is not read only; otherwise, pass one of the members of the DepthStencilViewFlag enumerated type.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Flags)</para>
    /// </summary>
    [FieldOffset(8)]
    DepthStencilViewFlag Flags;
    /// <summary>
    /// Specifies a 1D texture subresource (see <see cref="Texture1DDepthStencilView"/>)<seealso cref="Texture1DDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(12)]
    Texture1DDepthStencilView Texture1D;
    /// <summary>
    /// Specifies an array of 1D texture subresources (see <see cref="Texture1DArrayDepthStencilView"/>)<seealso cref="Texture1DArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(12)]
    Texture1DArrayDepthStencilView Texture1DArray;
    /// <summary>
    /// Specifies a 2D texture subresource (see <see cref="Texture2DDepthStencilView"/>)<seealso cref="Texture2DDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(12)]
    Texture2DDepthStencilView Texture2D;
    /// <summary>
    /// Specifies an array of 2D texture subresources (see <see cref="Texture2DArrayDepthStencilView"/>)<seealso cref="Texture2DArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(12)]
    Texture2DArrayDepthStencilView Texture2DArray;
    /// <summary>
    /// Specifies a multisampled 2D texture (see <see cref="Texture2DMultiSampleDepthStencilView"/>)<seealso cref="Texture2DMultiSampleDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2DMS)</para>
    /// </summary>
    [FieldOffset(12)]
    Texture2DMultiSampleDepthStencilView Texture2DMultiSample;
    /// <summary>
    /// Specifies an array of multisampled 2D textures (see <see cref="Texture2DMultiSampleArrayDepthStencilView"/>)<seealso cref="Texture2DMultiSampleArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(12)]
    Texture2DMultiSampleArrayDepthStencilView Texture2DMultiSampleArray;

internal:
    DepthStencilViewDescription(const D3D11_DEPTH_STENCIL_VIEW_DESC& desc)
    {
        Format = static_cast<DXGI::Format>(desc.Format);
        ViewDimension = static_cast<DepthStencilViewDimension>(desc.ViewDimension);
        Flags = static_cast<DepthStencilViewFlag>(desc.Flags);

        switch (ViewDimension)
        {
        case DepthStencilViewDimension::Texture1D :
              {
                  Texture1D.MipSlice = desc.Texture1D.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture1DArray :
              {
                  Texture1DArray.ArraySize = desc.Texture1DArray.ArraySize;
                  Texture1DArray.FirstArraySlice = desc.Texture1DArray.FirstArraySlice;
                  Texture1DArray.MipSlice = desc.Texture1DArray.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture2D :
              {
                  Texture2D.MipSlice = desc.Texture2D.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture2DArray :
              {
                  Texture2DArray.ArraySize = desc.Texture2DArray.ArraySize;
                  Texture2DArray.FirstArraySlice = desc.Texture2DArray.FirstArraySlice;
                  Texture2DArray.MipSlice = desc.Texture2DArray.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture2DMultiSample :
              {
                  Texture2DMultiSample.UnusedField = desc.Texture2DMS.UnusedField_NothingToDefine;
                  break;
              }
        case DepthStencilViewDimension::Texture2DMultiSampleArray :
              {
                  Texture2DMultiSampleArray.ArraySize = desc.Texture2DMSArray.ArraySize;
                  Texture2DMultiSampleArray.FirstArraySlice = desc.Texture2DMSArray.FirstArraySlice;
                  break;
              }
        default :
              {
                  throw gcnew NotSupportedException("Unknown or not supported DepthStencilViewDimension.");
              }
        }
    }

    void CopyTo(D3D11_DEPTH_STENCIL_VIEW_DESC* desc)
    {
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->ViewDimension = static_cast<D3D11_DSV_DIMENSION>(ViewDimension);
        desc->Flags = static_cast<UINT>(Flags);

        switch (ViewDimension)
        {
        case DepthStencilViewDimension::Texture1D :
              {
                  desc->Texture1D.MipSlice = Texture1D.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture1DArray :
              {
                  desc->Texture1DArray.ArraySize = Texture1DArray.ArraySize;
                  desc->Texture1DArray.FirstArraySlice = Texture1DArray.FirstArraySlice;
                  desc->Texture1DArray.MipSlice = Texture1DArray.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture2D :
              {
                  desc->Texture2D.MipSlice = Texture2D.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture2DArray :
              {
                  desc->Texture2DArray.ArraySize = Texture2DArray.ArraySize;
                  desc->Texture2DArray.FirstArraySlice = Texture2DArray.FirstArraySlice;
                  desc->Texture2DArray.MipSlice = Texture2DArray.MipSlice;
                  break;
              }
        case DepthStencilViewDimension::Texture2DMultiSample :
              {
                  desc->Texture2DMS.UnusedField_NothingToDefine = Texture2DMultiSample.UnusedField;
                  break;
              }
        case DepthStencilViewDimension::Texture2DMultiSampleArray :
              {
                  desc->Texture2DMSArray.ArraySize = Texture2DMultiSampleArray.ArraySize;
                  desc->Texture2DMSArray.FirstArraySlice = Texture2DMultiSampleArray.FirstArraySlice;
                  break;
              }
        default:
              {
                  throw gcnew NotSupportedException("Unknown or not supported DepthStencilViewDimension.");
              }
        }
    }

};
/// <summary>
/// Describes depth-stencil state.
/// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC)</para>
/// </summary>
public value struct DepthStencilDescription 
{
public:
    /// <summary>
    /// Enable depth testing.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.DepthEnable)</para>
    /// </summary>
    Boolean DepthEnable;
    /// <summary>
    /// Identify a portion of the depth-stencil buffer that can be modified by depth data (see <see cref="DepthWriteMask"/>)<seealso cref="DepthWriteMask"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.DepthWriteMask)</para>
    /// </summary>
    D3D11::DepthWriteMask DepthWriteMask;
    /// <summary>
    /// A function that compares depth data against existing depth data. The function options are listed in ComparisonFunction.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.DepthFunc)</para>
    /// </summary>
    ComparisonFunction DepthFunction;
    /// <summary>
    /// Enable stencil testing.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.StencilEnable)</para>
    /// </summary>
    Boolean StencilEnable;
    /// <summary>
    /// Identify a portion of the depth-stencil buffer for reading stencil data.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.StencilReadMask)</para>
    /// </summary>
    D3D11::StencilReadMask StencilReadMask;
    /// <summary>
    /// Identify a portion of the depth-stencil buffer for writing stencil data.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.StencilWriteMask)</para>
    /// </summary>
    D3D11::StencilWriteMask StencilWriteMask;
    /// <summary>
    /// Identify how to use the results of the depth test and the stencil test for pixels whose surface normal is facing towards the camera (see <see cref="DepthStencilOperationDescription"/>)<seealso cref="DepthStencilOperationDescription"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.FrontFace)</para>
    /// </summary>
    DepthStencilOperationDescription FrontFace;
    /// <summary>
    /// Identify how to use the results of the depth test and the stencil test for pixels whose surface normal is facing away from the camera (see <see cref="DepthStencilOperationDescription"/>)<seealso cref="DepthStencilOperationDescription"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.BackFace)</para>
    /// </summary>
    DepthStencilOperationDescription BackFace;

internal:
    DepthStencilDescription (const D3D11_DEPTH_STENCIL_DESC & desc)
    {
        DepthEnable = desc.DepthEnable != 0;
        DepthWriteMask = static_cast<D3D11::DepthWriteMask>(desc.DepthWriteMask);
        DepthFunction = static_cast<D3D11::ComparisonFunction>(desc.DepthFunc);
        StencilEnable = desc.StencilEnable != 0;
        StencilReadMask = static_cast<D3D11::StencilReadMask>(desc.StencilReadMask);
        StencilWriteMask = static_cast<D3D11::StencilWriteMask>(desc.StencilWriteMask);
        
        FrontFace.StencilFailOperation = static_cast<StencilOperation>(desc.FrontFace.StencilFailOp);
        FrontFace.StencilDepthFailOperation = static_cast<StencilOperation>(desc.FrontFace.StencilDepthFailOp);
        FrontFace.StencilPassOperation = static_cast<StencilOperation>(desc.FrontFace.StencilPassOp);
        FrontFace.StencilFunction = static_cast<ComparisonFunction>(desc.FrontFace.StencilFunc);

        BackFace.StencilFailOperation = static_cast<StencilOperation>(desc.BackFace.StencilFailOp);
        BackFace.StencilDepthFailOperation = static_cast<StencilOperation>(desc.BackFace.StencilDepthFailOp);
        BackFace.StencilPassOperation = static_cast<StencilOperation>(desc.BackFace.StencilPassOp);
        BackFace.StencilFunction = static_cast<ComparisonFunction>(desc.BackFace.StencilFunc);
    }

    void CopyTo (D3D11_DEPTH_STENCIL_DESC * desc)
    {
        desc->DepthEnable = DepthEnable ? 1 : 0;
        desc->DepthWriteMask = static_cast<D3D11_DEPTH_WRITE_MASK>(DepthWriteMask);
        desc->DepthFunc = static_cast<D3D11_COMPARISON_FUNC>(DepthFunction);
        desc->StencilEnable = StencilEnable ? 1 : 0;
        desc->StencilReadMask = static_cast<UINT8>(StencilReadMask);
        desc->StencilWriteMask = static_cast<UINT8>(StencilWriteMask);
        
        desc->FrontFace.StencilFailOp = static_cast<D3D11_STENCIL_OP>(FrontFace.StencilFailOperation);
        desc->FrontFace.StencilDepthFailOp = static_cast<D3D11_STENCIL_OP>(FrontFace.StencilDepthFailOperation);
        desc->FrontFace.StencilPassOp = static_cast<D3D11_STENCIL_OP>(FrontFace.StencilPassOperation );
        desc->FrontFace.StencilFunc = static_cast<D3D11_COMPARISON_FUNC>(FrontFace.StencilFunction);

        desc->BackFace.StencilFailOp = static_cast<D3D11_STENCIL_OP>(BackFace.StencilFailOperation);
        desc->BackFace.StencilDepthFailOp = static_cast<D3D11_STENCIL_OP>(BackFace.StencilDepthFailOperation);
        desc->BackFace.StencilPassOp = static_cast<D3D11_STENCIL_OP>(BackFace.StencilPassOperation );
        desc->BackFace.StencilFunc = static_cast<D3D11_COMPARISON_FUNC>(BackFace.StencilFunction);
    }
};
/// <summary>
/// Describes the multi-threading features that are supported by the current graphics driver.
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_THREADING)</para>
/// </summary>
public value struct FeatureDataThreading 
{
public:
    /// <summary>
    /// TRUE means resources can be created concurrently on multiple threads while drawing; FALSE means that the presence of coarse synchronization will prevent concurrency.
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_THREADING.DriverConcurrentCreates)</para>
    /// </summary>
    Boolean DriverConcurrentCreates;
    /// <summary>
    /// TRUE means command lists are supported by the current driver; FALSE means that the API will emulate deferred contexts and command lists with software.
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_THREADING.DriverCommandLists)</para>
    /// </summary>
    Boolean DriverCommandLists;

internal:
    FeatureDataThreading(const D3D11_FEATURE_DATA_THREADING & feature)
    {
        DriverConcurrentCreates = feature.DriverConcurrentCreates != 0;
        DriverCommandLists = feature.DriverCommandLists != 0;
    }

    void CopyTo(D3D11_FEATURE_DATA_THREADING * feature)
    {
        feature->DriverConcurrentCreates = DriverConcurrentCreates ? 1 : 0;
        feature->DriverCommandLists = DriverCommandLists ? 1 : 0;
    }
};
/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_DOUBLES)</para>
/// </summary>
public value struct FeatureDataDoubles 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_DOUBLES.DoublePrecisionFloatShaderOps)</para>
    /// </summary>
    Boolean DoublePrecisionFloatShaderOperations;

internal:
    FeatureDataDoubles(const D3D11_FEATURE_DATA_DOUBLES & feature)
    {
        DoublePrecisionFloatShaderOperations = feature.DoublePrecisionFloatShaderOps != 0;
    }

    void CopyTo(D3D11_FEATURE_DATA_DOUBLES * feature)
    {
        feature->DoublePrecisionFloatShaderOps = DoublePrecisionFloatShaderOperations ? 1 : 0;
    }
};

/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT)</para>
/// </summary>
public value struct FeatureDataFormatSupport 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT.InFormat)</para>
    /// </summary>
    DXGI::Format InFormat;

    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT.OutFormatSupport)</para>
    /// </summary>
    FormatSupport OutFormatSupport;

internal:
    FeatureDataFormatSupport(const D3D11_FEATURE_DATA_FORMAT_SUPPORT & feature)
    {
        InFormat = static_cast<DXGI::Format>(feature.InFormat);
        OutFormatSupport = static_cast<FormatSupport>(feature.OutFormatSupport);
    }

    void CopyTo(D3D11_FEATURE_DATA_FORMAT_SUPPORT * feature)
    {
        feature->InFormat = static_cast<DXGI_FORMAT>(InFormat);
        feature->OutFormatSupport = static_cast<UINT>(OutFormatSupport);
    }
};

/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT)</para>
/// </summary>
public value struct FeatureDataFormatSupport2 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT2.InFormat)</para>
    /// </summary>
    DXGI::Format InFormat;

    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT2.OutFormatSupport2)</para>
    /// </summary>
    FormatSupport2 OutFormatSupport2;
internal:
    FeatureDataFormatSupport2(const D3D11_FEATURE_DATA_FORMAT_SUPPORT2 & feature)
    {
        InFormat = static_cast<DXGI::Format>(feature.InFormat);
        OutFormatSupport2 = static_cast<FormatSupport2>(feature.OutFormatSupport2);
    }

    void CopyTo(D3D11_FEATURE_DATA_FORMAT_SUPPORT2 * feature)
    {
        feature->InFormat = static_cast<DXGI_FORMAT>(InFormat);
        feature->OutFormatSupport2 = static_cast<UINT>(OutFormatSupport2);
    }
};

/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS)</para>
/// </summary>
public value struct FeatureDataD3D10XHardwareOptions 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x)</para>
    /// </summary>
    Boolean ComputeShadersPlusRawAndStructuredBuffersViaShader4x;

internal:
    FeatureDataD3D10XHardwareOptions(const D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS & feature)
    {
        ComputeShadersPlusRawAndStructuredBuffersViaShader4x = feature.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x != 0;
    }

    void CopyTo(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS * feature)
    {
        feature->ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x = ComputeShadersPlusRawAndStructuredBuffersViaShader4x ? 1 : 0;
    }
};

/// <summary>
/// A description of a single element for the input-assembler stage.
/// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC)</para>
/// </summary>
public value struct InputElementDescription 
{
public:
    /// <summary>
    /// The HLSL semantic associated with this element in a shader input-signature.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.SemanticName)</para>
    /// </summary>
    String^ SemanticName;
    /// <summary>
    /// The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic name matrix, however each of the four component would have different semantic indices (0, 1, 2, and 3).
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.SemanticIndex)</para>
    /// </summary>
    UInt32 SemanticIndex;
    /// <summary>
    /// The data type of the element data. See Format.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// An integer value that identifies the input-assembler (see input slot). Valid values are between 0 and 15, defined in D3D11.h.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.InputSlot)</para>
    /// </summary>
    UInt32 InputSlot;
    /// <summary>
    /// Optional. Offset (in bytes) between each element. Use D3D11_APPEND_ALIGNED_ELEMENT for convenience to define the current element directly after the previous one, including any packing if necessary.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.AlignedByteOffset)</para>
    /// </summary>
    UInt32 AlignedByteOffset;
    /// <summary>
    /// Identifies the input data class for a single input slot (see <see cref="InputClassification"/>)<seealso cref="InputClassification"/>.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.InputSlotClass)</para>
    /// </summary>
    InputClassification InputSlotClass;
    /// <summary>
    /// The number of instances to draw using the same per-instance data before advancing in the buffer by one element. This value must be 0 for an element that contains per-vertex data (the slot class is set to PerVertexData).
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.InstanceDataStepRate)</para>
    /// </summary>
    UInt32 InstanceDataStepRate;

internal:
    InputElementDescription(const D3D11_INPUT_ELEMENT_DESC & desc)
    {
        SemanticName = desc.SemanticName ? gcnew String(desc.SemanticName) : nullptr;
        SemanticIndex = desc.SemanticIndex;
        Format = static_cast<DXGI::Format>(desc.Format);
        InputSlot = desc.InputSlot;
        AlignedByteOffset = desc.AlignedByteOffset;
        InputSlotClass = static_cast<InputClassification>(desc.InputSlotClass);
        InstanceDataStepRate = desc.InstanceDataStepRate;
    }

    void CopyTo(D3D11_INPUT_ELEMENT_DESC * desc, marshal_context^ context)
    {
        desc->SemanticIndex = SemanticIndex;
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->InputSlot = InputSlot;
        desc->AlignedByteOffset = AlignedByteOffset;
        desc->InputSlotClass = static_cast<D3D11_INPUT_CLASSIFICATION>(InputSlotClass);
        desc->InstanceDataStepRate = InstanceDataStepRate;

        String^ name = SemanticName;
        desc->SemanticName = SemanticName == nullptr ? NULL : context->marshal_as<const char*>(name);
    }


};
/// <summary>
/// Provides access to subresource data.
/// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE)</para>
/// </summary>
public value struct MappedSubresource 
{
public:
    /// <summary>
    /// Pointer to the data.
    /// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE.pData)</para>
    /// </summary>
    IntPtr Data;
    /// <summary>
    /// The row pitch, or width, or physical size (in bytes) of the data.
    /// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE.RowPitch)</para>
    /// </summary>
    UInt32 RowPitch;
    /// <summary>
    /// The depth pitch, or width, or physical size (in bytes)of the data.
    /// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE.DepthPitch)</para>
    /// </summary>
    UInt32 DepthPitch;

internal:
    MappedSubresource (const D3D11_MAPPED_SUBRESOURCE & subresource)
    {
        Data = IntPtr(subresource.pData);
        RowPitch = subresource.RowPitch;
        DepthPitch = subresource.DepthPitch;
    }

    void CopyTo(D3D11_MAPPED_SUBRESOURCE * subresource)
    {
        subresource->pData = Data.ToPointer();
        subresource->RowPitch = RowPitch;
        subresource->DepthPitch = DepthPitch;
    }

};

/// <summary>
/// A debug message in the Information Queue.
/// <para>(Also see DirectX SDK: D3D11_MESSAGE)</para>
/// </summary>
public value struct Message 
{
public:
    /// <summary>
    /// The category of the message. See MessageCategory.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.Category)</para>
    /// </summary>
    MessageCategory Category;
    /// <summary>
    /// The severity of the message. See MessageSeverity.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.Severity)</para>
    /// </summary>
    MessageSeverity Severity;
    /// <summary>
    /// The ID of the message. See MessageId.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.ID)</para>
    /// </summary>
    MessageId Id;
    /// <summary>
    /// The message string.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.pDescription)</para>
    /// </summary>
    String^ Description;

internal:
    Message (D3D11_MESSAGE* msg)
    {
        if (msg == NULL)
        {
            return;
        }

        Category = static_cast<MessageCategory>(msg->Category);
        Severity = static_cast<MessageSeverity>(msg->Severity);
        Id = static_cast<MessageId>(msg->ID);

        Description = msg->pDescription && msg->DescriptionByteLength  > 0 ? gcnew String(msg->pDescription) : nullptr;       
    }

    void CopyTo(D3D11_MESSAGE* msg)
    {
    }
};
/// <summary>
/// Query information about graphics-pipeline activity in between calls to DeviceContext.Begin and DeviceContext.End.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS)</para>
/// </summary>
public value struct QueryDataPipelineStatistics 
{
public:
    UInt64 InputAssemblerVertices;
    /// <summary>
    /// Number of primitives read by the input assembler. This number can be different depending on the primitive topology used. For example, a triangle strip with 6 vertices will produce 4 triangles, however a triangle list with 6 vertices will produce 2 triangles.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.IAPrimitives)</para>
    /// </summary>
    UInt64 InputAssemblerPrimitives;
    /// <summary>
    /// Number of times a vertex shader was invoked. Direct3D invokes the vertex shader once per vertex.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.VSInvocations)</para>
    /// </summary>
    UInt64 VertexShaderInvocations;
    /// <summary>
    /// Number of times a geometry shader was invoked. When the geometry shader is set to NULL, this statistic may or may not increment depending on the hardware manufacturer.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.GSInvocations)</para>
    /// </summary>
    UInt64 GeometryShaderInvocations;
    /// <summary>
    /// Number of primitives output by a geometry shader.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.GSPrimitives)</para>
    /// </summary>
    UInt64 GeometryShaderPrimitives;
    /// <summary>
    /// Number of primitives that were sent to the rasterizer. When the rasterizer is disabled, this will not increment.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.CInvocations)</para>
    /// </summary>
    UInt64 CInvocations;
    /// <summary>
    /// Number of primitives that were rendered. This may be larger or smaller than CInvocations because after a primitive is clipped sometimes it is either broken up into more than one primitive or completely culled.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.CPrimitives)</para>
    /// </summary>
    UInt64 CPrimitives;
    /// <summary>
    /// Number of times a pixel shader was invoked.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.PSInvocations)</para>
    /// </summary>
    UInt64 PixelShaderInvocations;
    /// <summary>
    /// Number of times a hull shader was invoked.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.HSInvocations)</para>
    /// </summary>
    UInt64 HullShaderInvocations;
    /// <summary>
    /// Number of times a domain shader was invoked.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.DSInvocations)</para>
    /// </summary>
    UInt64 DomainShaderInvocations;
};
/// <summary>
/// Query information about the amount of data streamed out to the stream-output buffers in between DeviceContext.Begin and DeviceContext.End.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_SO_STATISTICS)</para>
/// </summary>
public value struct QueryDataStreamOuputStatistics 
{
public:
    /// <summary>
    /// Number of primitives (that is, points, lines, and triangles) written to the stream-output buffers.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_SO_STATISTICS.NumPrimitivesWritten)</para>
    /// </summary>
    UInt64 NumPrimitivesWritten;
    /// <summary>
    /// Number of primitives that would have been written to the stream-output buffers if there had been enough space for them all.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_SO_STATISTICS.PrimitivesStorageNeeded)</para>
    /// </summary>
    UInt64 PrimitivesStorageNeeded;
};
/// <summary>
/// Query information about the reliability of a timestamp query.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_TIMESTAMP_DISJOINT)</para>
/// </summary>
public value struct QueryDataTimestampDisjoint 
{
public:
    /// <summary>
    /// How frequently the GPU counter increments in Hz.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_TIMESTAMP_DISJOINT.Frequency)</para>
    /// </summary>
    UInt64 Frequency;
    /// <summary>
    /// If this is TRUE, something occurred in between the query's DeviceContext.Begin and DeviceContext.End calls that caused the timestamp counter to become discontinuous or disjoint, such as unplugging the AC chord on a laptop, overheating, or throttling up/down due to laptop savings events. The timestamp returned by DeviceContext.GetData for a timestamp query is only reliable if Disjoint is FALSE.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_TIMESTAMP_DISJOINT.Disjoint)</para>
    /// </summary>
    Boolean Disjoint;
};
/// <summary>
/// Describes a query.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DESC)</para>
/// </summary>
public value struct QueryDescription 
{
public:
    /// <summary>
    /// Type of query.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DESC.D3DQuery)</para>
    /// </summary>
    D3D11::Query Query;
    /// <summary>
    /// Miscellaneous flags (see <see cref="QueryMiscFlag"/>)<seealso cref="QueryMiscFlag"/>.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DESC.MiscFlags)</para>
    /// </summary>
    QueryMiscFlag MiscFlags;
internal:
    QueryDescription (const D3D11_QUERY_DESC& desc)
    {
        Query = static_cast<D3D11::Query>(desc.Query);
        MiscFlags = static_cast<D3D11::QueryMiscFlag>(desc.MiscFlags);
    }

    void CopyTo(D3D11_QUERY_DESC* desc)
    {
        desc->Query = static_cast<D3D11_QUERY>(Query);
        desc->MiscFlags = static_cast<UINT>(MiscFlags);
    }

};
/// <summary>
/// Describes rasterizer state.
/// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC)</para>
/// </summary>
public value struct RasterizerDescription 
{
public:
    /// <summary>
    /// Determines the fill mode to use when rendering (see <see cref="FillMode"/>)<seealso cref="FillMode"/>.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.FillMode)</para>
    /// </summary>
    D3D11::FillMode FillMode;
    /// <summary>
    /// Indicates triangles facing the specified direction are not drawn (see <see cref="CullMode"/>)<seealso cref="CullMode"/>.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.CullMode)</para>
    /// </summary>
    D3D11::CullMode CullMode;
    /// <summary>
    /// Determines if a triangle is front- or back-facing. If this parameter is true, then a triangle will be considered front-facing if its vertices are counter-clockwise on the render target and considered back-facing if they are clockwise. If this parameter is false then the opposite is true.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.FrontCounterClockwise)</para>
    /// </summary>
    Boolean FrontCounterClockwise;
    /// <summary>
    /// Depth value added to a given pixel.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.DepthBias)</para>
    /// </summary>
    Int32 DepthBias;
    /// <summary>
    /// Maximum depth bias of a pixel.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.DepthBiasClamp)</para>
    /// </summary>
    Single DepthBiasClamp;
    /// <summary>
    /// Scalar on a given pixel's slope.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.SlopeScaledDepthBias)</para>
    /// </summary>
    Single SlopeScaledDepthBias;
    /// <summary>
    /// Enable clipping based on distance.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.DepthClipEnable)</para>
    /// </summary>
    Boolean DepthClipEnable;
    /// <summary>
    /// Enable scissor-rectangle culling. All pixels ouside an active scissor rectangle are culled.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.ScissorEnable)</para>
    /// </summary>
    Boolean ScissorEnable;
    /// <summary>
    /// Enable multisample antialiasing.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.MultisampleEnable)</para>
    /// </summary>
    Boolean MultisampleEnable;
    /// <summary>
    /// Enable line antialiasing; only applies if doing line drawing and MultisampleEnable is false.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.AntialiasedLineEnable)</para>
    /// </summary>
    Boolean AntialiasedLineEnable;

internal:
    RasterizerDescription(const D3D11_RASTERIZER_DESC& desc)
    {
        FillMode = static_cast<D3D11::FillMode>(desc.FillMode);
        CullMode = static_cast<D3D11::CullMode>(desc.CullMode);
        FrontCounterClockwise = desc.FrontCounterClockwise != 0;
        DepthBias = desc.DepthBias;
        DepthBiasClamp = desc.DepthBiasClamp;
        SlopeScaledDepthBias = desc.SlopeScaledDepthBias;
        DepthClipEnable = desc.DepthClipEnable != 0;
        ScissorEnable = desc.ScissorEnable != 0;
        MultisampleEnable = desc.MultisampleEnable != 0;
        AntialiasedLineEnable = desc.AntialiasedLineEnable != 0;
    }

    void CopyTo(D3D11_RASTERIZER_DESC* desc)
    {
        desc->FillMode = static_cast<D3D11_FILL_MODE>(FillMode) ;
        desc->CullMode = static_cast<D3D11_CULL_MODE>(CullMode) ;

        desc->FrontCounterClockwise = FrontCounterClockwise ? 1 : 0;
        desc->DepthBias = DepthBias;
        desc->DepthBiasClamp = DepthBiasClamp;
        desc->SlopeScaledDepthBias = SlopeScaledDepthBias;

        desc->DepthClipEnable = DepthClipEnable? 1 : 0;
        desc->ScissorEnable = ScissorEnable? 1 : 0;
        desc->MultisampleEnable = MultisampleEnable? 1 : 0;
        desc->AntialiasedLineEnable = AntialiasedLineEnable? 1 : 0;
    }
};

/// <summary>
/// Specifies the subresources from a resource that are accessible using a render-target view.
/// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct RenderTargetViewDescription 
{
public:
    /// <summary>
    /// The data format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// The resource type (see <see cref="RenderTargetViewDimension"/>)<seealso cref="RenderTargetViewDimension"/>, which specifies how the render-target resource will be accessed.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    RenderTargetViewDimension ViewDimension;
    /// <summary>
    /// Specifies which buffer elements can be accessed (see <see cref="BufferRenderTargetView"/>)<seealso cref="BufferRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Buffer)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferRenderTargetView Buffer;
    /// <summary>
    /// Specifies the subresources in a 1D texture that can be accessed (see <see cref="Texture1DRenderTargetView"/>)<seealso cref="Texture1DRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DRenderTargetView Texture1D;
    /// <summary>
    /// Specifies the subresources in a 1D texture array that can be accessed (see <see cref="Texture1DArrayRenderTargetView"/>)<seealso cref="Texture1DArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayRenderTargetView Texture1DArray;
    /// <summary>
    /// Specifies the subresources in a 2D texture that can be accessed (see <see cref="Texture2DRenderTargetView"/>)<seealso cref="Texture2DRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DRenderTargetView Texture2D;
    /// <summary>
    /// Specifies the subresources in a 2D texture array that can be accessed (see <see cref="Texture2DArrayRenderTargetView"/>)<seealso cref="Texture2DArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayRenderTargetView Texture2DArray;
    /// <summary>
    /// Specifies a single subresource because a multisampled 2D texture only contains one subresource (see <see cref="Texture2DMultiSampleRenderTargetView"/>)<seealso cref="Texture2DMultiSampleRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2DMS)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleRenderTargetView Texture2DMultiSample;
    /// <summary>
    /// Specifies the subresources in a multisampled 2D texture array that can be accessed (see <see cref="Texture2DMultiSampleArrayRenderTargetView"/>)<seealso cref="Texture2DMultiSampleArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleArrayRenderTargetView Texture2DMultiSampleArray;
    /// <summary>
    /// Specifies subresources in a 3D texture that can be accessed (see <see cref="Texture3DRenderTargetView"/>)<seealso cref="Texture3DRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture3D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture3DRenderTargetView Texture3D;
};
/// <summary>
/// Describes a sampler state.
/// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC)</para>
/// </summary>
public value struct SamplerDescription 
{
public:
    /// <summary>
    /// Filtering method to use when sampling a texture (see <see cref="Filter"/>)<seealso cref="Filter"/>.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.Filter)</para>
    /// </summary>
    D3D11::Filter Filter;
    /// <summary>
    /// Method to use for resolving a u texture coordinate that is outside the 0 to 1 range (see <see cref="TextureAddressMode"/>)<seealso cref="TextureAddressMode"/>.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.AddressU)</para>
    /// </summary>
    TextureAddressMode AddressU;
    /// <summary>
    /// Method to use for resolving a v texture coordinate that is outside the 0 to 1 range.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.AddressV)</para>
    /// </summary>
    TextureAddressMode AddressV;
    /// <summary>
    /// Method to use for resolving a w texture coordinate that is outside the 0 to 1 range.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.AddressW)</para>
    /// </summary>
    TextureAddressMode AddressW;
    /// <summary>
    /// offset from the calculated mipmap level. For example, if Direct3D calculates that a texture should be sampled at mipmap level 3 and MipLODBias is 2, then the texture will be sampled at mipmap level 5.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MipLODBias)</para>
    /// </summary>
    Single MipLODBias;
    /// <summary>
    /// Clamping value used if Anisotropic or ComparisonAnisotropic is specified in Filter. Valid values are between 1 and 16.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MaxAnisotropy)</para>
    /// </summary>
    UInt32 MaxAnisotropy;
    /// <summary>
    /// A function that compares sampled data against existing sampled data. The function options are listed in ComparisonFunction.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.ComparisonFunction)</para>
    /// </summary>
    D3D11::ComparisonFunction ComparisonFunction;
    /// <summary>
    /// Border color to use if Border is specified for AddressU, AddressV, or AddressW. Range must be between 0.0 and 1.0 inclusive.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.BorderColor)</para>
    /// </summary>
    ColorRgba BorderColor;

    /// <summary>
    /// Lower end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MinLOD)</para>
    /// </summary>
    Single MinLOD;
    /// <summary>
    /// Upper end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed. This value must be greater than or equal to MinLOD. To have no upper limit on LOD set this to a large value such as D3D11_FLOAT32_MAX.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MaxLOD)</para>
    /// </summary>
    Single MaxLOD;

internal:
    SamplerDescription(const D3D11_SAMPLER_DESC & desc)
    {
        Filter = static_cast<D3D11::Filter>(desc.Filter);
        AddressU = static_cast<TextureAddressMode>(desc.AddressU);
        AddressV = static_cast<TextureAddressMode>(desc.AddressV);
        AddressW = static_cast<TextureAddressMode>(desc.AddressW);
        
        MipLODBias = desc.MipLODBias;
        MaxAnisotropy = desc.MaxAnisotropy;

        ComparisonFunction = static_cast<D3D11::ComparisonFunction>(desc.ComparisonFunc);

        BorderColor = ColorRgba(desc.BorderColor);

        MinLOD = desc.MinLOD;
        MaxLOD = desc.MaxLOD;
    }

    void CopyTo(D3D11_SAMPLER_DESC* desc)
    {
        desc->Filter = static_cast<D3D11_FILTER>(Filter);
        desc->AddressU = static_cast<D3D11_TEXTURE_ADDRESS_MODE>(AddressU);
        desc->AddressV = static_cast<D3D11_TEXTURE_ADDRESS_MODE>(AddressV);
        desc->AddressW = static_cast<D3D11_TEXTURE_ADDRESS_MODE>(AddressW);
        
        desc->MipLODBias = MipLODBias;
        desc->MaxAnisotropy = MaxAnisotropy;

        desc->ComparisonFunc= static_cast<D3D11_COMPARISON_FUNC>(ComparisonFunction);

        desc->BorderColor[0] = BorderColor.Red;
        desc->BorderColor[1] = BorderColor.Green;
        desc->BorderColor[2] = BorderColor.Blue;
        desc->BorderColor[3] = BorderColor.Alpha;


        desc->MinLOD = MinLOD;
        desc->MaxLOD = MaxLOD;
    }
};
/// <summary>
/// Describes a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct ShaderResourceViewDescription 
{
public:
    /// <summary>
    /// A Format specifying the viewing format.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// The resource type of the view. See ShaderResourceViewDimension. This should be the same as the resource type of the underlying resource. This parameter also determines which _SRV to use in the union below.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    ShaderResourceViewDimension ViewDimension;
    /// <summary>
    /// View the resource as a buffer using information from a shader-resource view (see <see cref="BufferShaderResourceView"/>)<seealso cref="BufferShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Buffer)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferShaderResourceView Buffer;
    /// <summary>
    /// View the resource as a 1D texture using information from a shader-resource view (see <see cref="Texture1DShaderResourceView"/>)<seealso cref="Texture1DShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DShaderResourceView Texture1D;
    /// <summary>
    /// View the resource as a 1D-texture array using information from a shader-resource view (see <see cref="Texture1DArrayShaderResourceView"/>)<seealso cref="Texture1DArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayShaderResourceView Texture1DArray;
    /// <summary>
    /// View the resource as a 2D-texture using information from a shader-resource view (see <see cref="Texture2DShaderResourceView"/>)<seealso cref="Texture2DShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DShaderResourceView Texture2D;
    /// <summary>
    /// View the resource as a 2D-texture array using information from a shader-resource view (see <see cref="Texture2DArrayShaderResourceView"/>)<seealso cref="Texture2DArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayShaderResourceView Texture2DArray;
    /// <summary>
    /// View the resource as a 2D-multisampled texture using information from a shader-resource view (see <see cref="Texture2DMultiSampleShaderResourceView"/>)<seealso cref="Texture2DMultiSampleShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2DMultiSample)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleShaderResourceView Texture2DMultiSample;
    /// <summary>
    /// View the resource as a 2D-multisampled-texture array using information from a shader-resource view (see <see cref="Texture2DMultiSampleArrayShaderResourceView"/>)<seealso cref="Texture2DMultiSampleArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleArrayShaderResourceView Texture2DMultiSampleArray;
    /// <summary>
    /// View the resource as a 3D texture using information from a shader-resource view (see <see cref="Texture3DShaderResourceView"/>)<seealso cref="Texture3DShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture3D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture3DShaderResourceView Texture3D;
    /// <summary>
    /// View the resource as a 3D-cube texture using information from a shader-resource view (see <see cref="TextureCubeShaderResourceView"/>)<seealso cref="TextureCubeShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.TextureCube)</para>
    /// </summary>
    [FieldOffset(8)]
    TextureCubeShaderResourceView TextureCube;
    /// <summary>
    /// View the resource as a 3D-cube-texture array using information from a shader-resource view (see <see cref="TextureCubeArrayShaderResourceView"/>)<seealso cref="TextureCubeArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.TextureCubeArray)</para>
    /// </summary>
    [FieldOffset(8)]
    TextureCubeArrayShaderResourceView TextureCubeArray;
    /// <summary>
    /// View the resource as an extended buffer using information from a shader-resource view (see <see cref="BufferExShaderResourceView"/>)<seealso cref="BufferExShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.BufferEx)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferExShaderResourceView BufferEx;

internal:
    ShaderResourceViewDescription(const D3D11_SHADER_RESOURCE_VIEW_DESC& desc)
    {
        Format = static_cast<DXGI::Format>(desc.Format);
        ViewDimension = static_cast<ShaderResourceViewDimension>(desc.ViewDimension);

        switch (ViewDimension)
        {
        case ShaderResourceViewDimension::Buffer :
               {
                   Buffer.ElementOffset = desc.Buffer.ElementOffset;
                   Buffer.ElementWidth = desc.Buffer.ElementWidth;
                   break;
               }
        case ShaderResourceViewDimension::Texture1D :
              {
                  Texture1D.MipLevels = desc.Texture1D.MipLevels;
                  Texture1D.MostDetailedMip = desc.Texture1D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture1DArray :
              {
                  Texture1DArray.ArraySize = desc.Texture1DArray.ArraySize;
                  Texture1DArray.FirstArraySlice = desc.Texture1DArray.FirstArraySlice;
                  Texture1DArray.MipLevels = desc.Texture1DArray.MipLevels;
                  Texture1DArray.MostDetailedMip = desc.Texture1DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture2D :
              {
                  Texture2D.MipLevels = desc.Texture2D.MipLevels;
                  Texture2D.MostDetailedMip = desc.Texture2D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DArray :
              {
                  Texture2DArray.ArraySize = desc.Texture2DArray.ArraySize;
                  Texture2DArray.FirstArraySlice = desc.Texture2DArray.FirstArraySlice;
                  Texture2DArray.MipLevels = desc.Texture2DArray.MipLevels;
                  Texture2DArray.MostDetailedMip = desc.Texture2DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DMultiSample :
              {
                  Texture2DMultiSample.UnusedField = desc.Texture2DMS.UnusedField_NothingToDefine;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DMultiSampleArray :
              {
                  Texture2DMultiSampleArray.ArraySize = desc.Texture2DMSArray.ArraySize;
                  Texture2DMultiSampleArray.FirstArraySlice = desc.Texture2DMSArray.FirstArraySlice;
                  break;
              }
        case ShaderResourceViewDimension::Texture3D :
              {
                  Texture3D.MipLevels = desc.Texture3D.MipLevels;
                  Texture3D.MostDetailedMip = desc.Texture3D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::TextureCube :
              {
                  TextureCube.MipLevels = desc.TextureCube.MipLevels;
                  TextureCube.MostDetailedMip = desc.TextureCube.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::TextureCubeArray :
              {
                  TextureCubeArray.MostDetailedMip = desc.TextureCubeArray.MostDetailedMip;
                  TextureCubeArray.MipLevels = desc.TextureCubeArray.MipLevels;
                  TextureCubeArray.First2DArrayFace = desc.TextureCubeArray.First2DArrayFace;
                  TextureCubeArray.NumCubes = desc.TextureCubeArray.NumCubes;
                  break;
              }
        case ShaderResourceViewDimension::BufferEx :
              {
                  BufferEx.FirstElement = desc.BufferEx.FirstElement;
                  BufferEx.NumElements = desc.BufferEx.NumElements;
                  BufferEx.Flags = static_cast<BufferExShaderResourceViewFlag>(desc.BufferEx.Flags);
                  break;
              }
        default :
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }

    void CopyTo(D3D11_SHADER_RESOURCE_VIEW_DESC* desc)
    {
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->ViewDimension = static_cast<D3D11_SRV_DIMENSION>(ViewDimension);

        switch (ViewDimension)
        {
        case ShaderResourceViewDimension::Buffer :
               {
                   desc->Buffer.ElementOffset = Buffer.ElementOffset;
                   desc->Buffer.ElementWidth = Buffer.ElementWidth;
                   break;
               }
        case ShaderResourceViewDimension::Texture1D :
              {
                  desc->Texture1D.MipLevels = Texture1D.MipLevels;
                  desc->Texture1D.MostDetailedMip = Texture1D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture1DArray :
              {
                  desc->Texture1DArray.ArraySize = Texture1DArray.ArraySize;
                  desc->Texture1DArray.FirstArraySlice = Texture1DArray.FirstArraySlice;
                  desc->Texture1DArray.MipLevels = Texture1DArray.MipLevels;
                  desc->Texture1DArray.MostDetailedMip = Texture1DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture2D :
              {
                  desc->Texture2D.MipLevels = Texture2D.MipLevels;
                  desc->Texture2D.MostDetailedMip = Texture2D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DArray :
              {
                  desc->Texture2DArray.ArraySize = Texture2DArray.ArraySize;
                  desc->Texture2DArray.FirstArraySlice = Texture2DArray.FirstArraySlice;
                  desc->Texture2DArray.MipLevels = Texture2DArray.MipLevels;
                  desc->Texture2DArray.MostDetailedMip = Texture2DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DMultiSample :
              {
                  desc->Texture2DMS.UnusedField_NothingToDefine = Texture2DMultiSample.UnusedField;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DMultiSampleArray :
              {
                  desc->Texture2DMSArray.ArraySize = Texture2DMultiSampleArray.ArraySize;
                  desc->Texture2DMSArray.FirstArraySlice = Texture2DMultiSampleArray.FirstArraySlice;
                  break;
              }
        case ShaderResourceViewDimension::Texture3D :
              {
                  desc->Texture3D.MipLevels = Texture3D.MipLevels;
                  desc->Texture3D.MostDetailedMip = Texture3D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::TextureCube :
              {
                  desc->TextureCube.MipLevels = TextureCube.MipLevels;
                  desc->TextureCube.MostDetailedMip = TextureCube.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension::TextureCubeArray :
              {
                  desc->TextureCubeArray.MostDetailedMip = TextureCubeArray.MostDetailedMip;
                  desc->TextureCubeArray.MipLevels = TextureCubeArray.MipLevels;
                  desc->TextureCubeArray.First2DArrayFace = TextureCubeArray.First2DArrayFace;
                  desc->TextureCubeArray.NumCubes = TextureCubeArray.NumCubes;
                  break;
              }
        case ShaderResourceViewDimension::BufferEx :
              {
                  desc->BufferEx.FirstElement = BufferEx.FirstElement;
                  desc->BufferEx.NumElements = BufferEx.NumElements;
                  desc->BufferEx.Flags = static_cast<D3D11_BUFFEREX_SRV_FLAG>(BufferEx.Flags);
                  break;
              }
        default:
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }



};
/// <summary>
/// Description of a vertex element in a vertex buffer in an output slot.
/// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY)</para>
/// </summary>
public value struct StreamOutputDeclarationEntry 
{
public:
    /// <summary>
    /// Zero-based, stream index.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.Stream)</para>
    /// </summary>
    UInt32 StreamIndex;
    /// <summary>
    /// Type of output element; possible values include: "POSITION", "NORMAL", or "TEXCOORD0".
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.SemanticName)</para>
    /// </summary>
    String^ SemanticName;
    /// <summary>
    /// Output element's zero-based index. Should be used if, for example, you have more than one texture coordinate stored in each vertex.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.SemanticIndex)</para>
    /// </summary>
    UInt32 SemanticIndex;
    /// <summary>
    /// Which component of the entry to begin writing out to. Valid values are 0 ~ 3. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.StartComponent)</para>
    /// </summary>
    Byte StartComponent;
    /// <summary>
    /// The number of components of the entry to write out to. Valid values are 1 ~ 4. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.ComponentCount)</para>
    /// </summary>
    Byte ComponentCount;
    /// <summary>
    /// The output slot that contains the vertex buffer that contains this output entry.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.OutputSlot)</para>
    /// </summary>
    Byte OutputSlot;
internal:
    StreamOutputDeclarationEntry(const D3D11_SO_DECLARATION_ENTRY& entry)
    {
        StreamIndex = entry.Stream;
        SemanticIndex = entry.SemanticIndex;
        StartComponent = entry.StartComponent;
        ComponentCount = entry.ComponentCount;
        OutputSlot = entry.OutputSlot;
        SemanticName = gcnew String(entry.SemanticName);
    }

    void CopyTo(D3D11_SO_DECLARATION_ENTRY* entry, marshal_context^ context)
    {
        entry->Stream = StreamIndex;
        entry->SemanticIndex = SemanticIndex;
        entry->StartComponent = StartComponent;
        entry->ComponentCount = ComponentCount;
        entry->OutputSlot = OutputSlot;
        
        String^ name = SemanticName;
        entry->SemanticName = context->marshal_as<const char*>(name);
    }
};
/// <summary>
/// Specifies data for initializing a subresource.
/// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA)</para>
/// </summary>
public value struct SubresourceData 
{
public:
    /// <summary>
    /// Pointer to the initialization data.
    /// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA.pSysMem)</para>
    /// </summary>
    IntPtr SysMem;

    /// <summary>
    /// Pitch of the memory (in bytes). System-memory pitch is used only for 2D and 3D texture data as it is has no meaning for the other resource types.
    /// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA.SysMemPitch)</para>
    /// </summary>
    UInt32 SysMemPitch;

    /// <summary>
    /// Size of one depth level (in bytes). System-memory-slice pitch is only used for 3D texture data as it has no meaning for the other resource types.
    /// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA.SysMemSlicePitch)</para>
    /// </summary>
    UInt32 SysMemSlicePitch;
internal:
    SubresourceData(const D3D11_SUBRESOURCE_DATA & subresourceData)
    {
        SysMem = IntPtr((void*)subresourceData.pSysMem);
        SysMemPitch = subresourceData.SysMemPitch;
        SysMemSlicePitch = subresourceData.SysMemSlicePitch;
    }
    void CopyTo(D3D11_SUBRESOURCE_DATA* subresourceData)
    {
        subresourceData->pSysMem = SysMem.ToPointer();
        subresourceData->SysMemPitch = SysMemPitch;
        subresourceData->SysMemSlicePitch = SysMemSlicePitch;
    }
};





/// <summary>
/// Specifies the subresources from a resource that are accessible using an unordered-access view.
/// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct UnorderedAccessViewDescription 
{
public:
    /// <summary>
    /// The data format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// The resource type (see <see cref="UnorderedAccessViewDimension"/>)<seealso cref="UnorderedAccessViewDimension"/>, which specifies how the resource will be accessed.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    UnorderedAccessViewDimension ViewDimension;
    /// <summary>
    /// Specifies which buffer elements can be accessed (see <see cref="BufferUnorderedAccessView"/>)<seealso cref="BufferUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Buffer)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferUnorderedAccessView Buffer;
    /// <summary>
    /// Specifies the subresources in a 1D texture that can be accessed (see <see cref="Texture1DUnorderedAccessView"/>)<seealso cref="Texture1DUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DUnorderedAccessView Texture1D;
    /// <summary>
    /// Specifies the subresources in a 1D texture array that can be accessed (see <see cref="Texture1DArrayUnorderedAccessView"/>)<seealso cref="Texture1DArrayUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayUnorderedAccessView Texture1DArray;
    /// <summary>
    /// Specifies the subresources in a 2D texture that can be accessed (see <see cref="Texture2DUnorderedAccessView"/>)<seealso cref="Texture2DUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DUnorderedAccessView Texture2D;
    /// <summary>
    /// Specifies the subresources in a 2D texture array that can be accessed (see <see cref="Texture2DArrayUnorderedAccessView"/>)<seealso cref="Texture2DArrayUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayUnorderedAccessView Texture2DArray;
    /// <summary>
    /// Specifies subresources in a 3D texture that can be accessed (see <see cref="Texture3DUnorderedAccessView"/>)<seealso cref="Texture3DUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture3D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture3DUnorderedAccessView Texture3D;
internal:
    UnorderedAccessViewDescription(const D3D11_UNORDERED_ACCESS_VIEW_DESC& desc)
    {
        Format = static_cast<DXGI::Format>(desc.Format);
        ViewDimension = static_cast<UnorderedAccessViewDimension>(desc.ViewDimension);

        switch (ViewDimension)
        {
        case UnorderedAccessViewDimension::Buffer :
               {
                   Buffer.FirstElement = desc.Buffer.FirstElement;
                   Buffer.NumElements = desc.Buffer.NumElements;
                   Buffer.Flags = static_cast<BufferUnorderedAccessViewFlag>(desc.Buffer.Flags);
                   break;
               }
        case UnorderedAccessViewDimension::Texture1D :
              {
                  Texture1D.MipSlice = desc.Texture1D.MipSlice;
                  break;
              }
        case ShaderResourceViewDimension::Texture1DArray :
              {
                  Texture1DArray.MipSlice = desc.Texture1DArray.MipSlice;
                  Texture1DArray.FirstArraySlice = desc.Texture1DArray.FirstArraySlice;
                  Texture1DArray.ArraySize = desc.Texture1DArray.ArraySize;
                  break;
              }
        case ShaderResourceViewDimension::Texture2D :
              {
                  Texture2D.MipSlice = desc.Texture2D.MipSlice;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DArray :
              {
                  Texture2DArray.MipSlice = desc.Texture2DArray.MipSlice;
                  Texture2DArray.FirstArraySlice = desc.Texture2DArray.FirstArraySlice;
                  Texture2DArray.ArraySize = desc.Texture2DArray.ArraySize;
                  break;
              }
        case UnorderedAccessViewDimension::Texture3D :
              {
                  Texture3D.MipSlice = desc.Texture3D.MipSlice;
                  Texture3D.FirstWSlice = desc.Texture3D.FirstWSlice;
                  Texture3D.WSize = desc.Texture3D.WSize;
                  break;
              }
        default :
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }

    void CopyTo(D3D11_UNORDERED_ACCESS_VIEW_DESC* desc)
    {
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->ViewDimension = static_cast<D3D11_UAV_DIMENSION>(ViewDimension);

        switch (ViewDimension)
        {
        case UnorderedAccessViewDimension::Buffer :
               {
                   desc->Buffer.FirstElement = Buffer.FirstElement;
                   desc->Buffer.NumElements = Buffer.NumElements;
                   desc->Buffer.Flags = static_cast<UINT>(Buffer.Flags);
                   break;
               }
        case UnorderedAccessViewDimension::Texture1D :
              {
                  desc->Texture1D.MipSlice = Texture1D.MipSlice;
                  break;
              }
        case ShaderResourceViewDimension::Texture1DArray :
              {
                  desc->Texture1DArray.MipSlice = Texture1DArray.MipSlice;
                  desc->Texture1DArray.FirstArraySlice = Texture1DArray.FirstArraySlice;
                  desc->Texture1DArray.ArraySize = Texture1DArray.ArraySize;
                  break;
              }
        case ShaderResourceViewDimension::Texture2D :
              {
                  desc->Texture2D.MipSlice = Texture2D.MipSlice;
                  break;
              }
        case ShaderResourceViewDimension::Texture2DArray :
              {
                  desc->Texture2DArray.MipSlice = Texture2DArray.MipSlice;
                  desc->Texture2DArray.FirstArraySlice = Texture2DArray.FirstArraySlice;
                  desc->Texture2DArray.ArraySize = Texture2DArray.ArraySize;
                  break;
              }
        case UnorderedAccessViewDimension::Texture3D :
              {
                  desc->Texture3D.MipSlice = Texture3D.MipSlice;
                  desc->Texture3D.FirstWSlice = Texture3D.FirstWSlice;
                  desc->Texture3D.WSize = Texture3D.WSize;
                  break;
              }
        default:
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }




};
/// <summary>
/// Defines the dimensions of a viewport.
/// <para>(Also see DirectX SDK: D3D11_VIEWPORT)</para>
/// </summary>
public value struct Viewport 
{
public:
    /// <summary>
    /// X position of the left hand side of the viewport. Ranges between D3D11_VIEWPORT_BOUNDS_MIN and D3D11_VIEWPORT_BOUNDS_MAX.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.TopLeftX)</para>
    /// </summary>
    Single TopLeftX;
    /// <summary>
    /// Y position of the top of the viewport. Ranges between D3D11_VIEWPORT_BOUNDS_MIN and D3D11_VIEWPORT_BOUNDS_MAX.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.TopLeftY)</para>
    /// </summary>
    Single TopLeftY;
    /// <summary>
    /// Width of the viewport.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.Width)</para>
    /// </summary>
    Single Width;
    /// <summary>
    /// Height of the viewport.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.Height)</para>
    /// </summary>
    Single Height;
    /// <summary>
    /// Minimum depth of the viewport. Ranges between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.MinDepth)</para>
    /// </summary>
    Single MinDepth;
    /// <summary>
    /// Maximum depth of the viewport. Ranges between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.MaxDepth)</para>
    /// </summary>
    Single MaxDepth;

internal:
    Viewport(const D3D11_VIEWPORT& viewport)
    {
        TopLeftX = viewport.TopLeftX;
        TopLeftY = viewport.TopLeftY;
        Width = viewport.Width;
        Height = viewport.Height;
        MinDepth = viewport.MinDepth;
        MaxDepth = viewport.MaxDepth;    
    }

    operator const D3D11_VIEWPORT ()
    {
        D3D11_VIEWPORT nativeViewport;

        nativeViewport.TopLeftX = TopLeftX;
        nativeViewport.TopLeftY = TopLeftY;
        nativeViewport.Width = Width;
        nativeViewport.Height = Height;
        nativeViewport.MinDepth = MinDepth;
        nativeViewport.MaxDepth = MaxDepth;

        return nativeViewport;
    }
};
} } } }
