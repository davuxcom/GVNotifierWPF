//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;

ref class Surface;
ref class Adapter;
ref class DXGIResource;

    /// <summary>
    /// Implements a derived class for DXGI objects that produce image data.
    /// <para>(Also see DirectX SDK: IDXGIDevice)</para>
    /// </summary>
    public ref class DXGIDevice :
        public DXGIObject
    {
    public: 

        /// <summary>
        /// Returns the adapter for the specified device.
        /// <para>(Also see DirectX SDK: IDXGIDevice::GetAdapter)</para>
        /// </summary>
        Adapter^ GetAdapter();

        /// <summary>
        /// Sets or Gets the GPU thread priority.
        /// <para>(Also see DirectX SDK: IDXGIDevice::GetGPUThreadPriority and IDXGIDevice::SetGPUThreadPriority)</para>
        /// </summary>
        property Int32 GPUThreadPriority
        {
            Int32 get();
            void set(Int32 value);
        }

        /// <summary>
        /// Gets the residency status of a colleciton of resources.
        /// <para>Note: This method should not be called every frame as it incurs a non-trivial amount of overhead.</para>
        /// <para>(Also see DirectX SDK: IDXGIDevice::QueryResourceResidency)</para>
        /// </summary>
        /// <param name="resources">A collection or array of DXGIResource interfaces.</param>
        /// <returns>An array of residency flags. Each element describes the residency status for corresponding element in
        /// the resources argument.</returns>
        array<Residency>^ QueryResourceResidency(IEnumerable<DXGIResource^>^ resources);

    internal:
        DXGIDevice()
        {
        }
    internal:

        DXGIDevice(IDXGIDevice* pNativeIDXGIDevice)
        {
            Attach(pNativeIDXGIDevice);
        }        
    };
} } } }
