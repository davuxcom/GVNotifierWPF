// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Device1.h"
#include "LibraryLoader.h"

#include "D3D10Effect.h"
#include "D3D10BlendState1.h"
#include "D3D10Resource.h"
#include "D3D10ShaderResourceView1.h"
#include "DXGI/DXGIAdapter.h"
#include "DXGI/DXGISwapChain.h"

#pragma unmanaged

typedef HRESULT (*D3D10CreateEffectFromMemoryPtr)(
    void *pData,
    SIZE_T DataLength,
    UINT FXFlags,
    ID3D10Device *pDevice, 
    ID3D10EffectPool *pEffectPool,
    ID3D10Effect **ppEffect
);

HRESULT CreateEffectFromMemory1(                                     
    void *pData,
    SIZE_T DataLength,
    UINT FXFlags,
    ID3D10Device *pDevice, 
    ID3D10EffectPool *pEffectPool,
    ID3D10Effect **ppEffect)
{
    D3D10CreateEffectFromMemoryPtr createEffectFuncPtr = 
        (D3D10CreateEffectFromMemoryPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10_1Library, "D3D10CreateEffectFromMemory");

    HRESULT hr =
        (*createEffectFuncPtr)( 
            pData,
            DataLength,
            FXFlags,
            pDevice,
            pEffectPool,
            ppEffect);

    return hr;
}

#pragma managed
using namespace std;

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

typedef HRESULT (*D3D10CreateDeviceAndSwapChain1FuncPtr)(
    IDXGIAdapter *pAdapter,
    D3D10_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    D3D10_FEATURE_LEVEL1 HardwareLevel,
    UINT SDKVersion,
    DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
    IDXGISwapChain **ppSwapChain,    
    ID3D10Device1 **ppDevice
);

typedef HRESULT (*D3D10CreateDevice1FuncPtr)(
    IDXGIAdapter *pAdapter,
    D3D10_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    D3D10_FEATURE_LEVEL1 HardwareLevel,
    UINT SDKVersion,
    ID3D10Device1 **ppDevice
);

typedef HRESULT (*D3D10CreateEffectFromMemoryPtr)(
    void *pData,
    SIZE_T DataLength,
    UINT FXFlags,
    ID3D10Device *pDevice, 
    ID3D10EffectPool *pEffectPool,
    ID3D10Effect **ppEffect
);

D3DDevice1^ D3DDevice1::CreateDeviceAndSwapChain1(IntPtr windowHandle, [System::Runtime::InteropServices::Out] SwapChain^ % swapChain)
{
    D3D10CreateDeviceAndSwapChain1FuncPtr createFuncPtr = 
        (D3D10CreateDeviceAndSwapChain1FuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10_1Library, "D3D10CreateDeviceAndSwapChain1");

    RECT rc;
    GetClientRect( (HWND)windowHandle.ToPointer(), &rc );
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;


    UINT createDeviceFlags = 0;
#ifdef _DEBUG

// Make sure GetEnvironmentVariable is not defined
#ifdef GetEnvironmentVariable
#undef GetEnvironmentVariable
#endif

    if (!String::IsNullOrEmpty(Environment::GetEnvironmentVariable("DXSDK_DIR")))
    {
        createDeviceFlags  = D3D10_CREATE_DEVICE_DEBUG;
    }
#endif

    ID3D10Device1* pd3dDevice = NULL;
    IDXGISwapChain* pSwapChain = NULL;

    DXGI_SWAP_CHAIN_DESC sd = {0};

    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = (HWND)windowHandle.ToPointer();
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    array<D3D10_FEATURE_LEVEL1>^ featureLevels = 
    {
        D3D10_FEATURE_LEVEL_10_1,
        D3D10_FEATURE_LEVEL_10_0,
        D3D10_FEATURE_LEVEL_9_3,
        D3D10_FEATURE_LEVEL_9_2,
        D3D10_FEATURE_LEVEL_9_1
    };

    HRESULT hr = S_OK;
    for each (D3D10_FEATURE_LEVEL1 level in featureLevels)
    {
        hr = (*createFuncPtr)( NULL, D3D10_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags,
            level, D3D10_1_SDK_VERSION, &sd, &pSwapChain, &pd3dDevice);
        
        if (SUCCEEDED(hr))
        {
            break;
        }
    }

    if (FAILED(hr))
    {
        if (hr == E_FAIL)
        {
            throw gcnew Direct3DException("Attempted to create a device with the debug layer enabled and the layer is not installed.", (int)hr);
        }
        else
        {
            CommonUtils::VerifyResult(hr);
        }
    }

    swapChain = pSwapChain ? gcnew SwapChain(pSwapChain) : nullptr;

    return pd3dDevice ? gcnew D3DDevice1(pd3dDevice) : nullptr;
}

D3DDevice1^ D3DDevice1::CreateDeviceAndSwapChain1(Adapter^ adapter, Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DriverType driverType, String^ softwareRasterizerLibrary, CreateDeviceFlag flags, FeatureLevel hardwareLevel, SwapChainDescription swapChainDescription, [System::Runtime::InteropServices::Out] SwapChain^ % swapChain)
{
    DXGI_SWAP_CHAIN_DESC nativeDesc = {0};
    swapChainDescription.CopyTo(&nativeDesc);

    D3D10CreateDeviceAndSwapChain1FuncPtr createFuncPtr = 
        (D3D10CreateDeviceAndSwapChain1FuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10_1Library, "D3D10CreateDeviceAndSwapChain1");

    HINSTANCE softwareModule = NULL;
    if (!String::IsNullOrEmpty(softwareRasterizerLibrary))
    {
        softwareModule = CommonUtils::LoadDll(softwareRasterizerLibrary);
    }

    ID3D10Device1* pd3dDevice = NULL;
    IDXGISwapChain* pSwapChain = NULL;

    HRESULT hr = (*createFuncPtr)( 
        adapter == nullptr ? NULL : adapter->GetInterface<IDXGIAdapter>(), 
        static_cast<D3D10_DRIVER_TYPE>(driverType),
        softwareModule,
        static_cast<UINT>(flags),
        static_cast<D3D10_FEATURE_LEVEL1>(hardwareLevel),
        D3D10_1_SDK_VERSION, 
        &nativeDesc, 
        &pSwapChain, 
        &pd3dDevice);

    if (FAILED(hr))
    {
        if (hr == E_FAIL)
        {
            throw gcnew Direct3DException("Attempted to create a device with the debug layer enabled and the layer is not installed.", (int)hr);
        }
        else
        {
            CommonUtils::VerifyResult(hr);
        }
    }

    swapChain = pSwapChain ? gcnew SwapChain(pSwapChain) : nullptr;

    return pd3dDevice ? gcnew D3DDevice1(pd3dDevice) : nullptr;
}

D3DDevice1^ D3DDevice1::CreateDevice1()
{
    D3D10CreateDevice1FuncPtr createFuncPtr = 
        (D3D10CreateDevice1FuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10_1Library, "D3D10CreateDevice1");

    UINT createDeviceFlags = 0;
#ifdef _DEBUG

// Make sure GetEnvironmentVariable is not defined
#ifdef GetEnvironmentVariable
#undef GetEnvironmentVariable
#endif

    if (!String::IsNullOrEmpty(System::Environment::GetEnvironmentVariable("DXSDK_DIR")))
    {
        createDeviceFlags  = D3D10_CREATE_DEVICE_DEBUG;
    }
#endif

    ID3D10Device1* pd3dDevice = NULL;

    array<D3D10_FEATURE_LEVEL1>^ featureLevels = 
    {
        D3D10_FEATURE_LEVEL_10_1,
        D3D10_FEATURE_LEVEL_10_0,
        D3D10_FEATURE_LEVEL_9_3,
        D3D10_FEATURE_LEVEL_9_2,
        D3D10_FEATURE_LEVEL_9_1
    };

    HRESULT hr = S_OK;
    for each (D3D10_FEATURE_LEVEL1 level in featureLevels)
    {
        hr = (*createFuncPtr)( NULL, D3D10_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags,
            level, D3D10_1_SDK_VERSION, &pd3dDevice);

        if (SUCCEEDED(hr))
        {
            break;
        }
    }

    if (FAILED(hr))
    {
        if (hr == E_FAIL)
        {
            throw gcnew Direct3DException("Attempted to create a device with the debug layer enabled and the layer is not installed.", (int)hr);
        }
        else
        {
            CommonUtils::VerifyResult(hr);
        }
    }

    return pd3dDevice ? gcnew D3DDevice1(pd3dDevice) : nullptr;
}

D3DDevice1^ D3DDevice1::CreateDevice1(Adapter^ adapter,  Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DriverType driverType, String^ softwareRasterizerLibrary, CreateDeviceFlag flags, FeatureLevel hardwareLevel)
{
    D3D10CreateDevice1FuncPtr createFuncPtr = 
        (D3D10CreateDevice1FuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10_1Library, "D3D10CreateDevice1");

    ID3D10Device1* pd3dDevice = NULL;

    HINSTANCE softwareModule = NULL;
    if (!String::IsNullOrEmpty(softwareRasterizerLibrary))
    {
        softwareModule = CommonUtils::LoadDll(softwareRasterizerLibrary);
    }

    HRESULT hr =(*createFuncPtr)( 
        adapter == nullptr ? NULL : adapter->GetInterface<IDXGIAdapter>(), 
        static_cast<D3D10_DRIVER_TYPE>(driverType),
        softwareModule,
        static_cast<UINT>(flags),
        static_cast<D3D10_FEATURE_LEVEL1>(hardwareLevel),
        D3D10_1_SDK_VERSION, 
        &pd3dDevice);

    if (FAILED(hr))
    {
        if (hr == E_FAIL)
        {
            throw gcnew Direct3DException("Attempted to create a device with the debug layer enabled and the layer is not installed.", (int)hr);
        }
        else
        {
            CommonUtils::VerifyResult(hr);
        }
    }

    return pd3dDevice ? gcnew D3DDevice1(pd3dDevice) : nullptr;
}


BlendState1^ D3DDevice1::CreateBlendState1(BlendDescription1 BlendStateDescription)
{
    ID3D10BlendState1* tempoutBlendState = NULL;
    D3D10_BLEND_DESC1 desc;

    BlendStateDescription.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device1>()->CreateBlendState1(
        &desc, &tempoutBlendState));
    
    return tempoutBlendState == NULL ? nullptr : gcnew BlendState1(tempoutBlendState);
}

ShaderResourceView1^ D3DDevice1::CreateShaderResourceView1(D3DResource^ Resource, ShaderResourceViewDescription1 Description)
{
    ID3D10ShaderResourceView1* tempoutSRView = NULL;

    pin_ptr<ShaderResourceViewDescription1> ptr = &Description;

    CommonUtils::VerifyResult(GetInterface<ID3D10Device1>()->CreateShaderResourceView1(
        Resource->GetInterface<ID3D10Resource>(), (D3D10_SHADER_RESOURCE_VIEW_DESC1*)ptr, &tempoutSRView));

    return tempoutSRView == NULL ? nullptr : gcnew ShaderResourceView1(tempoutSRView);
}

FeatureLevel D3DDevice1::DeviceFeatureLevel::get()
{
    return static_cast<FeatureLevel>(GetInterface<ID3D10Device1>()->GetFeatureLevel());
}

Effect^ D3DDevice1::CreateEffectFromCompiledBinary( BinaryReader^ binaryEffect, int effectFlags, EffectPool^ effectPool )
{
    array<unsigned char>^ data = binaryEffect->ReadBytes((int)binaryEffect->BaseStream->Length);
    pin_ptr<unsigned char> pData = &data[0];

    ID3D10Effect* pEffect = NULL;
    CommonUtils::VerifyResult(
        CreateEffectFromMemory1( 
            pData,
            data->Length,
            effectFlags,
            this->GetInterface<ID3D10Device>(),
            effectPool ? effectPool->GetInterface<ID3D10EffectPool>() : NULL,
            &pEffect));

    return pEffect ? gcnew Effect( pEffect ) : nullptr;
}

