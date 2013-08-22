//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10EffectVariable.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
ref class RenderTargetView;

    /// <summary>
    /// A render-target-view interface accesses a render target.
    /// <para>(Also see DirectX SDK: ID3D10EffectRenderTargetViewVariable)</para>
    /// </summary>
    public ref class EffectRenderTargetViewVariable :
        public EffectVariable
    {
    public: 
        /// <summary>
        /// Get a render-target.
        /// <para>(Also see DirectX SDK: ID3D10EffectRenderTargetViewVariable::GetRenderTarget)</para>
        /// </summary>
        /// <returns>A render-target-view object. See RenderTargetView Object.</returns>
        RenderTargetView^ GetRenderTarget();

        /// <summary>
        /// Get a collection array of render-targets.
        /// <para>(Also see DirectX SDK: ID3D10EffectRenderTargetViewVariable::GetRenderTargetArray)</para>
        /// </summary>
        /// <param name="offset">The zero-based collection index to get the first object.</param>
        /// <param name="count">The number of elements requested in the collection.</param>
        /// <returns>A collection of render-target-view interfaces. See RenderTargetView Object.</returns>
        ReadOnlyCollection<RenderTargetView^>^ GetRenderTargetCollection(UInt32 offset, UInt32 count);

        /// <summary>
        /// Set a render-target.
        /// <para>(Also see DirectX SDK: ID3D10EffectRenderTargetViewVariable::SetRenderTarget)</para>
        /// </summary>
        /// <param name="Resource">A render-target-view object. See RenderTargetView Object.</param>
        void SetRenderTarget(RenderTargetView^ Resource);

        /// <summary>
        /// Set a collection of render-targets.
        /// <para>(Also see DirectX SDK: ID3D10EffectRenderTargetViewVariable::SetRenderTargetArray)</para>
        /// </summary>
        /// <param name="resources">Set a collection of render-target-view interfaces. See RenderTargetView Object.</param>
        /// <param name="offset">The zero-based collection index to store the first object at.</param>
        void SetRenderTargetCollection(IEnumerable<RenderTargetView^>^ resources, UInt32 offset);
    
    internal:
        EffectRenderTargetViewVariable()
        { }

        EffectRenderTargetViewVariable(ID3D10EffectRenderTargetViewVariable* pNativeID3D10EffectRenderTargetViewVariable)
            : EffectVariable(pNativeID3D10EffectRenderTargetViewVariable)
        { }

        EffectRenderTargetViewVariable(ID3D10EffectRenderTargetViewVariable* pNativeID3D10EffectRenderTargetViewVariable, bool deletable)
            : EffectVariable(pNativeID3D10EffectRenderTargetViewVariable, deletable)
        { }

    };
} } } }
