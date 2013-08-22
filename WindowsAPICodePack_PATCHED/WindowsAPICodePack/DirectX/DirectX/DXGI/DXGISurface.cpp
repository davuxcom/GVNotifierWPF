// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGISurface.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

SurfaceDescription Surface::Description::get()
{
    DXGI_SURFACE_DESC desc;

    CommonUtils::VerifyResult(GetInterface<IDXGISurface>()->GetDesc(&desc));

    return SurfaceDescription(desc);
}

MappedRect Surface::Map(MapOption flags)
{
    DXGI_MAPPED_RECT rect;
    CommonUtils::VerifyResult(GetInterface<IDXGISurface>()->Map(
        &rect, static_cast<UINT>(flags)));
    
    return MappedRect(rect);
}

void Surface::Unmap()
{
    CommonUtils::VerifyResult(GetInterface<IDXGISurface>()->Unmap());
}

