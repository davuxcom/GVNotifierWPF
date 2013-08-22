// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIKeyedMutex.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

void KeyedMutex::AcquireSync(UInt64 Key, DWORD dwMilliseconds)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIKeyedMutex>()->AcquireSync(safe_cast<UINT64>(Key), safe_cast<DWORD>(dwMilliseconds)));
}

void KeyedMutex::ReleaseSync(UInt64 Key)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIKeyedMutex>()->ReleaseSync(safe_cast<UINT64>(Key)));
}

