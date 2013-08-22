//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A render-target-view interface identifies the render-target subresources that can be accessed during rendering.
    /// <para>(Also see DirectX SDK: ID3D10RenderTargetView)</para>
    /// </summary>
    public ref class RenderTargetView :
        public View
    {
    public: 
        /// <summary>
        /// Get the properties of a render target view.
        /// <para>(Also see DirectX SDK: ID3D10RenderTargetView::GetDesc)</para>
        /// </summary>
        /// <returns>The description of a render target view (see <see cref="RenderTargetViewDescription"/>)<seealso cref="RenderTargetViewDescription"/>.</returns>
        property RenderTargetViewDescription Description
        {
            RenderTargetViewDescription  get();
        }
    internal:
        RenderTargetView()
        {
        }
    internal:

        RenderTargetView(ID3D10RenderTargetView* pNativeID3D10RenderTargetView) : View(pNativeID3D10RenderTargetView)
        { }

    };
} } } }
