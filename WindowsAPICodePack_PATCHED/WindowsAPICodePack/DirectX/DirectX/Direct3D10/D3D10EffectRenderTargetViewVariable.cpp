// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectRenderTargetViewVariable.h"

#include "D3D10RenderTargetView.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

RenderTargetView^ EffectRenderTargetViewVariable::GetRenderTarget()
{
    ID3D10RenderTargetView* resource = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectRenderTargetViewVariable>()->GetRenderTarget(&resource));
 
    return resource == NULL ? nullptr : gcnew RenderTargetView(resource);
}

ReadOnlyCollection<RenderTargetView^>^ EffectRenderTargetViewVariable::GetRenderTargetCollection(UInt32 offset, UInt32 count)
{
    vector<ID3D10RenderTargetView*> resourcesVector(count);
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectRenderTargetViewVariable>()->GetRenderTargetArray(&resourcesVector[0], static_cast<UINT>(offset), static_cast<UINT>(count)));

    return CommonUtils::GetCollection<RenderTargetView, ID3D10RenderTargetView>(count, resourcesVector);    
}

void EffectRenderTargetViewVariable::SetRenderTarget(RenderTargetView^ resource)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10EffectRenderTargetViewVariable>()->SetRenderTarget(
        resource == nullptr ? NULL : resource->GetInterface<ID3D10RenderTargetView>()));
}

void EffectRenderTargetViewVariable::SetRenderTargetCollection(IEnumerable<RenderTargetView^>^ resources, UInt32 offset)
{
    vector<ID3D10RenderTargetView*> resourcesVector;

    UINT count = CommonUtils::FillIUnknownsVector<RenderTargetView, ID3D10RenderTargetView>(resources, resourcesVector);

    CommonUtils::VerifyResult(
        GetInterface<ID3D10EffectRenderTargetViewVariable>()->SetRenderTargetArray(
        count == 0 ? NULL : &resourcesVector[0], static_cast<UINT>(offset), count));    
}

