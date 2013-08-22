//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A hull-shader class manages an executable program (a hull shader) that controls the hull-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11HullShader)</para>
    /// </summary>
    public ref class HullShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    internal:
        HullShader()
        {
        }
    internal:

        HullShader(ID3D11HullShader* pNativeID3D11HullShader)
        {
            Attach(pNativeID3D11HullShader);
        }

    };
} } } }
