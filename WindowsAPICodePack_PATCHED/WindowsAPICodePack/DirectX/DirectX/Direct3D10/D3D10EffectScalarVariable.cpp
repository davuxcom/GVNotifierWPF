// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectScalarVariable.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Boolean EffectScalarVariable::BoolValue::get()
{
    BOOL tempoutValue;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->GetBool(&tempoutValue));
    
    return tempoutValue != 0;
}

array<Boolean>^ EffectScalarVariable::GetBoolArray(UInt32 count)
{
    array<Boolean>^ arr = gcnew array<Boolean>(count);
    pin_ptr<Boolean> pArr = &arr[0];
    
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->GetBoolArray((BOOL*)pArr, 0, count));
    
    return arr;
}

Single EffectScalarVariable::FloatValue::get()
{
    FLOAT tempoutValue;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->GetFloat(&tempoutValue));
    
    return tempoutValue;
}

array<Single>^ EffectScalarVariable::GetFloatArray(UInt32 count)
{
    array<Single>^ arr = gcnew array<Single>(count);
    pin_ptr<FLOAT> pArr = &arr[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->GetFloatArray(pArr, 0, count));
    
    return arr;
}

Int32 EffectScalarVariable::IntValue::get()
{
    int tempoutValue;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->GetInt(&tempoutValue));

    return tempoutValue;
}

array<int>^ EffectScalarVariable::GetIntArray(UInt32 count)
{
    array<Int32>^ arr = gcnew array<Int32>(count);
    pin_ptr<int> pArr = &arr[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->GetIntArray(pArr, 0, count));
    
    return arr;
}

void EffectScalarVariable::BoolValue::set(Boolean value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->SetBool(value != 0));
}

void EffectScalarVariable::SetBoolArray(array<Boolean>^ data)
{
    UINT count = data->Length;
    pin_ptr<Boolean> pArr = &data[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->SetBoolArray((BOOL*) pArr, 0, count));
}

void EffectScalarVariable::FloatValue::set(Single value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->SetFloat(value));
}

void EffectScalarVariable::SetFloatArray(array<Single>^ data)
{
    UINT count = data->Length;
    pin_ptr<Single> pArr = &data[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->SetFloatArray(pArr, 0, count));
}

void EffectScalarVariable::IntValue::set(int Value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->SetInt(Value));
}

void EffectScalarVariable::SetIntArray(array<Int32>^ data)
{
    UINT count = data->Length;
    pin_ptr<int> pArr = &data[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectScalarVariable>()->SetIntArray(NULL, 0, count));
}

