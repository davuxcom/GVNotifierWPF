//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A shader-resource-view interface specifies the subresources a shader can access during rendering. Examples of shader resources include a constant buffer, a texture buffer, a texture or a sampler.
    /// <para>(Also see DirectX SDK: ID3D10ShaderResourceView)</para>
    /// </summary>
    public ref class ShaderResourceView :
        public View
    {
    public: 
        /// <summary>
        /// Get the shader resource view's description.
        /// <para>(Also see DirectX SDK: ID3D10ShaderResourceView::GetDesc)</para>
        /// </summary>
        /// <returns>A ShaderResourceViewDescription structure to be filled with data about the shader resource view.</returns>
        property ShaderResourceViewDescription Description
        {
            ShaderResourceViewDescription get();
        }

    internal:
        ShaderResourceView()
        { }

        ShaderResourceView(ID3D10ShaderResourceView* pNativeID3D10ShaderResourceView) : View(pNativeID3D10ShaderResourceView)
        { }

    };
} } } }
