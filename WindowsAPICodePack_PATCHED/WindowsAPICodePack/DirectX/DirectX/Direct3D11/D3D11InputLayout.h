//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// An input-layout interface accesses the input data for the input-assembler stage.
    /// <para>(Also see DirectX SDK: ID3D11InputLayout)</para>
    /// </summary>
    public ref class InputLayout :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    internal:
        InputLayout()
        {
        }

    internal:
        InputLayout(ID3D11InputLayout* pNativeID3D11InputLayout)
        {
            Attach(pNativeID3D11InputLayout);
        }
    };
} } } }
