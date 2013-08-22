//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "D3D11DeviceChild.h"

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {
    ref class Surface;
} } } }
namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

    /// <summary>
    /// A resource interface provides common actions on all resources.
    /// <para>(Also see DirectX SDK: ID3D11Resource)</para>
    /// </summary>
    public ref class D3DResource :
        public DeviceChild
    {
    public: 
        /// <summary>
        /// Gets or sets the eviction priority of a resource.
        /// <para>(Also see DirectX SDK: ID3D11Resource::GetEvictionPriority, ID3D11Resource::SetEvictionPriority)</para>
        /// </summary>
        property UInt32 EvictionPriority
        {
            UInt32 get();
            void set(UInt32 value);
        }

        /// <summary>
        /// Get the type of the resource.
        /// <para>(Also see DirectX SDK: ID3D11Resource::GetType)</para>
        /// </summary>
        property ResourceDimension Type
        {
            ResourceDimension get();
        }

        /// <summary>
        /// Get associated DXGI suraface.
        /// </summary>
        Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface^ GetDXGISurface();

    internal:
        D3DResource()
        {
        }
    internal:

        D3DResource(ID3D11Resource* pNativeID3D11Resource)
        {
            Attach(pNativeID3D11Resource);
        }

    };
} } } }
