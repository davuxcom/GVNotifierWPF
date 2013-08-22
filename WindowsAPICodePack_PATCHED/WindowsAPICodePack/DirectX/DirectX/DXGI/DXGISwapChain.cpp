// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGISwapChain.h"
#include "DXGIOutput.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

generic <typename T>  where T : DirectUnknown  
T SwapChain::GetBuffer(UInt32 bufferIndex)
{
    void* tempResource = NULL;
    GUID guid = CommonUtils::GetGuid(T::typeid);
    
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetBuffer(bufferIndex, guid, &tempResource));

    return CommonUtils::CreateIUnknownWrapper<T>(static_cast<IUnknown*>(tempResource));
}

Output^ SwapChain::GetContainingOutput()
{
    IDXGIOutput* tempoutOutput = NULL;
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetContainingOutput(&tempoutOutput));

    return (tempoutOutput == NULL ? nullptr : gcnew Output(tempoutOutput));
}

SwapChainDescription SwapChain::Description::get()
{
    DXGI_SWAP_CHAIN_DESC desc = {0};

    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetDesc(&desc));

    return SwapChainDescription(desc);
}

FrameStatistics SwapChain::GetFrameStatistics()
{
    FrameStatistics stats;
    pin_ptr<FrameStatistics> ptr = &stats;

    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetFrameStatistics((DXGI_FRAME_STATISTICS*)ptr));
    
    return  stats;
}

bool SwapChain::GetFullScreenState([System::Runtime::InteropServices::Out] Output^ %outTarget)
{
    BOOL tempoutFullscreen;
    IDXGIOutput* tempoutTarget = NULL;
    
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetFullscreenState(&tempoutFullscreen, &tempoutTarget));
    
    outTarget = (tempoutTarget == NULL ? nullptr : gcnew Output(tempoutTarget));

    return tempoutFullscreen != 0;
}

bool SwapChain::IsFullScreen::get()
{
    BOOL tempoutFullscreen;
    IDXGIOutput* tempoutTarget;
    
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetFullscreenState(&tempoutFullscreen, &tempoutTarget));
    
    return tempoutFullscreen != 0;
}

void SwapChain::IsFullScreen::set(bool value)
{
    SetFullScreenState(value, nullptr);
}

UInt32 SwapChain::LastPresentCount::get()
{
    UINT tempoutLastPresentCount;
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->GetLastPresentCount(&tempoutLastPresentCount));
    return tempoutLastPresentCount;
}

void SwapChain::Present(UInt32 SyncInterval, PresentFlag Flags)
{
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->Present(static_cast<UINT>(SyncInterval), static_cast<UINT>(Flags)));
}

bool SwapChain::TryPresent(UInt32 SyncInterval, PresentFlag Flags, [System::Runtime::InteropServices::Out] ErrorCode % error)
{
    HRESULT hr = GetInterface<IDXGISwapChain>()->Present(static_cast<UINT>(SyncInterval), static_cast<UINT>(Flags));

    error = safe_cast<ErrorCode>(hr);

    return SUCCEEDED(hr);
}

void SwapChain::ResizeBuffers(UInt32 BufferCount, UInt32 Width, UInt32 Height, Format NewFormat, SwapChainFlag SwapChainFlags)
{
    CommonUtils::VerifyResult(
        GetInterface<IDXGISwapChain>()->ResizeBuffers(
        BufferCount, Width, Height, static_cast<DXGI_FORMAT>(NewFormat), static_cast<UINT>(SwapChainFlags)));
}

bool SwapChain::TryResizeBuffers(UInt32 BufferCount, UInt32 Width, UInt32 Height, Format NewFormat, SwapChainFlag SwapChainFlags, [System::Runtime::InteropServices::Out] ErrorCode % errorCode)
{
    errorCode = static_cast<ErrorCode>(GetInterface<IDXGISwapChain>()->ResizeBuffers(
        BufferCount, Width, Height, static_cast<DXGI_FORMAT>(NewFormat), static_cast<UINT>(SwapChainFlags)));

    return SUCCEEDED(errorCode);
    
}

void SwapChain::ResizeTarget(ModeDescription newTargetParameters)
{
    DXGI_MODE_DESC desc;
    newTargetParameters.CopyTo(&desc);

    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->ResizeTarget(&desc));
}

void SwapChain::SetFullScreenState(Boolean isFullScreen, Output^ Target)
{
    CommonUtils::VerifyResult(GetInterface<IDXGISwapChain>()->SetFullscreenState(isFullScreen ? 1 : 0, Target == nullptr ? NULL : Target->GetInterface<IDXGIOutput>()));
}

