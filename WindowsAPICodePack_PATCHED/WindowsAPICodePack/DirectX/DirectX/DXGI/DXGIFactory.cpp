// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include "CommonUtils.h"
#include "LibraryLoader.h"
#include "Direct3D11/D3D11Device.h"
#include "Direct3D10/D3D10Device.h"
#include "DXGIFactory.h"
#include "DXGIAdapter.h"
#include "DXGISwapChain.h"

using namespace System::Collections::Generic;
using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;

typedef HRESULT (*CreateDXGIFactoryFuncPtr)(REFIID riid, void **ppFactory);

DXGIFactory^ DXGIFactory::CreateFactory()
{
    CreateDXGIFactoryFuncPtr createFuncPtr = 
        (CreateDXGIFactoryFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            DXGILibrary, "CreateDXGIFactory");

    IDXGIFactory * pNativeIDXGIFactory = NULL;

    CommonUtils::VerifyResult(
        (*createFuncPtr)(__uuidof(IDXGIFactory), (void**)(&pNativeIDXGIFactory)));

    return gcnew DXGIFactory(pNativeIDXGIFactory);
}

SwapChain^ DXGIFactory::CreateSwapChain(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ device, SwapChainDescription description)
{
    CommonUtils::CheckNull(device, "device");

    DXGI_SWAP_CHAIN_DESC nativeDesc = {0};
    description.CopyTo(&nativeDesc);
    
    IDXGISwapChain* tempoutSwapChain = NULL;

    CommonUtils::VerifyResult(
        GetInterface<IDXGIFactory>()->CreateSwapChain(
            device->GetInterface<ID3D10Device>(), 
            &nativeDesc, 
            &tempoutSwapChain));

    return tempoutSwapChain ? gcnew SwapChain(tempoutSwapChain) : nullptr;
}

SwapChain^ DXGIFactory::CreateSwapChain(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ device, SwapChainDescription description)
{
    CommonUtils::CheckNull(device, "device");

    DXGI_SWAP_CHAIN_DESC nativeDesc = {0};
    description.CopyTo(&nativeDesc);
    
    IDXGISwapChain* tempoutSwapChain = NULL;

    CommonUtils::VerifyResult(
        GetInterface<IDXGIFactory>()->CreateSwapChain(
            device->GetInterface<ID3D11Device>(), 
            &nativeDesc, 
            &tempoutSwapChain));

    return tempoutSwapChain ? gcnew SwapChain(tempoutSwapChain) : nullptr;
}

ReadOnlyCollection<Adapter^>^ DXGIFactory::GetAdapters()
{    
    IList<Adapter^>^ adaptersCache = gcnew List<Adapter^>();

    int i = 0;
    while (true)
    {
        IDXGIAdapter* tempAdapter;

        if (DXGI_ERROR_NOT_FOUND != GetInterface<IDXGIFactory>()->EnumAdapters(i++, &tempAdapter))
            adaptersCache->Add(gcnew Adapter(tempAdapter));
        else
            break;
    }

    return gcnew ReadOnlyCollection<Adapter^>(adaptersCache);
}

Adapter^ DXGIFactory::GetAdapter(UInt32 index)
{    
    IDXGIAdapter* tempAdapter = NULL;

    CommonUtils::VerifyResult(GetInterface<IDXGIFactory>()->EnumAdapters(index, &tempAdapter));
    return tempAdapter == NULL ? nullptr : gcnew Adapter(tempAdapter);
}

IntPtr DXGIFactory::GetWindowAssociation()
{
    HWND hWnd = 0;
    CommonUtils::VerifyResult(GetInterface<IDXGIFactory>()->GetWindowAssociation(&hWnd));
    
    return IntPtr(hWnd);
}

void DXGIFactory::MakeWindowAssociation(IntPtr WindowHandle, MakeWindowAssociationFlags Flags)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIFactory>()->MakeWindowAssociation(static_cast<HWND>(WindowHandle.ToPointer()), static_cast<UINT>(Flags)));
}

