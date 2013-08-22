//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10EffectVariable.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A vector-variable interface accesses a four-component vector.
    /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable)</para>
    /// </summary>
    public ref class EffectVectorVariable : public EffectVariable
    {
    public: 
        /// <summary>
        /// Get or set a four-component vector that contains boolean data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::GetBoolVector)</para>
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::SetBoolVector)</para>
        /// </summary>
        property Vector4B BoolVector
        {
            Vector4B get();
            void set(Vector4B);
        }

        /// <summary>
        /// Get an array of four-component vectors that contain boolean data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::GetBoolVectorArray)</para>
        /// </summary>
        /// <param name="count">The number of requested array elements to get.</param>
        /// <returns>An array of boolean vectors as 4-components arrays.</returns>
        array<Vector4B>^ GetBoolVectorArray(UInt32 count);

        /// <summary>
        /// Get or set a four-component vector that contains floating-point data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::GetFloatVector)</para>
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::SetFloatVector)</para>
        /// </summary>
        property Vector4F FloatVector
        {
            Vector4F get();
            void set(Vector4F);
        }


        /// <summary>
        /// Get an array of four-component vectors that contain floating-point data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::GetFloatVectorArray)</para>
        /// </summary>
        /// <param name="count">The number of requested array elements to get.</param>
        /// <returns>An array of floating-point vectors as 4-components arrays.</returns>
        array<Vector4F>^ GetFloatVectorArray(UInt32 count);

        /// <summary>
        /// Get or set a four-component vector that contains integer data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::GetIntVector)</para>
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::SetIntVector)</para>
        /// </summary>
        property Vector4I IntVector
        {
            Vector4I get();
            void set(Vector4I);
        }

        /// <summary>
        /// Get an array of four-component vectors that contain integer data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::GetIntVectorArray)</para>
        /// </summary>
        /// <param name="count">The number of requested array elements to get.</param>
        /// <returns>An array of integer value vectors as 4-components arrays.</returns>
        array<Vector4I>^ GetIntVectorArray(UInt32 count);

        /// <summary>
        /// Set an array of four-component vectors that contain boolean data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::SetBoolVectorArray)</para>
        /// </summary>
        /// <param name="data">An array of boolean vectors as 4-components arrays.</param>
        void SetBoolVectorArray(array<Vector4B>^ data);

        /// <summary>
        /// Set an array of four-component vectors that contain floating-point data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::SetFloatVectorArray)</para>
        /// </summary>
        /// <param name="data">An array of floating-point vectors as 4-components arrays.</param>
        void SetFloatVectorArray(array<Vector4F>^ data);

        /// <summary>
        /// Set an array of four-component vectors that contain integer data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVectorVariable::SetIntVectorArray)</para>
        /// </summary>
        /// <param name="data">An array of integer data vectors as 4-components arrays.</param>
        void SetIntVectorArray(array<Vector4I>^ data);
    
    internal:
        EffectVectorVariable()
        { }

        EffectVectorVariable(ID3D10EffectVectorVariable* pNativeID3D10EffectVectorVariable)
            : EffectVariable(pNativeID3D10EffectVectorVariable)
        { }

        EffectVectorVariable(ID3D10EffectVectorVariable* pNativeID3D10EffectVectorVariable, bool deletable)
            : EffectVariable(pNativeID3D10EffectVectorVariable, deletable)
        { }

      
    };
} } } }
