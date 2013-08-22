//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

ref class EffectBlendVariable;
ref class EffectConstantBuffer;
ref class EffectDepthStencilVariable;
ref class EffectDepthStencilViewVariable;
ref class EffectMatrixVariable;
ref class EffectRasterizerVariable;
ref class EffectRenderTargetViewVariable;
ref class EffectSamplerVariable;
ref class EffectScalarVariable;
ref class EffectShaderVariable;
ref class EffectShaderResourceVariable;
ref class EffectStringVariable;
ref class EffectVectorVariable;
ref class EffectVariable;
ref class EffectType;

    /// <summary>
    /// The EffectVariable interface is the base class for all effect variables.
    /// <para>(Also see DirectX SDK: ID3D10EffectVariable)</para>
    /// </summary>
    public ref class EffectVariable : public DirectObject
    {
    public: 
        /// <summary>
        /// Get a effect-blend variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsBlend)</para>
        /// </summary>
        EffectBlendVariable^ AsBlend();

        /// <summary>
        /// Get a constant buffer.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsConstantBuffer)</para>
        /// </summary>
        EffectConstantBuffer^ AsConstantBuffer();

        /// <summary>
        /// Get a depth-stencil variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsDepthStencil)</para>
        /// </summary>
        EffectDepthStencilVariable^ AsDepthStencil();

        /// <summary>
        /// Get a depth-stencil-view variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsDepthStencilView)</para>
        /// </summary>
        EffectDepthStencilViewVariable^ AsDepthStencilView();

        /// <summary>
        /// Get a matrix variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsMatrix)</para>
        /// </summary>
        EffectMatrixVariable^ AsMatrix();

        /// <summary>
        /// Get a rasterizer variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsRasterizer)</para>
        /// </summary>
        EffectRasterizerVariable^ AsRasterizer();

        /// <summary>
        /// Get a render-target-view variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsRenderTargetView)</para>
        /// </summary>
        EffectRenderTargetViewVariable^ AsRenderTargetView();

        /// <summary>
        /// Get a sampler variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsSampler)</para>
        /// </summary>
        EffectSamplerVariable^ AsSampler();

        /// <summary>
        /// Get a scalar variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsScalar)</para>
        /// </summary>
        EffectScalarVariable^ AsScalar();

        /// <summary>
        /// Get a shader variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsShader)</para>
        /// </summary>
        EffectShaderVariable^ AsShader();

        /// <summary>
        /// Get a shader-resource variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsShaderResource)</para>
        /// </summary>
        EffectShaderResourceVariable^ AsShaderResource();

        /// <summary>
        /// Get a string variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsString)</para>
        /// </summary>
        EffectStringVariable^ AsString();

        /// <summary>
        /// Get a vector variable.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::AsVector)</para>
        /// </summary>
        EffectVectorVariable^ AsVector();

        /// <summary>
        /// Get an annotation by index.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetAnnotationByIndex)</para>
        /// </summary>
        /// <param name="index">A zero-based index.</param>
        EffectVariable^ GetAnnotationByIndex(UInt32 index);

        /// <summary>
        /// Get an annotation by name.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetAnnotationByName)</para>
        /// </summary>
        /// <param name="name">The annotation name.</param>
        EffectVariable^ GetAnnotationByName(String^ name);

        /// <summary>
        /// Get a description.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetDesc)</para>
        /// </summary>
        /// <returns>A effect-variable description (see <see cref="EffectVariableDescription"/>)<seealso cref="EffectVariableDescription"/>.</returns>
        property EffectVariableDescription Description
        {
            EffectVariableDescription get();
        }

        /// <summary>
        /// Get an array element.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetElement)</para>
        /// </summary>
        /// <param name="index">A zero-based index; otherwise 0.</param>
        EffectVariable^ GetElement(UInt32 index);

        /// <summary>
        /// Get a structure member by index.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetMemberByIndex)</para>
        /// </summary>
        /// <param name="index">A zero-based index.</param>
        EffectVariable^ GetMemberByIndex(UInt32 index);

        /// <summary>
        /// Get a structure member by name.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetMemberByName)</para>
        /// </summary>
        /// <param name="name">Member name.</param>
        EffectVariable^ GetMemberByName(String^ name);

        /// <summary>
        /// Get a structure member by semantic.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetMemberBySemantic)</para>
        /// </summary>
        /// <param name="semantic">The semantic.</param>
        EffectVariable^ GetMemberBySemantic(String^ semantic);

        /// <summary>
        /// Get a constant buffer.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetParentConstantBuffer)</para>
        /// </summary>
        EffectConstantBuffer^ GetParentConstantBuffer();

        /// <summary>
        /// Get type information.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetType)</para>
        /// </summary>
        EffectType^ GetType();

        /// <summary>
        /// Compare the data type with the data stored.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::IsValid)</para>
        /// </summary>
        property Boolean IsValid
        {
            Boolean get();
        }

        /// <summary>
        /// Get data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::GetRawValue)</para>
        /// </summary>
        /// <param name="size">The number of bytes to get.</param>
        array<unsigned char>^ GetRawValue(UInt32 size);

        /// <summary>
        /// Set data.
        /// <para>(Also see DirectX SDK: ID3D10EffectVariable::SetRawValue)</para>
        /// </summary>
        /// <param name="data">The variable to set.</param>
        void SetRawValue(array<unsigned char>^ data);

    internal:
        EffectVariable()
        { }

        EffectVariable(ID3D10EffectVariable* pNativeID3D10EffectVariable)
            : DirectObject(pNativeID3D10EffectVariable)
        { }

        EffectVariable(ID3D10EffectVariable* pNativeID3D10EffectVariable, bool deletable) 
            :  DirectObject(pNativeID3D10EffectVariable, deletable)
        { }

    };
} } } }
