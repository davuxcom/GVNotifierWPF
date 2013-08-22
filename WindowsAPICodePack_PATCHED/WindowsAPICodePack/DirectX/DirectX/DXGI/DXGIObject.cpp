// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIObject.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

generic <typename T> where T : DXGIObject
T DXGIObject::GetParent() 
{
    void* tempParent = NULL;
    GUID guid = CommonUtils::GetGuid(T::typeid);
    
    CommonUtils::VerifyResult(GetInterface<IDXGIObject>()->GetParent(guid, &tempParent));

    return CommonUtils::CreateIUnknownWrapper<T>(static_cast<IUnknown*>(tempParent));
}
