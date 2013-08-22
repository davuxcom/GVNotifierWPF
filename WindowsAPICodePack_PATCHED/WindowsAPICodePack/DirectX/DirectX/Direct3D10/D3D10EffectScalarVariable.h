//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10EffectVariable.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// An effect-scalar-variable interface accesses scalar values.
    /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable)</para>
    /// </summary>
    public ref class EffectScalarVariable :
        public EffectVariable
    {
    public: 
        /// <summary>
        /// Get or set a boolean variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::GetBool)</para>
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::SetBool)</para>
        /// </summary>
        property Boolean BoolValue
        {
            Boolean get();
            void set(Boolean);
        }


        /// <summary>
        /// Get an array of boolean variables.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::GetBoolArray)</para>
        /// </summary>
        /// <param name="count">The number of array elements to get.</param>
        /// <returns>The array of boolean variables.</returns>
        array<Boolean>^ GetBoolArray(UInt32 count);

        /// <summary>
        /// Get or set a floating-point variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::GetFloat)</para>
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::SetFloat)</para>
        /// </summary>
        /// <returns>The variable.</returns>
        property Single FloatValue
        {
            Single get();
            void set(Single);
        }

        /// <summary>
        /// Get an array of floating-point variables.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::GetFloatArray)</para>
        /// </summary>
        /// <param name="count">The number of array elements to get.</param>
        /// <returns>The array of floating-point variables.</returns>
        array<Single>^ GetFloatArray(UInt32 count);

        /// <summary>
        /// Get or set an integer variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::GetInt)</para>
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::SetInt)</para>
        /// </summary>
        /// <returns>The variable.</returns>
        property Int32 IntValue
        {
            Int32 get();
            void set(Int32);
        }

        /// <summary>
        /// Get an array of integer variables.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::GetIntArray)</para>
        /// </summary>
        /// <param name="count">The number of array elements to get.</param>
        /// <returns>The array of integer variables.</returns>
        array<Int32>^ GetIntArray(UInt32 count);

        /// <summary>
        /// Set an array of boolean variables.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::SetBoolArray)</para>
        /// </summary>
        /// <param name="data">The array of variables to set.</param>
        void SetBoolArray(array<Boolean>^ data);

        /// <summary>
        /// Set an array of floating-point variables.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::SetFloatArray)</para>
        /// </summary>
        /// <param name="data">The array of variables to set.</param>
        void SetFloatArray(array<Single>^ data);

        /// <summary>
        /// Set an array of integer variables.
        /// <para>(Also see DirectX SDK: ID3D10EffectScalarVariable::SetIntArray)</para>
        /// </summary>
        /// <param name="data">The array of variables to set.</param>
        void SetIntArray(array<Int32>^ data);

    internal:
        EffectScalarVariable()
        { }

        EffectScalarVariable(ID3D10EffectScalarVariable* pNativeID3D10EffectScalarVariable)
            : EffectVariable(pNativeID3D10EffectScalarVariable)
        { }

        EffectScalarVariable(ID3D10EffectScalarVariable* pNativeID3D10EffectScalarVariable, bool deletable)
            : EffectVariable(pNativeID3D10EffectScalarVariable, deletable)
        { }

    };
} } } }
