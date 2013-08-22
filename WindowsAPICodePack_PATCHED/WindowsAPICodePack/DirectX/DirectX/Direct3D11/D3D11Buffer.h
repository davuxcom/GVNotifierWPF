//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11Resource.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// Allows acccess to a buffer resource, which is unstructured memory. 
    /// Buffers typically store vertex or index data.
    /// <para>(Also see DirectX SDK: ID3D11Buffer)</para>
    /// </summary>
    public ref class D3DBuffer :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource
    {
    public: 
        /// <summary>
        /// Get the properties of a buffer resource (see <see cref="BufferDescription"/>)<seealso cref="BufferDescription"/>.
        /// <para>(Also see DirectX SDK: ID3D11Buffer::GetDesc)</para>
        /// </summary>
        property BufferDescription Description
        {
            BufferDescription get();
        }

    internal:
        D3DBuffer()
        {
        }
    internal:

        D3DBuffer(ID3D11Buffer* pNativeID3D11Buffer)
        {
            Attach(pNativeID3D11Buffer);
        }

        D3DBuffer(ID3D11Buffer* pNativeID3D11Buffer, bool deletable)
        {
            Attach(pNativeID3D11Buffer, deletable);
        }

    };
} } } }
