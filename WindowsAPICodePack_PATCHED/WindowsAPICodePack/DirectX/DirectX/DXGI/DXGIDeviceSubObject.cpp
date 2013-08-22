// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIDeviceSubObject.h"

#include "DXGIDevice.h"
#include "Direct3D11/D3D11Device.h"
#include "Direct3D10/D3D10Device.h"
#include "Direct3D10/D3D10Device1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ DeviceSubObject::GetDirect3D10Device()
{
    ID3D10Device* tempoutDevice = NULL;

    CommonUtils::VerifyResult(GetInterface<IDXGIDeviceSubObject>()->GetDevice(__uuidof(tempoutDevice), (void**)&tempoutDevice));

    return tempoutDevice == NULL ? nullptr : gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice(tempoutDevice);
}

Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice1^ DeviceSubObject::GetDirect3D10Device1()
{
    ID3D10Device1* tempoutDevice = NULL;

    CommonUtils::VerifyResult(GetInterface<IDXGIDeviceSubObject>()->GetDevice(__uuidof(tempoutDevice), (void**)&tempoutDevice));

    return tempoutDevice == NULL ? nullptr : gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice1(tempoutDevice);
}

Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ DeviceSubObject::GetDirect3D11Device()
{
    ID3D11Device* tempoutDevice = NULL;

    CommonUtils::VerifyResult(GetInterface<IDXGIDeviceSubObject>()->GetDevice(__uuidof(tempoutDevice), (void**)&tempoutDevice));

    return tempoutDevice == NULL ? nullptr : gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice(tempoutDevice);
}

Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice^ DeviceSubObject::GetDXGIDevice()
{
    IDXGIDevice* tempoutDevice = NULL;

    CommonUtils::VerifyResult(GetInterface<IDXGIDeviceSubObject>()->GetDevice(__uuidof(tempoutDevice), (void**)&tempoutDevice));

    return tempoutDevice == NULL ? nullptr : gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice(tempoutDevice);
}

