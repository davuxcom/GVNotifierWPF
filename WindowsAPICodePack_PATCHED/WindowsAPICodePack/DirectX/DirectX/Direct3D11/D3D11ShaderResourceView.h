//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A shader-resource-view interface specifies the subresources a shader can access during rendering. Examples of shader resources include a constant buffer, a texture buffer, a texture or a sampler.
    /// <para>(Also see DirectX SDK: ID3D11ShaderResourceView)</para>
    /// </summary>
    public ref class ShaderResourceView :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View
    {
    public: 
        /// <summary>
        /// Get the shader resource view's description.
        /// <para>(Also see DirectX SDK: ID3D11ShaderResourceView::GetDesc)</para>
        /// </summary>
        /// <returns>A ShaderResourceViewDescription structure to be filled with data about the shader resource view.</returns>
        property ShaderResourceViewDescription Description
        {
            ShaderResourceViewDescription  get();
        }

    internal:
        ShaderResourceView()
        {
        }
    internal:

        ShaderResourceView(ID3D11ShaderResourceView* pNativeID3D11ShaderResourceView)
        {
            Attach(pNativeID3D11ShaderResourceView);
        }

        ShaderResourceView(ID3D11ShaderResourceView* pNativeID3D11ShaderResourceView, bool deletable)
        {
            Attach(pNativeID3D11ShaderResourceView, deletable);
        }

    };
} } } }
