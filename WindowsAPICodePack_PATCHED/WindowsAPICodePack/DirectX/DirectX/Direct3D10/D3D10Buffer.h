//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10Resource.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A buffer interface accesses a buffer resource, which is unstructured memory. Buffers typically store vertex or index data.
    /// <para>(Also see DirectX SDK: ID3D10Buffer)</para>
    /// </summary>
    public ref class D3DBuffer :
        public D3DResource
    {
    public: 
        /// <summary>
        /// Get the properties of a buffer resource.
        /// <para>(Also see DirectX SDK: ID3D10Buffer::GetDesc)</para>
        /// </summary>
        /// <returns>A resource description (see <see cref="BufferDescription"/>)<seealso cref="BufferDescription"/> filled in by the method.</returns>
        property BufferDescription Description
        {
            BufferDescription get();
        }

        /// <summary>
        /// Get the data contained in the resource and deny GPU access to the resource.
        /// <para>(Also see DirectX SDK: ID3D10Buffer::Map)</para>
        /// </summary>
        /// <param name="type">Flag that specifies the CPU's permissions for the reading and writing of a resource. For possible values, see Map.</param>
        /// <param name="flags">Flag that specifies what the CPU should do when the GPU is busy (see <see cref="MapFlag"/>)<seealso cref="MapFlag"/>. This flag is optional.</param>
        /// <returns>Pointer to the buffer resource data.</returns>
        IntPtr Map(D3D10::Map type, MapFlag flags);

        /// <summary>
        /// Invalidate the pointer to the resource retrieved by D3DBuffer.Map and reenable GPU access to the resource.
        /// <para>(Also see DirectX SDK: ID3D10Buffer::Unmap)</para>
        /// </summary>
        void Unmap();

    internal:
        D3DBuffer()
        {
        }

        D3DBuffer(ID3D10Buffer* pNativeID3D10Buffer)
        {
            Attach(pNativeID3D10Buffer);
        }
    };
} } } }
