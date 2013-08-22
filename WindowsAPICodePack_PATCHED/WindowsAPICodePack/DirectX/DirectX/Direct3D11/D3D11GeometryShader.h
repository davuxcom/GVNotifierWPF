//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A geometry-shader class manages an executable program (a geometry shader) that controls the geometry-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11GeometryShader)</para>
    /// </summary>
    public ref class GeometryShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    internal:
        GeometryShader()
        {
        }
    internal:

        GeometryShader(ID3D11GeometryShader* pNativeID3D11GeometryShader)
        {
            Attach(pNativeID3D11GeometryShader);
        }

    };
} } } }
