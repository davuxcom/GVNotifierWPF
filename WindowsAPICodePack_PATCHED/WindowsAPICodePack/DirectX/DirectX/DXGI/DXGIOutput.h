//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {
ref class D3DDevice;
}}}}

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {
ref class D3DDevice;
}}}}

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;
using namespace System::Collections::ObjectModel;

ref class Surface;
ref class DXGIDevice;

    /// <summary>
    /// An Output interface represents an adapter output (such as a monitor).
    /// <para>(Also see DirectX SDK: IDXGIOutput)</para>
    /// </summary>
    public ref class Output :
        public DXGIObject
    {
    public: 
        /// <summary>
        /// Find the display mode that most closely matches the requested display mode 
        /// for a given Direct3D Device.
        /// <para>(Also see DirectX SDK: IDXGIOutput::FindClosestMatchingMode)</para>
        /// </summary>
        /// <param name="modeToMatch">The desired display mode (see <see cref="ModeDescription"/>)<seealso cref="ModeDescription"/>. Members of ModeDescription can be unspecified indicating no preference for that member.  A value of 0 for Width or Height indicates the value is unspecified.  If either Width or Height are 0 both must be 0.  A numerator and denominator of 0 in RefreshRate indicate it is unspecified. Other members of ModeDescription have enumeration values indicating the member is unspecified.  If pConnectedDevice is null, Format cannot be UNKNOWN.</param>
        /// <param name="concernedDevice">The Direct3D device object. If this parameter is NULL, only modes whose format matches that of pModeToMatch will         be returned; otherwise, only those formats that are supported for scan-out by the device are returned.</param>
        /// <returns>The mode that most closely matches ModeToMatch.</returns>
        ModeDescription FindClosestMatchingMode(ModeDescription modeToMatch, Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ concernedDevice);

        /// <summary>
        /// Find the display mode that most closely matches the requested display mode 
        /// for a given Direct3D Device.
        /// <para>(Also see DirectX SDK: IDXGIOutput::FindClosestMatchingMode)</para>
        /// </summary>
        /// <param name="modeToMatch">The desired display mode (see <see cref="ModeDescription"/>)<seealso cref="ModeDescription"/>. Members of ModeDescription can be unspecified indicating no preference for that member.  A value of 0 for Width or Height indicates the value is unspecified.  If either Width or Height are 0 both must be 0.  A numerator and denominator of 0 in RefreshRate indicate it is unspecified. Other members of ModeDescription have enumeration values indicating the member is unspecified.  If pConnectedDevice is null, Format cannot be UNKNOWN.</param>
        /// <param name="concernedDevice">The Direct3D device object. If this parameter is NULL, only modes whose format matches that of pModeToMatch will         be returned; otherwise, only those formats that are supported for scan-out by the device are returned.</param>
        /// <returns>The mode that most closely matches ModeToMatch.</returns>
        ModeDescription FindClosestMatchingMode(ModeDescription modeToMatch, Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ concernedDevice);
        
        /// <summary>
        /// Find the display mode that most closely matches the requested display mode.
        /// <para>(Also see DirectX SDK: IDXGIOutput::FindClosestMatchingMode)</para>
        /// </summary>
        /// <param name="modeToMatch">The desired display mode (see <see cref="ModeDescription"/>)<seealso cref="ModeDescription"/>. Members of ModeDescription can be unspecified indicating no preference for that member.  A value of 0 for Width or Height indicates the value is unspecified.  If either Width or Height are 0 both must be 0.  A numerator and denominator of 0 in RefreshRate indicate it is unspecified. Other members of ModeDescription have enumeration values indicating the member is unspecified. Format cannot be UNKNOWN.</param>
        /// <returns>The mode that most closely matches ModeToMatch.</returns>
        ModeDescription FindClosestMatchingMode(ModeDescription modeToMatch);

        /// <summary>
        /// Get a description of the output.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetDesc)</para>
        /// </summary>
        property OutputDescription Description
        {
            OutputDescription get();
        }

        /// <summary>
        /// Gets the display modes that match the requested format and other input options.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetDisplayModeList)</para>
        /// </summary>
        /// <param name="colorFormat">The color format (see <see cref="Format"/>)<seealso cref="Format"/>.</param>
        /// <param name="flags">Options for modes to include (see <see cref="EnumModes"/>)<seealso cref="EnumModes"/>. EnumModes.Scaling needs to be specified to expose the display modes that require scaling.  Centered modes, requiring no scaling and corresponding directly to the display output, are enumerated by default.</param>
        /// <returns>An aray of display modes (see <see cref="ModeDescription"/>)<seealso cref="ModeDescription"/> or null if no modes were found.</returns>
        array<ModeDescription>^ GetDisplayModeList(Format colorFormat, EnumModes flags);

        /// <summary>
        /// Gets the display modes that match the requested format and other input options.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetDisplayModeList)</para>
        /// </summary>
        /// <param name="colorFormat">The color format (see <see cref="Format"/>)<seealso cref="Format"/>.</param>
        /// <param name="flags">Options for modes to include (see <see cref="EnumModes"/>)<seealso cref="EnumModes"/>. EnumModes.Scaling needs to be specified to expose the display modes that require scaling.  Centered modes, requiring no scaling and corresponding directly to the display output, are enumerated by default.</param>
        /// <returns>The number of display modes (see <see cref="ModeDescription"/>) that matches the format and options.<seealso cref="ModeDescription"/></returns>
        UInt32 GetNumberOfDisplayModes(Format colorFormat, EnumModes flags);

        /// <summary>
        /// Get a copy of the current display surface.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetDisplaySurfaceData)</para>
        /// </summary>
        /// <remarks>
        /// GetDisplaySurfaceData can only be called when an output is in full-screen mode. 
        /// If the method succeeds, the destination surface will be filled and its reference count incremented. 
        /// </remarks>
        /// <param name="Destination">A destination surface (see <see cref="Surface"/>)<seealso cref="Surface"/>.</param>
        void GetDisplaySurfaceData(Surface^ Destination);

        /// <summary>
        /// Get statistics about recently rendered frames.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetFrameStatistics)</para>
        /// </summary>
        FrameStatistics GetRenderedFrameStatistics();

        /// <summary>
        /// Gets the gamma control settings.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetGammaControl)</para>
        /// </summary>
        GammaControl GetGammaControl();

        /// <summary>
        /// Sets the gamma control settings.
        /// <para>(Also see DirectX SDK: IDXGIOutput::SetGammaControl)</para>
        /// </summary>
        /// <param name="gammaControl">Gamma control settings.</param>
        void SetGammaControl(GammaControl gammaControl);

        /// <summary>
        /// Get a description of the gamma-control capabilities.
        /// <para>(Also see DirectX SDK: IDXGIOutput::GetGammaControlCapabilities)</para>
        /// </summary>
        GammaControlCapabilities GetGammaControlCapabilities();

        /// <summary>
        /// Change the display mode.
        /// <para>(Also see DirectX SDK: IDXGIOutput::SetDisplaySurface)</para>
        /// </summary>
        /// <param name="ScanoutSurface">A surface (see <see cref="Surface"/>)<seealso cref="Surface"/> used for rendering an image to the screen. The surface must have been created with as a back buffer (DXGI_USAGE_BACKBUFFER).</param>
        void SetDisplaySurface(Surface^ ScanoutSurface);

        /// <summary>
        /// Release ownership of the output.
        /// <para>(Also see DirectX SDK: IDXGIOutput::ReleaseOwnership)</para>
        /// </summary>
        void ReleaseOwnership();

        /// <summary>
        /// Take ownership of an output.
        /// <para>(Also see DirectX SDK: IDXGIOutput::TakeOwnership)</para>
        /// </summary>
        /// <param name="device">A Direct3D 10 Device.</param>
        /// <param name="exclusive">Set to TRUE to enable other threads or applications to take ownership of the device; otherwise set to FALSE.</param>
        void TakeOwnership(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ device, Boolean exclusive);

        /// <summary>
        /// Take ownership of an output.
        /// <para>(Also see DirectX SDK: IDXGIOutput::TakeOwnership)</para>
        /// </summary>
        /// <param name="device">A Direct3D 11 Device.</param>
        /// <param name="exclusive">Set to TRUE to enable other threads or applications to take ownership of the device; otherwise set to FALSE.</param>
        void TakeOwnership(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ device, Boolean exclusive);

        /// <summary>
        /// Take ownership of an output.
        /// <para>(Also see DirectX SDK: IDXGIOutput::TakeOwnership)</para>
        /// </summary>
        /// <param name="device">A DXGI Device.</param>
        /// <param name="exclusive">Set to TRUE to enable other threads or applications to take ownership of the device; otherwise set to FALSE.</param>
        void TakeOwnership(DXGIDevice^ device, Boolean exclusive);

        /// <summary>
        /// Halt a thread until the next vertical blank occurs.
        /// <para>(Also see DirectX SDK: IDXGIOutput::WaitForVBlank)</para>
        /// </summary>
        void WaitForVBlank();
    internal:
        Output()
        {
        }
    internal:

        Output(IDXGIOutput* pNativeIDXGIOutput)
        {
            Attach(pNativeIDXGIOutput);
        }
    };
} } } }
