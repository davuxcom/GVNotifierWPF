// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Effect.h"

#include "D3D10EffectConstantBuffer.h"
#include "D3D10Device.h"
#include "D3D10Device1.h"
#include "D3D10EffectTechnique.h"
#include "D3D10EffectVariable.h"

using namespace System::Runtime::InteropServices;
using namespace msclr::interop;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

EffectConstantBuffer^ Effect::GetConstantBufferByIndex(UInt32 index)
{
    ID3D10EffectConstantBuffer* returnValue = GetInterface<ID3D10Effect>()->GetConstantBufferByIndex(static_cast<UINT>(index));
    return gcnew EffectConstantBuffer(returnValue);
}

EffectConstantBuffer^ Effect::GetConstantBufferByName(String^ name)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(name);

    try
    {
        ID3D10EffectConstantBuffer * returnValue = GetInterface<ID3D10Effect>()->GetConstantBufferByName(static_cast<char*>(ptr.ToPointer()));
        
        return returnValue ? gcnew EffectConstantBuffer(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

EffectDescription Effect::Description::get()
{
    EffectDescription desc;
    pin_ptr<EffectDescription> ptr = &desc;

    CommonUtils::VerifyResult(GetInterface<ID3D10Effect>()->GetDesc((D3D10_EFFECT_DESC*)ptr));
    
    return desc;
}

D3DDevice^ Effect::GetDevice()
{
    ID3D10Device* tempoutDevice = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Effect>()->GetDevice(&tempoutDevice));
    
    return tempoutDevice == NULL ? nullptr : gcnew D3DDevice(tempoutDevice);
}

EffectTechnique^ Effect::GetTechniqueByIndex(UInt32 index)
{
    ID3D10EffectTechnique* returnValue = GetInterface<ID3D10Effect>()->GetTechniqueByIndex(static_cast<UINT>(index));
    return gcnew EffectTechnique(returnValue);
}

EffectTechnique^ Effect::GetTechniqueByName(String^ name)
{

    IntPtr ptr = Marshal::StringToHGlobalAnsi(name);

    try
    {
        ID3D10EffectTechnique * returnValue =  GetInterface<ID3D10Effect>()->GetTechniqueByName(static_cast<char*>(ptr.ToPointer()));

        return returnValue ? gcnew EffectTechnique(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

EffectVariable^ Effect::GetVariableByIndex(UInt32 index)
{
    return gcnew EffectVariable(GetInterface<ID3D10Effect>()->GetVariableByIndex(static_cast<UINT>(index)), false);
}

EffectVariable^ Effect::GetVariableByName(String^ name)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(name);

    try
    {
        ID3D10EffectVariable * returnValue =  GetInterface<ID3D10Effect>()->GetVariableByName(static_cast<char*>(ptr.ToPointer()));
        return returnValue ? gcnew EffectVariable(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

EffectVariable^ Effect::GetVariableBySemantic(String^ semantic)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(semantic);

    try
    {
        ID3D10EffectVariable * returnValue = GetInterface<ID3D10Effect>()->GetVariableBySemantic(static_cast<char*>(ptr.ToPointer()));

        return returnValue ? gcnew EffectVariable(returnValue, false) : nullptr;
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

Boolean Effect::IsOptimized::get()
{
    return GetInterface<ID3D10Effect>()->IsOptimized() != 0;
}

Boolean Effect::IsPool::get()
{
    return GetInterface<ID3D10Effect>()->IsPool() != 0;
}

Boolean Effect::IsValid::get()
{
    return GetInterface<ID3D10Effect>()->IsValid() != 0;
}

void Effect::Optimize()
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Effect>()->Optimize());
}

