//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIDeviceSubObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;

    /// <summary>
    /// An Resource interface allows resource sharing and identifies the memory that a resource resides in.
    /// <para>(Also see DirectX SDK: IDXGIResource)</para>
    /// </summary>
    public ref class DXGIResource :
        public Microsoft::WindowsAPICodePack::DirectX::DXGI::DeviceSubObject
    {
    public: 
        /// <summary>
        /// The priority for evicting the resource from memory
        /// <para>(Also see DirectX SDK: IDXGIResource::GetEvictionPriority)</para>
        /// </summary>
        property ResourcePriority EvictionPriority
        {
            ResourcePriority get();
            void set(ResourcePriority value);
        }

        /// <summary>
        /// Get the handle to a shared resource. 
        /// The returned handle can be used to open the resource using different Direct3D devices.
        /// <para>(Also see DirectX SDK: IDXGIResource::GetSharedHandle)</para>
        /// </summary>
        property IntPtr SharedHandle        
        {
            IntPtr get();
        }

        /// <summary>
        /// Get the expected resource usage.
        /// <para>(Also see DirectX SDK: IDXGIResource::GetUsage)</para>
        /// </summary>
        /// <param name="outUsage">A usage flag (see <see cref="UsageOption"/>)<seealso cref="UsageOption"/>. For Direct3D 10, a surface can be used as a shader input or a render-target output.</param>
        property UsageOption UsageFlags
        {
            UsageOption get();
        }
    internal:
        DXGIResource()
        {
        }
    internal:

        DXGIResource(IDXGIResource* pNativeIDXGIResource)
        {
            Attach(pNativeIDXGIResource);
        }

    };
} } } }
