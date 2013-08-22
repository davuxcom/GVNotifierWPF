// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectShaderResourceVariable.h"

#include "D3D10ShaderResourceView.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

ShaderResourceView^ EffectShaderResourceVariable::GetResource()
{
    ID3D10ShaderResourceView* tempoutResource = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectShaderResourceVariable>()->GetResource(&tempoutResource));
    
    return tempoutResource == NULL ? nullptr : gcnew ShaderResourceView(tempoutResource);
}

ReadOnlyCollection<ShaderResourceView^>^ EffectShaderResourceVariable::GetResourceArray(UInt32 offset, UInt32 count)
{
    vector<ID3D10ShaderResourceView*> resourceVector(count);

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectShaderResourceVariable>()->GetResourceArray(
        count == 0 ? NULL : &resourceVector[0], static_cast<UINT>(offset), static_cast<UINT>(count)));

    return CommonUtils::GetCollection<ShaderResourceView, ID3D10ShaderResourceView>(count, resourceVector);
}

void EffectShaderResourceVariable::SetResource(ShaderResourceView^ resource)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectShaderResourceVariable>()->SetResource(
        resource == nullptr ? NULL : resource->GetInterface<ID3D10ShaderResourceView>()));
}

void EffectShaderResourceVariable::SetResourceArray(IEnumerable<ShaderResourceView^>^ resources, UInt32 offset)
{
    vector<ID3D10ShaderResourceView*> resourceVector;
    UINT count = CommonUtils::FillIUnknownsVector<ShaderResourceView, ID3D10ShaderResourceView>(resources, resourceVector);

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectShaderResourceVariable>()->SetResourceArray(
        count == 0 ? NULL : &resourceVector[0], static_cast<UINT>(offset), static_cast<UINT>(count)));
}

