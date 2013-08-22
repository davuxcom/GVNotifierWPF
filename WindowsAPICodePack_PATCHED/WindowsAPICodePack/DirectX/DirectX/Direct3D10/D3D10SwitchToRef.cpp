// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10SwitchToRef.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Boolean SwitchToRef::UseRef::get()
{
    return GetInterface<ID3D10SwitchToRef>()->GetUseRef() != 0;
}

void SwitchToRef::UseRef::set(Boolean value)
{
    GetInterface<ID3D10SwitchToRef>()->SetUseRef(safe_cast<BOOL>(UseRef));
}

