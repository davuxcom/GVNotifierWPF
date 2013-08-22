// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectDepthStencilViewVariable.h"

#include "D3D10DepthStencilView.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

DepthStencilView^ EffectDepthStencilViewVariable::GetDepthStencil()
{
    ID3D10DepthStencilView* tempoutResource = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectDepthStencilViewVariable>()->GetDepthStencil(&tempoutResource));
    
    return tempoutResource == NULL ? nullptr : gcnew DepthStencilView(tempoutResource);
}

ReadOnlyCollection<DepthStencilView^>^ EffectDepthStencilViewVariable::GetDepthStencilArray(UInt32 offset, UInt32 count)
{
    vector<ID3D10DepthStencilView*> tempVector(count);
    CommonUtils::VerifyResult(
        GetInterface<ID3D10EffectDepthStencilViewVariable>()->GetDepthStencilArray(&tempVector[0], static_cast<UINT>(offset), static_cast<UINT>(count)));

    return CommonUtils::GetCollection<DepthStencilView, ID3D10DepthStencilView>(count, tempVector);
}

void EffectDepthStencilViewVariable::SetDepthStencil(DepthStencilView^ resource)
{

    CommonUtils::CheckNull(resource,"resource");

    CommonUtils::VerifyResult(GetInterface<ID3D10EffectDepthStencilViewVariable>()->SetDepthStencil(resource->GetInterface<ID3D10DepthStencilView>()));
}

void EffectDepthStencilViewVariable::SetDepthStencilArray(IEnumerable<DepthStencilView^>^ resources, UInt32 offset)
{
    vector<ID3D10DepthStencilView*> itemsVector;

    UINT count = CommonUtils::FillIUnknownsVector<DepthStencilView, ID3D10DepthStencilView>(resources, itemsVector);

    CommonUtils::VerifyResult(
        GetInterface<ID3D10EffectDepthStencilViewVariable>()->SetDepthStencilArray(
        count == 0 ? NULL : &(itemsVector[0]), static_cast<UINT>(offset), static_cast<UINT>(count)));
}

