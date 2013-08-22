// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIAdapter1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

AdapterDescription1 Adapter1::Description1::get()
{
    if (!init)
    {
        DXGI_ADAPTER_DESC1 nativeDesc;
        CommonUtils::VerifyResult(GetInterface<IDXGIAdapter1>()->GetDesc1(&nativeDesc));
        m_desc1 = AdapterDescription1(nativeDesc);
        init = true;
    }

    return m_desc1;
}

