// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10ShaderReflectionVariable.h"

#include "D3D10ShaderReflectionType.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

ShaderVariableDescription ShaderReflectionVariable::Description::get()
{
    D3D10_SHADER_VARIABLE_DESC desc = {0};
    CommonUtils::VerifyResult(GetInterface<ID3D10ShaderReflectionVariable>()->GetDesc(&desc));
    return ShaderVariableDescription(desc);
}

ShaderReflectionType^ ShaderReflectionVariable::Type::get()
{
    ID3D10ShaderReflectionType* returnValue = GetInterface<ID3D10ShaderReflectionVariable>()->GetType();
    return returnValue == NULL ? nullptr : gcnew ShaderReflectionType(returnValue);
}

