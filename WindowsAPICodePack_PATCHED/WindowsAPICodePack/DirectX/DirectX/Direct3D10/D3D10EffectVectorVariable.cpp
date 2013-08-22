// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectVectorVariable.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Vector4B EffectVectorVariable::BoolVector::get()
{
    Vector4B arr;
    pin_ptr<Boolean> pArr = &arr.X;

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->GetBoolVector((BOOL*)pArr));

    return arr;
}

array<Vector4B>^ EffectVectorVariable::GetBoolVectorArray(UInt32 count)
{
    if (count == 0)
        return nullptr;

    array<Vector4B>^ arr = gcnew array<Vector4B>(count);
    pin_ptr<Vector4B> pArr = &arr[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->GetBoolVectorArray((BOOL*) pArr, 0, count));

    return arr;
}

Vector4F EffectVectorVariable::FloatVector::get()
{
    Vector4F arr;
    pin_ptr<Single> pArr = &arr.X;

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->GetFloatVector(pArr));

    return arr;
}

array<Vector4F>^  EffectVectorVariable::GetFloatVectorArray(UInt32 count)
{
    if (count == 0)
        return nullptr;

    array<Vector4F>^ arr = gcnew array<Vector4F>(count);
    pin_ptr<Vector4F> pArr = &arr[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->GetFloatVectorArray((FLOAT*)pArr, 0, count));

    return arr;
}

Vector4I EffectVectorVariable::IntVector::get()
{
    Vector4I arr;
    pin_ptr<int> pArr = &arr.X;

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->GetIntVector(pArr));

    return arr;
}

array<Vector4I>^ EffectVectorVariable::GetIntVectorArray(UInt32 count)
{
    if (count == 0)
        return nullptr;

    array<Vector4I>^ arr = gcnew array<Vector4I>(count);
    pin_ptr<Vector4I> pArr = &arr[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->GetIntVectorArray((int*)pArr, 0, count));

    return arr;
}

void EffectVectorVariable::BoolVector::set(Vector4B data)
{
    pin_ptr<Boolean> pArr = &data.X;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->SetBoolVector((BOOL*)pArr));
}

void EffectVectorVariable::SetBoolVectorArray(array<Vector4B>^ data)
{
    if (data == nullptr)
    {
        throw gcnew ArgumentNullException("data", "Must be a valid array.");
    }

    pin_ptr<Vector4B> pArr = &data[0];
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->SetBoolVectorArray((BOOL*)pArr, 0, data->Length));
}

void EffectVectorVariable::FloatVector::set(Vector4F data)
{
    pin_ptr<FLOAT> dataArray = &data.X;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->SetFloatVector(dataArray));
}

void EffectVectorVariable::SetFloatVectorArray(array<Vector4F>^ data)
{
    if (data == nullptr)
    {
        throw gcnew ArgumentNullException("data", "Must be a valid array.");
    }

    pin_ptr<float> pArr = &data[0].X;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->SetFloatVectorArray(pArr, 0, data->Length));
}

void EffectVectorVariable::IntVector::set(Vector4I data)
{
    pin_ptr<int> pArr = &data.X;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->SetIntVector(pArr));
}

void EffectVectorVariable::SetIntVectorArray(array<Vector4I>^ data)
{
    if (data == nullptr)
    {
        throw gcnew ArgumentNullException("data", "Must be a valid array.");
    }

    pin_ptr<Vector4I> pArr = &data[0];

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectVectorVariable>()->SetIntVectorArray((int*)pArr, 0, data->Length));
}

