// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Resource.h"
#include "DXGI/DXGISurface.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

UInt32 D3DResource::EvictionPriority::get()
{
    return GetInterface<ID3D11Resource>()->GetEvictionPriority();
}

void D3DResource::EvictionPriority::set(UInt32 value)
{
    GetInterface<ID3D11Resource>()->SetEvictionPriority(static_cast<UINT>(value));
}

ResourceDimension D3DResource::Type::get()
{
    D3D11_RESOURCE_DIMENSION tempoutrType = D3D11_RESOURCE_DIMENSION_UNKNOWN;

    GetInterface<ID3D11Resource>()->GetType(&tempoutrType);

    return safe_cast<ResourceDimension>(tempoutrType);
}

Surface^ D3DResource::GetDXGISurface()
{
    IDXGISurface* surface = NULL;

    CommonUtils::VerifyResult ( GetInterface<ID3D11Resource>()->QueryInterface(
            __uuidof(IDXGISurface),
            (void**)&surface));

    return surface ? gcnew Surface(surface) : nullptr;
}
