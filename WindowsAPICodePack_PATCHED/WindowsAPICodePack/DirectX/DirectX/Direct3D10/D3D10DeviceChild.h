//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;
using namespace Microsoft::WindowsAPICodePack::DirectX;

ref class D3DDevice;
ref class D3DDevice1;

    /// <summary>
    /// A device-child interface accesses data used by a device.
    /// <para>(Also see DirectX SDK: ID3D10DeviceChild)</para>
    /// </summary>
    public ref class DeviceChild :
        public DirectUnknown
    {
    public: 
        /// <summary>
        /// Get the device that created this object.
        /// <para>(Also see DirectX SDK: ID3D10DeviceChild::GetDevice)</para>
        /// </summary>
        /// <returns>A D3DDevice 10.0 object</returns>
        D3DDevice^ GetDevice();

    internal:
        DeviceChild() {}
    
        DeviceChild(ID3D10DeviceChild* pNativeID3D10DeviceChild) : 
            DirectUnknown(pNativeID3D10DeviceChild) {}
    };
} } } }
