//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

ref class Effect;

    /// <summary>
    /// A pool interface represents a common memory space (or pool) for sharing variables between effects.
    /// <para>(Also see DirectX SDK: ID3D10EffectPool)</para>
    /// </summary>
    public ref class EffectPool :
        public DirectUnknown
    {
    public: 
        /// <summary>
        /// Get the effect that created the effect pool.
        /// <para>(Also see DirectX SDK: ID3D10EffectPool::AsEffect)</para>
        /// </summary>
        Effect^ AsEffect();
    internal:
        EffectPool()
        {
        }
    internal:

        EffectPool(ID3D10EffectPool* pNativeID3D10EffectPool)
        {
            Attach(pNativeID3D10EffectPool);
        }
    };
} } } }
