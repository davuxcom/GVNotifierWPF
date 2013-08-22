//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIAdapter.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;

    /// <summary>
    /// The Adapter1 interface represents a display sub-system (including one or more GPU's, DACs and video memory).
    /// <para>(Also see DirectX SDK: IDXGIAdapter1)</para>
    /// </summary>
    public ref class Adapter1 :
        public Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter
    {
    public: 
        /// <summary>
        /// Gets a DXGI 1.1 description of a local or remote adapter (or video card).
        /// <para>(Also see DirectX SDK: IDXGIAdapter1::GetDesc1)</para>
        /// </summary>
        /// <returns>An AdapterDescription1 object.</returns>
        property AdapterDescription1 Description1
        {
            AdapterDescription1 get();
        }

    internal:
        Adapter1() : Adapter()
        { }

        Adapter1(IDXGIAdapter1* pNativeIDXGIAdapter1) : Adapter(pNativeIDXGIAdapter1)
        { }

        AdapterDescription1 m_desc1;
        bool init;
    };
} } } }
