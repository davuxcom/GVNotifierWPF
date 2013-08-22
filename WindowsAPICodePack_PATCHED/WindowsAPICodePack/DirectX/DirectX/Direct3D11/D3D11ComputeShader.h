//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A compute-shader class manages an executable program (a compute shader) that controls the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11ComputeShader)</para>
    /// </summary>
    public ref class ComputeShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    internal:
        ComputeShader()
        {
        }
    internal:

        ComputeShader(ID3D11ComputeShader* pNativeID3D11ComputeShader)
        {
            Attach(pNativeID3D11ComputeShader);
        }

    };
} } } }
