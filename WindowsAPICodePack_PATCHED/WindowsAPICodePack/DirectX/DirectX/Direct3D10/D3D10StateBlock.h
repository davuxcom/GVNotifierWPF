//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

ref class D3DDevice;

    /// <summary>
    /// A state-block interface encapsulates render states.
    /// <para>(Also see DirectX SDK: ID3D10StateBlock)</para>
    /// </summary>
    public ref class StateBlock :
        public DirectUnknown
    {
    public: 
        /// <summary>
        /// Apply the state block to the current device state.
        /// <para>(Also see DirectX SDK: ID3D10StateBlock::Apply)</para>
        /// </summary>
        void Apply();

        /// <summary>
        /// Capture the current value of states that are included in a stateblock.
        /// <para>(Also see DirectX SDK: ID3D10StateBlock::Capture)</para>
        /// </summary>
        void Capture();

        /// <summary>
        /// Get the device.
        /// <para>(Also see DirectX SDK: ID3D10StateBlock::GetDevice)</para>
        /// </summary>
        /// <returns>Pointer to the Device interface that is returned.</returns>
        D3DDevice^ GetDevice();

        /// <summary>
        /// Release all references to device objects.
        /// <para>(Also see DirectX SDK: ID3D10StateBlock::ReleaseAllDeviceObjects)</para>
        /// </summary>
        void ReleaseAllDeviceObjects();

    internal:
        StateBlock()
        { }

        StateBlock(ID3D10StateBlock* pNativeID3D10StateBlock) : 
            DirectUnknown(pNativeID3D10StateBlock)
        { }

    };
} } } }
