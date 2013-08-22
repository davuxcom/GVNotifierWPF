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
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;

ref class Adapter;
ref class SwapChain;

    /// <summary>
    /// Implements methods for generating DXGI objects (which handle fullscreen transitions).
    /// <para>(Also see DirectX SDK: IDXGIFactory)</para>
    /// </summary>
    public ref class DXGIFactory :
        public DXGIObject
    {
    public: 

        /// <summary>
        /// Creates a swap chain.
        /// <para>(Also see DirectX SDK: IDXGIFactory::CreateSwapChain)</para>
        /// </summary>
        /// <param name="device">The device that will write 2D images to the swap chain.</param>
        /// <param name="description">The swap-chain description (see <see cref="SwapChainDescription"/>)<seealso cref="SwapChainDescription"/>. This parameter cannot be NULL.</param>
        /// <return>The swap chain created (see <see cref="SwapChain"/>)<seealso cref="SwapChain"/>.</return>
        SwapChain^ CreateSwapChain(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ device, SwapChainDescription description);

        /// <summary>
        /// Creates a swap chain.
        /// <para>(Also see DirectX SDK: IDXGIFactory::CreateSwapChain)</para>
        /// </summary>
        /// <param name="device">The device that will write 2D images to the swap chain.</param>
        /// <param name="description">The swap-chain description (see <see cref="SwapChainDescription"/>)<seealso cref="SwapChainDescription"/>. This parameter cannot be NULL.</param>
        /// <return>The swap chain created (see <see cref="SwapChain"/>)<seealso cref="SwapChain"/>.</return>
        SwapChain^ CreateSwapChain(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ device, SwapChainDescription description);

        /// <summary>
        /// Enumerates the adapters (video cards).
        /// <para>(Also see DirectX SDK: IDXGIFactory::EnumAdapters)</para>
        /// </summary>
        /// <returns>A readonly collection of Adapter objects.</returns>
        ReadOnlyCollection<Adapter^>^ GetAdapters();

        /// <summary>
        /// Get an adapter (video cards).
        /// <para>(Also see DirectX SDK: IDXGIFactory::EnumAdapters)</para>
        /// </summary>
        /// <param name="index">The index of the adapter requested.</param>
        /// <returns>An Adapter object.</returns>
        Adapter^ GetAdapter(UInt32 index);

        /// <summary>
        /// Get the window through which the user controls the transition to and from fullscreen.
        /// <para>(Also see DirectX SDK: IDXGIFactory::GetWindowAssociation)</para>
        /// </summary>
        /// <return>A window handle.</return>
        IntPtr GetWindowAssociation();

        /// <summary>
        /// Allows DXGI to monitor an application's message queue for the alt-enter key sequence (which causes the application to switch from windowed to fullscreen or vice versa).
        /// <para>(Also see DirectX SDK: IDXGIFactory::MakeWindowAssociation)</para>
        /// </summary>
        /// <param name="WindowHandle">The handle of the window that is to be monitored. This parameter can be NULL; but only if the flags are also 0.</param>
        /// <param name="Flags">One or more of the MakeWindowAssociation flags.</param>
        void MakeWindowAssociation(IntPtr WindowHandle, MakeWindowAssociationFlags Flags);

        /// <summary>
        /// Creates a DXGI 1.0 factory that generates objects used to enumerate and specify video graphics settings.
        /// <para>(Also see DirectX SDK: CreateDXGIFactory() Function.)</para>
        /// </summary>
        /// <returns>DXGIFactory Object.</returns>
        static DXGIFactory^ CreateFactory();
    
    internal:
        DXGIFactory() {}
    
        DXGIFactory(IDXGIFactory* pNativeIDXGIFactory) : DXGIObject(pNativeIDXGIFactory)
        { }

    };
} } } }
