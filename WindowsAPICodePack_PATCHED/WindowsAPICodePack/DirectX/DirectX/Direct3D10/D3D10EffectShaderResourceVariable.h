//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10EffectVariable.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
ref class ShaderResourceView;

    /// <summary>
    /// A shader-resource interface accesses a shader resource.
    /// <para>(Also see DirectX SDK: ID3D10EffectShaderResourceVariable)</para>
    /// </summary>
    public ref class EffectShaderResourceVariable :
        public EffectVariable
    {
    public: 
        /// <summary>
        /// Get a shader resource.
        /// <para>(Also see DirectX SDK: ID3D10EffectShaderResourceVariable::GetResource)</para>
        /// </summary>
        /// <returns>A shader-resource-view object. See ShaderResourceView Object.</returns>
        ShaderResourceView^ GetResource();

        /// <summary>
        /// Get a collection of shader resources.
        /// <para>(Also see DirectX SDK: ID3D10EffectShaderResourceVariable::GetResourceArray)</para>
        /// </summary>
        /// <param name="offset">The zero-based array index to get the first object.</param>
        /// <param name="count">The number of requested elements in the array.</param>
        /// <returns>A collection of shader-resource-view interfaces. See ShaderResourceView Object.</returns>
        ReadOnlyCollection<ShaderResourceView^>^ GetResourceArray(UInt32 offset, UInt32 count);

        /// <summary>
        /// Set a shader resource.
        /// <para>(Also see DirectX SDK: ID3D10EffectShaderResourceVariable::SetResource)</para>
        /// </summary>
        /// <param name="resource">A shader-resource-view object. See ShaderResourceView Object.</param>
        void SetResource(ShaderResourceView^ resource);

        /// <summary>
        /// Set an collection of shader resources.
        /// <para>(Also see DirectX SDK: ID3D10EffectShaderResourceVariable::SetResourceArray)</para>
        /// </summary>
        /// <param name="resources">A collection of shader-resource-view interfaces. See ShaderResourceView Object.</param>
        /// <param name="offset">The zero-based array index to get the first object.</param>
        void SetResourceArray(IEnumerable<ShaderResourceView^>^ resources, UInt32 offset);

    internal:
        EffectShaderResourceVariable()
        { }

        EffectShaderResourceVariable(ID3D10EffectShaderResourceVariable* pNativeID3D10EffectShaderResourceVariable)
            : EffectVariable(pNativeID3D10EffectShaderResourceVariable)
        { }

        EffectShaderResourceVariable(ID3D10EffectShaderResourceVariable* pNativeID3D10EffectShaderResourceVariable, bool deletable)
            : EffectVariable(pNativeID3D10EffectShaderResourceVariable, deletable)
        { }

    };
} } } }
