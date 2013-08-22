// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIDevice1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

UInt32 DXGIDevice1::MaximumFrameLatency::get()
{
    UINT tempoutMaxLatency;
    CommonUtils::VerifyResult(GetInterface<IDXGIDevice1>()->GetMaximumFrameLatency(&tempoutMaxLatency));
    return tempoutMaxLatency;
}

void DXGIDevice1::MaximumFrameLatency::set(UInt32 value)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIDevice1>()->SetMaximumFrameLatency(static_cast<UINT>(value)));
}

