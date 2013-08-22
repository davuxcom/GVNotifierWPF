// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include <vector>
#include "LibraryLoader.h"
#include "D3D10Device.h"
#include "D3D10DepthStencilView.h"
#include "D3D10RenderTargetView.h"
#include "D3D10Resource.h"
#include "D3D10BlendState.h"
#include "D3D10Buffer.h"
#include "D3D10DepthStencilState.h"
#include "D3D10GeometryShader.h"
#include "D3D10InputLayout.h"
#include "D3D10PixelShader.h"
#include "D3D10RasterizerState.h"
#include "D3D10SamplerState.h"
#include "D3D10ShaderResourceView.h"
#include "D3D10Texture1D.h"
#include "D3D10Texture2D.h"
#include "D3D10Texture3D.h"
#include "D3D10VertexShader.h"
#include "D3D10SwitchToRef.h"
#include "D3D10GeometryShaderPipelineStage.h"
#include "D3D10InputAssemblerPipelineStage.h"
#include "D3D10OutputMergerPipelineStage.h"
#include "D3D10PixelShaderPipelineStage.h"
#include "D3D10RasterizerPipelineStage.h"
#include "D3D10StreamOutputPipelineStage.h"
#include "D3D10VertexShaderPipelineStage.h"
#include "D3D10Effect.h"
#include "D3D10Counter.h"
#include "D3D10Predicate.h"
#include "D3D10Query.h"
#include "D3D10InfoQueue.h"

#include "DXGI/DXGISwapChain.h"
#include "DXGI/DXGIAdapter.h"
#include "DXGI/DXGIDevice.h"
#include "DXGI/DXGIDevice1.h"
#include "DXGI/DXGIObject.h"


using namespace std;

#pragma unmanaged

typedef HRESULT (*D3D10CreateEffectFromMemoryPtr)(
    void *pData,
    SIZE_T DataLength,
    UINT FXFlags,
    ID3D10Device *pDevice, 
    ID3D10EffectPool *pEffectPool,
    ID3D10Effect **ppEffect
);

HRESULT CreateEffectFromMemory(                                     
    void *pData,
    SIZE_T DataLength,
    UINT FXFlags,
    ID3D10Device *pDevice, 
    ID3D10EffectPool *pEffectPool,
    ID3D10Effect **ppEffect)
{
    D3D10CreateEffectFromMemoryPtr createEffectFuncPtr = 
        (D3D10CreateEffectFromMemoryPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10Library, "D3D10CreateEffectFromMemory");

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

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace System::IO;



typedef HRESULT (*D3D10CreateDeviceAndSwapChainFuncPtr)(
    IDXGIAdapter *pAdapter,
    D3D10_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    UINT SDKVersion,
    DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
    IDXGISwapChain **ppSwapChain,    
    ID3D10Device **ppDevice
);

typedef HRESULT (*D3D10CreateDeviceFuncPtr)(
    IDXGIAdapter *pAdapter,
    D3D10_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    UINT SDKVersion,
    ID3D10Device **ppDevice
);


D3DDevice^ D3DDevice::CreateDeviceAndSwapChain(IntPtr windowHandle, [System::Runtime::InteropServices::Out] SwapChain^ % swapChain)
{
    D3D10CreateDeviceAndSwapChainFuncPtr createFuncPtr = 
        (D3D10CreateDeviceAndSwapChainFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10Library, "D3D10CreateDeviceAndSwapChain");

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
        createDeviceFlags  = D3D10_CREATE_DEVICE_DEBUG;
    }
#endif

    ID3D10Device* pd3dDevice = NULL;
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

    HRESULT hr =(*createFuncPtr)( NULL, D3D10_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags,
                                        D3D10_SDK_VERSION, &sd, &pSwapChain, &pd3dDevice);

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


D3DDevice^ D3DDevice::CreateDeviceAndSwapChain(Adapter^ adapter, Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DriverType driverType, String^ softwareRasterizerLibrary, CreateDeviceFlag flags, SwapChainDescription swapChainDescription, [System::Runtime::InteropServices::Out] SwapChain^ % swapChain)
{

    DXGI_SWAP_CHAIN_DESC nativeDesc = {0};
    swapChainDescription.CopyTo(&nativeDesc);

    D3D10CreateDeviceAndSwapChainFuncPtr createFuncPtr = 
        (D3D10CreateDeviceAndSwapChainFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10Library, "D3D10CreateDeviceAndSwapChain");

    ID3D10Device* pd3dDevice = NULL;
    IDXGISwapChain* pSwapChain = NULL;

    HINSTANCE softwareModule = NULL;
    if (!String::IsNullOrEmpty(softwareRasterizerLibrary))
    {
        softwareModule = CommonUtils::LoadDll(softwareRasterizerLibrary);
    }

    HRESULT hr = (*createFuncPtr)( 
        adapter == nullptr ? NULL : adapter->GetInterface<IDXGIAdapter>(), 
        static_cast<D3D10_DRIVER_TYPE>(driverType),
        softwareModule,
        static_cast<UINT>(flags),
        D3D10_SDK_VERSION, 
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

    return pd3dDevice ? gcnew D3DDevice(pd3dDevice) : nullptr;
}

D3DDevice^ D3DDevice::CreateDevice()
{
    D3D10CreateDeviceFuncPtr createFuncPtr = 
        (D3D10CreateDeviceFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10Library, "D3D10CreateDevice");

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

    ID3D10Device* pd3dDevice = NULL;

    HRESULT hr = (*createFuncPtr)( NULL, D3D10_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags,
                                        D3D10_SDK_VERSION, &pd3dDevice);

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

D3DDevice^ D3DDevice::CreateDevice(Adapter^ adapter, Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DriverType driverType, String^ softwareRasterizerLibrary, CreateDeviceFlag flags)
{
    D3D10CreateDeviceFuncPtr createFuncPtr = 
        (D3D10CreateDeviceFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D3D10Library, "D3D10CreateDevice");

    ID3D10Device* pd3dDevice = NULL;

    HINSTANCE softwareModule = NULL;
    if (!String::IsNullOrEmpty(softwareRasterizerLibrary))
    {
        softwareModule = CommonUtils::LoadDll(softwareRasterizerLibrary);
    }

    HRESULT hr = (*createFuncPtr)( 
        adapter == nullptr ? NULL : adapter->GetInterface<IDXGIAdapter>(), 
        static_cast<D3D10_DRIVER_TYPE>(driverType),
        softwareModule,
        static_cast<UINT>(flags),
        D3D10_SDK_VERSION, 
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

    return pd3dDevice ? gcnew D3DDevice(pd3dDevice) : nullptr;
}

bool D3DDevice::CheckCounter(CounterDescription description, [System::Runtime::InteropServices::Out] CounterType %outType, [System::Runtime::InteropServices::Out] UInt32 %outNumActiveCounters, [System::Runtime::InteropServices::Out] String^ %outName, [System::Runtime::InteropServices::Out] String^ %outUnits, [System::Runtime::InteropServices::Out] String^ %outDescription)
{
    D3D10_COUNTER_TYPE tempoutType;

    D3D10_COUNTER_DESC desc;
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
        HRESULT hr = GetInterface<ID3D10Device>()->CheckCounter(&desc, &tempoutType, &tempoutActiveCounters, tempoutszName, &tempoutNameLength, tempoutszUnits, &tempoutUnitsLength, tempoutszDescription, &tempoutDescriptionLength);
        
        if (SUCCEEDED(hr))
        {
            outType = static_cast<CounterType>(tempoutType);
            outNumActiveCounters = tempoutActiveCounters;
            outName = tempoutszName ? gcnew String(tempoutszName) : nullptr;
            outUnits = tempoutszUnits ? gcnew String(tempoutszUnits) : nullptr;
            outDescription = tempoutszDescription ? gcnew String(tempoutszDescription) : nullptr;

            return true;
        }
        else
        {
            outType = static_cast<CounterType>(0);
            outNumActiveCounters = 0;
            outName = nullptr;
            outUnits = nullptr;
            outDescription = nullptr;

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
    D3D10_COUNTER_INFO info;
    GetInterface<ID3D10Device>()->CheckCounterInfo(&info);
    
    return CounterInformation(info);
}

FormatSupport D3DDevice::GetFormatSupport(Format format)
{
    UINT tempoutFormatSupport = 0;
    
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CheckFormatSupport(static_cast<DXGI_FORMAT>(format), &tempoutFormatSupport));
    
    return static_cast<FormatSupport>(tempoutFormatSupport);
}

bool D3DDevice::CheckFormatSupport(Format format, [System::Runtime::InteropServices::Out] FormatSupport % formatSupport )
{
    UINT tempoutFormatSupport = 0;
    
    bool succeeded = SUCCEEDED(GetInterface<ID3D10Device>()->CheckFormatSupport(static_cast<DXGI_FORMAT>(format), &tempoutFormatSupport));
    
    formatSupport =  static_cast<FormatSupport>(tempoutFormatSupport);

    return succeeded;
}

UInt32 D3DDevice::GetMultisampleQualityLevels(Format format, UInt32 sampleCount)
{
    UINT tempoutNumQualityLevels;
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CheckMultisampleQualityLevels(static_cast<DXGI_FORMAT>(format), static_cast<UINT>(sampleCount), &tempoutNumQualityLevels));
    return tempoutNumQualityLevels;
}

bool D3DDevice::CheckMultisampleQualityLevels(Format format, UInt32 sampleCount, [System::Runtime::InteropServices::Out] UInt32 % multisampleQualityLevels)
{
    UINT tempoutNumQualityLevels;
    if (SUCCEEDED(GetInterface<ID3D10Device>()->CheckMultisampleQualityLevels(static_cast<DXGI_FORMAT>(format), static_cast<UINT>(sampleCount), &tempoutNumQualityLevels))) 
    {
        multisampleQualityLevels = tempoutNumQualityLevels;
        return true;
    }
    else
    {
        multisampleQualityLevels = 0;
        return false;
    }
}


void D3DDevice::ClearDepthStencilView(DepthStencilView^ depthStencilView, ClearFlag flags, Single depth, Byte stencil)
{
    GetInterface<ID3D10Device>()->ClearDepthStencilView(depthStencilView->GetInterface<ID3D10DepthStencilView>(), static_cast<UINT>(flags), static_cast<FLOAT>(depth), static_cast<UINT8>(stencil));
}

void D3DDevice::ClearRenderTargetView(RenderTargetView^ renderTargetView, ColorRgba colorRgba)
{
    pin_ptr<ColorRgba> rgba = &colorRgba;
    GetInterface<ID3D10Device>()->ClearRenderTargetView(renderTargetView->GetInterface<ID3D10RenderTargetView>(), (float*)rgba);
}
void D3DDevice::ClearState()
{
    GetInterface<ID3D10Device>()->ClearState();
}

void D3DDevice::CopyResource(D3DResource^ dstResource, D3DResource^ srcResource)
{
    GetInterface<ID3D10Device>()->CopyResource(dstResource->GetInterface<ID3D10Resource>(), srcResource->GetInterface<ID3D10Resource>());
}

void D3DDevice::CopySubresourceRegion(D3DResource^ destinationResource, UInt32 destinationSubresource, UInt32 destinationX, UInt32 destinationY, UInt32 destinationZ, D3DResource^ sourceResource, UInt32 sourceSubresource, Box sourceBox)
{
    pin_ptr<Box> boxPtr = &sourceBox;
    GetInterface<ID3D10Device>()->CopySubresourceRegion(destinationResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(destinationSubresource), static_cast<UINT>(destinationX), static_cast<UINT>(destinationY), static_cast<UINT>(destinationZ), sourceResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(sourceSubresource), (D3D10_BOX*)boxPtr);
}

void D3DDevice::CopySubresourceRegion(D3DResource^ destinationResource, UInt32 destinationSubresource, UInt32 destinationX, UInt32 destinationY, UInt32 destinationZ, D3DResource^ sourceResource, UInt32 sourceSubresource)
{
    GetInterface<ID3D10Device>()->CopySubresourceRegion(destinationResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(destinationSubresource), static_cast<UINT>(destinationX), static_cast<UINT>(destinationY), static_cast<UINT>(destinationZ), sourceResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(sourceSubresource), NULL);
}

BlendState^ D3DDevice::CreateBlendState(BlendDescription description)
{
    ID3D10BlendState* tempoutBlendState = NULL;

    D3D10_BLEND_DESC desc = {0};
    description.CopyTo(&desc);
    
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateBlendState(
        &desc, &tempoutBlendState));
    
    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);
}

D3DBuffer^ D3DDevice::CreateBuffer(BufferDescription description, SubresourceData initialData)
{
    ID3D10Buffer* tempoutBuffer = NULL;

    D3D10_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);
    
    D3D10_BUFFER_DESC nativeDesc = {0};
    description.CopyTo(&nativeDesc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateBuffer(
        &nativeDesc, 
        &data, 
        &tempoutBuffer));
    
    return tempoutBuffer == NULL ? nullptr :  gcnew D3DBuffer(tempoutBuffer);
}

D3DBuffer^ D3DDevice::CreateBuffer(BufferDescription description)
{
    ID3D10Buffer* tempoutBuffer = NULL;
    
    D3D10_BUFFER_DESC nativeDesc = {0};
    description.CopyTo(&nativeDesc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateBuffer(
        &nativeDesc, 
        NULL, 
        &tempoutBuffer));
    
    return tempoutBuffer == NULL ? nullptr :  gcnew D3DBuffer(tempoutBuffer);
}

D3DCounter^ D3DDevice::CreateCounter(CounterDescription description)
{
    ID3D10Counter* tempoutCounter = NULL;

    D3D10_COUNTER_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateCounter(&desc, &tempoutCounter));
    return tempoutCounter == NULL ? nullptr : gcnew D3DCounter(tempoutCounter);
}

DepthStencilState^ D3DDevice::CreateDepthStencilState(DepthStencilDescription description)
{
    ID3D10DepthStencilState* tempoutDepthStencilState = NULL;
    D3D10_DEPTH_STENCIL_DESC desc = {0};
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateDepthStencilState(
        &desc,
        &tempoutDepthStencilState));
    
    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);
}

DepthStencilView^ D3DDevice::CreateDepthStencilView(D3DResource^ resource, DepthStencilViewDescription description)
{
    ID3D10DepthStencilView* tempoutDepthStencilView = NULL;
    D3D10_DEPTH_STENCIL_VIEW_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateDepthStencilView(
        resource->GetInterface<ID3D10Resource>(), 
        &desc, 
        &tempoutDepthStencilView));
    
    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

DepthStencilView^ D3DDevice::CreateDepthStencilView(D3DResource^ resource)
{
    ID3D10DepthStencilView* tempoutDepthStencilView = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateDepthStencilView(
        resource->GetInterface<ID3D10Resource>(), 
        NULL, 
        &tempoutDepthStencilView));
    
    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

GeometryShader^ D3DDevice::CreateGeometryShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    ID3D10GeometryShader* tempoutGeometryShader = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateGeometryShader(shaderBytecode.ToPointer(), static_cast<SIZE_T>(shaderBytecodeLength), &tempoutGeometryShader));
    return tempoutGeometryShader == NULL ? nullptr : gcnew GeometryShader(tempoutGeometryShader);
}

GeometryShader^ D3DDevice::CreateGeometryShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateGeometryShader(IntPtr(data), dataArray->Length);    
}

GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(IntPtr shaderBytecode, UInt32 shaderBytecodeLength, IEnumerable<StreamOutputDeclarationEntry>^ streamOutputDeclarations, UInt32 outputStreamStride)
{
    ID3D10GeometryShader* tempoutGeometryShader = NULL;

    vector<D3D10_SO_DECLARATION_ENTRY> declEntries;
    marshal_context^ ctx = gcnew marshal_context();

    UINT declEntriesLen = CommonUtils::FillValStructsVector<StreamOutputDeclarationEntry,D3D10_SO_DECLARATION_ENTRY>(streamOutputDeclarations, declEntries, ctx);

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateGeometryShaderWithStreamOutput(
        shaderBytecode.ToPointer(), 
        shaderBytecodeLength, 
        declEntriesLen == 0 ? NULL : &declEntries[0], 
        declEntriesLen, 
        static_cast<UINT>(outputStreamStride), 
        &tempoutGeometryShader));

    GC::KeepAlive(ctx);

    return tempoutGeometryShader == NULL ? nullptr : gcnew GeometryShader(tempoutGeometryShader);
}
GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(Stream^ stream, IEnumerable<StreamOutputDeclarationEntry>^ streamOutputDeclarations, UInt32 outputStreamStride)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateGeometryShaderWithStreamOutput(IntPtr(data), dataArray->Length, streamOutputDeclarations, outputStreamStride);
}


InputLayout^ D3DDevice::CreateInputLayout(
    IEnumerable<InputElementDescription>^ inputElementDescriptions, 
    IntPtr shaderBytecodeWithInputSignature, 
    UInt32 shaderBytecodeWithInputSignatureSize)
{

    vector<D3D10_INPUT_ELEMENT_DESC> inputElements;

    marshal_context^ ctx = gcnew marshal_context();
    UINT count = CommonUtils::FillValStructsVector<InputElementDescription,D3D10_INPUT_ELEMENT_DESC>(inputElementDescriptions,inputElements, ctx);
    
    ID3D10InputLayout* tempoutInputLayout = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateInputLayout(
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

PixelShader^ D3DDevice::CreatePixelShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    ID3D10PixelShader* tempoutPixelShader = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreatePixelShader(shaderBytecode.ToPointer(), static_cast<SIZE_T>(shaderBytecodeLength), &tempoutPixelShader));
    
    return tempoutPixelShader == NULL ? nullptr : gcnew PixelShader(tempoutPixelShader);
}

PixelShader^ D3DDevice::CreatePixelShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];

    return CreatePixelShader(IntPtr(data), dataArray->Length);
}

D3DPredicate^ D3DDevice::CreatePredicate(QueryDescription description)
{
    ID3D10Predicate* tempoutPredicate = NULL;
    D3D10_QUERY_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreatePredicate(&desc, &tempoutPredicate));
    
    return tempoutPredicate == NULL ? nullptr : gcnew D3DPredicate(tempoutPredicate);
}

D3DQuery^ D3DDevice::CreateQuery(QueryDescription description)
{
    ID3D10Query* tempoutQuery = NULL;
    D3D10_QUERY_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateQuery(&desc, &tempoutQuery));
    return tempoutQuery == NULL ? nullptr : gcnew D3DQuery(tempoutQuery);
}

RasterizerState^ D3DDevice::CreateRasterizerState(RasterizerDescription description)
{
    D3D10_RASTERIZER_DESC desc;
    description.CopyTo(&desc);

    ID3D10RasterizerState* tempoutRasterizerState = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateRasterizerState(
        &desc, 
        &tempoutRasterizerState));
    return tempoutRasterizerState == NULL ? nullptr : gcnew RasterizerState(tempoutRasterizerState);
}

RenderTargetView^ D3DDevice::CreateRenderTargetView(D3DResource^ resource, RenderTargetViewDescription description)
{
    ID3D10RenderTargetView* tempoutRTView = NULL;
    pin_ptr<RenderTargetViewDescription> ptr = &description;

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateRenderTargetView(
        resource->GetInterface<ID3D10Resource>(), 
        (D3D10_RENDER_TARGET_VIEW_DESC*)ptr, 
        &tempoutRTView));

    return tempoutRTView == NULL ? nullptr : gcnew RenderTargetView(tempoutRTView);
}

RenderTargetView^ D3DDevice::CreateRenderTargetView(D3DResource^ resource)
{
    ID3D10RenderTargetView* tempoutRTView = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateRenderTargetView(
        resource->GetInterface<ID3D10Resource>(), 
        NULL, 
        &tempoutRTView));

    return tempoutRTView == NULL ? nullptr : gcnew RenderTargetView(tempoutRTView);
}

SamplerState^ D3DDevice::CreateSamplerState(SamplerDescription description)
{

    ID3D10SamplerState* tempoutSamplerState = NULL;
    D3D10_SAMPLER_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateSamplerState(&desc, &tempoutSamplerState));
    return tempoutSamplerState == NULL ? nullptr : gcnew SamplerState(tempoutSamplerState);
}

ShaderResourceView^ D3DDevice::CreateShaderResourceView(D3DResource^ resource, ShaderResourceViewDescription description)
{
    CommonUtils::CheckNull(resource, "resource");

    ID3D10ShaderResourceView* tempoutSRView = NULL;
    D3D10_SHADER_RESOURCE_VIEW_DESC desc;
    description.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateShaderResourceView(
        resource->GetInterface<ID3D10Resource>(), 
        &desc, 
        &tempoutSRView));

    return tempoutSRView == NULL ? nullptr : gcnew ShaderResourceView(tempoutSRView);
}

ShaderResourceView^ D3DDevice::CreateShaderResourceView(D3DResource^ resource)
{
    ID3D10ShaderResourceView* tempoutSRView = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateShaderResourceView(
        resource->GetInterface<ID3D10Resource>(), 
        NULL, 
        &tempoutSRView));

    return tempoutSRView == NULL ? nullptr : gcnew ShaderResourceView(tempoutSRView);
}
Texture1D^ D3DDevice::CreateTexture1D(Texture1DDescription description, SubresourceData initialData)
{
    ID3D10Texture1D* tempoutTexture1D = NULL;
    
    D3D10_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);

    pin_ptr<Texture1DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateTexture1D(
        (D3D10_TEXTURE1D_DESC*) ptr, 
        &data, 
        &tempoutTexture1D));
    
    return tempoutTexture1D == NULL ? nullptr : gcnew Texture1D(tempoutTexture1D);
}

Texture2D^ D3DDevice::CreateTexture2D(Texture2DDescription description, SubresourceData initialData)
{
    ID3D10Texture2D* tempoutTexture2D = NULL;

    D3D10_TEXTURE2D_DESC nativeDesc = {0};
    description.CopyTo(&nativeDesc);
    
    D3D10_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateTexture2D(
        &nativeDesc, 
        &data, 
        &tempoutTexture2D));

    return tempoutTexture2D == NULL ? nullptr : gcnew Texture2D(tempoutTexture2D);
}

Texture3D^ D3DDevice::CreateTexture3D(Texture3DDescription description, SubresourceData initialData)
{
    ID3D10Texture3D* tempoutTexture3D = NULL;
    
    pin_ptr<Texture3DDescription> ptr = &description;

    D3D10_SUBRESOURCE_DATA data;
    initialData.CopyTo(&data);

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateTexture3D(
            (D3D10_TEXTURE3D_DESC*) ptr, 
            &data, 
            &tempoutTexture3D));
    return tempoutTexture3D == NULL ? nullptr : gcnew Texture3D(tempoutTexture3D);
}

Texture1D^ D3DDevice::CreateTexture1D(Texture1DDescription description)
{
    ID3D10Texture1D* tempoutTexture1D = NULL;

    pin_ptr<Texture1DDescription> ptr = &description;

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateTexture1D(
        (D3D10_TEXTURE1D_DESC*) ptr, 
        NULL, 
        &tempoutTexture1D));
    
    return tempoutTexture1D == NULL ? nullptr : gcnew Texture1D(tempoutTexture1D);
}

Texture2D^ D3DDevice::CreateTexture2D(Texture2DDescription description)
{
    ID3D10Texture2D* tempoutTexture2D = NULL;

    D3D10_TEXTURE2D_DESC nativeDesc = {0};
    description.CopyTo(&nativeDesc);

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->CreateTexture2D(
        &nativeDesc, 
        NULL, 
        &tempoutTexture2D));

    return tempoutTexture2D == NULL ? nullptr : gcnew Texture2D(tempoutTexture2D);
}

Texture3D^ D3DDevice::CreateTexture3D(Texture3DDescription description)
{
    ID3D10Texture3D* tempoutTexture3D = NULL;
    pin_ptr<Texture3DDescription> ptr = &description;

    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateTexture3D(
            (D3D10_TEXTURE3D_DESC*) ptr, 
            NULL, 
            &tempoutTexture3D));
    return tempoutTexture3D == NULL ? nullptr : gcnew Texture3D(tempoutTexture3D);
}

VertexShader^ D3DDevice::CreateVertexShader(IntPtr shaderBytecode, UInt32 shaderBytecodeLength)
{
    ID3D10VertexShader* tempoutVertexShader = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID3D10Device>()->CreateVertexShader(
            shaderBytecode.ToPointer(), 
            shaderBytecodeLength, 
            &tempoutVertexShader));
    
    return tempoutVertexShader == NULL ? nullptr : gcnew VertexShader(tempoutVertexShader);
}

VertexShader^ D3DDevice::CreateVertexShader(Stream^ stream)
{
    array<unsigned char>^ dataArray = CommonUtils::ReadStream(stream);
    pin_ptr<unsigned char> data = &dataArray[0];
    return CreateVertexShader(IntPtr(data), dataArray->Length);
}

void D3DDevice::Draw(UInt32 vertexCount, UInt32 startVertexLocation)
{
    GetInterface<ID3D10Device>()->Draw(static_cast<UINT>(vertexCount), static_cast<UINT>(startVertexLocation));
}

void D3DDevice::DrawAuto()
{
    GetInterface<ID3D10Device>()->DrawAuto();
}

void D3DDevice::DrawIndexed(UInt32 indexCount, UInt32 startIndexLocation, Int32 baseVertexLocation)
{
    GetInterface<ID3D10Device>()->DrawIndexed(static_cast<UINT>(indexCount), static_cast<UINT>(startIndexLocation), safe_cast<INT>(baseVertexLocation));
}

void D3DDevice::DrawIndexedInstanced(UInt32 indexCountPerInstance, UInt32 instanceCount, UInt32 startIndexLocation, Int32 baseVertexLocation, UInt32 startInstanceLocation)
{
    GetInterface<ID3D10Device>()->DrawIndexedInstanced(static_cast<UINT>(indexCountPerInstance), static_cast<UINT>(instanceCount), static_cast<UINT>(startIndexLocation), safe_cast<INT>(baseVertexLocation), static_cast<UINT>(startInstanceLocation));
}

void D3DDevice::DrawInstanced(UInt32 vertexCountPerInstance, UInt32 instanceCount, UInt32 startVertexLocation, UInt32 startInstanceLocation)
{
    GetInterface<ID3D10Device>()->DrawInstanced(static_cast<UINT>(vertexCountPerInstance), static_cast<UINT>(instanceCount), static_cast<UINT>(startVertexLocation), static_cast<UINT>(startInstanceLocation));
}

void D3DDevice::Flush()
{
    GetInterface<ID3D10Device>()->Flush();
}

void D3DDevice::GenerateMips(ShaderResourceView^ shaderResourceView)
{
    GetInterface<ID3D10Device>()->GenerateMips(shaderResourceView->GetInterface<ID3D10ShaderResourceView>());
}

D3DPredicate^ D3DDevice::GetPredication([System::Runtime::InteropServices::Out] Boolean %outPredicateValue)
{
    ID3D10Predicate* tempoutPredicate = NULL;
    BOOL tempoutPredicateValue;
    GetInterface<ID3D10Device>()->GetPredication(&tempoutPredicate, &tempoutPredicateValue);
    outPredicateValue = tempoutPredicateValue != 0;

    return tempoutPredicate == NULL ? nullptr :gcnew D3DPredicate(tempoutPredicate);
}

generic <typename T> where T : DXGIObject
T D3DDevice::OpenSharedResource(IntPtr resource)
{
    void* tempoutResource = NULL;

    GUID guid = CommonUtils::GetGuid(T::typeid);
    
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->OpenSharedResource(static_cast<HANDLE>(resource.ToPointer()), guid, &tempoutResource));
    
    return CommonUtils::CreateIUnknownWrapper<T>(static_cast<IUnknown*>(tempoutResource));
}

void D3DDevice::ResolveSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, D3DResource^ sourceResource, UInt32 sourceSubresource, Format format)
{
    GetInterface<ID3D10Device>()->ResolveSubresource(destinationResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(destinationSubresource), sourceResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(sourceSubresource), static_cast<DXGI_FORMAT>(format));
}

void D3DDevice::SetPredication(D3DPredicate^ D3DPredicate, Boolean PredicateValue)
{
    GetInterface<ID3D10Device>()->SetPredication(D3DPredicate->GetInterface<ID3D10Predicate>(), safe_cast<BOOL>(PredicateValue));
}

void D3DDevice::UpdateSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, IntPtr sourceData, UInt32 sourceRowPitch, UInt32 sourceDepthPitch, Box destinationBox)
{
    pin_ptr<Box> boxPtr = &destinationBox;;
    GetInterface<ID3D10Device>()->UpdateSubresource(destinationResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(destinationSubresource), (D3D10_BOX*)boxPtr, reinterpret_cast<LPVOID>(sourceData.ToPointer()), static_cast<UINT>(sourceRowPitch), static_cast<UINT>(sourceDepthPitch));
}

void D3DDevice::UpdateSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, IntPtr sourceData, UInt32 sourceRowPitch, UInt32 sourceDepthPitch)
{
    GetInterface<ID3D10Device>()->UpdateSubresource(destinationResource->GetInterface<ID3D10Resource>(), static_cast<UINT>(destinationSubresource), NULL, reinterpret_cast<LPVOID>(sourceData.ToPointer()), static_cast<UINT>(sourceRowPitch), static_cast<UINT>(sourceDepthPitch));
}

CreateDeviceFlag D3DDevice::CreationFlags::get()
{
    UINT returnValue = GetInterface<ID3D10Device>()->GetCreationFlags();
    return safe_cast<CreateDeviceFlag>(returnValue);
}

ErrorCode D3DDevice::DeviceRemovedReason::get()
{
    return safe_cast<ErrorCode>(GetInterface<ID3D10Device>()->GetDeviceRemovedReason());
}

RaiseFlag D3DDevice::ExceptionMode::get()
{
    UINT returnValue = GetInterface<ID3D10Device>()->GetExceptionMode();
    return safe_cast<RaiseFlag>(returnValue);
}

void D3DDevice::ExceptionMode::set(RaiseFlag value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->SetExceptionMode(static_cast<UINT>(value)));
}

InfoQueue ^ D3DDevice::GetInfoQueue()
{
    ID3D10InfoQueue * infoQueue = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->QueryInterface(__uuidof(ID3D10InfoQueue), (void**) &infoQueue));

    return infoQueue == NULL ? nullptr : gcnew InfoQueue(infoQueue);
}

// Gets a switch-to-reference object that enables an application to switch between a hardware and software device.
// Can only be obtained if the device was created using CreateDeviceFlag.SwitchToRef flag
// If it was not - it will throw an InvalidCastException
SwitchToRef ^ D3DDevice::GetSwitchToRef()
{
    ID3D10SwitchToRef * switchToRef = NULL;

    CommonUtils::VerifyResult(GetInterface<ID3D10Device>()->QueryInterface(__uuidof(ID3D10SwitchToRef), (void**) &switchToRef));

    return switchToRef == NULL ? nullptr : gcnew SwitchToRef(switchToRef);
}

// The pipeline stage accessors

GeometryShaderPipelineStage^ D3DDevice::GS::get() 
{ 
    if (m_GS == nullptr) 
        m_GS = gcnew GeometryShaderPipelineStage(this); 
    
    return m_GS; 
}


InputAssemblerPipelineStage^ D3DDevice::IA::get() 
{ 
    if (m_IA == nullptr) 
        m_IA = gcnew InputAssemblerPipelineStage(this); 
    
    return m_IA; 
}

OutputMergerPipelineStage^ D3DDevice::OM::get() 
{ 
    if (m_OM == nullptr) 
        m_OM = gcnew OutputMergerPipelineStage(this); 
    
    return m_OM; 
}

PixelShaderPipelineStage^ D3DDevice::PS::get() 
{ 
    if (m_PS == nullptr) 
        m_PS = gcnew PixelShaderPipelineStage(this); 
    
    return m_PS; 
}

RasterizerPipelineStage^ D3DDevice::RS::get() 
{ 
    if (m_RS == nullptr) 
        m_RS = gcnew RasterizerPipelineStage(this); 
    
    return m_RS; 
}

StreamOutputPipelineStage^ D3DDevice::SO::get() 
{ 
    if (m_SO == nullptr) 
        m_SO = gcnew StreamOutputPipelineStage(this); 
    
    return m_SO; 
}

VertexShaderPipelineStage^ D3DDevice::VS::get() 
{ 
    if (m_VS == nullptr) 
        m_VS = gcnew VertexShaderPipelineStage(this); 
    
    return m_VS; 
}

Effect^ D3DDevice::CreateEffectFromCompiledBinary( String^ path )
{
    FileStream^ stream = File::Open( path, FileMode::Open );
    return CreateEffectFromCompiledBinary( gcnew BinaryReader( stream ), 0, nullptr );
}

Effect^ D3DDevice::CreateEffectFromCompiledBinary( BinaryReader^ binaryEffect )
{
    return CreateEffectFromCompiledBinary( binaryEffect, 0, nullptr );
}

Effect^ D3DDevice::CreateEffectFromCompiledBinary( Stream^ inputStream )
{
    return CreateEffectFromCompiledBinary( gcnew BinaryReader( inputStream ), 0, nullptr );
}

Effect^ D3DDevice::CreateEffectFromCompiledBinary( Stream^ inputStream, int effectFlags, EffectPool^ effectPool )
{
    return CreateEffectFromCompiledBinary( gcnew BinaryReader( inputStream ), effectFlags, effectPool );
}


Effect^ D3DDevice::CreateEffectFromCompiledBinary( BinaryReader^ binaryEffect, int effectFlags, EffectPool^ effectPool )
{
    array<unsigned char>^ data = binaryEffect->ReadBytes((int)binaryEffect->BaseStream->Length);
    pin_ptr<unsigned char> pData = &data[0];

    ID3D10Effect* pEffect = NULL;
    CommonUtils::VerifyResult(
        CreateEffectFromMemory( 
            pData,
            data->Length,
            effectFlags,
            this->GetInterface<ID3D10Device>(),
            effectPool ? effectPool->GetInterface<ID3D10EffectPool>() : NULL,
            &pEffect));

    return pEffect ? gcnew Effect( pEffect ) : nullptr;
}

DXGIDevice^ D3DDevice::GetDXGIDevice() 
{
    IDXGIDevice * pDXGIDevice = NULL;
    CommonUtils::VerifyResult(GetInterface<IUnknown>()->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice));

    return pDXGIDevice == NULL ? nullptr : gcnew DXGIDevice(pDXGIDevice);
}
