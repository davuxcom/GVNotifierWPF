//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10ShaderReflection.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
ref class ShaderReflectionVariable;

    /// <summary>
    /// A shader-reflection interface accesses shader information.
    /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1)</para>
    /// </summary>
    public ref class ShaderReflection1 :
        public ShaderReflection
    {
    public: 
        /// <summary>
        /// Gets the number of bitwise instructions.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetBitwiseInstructionCount)</para>
        /// </summary>
        property UInt32 BitwiseInstructionCount
        {
            UInt32 get();
        }

        /// <summary>
        /// Gets the number of Conversion instructions.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetConversionInstructionCount)</para>
        /// </summary>
        property UInt32 ConversionInstructionCount
        {
            UInt32 get();
        }

        /// <summary>
        /// Gets the geometry-shader input-primitive description.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetGSInputPrimitive)</para>
        /// </summary>
        property Primitive GSInputPrimitive
        {
            Primitive get();
        }

        /// <summary>
        /// Gets the number of Movc instructions.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetMovcInstructionCount)</para>
        /// </summary>
        property UInt32 MovcInstructionCount
        {
            UInt32 get();
        }

        /// <summary>
        /// Gets the number of Mov instructions.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetMovInstructionCount)</para>
        /// </summary>
        property UInt32 MovInstructionCount
        {
            UInt32 get();
        }

        /// <summary>
        /// Gets a variable by name.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetResourceBindingDescByName)</para>
        /// </summary>
        /// <param name="name">A string containing the variable name.</param>
        /// <returns>ShaderInputBindDescription object.</returns>
        ShaderInputBindDescription GetResourceBindingDescriptionByName(String^ name);

        /// <summary>
        /// Gets a variable by name.
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::GetVariableByName)</para>
        /// </summary>
        /// <param name="name">A string containing the variable name.</param>
        /// <returns>ShaderReflectionVariable object.</returns>
        ShaderReflectionVariable^ GetVariableByName(String^ name);

        /// <summary>
        /// Is Level9 Shader
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::IsLevel9Shader)</para>
        /// </summary>
        property Boolean IsLevel9Shader
        {
            Boolean get();
        }

        /// <summary>
        /// TBD
        /// <para>(Also see DirectX SDK: ID3D10ShaderReflection1::IsSampleFrequencyShader)</para>
        /// </summary>
        property Boolean IsSampleFrequencyShader
        {
            Boolean get();
        }

    internal:
        ShaderReflection1()
        { }

        ShaderReflection1(ID3D10ShaderReflection1* pNativeID3D10ShaderReflection1)
        { 
            Attach(pNativeID3D10ShaderReflection1);
        }
    };
} } } }
