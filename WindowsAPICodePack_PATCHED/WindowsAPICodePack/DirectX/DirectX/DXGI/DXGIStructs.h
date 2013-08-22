//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;


namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI { 

    namespace DXGI = Microsoft::WindowsAPICodePack::DirectX::DXGI;

/// <summary>
/// A Luid is a 64-bit value guaranteed to be unique only on the system on which it was generated. The uniqueness of a locally unique identifier (LUID) is guaranteed only until the system is restarted. An LUID is not for direct manipulation. 
/// Applications are to use functions and structures to manipulate Luid values.
/// </summary>
public value struct Luid 
{
public:
    /// <summary>
    /// Low order bits.
    /// <para>(Also see DirectX SDK: LUID.LowPart)</para>
    /// </summary>
    Int32 LowPart;
    /// <summary>
    /// High order bits.
    /// <para>(Also see DirectX SDK: LUID.HighPart)</para>
    /// </summary>
    Int32 HighPart;

internal:
    Luid(const LUID& luid)
    {
        LowPart = luid.LowPart;
        HighPart = luid.HighPart;
    }
};

/// <summary>
/// Describes a monitor.
/// <para>(Also see Windows SDK: MONITORINFOEX)</para>
/// </summary>
public value struct MonitorInfo 
{
public:
    /// <summary>
    /// Specifies the display monitor rectangle, expressed in virtual-screen coordinates. 
    /// Note that if the monitor is not the primary display monitor, some of the rectangle's coordinates may be negative values.
    /// </summary>
    D3dRect MonitorCoordinates;

    /// <summary>
    /// Specifies the work area rectangle of the display monitor 
    /// that can be used by applications, expressed in virtual-screen coordinates. 
    /// Windows uses this rectangle to maximize an application on the monitor. 
    /// The rest of the area in MonitorRect contains system windows such as the task bar 
    /// and side bars. Note that if the monitor is not the primary display monitor, 
    /// some of the rectangle's coordinates may be negative values.
    /// </summary>
    D3dRect WorkCoordinates;

    /// <summary>
    /// Indicates if this is the primary monitor
    /// </summary>
    Boolean IsPrimaryMonitor;

    /// <summary>
    /// Handle to this monitor
    /// </summary>
    IntPtr MonitorHandle;

internal:
    MonitorInfo(HMONITOR hMon)
    {
        MONITORINFOEX pInfo;
        pInfo.cbSize = sizeof(MONITORINFOEXW);

        if (!GetMonitorInfo(hMon, &pInfo))
        {
            throw gcnew DXGIException(
                String::Format("Unable to obtain monitor info. Last Error = 0x{0:X}.", ::GetLastError()), 0);
        }

        MonitorHandle = IntPtr(hMon);
        MonitorCoordinates = D3dRect(pInfo.rcMonitor);
        WorkCoordinates = D3dRect(pInfo.rcWork);
        IsPrimaryMonitor = (pInfo.dwFlags & MONITORINFOF_PRIMARY) == MONITORINFOF_PRIMARY;
    }
};

/// <summary>
/// Represents a rational number.
/// <para>(Also see DirectX SDK: DXGI_RATIONAL)</para>
/// </summary>
public value struct Rational 
{
public:
    /// <summary>
    /// An unsigned integer value representing the top of the rational number.
    /// <para>(Also see DirectX SDK: DXGI_RATIONAL.Numerator)</para>
    /// </summary>
    UInt32 Numerator;

    /// <summary>
    /// An unsigned integer value representing the bottom of the rational number.
    /// <para>(Also see DirectX SDK: DXGI_RATIONAL.Denominator)</para>
    /// </summary>
    UInt32 Denominator;
internal:
    Rational (const DXGI_RATIONAL& rational)
    {
        Numerator = rational.Numerator;
        Denominator = rational.Denominator;
    }
};
/// <summary>
/// Represents an RGB color.
/// <para>(Also see DirectX SDK: DXGI_RGB)</para>
/// </summary>
public value struct ColorRgb
{
public:
    /// <summary>
    /// A value representing the color of the red component. The range of this value is between 0 and 1.
    /// <para>(Also see DirectX SDK: DXGI_RGB.Red)</para>
    /// </summary>
    Single Red;

    /// <summary>
    /// A value representing the color of the green component. The range of this value is between 0 and 1.
    /// <para>(Also see DirectX SDK: DXGI_RGB.Green)</para>
    /// </summary>
    Single Green;

    /// <summary>
    /// A value representing the color of the blue component. The range of this value is between 0 and 1.
    /// <para>(Also see DirectX SDK: DXGI_RGB.Blue)</para>
    /// </summary>
    Single Blue;

public:
    ColorRgb(Single red, Single green, Single blue)
    {
        Red = red;
        Green = green;
        Blue = blue;
    }

    static Boolean operator == ( ColorRgb a, ColorRgb b )
    {
        return 
            (a.Red == b.Red)  &&
            (a.Green == b.Green)  &&
            (a.Blue == b.Blue);
    }

    static Boolean operator != ( ColorRgb a, ColorRgb b )
    {
        return !(a == b);
    }
internal:
    ColorRgb(const DXGI_RGB& rgb)
    {
        Red = rgb.Red;
        Green = rgb.Green;
        Blue = rgb.Blue;
    }

   void CopyTo(DXGI_RGB* rgb)
    {
        rgb->Red = Red;
        rgb->Green = Green;
        rgb->Blue = Blue;
    }

};

/// <summary>
/// Represents an RGBA color.
/// </summary>
public value struct ColorRgba
{
public:
    /// <summary>
    /// A value representing the color of the red component. The range of this value is between 0 and 1.
    /// </summary>
    Single Red;

    /// <summary>
    /// A value representing the color of the green component. The range of this value is between 0 and 1.
    /// </summary>
    Single Green;

    /// <summary>
    /// A value representing the color of the blue component. The range of this value is between 0 and 1.
    /// </summary>
    Single Blue;

    /// <summary>
    /// A value representing the alpha channel component. The range of this value is between 0 and 1.
    /// </summary>
    Single Alpha;

public:
    ColorRgba(array<float>^ rgbaColors)
    {
        if (rgbaColors == nullptr)
        {
            throw gcnew ArgumentNullException("rgbaColors");
        }

        if (rgbaColors->Length != 4)
        {
            throw gcnew ArgumentOutOfRangeException("rgbaColors","Length of input array must be exactly \"4\".");
        }

        Red = rgbaColors[0];
        Green = rgbaColors[1];
        Blue = rgbaColors[2];
        Alpha = rgbaColors[3];
    }

    ColorRgba(Single red, Single green, Single blue, Single alpha)
    {
        Red = red;
        Green = green;
        Blue = blue;
        Alpha = alpha;
    }

    ColorRgba(Colors color)
    {
        Red = static_cast<FLOAT>((static_cast<UINT32>(color) & sc_redMask) >> sc_redShift) / 255.f;
        Green = static_cast<FLOAT>((static_cast<UINT32>(color) & sc_greenMask) >> sc_greenShift) / 255.f;
        Blue = static_cast<FLOAT>((static_cast<UINT32>(color) & sc_blueMask) >> sc_blueShift) / 255.f; 
        Alpha = 1.0f;
    }

    ColorRgba(Colors color, Single alpha)
    {
        Red = static_cast<FLOAT>((static_cast<UINT32>(color) & sc_redMask) >> sc_redShift) / 255.f;
        Green = static_cast<FLOAT>((static_cast<UINT32>(color) & sc_greenMask) >> sc_greenShift) / 255.f;
        Blue = static_cast<FLOAT>((static_cast<UINT32>(color) & sc_blueMask) >> sc_blueShift) / 255.f; 
        Alpha = alpha;
    }

    static Boolean operator == ( ColorRgba a, ColorRgba b )
    {
        return 
            (a.Red == b.Red)  &&
            (a.Green == b.Green)  &&
            (a.Blue == b.Blue)  &&
            (a.Alpha == b.Alpha);
    }

    static Boolean operator != ( ColorRgba a, ColorRgba b )
    {
        return !(a == b);
    }

internal:

    ColorRgba(const FLOAT rgbaColors[4])
    {
        Red = rgbaColors[0];
        Green = rgbaColors[1];
        Blue = rgbaColors[2];
        Alpha = rgbaColors[3];
    }

private:
    static const UINT32 sc_redShift   = 16;
    static const UINT32 sc_greenShift = 8;
    static const UINT32 sc_blueShift  = 0;    

    static const UINT32 sc_redMask = 0xff << sc_redShift;
    static const UINT32 sc_greenMask = 0xff << sc_greenShift;
    static const UINT32 sc_blueMask = 0xff << sc_blueShift;      

};

/// <summary>
/// Describes an adapter (or video card) by using DXGI 1.0.
/// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC)</para>
/// </summary>
public value struct AdapterDescription 
{
public:
    /// <summary>
    /// A string that contains the adapter description.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.Description)</para>
    /// </summary>
    String^ Description;
    /// <summary>
    /// The PCI ID of the hardware vendor.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.VendorId)</para>
    /// </summary>
    UInt32 VendorId;
    /// <summary>
    /// The PCI ID of the hardware device.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.DeviceId)</para>
    /// </summary>
    UInt32 DeviceId;
    /// <summary>
    /// The PCI ID of the sub system.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.SubSysId)</para>
    /// </summary>
    UInt32 SubSysId;
    /// <summary>
    /// The PCI ID of the revision number of the adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.Revision)</para>
    /// </summary>
    UInt32 Revision;
    /// <summary>
    /// The number of bytes of dedicated video memory that are not shared with the CPU.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.DedicatedVideoMemory)</para>
    /// </summary>
    UInt32 DedicatedVideoMemory;
    /// <summary>
    /// The number of bytes of dedicated system memory that are not shared with the GPU. This memory is allocated from available system memory at boot time.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.DedicatedSystemMemory)</para>
    /// </summary>
    UInt32 DedicatedSystemMemory;
    /// <summary>
    /// The number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.SharedSystemMemory)</para>
    /// </summary>
    UInt32 SharedSystemMemory;
    /// <summary>
    /// A unique value that identifies the adapter. See LUID for a definition of the structure. LUID is defined in dxgi.h.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.AdapterLuid)</para>
    /// </summary>
    Luid AdapterLuid;

internal:
    AdapterDescription(const DXGI_ADAPTER_DESC& adapterDescription)
    {
        VendorId = adapterDescription.VendorId;
        DeviceId = adapterDescription.DeviceId;
        SubSysId = adapterDescription.SubSysId;
        Revision = adapterDescription.Revision;
        DedicatedVideoMemory = static_cast<UInt32>(adapterDescription.DedicatedVideoMemory);
        DedicatedSystemMemory = static_cast<UInt32>(adapterDescription.DedicatedSystemMemory);
        AdapterLuid = Luid(adapterDescription.AdapterLuid);
        Description = gcnew String(adapterDescription.Description);
    }

};
/// <summary>
/// Describes an adapter (or video card) using DXGI 1.1.
/// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1)</para>
/// </summary>
public value struct AdapterDescription1 
{
public:
    /// <summary>
    /// A string that contains the adapter description.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.Description)</para>
    /// </summary>
    String^ Description;

    /// <summary>
    /// The PCI ID of the hardware vendor.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.VendorId)</para>
    /// </summary>
    UInt32 VendorId;
    /// <summary>
    /// The PCI ID of the hardware device.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.DeviceId)</para>
    /// </summary>
    UInt32 DeviceId;
    /// <summary>
    /// The PCI ID of the sub system.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.SubSysId)</para>
    /// </summary>
    UInt32 SubSysId;
    /// <summary>
    /// The PCI ID of the revision number of the adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.Revision)</para>
    /// </summary>
    UInt32 Revision;
    /// <summary>
    /// The number of bytes of dedicated video memory that are not shared with the CPU.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.DedicatedVideoMemory)</para>
    /// </summary>
    UInt32 DedicatedVideoMemory;
    /// <summary>
    /// The number of bytes of dedicated system memory that are not shared with the GPU. This memory is allocated from available system memory at boot time.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.DedicatedSystemMemory)</para>
    /// </summary>
    UInt32 DedicatedSystemMemory;
    /// <summary>
    /// The number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.SharedSystemMemory)</para>
    /// </summary>
    UInt32 SharedSystemMemory;
    /// <summary>
    /// A unique value that identifies the adapter. See LUID for a definition of the structure. LUID is defined in dxgi.h.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.AdapterLuid)</para>
    /// </summary>
    Luid AdapterLuid;
    /// <summary>
    /// A member of the AdapterFlag enumerated type that describes the adapter type.  
    /// The AdapterFlag Remote flag specifies that the adapter is a remote adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.Flags)</para>
    /// </summary>
    AdapterFlag Flags;
internal:
    AdapterDescription1(const DXGI_ADAPTER_DESC1& adapterDescription)
    {
        VendorId = adapterDescription.VendorId;
        DeviceId = adapterDescription.DeviceId;
        SubSysId = adapterDescription.SubSysId;
        Revision = adapterDescription.Revision;
        DedicatedVideoMemory = static_cast<UInt32>(adapterDescription.DedicatedVideoMemory);
        DedicatedSystemMemory = static_cast<UInt32>(adapterDescription.DedicatedSystemMemory);
        AdapterLuid = Luid(adapterDescription.AdapterLuid);
        Description = gcnew String(adapterDescription.Description);
        // For DXGI 1.1
        Flags = static_cast<AdapterFlag>(adapterDescription.Flags);
    }
};

/// <summary>
/// Describes timing and presentation statistics for a frame.
/// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS)</para>
/// </summary>
public value struct FrameStatistics 
{
public:
    /// <summary>
    /// A value representing the running total count of times that an image has been presented to the monitor since the computer booted. Note that the number of times that an image has been presented to the monitor is not necessarily the same as the number of times that SwapChain.Present has been called.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.PresentCount)</para>
    /// </summary>
    UInt32 PresentCount;
    /// <summary>
    /// A value representing  the running total count of v-blanks that have happened since the computer booted.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.PresentRefreshCount)</para>
    /// </summary>
    UInt32 PresentRefreshCount;
    /// <summary>
    /// A value representing  the running total count of v-blanks that have happened since the computer booted.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.SyncRefreshCount)</para>
    /// </summary>
    UInt32 SyncRefreshCount;
    /// <summary>
    /// A value representing the high-resolution performance counter timer. 
    /// This value is that same as the value returned by the QueryPerformanceCounter function.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.SyncQPCTime)</para>
    /// </summary>
    Int64 SyncQueryPerformanceCounterTime;
    /// <summary>
    /// Reserved. Always returns 0.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.SyncGPUTime)</para>
    /// </summary>
    Int64 SyncGPUTime;

internal:
    FrameStatistics(const DXGI_FRAME_STATISTICS & frameStatistics)
    {
        PresentCount = frameStatistics.PresentCount;
        PresentRefreshCount = frameStatistics.PresentRefreshCount;
        SyncRefreshCount = frameStatistics.SyncRefreshCount;
        SyncQueryPerformanceCounterTime = frameStatistics.SyncQPCTime.QuadPart;
        SyncGPUTime = frameStatistics.SyncGPUTime.QuadPart;
    }
};
/// <summary>
/// Controls the settings of a gamma curve.
/// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL)</para>
/// </summary>
public value struct GammaControl 
{
public:
    /// <summary>
    /// A ColorRGB structure with scalar values that are applied to rgb values before being sent to the gamma look up table.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL.Scale)</para>
    /// </summary>
    ColorRgb Scale;
    /// <summary>
    /// A ColorRGB structure with offset values that are applied to the rgb values before being sent to the gamma look up table.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL.offset)</para>
    /// </summary>
    ColorRgb Offset;
    /// <summary>
    /// A collection of ColorRGB structures that control the points of a gamma curve.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL.GammaCurve)</para>
    /// </summary>
    property array<ColorRgb>^ GammaCurve
    {
        array<ColorRgb>^ get()
        {
            if (gammaCurveArray == nullptr)
            {
                gammaCurveArray = gcnew array<ColorRgb>(GammaCurveArrayLength);
            }
            return gammaCurveArray;
        }
    }
internal:
    literal int GammaCurveArrayLength = 1025;
    GammaControl(const DXGI_GAMMA_CONTROL & gammaControl)
    {
        Scale = ColorRgb(gammaControl.Scale);
        Offset = ColorRgb(gammaControl.Offset);
        gammaCurveArray = gcnew array<ColorRgb>(GammaCurveArrayLength); 

        pin_ptr<ColorRgb> gammaCurveArrayPtr = &gammaCurveArray[0];
        memcpy(gammaCurveArrayPtr, gammaControl.GammaCurve, sizeof (DXGI_RGB) * GammaCurveArrayLength);
    }

    void CopyTo(DXGI_GAMMA_CONTROL * gammaControl)
    {
        DXGI_RGB scale;
        DXGI_RGB offset;

        Scale.CopyTo(&scale);
        Offset.CopyTo(&offset);

        if (gammaCurveArray != nullptr)
        {
            pin_ptr<ColorRgb> gammaCurveArrayPtr = &gammaCurveArray[0];
            memcpy(gammaControl->GammaCurve, gammaCurveArrayPtr, sizeof (DXGI_RGB) * GammaCurveArrayLength);
        }
        else
        {
            ZeroMemory(gammaControl->GammaCurve, sizeof (DXGI_RGB) * GammaCurveArrayLength);
        }
    }

private:
    array<ColorRgb>^ gammaCurveArray;

};
/// <summary>
/// Controls the gamma capabilities of an adapter.
/// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES)</para>
/// </summary>
public value struct GammaControlCapabilities 
{
public:
    /// <summary>
    /// True if scaling and offset operations are supported during gamma correction; otherwise, false.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.ScaleAndOffsetSupported)</para>
    /// </summary>
    Boolean ScaleAndOffsetSupported;

    /// <summary>
    /// A value describing the maximum range of the control-point positions.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.MaxConvertedValue)</para>
    /// </summary>
    Single MaxConvertedValue;

    /// <summary>
    /// A value describing the minimum range of the control-point positions.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.MinConvertedValue)</para>
    /// </summary>
    Single MinConvertedValue;

    /// <summary>
    /// A value describing the number of control points in the array.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.NumGammaControlPoints)</para>
    /// </summary>
    UInt32 NumGammaControlPoints;

    /// <summary>
    /// A collection of values describing control points; the maximum length of control points is 1025.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.ControlPointPositions)</para>
    /// </summary>
    property array<Single>^ ControlPointPositions
    {
        array<Single>^ get()
        {
            if (controlPointsPositions == nullptr)
            {
                controlPointsPositions = gcnew array<Single>(ControlPointPositionsArrayLength);
            }
            return controlPointsPositions;
        }
    }
internal:
    literal int ControlPointPositionsArrayLength = 1025;
    GammaControlCapabilities(const DXGI_GAMMA_CONTROL_CAPABILITIES & gammaControlCapabilities)
    {
        MaxConvertedValue = gammaControlCapabilities.MaxConvertedValue;
        MinConvertedValue = gammaControlCapabilities.MinConvertedValue;
        NumGammaControlPoints = gammaControlCapabilities.NumGammaControlPoints;
        ScaleAndOffsetSupported = gammaControlCapabilities.ScaleAndOffsetSupported != 0;
        
        controlPointsPositions = gcnew array<Single>(ControlPointPositionsArrayLength); 

        pin_ptr<Single> controlPointsPositionsPtr = &controlPointsPositions[0];
        memcpy(controlPointsPositionsPtr, gammaControlCapabilities.ControlPointPositions, sizeof (FLOAT) * ControlPointPositionsArrayLength);
    }

private:
    array<Single>^ controlPointsPositions;

};
/// <summary>
/// A mapped rectangle used for accessing a surface.
/// <para>(Also see DirectX SDK: DXGI_MAPPED_RECT)</para>
/// </summary>
public value struct MappedRect 
{
public:
    /// <summary>
    /// A value describing the width of the surface.
    /// <para>(Also see DirectX SDK: DXGI_MAPPED_RECT.Pitch)</para>
    /// </summary>
    Int32 Pitch;
    /// <summary>
    /// The image buffer of the surface.
    /// <para>(Also see DirectX SDK: DXGI_MAPPED_RECT.pBits)</para>
    /// </summary>
    IntPtr Bits;

internal:
    MappedRect(const DXGI_MAPPED_RECT& mappedRect)
    {
        Pitch = mappedRect.Pitch;
        Bits = IntPtr(mappedRect.pBits);
    }
};
/// <summary>
/// Describes a display mode.
/// <para>(Also see DirectX SDK: DXGI_MODE_DESC)</para>
/// </summary>
public value struct ModeDescription 
{
public:
    /// <summary>
    /// A value describing the resolution width.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// A value describing the resolution height.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// A Rational structure describing the refresh rate in hertz
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.RefreshRate)</para>
    /// </summary>
    Rational RefreshRate;
    /// <summary>
    /// A Format structure describing the display format.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// A member of the ModeScanlineOrder enumerated type describing the scanline drawing mode.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.ScanlineOrdering)</para>
    /// </summary>
    ModeScanlineOrder ScanlineOrdering;
    /// <summary>
    /// A member of the ModeScaling enumerated type describing the scaling mode.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Scaling)</para>
    /// </summary>
    ModeScaling Scaling;

internal:
    ModeDescription(const DXGI_MODE_DESC& modeDescription)
    {
        Width = modeDescription.Width;
        Height = modeDescription.Height;
        RefreshRate.Numerator = modeDescription.RefreshRate.Numerator;
        RefreshRate.Denominator = modeDescription.RefreshRate.Denominator;
        Format = static_cast<DXGI::Format>(modeDescription.Format);
        ScanlineOrdering = static_cast<ModeScanlineOrder>(modeDescription.ScanlineOrdering);
        Scaling = static_cast<ModeScaling>(modeDescription.Scaling);
    }

    void CopyTo(DXGI_MODE_DESC* modeDescription)
    {
        modeDescription->Width = Width;
        modeDescription->Height = Height;
        modeDescription->RefreshRate.Numerator = RefreshRate.Numerator;
        modeDescription->RefreshRate.Denominator = RefreshRate.Denominator;
        modeDescription->Format = static_cast<DXGI_FORMAT>(Format);
        modeDescription->ScanlineOrdering = static_cast<DXGI_MODE_SCANLINE_ORDER>(ScanlineOrdering);
        modeDescription->Scaling = static_cast<DXGI_MODE_SCALING>(Scaling);
    }
};
/// <summary>
/// Describes an output or physical connection between the adapter (video card) and a device.
/// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC)</para>
/// </summary>
public value struct OutputDescription 
{
public:
    /// <summary>
    /// A string that contains the name of the output device.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.DeviceName)</para>
    /// </summary>
    String^ DeviceName;
    /// <summary>
    /// A RECT structure containing the bounds of the output in desktop coordinates.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.DesktopCoordinates)</para>
    /// </summary>
    D3dRect DesktopCoordinates;
    /// <summary>
    /// True if the output is attached to the desktop; otherwise, false.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.AttachedToDesktop)</para>
    /// </summary>
    Boolean AttachedToDesktop;
    /// <summary>
    /// A member of the ModeRotation enumerated type describing on how an image is rotated by the output.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.Rotation)</para>
    /// </summary>
    ModeRotation Rotation;
    /// <summary>
    /// An HMONITOR handle that represents the display monitor. For more information, see HMONITOR and the Device Context.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.Monitor)</para>
    /// </summary>
    MonitorInfo Monitor;
internal:
    OutputDescription(const DXGI_OUTPUT_DESC& outputDescription)
    {
        DeviceName = gcnew String(outputDescription.DeviceName);
        DesktopCoordinates = D3dRect(outputDescription.DesktopCoordinates);
        AttachedToDesktop = outputDescription.AttachedToDesktop != 0;
        Rotation = static_cast<ModeRotation>(outputDescription.Rotation);
        Monitor = MonitorInfo(outputDescription.Monitor);
    }
};
/// <summary>
/// Describes multi-sampling parameters for a resource.
/// <para>(Also see DirectX SDK: DXGI_SAMPLE_DESC)</para>
/// </summary>
public value struct SampleDescription
{
public:
    /// <summary>
    /// The number of multisamples per pixel.
    /// <para>(Also see DirectX SDK: DXGI_SAMPLE_DESC.Count)</para>
    /// </summary>
    UInt32 Count;
    /// <summary>
    /// The image quality level. The higher the quality, the lower the performance. The valid range is between zero and one less than the level returned         by Device.CheckMultiSampleQualityLevels.
    /// <para>(Also see DirectX SDK: DXGI_SAMPLE_DESC.Quality)</para>
    /// </summary>
    UInt32 Quality;
internal:
    SampleDescription(const DXGI_SAMPLE_DESC& sampleDescription)
    {
        Count = sampleDescription.Count;
        Quality = sampleDescription.Quality;
    }
};
/// <summary>
/// Represents a handle to a shared resource.
/// <para>(Also see DirectX SDK: DXGI_SHARED_RESOURCE)</para>
/// </summary>
public value struct SharedResource 
{
public:
    /// <summary>
    /// A handle to a shared resource.
    /// <para>(Also see DirectX SDK: DXGI_SHARED_RESOURCE.Handle)</para>
    /// </summary>
    IntPtr Handle;
internal:
    SharedResource(const DXGI_SHARED_RESOURCE & sharedResource)
    {
        Handle = IntPtr(sharedResource.Handle);
    }
};
/// <summary>
/// Describes a surface.
/// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC)</para>
/// </summary>
public value struct SurfaceDescription 
{
public:
    /// <summary>
    /// A value describing the surface width.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.Width)</para>
    /// </summary>
    UInt32 Width;
    /// <summary>
    /// A value describing the surface height.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.Height)</para>
    /// </summary>
    UInt32 Height;
    /// <summary>
    /// A member of the Format enumerated type that describes the surface format.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.Format)</para>
    /// </summary>
    DXGI::Format Format;
    /// <summary>
    /// A member of the SampleDescription structure that describes multi-sampling parameters for the surface.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.SampleDesc)</para>
    /// </summary>
    DXGI::SampleDescription SampleDescription;

internal:
    SurfaceDescription(const DXGI_SURFACE_DESC & surfaceDescription)
    {
        Width = surfaceDescription.Width;
        Height = surfaceDescription.Height;
        Format = static_cast<DXGI::Format>(surfaceDescription.Format);
        SampleDescription.Count = surfaceDescription.SampleDesc.Count;        
        SampleDescription.Quality = surfaceDescription.SampleDesc.Quality;
    }
};
/// <summary>
/// Describes a swap chain.
/// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC)</para>
/// </summary>
public value struct SwapChainDescription 
{
public:
    /// <summary>
    /// A ModeDescription structure describing the backbuffer display mode.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.BufferDesc)</para>
    /// </summary>
    ModeDescription BufferDescription;
    /// <summary>
    /// A SampleDescription structure describing multi-sampling parameters.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.SampleDesc)</para>
    /// </summary>
    DXGI::SampleDescription SampleDescription;
    /// <summary>
    /// A member of the UsageOption enumerated type describing the surface usage and CPU access options for the back buffer. The back buffer can be used for shader input or render-target output.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.BufferUsage)</para>
    /// </summary>
    UsageOption BufferUsage;
    /// <summary>
    /// A value that describes the number of buffers in the swap chain, including the front buffer.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.BufferCount)</para>
    /// </summary>
    UInt32 BufferCount;
    /// <summary>
    /// An HWND handle to the output window. This member must a valid window handle.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.OutputWindow)</para>
    /// </summary>
    IntPtr OutputWindowHandle;
    /// <summary>
    /// True if the output is in windowed mode; otherwise, false. For more information, see DXGIFactory.CreateSwapChain.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.Windowed)</para>
    /// </summary>
    Boolean Windowed;
    /// <summary>
    /// A member of the SwapEffect enumerated type that describes options for handling the contents of the presentation buffer after         presenting a surface.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.SwapEffect)</para>
    /// </summary>
    DXGI::SwapEffect SwapEffect;
    /// <summary>
    /// A member of the SwapChainFlag enumerated type that describes options for swap-chain behavior.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.Flags)</para>
    /// </summary>
    SwapChainFlag Flags;

internal:
    SwapChainDescription(const DXGI_SWAP_CHAIN_DESC& swapChainDescription)
    {
        BufferDescription = ModeDescription(swapChainDescription.BufferDesc);
        SampleDescription = DXGI::SampleDescription(swapChainDescription.SampleDesc);
        BufferUsage = static_cast<UsageOption>(swapChainDescription.BufferUsage);
        OutputWindowHandle = IntPtr(swapChainDescription.OutputWindow);
        Windowed = swapChainDescription.Windowed != 0;
        SwapEffect = static_cast<DXGI::SwapEffect>(swapChainDescription.SwapEffect);
        Flags = static_cast<SwapChainFlag>(swapChainDescription.Flags);
        BufferCount = swapChainDescription.BufferCount;
    }

    void CopyTo(DXGI_SWAP_CHAIN_DESC* pSwapChainDescription)
    {
        pSwapChainDescription->BufferDesc.Format = static_cast<DXGI_FORMAT>(BufferDescription.Format);
        pSwapChainDescription->BufferDesc.Height = BufferDescription.Height;
        pSwapChainDescription->BufferDesc.Width = BufferDescription.Width;
        pSwapChainDescription->BufferDesc.RefreshRate.Denominator  = BufferDescription.RefreshRate.Denominator;
        pSwapChainDescription->BufferDesc.RefreshRate.Numerator = BufferDescription.RefreshRate.Numerator;
        pSwapChainDescription->BufferDesc.Scaling = static_cast<DXGI_MODE_SCALING>(BufferDescription.Scaling);
        pSwapChainDescription->BufferDesc.ScanlineOrdering = static_cast<DXGI_MODE_SCANLINE_ORDER>(BufferDescription.ScanlineOrdering);

        pSwapChainDescription->SampleDesc.Count = SampleDescription.Count;
        pSwapChainDescription->SampleDesc.Quality = SampleDescription.Quality;
        
        pSwapChainDescription->BufferUsage = static_cast<DXGI_USAGE>(BufferUsage);
        pSwapChainDescription->BufferCount = BufferCount;
        pSwapChainDescription->OutputWindow = static_cast<HWND>(OutputWindowHandle.ToPointer());
        pSwapChainDescription->Windowed = Windowed ? 1 : 0;
        pSwapChainDescription->SwapEffect = static_cast<DXGI_SWAP_EFFECT>(SwapEffect);
        pSwapChainDescription->Flags = static_cast<UINT>(Flags);
    }
};
} } } }
