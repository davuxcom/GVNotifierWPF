//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A depth-stencil-view interface accesses a texture resource during depth-stencil testing.
    /// <para>(Also see DirectX SDK: ID3D11DepthStencilView)</para>
    /// </summary>
    public ref class DepthStencilView :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View
    {
    public: 
        /// <summary>
        /// Get the depth-stencil view.
        /// <para>(Also see DirectX SDK: ID3D11DepthStencilView::GetDesc)</para>
        /// </summary>
        /// <returns>A depth-stencil-view description (see <see cref="DepthStencilViewDescription"/>)<seealso cref="DepthStencilViewDescription"/>.</returns>
        property DepthStencilViewDescription Description
        {
            DepthStencilViewDescription get();
        }

    internal:
        DepthStencilView()
        {
        }
    internal:

        DepthStencilView(ID3D11DepthStencilView* pNativeID3D11DepthStencilView)
        {
            Attach(pNativeID3D11DepthStencilView);
        }

    };
} } } }
