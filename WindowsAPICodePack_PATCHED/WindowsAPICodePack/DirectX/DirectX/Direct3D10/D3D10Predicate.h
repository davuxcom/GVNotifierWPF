//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D10Query.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;

    /// <summary>
    /// A predicate interface determines whether geometry should be processed depending on the results of a previous draw call.
    /// <para>(Also see DirectX SDK: ID3D10Predicate)</para>
    /// </summary>
    public ref class D3DPredicate :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DQuery
    {

    internal:
        D3DPredicate()
        { }

        D3DPredicate(ID3D10Predicate* pNativeID3D10Predicate) : D3DQuery(pNativeID3D10Predicate)
        { }
    };
} } } }
