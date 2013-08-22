//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {
ref class SwapChain;
}}}}

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

ref class DeviceContext;

    /// <summary>
    /// A debug interface controls debug settings, validates pipeline state and can only be used if the debug layer is turned on.
    /// <para>(Also see DirectX SDK: ID3D11Debug)</para>
    /// </summary>
    public ref class D3DDebug :
        public DirectUnknown
    {
    public: 
        /// <summary>
        /// Gets or sets a bitfield of flags that indicates which debug features are on or off.
        /// <para>(Also see DirectX SDK: ID3D11Debug::GetFeatureMask)</para>
        /// </summary>
        property DebugFeature FeatureMask
        {
            DebugFeature get();
            void set(DebugFeature value);
        }

        /// <summary>
        /// Gets or sets the number of milliseconds to sleep after SwapChain.Present is called.
        /// <para>(Also see DirectX SDK: ID3D11Debug::GetPresentPerRenderOpDelay)</para>
        /// </summary>
        property UInt32 PresentPerRenderOpDelay
        {
            UInt32 get();
            void set(UInt32 value);
        }

        /// <summary>
        /// Get or set the swap chain that the runtime will use for automatically calling SwapChain.Present.
        /// <para>(Also see DirectX SDK: ID3D11Debug::GetSwapChain)</para>
        /// </summary>
        property SwapChain^ RuntimeSwapChain
        {
            SwapChain^ get();
            void set(SwapChain^ value);
        }

        /// <summary>
        /// Check to see if the pipeline state is valid.
        /// <para>(Also see DirectX SDK: ID3D11Debug::ValidateContext)</para>
        /// </summary>
        /// <param name="Context">The DeviceContext, that represents a device context.</param>
        void ValidateContext(DeviceContext^ Context);

    internal:
        D3DDebug()
        {
        }
    internal:

        D3DDebug(ID3D11Debug* pNativeID3D11Debug)
        {
            Attach(pNativeID3D11Debug);
        }

    };
} } } }
