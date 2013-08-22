// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIResource.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

ResourcePriority DXGIResource::EvictionPriority::get()
{
    UINT tempoutEvictionPriority;
    CommonUtils::VerifyResult(GetInterface<IDXGIResource>()->GetEvictionPriority(&tempoutEvictionPriority));
    return static_cast<ResourcePriority>(tempoutEvictionPriority);
}

void DXGIResource::EvictionPriority::set(ResourcePriority value)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIResource>()->SetEvictionPriority(static_cast<UINT>(value)));
}

IntPtr DXGIResource::SharedHandle::get()
{
    HANDLE tempoutSharedHandle;
    CommonUtils::VerifyResult(GetInterface<IDXGIResource>()->GetSharedHandle(&tempoutSharedHandle));
    return IntPtr(tempoutSharedHandle);
}

UsageOption DXGIResource::UsageFlags::get()
{
    DXGI_USAGE tempoutUsage;
    CommonUtils::VerifyResult(GetInterface<IDXGIResource>()->GetUsage(&tempoutUsage));
    return safe_cast<UsageOption>(tempoutUsage);
}
