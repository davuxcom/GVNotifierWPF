//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {
    ref class Surface;
} } } }

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A resource interface provides common actions on all resources.
    /// <para>(Also see DirectX SDK: ID3D10Resource)</para>
    /// </summary>
    public ref class D3DResource :
        public DeviceChild
    {
    public: 
        /// <summary>
        /// Get or set the eviction priority of a resource.
        /// <para>(Also see DirectX SDK: ID3D10Resource::GetEvictionPriority)</para>
        /// </summary>
        property UInt32 EvictionPriority
        {
            void set(UInt32 value);
            UInt32 get();
        }

        /// <summary>
        /// Get the type of the resource.
        /// <para>(Also see DirectX SDK: ID3D10Resource::GetType)</para>
        /// </summary>
        property ResourceDimension Type
        {
            ResourceDimension get();
        }

        /// <summary>
        /// Get associated DXGI suraface. If none is associated - throw an InvalidCastException.
        /// </summary>
        Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface^ GetDXGISurface();

    internal:
        D3DResource()
        { }

        D3DResource(ID3D10Resource* pNativeID3D10Resource) : DeviceChild(pNativeID3D10Resource)
        { }
    };
} } } }
