//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DXGIFactory.h"

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

ref class Adapter1;

    /// <summary>
    /// The DXGIFactory1 interface implements methods for generating DXGI objects.
    /// <para>(Also see DirectX SDK: IDXGIFactory1)</para>
    /// </summary>
    public ref class DXGIFactory1 :
        public Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory
    {
    public: 
        /// <summary>
        /// Enumerates both local and remote adapters (video cards).
        /// <para>(Also see DirectX SDK: IDXGIFactory1::EnumAdapters1)</para>
        /// </summary>
        /// <returns>A read-only collection of Adapter objects.</returns>
        ReadOnlyCollection<Adapter1^>^ GetAdapters1();

        /// <summary>
        /// Get a local or remote adapter (video cards).
        /// <para>(Also see DirectX SDK: IDXGIFactory1::EnumAdapters1)</para>
        /// </summary>
        /// <param name="index">The index of the adapter requested.</param>
        /// <returns>An Adapter1 object.</returns>
        Adapter1^ GetAdapter1(UInt32 index);

        /// <summary>
        /// Informs application the possible need to re-enumerate adapters -- new adapter(s) have become available, current adapter(s) become unavailable.
        /// Called by Direct3D 10.1 Command Remoting applications to handle Remote Desktop Services session transitions.
        /// <para>(Also see DirectX SDK: IDXGIFactory1::IsCurrent)</para>
        /// </summary>
        property Boolean IsCurrent
        {
            Boolean get();
        }

        /// <summary>
        /// Creates a DXGI 1.1 factory that generates objects used to enumerate and specify video graphics settings.
        /// <para>(Also see DirectX SDK: CreateDXGIFactory1() Function.)</para>
        /// </summary>
        /// <returns>DXGIFactory1 Object.</returns>
        static DXGIFactory1^ CreateFactory1();

    internal:
        DXGIFactory1() {}

        DXGIFactory1(IDXGIFactory1* pNativeIDXGIFactory1) : DXGIFactory(pNativeIDXGIFactory1)
        { }
    };
} } } }
