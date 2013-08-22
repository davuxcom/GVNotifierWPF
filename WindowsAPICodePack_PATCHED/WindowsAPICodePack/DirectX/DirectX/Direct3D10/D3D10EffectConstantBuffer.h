//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10EffectVariable.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
ref class D3DBuffer;
ref class ShaderResourceView;

    /// <summary>
    /// A constant-buffer interface accesses constant buffers or texture buffers.
    /// <para>(Also see DirectX SDK: ID3D10EffectConstantBuffer)</para>
    /// </summary>
    public ref class EffectConstantBuffer :
        public EffectVariable
    {
    public: 
        /// <summary>
        /// Get a constant-buffer.
        /// <para>(Also see DirectX SDK: ID3D10EffectConstantBuffer::GetConstantBuffer)</para>
        /// </summary>
        /// <returns>A constant-buffer object. See D3DBuffer Object.</returns>
        D3DBuffer^ GetConstantBuffer();

        /// <summary>
        /// Get a texture-buffer.
        /// <para>(Also see DirectX SDK: ID3D10EffectConstantBuffer::GetTextureBuffer)</para>
        /// </summary>
        /// <returns>A shader-resource-view interface for accessing a texture buffer. See ShaderResourceView Object.</returns>
        ShaderResourceView^  GetTextureBuffer();

        /// <summary>
        /// Set a constant-buffer.
        /// <para>(Also see DirectX SDK: ID3D10EffectConstantBuffer::SetConstantBuffer)</para>
        /// </summary>
        /// <param name="constantBuffer">A constant-buffer object. See D3DBuffer Object.</param>
        void SetConstantBuffer(D3DBuffer^ constantBuffer);

        /// <summary>
        /// Set a texture-buffer.
        /// <para>(Also see DirectX SDK: ID3D10EffectConstantBuffer::SetTextureBuffer)</para>
        /// </summary>
        /// <param name="textureBuffer">A shader-resource-view interface for accessing a texture buffer.</param>
        void SetTextureBuffer(ShaderResourceView^ textureBuffer);

    internal:
        EffectConstantBuffer()
        { }

        EffectConstantBuffer(ID3D10EffectConstantBuffer* pNativeID3D10EffectConstantBuffer): 
            EffectVariable(pNativeID3D10EffectConstantBuffer)
        { }


        EffectConstantBuffer(ID3D10EffectConstantBuffer* pNativeID3D10EffectConstantBuffer, bool deletable): 
            EffectVariable(pNativeID3D10EffectConstantBuffer, deletable)
        { }

    };
} } } }
