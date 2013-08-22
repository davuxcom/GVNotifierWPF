//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

ref class ShaderReflectionConstantBuffer;

    /// <summary>
    /// A shader-reflection interface accesses shader information.
    /// <para>(Also see DirectX SDK: ID3D10ShaderReflection)</para>
    /// </summary>
    public ref class ShaderReflection :
        public DirectUnknown
    {
    public: 
        /// <summary>
        /// Get a constant buffer by index.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection::GetConstantBufferByIndex)</para>
        /// </summary>
        /// <param name="index">Zero-based index.</param>
        /// <returns>A shader reflection constant bufer.</returns>
        ShaderReflectionConstantBuffer^ GetConstantBufferByIndex(UInt32 index);

        /// <summary>
        /// Get a constant buffer by name.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection::GetConstantBufferByName)</para>
        /// </summary>
        /// <param name="name">The constant-buffer name.</param>
        /// <returns>A shader reflection constant bufer.</returns>
        ShaderReflectionConstantBuffer^ GetConstantBufferByName(String^ name);

        /// <summary>
        /// Get a shader description.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection::GetDesc)</para>
        /// </summary>
        /// <returns>A shader description. See ShaderDescription.</returns>
        property ShaderDescription Description
        {
            ShaderDescription get();
        }

        /// <summary>
        /// Get an input-parameter description for a shader.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection::GetInputParameterDesc)</para>
        /// </summary>
        /// <param name="parameterIndex">A zero-based parameter index.</param>
        /// <returns>A shader-input-signature description. See SignatureParameterDescription.</returns>
        SignatureParameterDescription GetInputParameterDescription(UInt32 parameterIndex);

        /// <summary>
        /// Get an output-parameter description for a shader.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection::GetOutputParameterDesc)</para>
        /// </summary>
        /// <param name="parameterIndex">A zero-based parameter index.</param>
        /// <returns>A shader-output-parameter description. See SignatureParameterDescription.</returns>
        SignatureParameterDescription GetOutputParameterDescription(UInt32 parameterIndex);

        /// <summary>
        /// Get a description of the resources bound to a shader.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection::GetResourceBindingDesc)</para>
        /// </summary>
        /// <param name="resourceIndex">A zero-based resource index.</param>
        /// <returns>A input-binding description. See ShaderInputBindDescription.</returns>
        ShaderInputBindDescription GetResourceBindingDescription(UInt32 resourceIndex);
    internal:
        ShaderReflection()
        { }

        ShaderReflection(ID3D10ShaderReflection* pNativeID3D10ShaderReflection) : DirectUnknown (pNativeID3D10ShaderReflection)
        { }
    };
} } } }
