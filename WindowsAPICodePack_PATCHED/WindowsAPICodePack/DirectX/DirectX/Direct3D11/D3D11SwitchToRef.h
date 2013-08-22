//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A swith-to-reference interface enables an application to switch between a hardware and software device.
    /// <para>(Also see DirectX SDK: ID3D11SwitchToRef)</para>
    /// </summary>
    public ref class SwitchToRef :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Get a boolean value that indicates the type of device being used.
        /// <para>(Also see DirectX SDK: ID3D10SwitchToRef::GetUseRef)</para>
        /// </summary>
        Boolean GetUseRef();

        /// <summary>
        /// Switch between a hardware and a software device.
        /// <para>(Also see DirectX SDK: ID3D10SwitchToRef::SetUseRef)</para>
        /// </summary>
        /// <param name="UseRef">A boolean value. Set this to TRUE to change to a software device, set this to FALSE to change to a hardware device.</param>
        Boolean SetUseRef(Boolean UseRef);
    internal:
        SwitchToRef()
        {
        }
    internal:

        SwitchToRef(ID3D11SwitchToRef* pNativeID3D11SwitchToRef)
        {
            Attach(pNativeID3D11SwitchToRef);
        }

    };
} } } }
