//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A depth-stencil-view interface accesses a texture resource during depth-stencil testing.
    /// <para>(Also see DirectX SDK: ID3D10DepthStencilView)</para>
    /// </summary>
    public ref class DepthStencilView :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D10::View
    {
    public: 
        /// <summary>
        /// Get the depth-stencil view description.
        /// <para>(Also see DirectX SDK: ID3D10DepthStencilView::GetDesc)</para>
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

        DepthStencilView(ID3D10DepthStencilView* pNativeID3D10DepthStencilView)
        {
            Attach(pNativeID3D10DepthStencilView);
        }

    };
} } } }
