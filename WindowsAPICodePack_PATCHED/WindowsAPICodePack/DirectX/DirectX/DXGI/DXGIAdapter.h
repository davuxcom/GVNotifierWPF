//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"

using namespace System;
using namespace System::Collections::ObjectModel;
namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {
ref class Output;

    /// <summary>
    /// The  Adapter interface represents a display sub-system (including one or more GPU's, DACs and video memory).
    /// <para>(Also see DirectX SDK: IDXGIAdapter)</para>
    /// </summary>
    public ref class Adapter :
        public DXGIObject
    {
    public: 
        /// <summary>
        /// Checks to see if a device interface for a graphics component is supported by the system.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::CheckInterfaceSupport)</para>
        /// </summary>
        /// <param name="deviceType"> The device support checked.</param>
        /// <param name="UMDVersionMajor">An out parameter containing the user mode driver version of InterfaceName high 32 bit value. Returns 0 if interface is not supported.</param>
        /// <param name="UMDVersionMinor">An out parameter containing the user mode driver version of InterfaceName low 32 bit value. Returns 0 if interface is not supported.</param>
        /// <returns>True if the device is supported by the system; false otherwise</returns>
        bool CheckDeviceSupport(DeviceType deviceType, [System::Runtime::InteropServices::Out] Int32 %UMDVersionMajor, [System::Runtime::InteropServices::Out] Int32 %UMDVersionMinor );

        /// <summary>
        /// Checks to see if a device interface for a graphics component is supported by the system.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::CheckInterfaceSupport)</para>
        /// </summary>
        /// <param name="deviceType"> The device support checked.</param>
        /// <returns>True if the device is supported by the system; false otherwise</returns>
        bool CheckDeviceSupport(DeviceType deviceType);

        /// <summary>
        /// Get a read-only collection of all adapter (video card) outputs available.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::EnumOutputs)</para>
        /// </summary>
        /// <returns>A readonly collection of Output object</returns>
        ReadOnlyCollection<Output^>^ GetOutputs();

        /// <summary>
        /// Get an adapter (video card) output.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::EnumOutputs)</para>
        /// </summary>
        /// <param name="index">The index of the output requested.</param>
        /// <returns>An Output object</returns>
        Output^ GetOutput(UInt32 index);

        /// <summary>
        /// Gets a DXGI 1.0 description of an adapter (or video card).
        /// <para>(Also see DirectX SDK: IDXGIAdapter::GetDesc)</para>
        /// </summary>
        property AdapterDescription Description
        {
            AdapterDescription get();
        }

    internal:
        Adapter()
        { }

        Adapter(IDXGIAdapter* pNativeIDXGIAdapter)
            : DXGIObject(pNativeIDXGIAdapter)
        { }

        AdapterDescription m_desc;
        bool init;

    };
} } } }
