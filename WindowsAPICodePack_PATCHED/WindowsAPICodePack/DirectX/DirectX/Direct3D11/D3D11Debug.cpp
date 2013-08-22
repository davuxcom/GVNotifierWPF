// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include "D3D11Debug.h"
#include "D3D11DeviceContext.h"
#include "DXGI/DXGISwapChain.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

DebugFeature D3DDebug::FeatureMask::get()
{
    return safe_cast<DebugFeature>(GetInterface<ID3D11Debug>()->GetFeatureMask());
}

UInt32 D3DDebug::PresentPerRenderOpDelay::get()
{
    return GetInterface<ID3D11Debug>()->GetPresentPerRenderOpDelay();
}

SwapChain^ D3DDebug::RuntimeSwapChain::get()
{
    IDXGISwapChain* tempoutSwapChain = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D11Debug>()->GetSwapChain(&tempoutSwapChain));
    
    return tempoutSwapChain == NULL ? nullptr : gcnew SwapChain(tempoutSwapChain);
}

void D3DDebug::ValidateContext(DeviceContext^ Context)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11Debug>()->ValidateContext(Context->GetInterface<ID3D11DeviceContext>()));
}

void D3DDebug::FeatureMask::set(DebugFeature value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11Debug>()->SetFeatureMask(static_cast<UINT>(value)));
}

void D3DDebug::PresentPerRenderOpDelay::set(UInt32 value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11Debug>()->SetPresentPerRenderOpDelay(static_cast<UINT>(value)));
}

void D3DDebug::RuntimeSwapChain::set(SwapChain^ value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11Debug>()->SetSwapChain(value->GetInterface<IDXGISwapChain>()));
}

