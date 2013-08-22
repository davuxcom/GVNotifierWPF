// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11SwitchToRef.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

Boolean SwitchToRef::GetUseRef()
{
    BOOL returnValue = GetInterface<ID3D11SwitchToRef>()->GetUseRef();
    return returnValue != 0;
}

Boolean SwitchToRef::SetUseRef(Boolean UseRef)
{
    BOOL returnValue = GetInterface<ID3D11SwitchToRef>()->SetUseRef(safe_cast<BOOL>(UseRef));
    return returnValue != 0;
}

