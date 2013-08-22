// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectVariable.h"

#include "D3D10EffectBlendVariable.h"
#include "D3D10EffectConstantBuffer.h"
#include "D3D10EffectDepthStencilVariable.h"
#include "D3D10EffectDepthStencilViewVariable.h"
#include "D3D10EffectMatrixVariable.h"
#include "D3D10EffectRasterizerVariable.h"
#include "D3D10EffectRenderTargetViewVariable.h"
#include "D3D10EffectSamplerVariable.h"
#include "D3D10EffectScalarVariable.h"
#include "D3D10EffectShaderVariable.h"
#include "D3D10EffectShaderResourceVariable.h"
#include "D3D10EffectStringVariable.h"
#include "D3D10EffectVectorVariable.h"
#include "D3D10EffectVariable.h"
#include "D3D10EffectType.h"

using namespace msclr::interop;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

EffectBlendVariable^ EffectVariable::AsBlend()
{
    ID3D10EffectBlendVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsBlend();
    return returnValue == NULL ? nullptr : gcnew EffectBlendVariable(returnValue, false);
}

EffectConstantBuffer^ EffectVariable::AsConstantBuffer()
{
    ID3D10EffectConstantBuffer* returnValue = GetInterface<ID3D10EffectVariable>()->AsConstantBuffer();
    return returnValue == NULL ? nullptr : gcnew EffectConstantBuffer(returnValue, false);
}

EffectDepthStencilVariable^ EffectVariable::AsDepthStencil()
{
    ID3D10EffectDepthStencilVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsDepthStencil();
    return returnValue == NULL ? nullptr : gcnew EffectDepthStencilVariable(returnValue, false);
}

EffectDepthStencilViewVariable^ EffectVariable::AsDepthStencilView()
{
    ID3D10EffectDepthStencilViewVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsDepthStencilView();
    return returnValue == NULL ? nullptr : gcnew EffectDepthStencilViewVariable(returnValue, false);
}

EffectMatrixVariable^ EffectVariable::AsMatrix()
{
    ID3D10EffectMatrixVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsMatrix();
    return returnValue == NULL ? nullptr : gcnew EffectMatrixVariable(returnValue, false);
}

EffectRasterizerVariable^ EffectVariable::AsRasterizer()
{
    ID3D10EffectRasterizerVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsRasterizer();
    return returnValue == NULL ? nullptr : gcnew EffectRasterizerVariable(returnValue, false);
}

EffectRenderTargetViewVariable^ EffectVariable::AsRenderTargetView()
{
    ID3D10EffectRenderTargetViewVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsRenderTargetView();
    return returnValue == NULL ? nullptr : gcnew EffectRenderTargetViewVariable(returnValue, false);
}

EffectSamplerVariable^ EffectVariable::AsSampler()
{
    ID3D10EffectSamplerVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsSampler();
    return returnValue == NULL ? nullptr : gcnew EffectSamplerVariable(returnValue, false);
}

EffectScalarVariable^ EffectVariable::AsScalar()
{
    ID3D10EffectScalarVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsScalar();
    return returnValue == NULL ? nullptr : gcnew EffectScalarVariable(returnValue, false);
}

EffectShaderVariable^ EffectVariable::AsShader()
{
    ID3D10EffectShaderVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsShader();
    return returnValue == NULL ? nullptr : gcnew EffectShaderVariable(returnValue, false);
}

EffectShaderResourceVariable^ EffectVariable::AsShaderResource()
{
    ID3D10EffectShaderResourceVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsShaderResource();
    return returnValue == NULL ? nullptr : gcnew EffectShaderResourceVariable(returnValue, false);
}

EffectStringVariable^ EffectVariable::AsString()
{
    ID3D10EffectStringVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsString();
    return returnValue == NULL ? nullptr : gcnew EffectStringVariable(returnValue, false);
}

EffectVectorVariable^ EffectVariable::AsVector()
{
    ID3D10EffectVectorVariable* returnValue = GetInterface<ID3D10EffectVariable>()->AsVector();
    return returnValue == NULL ? nullptr : gcnew EffectVectorVariable(returnValue, false);
}

EffectVariable^ EffectVariable::GetAnnotationByIndex(UInt32 index)
{
    ID3D10EffectVariable* returnValue = GetInterface<ID3D10EffectVariable>()->GetAnnotationByIndex(static_cast<UINT>(index));
    return returnValue == NULL ? nullptr : gcnew EffectVariable(returnValue, false);
}

EffectVariable^ EffectVariable::GetAnnotationByName(String^ name)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(name);

    try
    {
        ID3D10EffectVariable * returnValue = GetInterface<ID3D10EffectVariable>()->GetAnnotationByName(static_cast<char*>(ptr.ToPointer()));

        return returnValue ? gcnew EffectVariable(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

EffectVariableDescription EffectVariable::Description::get()
{
    D3D10_EFFECT_VARIABLE_DESC nativeDesc = {0};
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVariable>()->GetDesc(&nativeDesc));

    return EffectVariableDescription(nativeDesc);
}

EffectVariable^ EffectVariable::GetElement(UInt32 index)
{
    ID3D10EffectVariable* returnValue = GetInterface<ID3D10EffectVariable>()->GetElement(static_cast<UINT>(index));
    return returnValue == NULL ? nullptr : gcnew EffectVariable(returnValue, false);
}

EffectVariable^ EffectVariable::GetMemberByIndex(UInt32 index)
{
    ID3D10EffectVariable* returnValue = GetInterface<ID3D10EffectVariable>()->GetMemberByIndex(static_cast<UINT>(index));
    return returnValue == NULL ? nullptr : gcnew EffectVariable(returnValue, false);
}

EffectVariable^ EffectVariable::GetMemberByName(String^ name)
{

    IntPtr ptr = Marshal::StringToHGlobalAnsi(name);

    try
    {
        ID3D10EffectVariable * returnValue = GetInterface<ID3D10EffectVariable>()->GetMemberByName(static_cast<char*>(ptr.ToPointer()));

        return returnValue ? gcnew EffectVariable(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

EffectVariable^ EffectVariable::GetMemberBySemantic(String^ semantic)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(semantic);

    try
    {
        ID3D10EffectVariable * returnValue = GetInterface<ID3D10EffectVariable>()->GetMemberBySemantic(static_cast<char*>(ptr.ToPointer()));

        return returnValue ? gcnew EffectVariable(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

EffectConstantBuffer^ EffectVariable::GetParentConstantBuffer()
{
    ID3D10EffectConstantBuffer* returnValue = GetInterface<ID3D10EffectVariable>()->GetParentConstantBuffer();
    return returnValue == NULL ? nullptr : gcnew EffectConstantBuffer(returnValue, false);
}


EffectType^ EffectVariable::GetType()
{
    ID3D10EffectType* returnValue = GetInterface<ID3D10EffectVariable>()->GetType();
    return returnValue == NULL ? nullptr : gcnew EffectType(returnValue);
}

Boolean EffectVariable::IsValid::get()
{
    return GetInterface<ID3D10EffectVariable>()->IsValid() != 0;
}

array<unsigned char>^ EffectVariable::GetRawValue(UInt32 count)
{
    if (count == 0)
    {
        return nullptr;
    }

    array<unsigned char>^ data = gcnew array<unsigned char>(count);
    pin_ptr<unsigned char> ptr = &data[0];
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVariable>()->GetRawValue(
        (void*) ptr, 0, count));

    return data;
}

void EffectVariable::SetRawValue(array<unsigned char>^ data)
{
    pin_ptr<unsigned char> ptr = data != nullptr ? &data[0] : nullptr;

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVariable>()->SetRawValue(
        data == nullptr ? NULL : (void*) ptr, 
        0, 
        data == nullptr ? 0 : data->Length));
}

