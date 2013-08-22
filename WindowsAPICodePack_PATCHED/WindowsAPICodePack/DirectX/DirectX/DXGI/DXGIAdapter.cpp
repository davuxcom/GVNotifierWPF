// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIAdapter.h"
#include "DXGIOutput.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;
using namespace System::Collections::Generic;

bool Adapter::CheckDeviceSupport(DeviceType deviceType)
{
    Int32 high, low;
    return CheckDeviceSupport(deviceType, high, low);
}

bool Adapter::CheckDeviceSupport(
            DeviceType deviceType, 
            [System::Runtime::InteropServices::Out] Int32 %UMDVersionMajor, 
            [System::Runtime::InteropServices::Out] Int32 %UMDVersionMinor )
{
    LARGE_INTEGER tempoutUMDVersion;
    GUID interfaceGuid;

    switch (deviceType)
    {
        case DeviceType::Direct3D_10_0:
            interfaceGuid = __uuidof(ID3D10Device);
            break;
        case DeviceType::Direct3D_10_1:
            interfaceGuid = __uuidof(ID3D10Device1);
            break;
        case DeviceType::Direct3D_11_0:
            interfaceGuid = __uuidof(ID3D11Device);
            break;
        default:
            throw gcnew ArgumentOutOfRangeException("Device type not supported.", "deviceType");
    }
    if (!SUCCEEDED(GetInterface<IDXGIAdapter>()->CheckInterfaceSupport(interfaceGuid, &tempoutUMDVersion)))
    {
        UMDVersionMajor = UMDVersionMinor = 0;
        return false;
    }
    else
    {
        UMDVersionMajor = tempoutUMDVersion.HighPart;
        UMDVersionMinor = tempoutUMDVersion.LowPart;
        return true;
    }
}

ReadOnlyCollection<Output^>^ Adapter::GetOutputs()
{
    int i = 0;
    IList<Output^>^ outputsCache = gcnew List<Output^>();
    while (true)
    {
        IDXGIOutput* tempoutOutput;

        if (DXGI_ERROR_NOT_FOUND != GetInterface<IDXGIAdapter>()->EnumOutputs(i++, &tempoutOutput))
            outputsCache->Add(gcnew Output(tempoutOutput));
        else
            break;
    }

    return gcnew ReadOnlyCollection<Output^>(outputsCache);
}

Output^ Adapter::GetOutput(UInt32 index)
{
    IDXGIOutput* tempoutOutput = NULL;
    CommonUtils::VerifyResult(GetInterface<IDXGIAdapter>()->EnumOutputs(index, &tempoutOutput));
    return tempoutOutput == NULL ? nullptr : gcnew Output(tempoutOutput);
}

AdapterDescription Adapter::Description::get()
{
    if (!init)
    {
        DXGI_ADAPTER_DESC nativeDesc;
        CommonUtils::VerifyResult(GetInterface<IDXGIAdapter>()->GetDesc(&nativeDesc));
        m_desc = AdapterDescription(nativeDesc);
        init = true;
    }

    return m_desc;
}
