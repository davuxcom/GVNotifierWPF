// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Device.h"
#include "LibraryLoader.h"

#include "D3D11BlendState.h"
#include "D3D11Buffer.h"
#include "D3D11ClassLinkage.h"
#include "D3D11ComputeShader.h"
#include "D3D11Counter.h"
#include "D3D11DeviceContext.h"
#include "D3D11DepthStencilState.h"
#include "D3D11Resource.h"
#include "D3D11DepthStencilView.h"
#include "D3D11DomainShader.h"
#include "D3D11GeometryShader.h"
#include "D3D11HullShader.h"
#include "D3D11InputLayout.h"
#include "D3D11PixelShader.h"
#include "D3D11Predicate.h"
#include "D3D11Query.h"
#include "D3D11RasterizerState.h"
#include "D3D11RenderTargetView.h"
#include "D3D11SamplerState.h"
#include "D3D11ShaderResourceView.h"
#include "D3D11Texture1D.h"
#include "D3D11Texture2D.h"
#include "D3D11Texture3D.h"
#include "D3D11UnorderedAccessView.h"
#include "D3D11VertexShader.h"
#include "D3D11InfoQueue.h"
#include "D3D11SwitchToRef.h"
#include "DXGI/DXGISwapChain.h"
#include "DXGI/DXGIDevice.h"
#include "DXGI/DXGIDevice1.h"
#include "DXGI/DXGIAdapter.h"
#include "DXGI/DXGIObject.h"

#include <vector>
using namespace std;
using namespace System::Collections::Generic;

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

D3DDevice^ D3DDevice::CreateDeviceAndSwapChain(IntPtr windowHandle, [System::Runtime::InteropServices::Out] SwapChain^ % swapChain)
{
    PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN createFuncPtr = 
        (PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D11Library, "D3D11CreateDeviceAndSwapChain");

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

    if (!String::IsNullOrEmpty(System::Environment::GetEnvironmentVariable("DXSDK_DIR")))
    {
        createDeviceFlags  = D3D11_CREATE_DEVICE_DEBUG;
    }
#endif

    DXGI_SWAP_CHAIN_DESC sd = {0};
    sd.BufferCount = 1;    
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;    
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;        
    sd.OutputWindow = static_cast<HWND>(windowHandle.ToPointer());    
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;    
    sd.Flags = 0;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    ID3D11Device* pd3dDevice = NULL;
    ID3D11DeviceContext* pDeviceContext  = NULL;
    IDXGISwapChain* pSwapChain = NULL;
    D3D_FEATURE_LEVEL featureLevel;

    HRESULT hr =(*createFuncPtr)(
        NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0,
        D3D11_SDK_VERSION, &sd, &pSwapChain, &pd3dDevice, &featureLevel, &pDeviceContext);

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

    return pd3dDevice ? gcnew D3DDevice(pd3dDevice) : nullptr;
}

D3DDevice^ D3DDevice::CreateDeviceAndSwapChain(Adapter^ adapter, D3D11::DriverType driverType, String^ softwareRasterizerLibrary, CreateDeviceFlag flags, array<FeatureLevel>^ featureLevels, SwapChainDescription swapChainDescription, [System::Runtime::InteropServices::Out] SwapChain^ % swapChain)
{
    DXGI_SWAP_CHAIN_DESC nativeDesc = {0};
    swapChainDescription.CopyTo(&nativeDesc);

    PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN createFuncPtr = 
        (PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D11Library, "D3D11CreateDeviceAndSwapChain");

    ID3D11Device* pd3dDevice;
    ID3D11DeviceContext* pd3dDeviceContext;
    IDXGISwapChain* pSwapChain;
    D3D_FEATURE_LEVEL featureLevel;
    HINSTANCE softwareModule = NULL;

    if (!String::IsNullOrEmpty(softwareRasterizerLibrary))
    {
        softwareModule = CommonUtils::LoadDll(softwareRasterizerLibrary);
    }

    bool hasFeatures = featureLevels != nullptr && featureLevels->Length > 0;
    pin_ptr<FeatureLevel> levels = hasFeatures ? &featureLevels[0] : nullptr;

    HRESULT hr = (*createFuncPtr)( 
        adapter == nullptr ? NULL : adapter->GetInterface<IDXGIAdapter>(), 
        safe_cast<D3D_DRIVER_TYPE>(driverType),
        softwareModule,
        static_cast<UINT>(flags),
        levels ? (D3D_FEATURE_LEVEL*)levels : NULL,
        levels ? featureLevels->Length : 0, 
        D3D11_SDK_VERSION, 
        &nativeDesc, 
        &pSwapChain, 
        &pd3dDevice, 
        &featureLevel, 
        &pd3dDeviceContext);

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

    return pd3dDevice ? gcnew D3DDevice(pd3dDevice) : nullptr;
}

D3DDevice^ D3DDevice::CreateDevice()
{
    PFN_D3D11_CREATE_DEVICE createFuncPtr = 
        (PFN_D3D11_CREATE_DEVICE) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D11Library, "D3D11CreateDevice");

    UINT createDeviceFlags = 0;

#ifdef _DEBUG

// Make sure GetEnvironmentVariable is not defined
#ifdef GetEnvironmentVariable
#undef GetEnvironmentVariable
#endif

    if (!String::IsNullOrEmpty(System::Environment::GetEnvironmentVariable("DXSDK_DIR")))
    {
        createDeviceFlags  = D3D11_CREATE_DEVICE_DEBUG;
    }
#endif

    ID3D11Device* pd3dDevice;
    ID3D11DeviceContext* pDeviceContext;
    D3D_FEATURE_LEVEL featureLevel;

    HRESULT hr = (*createFuncPtr)(
        NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0,
        D3D11_SDK_VERSION, &pd3dDevice, &featureLevel, &pDeviceContext);

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

    return pd3dDevice ? gcnew D3DDevice(pd3dDevice) : nullptr;
}

D3DDevice^ D3DDevice::CreateDevice(Adapter^ adapter, D3D11::DriverType driverType, String^ softwareRasterizerLibrary, CreateDeviceFlag flags, array<FeatureLevel>^ featureLevels)
{
    PFN_D3D11_CREATE_DEVICE createFuncPtr = 
        (PFN_D3D11_CREATE_DEVICE)LibraryLoader::Instance()->GetFunctionfromDll(
            D3D11Library, "D3D11CreateDevice");

    ID3D11Device* pd3dDevice;
    ID3D11DeviceContext* pd3dDeviceContext;
    HINSTANCE softwareModule = NULL;
    D3D_FEATURE_LEVEL featureLevel;

    if (!String::IsNullOrEmpty(softwareRasterizerLibrary))
    {
        softwareModule = CommonUtils::LoadDll(softwareRasterizerLibrary);
    }
    
    bool hasFeatures = featureLevels != nullptr && featureLevels->Length > 0;
    pin_ptr<FeatureLevel> levels = hasFeatures ? &featureLevels[0] : nullptr;

    HRESULT hr = (*createFuncPtr)( 
        adapter == nullptr ? NULL : adapter->GetInterface<IDXGIAdapter>(), 
        safe_cast<D3D_DRIVER_TYPE>(driverType),
        softwareModule,
        static_cast<UINT>(flags),
        levels ? (D3D_FEATURE_LEVEL*)levels : NULL,
        levels ? featureLevels->Length : 0, 
        D3D11_SDK_VERSION, 
        &pd3dDevice, 
        &featureLevel, 
        &pd3dDeviceContext);

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

    return pd3dDevice ? gcnew D3DDevice(pd3dDevice) : nullptr;
}

bool D3DDevice::CheckCounter(CounterDescription description, [System::Runtime::InteropServices::Out] CounterType %outType, [System::Runtime::InteropServices::Out] UInt32 %outNumActiveCounters, [System::Runtime::InteropServices::Out] String^ %outName, [System::Runtime::InteropServices::Out] String^ %outUnits, [System::Runtime::InteropServices::Out] String^ %outDescription)
{
    D3D11_COUNTER_TYPE tempoutType;
    D3D11_COUNTER_DESC desc;
    description.CopyTo(&desc);
    
    UINT tempoutActiveCounters;
    
    UINT tempoutNameLength = CommonUtils::MaxNameSize;
    UINT tempoutUnitsLength = CommonUtils::MaxNameSize;
    UINT tempoutDescriptionLength = CommonUtils::MaxNameSize;

    LPSTR tempoutszName = new char[CommonUtils::MaxNameSize];
    LPSTR tempoutszUnits = new char[CommonUtils::MaxNameSize];
    LPSTR tempoutszDescription = new char[CommonUtils::MaxNameSize];

    try
    {
        HRESULT hr = GetInterface<ID3D11Device>()->CheckCounter(&desc, &tempoutType, &tempoutActiveCounters, tempoutszName, &tempoutNameLength, tempoutszUnits, &tempoutUnitsLength, tempoutszDescription, &tempoutDescriptionLength);
    
        if (SUCCEEDED(hr))
        {
            outType = safe_cast<CounterType>(tempoutType);
            outNumActiveCounters = safe_cast<UInt32>(tempoutActiveCounters);
            outName = tempoutszName ? gcnew String(tempoutszName) : nullptr;
            outUnits = tempoutszUnits ? gcnew String(tempoutszUnits) : nullptr;
            outDescription = tempoutszDescription ? gcnew String(tempoutszDescription) : nullptr;

            return true;
        }
        else
        {
            return false;
        }
    }
    finally
    {
        delete [] tempoutszName;
        delete [] tempoutszUnits;
        delete [] tempoutszDescription;
    }
    
}

CounterInformation D3DDevice::CheckCounterInformation()
{
    D3D11_COUNTER_INFO info;
    GetInterface<ID3D11Device>()->CheckCounterInfo(&info);
    
    return CounterInformation(info);
}

bool D3DDevice::CheckThreadingSupport([System::Runtime::InteropServices::Out] FeatureDataThreading %featureData)
{
    D3D11_FEATURE_DATA_THREADING temp;
    featureData.CopyTo(&temp);
    
    if(SUCCEEDED(GetInterface<ID3D11Device>()->CheckFeatureSupport(D3D11_FEATURE_THREADING , &temp, sizeof(D3D11_FEATURE_DATA_THREADING))))
    {
        featureData = FeatureDataThreading(temp);
        return true;
    }

    featureData = FeatureDataThreading(temp);
    return false;
}

bool D3DDevice::CheckFeatureDataDoubles([System::Runtime::InteropServices::Out] FeatureDataDoubles %featureData)
{
    D3D11_FEATURE_DATA_DOUBLES temp;
    featureData.CopyTo(&temp);
    
    if(SUCCEEDED(GetInterface<ID3D11Device>()->CheckFeatureSupport(D3D11_FEATURE_DOUBLES , &temp, sizeof(D3D11_FEATURE_DATA_DOUBLES))))
    {    
        featureData = FeatureDataDoubles(temp);
        return true;
    }

    featureData = FeatureDataDoubles(temp);
    return false;
}

bool D3DDevice::CheckFeatureDataFormatSupport( [System::Runtime::InteropServices::In, System::Runtime::InteropServices::Out] FeatureDataFormatSupport %featureData)
{
    D3D11_FEATURE_DATA_FORMAT_SUPPORT temp;
    featureData.CopyTo(&temp);
    
    if (SUCCEEDED(GetInterface<ID3D11Device>()->CheckFeatureSupport(D3D11_FEATURE_FORMAT_SUPPORT , &temp, sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT))))
    {
        featureData = FeatureDataFormatSupport(temp);
        return true;
    }

    return false;
}

bool D3DDevice::CheckFeatureDataFormatSupport2([System::Runtime::InteropServices::In, System::Runtime::InteropServices::Out] FeatureDataFormatSupport2 %featureData)
{
    D3D11_FEATURE_DATA_FORMAT_SUPPORT2 temp;
    featureData.CopyTo(&temp);
    
    if (SUCCEEDED(GetInterface<ID3D11Device>()->CheckFeatureSupport(D3D11_FEATURE_FORMAT_SUPPORT2 , &temp, sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT2))))
    {
        featureData = FeatureDataFormatSupport2(temp);
        return true;
    }

    return false;
}

bool D3DDevice::CheckFeatureDataD3D10XHardwareOptions( [System::Runtime::InteropServices::Out] FeatureDataD3D10XHardwareOptions %featureData)
{
    D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS temp;
    featureData.CopyTo(&temp);
    
    if(SUCCEEDED(GetInterface<ID3D11Device>()->CheckFeatureSupport(D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS , &temp, sizeof(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS))))
    {
        featureData = FeatureDataD3D10XHardwareOptions(temp);
        return true;
    }

    return false;
}

FormatSupport D3DDevice::GetFormatSupport(Format format)
{
    UINT tempoutFormatSupport = 0;
    
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CheckFormatSupport(static_cast<DXGI_FORMAT>(format), &tempoutFormatSupport));
    
    return safe_cast<FormatSupport>(tempoutFormatSupport);
}

bool D3DDevice::CheckFormatSupport(Format format, [System::Runtime::InteropServices::Out] FormatSupport % formatSupport )
{
    UINT tempoutFormatSupport = 0;
    
    bool succeeded = SUCCEEDED(GetInterface<ID3D11Device>()->CheckFormatSupport(static_cast<DXGI_FORMAT>(format), &tempoutFormatSupport));
    
    formatSupport =  safe_cast<FormatSupport>(tempoutFormatSupport);

    return succeeded;
}

UInt32 D3DDevice::GetMultisampleQualityLevels(Format format, UInt32 sampleCount)
{
    UINT tempoutNumQualityLevels;
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CheckMultisampleQualityLevels(static_cast<DXGI_FORMAT>(format), sampleCount, &tempoutNumQualityLevels));
    return tempoutNumQualityLevels;
}

bool D3DDevice::CheckMultisampleQualityLevels(Format format, UInt32 sampleCount, [System::Runtime::InteropServices::Out] UInt32 % multisampleQualityLevels)
{
    UINT tempoutNumQualityLevels;
    bool succeeded = SUCCEEDED(GetInterface<ID3D11Device>()->CheckMultisampleQualityLevels(static_cast<DXGI_FORMAT>(format), static_cast<UINT>(sampleCount), &tempoutNumQualityLevels));

    if (succeeded) 
        multisampleQualityLevels = tempoutNumQualityLevels;

    return succeeded;
}

BlendState^ D3DDevice::CreateBlendState(BlendDescription description)
{
    ID3D11BlendState* tempoutBlendState = NULL;
    
    D3D11_BLEND_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateBlendState(&desc, &tempoutBlendState));
    
    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);
}

D3DBuffer^ D3DDevice::CreateBuffer(BufferDescription description, SubresourceData initialData)
{
    ID3D11Buffer* tempoutBuffer = NULL;

    D3D11_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);
    
    pin_ptr<BufferDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateBuffer(
        (D3D11_BUFFER_DESC*)ptr, 
        &data, 
        &tempoutBuffer));

    return tempoutBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutBuffer);
}

D3DBuffer^ D3DDevice::CreateBuffer(BufferDescription description)
{
    ID3D11Buffer* tempoutBuffer = NULL;
    pin_ptr<BufferDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateBuffer(
        (D3D11_BUFFER_DESC*)ptr, 
        NULL, 
        &tempoutBuffer));

    return tempoutBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutBuffer);
}
ClassLinkage^ D3DDevice::CreateClassLinkage()
{
    ID3D11ClassLinkage* tempoutLinkage = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateClassLinkage(&tempoutLinkage));
    return tempoutLinkage == NULL ? nullptr : gcnew ClassLinkage(tempoutLinkage);
}

D3DCounter^ D3DDevice::CreateCounter(CounterDescription description)
{
    ID3D11Counter* tempoutCounter = NULL;

    D3D11_COUNTER_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateCounter(&desc, &tempoutCounter));
    
    return tempoutCounter == NULL ? nullptr : gcnew D3DCounter(tempoutCounter);
}

DeviceContext^ D3DDevice::CreateDeferredContext(UInt32 contextFlags)
{
    ID3D11DeviceContext* tempoutDeferredContext = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateDeferredContext(static_cast<UINT>(contextFlags), &tempoutDeferredContext));
    return tempoutDeferredContext == NULL ? nullptr : gcnew DeviceContext(tempoutDeferredContext);
}

DepthStencilState^ D3DDevice::CreateDepthStencilState(DepthStencilDescription description)
{
    ID3D11DepthStencilState* tempoutDepthStencilState = NULL;

    D3D11_DEPTH_STENCIL_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateDepthStencilState(&desc, &tempoutDepthStencilState));
    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);
}

DepthStencilView^  D3DDevice::CreateDepthStencilView(D3DResource^ resource, DepthStencilViewDescription description)
{
    CommonUtils::CheckNull(resource, "resource");

    D3D11_DEPTH_STENCIL_VIEW_DESC desc;
    description.CopyTo(&desc);

    ID3D11DepthStencilView* tempoutDepthStencilView = NULL;
    
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateDepthStencilView(
        resource->GetInterface<ID3D11Resource>(), 
        &desc, 
        &tempoutDepthStencilView));

    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

DepthStencilView^ D3DDevice::CreateDepthStencilView(D3DResource^ resource)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D11DepthStencilView* tempoutDepthStencilView = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateDepthStencilView(
        resource->GetInterface<ID3D11Resource>(), 
        NULL,
        &tempoutDepthStencilView));

    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

ComputeShader^ D3DDevice::CreateComputeShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, ClassLinkage^ classLinkage)
{
    ID3D11ComputeShader* tempShader = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateComputeShader(
        shaderBytecode.ToPointer(), 
        shaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew ComputeShader(tempShader);
}


ComputeShader^ D3DDevice::CreateComputeShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    return CreateComputeShader(shaderBytecode, shaderBytecodeLength, nullptr);
}

ComputeShader^ D3DDevice::CreateComputeShader(Stream^ stream, ClassLinkage^ classLinkage)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateComputeShader(IntPtr(data), dataArray->Length, classLinkage);

}

ComputeShader^ D3DDevice::CreateComputeShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateComputeShader(IntPtr(data), dataArray->Length, nullptr);
}


DomainShader^ D3DDevice::CreateDomainShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, ClassLinkage^ classLinkage)
{
    ID3D11DomainShader* tempShader = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateDomainShader(
        shaderBytecode.ToPointer(), 
        shaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew DomainShader(tempShader);
}

DomainShader^ D3DDevice::CreateDomainShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    return CreateDomainShader(shaderBytecode, shaderBytecodeLength, nullptr);
}

DomainShader^ D3DDevice::CreateDomainShader(Stream^ stream, ClassLinkage^ classLinkage)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateDomainShader(IntPtr(data), dataArray->Length, classLinkage);

}

DomainShader^ D3DDevice::CreateDomainShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateDomainShader (IntPtr(data), dataArray->Length, nullptr);

}

GeometryShader^ D3DDevice::CreateGeometryShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, ClassLinkage^ classLinkage)
{
    ID3D11GeometryShader* tempShader = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateGeometryShader(
        shaderBytecode.ToPointer(), 
        shaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew GeometryShader(tempShader);
}

GeometryShader^ D3DDevice::CreateGeometryShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    return CreateGeometryShader(shaderBytecode, shaderBytecodeLength, nullptr);
}

GeometryShader^ D3DDevice::CreateGeometryShader(Stream^ stream, ClassLinkage^ classLinkage)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateGeometryShader(IntPtr(data), dataArray->Length, classLinkage);

}

GeometryShader^ D3DDevice::CreateGeometryShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateGeometryShader(IntPtr(data), dataArray->Length, nullptr);
}


GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, IEnumerable<StreamOutputDeclarationEntry>^ SODeclarations, 
    array<UInt32>^ bufferStrides, UInt32 rasterizedStream, ClassLinkage^ classLinkage)
{
    ID3D11GeometryShader* tempoutGeometryShader = NULL;

    vector<D3D11_SO_DECLARATION_ENTRY> declEntries;
    marshal_context^ ctx = gcnew marshal_context();
    UINT declEntriesLen = CommonUtils::FillValStructsVector<StreamOutputDeclarationEntry,D3D11_SO_DECLARATION_ENTRY>(SODeclarations, declEntries, ctx);

    pin_ptr<UInt32> strides;
    
    if (bufferStrides != nullptr && bufferStrides->Length > 0)
    {
        strides = &(bufferStrides[ 0 ]);
    }

    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateGeometryShaderWithStreamOutput(
        shaderBytecode.ToPointer(), 
        shaderBytecodeLength, 
        declEntriesLen == 0 ? NULL : &declEntries[0], 
        declEntriesLen, 
        strides, 
        static_cast<UINT>(bufferStrides->Length), 
        static_cast<UINT>(rasterizedStream), 
        classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
        &tempoutGeometryShader));

    GC::KeepAlive(ctx);
        
    return tempoutGeometryShader == NULL ? nullptr : gcnew GeometryShader(tempoutGeometryShader);
}

GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, IEnumerable<StreamOutputDeclarationEntry>^ SODeclarations, 
    array<UInt32>^ bufferStrides, UInt32 rasterizedStream)
{
    return CreateGeometryShaderWithStreamOutput(shaderBytecode, shaderBytecodeLength, SODeclarations, 
            bufferStrides, rasterizedStream, nullptr);
}

GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(Stream^ stream, IEnumerable<StreamOutputDeclarationEntry>^ SODeclarations, 
    array<UInt32>^ bufferStrides, UInt32 rasterizedStream, ClassLinkage^ classLinkage)
{

    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateGeometryShaderWithStreamOutput(IntPtr(data), dataArray->Length, SODeclarations, 
            bufferStrides, rasterizedStream, classLinkage);

}
    
GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(Stream^ stream, IEnumerable<StreamOutputDeclarationEntry>^ SODeclarations, 
    array<UInt32>^ bufferStrides, UInt32 rasterizedStream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateGeometryShaderWithStreamOutput(IntPtr(data), dataArray->Length, SODeclarations, 
            bufferStrides, rasterizedStream, nullptr);

}

HullShader^ D3DDevice::CreateHullShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, ClassLinkage^ classLinkage)
{
    ID3D11HullShader* tempShader = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateHullShader(
        shaderBytecode.ToPointer(), 
        shaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew HullShader(tempShader);
}

HullShader^ D3DDevice::CreateHullShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    return CreateHullShader(shaderBytecode, shaderBytecodeLength, nullptr);
}

HullShader^ D3DDevice::CreateHullShader(Stream^ stream, ClassLinkage^ classLinkage)
{        
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateHullShader(IntPtr(data), dataArray->Length, classLinkage);

}

HullShader^ D3DDevice::CreateHullShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateHullShader(IntPtr(data), dataArray->Length, nullptr);
}

InputLayout^ D3DDevice::CreateInputLayout(
    IEnumerable<InputElementDescription>^ inputElementDescriptions, 
    IntPtr shaderBytecodeWithInputSignature, 
    UInt32 shaderBytecodeWithInputSignatureSize)
{
    vector<D3D11_INPUT_ELEMENT_DESC> inputElements;

    marshal_context^ ctx = gcnew marshal_context();

    UINT count = CommonUtils::FillValStructsVector<InputElementDescription, D3D11_INPUT_ELEMENT_DESC>(inputElementDescriptions,inputElements, ctx);

    ID3D11InputLayout* tempoutInputLayout = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateInputLayout(
        count == 0 ? NULL : &inputElements[0],
        count,
        shaderBytecodeWithInputSignature.ToPointer(), 
        shaderBytecodeWithInputSignatureSize, 
        &tempoutInputLayout));

    GC::KeepAlive(ctx);

    return tempoutInputLayout == NULL ? nullptr : gcnew InputLayout(tempoutInputLayout);
}

InputLayout^ D3DDevice::CreateInputLayout(
    IEnumerable<InputElementDescription>^ inputElementDescriptions, 
    Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateInputLayout(inputElementDescriptions, IntPtr(data), dataArray->Length);
}

PixelShader^ D3DDevice::CreatePixelShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, ClassLinkage^ classLinkage)
{
    ID3D11PixelShader* tempoutPixelShader = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreatePixelShader(
            shaderBytecode.ToPointer(), 
            shaderBytecodeLength, 
            classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
            &tempoutPixelShader));
    
    return tempoutPixelShader == NULL ? nullptr : gcnew PixelShader(tempoutPixelShader);
}

PixelShader^ D3DDevice::CreatePixelShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    return CreatePixelShader(shaderBytecode, shaderBytecodeLength, nullptr);
}

PixelShader^ D3DDevice::CreatePixelShader(Stream^ stream, ClassLinkage^ classLinkage)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreatePixelShader(IntPtr(data), dataArray->Length, classLinkage);
}

PixelShader^ D3DDevice::CreatePixelShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreatePixelShader(IntPtr(data), dataArray->Length, nullptr);
}

D3DPredicate^ D3DDevice::CreatePredicate(QueryDescription description)
{
    ID3D11Predicate* tempoutPredicate = NULL;

    D3D11_QUERY_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreatePredicate(&desc, &tempoutPredicate));
    return tempoutPredicate == NULL ? nullptr : gcnew D3DPredicate(tempoutPredicate);
}

D3DQuery^ D3DDevice::CreateQuery(QueryDescription description)
{
    ID3D11Query* tempoutQuery = NULL;

    D3D11_QUERY_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateQuery(&desc, &tempoutQuery));
    return tempoutQuery == NULL ? nullptr : gcnew D3DQuery(tempoutQuery);
}

RasterizerState^ D3DDevice::CreateRasterizerState(RasterizerDescription description)
{
    ID3D11RasterizerState* tempoutRasterizerState = NULL;

    D3D11_RASTERIZER_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateRasterizerState(
        &desc, &tempoutRasterizerState));

    return tempoutRasterizerState == NULL ? nullptr : gcnew RasterizerState(tempoutRasterizerState);
}
RenderTargetView^ D3DDevice::CreateRenderTargetView(D3DResource^ resource, RenderTargetViewDescription description)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D11RenderTargetView* tempoutRTView = NULL;
    pin_ptr<RenderTargetViewDescription> ptr = &description;

    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateRenderTargetView(
        resource->GetInterface<ID3D11Resource>(), 
        (D3D11_RENDER_TARGET_VIEW_DESC*)ptr, 
        &tempoutRTView));
    return  tempoutRTView == NULL ? nullptr : gcnew RenderTargetView(tempoutRTView);
}

RenderTargetView^ D3DDevice::CreateRenderTargetView(D3DResource^ resource)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D11RenderTargetView* tempoutRTView = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateRenderTargetView(
        resource->GetInterface<ID3D11Resource>(), 
        NULL, 
        &tempoutRTView));
    return  tempoutRTView == NULL ? nullptr : gcnew RenderTargetView(tempoutRTView);
}

SamplerState^ D3DDevice::CreateSamplerState(SamplerDescription description)
{
    ID3D11SamplerState* tempoutSamplerState = NULL;
    D3D11_SAMPLER_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateSamplerState(&desc, &tempoutSamplerState));
    return tempoutSamplerState == NULL ? nullptr : gcnew SamplerState(tempoutSamplerState);
}

ShaderResourceView^ D3DDevice::CreateShaderResourceView(D3DResource^ resource, ShaderResourceViewDescription description)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D11ShaderResourceView* tempoutSRView = NULL;
    D3D11_SHADER_RESOURCE_VIEW_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateShaderResourceView(
        resource->GetInterface<ID3D11Resource>(), 
        &desc, 
        &tempoutSRView));

    return tempoutSRView == NULL ? nullptr : gcnew ShaderResourceView(tempoutSRView);
}

ShaderResourceView^ D3DDevice::CreateShaderResourceView(D3DResource^ resource)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D11ShaderResourceView* tempoutSRView = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateShaderResourceView(
        resource->GetInterface<ID3D11Resource>(), 
        NULL,
        &tempoutSRView));

    return tempoutSRView == NULL ? nullptr : gcnew ShaderResourceView(tempoutSRView);
}

Texture1D^ D3DDevice::CreateTexture1D(Texture1DDescription description, SubresourceData initialData)
{
    ID3D11Texture1D* tempoutTexture1D = NULL;

    D3D11_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);

    pin_ptr<Texture1DDescription> ptr = &description;


    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateTexture1D(
        (D3D11_TEXTURE1D_DESC*)ptr, 
        &data, 
        &tempoutTexture1D));
    
    return tempoutTexture1D == NULL ? nullptr : gcnew Texture1D(tempoutTexture1D);
}

Texture2D^ D3DDevice::CreateTexture2D(Texture2DDescription description, SubresourceData initialData)
{
    ID3D11Texture2D* tempoutTexture2D = NULL;
    
    D3D11_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);

    pin_ptr<Texture2DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateTexture2D(
        (D3D11_TEXTURE2D_DESC*)ptr, 
        &data, 
        &tempoutTexture2D));

    return tempoutTexture2D == NULL ? nullptr : gcnew Texture2D(tempoutTexture2D);
}

Texture3D^ D3DDevice::CreateTexture3D(Texture3DDescription description, SubresourceData initialData)
{
    ID3D11Texture3D* tempoutTexture3D = NULL;
    
    D3D11_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);

    pin_ptr<Texture3DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateTexture3D(
        (D3D11_TEXTURE3D_DESC*)ptr, 
        &data, 
        &tempoutTexture3D));

    return tempoutTexture3D == NULL ? nullptr : gcnew Texture3D(tempoutTexture3D);
}

Texture1D^ D3DDevice::CreateTexture1D(Texture1DDescription description)
{
    ID3D11Texture1D* tempoutTexture1D = NULL;

    pin_ptr<Texture1DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateTexture1D(
        (D3D11_TEXTURE1D_DESC*)ptr, 
        NULL, 
        &tempoutTexture1D));
    
    return tempoutTexture1D == NULL ? nullptr : gcnew Texture1D(tempoutTexture1D);
}

Texture2D^ D3DDevice::CreateTexture2D(Texture2DDescription description)
{
    ID3D11Texture2D* tempoutTexture2D = NULL;

    pin_ptr<Texture2DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateTexture2D(
        (D3D11_TEXTURE2D_DESC*)ptr, 
        NULL, 
        &tempoutTexture2D));

    return tempoutTexture2D == NULL ? nullptr : gcnew Texture2D(tempoutTexture2D);
}

Texture3D^ D3DDevice::CreateTexture3D(Texture3DDescription description)
{
    ID3D11Texture3D* tempoutTexture3D = NULL;

    pin_ptr<Texture3DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->CreateTexture3D(
        (D3D11_TEXTURE3D_DESC*)ptr, 
        NULL, 
        &tempoutTexture3D));

    return tempoutTexture3D == NULL ? nullptr : gcnew Texture3D(tempoutTexture3D);
}

UnorderedAccessView^ D3DDevice::CreateUnorderedAccessView(D3DResource^ resource, UnorderedAccessViewDescription description)
{
    CommonUtils::CheckNull(resource, "resource");
    D3D11_UNORDERED_ACCESS_VIEW_DESC desc;
    description.CopyTo(&desc);


    ID3D11UnorderedAccessView* tempoutUAView = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateUnorderedAccessView(
            resource->GetInterface<ID3D11Resource>(), 
            &desc, 
            &tempoutUAView));
    
    return tempoutUAView == NULL ? nullptr : gcnew UnorderedAccessView(tempoutUAView);
}

UnorderedAccessView^ D3DDevice::CreateUnorderedAccessView(D3DResource^ resource)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D11UnorderedAccessView* tempoutUAView = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateUnorderedAccessView(
            resource->GetInterface<ID3D11Resource>(), 
            NULL, 
            &tempoutUAView));
    
    return tempoutUAView == NULL ? nullptr : gcnew UnorderedAccessView(tempoutUAView);
}
VertexShader^ D3DDevice::CreateVertexShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, ClassLinkage^ classLinkage)
{
    ID3D11VertexShader* tempoutVertexShader = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID3D11Device>()->CreateVertexShader(
            shaderBytecode.ToPointer(), 
            shaderBytecodeLength, 
            classLinkage == nullptr ? NULL : classLinkage->GetInterface<ID3D11ClassLinkage>(), 
            &tempoutVertexShader));
    
    return tempoutVertexShader == NULL ? nullptr : gcnew VertexShader(tempoutVertexShader);
}

VertexShader^ D3DDevice::CreateVertexShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    return CreateVertexShader(shaderBytecode, shaderBytecodeLength, nullptr);
}

VertexShader^ D3DDevice::CreateVertexShader(Stream^ stream, ClassLinkage^ classLinkage)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateVertexShader(IntPtr(data), dataArray->Length, classLinkage);
}

VertexShader^ D3DDevice::CreateVertexShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateVertexShader(IntPtr(data), dataArray->Length, nullptr);
}

CreateDeviceFlag D3DDevice::CreationFlags::get()
{
    UINT returnValue = GetInterface<ID3D11Device>()->GetCreationFlags();
    return safe_cast<CreateDeviceFlag>(returnValue);
}

ErrorCode D3DDevice::DeviceRemovedReason::get()
{
    return safe_cast<ErrorCode>(GetInterface<ID3D11Device>()->GetDeviceRemovedReason());
}

RaiseFlag D3DDevice::ExceptionMode::get()
{
    UINT returnValue = GetInterface<ID3D11Device>()->GetExceptionMode();
    return safe_cast<RaiseFlag>(returnValue);
}

void D3DDevice::ExceptionMode::set(RaiseFlag value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->SetExceptionMode(static_cast<UINT>(value)));
}

DeviceContext^ D3DDevice::GetImmediateContext()
{
    ID3D11DeviceContext* tempoutImmediateContext = NULL;
    GetInterface<ID3D11Device>()->GetImmediateContext(&tempoutImmediateContext);
    return tempoutImmediateContext == NULL ? nullptr : gcnew DeviceContext(tempoutImmediateContext);
}

InfoQueue ^ D3DDevice::GetInfoQueue()
{
    ID3D11InfoQueue * infoQueue = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->QueryInterface(__uuidof(ID3D11InfoQueue), (void**) &infoQueue));

    return infoQueue == NULL ? nullptr : gcnew InfoQueue(infoQueue);
}

SwitchToRef ^ D3DDevice::GetSwitchToRef()
{
    ID3D11SwitchToRef * switchToRef = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->QueryInterface(__uuidof(ID3D11SwitchToRef), (void**) &switchToRef));

    return switchToRef == NULL ? nullptr : gcnew SwitchToRef(switchToRef);
}

generic <typename T> where T : DXGIObject
T D3DDevice::OpenSharedResource(IntPtr resource)
{
    void* tempoutResource = NULL;

    GUID guid = CommonUtils::GetGuid(T::typeid);
    
    CommonUtils::VerifyResult(GetInterface<ID3D11Device>()->OpenSharedResource(static_cast<HANDLE>(resource.ToPointer()), guid, &tempoutResource));
    
    return CommonUtils::CreateIUnknownWrapper<T>(static_cast<IUnknown*>(tempoutResource));
}

FeatureLevel D3DDevice::DeviceFeatureLevel::get()
{
    return static_cast<FeatureLevel>(GetInterface<ID3D11Device>()->GetFeatureLevel());
}

DXGIDevice^ D3DDevice::GetDXGIDevice() 
{
    IDXGIDevice * pDXGIDevice = NULL;
    CommonUtils::VerifyResult(GetInterface<IUnknown>()->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice));

    return pDXGIDevice == NULL ? nullptr : gcnew DXGIDevice(pDXGIDevice);
}
