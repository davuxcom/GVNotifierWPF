//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

namespace D3D10 = Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

/// <summary>
/// Describes the blend state.
/// <para>(Also see DirectX SDK: D3D10_BLEND_DESC)</para>
/// </summary>
public value struct BlendDescription 
{
public:
    /// <summary>
    /// Determines whether or not to use alpha-to-coverage as a multisampling technique when setting a pixel to a rendertarget.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.AlphaToCoverageEnable)</para>
    /// </summary>
    Boolean AlphaToCoverageEnable;
    /// <summary>
    /// Enable (or disable) blending. There are eight elements in this array; these correspond to the eight rendertargets that can be set to output-merger stage at one time.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.BlendEnable)</para>
    /// </summary>
    property array<Boolean>^ BlendEnable
    {
        array<Boolean>^ get()
        {
            if (blendEnable == nullptr)
            {
                blendEnable = gcnew array<Boolean>(BlendEnableArrayLength);
            }
            return blendEnable;
        }
    }
    /// <summary>
    /// This blend option specifies the first RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.SrcBlend)</para>
    /// </summary>
    Blend SourceBlend;
    /// <summary>
    /// This blend option specifies the second RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.DestBlend)</para>
    /// </summary>
    Blend DestinationBlend;
    /// <summary>
    /// This blend operation defines how to combine the RGB data sources.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.BlendOp)</para>
    /// </summary>
    D3D10::BlendOperation BlendOperation;
    /// <summary>
    /// This blend option specifies the first alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.SrcBlendAlpha)</para>
    /// </summary>
    Blend SourceBlendAlpha;
    /// <summary>
    /// This blend option specifies the second alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.DestBlendAlpha)</para>
    /// </summary>
    Blend DestinationBlendAlpha;
    /// <summary>
    /// This blend operation defines how to combine the alpha data sources.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.BlendOpAlpha)</para>
    /// </summary>
    D3D10::BlendOperation BlendOperationAlpha;
    /// <summary>
    /// A per-pixel write mask that allows control over which components can be written (see <see cref="ColorWriteEnable"/>)<seealso cref="ColorWriteEnable"/>.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC.RenderTargetWriteMask)</para>
    /// </summary>
    property array<ColorWriteEnable>^ RenderTargetWriteMask
    {
        array<ColorWriteEnable>^ get()
        {
            if (renderTargetWriteMask == nullptr)
            {
                renderTargetWriteMask =
                    gcnew array<ColorWriteEnable>(RenderTargetWriteMaskArrayLength);
                for (int i =0; i < renderTargetWriteMask->Length; i++)
                {
                    renderTargetWriteMask[i] = ColorWriteEnable::All;
                }
            }
            return renderTargetWriteMask;
        }
    }
internal:
    BlendDescription(const D3D10_BLEND_DESC & blendDescription)
    {
        AlphaToCoverageEnable = blendDescription.AlphaToCoverageEnable != 0;
        BlendOperation = static_cast<D3D10::BlendOperation>(blendDescription.BlendOp);
        BlendOperationAlpha = static_cast<D3D10::BlendOperation>(blendDescription.BlendOpAlpha);

        DestinationBlend = static_cast<D3D10::Blend>(blendDescription.DestBlend);
        DestinationBlendAlpha = static_cast<D3D10::Blend>(blendDescription.DestBlendAlpha);

        SourceBlend = static_cast<D3D10::Blend>(blendDescription.SrcBlend);
        SourceBlendAlpha = static_cast<D3D10::Blend>(blendDescription.SrcBlendAlpha);
        
        renderTargetWriteMask = gcnew array<ColorWriteEnable>(RenderTargetWriteMaskArrayLength);
        pin_ptr<ColorWriteEnable> rtMaskPtr = &renderTargetWriteMask[0];
        memcpy(rtMaskPtr, blendDescription.RenderTargetWriteMask, sizeof(BYTE) * RenderTargetWriteMaskArrayLength);
        
        blendEnable = gcnew array<Boolean>(BlendEnableArrayLength);
        pin_ptr<Boolean> blendEnablePtr = &blendEnable[0];
        memcpy(blendEnablePtr, blendDescription.BlendEnable, sizeof(BOOL) * BlendEnableArrayLength);
    }

    void CopyTo(D3D10_BLEND_DESC * blendDescription)
    {
        blendDescription->AlphaToCoverageEnable = AlphaToCoverageEnable ? 1: 0;
        blendDescription->BlendOp = static_cast<D3D10_BLEND_OP>(BlendOperation);
        blendDescription->BlendOpAlpha = static_cast<D3D10_BLEND_OP>(BlendOperationAlpha);

        blendDescription->DestBlend = static_cast<D3D10_BLEND>(DestinationBlend);
        blendDescription->DestBlendAlpha = static_cast<D3D10_BLEND>(DestinationBlendAlpha);

        blendDescription->SrcBlend = static_cast<D3D10_BLEND>(SourceBlend);
        blendDescription->SrcBlendAlpha = static_cast<D3D10_BLEND>(SourceBlendAlpha);
        
        if (renderTargetWriteMask != nullptr)
        {
            pin_ptr<ColorWriteEnable> rtMaskPtr = &renderTargetWriteMask[0];
            memcpy(blendDescription->RenderTargetWriteMask, rtMaskPtr, sizeof(BYTE) * RenderTargetWriteMaskArrayLength);
        } 
        else
        {
            ZeroMemory(blendDescription->RenderTargetWriteMask, sizeof(BYTE) * RenderTargetWriteMaskArrayLength);
        }
        
        if (blendEnable != nullptr)
        {
            pin_ptr<Boolean> blendEnablePtr = &blendEnable[0];
            memcpy(blendDescription->BlendEnable, blendEnablePtr, sizeof(BOOL) * BlendEnableArrayLength);
        }
        else
        {
            ZeroMemory(blendDescription->BlendEnable, sizeof(BOOL) * BlendEnableArrayLength);
        }
    }
private:
    array<ColorWriteEnable>^ renderTargetWriteMask;
    array<Boolean>^ blendEnable;
    literal int RenderTargetWriteMaskArrayLength = 8;
    literal int BlendEnableArrayLength = 8;
};
/// <summary>
/// Describes the blend state for a render target for a Direct3D 10.1 device
/// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1)</para>
/// </summary>
public value struct RenderTargetBlendDescription1 
{
public:
    /// <summary>
    /// Enable (or disable) blending.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.BlendEnable)</para>
    /// </summary>
    Boolean BlendEnable;
    /// <summary>
    /// This blend option specifies the first RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.SrcBlend)</para>
    /// </summary>
    Blend SourceBlend;
    /// <summary>
    /// This blend option specifies the second RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.DestBlend)</para>
    /// </summary>
    Blend DestinationBlend;
    /// <summary>
    /// This blend operation defines how to combine the RGB data sources.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.BlendOp)</para>
    /// </summary>
    D3D10::BlendOperation BlendOperation;
    /// <summary>
    /// This blend option specifies the first alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.SrcBlendAlpha)</para>
    /// </summary>
    Blend SourceBlendAlpha;
    /// <summary>
    /// This blend option specifies the second alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.DestBlendAlpha)</para>
    /// </summary>
    Blend DestinationBlendAlpha;
    /// <summary>
    /// This blend operation defines how to combine the alpha data sources.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.BlendOpAlpha)</para>
    /// </summary>
    D3D10::BlendOperation BlendOperationAlpha;
    /// <summary>
    /// A write mask.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_BLEND_DESC1.RenderTargetWriteMask)</para>
    /// </summary>
    ColorWriteEnable RenderTargetWriteMask;

internal:
    RenderTargetBlendDescription1(const D3D10_RENDER_TARGET_BLEND_DESC1 &renderTargetBlendDescription1)
    {
        BlendEnable = renderTargetBlendDescription1.BlendEnable != 0;

        BlendOperation = static_cast<D3D10::BlendOperation>(renderTargetBlendDescription1.BlendOp);
        BlendOperationAlpha = static_cast<D3D10::BlendOperation>(renderTargetBlendDescription1.BlendOpAlpha);

        DestinationBlend = static_cast<D3D10::Blend>(renderTargetBlendDescription1.DestBlend);
        DestinationBlendAlpha = static_cast<D3D10::Blend>(renderTargetBlendDescription1.DestBlendAlpha);

        SourceBlend = static_cast<D3D10::Blend>(renderTargetBlendDescription1.SrcBlend);
        SourceBlendAlpha = static_cast<D3D10::Blend>(renderTargetBlendDescription1.SrcBlendAlpha);
        
        RenderTargetWriteMask = static_cast<ColorWriteEnable>(renderTargetBlendDescription1.RenderTargetWriteMask);
    }

    void CopyTo(D3D10_RENDER_TARGET_BLEND_DESC1 * renderTargetBlendDescription1)
    {
        renderTargetBlendDescription1->BlendEnable = BlendEnable ? 1 : 0;
        renderTargetBlendDescription1->BlendOp = static_cast<D3D10_BLEND_OP>(BlendOperation);
        renderTargetBlendDescription1->BlendOpAlpha = static_cast<D3D10_BLEND_OP>(BlendOperationAlpha);

        renderTargetBlendDescription1->DestBlend = static_cast<D3D10_BLEND>(DestinationBlend);
        renderTargetBlendDescription1->DestBlendAlpha = static_cast<D3D10_BLEND>(DestinationBlendAlpha);

        renderTargetBlendDescription1->SrcBlend = static_cast<D3D10_BLEND>(SourceBlend);
        renderTargetBlendDescription1->SrcBlendAlpha = static_cast<D3D10_BLEND>(SourceBlendAlpha);

        renderTargetBlendDescription1->RenderTargetWriteMask = static_cast<UINT8>(RenderTargetWriteMask);
    }
};
/// <summary>
/// Describes the blend state for a Direct3D 10.1 device.
/// <para>(Also see DirectX SDK: D3D10_BLEND_DESC1)</para>
/// </summary>
public value struct BlendDescription1 
{
public:
    /// <summary>
    /// Determines whether or not to use the alpha-to-coverage multisampling technique when setting a render-target pixel.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC1.AlphaToCoverageEnable)</para>
    /// </summary>
    property Boolean AlphaToCoverageEnable;
    /// <summary>
    /// Set to TRUE to enable independent blending in simultaneous render targets.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC1.IndependentBlendEnable)</para>
    /// </summary>
    property Boolean IndependentBlendEnable;
    /// <summary>
    /// An array of render-target-blend descriptions (see <see cref="RenderTargetBlendDescription1"/>)<seealso cref="RenderTargetBlendDescription1"/>; these correspond to the eight rendertargets that can be set to the output-merger stage at one time.
    /// <para>(Also see DirectX SDK: D3D10_BLEND_DESC1.RenderTarget)</para>
    /// </summary>
    property array<RenderTargetBlendDescription1>^ RenderTarget
    {
        array<RenderTargetBlendDescription1>^ get()
        {
            if (renderTarget == nullptr)
            {
                renderTarget  = gcnew array<RenderTargetBlendDescription1>(RenderTargetArrayLength);
            }

            return renderTarget;
        }
    }

internal:
    BlendDescription1(const D3D10_BLEND_DESC1& blendDescription1)
    {
        AlphaToCoverageEnable = blendDescription1.AlphaToCoverageEnable != 0;
        IndependentBlendEnable = blendDescription1.IndependentBlendEnable != 0;

        renderTarget = gcnew array<RenderTargetBlendDescription1>(RenderTargetArrayLength);
        pin_ptr<RenderTargetBlendDescription1> renderTargetPtr = &renderTarget[0];

        memcpy(renderTargetPtr, blendDescription1.RenderTarget, sizeof(D3D10_RENDER_TARGET_BLEND_DESC1) * RenderTargetArrayLength);
    }

    void CopyTo(D3D10_BLEND_DESC1* blendDescription1)
    {
        blendDescription1->AlphaToCoverageEnable = AlphaToCoverageEnable ? 1 :0;
        blendDescription1->IndependentBlendEnable = IndependentBlendEnable ? 1 :0;

        if (renderTarget != nullptr)
        {
            pin_ptr<RenderTargetBlendDescription1> renderTargetPtr = &renderTarget[0];
            memcpy(blendDescription1->RenderTarget, renderTargetPtr, sizeof(D3D10_RENDER_TARGET_BLEND_DESC1) * RenderTargetArrayLength);
        }
        else
        {
            ZeroMemory(blendDescription1->RenderTarget, sizeof(D3D10_RENDER_TARGET_BLEND_DESC1) * RenderTargetArrayLength);
        }
    }

private:
    literal int RenderTargetArrayLength = 8;
    array<RenderTargetBlendDescription1>^ renderTarget;
};
/// <summary>
/// Defines a 3D box.
/// <para>(Also see DirectX SDK: D3D10_BOX)</para>
/// </summary>
public value struct Box 
{
public:
    /// <summary>
    /// The x position of the left hand side of the box.
    /// <para>(Also see DirectX SDK: D3D10_BOX.left)</para>
    /// </summary>
    UInt32 Left;
    /// <summary>
    /// The y position of the top of the box.
    /// <para>(Also see DirectX SDK: D3D10_BOX.top)</para>
    /// </summary>
    UInt32 Top;
    /// <summary>
    /// The z position of the front of the box.
    /// <para>(Also see DirectX SDK: D3D10_BOX.front)</para>
    /// </summary>
    UInt32 Front;
    /// <summary>
    /// The x position of the right hand side of the box.
    /// <para>(Also see DirectX SDK: D3D10_BOX.right)</para>
    /// </summary>
    UInt32 Right;
    /// <summary>
    /// The y position of the bottom of the box.
    /// <para>(Also see DirectX SDK: D3D10_BOX.bottom)</para>
    /// </summary>
    UInt32 Bottom;
    /// <summary>
    /// The z position of the back of the box.
    /// <para>(Also see DirectX SDK: D3D10_BOX.back)</para>
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
    Box(const D3D10_BOX& nBox)
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
/// Describes a buffer resource.
/// <para>(Also see DirectX SDK: D3D10_BUFFER_DESC)</para>
/// </summary>
public value struct BufferDescription 
{
public:
    /// <summary>
    /// Size of the buffer in bytes.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_DESC.ByteWidth)</para>
    /// </summary>
    UInt32 ByteWidth;
    /// <summary>
    /// Identify how the buffer is expected to be read from and written to. Frequency of update is a key factor. The most common value is typically Usage_DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_DESC.Usage)</para>
    /// </summary>
    D3D10::Usage Usage;
    /// <summary>
    /// Identify how the buffer will be bound to the pipeline. Applications can logicaly OR flags together (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> to indicate that the buffer can be accessed in different ways.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// CPU access flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> or 0 if no CPU access is necessary. Applications can logicaly OR flags together.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Miscellaneous flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> or 0 if unused. Applications can logically OR flags together.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;

internal:
    BufferDescription(const D3D10_BUFFER_DESC & desc)
    {
        ByteWidth = desc.ByteWidth;
        Usage = static_cast<D3D10::Usage>(desc.Usage);
        BindFlags = static_cast<BindFlag>(desc.BindFlags);
        CpuAccessFlags  = static_cast<CpuAccessFlag>(desc.CPUAccessFlags);
        MiscFlags = static_cast<ResourceMiscFlag>(desc.MiscFlags);
    }

    void CopyTo(D3D10_BUFFER_DESC * pDesc)
    {
        pDesc->ByteWidth = ByteWidth;
        pDesc->Usage = static_cast<D3D10_USAGE>(Usage);
        pDesc->BindFlags = static_cast<UINT>(BindFlags);
        pDesc->CPUAccessFlags  = static_cast<UINT>(CpuAccessFlags);
        pDesc->MiscFlags = static_cast<UINT>(MiscFlags);
    }
};
/// <summary>
/// Specifies the elements from a buffer resource to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_BUFFER_RTV)</para>
/// </summary>
public value struct BufferRenderTargetView 
{
public:
    /// <summary>
    /// The offset (that is, the number of elements) between the beginning of the buffer and the first element that is to be used in the view, starting at 0.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_RTV.ElementOffset)</para>
    /// </summary>
    UInt32 ElementOffset;
    /// <summary>
    /// The number of elements in the view.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_RTV.ElementWidth)</para>
    /// </summary>
    UInt32 ElementWidth;
};
/// <summary>
/// Specifies the elements in a buffer resource to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_BUFFER_SRV)</para>
/// </summary>
public value struct BufferShaderResourceView 
{
public:
    /// <summary>
    /// The offset of the first element in the view to access, relative to element 0.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_SRV.ElementOffset)</para>
    /// </summary>
    UInt32 ElementOffset;
    /// <summary>
    /// The total number of elements in the view.
    /// <para>(Also see DirectX SDK: D3D10_BUFFER_SRV.ElementWidth)</para>
    /// </summary>
    UInt32 ElementWidth;
};
/// <summary>
/// Describes the stencil operations that can be performed based on the results of stencil test.
/// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCILOP_DESC)</para>
/// </summary>
public value struct DepthStencilOperationDescription 
{
public:
    /// <summary>
    /// A member of the StencilOperation enumerated type that describes the stencil operation to perform when stencil testing fails. The default value is StencilOperation_KEEP.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCILOP_DESC.StencilFailOp)</para>
    /// </summary>
    StencilOperation StencilFailOperation;
    /// <summary>
    /// A member of the StencilOperation enumerated type that describes the stencil operation to perform when stencil testing passes and depth testing fails. The default value is StencilOperation_KEEP.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCILOP_DESC.StencilDepthFailOp)</para>
    /// </summary>
    StencilOperation StencilDepthFailOperation;
    /// <summary>
    /// A member of the StencilOperation enumerated type that describes the stencil operation to perform when stencil testing and depth testing both pass. The default value is StencilOperation_KEEP.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCILOP_DESC.StencilPassOp)</para>
    /// </summary>
    StencilOperation StencilPassOperation;
    /// <summary>
    /// A member of the ComparisonFunction enumerated type that describes how stencil data is compared against existing stencil data. The default value is Always.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCILOP_DESC.StencilFunc)</para>
    /// </summary>
    ComparisonFunction StencilFunction;
};

/// <summary>
/// Describes a counter.
/// <para>(Also see DirectX SDK: D3D10_COUNTER_DESC)</para>
/// </summary>
public value struct CounterDescription 
{
public:
    /// <summary>
    /// Type of counter (see <see cref="Counter"/>)<seealso cref="Counter"/>.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_DESC.Counter)</para>
    /// </summary>
    D3D10::Counter Counter;
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_DESC.MiscFlags)</para>
    /// </summary>
    UInt32 MiscFlags;

internal:
    CounterDescription(const D3D10_COUNTER_DESC& desc)
    {
        Counter = static_cast<D3D10::Counter>(desc.Counter);
        MiscFlags = desc.MiscFlags;
    }
    
    void CopyTo(D3D10_COUNTER_DESC* desc)
    {
        desc->Counter = static_cast<D3D10_COUNTER>(Counter);
        desc->MiscFlags = MiscFlags;
    }
};
/// <summary>
/// Information about the video card's performance counter capabilities.
/// <para>(Also see DirectX SDK: D3D10_COUNTER_INFO)</para>
/// </summary>
public value struct CounterInformation 
{
public:
    /// <summary>
    /// Largest device-dependent counter ID that the device supports. If none are supported, this value will be 0. Otherwise it will be greater than or equal to DeviceDependent0. See Counter.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_INFO.LastDeviceDependentCounter)</para>
    /// </summary>
    Counter LastDeviceDependentCounter;
    /// <summary>
    /// Number of counters that can be simultaneously supported.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_INFO.NumSimultaneousCounters)</para>
    /// </summary>
    UInt32 NumSimultaneousCounters;
    /// <summary>
    /// Number of detectable parallel units that the counter is able to discern. Values are 1 ~ 4. Use NumDetectableParallelUnits to interpret the values of the VERTEX_PROCESSING, GEOMETRY_PROCESSING, PIXEL_PROCESSING, and OTHER_GPU_PROCESSING counters. See Asynchronous.GetData for an equation.
    /// <para>(Also see DirectX SDK: D3D10_COUNTER_INFO.NumDetectableParallelUnits)</para>
    /// </summary>
    Byte NumDetectableParallelUnits;

internal:
    CounterInformation(const D3D10_COUNTER_INFO & info)
    {
        LastDeviceDependentCounter = static_cast<Counter>(info.LastDeviceDependentCounter);
        NumSimultaneousCounters = info.NumSimultaneousCounters;
        NumDetectableParallelUnits = info.NumDetectableParallelUnits;
    }
};

/// <summary>
/// Describes depth-stencil state.
/// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC)</para>
/// </summary>
public value struct DepthStencilDescription 
{
public:
    /// <summary>
    /// A Boolean value that enables depth testing.  The default value is TRUE.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.DepthEnable)</para>
    /// </summary>
    Boolean DepthEnable;
    /// <summary>
    /// A member of the DepthWriteMask enumerated type that identifies a portion of the depth-stencil buffer that can be modified by depth data.  The default value is DepthWriteMask_ALL.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.DepthWriteMask)</para>
    /// </summary>
    D3D10::DepthWriteMask DepthWriteMask;
    /// <summary>
    /// A member of the ComparisonFunction enumerated type that defines how depth data is compared against existing depth data.  The default value is Less
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.DepthFunc)</para>
    /// </summary>
    D3D10::ComparisonFunction DepthFunction;
    /// <summary>
    /// A Boolean value that enables stencil testing.  The default value is FALSE.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.StencilEnable)</para>
    /// </summary>
    Boolean StencilEnable;
    /// <summary>
    /// A value that identifies a portion of the depth-stencil buffer for reading stencil data.  The default value is Default.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.StencilReadMask)</para>
    /// </summary>
    D3D10::StencilReadMask StencilReadMask;
    /// <summary>
    /// A value that identifies a portion of the depth-stencil buffer for writing stencil data. The default value is Default.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.StencilWriteMask)</para>
    /// </summary>
    D3D10::StencilWriteMask StencilWriteMask;
    /// <summary>
    /// A DepthStencilOperationDescription structure that identifies how to use the results of the depth test and the stencil test for pixels whose surface normal is facing toward the camera.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.FrontFace)</para>
    /// </summary>
    DepthStencilOperationDescription FrontFace;
    /// <summary>
    /// A DepthStencilOperationDescription structure that identifies how to use the results of the depth test and the stencil test for pixels whose surface normal is facing away from the camera.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_DESC.BackFace)</para>
    /// </summary>
    DepthStencilOperationDescription BackFace;

internal:
    DepthStencilDescription (const D3D10_DEPTH_STENCIL_DESC & desc)
    {
        DepthEnable = desc.DepthEnable != 0;
        DepthWriteMask = static_cast<D3D10::DepthWriteMask>(desc.DepthWriteMask);
        DepthFunction = static_cast<D3D10::ComparisonFunction>(desc.DepthFunc);
        StencilEnable = desc.StencilEnable != 0;
        StencilReadMask = static_cast<D3D10::StencilReadMask>(desc.StencilReadMask);
        StencilWriteMask = static_cast<D3D10::StencilWriteMask>(desc.StencilWriteMask);
        
        FrontFace.StencilFailOperation = static_cast<StencilOperation>(desc.FrontFace.StencilFailOp);
        FrontFace.StencilDepthFailOperation = static_cast<StencilOperation>(desc.FrontFace.StencilDepthFailOp);
        FrontFace.StencilPassOperation = static_cast<StencilOperation>(desc.FrontFace.StencilPassOp);
        FrontFace.StencilFunction = static_cast<ComparisonFunction>(desc.FrontFace.StencilFunc);

        BackFace.StencilFailOperation = static_cast<StencilOperation>(desc.BackFace.StencilFailOp);
        BackFace.StencilDepthFailOperation = static_cast<StencilOperation>(desc.BackFace.StencilDepthFailOp);
        BackFace.StencilPassOperation = static_cast<StencilOperation>(desc.BackFace.StencilPassOp);
        BackFace.StencilFunction = static_cast<ComparisonFunction>(desc.BackFace.StencilFunc);
    }

    void CopyTo (D3D10_DEPTH_STENCIL_DESC * desc)
    {
        desc->DepthEnable = DepthEnable ? 1 : 0;
        desc->DepthWriteMask = static_cast<D3D10_DEPTH_WRITE_MASK>(DepthWriteMask);
        desc->DepthFunc = static_cast<D3D10_COMPARISON_FUNC>(DepthFunction);
        desc->StencilEnable = StencilEnable ? 1 : 0;
        desc->StencilReadMask = static_cast<UINT8>(StencilReadMask);
        desc->StencilWriteMask = static_cast<UINT8>(StencilWriteMask);
        
        desc->FrontFace.StencilFailOp = static_cast<D3D10_STENCIL_OP>(FrontFace.StencilFailOperation);
        desc->FrontFace.StencilDepthFailOp = static_cast<D3D10_STENCIL_OP>(FrontFace.StencilDepthFailOperation);
        desc->FrontFace.StencilPassOp = static_cast<D3D10_STENCIL_OP>(FrontFace.StencilPassOperation );
        desc->FrontFace.StencilFunc = static_cast<D3D10_COMPARISON_FUNC>(FrontFace.StencilFunction);

        desc->BackFace.StencilFailOp = static_cast<D3D10_STENCIL_OP>(BackFace.StencilFailOperation);
        desc->BackFace.StencilDepthFailOp = static_cast<D3D10_STENCIL_OP>(BackFace.StencilDepthFailOperation);
        desc->BackFace.StencilPassOp = static_cast<D3D10_STENCIL_OP>(BackFace.StencilPassOperation );
        desc->BackFace.StencilFunc = static_cast<D3D10_COMPARISON_FUNC>(BackFace.StencilFunction);
    }
};

/// <summary>
/// Specifies the subresource from a 1D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_TEX1D_DSV)</para>
/// </summary>
public value struct Texture1DDepthStencilView
{
public:
    /// <summary>
    /// The index of the first mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 1D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX1D_RTV)</para>
/// </summary>
public value struct Texture1DRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 1D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX1D_SRV)</para>
/// </summary>
public value struct Texture1DShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of mipmap levels to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Specifies the subresource(s) from an array of multisampled 2D textures for a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_DSV)</para>
/// </summary>
public value struct Texture2DMultiSampleArrayDepthStencilView
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from a an array of multisampled 2D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_RTV)</para>
/// </summary>
public value struct Texture2DMultiSampleArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from an array of multisampled 2D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_SRV)</para>
/// </summary>
public value struct Texture2DMultiSampleArrayShaderResourceView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX2DMS_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource from a multisampled 2D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_TEX2DMS_DSV)</para>
/// </summary>
public value struct Texture2DMultiSampleDepthStencilView
{
public:
    /// <summary>
    /// Unused Field;
    /// </summary>
    UInt32 UnusedField;
};
/// <summary>
/// Specifies the subresource from a multisampled 2D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX2DMS_RTV)</para>
/// </summary>
public value struct Texture2DMultiSampleRenderTargetView 
{
public:
    /// <summary>
    /// Unused Field;
    /// </summary>
    UInt32 UnusedField;
};
/// <summary>
/// Specifies the subresource(s) from a multisampled 2D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX2DMS_SRV)</para>
/// </summary>
public value struct Texture2DMultiSampleShaderResourceView 
{
public:
    /// <summary>
    /// Unused Field;
    /// </summary>
    UInt32 UnusedField;
};
/// <summary>
/// Specifies the subresource(s) from an array 2D textures that are accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_DSV)</para>
/// </summary>
public value struct Texture2DArrayDepthStencilView
{
public:
    /// <summary>
    /// The index of the first mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from an array of 2D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_RTV)</para>
/// </summary>
public value struct Texture2DArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures in the array to use in the render target view, starting from FirstArraySlice.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from an array of 2D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_SRV)</para>
/// </summary>
public value struct Texture2DArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of subtextures to access.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource from a 2D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_TEX2D_DSV)</para>
/// </summary>
public value struct Texture2DDepthStencilView
{
public:
    /// <summary>
    /// The index of the first mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 2D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX2D_RTV)</para>
/// </summary>
public value struct Texture2DRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
};
/// <summary>
/// Specifies the subresource from a 2D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX2D_SRV)</para>
/// </summary>
public value struct Texture2DShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of mipmap levels to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX2D_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Specifies the subresource(s) from a 3D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX3D_RTV)</para>
/// </summary>
public value struct Texture3DRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX3D_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;

    /// <summary>
    /// First depth level to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX3D_RTV.FirstWSlice)</para>
    /// </summary>
    UInt32 FirstWSlice;

    /// <summary>
    /// Number of depth levels to use in the render-target view, starting from FirstWSlice. A value of -1 indicates all of the slices along the w axis, starting from FirstWSlice.
    /// <para>(Also see DirectX SDK: D3D10_TEX3D_RTV.WSize)</para>
    /// </summary>
    UInt32 WSize;
};
/// <summary>
/// Specifies the subresource(s) from a 3D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX3D_SRV)</para>
/// </summary>
public value struct Texture3DShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEX3D_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of mipmap levels to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX3D_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Specifies the subresource(s) from an array of 1D textures to use in a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_DSV)</para>
/// </summary>
public value struct Texture1DArrayDepthStencilView
{
public:
    /// <summary>
    /// The index of the first mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_DSV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from an array of 1D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_RTV)</para>
/// </summary>
public value struct Texture1DArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use (see mip slice).
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_RTV.MipSlice)</para>
    /// </summary>
    UInt32 MipSlice;
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from an array of 1D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_SRV)</para>
/// </summary>
public value struct Texture1DArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of subtextures to access.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// The index of the first texture to use in an array of textures (see array slice)
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    UInt32 FirstArraySlice;
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D10_TEX1D_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
};
/// <summary>
/// Specifies the subresource(s) from an array of cube textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEXCUBE_ARRAY_SRV1)</para>
/// </summary>
public value struct TextureCubeArrayShaderResourceView1 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEXCUBE_ARRAY_SRV1.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of mipmap levels to use.
    /// <para>(Also see DirectX SDK: D3D10_TEXCUBE_ARRAY_SRV1.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Index of the first 2D texture to use.
    /// <para>(Also see DirectX SDK: D3D10_TEXCUBE_ARRAY_SRV1.First2DArrayFace)</para>
    /// </summary>
    UInt32 First2DArrayFace;
    /// <summary>
    /// Number of cube textures in the array.
    /// <para>(Also see DirectX SDK: D3D10_TEXCUBE_ARRAY_SRV1.NumCubes)</para>
    /// </summary>
    UInt32 NumCubes;
};
/// <summary>
/// Specifies the subresource from a cube texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_TEXCUBE_SRV)</para>
/// </summary>
public value struct TextureCubeShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D10_TEXCUBE_SRV.MostDetailedMip)</para>
    /// </summary>
    UInt32 MostDetailedMip;
    /// <summary>
    /// Number of mipmap levels to use.
    /// <para>(Also see DirectX SDK: D3D10_TEXCUBE_SRV.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
};
/// <summary>
/// Describes a 1D texture.
/// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC)</para>
/// </summary>
public value struct Texture1DDescription 
{
public:
    /// <summary>
    /// Texture width (in texels).
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// Number of subtextures (also called mipmap levels). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.Usage)</para>
    /// </summary>
    D3D10::Usage Usage;
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE1D_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;
};
/// <summary>
/// Describes a 2D texture.
/// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC)</para>
/// </summary>
public value struct Texture2DDescription 
{
public:
    /// <summary>
    /// Texture width (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// Texture height (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// Number of subtextures (also called mipmap levels). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    /// Number of textures in the texture array.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.ArraySize)</para>
    /// </summary>
    UInt32 ArraySize;
    /// <summary>
    ///  format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// Structure that specifies multisampling parameters for the texture. See SampleDescription.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.SampleDesc)</para>
    /// </summary>
    DXGI::SampleDescription SampleDescription;
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.Usage)</para>
    /// </summary>
    D3D10::Usage Usage;
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE2D_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;

internal:
    Texture2DDescription(const D3D10_TEXTURE2D_DESC & desc)
    {
        Width = desc.Width;
        Height = desc.Height;
        MipLevels = desc.MipLevels;
        ArraySize = desc.ArraySize;
        Format = static_cast<DXGI::Format>(desc.Format);
        SampleDescription.Count = desc.SampleDesc.Count;
        SampleDescription.Quality = desc.SampleDesc.Quality;
        Usage = static_cast<D3D10::Usage>(desc.Usage);
        BindFlags = static_cast<BindFlag>(desc.BindFlags);
        CpuAccessFlags  = static_cast<CpuAccessFlag>(desc.CPUAccessFlags);
        MiscFlags = static_cast<ResourceMiscFlag>(desc.MiscFlags);
    }

    void CopyTo(D3D10_TEXTURE2D_DESC * pDesc)
    {
        pDesc->Width = Width;
        pDesc->Height = Height;
        pDesc->MipLevels = MipLevels;
        pDesc->ArraySize = ArraySize;
        pDesc->Format = static_cast<DXGI_FORMAT>(Format);
        pDesc->SampleDesc.Count = SampleDescription.Count;
        pDesc->SampleDesc.Quality = SampleDescription.Quality;
        pDesc->Usage = static_cast<D3D10_USAGE>(Usage);
        pDesc->BindFlags = static_cast<UINT>(BindFlags);
        pDesc->CPUAccessFlags  = static_cast<UINT>(CpuAccessFlags);
        pDesc->MiscFlags = static_cast<UINT>(MiscFlags);
    }

};
/// <summary>
/// Describes a 3D texture.
/// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC)</para>
/// </summary>
public value struct Texture3DDescription 
{
public:
    /// <summary>
    /// Texture width (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// Texture height (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// Texture depth (in texels)
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.Depth)</para>
    /// </summary>
    UInt32 Depth;
    /// <summary>
    /// Number of subtextures (also called mipmap levels). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.MipLevels)</para>
    /// </summary>
    UInt32 MipLevels;
    /// <summary>
    ///  format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.Usage)</para>
    /// </summary>
    D3D10::Usage Usage;
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.BindFlags)</para>
    /// </summary>
    BindFlag BindFlags;
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.CPUAccessFlags)</para>
    /// </summary>
    CpuAccessFlag CpuAccessFlags;
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D10_TEXTURE3D_DESC.MiscFlags)</para>
    /// </summary>
    ResourceMiscFlag MiscFlags;
};
/// <summary>
/// Specifies the subresource(s) from a texture that are accessible using a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct DepthStencilViewDescription 
{
public:
    /// <summary>
    ///   format (see <see cref="Format"/>)<seealso cref="Format"/>. See remarks for allowable formats.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// Type of resource (see <see cref="DepthStencilViewDimension"/>)<seealso cref="DepthStencilViewDimension"/>. Specifies how a depth-stencil resource will be accessed; the value is stored in the union in this structure.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    DepthStencilViewDimension ViewDimension;
    /// <summary>
    /// Specifies a 1D texture subresource (see <see cref="Texture1DDepthStencilView"/>)<seealso cref="Texture1DDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DDepthStencilView Texture1D;
    /// <summary>
    /// Specifies an array of 1D texture subresources (see <see cref="Texture1DArrayDepthStencilView"/>)<seealso cref="Texture1DArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayDepthStencilView Texture1DArray;
    /// <summary>
    /// Specifies a 2D texture subresource (see <see cref="Texture2DDepthStencilView"/>)<seealso cref="Texture2DDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DDepthStencilView Texture2D;
    /// <summary>
    /// Specifies an array of 2D texture subresources (see <see cref="Texture2DArrayDepthStencilView"/>)<seealso cref="Texture2DArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayDepthStencilView Texture2DArray;
    /// <summary>
    /// Unused -- a multisampled 2D texture contains a single subresource.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Texture2DMultiSample)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleDepthStencilView Texture2DMultiSample;
    /// <summary>
    /// Unused -- a multisampled 2D texture contains a single subresource per texture.
    /// <para>(Also see DirectX SDK: D3D10_DEPTH_STENCIL_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleArrayDepthStencilView Texture2DMultiSampleArray;

internal:
    DepthStencilViewDescription(const D3D10_DEPTH_STENCIL_VIEW_DESC& desc)
    {
        Format = static_cast<DXGI::Format>(desc.Format);
        ViewDimension = static_cast<DepthStencilViewDimension>(desc.ViewDimension);

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

    void CopyTo(D3D10_DEPTH_STENCIL_VIEW_DESC* desc)
    {
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->ViewDimension = static_cast<D3D10_DSV_DIMENSION>(ViewDimension);

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
/// Describes an effect.
/// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC)</para>
/// </summary>
public value struct EffectDescription 
{
public:
    /// <summary>
    /// TRUE if the effect is a child effect; otherwise FALSE.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC.IsChildEffect)</para>
    /// </summary>
    Boolean IsChildEffect;
    /// <summary>
    /// The number of constant buffers.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC.ConstantBuffers)</para>
    /// </summary>
    UInt32 ConstantBuffers;
    /// <summary>
    /// The number of constant buffers shared in an effect pool.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC.SharedConstantBuffers)</para>
    /// </summary>
    UInt32 SharedConstantBuffers;
    /// <summary>
    /// The number of global variables.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC.GlobalVariables)</para>
    /// </summary>
    UInt32 GlobalVariables;
    /// <summary>
    /// The number of global variables shared in an effect pool.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC.SharedGlobalVariables)</para>
    /// </summary>
    UInt32 SharedGlobalVariables;
    /// <summary>
    /// The number of techniques.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_DESC.Techniques)</para>
    /// </summary>
    UInt32 Techniques;
};
/// <summary>
/// Describes an effect shader.
/// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC)</para>
/// </summary>
public value struct EffectShaderDescription 
{
public:
    /// <summary>
    /// Passed into CreateInputLayout. Only valid on a vertex shader or geometry shader. See ID3D10Device_CreateInputLayout.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.pInputSignature)</para>
    /// </summary>
    IntPtr InputSignature;
    /// <summary>
    /// TRUE is the shader is defined inline; otherwise FALSE.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.IsInline)</para>
    /// </summary>
    Boolean IsInline;
    /// <summary>
    /// The compiled shader.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.pBytecode)</para>
    /// </summary>
    IntPtr Bytecode;
    /// <summary>
    /// The length of pBytecode.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.BytecodeLength)</para>
    /// </summary>
    UInt32 BytecodeLength;
    /// <summary>
    /// A string that constains a declaration of the stream output from a geometry shader.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.SODecl)</para>
    /// </summary>
    String^ StreamOutputDeclaration;
    /// <summary>
    /// The number of entries in the input signature.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.NumInputSignatureEntries)</para>
    /// </summary>
    UInt32 NumInputSignatureEntries;
    /// <summary>
    /// The number of entries in the output signature.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_SHADER_DESC.NumOutputSignatureEntries)</para>
    /// </summary>
    UInt32 NumOutputSignatureEntries;

internal:
    EffectShaderDescription(const D3D10_EFFECT_SHADER_DESC & desc)
    {
        StreamOutputDeclaration = desc.SODecl ? gcnew String(desc.SODecl) : nullptr;

        InputSignature = IntPtr((void*)desc.pInputSignature);
        IsInline = desc.IsInline != 0;
        Bytecode = IntPtr((void*)desc.pBytecode);
        NumInputSignatureEntries = desc.NumInputSignatureEntries;
        NumOutputSignatureEntries = desc.NumOutputSignatureEntries;
    }
};
/// <summary>
/// Describes an effect-variable type.
/// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC)</para>
/// </summary>
public value struct EffectTypeDescription 
{
public:
    /// <summary>
    /// A string that contains the variable name.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.TypeName)</para>
    /// </summary>
    String^ TypeName;
    /// <summary>
    /// The variable class (see <see cref="ShaderVariableClass"/>)<seealso cref="ShaderVariableClass"/>.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Class)</para>
    /// </summary>
    ShaderVariableClass Class;
    /// <summary>
    /// The variable type (see <see cref="ShaderVariableType"/>)<seealso cref="ShaderVariableType"/>.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Type)</para>
    /// </summary>
    ShaderVariableType Type;
    /// <summary>
    /// The number of elements if the variable is an array; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Elements)</para>
    /// </summary>
    UInt32 Elements;
    /// <summary>
    /// The number of members if the variable is a structure; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Members)</para>
    /// </summary>
    UInt32 Members;
    /// <summary>
    /// The number of rows if the variable is a matrix; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Rows)</para>
    /// </summary>
    UInt32 Rows;
    /// <summary>
    /// The number of columns if the variable is a matrix; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Columns)</para>
    /// </summary>
    UInt32 Columns;
    /// <summary>
    /// The number of bytes that the variable consumes when it is packed tightly by the compiler.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.PackedSize)</para>
    /// </summary>
    UInt32 PackedSize;
    /// <summary>
    /// The number of bytes that the variable consumes before it is packed by the compiler.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.UnpackedSize)</para>
    /// </summary>
    UInt32 UnpackedSize;
    /// <summary>
    /// The number of bytes between elements.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_TYPE_DESC.Stride)</para>
    /// </summary>
    UInt32 Stride;
internal:
    EffectTypeDescription(const D3D10_EFFECT_TYPE_DESC & effectTypeDescription)
    {
        TypeName = effectTypeDescription.TypeName ? gcnew String(effectTypeDescription.TypeName) : nullptr;

        Class = static_cast<ShaderVariableClass>(effectTypeDescription.Class);
        Type = static_cast<ShaderVariableType>(effectTypeDescription.Type);

        Elements = effectTypeDescription.Elements ;
        Members = effectTypeDescription.Members ;
        Rows = effectTypeDescription.Rows ;
        Columns = effectTypeDescription.Columns ;
        PackedSize = effectTypeDescription.PackedSize ;
        UnpackedSize = effectTypeDescription.UnpackedSize ;
        Stride = effectTypeDescription.Stride ;
    }

    void CopTo(D3D10_EFFECT_TYPE_DESC* effectTypeDescription, marshal_context^ context)
    {
        String^ name = TypeName;
        effectTypeDescription->TypeName = TypeName != nullptr ? context->marshal_as<const char*>(name) : NULL;

        effectTypeDescription->Class = static_cast<D3D10_SHADER_VARIABLE_CLASS>(Class);
        effectTypeDescription->Type = static_cast<D3D10_SHADER_VARIABLE_TYPE>(Type);

        effectTypeDescription->Elements = Elements;
        effectTypeDescription->Members = Members;
        effectTypeDescription->Rows = Rows;
        effectTypeDescription->Columns = Columns;
        effectTypeDescription->PackedSize = PackedSize;
        effectTypeDescription->UnpackedSize = UnpackedSize;
        effectTypeDescription->Stride = Stride;
    }
};

/// <summary>
/// Describes an effect variable.
/// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC)</para>
/// </summary>
public value struct EffectVariableDescription 
{
public:
    /// <summary>
    /// A string that contains the variable name.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC.Name)</para>
    /// </summary>
    String^ Name;
    /// <summary>
    /// The semantic attached to the variable; otherwise NULL.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC.Semantic)</para>
    /// </summary>
    String^ Semantic;
    /// <summary>
    /// Optional flags for effect variables.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC.Flags)</para>
    /// </summary>
    UInt32 Flags;
    /// <summary>
    /// The number of annotations; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC.Annotations)</para>
    /// </summary>
    UInt32 Annotations;
    /// <summary>
    /// The offset between the begining of the constant buffer and this variable; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC.BufferOffset)</para>
    /// </summary>
    UInt32 BufferOffset;
    /// <summary>
    /// The register that this variable is bound to. To bind a variable explicitly use the D3D10_EFFECT_VARIABLE_EXPLICIT_BIND_POINT flag.
    /// <para>(Also see DirectX SDK: D3D10_EFFECT_VARIABLE_DESC.ExplicitBindPoint)</para>
    /// </summary>
    UInt32 ExplicitBindPoint;

internal:
    EffectVariableDescription(const D3D10_EFFECT_VARIABLE_DESC & effectVariableDescription)
    {
        Flags = effectVariableDescription.Flags;
        Annotations = effectVariableDescription.Annotations;
        BufferOffset = effectVariableDescription.BufferOffset;
        ExplicitBindPoint = effectVariableDescription.ExplicitBindPoint;

        Name = effectVariableDescription.Name ? gcnew String(effectVariableDescription.Name) : nullptr;
        Semantic = effectVariableDescription.Semantic ? gcnew String(effectVariableDescription.Semantic) : nullptr;

    }

};

/// <summary>
/// A description of a single element for the input-assembler stage.
/// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC)</para>
/// </summary>
public value struct InputElementDescription 
{
public:
    /// <summary>
    /// The HLSL semantic associated with this element in a shader input-signature.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.SemanticName)</para>
    /// </summary>
    String^ SemanticName;

    /// <summary>
    /// The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic name matrix, however each of the four component would have different semantic indices (0, 1, 2, and 3).
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.SemanticIndex)</para>
    /// </summary>
    UInt32 SemanticIndex;

    /// <summary>
    /// The data type of the element data. See Format.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;

    /// <summary>
    /// An integer value that identifies the input-assembler (see input slot). Valid values are between 0 and 15, defined in D3D10.h.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.InputSlot)</para>
    /// </summary>
    UInt32 InputSlot;

    /// <summary>
    /// Optional. Offset (in bytes) between each element. Use D3D10_APPEND_ALIGNED_ELEMENT for convenience to define the current element directly after the previous one, including any packing if necessary.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.AlignedByteOffset)</para>
    /// </summary>
    UInt32 AlignedByteOffset;

    /// <summary>
    /// Identifies the input data class for a single input slot (see <see cref="InputClassification"/>)<seealso cref="InputClassification"/>.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.InputSlotClass)</para>
    /// </summary>
    InputClassification InputSlotClass;

    /// <summary>
    /// The number of instances to draw before stepping one unit forward in a vertex buffer filled with instance data. Can be any unsigned integer value (0 means do not step) when the slot class is D3D10_INPUT_PER_INSTANCE_DATA; must be 0 when the slot class is PerVertexData.
    /// <para>(Also see DirectX SDK: D3D10_INPUT_ELEMENT_DESC.InstanceDataStepRate)</para>
    /// </summary>
    UInt32 InstanceDataStepRate;
internal:
    InputElementDescription(const D3D10_INPUT_ELEMENT_DESC & desc)
    {
        SemanticName = desc.SemanticName ? gcnew String(desc.SemanticName) : nullptr;
        SemanticIndex = desc.SemanticIndex;
        Format = static_cast<DXGI::Format>(desc.Format);
        InputSlot = desc.InputSlot;
        AlignedByteOffset = desc.AlignedByteOffset;
        InputSlotClass = static_cast<InputClassification>(desc.InputSlotClass);
        InstanceDataStepRate = desc.InstanceDataStepRate;
    }

    void CopyTo(D3D10_INPUT_ELEMENT_DESC * desc, marshal_context^ context)
    {
        desc->SemanticIndex = SemanticIndex;
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->InputSlot = InputSlot;
        desc->AlignedByteOffset = AlignedByteOffset;
        desc->InputSlotClass = static_cast<D3D10_INPUT_CLASSIFICATION>(InputSlotClass);
        desc->InstanceDataStepRate = InstanceDataStepRate;

        String^ name = SemanticName;
        desc->SemanticName = SemanticName == nullptr ? NULL : context->marshal_as<const char*>(name);
    }

};
/// <summary>
/// Provides access to subresource data in a 2D texture.
/// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE2D)</para>
/// </summary>
public value struct MappedTexture2D 
{
public:
    /// <summary>
    /// Pointer to the data.
    /// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE2D.pData)</para>
    /// </summary>
    IntPtr Data;

    /// <summary>
    /// The pitch, or width, or physical size (in bytes), of one row of an uncompressed texture. A block-compressed texture is encoded in 4x4 blocks (see virtual size vs physical size) ; therefore, RowPitch is the number of bytes in a block of 4x4 texels.
    /// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE2D.RowPitch)</para>
    /// </summary>
    UInt32 RowPitch;
internal:
    MappedTexture2D(const D3D10_MAPPED_TEXTURE2D & tex)
    {
        Data = IntPtr(tex.pData);
        RowPitch = tex.RowPitch;
    }

};
/// <summary>
/// Provides access to subresource data in a 3D texture.
/// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE3D)</para>
/// </summary>
public value struct MappedTexture3D 
{
public:
    /// <summary>
    /// Pointer to the data.
    /// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE3D.pData)</para>
    /// </summary>
    IntPtr Data;
    /// <summary>
    /// The pitch, or width, or physical size (in bytes) of one row of an uncompressed texture. Since a block-compressed texture is encoded in 4x4 blocks, the RowPitch for a compressed texture is the number of bytes in a block of 4x4 texels. See virtual size vs physical size for more information on block compression.
    /// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE3D.RowPitch)</para>
    /// </summary>
    UInt32 RowPitch;
    /// <summary>
    /// The pitch or number of bytes in all rows for a single depth.
    /// <para>(Also see DirectX SDK: D3D10_MAPPED_TEXTURE3D.DepthPitch)</para>
    /// </summary>
    UInt32 DepthPitch;
internal:
    MappedTexture3D(const D3D10_MAPPED_TEXTURE3D & tex)
    {
        Data = IntPtr(tex.pData);
        RowPitch = tex.RowPitch;
        DepthPitch = tex.DepthPitch;
    }
};

/// <summary>
/// A debug message in the Information Queue.
/// <para>(Also see DirectX SDK: D3D10_MESSAGE)</para>
/// </summary>
public value struct Message 
{
public:
    /// <summary>
    /// The category of the message. See MessageCategory.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE.Category)</para>
    /// </summary>
    MessageCategory Category;
    /// <summary>
    /// The severity of the message. See MessageSeverity.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE.Severity)</para>
    /// </summary>
    MessageSeverity Severity;
    /// <summary>
    /// The ID of the message. See MessageId.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE.ID)</para>
    /// </summary>
    MessageId Id;
    /// <summary>
    /// The message description string.
    /// <para>(Also see DirectX SDK: D3D10_MESSAGE.pDescription)</para>
    /// </summary>
    String^ Description;
internal:
    Message (D3D10_MESSAGE* msg)
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

    void CopyTo(D3D10_MESSAGE* msg)
    {
    }};
/// <summary>
/// Describes an effect pass, which contains pipeline state.
/// <para>(Also see DirectX SDK: D3D10_PASS_DESC)</para>
/// </summary>
public value struct PassDescription 
{
public:
    /// <summary>
    /// A string that contains the name of the pass; otherwise NULL.
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.Name)</para>
    /// </summary>
    String^ Name;
    /// <summary>
    /// The number of annotations.
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.Annotations)</para>
    /// </summary>
    UInt32 Annotations;
    /// <summary>
    /// The input signature or the vertex shader; otherwise NULL.
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.pIAInputSignature)</para>
    /// </summary>
    IntPtr InputAssemblerInputSignature;
    /// <summary>
    /// The size of the input signature (in bytes).
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.IAInputSignatureSize)</para>
    /// </summary>
    UInt32 InputAssemblerInputSignatureSize;
    /// <summary>
    /// The stencil-reference value used in the depth-stencil state (see Configuring Depth-Stencil Functionality (Direct3D 10)).
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.StencilRef)</para>
    /// </summary>
    UInt32 StencilRef;
    /// <summary>
    /// The sample mask for the blend state (see Configuring Blending Functionality (Direct3D 10)).
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.SampleMask)</para>
    /// </summary>
    UInt32 SampleMask;
    /// <summary>
    /// The per-component blend factors (RGBA) for the blend state (see Configuring Blending Functionality (Direct3D 10)).
    /// <para>(Also see DirectX SDK: D3D10_PASS_DESC.BlendFactor)</para>
    /// </summary>
    property array<Single>^ BlendFactor
    {
        array<Single>^ get()
        {
            if (blendFactor == nullptr)
            {
                 blendFactor = gcnew array<Single>(BlendFactorArrayLength);
            }
            return blendFactor;
        }

    }
internal:
    PassDescription(const D3D10_PASS_DESC & desc)
    {
        Name = desc.Name ? gcnew String(desc.Name) : nullptr;
        Annotations = desc.Annotations;
        InputAssemblerInputSignature = IntPtr((void*)desc.pIAInputSignature);
        InputAssemblerInputSignatureSize = static_cast<UInt32>(desc.IAInputSignatureSize);
        StencilRef = desc.StencilRef;
        SampleMask = desc.SampleMask;


        blendFactor = gcnew array<Single>(BlendFactorArrayLength);       
        pin_ptr<Single> ptr = &blendFactor[0];

        memcpy(ptr, desc.BlendFactor, sizeof(FLOAT)* BlendFactorArrayLength);        
    }
private:
    literal int BlendFactorArrayLength = 4;
    array<Single>^ blendFactor;
};
ref class EffectShaderVariable;
/// <summary>
/// Describes an effect variable that contains a shader.
/// <para>(Also see DirectX SDK: D3D10_PASS_SHADER_DESC)</para>
/// </summary>
public value struct PassShaderDescription 
{
public:
    /// <summary>
    /// The variable that the shader came from. If it is an inline shader assignment, the returned interface will be an anonymous shader variable, which is not retrievable any other way.  Its name in the variable description will be "$Anonymous". If there is no assignment of this type in the pass block, this will point to a shader variable that returns false when IsValid is called.
    /// <para>(Also see DirectX SDK: D3D10_PASS_SHADER_DESC.pShaderVariable)</para>
    /// </summary>
    EffectShaderVariable^ ShaderVariable;

    /// <summary>
    /// A zero-based array index; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_PASS_SHADER_DESC.ShaderIndex)</para>
    /// </summary>
    UInt32 ShaderIndex;
internal:
    PassShaderDescription(const D3D10_PASS_SHADER_DESC&);
};

/// <summary>
/// Query information about graphics-pipeline activity in between calls to Asynchronous.Begin and Asynchronous.End.
/// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS)</para>
/// </summary>
public value struct QueryDataPipelineStatistics 
{
public:
    /// <summary>
    /// Number of vertices read by input assembler.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.IAVertices)</para>
    /// </summary>
    UInt64 InputAssemblerVertices;
    /// <summary>
    /// Number of primitives read by the input assembler. This number can be different depending on the primitive topology used. For example, a triangle strip with 6 vertices will produce 4 triangles, however a triangle list with 6 vertices will produce 2 triangles.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.IAPrimitives)</para>
    /// </summary>
    UInt64 InputAssemblerPrimitives;
    /// <summary>
    /// Number of times a vertex shader was invoked. Direct3D invokes the vertex shader once per vertex.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.VSInvocations)</para>
    /// </summary>
    UInt64 VertexShaderInvocations;
    /// <summary>
    /// Number of times a geometry shader was invoked. When the geometry shader is set to NULL, this statistic may or may not increment depending on the hardware manufacturer.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.GSInvocations)</para>
    /// </summary>
    UInt64 GeometryShaderInvocations;
    /// <summary>
    /// Number of primitives output by a geometry shader.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.GSPrimitives)</para>
    /// </summary>
    UInt64 GeometryShaderPrimitives;
    /// <summary>
    /// Number of primitives that were sent to the rasterizer. When the rasterizer is disabled, this will not increment.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.CInvocations)</para>
    /// </summary>
    UInt64 CInvocations;
    /// <summary>
    /// Number of primitives that were rendered. This may be larger or smaller than CInvocations because after a primitive is clipped sometimes it is either broken up into more than one primitive or completely culled.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.CPrimitives)</para>
    /// </summary>
    UInt64 CPrimitives;
    /// <summary>
    /// Number of times a pixel shader was invoked.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_PIPELINE_STATISTICS.PSInvocations)</para>
    /// </summary>
    UInt64 PixelShaderInvocations;
};
/// <summary>
/// Query information about the amount of data streamed out to the stream-output buffers in between Asynchronous.Begin and Asynchronous.End.
/// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_SO_STATISTICS)</para>
/// </summary>
public value struct QueryDataStreamOuputStatistics 
{
public:
    /// <summary>
    /// Number of primitives (that is, points, lines, and triangles) written to the stream-output buffers.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_SO_STATISTICS.NumPrimitivesWritten)</para>
    /// </summary>
    UInt64 NumPrimitivesWritten;
    /// <summary>
    /// Number of primitives that would have been written to the stream-output buffers if there had been enough space for them all.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_SO_STATISTICS.PrimitivesStorageNeeded)</para>
    /// </summary>
    UInt64 PrimitivesStorageNeeded;
};
/// <summary>
/// Query information about the reliability of a timestamp query.
/// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_TIMESTAMP_DISJOINT)</para>
/// </summary>
public value struct QueryDataTimestampDisjoint 
{
public:
    /// <summary>
    /// How frequently the GPU counter increments in Hz.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_TIMESTAMP_DISJOINT.Frequency)</para>
    /// </summary>
    UInt64 Frequency;
    /// <summary>
    /// If this is TRUE, something occurred in between the query's Asynchronous.Begin and Asynchronous.End calls that caused the timestamp counter to become discontinuous or disjoint, such as unplugging the AC chord on a laptop, overheating, or throttling up/down due to laptop savings events. The timestamp returned by Asynchronous.GetData for a timestamp query is only reliable if Disjoint is FALSE.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DATA_TIMESTAMP_DISJOINT.Disjoint)</para>
    /// </summary>
    Boolean Disjoint;
};
/// <summary>
/// Describes a query.
/// <para>(Also see DirectX SDK: D3D10_QUERY_DESC)</para>
/// </summary>
public value struct QueryDescription 
{
public:
    /// <summary>
    /// Type of query.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DESC.D3DQuery)</para>
    /// </summary>
    D3D10::Query Query;
    /// <summary>
    /// Miscellaneous flags (see <see cref="QueryMiscFlag"/>)<seealso cref="QueryMiscFlag"/>.
    /// <para>(Also see DirectX SDK: D3D10_QUERY_DESC.MiscFlags)</para>
    /// </summary>
    QueryMiscFlag MiscFlags;

internal:
    QueryDescription (const D3D10_QUERY_DESC& desc)
    {
        Query = static_cast<D3D10::Query>(desc.Query);
        MiscFlags = static_cast<D3D10::QueryMiscFlag>(desc.MiscFlags);
    }

    void CopyTo(D3D10_QUERY_DESC* desc)
    {
        desc->Query = static_cast<D3D10_QUERY>(Query);
        desc->MiscFlags = static_cast<UINT>(MiscFlags);
    }
};
/// <summary>
/// Describes the rasterizer state.
/// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC)</para>
/// </summary>
public value struct RasterizerDescription
{
public:
    /// <summary>
    /// A member of the FillMode enumerated type that determines the fill mode to use when rendering.  The default value is Solid.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.FillMode)</para>
    /// </summary>
    D3D10::FillMode FillMode;
    /// <summary>
    /// A member of the CullMode enumerated type that indicates whether triangles facing the specified direction are drawn.  The default value is Back.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.CullMode)</para>
    /// </summary>
    D3D10::CullMode CullMode;
    /// <summary>
    /// Determines if a triangle is front-facing or back-facing. If this parameter is TRUE, then a triangle is considered front-facing if its vertices are counter-clockwise on the render target, and considered back-facing if they are clockwise. If this parameter is FALSE, then the opposite is true.  The default value is FALSE.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.FrontCounterClockwise)</para>
    /// </summary>
    Boolean FrontCounterClockwise;
    /// <summary>
    /// Specifies the depth value added to a given pixel. The default value is 0. For more information, see Depth Bias.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.DepthBias)</para>
    /// </summary>
    Int32 DepthBias;
    /// <summary>
    /// Specifies the maximum depth bias of a pixel. The default value is 0.0f. For more information, see Depth Bias.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.DepthBiasClamp)</para>
    /// </summary>
    Single DepthBiasClamp;
    /// <summary>
    /// Specifies a scalar on a given pixel's slope. The default value is 0.0f. For more information, see Depth Bias.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.SlopeScaledDepthBias)</para>
    /// </summary>
    Single SlopeScaledDepthBias;
    /// <summary>
    /// Enables or disables clipping based on distance.  The default value is TRUE.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.DepthClipEnable)</para>
    /// </summary>
    Boolean DepthClipEnable;
    /// <summary>
    /// Enable or disables scissor-rectangle culling. All pixels outside an active scissor rectangle are culled. The default value is FALSE. For more information, see Set the Scissor Rectangle.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.ScissorEnable)</para>
    /// </summary>
    Boolean ScissorEnable;
    /// <summary>
    /// Enables or disables multisample antialiasing.  The default value is FALSE.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.MultisampleEnable)</para>
    /// </summary>
    Boolean MultisampleEnable;
    /// <summary>
    /// Enable or disables line antialiasing. Note that this option only applies when alpha blending is enabled, you are drawing lines, and the MultisampleEnable member is FALSE.  The default value is FALSE.
    /// <para>(Also see DirectX SDK: D3D10_RASTERIZER_DESC.AntialiasedLineEnable)</para>
    /// </summary>
    Boolean AntialiasedLineEnable;

internal:
    RasterizerDescription(const D3D10_RASTERIZER_DESC& desc)
    {
        FillMode = static_cast<D3D10::FillMode>(desc.FillMode);
        CullMode = static_cast<D3D10::CullMode>(desc.CullMode);
        FrontCounterClockwise = desc.FrontCounterClockwise != 0;
        DepthBias = desc.DepthBias;
        DepthBiasClamp = desc.DepthBiasClamp;
        SlopeScaledDepthBias = desc.SlopeScaledDepthBias;
        DepthClipEnable = desc.DepthClipEnable != 0;
        ScissorEnable = desc.ScissorEnable != 0;
        MultisampleEnable = desc.MultisampleEnable != 0;
        AntialiasedLineEnable = desc.AntialiasedLineEnable != 0;
    }

    void CopyTo(D3D10_RASTERIZER_DESC* desc)
    {
        desc->FillMode = static_cast<D3D10_FILL_MODE>(FillMode) ;
        desc->CullMode = static_cast<D3D10_CULL_MODE>(CullMode) ;

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
/// Specifies the subresource(s) from a resource that are accessible using a render-target view.
/// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct RenderTargetViewDescription 
{
public:
    /// <summary>
    /// The data format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// The resource type (see <see cref="RenderTargetViewDimension"/>)<seealso cref="RenderTargetViewDimension"/>, which specifies how the render-target resource will be accessed.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    RenderTargetViewDimension ViewDimension;
    /// <summary>
    /// Specifies which buffer elements can be accessed (see <see cref="BufferRenderTargetView"/>)<seealso cref="BufferRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Buffer)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferRenderTargetView Buffer;
    /// <summary>
    /// Specifies the subresources in a 1D texture that can be accessed (see <see cref="Texture1DRenderTargetView"/>)<seealso cref="Texture1DRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DRenderTargetView Texture1D;
    /// <summary>
    /// Specifies the subresources in a 1D texture array that can be accessed (see <see cref="Texture1DArrayRenderTargetView"/>)<seealso cref="Texture1DArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayRenderTargetView Texture1DArray;
    /// <summary>
    /// Specifies the subresources in a 2D texture that can be accessed (see <see cref="Texture2DRenderTargetView"/>)<seealso cref="Texture2DRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DRenderTargetView Texture2D;
    /// <summary>
    /// Specifies the subresources in a 2D texture array that can be accessed (see <see cref="Texture2DArrayRenderTargetView"/>)<seealso cref="Texture2DArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayRenderTargetView Texture2DArray;
    /// <summary>
    /// Specifies a single subresource because a multisampled 2D texture only contains one subresource (see <see cref="Texture2DMultiSampleRenderTargetView"/>)<seealso cref="Texture2DMultiSampleRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture2DMultiSample)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleRenderTargetView Texture2DMultiSample;
    /// <summary>
    /// Specifies the subresources in a multisampled 2D texture array that can be accessed (see <see cref="Texture2DMultiSampleArrayRenderTargetView"/>)<seealso cref="Texture2DMultiSampleArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleArrayRenderTargetView Texture2DMultiSampleArray;
    /// <summary>
    /// Specifies subresources in a 3D texture that can be accessed (see <see cref="Texture3DRenderTargetView"/>)<seealso cref="Texture3DRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D10_RENDER_TARGET_VIEW_DESC.Texture3D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture3DRenderTargetView Texture3D;
};
/// <summary>
/// Describes a sampler state.
/// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC)</para>
/// </summary>
public value struct SamplerDescription
{
public:
    /// <summary>
    /// Filtering method to use when sampling a texture (see <see cref="Filter"/>)<seealso cref="Filter"/>.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.Filter)</para>
    /// </summary>
    D3D10::Filter Filter;
    /// <summary>
    /// Method to use for resolving a u texture coordinate that is outside the 0 to 1 range (see <see cref="TextureAddressMode"/>)<seealso cref="TextureAddressMode"/>.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.AddressU)</para>
    /// </summary>
    TextureAddressMode AddressU;
    /// <summary>
    /// Method to use for resolving a v texture coordinate that is outside the 0 to 1 range.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.AddressV)</para>
    /// </summary>
    TextureAddressMode AddressV;
    /// <summary>
    /// Method to use for resolving a w texture coordinate that is outside the 0 to 1 range.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.AddressW)</para>
    /// </summary>
    TextureAddressMode AddressW;
    /// <summary>
    /// Offset from the calculated mipmap level. For example, if Direct3D calculates that a texture should be sampled at mipmap level 3 and MipLODBias is 2, then the texture will be sampled at mipmap level 5.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.MipLODBias)</para>
    /// </summary>
    Single MipLODBias;
    /// <summary>
    /// Clamping value used if Anisotropic or ComparisonAnisotropic is specified in Filter. Valid values are between 1 and 16.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.MaxAnisotropy)</para>
    /// </summary>
    UInt32 MaxAnisotropy;
    /// <summary>
    /// A function that compares sampled data against existing sampled data. The function options are listed in ComparisonFunction.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.ComparisonFunc)</para>
    /// </summary>
    D3D10::ComparisonFunction ComparisonFunction;

    /// <summary>
    /// Border color to use if Border is specified for AddressU, AddressV, or AddressW. Range must be between 0.0 and 1.0 inclusive.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.BorderColor)</para>
    /// </summary>
    ColorRgba BorderColor;

    /// <summary>
    /// Lower end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.MinLOD)</para>
    /// </summary>
    Single MinLOD;
    /// <summary>
    /// Upper end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed. This value must be greater than or equal to MinLOD. To have no upper limit on LOD set this to a large value such as D3D10_FLOAT32_MAX.
    /// <para>(Also see DirectX SDK: D3D10_SAMPLER_DESC.MaxLOD)</para>
    /// </summary>
    Single MaxLOD;

internal:
    SamplerDescription(const D3D10_SAMPLER_DESC & desc)
    {
        Filter = static_cast<D3D10::Filter>(desc.Filter);
        AddressU = static_cast<TextureAddressMode>(desc.AddressU);
        AddressV = static_cast<TextureAddressMode>(desc.AddressV);
        AddressW = static_cast<TextureAddressMode>(desc.AddressW);
        
        MipLODBias = desc.MipLODBias;
        MaxAnisotropy = desc.MaxAnisotropy;

        ComparisonFunction = static_cast<D3D10::ComparisonFunction>(desc.ComparisonFunc);

        BorderColor = ColorRgba(desc.BorderColor);

        MinLOD = desc.MinLOD;
        MaxLOD = desc.MaxLOD;
    }

    void CopyTo(D3D10_SAMPLER_DESC* desc)
    {
        desc->Filter = static_cast<D3D10_FILTER>(Filter);
        desc->AddressU = static_cast<D3D10_TEXTURE_ADDRESS_MODE>(AddressU);
        desc->AddressV = static_cast<D3D10_TEXTURE_ADDRESS_MODE>(AddressV);
        desc->AddressW = static_cast<D3D10_TEXTURE_ADDRESS_MODE>(AddressW);
        
        desc->MipLODBias = MipLODBias;
        desc->MaxAnisotropy = MaxAnisotropy;

        desc->BorderColor[0] = BorderColor.Red;
        desc->BorderColor[1] = BorderColor.Green;
        desc->BorderColor[2] = BorderColor.Blue;
        desc->BorderColor[3] = BorderColor.Alpha;

        desc->ComparisonFunc= static_cast<D3D10_COMPARISON_FUNC>(ComparisonFunction);

        desc->MinLOD = MinLOD;
        desc->MaxLOD = MaxLOD;
    }
};
/// <summary>
/// Describes a shader constant-buffer.
/// <para>(Also see DirectX SDK: D3D10_SHADER_BUFFER_DESC)</para>
/// </summary>
public value struct ShaderBufferDescription 
{
public:
    /// <summary>
    /// The name of the buffer.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_BUFFER_DESC.Name)</para>
    /// </summary>
    String^ Name;
    /// <summary>
    /// The intended use of the constant data. See ConstantBufferType.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_BUFFER_DESC.Type)</para>
    /// </summary>
    ConstantBufferType Type;
    /// <summary>
    /// The number of unique variables.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_BUFFER_DESC.Variables)</para>
    /// </summary>
    UInt32 Variables;
    /// <summary>
    /// Buffer size (in bytes).
    /// <para>(Also see DirectX SDK: D3D10_SHADER_BUFFER_DESC.Size)</para>
    /// </summary>
    UInt32 Size;
    /// <summary>
    /// Shader buffer properties. See ShaderConstantBufferFlags.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_BUFFER_DESC.uFlags)</para>
    /// </summary>
    UInt32 Flags;

internal:
    ShaderBufferDescription(const D3D10_SHADER_BUFFER_DESC & desc)
    {
        Name = desc.Name ? gcnew String(desc.Name) : nullptr;
        Type = static_cast<ConstantBufferType>(desc.Type);
        Variables = desc.Variables;
        Size = desc.Size;
        Flags = desc.Type;
    }
};
/// <summary>
/// Describes a shader.
/// <para>(Also see DirectX SDK: D3D10_SHADER_DESC)</para>
/// </summary>
public value struct ShaderDescription 
{
public:
    /// <summary>
    /// Shader version.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.Version)</para>
    /// </summary>
    UInt32 Version;
    /// <summary>
    /// The name of the originator of the shader.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.Creator)</para>
    /// </summary>
    String^ Creator;
    /// <summary>
    /// Shader compilation/parse flags.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.Flags)</para>
    /// </summary>
    UInt32 Flags;
    /// <summary>
    /// The number of shader-constant buffers.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.ConstantBuffers)</para>
    /// </summary>
    UInt32 ConstantBuffers;
    /// <summary>
    /// The number of resource (textures and buffers) bound to a shader.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.BoundResources)</para>
    /// </summary>
    UInt32 BoundResources;
    /// <summary>
    /// The number of parameters in the input signature.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.InputParameters)</para>
    /// </summary>
    UInt32 InputParameters;
    /// <summary>
    /// The number of parameters in the output signature.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.OutputParameters)</para>
    /// </summary>
    UInt32 OutputParameters;
    /// <summary>
    /// The number of intermediate-language instructions in the compiled shader.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.InstructionCount)</para>
    /// </summary>
    UInt32 InstructionCount;
    /// <summary>
    /// The number of temporary registers in the compiled shader.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TempRegisterCount)</para>
    /// </summary>
    UInt32 TempRegisterCount;
    /// <summary>
    /// Number of temporary arrays used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TempArrayCount)</para>
    /// </summary>
    UInt32 TempArrayCount;
    /// <summary>
    /// Number of constant defines.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.DefCount)</para>
    /// </summary>
    UInt32 DefCount;
    /// <summary>
    /// Number of declarations (input + output).
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.DclCount)</para>
    /// </summary>
    UInt32 DclCount;
    /// <summary>
    /// Number of non-categorized texture instructions.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TextureNormalInstructions)</para>
    /// </summary>
    UInt32 TextureNormalInstructions;
    /// <summary>
    /// Number of texture load instructions
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TextureLoadInstructions)</para>
    /// </summary>
    UInt32 TextureLoadInstructions;
    /// <summary>
    /// Number of texture comparison instructions
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TextureCompInstructions)</para>
    /// </summary>
    UInt32 TextureCompInstructions;
    /// <summary>
    /// Number of texture bias instructions
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TextureBiasInstructions)</para>
    /// </summary>
    UInt32 TextureBiasInstructions;
    /// <summary>
    /// Number of texture gradient instructions.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.TextureGradientInstructions)</para>
    /// </summary>
    UInt32 TextureGradientInstructions;
    /// <summary>
    /// Number of floating point arithmetic instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.FloatInstructionCount)</para>
    /// </summary>
    UInt32 FloatInstructionCount;
    /// <summary>
    /// Number of signed integer arithmetic instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.IntInstructionCount)</para>
    /// </summary>
    UInt32 IntInstructionCount;
    /// <summary>
    /// Number of unsigned integer arithmetic instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.UintInstructionCount)</para>
    /// </summary>
    UInt32 UintInstructionCount;
    /// <summary>
    /// Number of static flow control instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.StaticFlowControlCount)</para>
    /// </summary>
    UInt32 StaticFlowControlCount;
    /// <summary>
    /// Number of dynamic flow control instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.DynamicFlowControlCount)</para>
    /// </summary>
    UInt32 DynamicFlowControlCount;
    /// <summary>
    /// Number of macro instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.MacroInstructionCount)</para>
    /// </summary>
    UInt32 MacroInstructionCount;
    /// <summary>
    /// Number of array instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.ArrayInstructionCount)</para>
    /// </summary>
    UInt32 ArrayInstructionCount;
    /// <summary>
    /// Number of cut instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.CutInstructionCount)</para>
    /// </summary>
    UInt32 CutInstructionCount;
    /// <summary>
    /// Number of emit instructions used.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.EmitInstructionCount)</para>
    /// </summary>
    UInt32 EmitInstructionCount;
    /// <summary>
    /// Geometry shader output topology.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.GSOutputTopology)</para>
    /// </summary>
    PrimitiveTopology GeometryShaderOutputTopology;
    /// <summary>
    /// Geometry shader maximum output vertex count.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_DESC.GSMaxOutputVertexCount)</para>
    /// </summary>
    UInt32 GeometryShaderMaxOutputVertexCount;

internal:
    ShaderDescription(const D3D10_SHADER_DESC & desc)
    {
        Version = desc.Version;
        Creator = desc.Creator ? gcnew String(desc.Creator) : nullptr;
        Flags = desc.Flags  ;    
        ConstantBuffers = desc.ConstantBuffers ;
        BoundResources = desc.BoundResources ;
        InputParameters = desc.InputParameters ;
        OutputParameters = desc.OutputParameters ;
        InstructionCount = desc.InstructionCount ;
        TempRegisterCount = desc.TempRegisterCount ;
        TempArrayCount = desc.TempArrayCount ;
        DefCount = desc.DefCount ;
        DclCount = desc.DclCount ;
        TextureNormalInstructions = desc.TextureNormalInstructions ;
        TextureLoadInstructions = desc.TextureLoadInstructions ;
        TextureCompInstructions = desc.TextureCompInstructions ;
        TextureBiasInstructions = desc.TextureBiasInstructions ;
        TextureGradientInstructions = desc.TextureGradientInstructions ;
        FloatInstructionCount = desc.FloatInstructionCount ;
        IntInstructionCount = desc.IntInstructionCount ;
        UintInstructionCount = desc.UintInstructionCount ;
        StaticFlowControlCount = desc.StaticFlowControlCount ;
        DynamicFlowControlCount = desc.DynamicFlowControlCount ;
        MacroInstructionCount = desc.MacroInstructionCount ;
        ArrayInstructionCount = desc.ArrayInstructionCount ;
        CutInstructionCount = desc.CutInstructionCount ;
        EmitInstructionCount = desc.EmitInstructionCount ;
        GeometryShaderOutputTopology = static_cast<PrimitiveTopology>(desc.GSOutputTopology );
        GeometryShaderMaxOutputVertexCount = desc.GSMaxOutputVertexCount ;
    }
};
/// <summary>
/// Describes how a shader resource is bound to a shader input.
/// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC)</para>
/// </summary>
public value struct ShaderInputBindDescription 
{
public:
    /// <summary>
    /// Name of the shader resource.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.Name)</para>
    /// </summary>
    String^ Name;
    /// <summary>
    /// Identifies the type of data in the resource. See ShaderInputType.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.Type)</para>
    /// </summary>
    ShaderInputType Type;
    /// <summary>
    /// Starting bind point.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.BindPoint)</para>
    /// </summary>
    UInt32 BindPoint;
    /// <summary>
    /// Number of contiguous bind points for arrays.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.BindCount)</para>
    /// </summary>
    UInt32 BindCount;
    /// <summary>
    /// Shader input-parameter options. See ShaderInputFlags.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.uFlags)</para>
    /// </summary>
    ShaderInputFlags Flags;
    /// <summary>
    /// If the input is a texture, the return type. See ResourceReturnType.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.ReturnType)</para>
    /// </summary>
    ResourceReturnType ReturnType;
    /// <summary>
    /// Identifies the amount of data in the resource. See ShaderResourceViewDimension.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.Dimension)</para>
    /// </summary>
    ShaderResourceViewDimension Dimension;
    /// <summary>
    /// The number of samples for a multisampled texture; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_INPUT_BIND_DESC.NumSamples)</para>
    /// </summary>
    UInt32 NumSamples;
internal:
    ShaderInputBindDescription(const D3D10_SHADER_INPUT_BIND_DESC & desc)
    {
        Name = desc.Name ? gcnew String(desc.Name) : nullptr;
        Type = static_cast<ShaderInputType>(desc.Type);
        BindCount = desc.BindCount;
        BindPoint = desc.BindPoint;
        Flags = static_cast<ShaderInputFlags>(desc.uFlags);
        ReturnType = static_cast<ResourceReturnType>(desc.ReturnType);
        Dimension = static_cast<ShaderResourceViewDimension>(desc.Dimension);
        NumSamples = desc.NumSamples;
    }
};
/// <summary>
/// Describes a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct ShaderResourceViewDescription 
{
public:
    /// <summary>
    /// The viewing format.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// The resource type of the view. See ShaderResourceViewDimension. This should be the same as the resource type of the underlying resource. This parameter also determines which _SRV to use in the union below.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    ShaderResourceViewDimension ViewDimension;
    /// <summary>
    /// View the resource as a buffer using information from a shader-resource view (see <see cref="BufferShaderResourceView"/>)<seealso cref="BufferShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Buffer)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferShaderResourceView Buffer;
    /// <summary>
    /// View the resource as a 1D texture using information from a shader-resource view (see <see cref="Texture1DShaderResourceView"/>)<seealso cref="Texture1DShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DShaderResourceView Texture1D;
    /// <summary>
    /// View the resource as a 1D-texture array using information from a shader-resource view (see Texture1DArrayShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayShaderResourceView Texture1DArray;
    /// <summary>
    /// View the resource as a 2D-texture using information from a shader-resource view (see Texture2DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DShaderResourceView Texture2D;
    /// <summary>
    /// View the resource as a 2D-texture array using information from a shader-resource view (see Texture2DArrayShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayShaderResourceView Texture2DArray;
    /// <summary>
    /// View the resource as a 2D-multisampled texture using information from a shader-resource view (see Texture2DMultiSampleShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture2DMultiSample)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleShaderResourceView Texture2DMultiSample;
    /// <summary>
    /// View the resource as a 2D-multisampled-texture array using information from a shader-resource view (see Texture2DMultiSampleArrayShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleArrayShaderResourceView Texture2DMultiSampleArray;
    /// <summary>
    /// View the resource as a 3D texture using information from a shader-resource view (see Texture3DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.Texture3D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture3DShaderResourceView Texture3D;
    /// <summary>
    /// View the resource as a 3D-cube texture using information from a shader-resource view (see <see cref="TextureCubeShaderResourceView"/>)<seealso cref="TextureCubeShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC.TextureCube)</para>
    /// </summary>
    [FieldOffset(8)]
    TextureCubeShaderResourceView TextureCube;

internal:
    ShaderResourceViewDescription(const D3D10_SHADER_RESOURCE_VIEW_DESC& desc)
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
        default :
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }

    void CopyTo(D3D10_SHADER_RESOURCE_VIEW_DESC* desc)
    {
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->ViewDimension = static_cast<D3D10_SRV_DIMENSION>(ViewDimension);

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
        default:
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }


};
/// <summary>
/// Describes a shader-resource view.
/// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1)</para>
/// </summary>
[StructLayout(LayoutKind::Explicit)]
public value struct ShaderResourceViewDescription1 
{
public:
    /// <summary>
    /// The viewing format.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Format)</para>
    /// </summary>
    [FieldOffset(0)]
    DXGI::Format Format;
    /// <summary>
    /// The resource type of the view. See ShaderResourceViewDimension1. This should be the same as the resource type of the underlying resource. This parameter also determines which _SRV to use in the union below.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.ViewDimension)</para>
    /// </summary>
    [FieldOffset(4)]
    ShaderResourceViewDimension1 ViewDimension;
    /// <summary>
    /// View the resource as a buffer using information from a shader-resource view (see <see cref="BufferShaderResourceView"/>)<seealso cref="BufferShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Buffer)</para>
    /// </summary>
    [FieldOffset(8)]
    BufferShaderResourceView Buffer;
    /// <summary>
    /// View the resource as a 1D texture using information from a shader-resource view (see <see cref="Texture1DShaderResourceView"/>)<seealso cref="Texture1DShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture1D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DShaderResourceView Texture1D;
    /// <summary>
    /// View the resource as a 1D-texture array using information from a shader-resource view (see Texture1DArrayShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture1DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture1DArrayShaderResourceView Texture1DArray;
    /// <summary>
    /// View the resource as a 2D-texture using information from a shader-resource view (see Texture2DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture2D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DShaderResourceView Texture2D;
    /// <summary>
    /// View the resource as a 2D-texture array using information from a shader-resource view (see Texture2DArrayShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture2DArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DArrayShaderResourceView Texture2DArray;
    /// <summary>
    /// View the resource as a 2D-multisampled texture using information from a shader-resource view (see Texture2DMultiSampleShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture2DMultiSample)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleShaderResourceView Texture2DMultiSample;
    /// <summary>
    /// View the resource as a 2D-multisampled-texture array using information from a shader-resource view (see Texture2DMultiSampleArrayShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture2DMSArray)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture2DMultiSampleArrayShaderResourceView Texture2DMultiSampleArray;
    /// <summary>
    /// View the resource as a 3D texture using information from a shader-resource view (see Texture3DShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.Texture3D)</para>
    /// </summary>
    [FieldOffset(8)]
    Texture3DShaderResourceView Texture3D;
    /// <summary>
    /// View the resource as a 3D-cube texture using information from a shader-resource view (see <see cref="TextureCubeShaderResourceView"/>)<seealso cref="TextureCubeShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.TextureCube)</para>
    /// </summary>
    [FieldOffset(8)]
    TextureCubeShaderResourceView TextureCube;
    /// <summary>
    /// View the resource as an array of cube textures using information from a shader-resource view (see <see cref="TextureCubeArrayShaderResourceView1"/>)<seealso cref="TextureCubeArrayShaderResourceView1"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_RESOURCE_VIEW_DESC1.TextureCubeArray)</para>
    /// </summary>
    [FieldOffset(8)]
    TextureCubeArrayShaderResourceView1 TextureCubeArray;
internal:
    ShaderResourceViewDescription1(const D3D10_SHADER_RESOURCE_VIEW_DESC1& desc)
    {
        Format = static_cast<DXGI::Format>(desc.Format);
        ViewDimension = static_cast<ShaderResourceViewDimension1>(desc.ViewDimension);

        switch (ViewDimension)
        {
        case ShaderResourceViewDimension1::Buffer :
               {
                   Buffer.ElementOffset = desc.Buffer.ElementOffset;
                   Buffer.ElementWidth = desc.Buffer.ElementWidth;
                   break;
               }
        case ShaderResourceViewDimension1::Texture1D :
              {
                  Texture1D.MipLevels = desc.Texture1D.MipLevels;
                  Texture1D.MostDetailedMip = desc.Texture1D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture1DArray :
              {
                  Texture1DArray.ArraySize = desc.Texture1DArray.ArraySize;
                  Texture1DArray.FirstArraySlice = desc.Texture1DArray.FirstArraySlice;
                  Texture1DArray.MipLevels = desc.Texture1DArray.MipLevels;
                  Texture1DArray.MostDetailedMip = desc.Texture1DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2D :
              {
                  Texture2D.MipLevels = desc.Texture2D.MipLevels;
                  Texture2D.MostDetailedMip = desc.Texture2D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2DArray :
              {
                  Texture2DArray.ArraySize = desc.Texture2DArray.ArraySize;
                  Texture2DArray.FirstArraySlice = desc.Texture2DArray.FirstArraySlice;
                  Texture2DArray.MipLevels = desc.Texture2DArray.MipLevels;
                  Texture2DArray.MostDetailedMip = desc.Texture2DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2DMultiSample :
              {
                  Texture2DMultiSample.UnusedField = desc.Texture2DMS.UnusedField_NothingToDefine;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2DMultiSampleArray :
              {
                  Texture2DMultiSampleArray.ArraySize = desc.Texture2DMSArray.ArraySize;
                  Texture2DMultiSampleArray.FirstArraySlice = desc.Texture2DMSArray.FirstArraySlice;
                  break;
              }
        case ShaderResourceViewDimension1::Texture3D :
              {
                  Texture3D.MipLevels = desc.Texture3D.MipLevels;
                  Texture3D.MostDetailedMip = desc.Texture3D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::TextureCube :
              {
                  TextureCube.MipLevels = desc.TextureCube.MipLevels;
                  TextureCube.MostDetailedMip = desc.TextureCube.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::TextureCubeArray :
              {
                  TextureCubeArray.First2DArrayFace = desc.TextureCubeArray.First2DArrayFace;
                  TextureCubeArray.MipLevels = desc.TextureCubeArray.MipLevels;
                  TextureCubeArray.MostDetailedMip = desc.TextureCubeArray.MostDetailedMip;
                  TextureCubeArray.NumCubes = desc.TextureCubeArray.NumCubes;
                  break;
              }
        default:
              {
                  throw gcnew NotSupportedException("Unknown or not supported ViewDimension.");
              }
        }
    }

    void CopyTo(D3D10_SHADER_RESOURCE_VIEW_DESC1* desc)
    {
        desc->Format = static_cast<DXGI_FORMAT>(Format);
        desc->ViewDimension = static_cast<D3D10_SRV_DIMENSION1>(ViewDimension);

        switch (ViewDimension)
        {
        case ShaderResourceViewDimension1::Buffer :
               {
                   desc->Buffer.ElementOffset = Buffer.ElementOffset;
                   desc->Buffer.ElementWidth = Buffer.ElementWidth;
                   break;
               }
        case ShaderResourceViewDimension1::Texture1D :
              {
                  desc->Texture1D.MipLevels = Texture1D.MipLevels;
                  desc->Texture1D.MostDetailedMip = Texture1D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture1DArray :
              {
                  desc->Texture1DArray.ArraySize = Texture1DArray.ArraySize;
                  desc->Texture1DArray.FirstArraySlice = Texture1DArray.FirstArraySlice;
                  desc->Texture1DArray.MipLevels = Texture1DArray.MipLevels;
                  desc->Texture1DArray.MostDetailedMip = Texture1DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2D :
              {
                  desc->Texture2D.MipLevels = Texture2D.MipLevels;
                  desc->Texture2D.MostDetailedMip = Texture2D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2DArray :
              {
                  desc->Texture2DArray.ArraySize = Texture2DArray.ArraySize;
                  desc->Texture2DArray.FirstArraySlice = Texture2DArray.FirstArraySlice;
                  desc->Texture2DArray.MipLevels = Texture2DArray.MipLevels;
                  desc->Texture2DArray.MostDetailedMip = Texture2DArray.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2DMultiSample :
              {
                  desc->Texture2DMS.UnusedField_NothingToDefine = Texture2DMultiSample.UnusedField;
                  break;
              }
        case ShaderResourceViewDimension1::Texture2DMultiSampleArray :
              {
                  desc->Texture2DMSArray.ArraySize = Texture2DMultiSampleArray.ArraySize;
                  desc->Texture2DMSArray.FirstArraySlice = Texture2DMultiSampleArray.FirstArraySlice;
                  break;
              }
        case ShaderResourceViewDimension1::Texture3D :
              {
                  desc->Texture3D.MipLevels = Texture3D.MipLevels;
                  desc->Texture3D.MostDetailedMip = Texture3D.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::TextureCube :
              {
                  desc->TextureCube.MipLevels = TextureCube.MipLevels;
                  desc->TextureCube.MostDetailedMip = TextureCube.MostDetailedMip;
                  break;
              }
        case ShaderResourceViewDimension1::TextureCubeArray :
              {
                  desc->TextureCubeArray.First2DArrayFace = TextureCubeArray.First2DArrayFace;
                  desc->TextureCubeArray.MipLevels = TextureCubeArray.MipLevels;
                  desc->TextureCubeArray.MostDetailedMip = TextureCubeArray.MostDetailedMip;
                  desc->TextureCubeArray.NumCubes = TextureCubeArray.NumCubes;
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
/// Describes a shader-variable type.
/// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC)</para>
/// </summary>
public value struct ShaderTypeDescription 
{
public:
    /// <summary>
    /// Identifies the variable class as one of scalar, vector, matrix or object. See ShaderVariableClass.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Class)</para>
    /// </summary>
    ShaderVariableClass Class;
    /// <summary>
    /// The variable type. See ShaderVariableType.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Type)</para>
    /// </summary>
    ShaderVariableType Type;
    /// <summary>
    /// Number of rows in a matrix. Otherwise a numeric type returns 1, any other type returns 0.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Rows)</para>
    /// </summary>
    UInt32 Rows;
    /// <summary>
    /// Number of columns in a matrix. Otherwise a numeric type returns 1, any other type returns 0.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Columns)</para>
    /// </summary>
    UInt32 Columns;
    /// <summary>
    /// Number of elements in an array; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Elements)</para>
    /// </summary>
    UInt32 Elements;
    /// <summary>
    /// Number of members in the structure; otherwise 0.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Members)</para>
    /// </summary>
    UInt32 Members;
    /// <summary>
    /// Offset, in bytes, between the start of the parent structure and this variable.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_TYPE_DESC.Offset)</para>
    /// </summary>
    UInt32 Offset;
};
/// <summary>
/// Describes a shader variable.
/// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_DESC)</para>
/// </summary>
public value struct ShaderVariableDescription 
{
public:
    /// <summary>
    /// The variable name.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_DESC.Name)</para>
    /// </summary>
    String^ Name;
    /// <summary>
    /// Offset from the start of the parent structure, to the beginning of the variable.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_DESC.StartOffset)</para>
    /// </summary>
    UInt32 StartOffset;
    /// <summary>
    /// Size of the variable (in bytes).
    /// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_DESC.Size)</para>
    /// </summary>
    UInt32 Size;
    /// <summary>
    /// Flags, which identify shader-variable properties (see <see cref="ShaderVariableFlags"/>)<seealso cref="ShaderVariableFlags"/>.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_DESC.uFlags)</para>
    /// </summary>
    ShaderVariableFlags Flags;
    /// <summary>
    /// The default value for initializing the variable.
    /// <para>(Also see DirectX SDK: D3D10_SHADER_VARIABLE_DESC.DefaultValue)</para>
    /// </summary>
    array<unsigned char>^ DefaultValue;

internal:
    ShaderVariableDescription(const D3D10_SHADER_VARIABLE_DESC & desc)
    {
        Name = desc.Name ? gcnew String(desc.Name) : nullptr;
        StartOffset = desc.StartOffset;
        Size = desc.Size;
        Flags = static_cast<ShaderVariableFlags>(desc.uFlags);
        if (desc.Size > 0)
        {
            DefaultValue = gcnew array<unsigned char>(desc.Size);
            pin_ptr<unsigned char> ptr = &DefaultValue[0];
            memcpy(ptr, desc.DefaultValue, desc.Size);
        }
    }
};
/// <summary>
/// Describes a shader signature.
/// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC)</para>
/// </summary>
public value struct SignatureParameterDescription 
{
public:
    /// <summary>
    /// A per-parameter string that identifies how the data will be used. See Semantics (DirectX HLSL).
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.SemanticName)</para>
    /// </summary>
    String^ SemanticName;
    /// <summary>
    /// Semantic index that modifies the semantic. Used to differentiate different parameters that use the same semantic.
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.SemanticIndex)</para>
    /// </summary>
    UInt32 SemanticIndex;
    /// <summary>
    /// The register that will contain this variable's data.
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.Register)</para>
    /// </summary>
    UInt32 Register;
    /// <summary>
    /// A predefined string that determines the functionality of certain pipeline stages. See Name.
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.SystemValueType)</para>
    /// </summary>
    Name SystemValueType;
    /// <summary>
    /// The per-component-data type that is stored in a register. See RegisterComponentType. Each register can store up to four-components of data.
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.ComponentType)</para>
    /// </summary>
    RegisterComponentType ComponentType;
    /// <summary>
    /// Mask which indicates which components of a register are used.
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.Mask)</para>
    /// </summary>
    unsigned char Mask;
    /// <summary>
    /// Mask which indicates whether a given component is never written (if the signature is an output signature) or always read (if the signature is an input signature). 
    /// The mask is a combination of RegisterComponentType values.
    /// <para>(Also see DirectX SDK: D3D10_SIGNATURE_PARAMETER_DESC.ReadWriteMask)</para>
    /// </summary>
    unsigned char ReadWriteMask;
internal:
    SignatureParameterDescription(const D3D10_SIGNATURE_PARAMETER_DESC& desc)
    {
        SemanticName = desc.SemanticName ? gcnew String(desc.SemanticName) : nullptr;
        SemanticIndex = desc.SemanticIndex;
        Register = desc.Register;
        SystemValueType = static_cast<Name>(desc.SystemValueType);
        ComponentType = static_cast<RegisterComponentType>(desc.ComponentType);
        Mask = desc.Mask;
        ReadWriteMask = desc.ReadWriteMask;
    }
};
/// <summary>
/// Description of a vertex element in a vertex buffer in an output slot.
/// <para>(Also see DirectX SDK: D3D10_SO_DECLARATION_ENTRY)</para>
/// </summary>
public value struct StreamOutputDeclarationEntry 
{
public:
    /// <summary>
    /// Type of output element.  Possible values: "POSITION", "NORMAL", or "TEXCOORD0".
    /// <para>(Also see DirectX SDK: D3D10_SO_DECLARATION_ENTRY.SemanticName)</para>
    /// </summary>
    String^ SemanticName;
    /// <summary>
    /// Output element's zero-based index. Should be used if, for example, you have more than one texture coordinate stored in each vertex.
    /// <para>(Also see DirectX SDK: D3D10_SO_DECLARATION_ENTRY.SemanticIndex)</para>
    /// </summary>
    UInt32 SemanticIndex;
    /// <summary>
    /// Which component of the entry to begin writing out to. Valid values are 0 ~ 3. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.
    /// <para>(Also see DirectX SDK: D3D10_SO_DECLARATION_ENTRY.StartComponent)</para>
    /// </summary>
    Byte StartComponent;
    /// <summary>
    /// The number of components of the entry to write out to. Valid values are 1 ~ 4. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.
    /// <para>(Also see DirectX SDK: D3D10_SO_DECLARATION_ENTRY.ComponentCount)</para>
    /// </summary>
    Byte ComponentCount;
    /// <summary>
    /// The output slot that contains the vertex buffer that contains this output entry.
    /// <para>(Also see DirectX SDK: D3D10_SO_DECLARATION_ENTRY.OutputSlot)</para>
    /// </summary>
    Byte OutputSlot;
internal:
    StreamOutputDeclarationEntry(const D3D10_SO_DECLARATION_ENTRY& entry)
    {
        SemanticIndex = entry.SemanticIndex;
        StartComponent = entry.StartComponent;
        ComponentCount = entry.ComponentCount;
        OutputSlot = entry.OutputSlot;
        SemanticName = gcnew String(entry.SemanticName);
    }

    void CopyTo(D3D10_SO_DECLARATION_ENTRY * entry, marshal_context^ context)
    {
        entry->SemanticIndex = SemanticIndex;
        entry->StartComponent = StartComponent;
        entry->ComponentCount = ComponentCount;
        entry->OutputSlot = OutputSlot;
        
        String^ name = SemanticName;
        entry->SemanticName = context->marshal_as<const char*>(name);
    }
};
/// <summary>
/// Indicates the device state.
/// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK)</para>
/// </summary>
public ref class StateBlockMask 
{
public:
    /// <summary>
    /// Boolean value indicating whether to save the vertex shader state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.VS)</para>
    /// </summary>
    property bool  VertexShader
    {
        bool  get()
        {
            return nativeObject->VS != 0;
        }
    }
    /// <summary>
    /// Array of vertex-shader samplers.  The array is a multi-byte bitmask where each bit represents one sampler slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.VSSamplers)</para>
    /// </summary>
    property array<unsigned char>^ VertexShaderSamplers
    {
        array<unsigned char>^ get()
        {
            if (VSSamplersArray == nullptr)
            {
                VSSamplersArray = gcnew array<unsigned char>(VSSamplersArrayLength);

                pin_ptr<unsigned char> arr = &VSSamplersArray[0];
                memcpy(arr, nativeObject->VSSamplers, sizeof(VSSamplersArrayLength));
            }
            return VSSamplersArray;
        }
    }
    /// <summary>
    /// Array of vertex-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.VSShaderResources)</para>
    /// </summary>
    property array<unsigned char>^ VertexShaderShaderResources
    {
        array<unsigned char>^ get()
        {
            if (VSShaderResourcesArray == nullptr)
            {
                VSShaderResourcesArray = gcnew array<unsigned char>(VSShaderResourcesArrayLength);
                
                pin_ptr<unsigned char> arr = &VSShaderResourcesArray[0];
                memcpy(arr, nativeObject->VSShaderResources, sizeof(VSShaderResourcesArrayLength));
            }
            return VSShaderResourcesArray;
        }
    }
    /// <summary>
    /// Array of vertex-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.VSConstantBuffers)</para>
    /// </summary>
    property array<unsigned char>^ VertexShaderConstantBuffers
    {
        array<unsigned char>^ get()
        {
            if (VSConstantBuffersArray == nullptr)
            {
                VSConstantBuffersArray = gcnew array<unsigned char>(VSConstantBuffersArrayLength);

                pin_ptr<unsigned char> arr = &VSConstantBuffersArray[0];
                memcpy(arr, nativeObject->VSConstantBuffers, sizeof(VSConstantBuffersArrayLength));
            }
            return VSConstantBuffersArray;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the geometry shader state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.GS)</para>
    /// </summary>
    property bool GeometryShader
    {
        bool get()
        {
            return nativeObject->GS != 0;
        }
    }
    /// <summary>
    /// Array of geometry-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.GSSamplers)</para>
    /// </summary>
    property array<unsigned char>^ GeometryShaderSamplers
    {
        array<unsigned char>^ get()
        {
            if (GSSamplersArray == nullptr)
            {
                GSSamplersArray = gcnew array<unsigned char>(GSSamplersArrayLength);
                
                pin_ptr<unsigned char> arr = &GSSamplersArray[0];
                memcpy(arr, nativeObject->GSSamplers, sizeof(GSSamplersArrayLength));
            }
            return GSSamplersArray;
        }
    }
    /// <summary>
    /// Array of geometry-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.GSShaderResources)</para>
    /// </summary>
    property array<unsigned char>^ GeometryShaderShaderResources
    {
        array<unsigned char>^ get()
        {
            if (GSShaderResourcesArray == nullptr)
            {
                GSShaderResourcesArray = gcnew array<unsigned char>(GSShaderResourcesArrayLength);

                pin_ptr<unsigned char> arr = &GSShaderResourcesArray[0];
                memcpy(arr, nativeObject->GSShaderResources, sizeof(GSShaderResourcesArrayLength));
            }
            return GSShaderResourcesArray;
        }
    }
    /// <summary>
    /// Array of geometry-shader constant buffers. The array is a multi-byte bitmask where each bit represents one buffer slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.GSConstantBuffers)</para>
    /// </summary>
    property array<unsigned char>^ GeometryShaderConstantBuffers
    {
        array<unsigned char>^ get()
        {
            if (GSConstantBuffersArray == nullptr)
            {
                GSConstantBuffersArray = gcnew array<unsigned char>(GSConstantBuffersArrayLength);

                pin_ptr<unsigned char> arr = &GSConstantBuffersArray[0];
                memcpy(arr, nativeObject->GSConstantBuffers, sizeof(GSConstantBuffersArrayLength));
            }
            return GSConstantBuffersArray;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the pixel shader state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.PS)</para>
    /// </summary>
    property bool PixelShader
    {
        bool get()
        {
            return nativeObject->PS != 0;
        }
    }
    /// <summary>
    /// Array of pixel-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.PSSamplers)</para>
    /// </summary>
    property array<unsigned char>^ PixelShaderSamplers
    {
        array<unsigned char>^ get()
        {
            if (PSSamplersArray == nullptr)
            {
                PSSamplersArray = gcnew array<unsigned char>(PSSamplersArrayLength);

                pin_ptr<unsigned char> arr = &PSSamplersArray[0];
                memcpy(arr, nativeObject->PSSamplers, sizeof(PSSamplersArrayLength));
            }
            return PSSamplersArray;
        }
    }
    /// <summary>
    /// Array of pixel-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.PSShaderResources)</para>
    /// </summary>
    property array<unsigned char>^ PixelShaderShaderResources
    {
        array<unsigned char>^ get()
        {
            if (PSShaderResourcesArray == nullptr)
            {
                PSShaderResourcesArray = gcnew array<unsigned char>(PSShaderResourcesArrayLength);

                pin_ptr<unsigned char> arr = &PSShaderResourcesArray[0];
                memcpy(arr, nativeObject->PSShaderResources, sizeof(PSShaderResourcesArrayLength));
            }
            return PSShaderResourcesArray;
        }
    }
    /// <summary>
    /// Array of pixel-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.PSConstantBuffers)</para>
    /// </summary>
    property array<unsigned char>^ PixelShaderConstantBuffers
    {
        array<unsigned char>^ get()
        {
            if (PSConstantBuffersArray == nullptr)
            {
                PSConstantBuffersArray = gcnew array<unsigned char>(PSConstantBuffersArrayLength);

                pin_ptr<unsigned char> arr = &PSConstantBuffersArray[0];
                memcpy(arr, nativeObject->PSConstantBuffers, sizeof(PSConstantBuffersArrayLength));
            }
            return PSConstantBuffersArray;
        }
    }
    /// <summary>
    /// Array of vertex buffers. The array is a multi-byte bitmask where each bit represents one resource slot.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.IAVertexBuffers)</para>
    /// </summary>
    property array<unsigned char>^ InputAssemblerVertexBuffers
    {
        array<unsigned char>^ get()
        {
            if (IAVertexBuffersArray == nullptr)
            {
                IAVertexBuffersArray = gcnew array<unsigned char>(IAVertexBuffersArrayLength);

                pin_ptr<unsigned char> arr = &IAVertexBuffersArray[0];
                memcpy(arr, nativeObject->IAVertexBuffers, sizeof(IAVertexBuffersArrayLength));
            }
            return IAVertexBuffersArray;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the index buffer state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.IAIndexBuffer)</para>
    /// </summary>
    property bool InputAssemblerIndexBuffer
    {
        bool get()
        {
            return nativeObject->IAIndexBuffer != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the input layout state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.IAInputLayout)</para>
    /// </summary>
    property bool InputAssemblerInputLayout
    {
        bool get()
        {
            return nativeObject->IAInputLayout != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the primitive topology state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.IAPrimitiveTopology)</para>
    /// </summary>
    property bool InputAssemblerPrimitiveTopology
    {
        bool get()
        {
            return nativeObject->IAPrimitiveTopology != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the render targets states.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.OMRenderTargets)</para>
    /// </summary>
    property bool OutputMergerRenderTargets
    {
        bool get()
        {
            return nativeObject->OMRenderTargets != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the depth-stencil state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.OMDepthStencilState)</para>
    /// </summary>
    property bool OutputMergerDepthStencilState
    {
        bool get()
        {
            return nativeObject->OMDepthStencilState != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the blend state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.OMBlendState)</para>
    /// </summary>
    property bool OutputMergerBlendState
    {
        bool get()
        {
            return nativeObject->OMBlendState != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the viewports states.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.RSViewports)</para>
    /// </summary>
    property bool RasterizerViewports
    {
        bool get()
        {
            return nativeObject->RSViewports != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the scissor rectangles states.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.RSScissorRects)</para>
    /// </summary>
    property bool RasterizerScissorRectangles
    {
        bool get()
        {
            return nativeObject->RSScissorRects != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the rasterizer state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.RSRasterizerState)</para>
    /// </summary>
    property bool RasterizerState
    {
        bool get()
        {
            return nativeObject->RSRasterizerState != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the stream-out buffers states.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.SOBuffers)</para>
    /// </summary>
    property bool StreamOutputBuffers
    {
        bool get()
        {
            return nativeObject->SOBuffers != 0;
        }
    }
    /// <summary>
    /// Boolean value indicating whether to save the predication state.
    /// <para>(Also see DirectX SDK: D3D10_STATE_BLOCK_MASK.Predication)</para>
    /// </summary>
    property bool Predication
    {
        bool get()
        {
            return nativeObject->Predication != 0;
        }
    }
public:
    // TODO: Implement
    // static void EnableCapture(  StateBlockMask^ pMask, DeviceStateTypes stateType, UInt32 rangeStart, UInt32 rangeLength);

internal:
    StateBlockMask()
    {
        nativeObject.Set(new D3D10_STATE_BLOCK_MASK());
        ZeroMemory(nativeObject.Get(), sizeof(D3D10_STATE_BLOCK_MASK));
    }
internal:
    AutoPointer<D3D10_STATE_BLOCK_MASK> nativeObject;
internal:
    StateBlockMask(D3D10_STATE_BLOCK_MASK* pStateBlockMask)
    {
        nativeObject.Set(pStateBlockMask);
    }
private:
        static int VSSamplersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT);
        array<unsigned char>^ VSSamplersArray;
        static int VSShaderResourcesArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
        array<unsigned char>^ VSShaderResourcesArray;
        static int VSConstantBuffersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
        array<unsigned char>^ VSConstantBuffersArray;
        static int GSSamplersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT);
        array<unsigned char>^ GSSamplersArray;
        static int GSShaderResourcesArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
        array<unsigned char>^ GSShaderResourcesArray;
        static int GSConstantBuffersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
        array<unsigned char>^ GSConstantBuffersArray;
        static int PSSamplersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT);
        array<unsigned char>^ PSSamplersArray;
        static int PSShaderResourcesArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT);
        array<unsigned char>^ PSShaderResourcesArray;
        static int PSConstantBuffersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT);
        array<unsigned char>^ PSConstantBuffersArray;
        static int IAVertexBuffersArrayLength = D3D10_BYTES_FROM_BITS(D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT);
        array<unsigned char>^ IAVertexBuffersArray;
};

/// <summary>
/// Specifies data for initializing a subresource.
/// <para>(Also see DirectX SDK: D3D10_SUBRESOURCE_DATA)</para>
/// </summary>
public value struct SubresourceData 
{
public:
    /// <summary>
    /// Pointer to the initialization data.
    /// <para>(Also see DirectX SDK: D3D10_SUBRESOURCE_DATA.pSysMem)</para>
    /// </summary>
    IntPtr SysMem;
    /// <summary>
    /// Pitch of the memory (in bytes). System-memory pitch is used only for 2D and 3D texture data as it is has no meaning for the other resource types.
    /// <para>(Also see DirectX SDK: D3D10_SUBRESOURCE_DATA.SysMemPitch)</para>
    /// </summary>
    UInt32 SysMemPitch;
    /// <summary>
    /// Size of one depth level (in bytes). System-memory-slice pitch is only used for 3D texture data as it has no meaning for the other resource types.
    /// <para>(Also see DirectX SDK: D3D10_SUBRESOURCE_DATA.SysMemSlicePitch)</para>
    /// </summary>
    UInt32 SysMemSlicePitch;

internal:
    SubresourceData(const D3D10_SUBRESOURCE_DATA & subresourceData)
    {
        SysMem = IntPtr((void*)subresourceData.pSysMem);
        SysMemPitch = subresourceData.SysMemPitch;
        SysMemSlicePitch = subresourceData.SysMemSlicePitch;
    }
    void CopyTo(D3D10_SUBRESOURCE_DATA* subresourceData)
    {
        subresourceData->pSysMem = SysMem.ToPointer();
        subresourceData->SysMemPitch = SysMemPitch;
        subresourceData->SysMemSlicePitch = SysMemSlicePitch;
    }
};
/// <summary>
/// Describes an effect technique.
/// <para>(Also see DirectX SDK: D3D10_TECHNIQUE_DESC)</para>
/// </summary>
public value struct TechniqueDescription 
{
public:
    /// <summary>
    /// A string that contains the technique name; otherwise NULL.
    /// <para>(Also see DirectX SDK: D3D10_TECHNIQUE_DESC.Name)</para>
    /// </summary>
    String^ Name;
    /// <summary>
    /// The number of passes in the technique.
    /// <para>(Also see DirectX SDK: D3D10_TECHNIQUE_DESC.Passes)</para>
    /// </summary>
    UInt32 Passes;
    /// <summary>
    /// The number of annotations.
    /// <para>(Also see DirectX SDK: D3D10_TECHNIQUE_DESC.Annotations)</para>
    /// </summary>
    UInt32 Annotations;

internal:
    TechniqueDescription(const D3D10_TECHNIQUE_DESC & desc)
    {
        Annotations = desc.Annotations;
        Passes = desc.Passes;

        Name = desc.Name ? gcnew String(desc.Name) : nullptr;
    }

    void CopyTo(D3D10_TECHNIQUE_DESC* desc, marshal_context^ context)
    {
        desc->Annotations = Annotations;
        desc->Passes = Passes;

        String^ name = Name;
        desc->Name = Name == nullptr ? NULL : context->marshal_as<const char*>(name);
    }
};
/// <summary>
/// Defines the dimensions of a viewport.
/// <para>(Also see DirectX SDK: D3D10_VIEWPORT)</para>
/// </summary>
public value struct Viewport 
{
public:
    /// <summary>
    /// X position of the left hand side of the viewport. Must be between -16384 and 16383.
    /// <para>(Also see DirectX SDK: D3D10_VIEWPORT.TopLeftX)</para>
    /// </summary>
    Int32 TopLeftX;
    /// <summary>
    /// Y position of the top of the viewport. Must be between -16384 and 16383.
    /// <para>(Also see DirectX SDK: D3D10_VIEWPORT.TopLeftY)</para>
    /// </summary>
    Int32 TopLeftY;
    /// <summary>
    /// Width of the viewport. Must be between 0 and 16383.
    /// <para>(Also see DirectX SDK: D3D10_VIEWPORT.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// Height of the viewport. Must be between 0 and 16383.
    /// <para>(Also see DirectX SDK: D3D10_VIEWPORT.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// Minimum depth of the viewport. Must be between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D10_VIEWPORT.MinDepth)</para>
    /// </summary>
    Single MinDepth;
    /// <summary>
    /// Maximum depth of the viewport. Must be between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D10_VIEWPORT.MaxDepth)</para>
    /// </summary>
    Single MaxDepth;

public:
    static Boolean operator == ( Viewport a, Viewport b )
    {
        return 
            (a.Height == b.Height)  &&
            (a.MaxDepth == b.MaxDepth)  &&
            (a.MinDepth == b.MinDepth)  &&
            (a.TopLeftX == b.TopLeftX)  &&
            (a.TopLeftY == b.TopLeftY)  &&
            (a.Width == b.Width);
    }

    static Boolean operator != ( Viewport a, Viewport b )
    {
        return !(a == b);
    }

internal:
    Viewport(const D3D10_VIEWPORT& viewport)
    {
        TopLeftX = viewport.TopLeftX;
        TopLeftY = viewport.TopLeftY;
        Width = viewport.Width;
        Height = viewport.Height;
        MinDepth = viewport.MinDepth;
        MaxDepth = viewport.MaxDepth;    
    }

    operator const D3D10_VIEWPORT ()
    {
        D3D10_VIEWPORT nativeViewport;

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
