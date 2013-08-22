// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include "D3D10Debug.h"
#include "DXGI/DXGISwapChain.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
DebugFeature D3DDebug::FeatureMask::get()
{
    return static_cast<DebugFeature>(GetInterface<ID3D10Debug>()->GetFeatureMask());
}

UInt32 D3DDebug::PresentPerRenderOpDelay::get()
{
    return GetInterface<ID3D10Debug>()->GetPresentPerRenderOpDelay();
}

SwapChain^ D3DDebug::RuntimeSwapChain::get()
{
    IDXGISwapChain* tempoutSwapChain = NULL;
    CommonUtils::VerifyResult(GetInterface<ID3D10Debug>()->GetSwapChain(&tempoutSwapChain));
    
    return tempoutSwapChain == NULL ? nullptr : gcnew SwapChain(tempoutSwapChain);
}
void D3DDebug::FeatureMask::set(DebugFeature value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Debug>()->SetFeatureMask(static_cast<UINT>(value)));
}

void D3DDebug::PresentPerRenderOpDelay::set(UInt32 value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Debug>()->SetPresentPerRenderOpDelay(static_cast<UINT>(value)));
}

void D3DDebug::RuntimeSwapChain::set(SwapChain^ value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Debug>()->SetSwapChain(value->GetInterface<IDXGISwapChain>()));
}

void D3DDebug::Validate()
{
    CommonUtils::VerifyResult(GetInterface<ID3D10Debug>()->Validate());
}

