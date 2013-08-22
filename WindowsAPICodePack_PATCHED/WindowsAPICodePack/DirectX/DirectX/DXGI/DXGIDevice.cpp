// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIDevice.h"
#include "DXGIResource.h"
#include "DXGISurface.h"
#include "DXGIAdapter.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

Adapter^ DXGIDevice::GetAdapter()
{
    IDXGIAdapter* tempoutAdapter = NULL;
    CommonUtils::VerifyResult(GetInterface<IDXGIDevice>()->GetAdapter(&tempoutAdapter));
    return (tempoutAdapter == NULL ? nullptr : gcnew Adapter(tempoutAdapter));
}

Int32 DXGIDevice::GPUThreadPriority::get()
{
    INT tempoutPriority;
    CommonUtils::VerifyResult(GetInterface<IDXGIDevice>()->GetGPUThreadPriority(&tempoutPriority));
    return tempoutPriority;
}

void DXGIDevice::GPUThreadPriority::set(Int32 value)
{
    if (value < -7 || value > 7)
    {
        throw gcnew ArgumentOutOfRangeException("value", "GPUThreadPriority valid range is -7 to +7, inclusive.");
    }

    CommonUtils::VerifyResult(GetInterface<IDXGIDevice>()->SetGPUThreadPriority(value));
}

array<Residency>^ DXGIDevice::QueryResourceResidency(IEnumerable<DXGIResource^>^ resources)
{
    vector<IDXGIResource*> resourcesVector;

    UINT count = CommonUtils::FillIUnknownsVector<DXGIResource, IDXGIResource>(resources, resourcesVector);
    if (count == 0)
        return nullptr;

    DXGI_RESIDENCY* residencyStatusArray = new DXGI_RESIDENCY[count];
    try
    {
        CommonUtils::VerifyResult(GetInterface<IDXGIDevice>()->QueryResourceResidency((IUnknown**)&resourcesVector[0], residencyStatusArray, count));

        array<Residency>^ returnArray = gcnew array<Residency>(count);
        pin_ptr<Residency> pinnedArray = &returnArray[0];
        memcpy(pinnedArray, residencyStatusArray, sizeof(DXGI_RESIDENCY) * count);
        return returnArray;
    }
    finally
    {
        delete [] residencyStatusArray;
    }
}

