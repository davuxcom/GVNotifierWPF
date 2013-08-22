// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Resource.h"
#include "DXGI/DXGISurface.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

UInt32 D3DResource::EvictionPriority::get()
{
    return safe_cast<UInt32>(GetInterface<ID3D10Resource>()->GetEvictionPriority());
}

ResourceDimension D3DResource::Type::get()
{
    D3D10_RESOURCE_DIMENSION tempoutrType;
    GetInterface<ID3D10Resource>()->GetType(&tempoutrType);
    return safe_cast<ResourceDimension>(tempoutrType);
}

void D3DResource::EvictionPriority::set(UInt32 value)
{
    GetInterface<ID3D10Resource>()->SetEvictionPriority(static_cast<UINT>(value));
}

// Get associated DXGI suraface. If none is associated - throw an InvalidCastException.
Surface^ D3DResource::GetDXGISurface()
{
    IDXGISurface* surface = NULL;

    CommonUtils::VerifyResult ( GetInterface<ID3D10Resource>()->QueryInterface(
            __uuidof(IDXGISurface),
            (void**)&surface));

    return surface ? gcnew Surface(surface) : nullptr;
}
