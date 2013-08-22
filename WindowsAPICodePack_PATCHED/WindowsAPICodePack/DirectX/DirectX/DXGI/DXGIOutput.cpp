// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include <vector>

#include "DXGIOutput.h"
#include "DXGISurface.h"
#include "DXGIDevice.h"
#include "Direct3D11/D3D11Device.h"
#include "Direct3D10/D3D10Device.h"

using namespace std;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;

ModeDescription Output::FindClosestMatchingMode(ModeDescription modeToMatch, Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ ConcernedDevice)
{
    DXGI_MODE_DESC inMode;
    modeToMatch.CopyTo(&inMode);

    DXGI_MODE_DESC outMode;

    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->FindClosestMatchingMode(
        &inMode, &outMode, 
        ConcernedDevice == nullptr ? NULL : ConcernedDevice->GetInterface<IUnknown>()));

    return ModeDescription(outMode);
}

ModeDescription Output::FindClosestMatchingMode(ModeDescription modeToMatch, Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ ConcernedDevice)
{
    DXGI_MODE_DESC inMode;
    modeToMatch.CopyTo(&inMode);

    DXGI_MODE_DESC outMode;

    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->FindClosestMatchingMode(
        &inMode, &outMode, 
        (ConcernedDevice == nullptr ? NULL : ConcernedDevice->GetInterface<IUnknown>())));

    return ModeDescription(outMode);
}

ModeDescription Output::FindClosestMatchingMode(ModeDescription modeToMatch)
{
    DXGI_MODE_DESC inMode;
    modeToMatch.CopyTo(&inMode);

    DXGI_MODE_DESC outMode;

    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->FindClosestMatchingMode(
        &inMode, &outMode, 
        NULL));
    
    return ModeDescription(outMode);
}

UInt32 Output::GetNumberOfDisplayModes(Format colorFormat, EnumModes flags)
{
    UINT outNumModes = 0;

    CommonUtils::VerifyResult(
        GetInterface<IDXGIOutput>()->GetDisplayModeList(
        static_cast<DXGI_FORMAT>(colorFormat), static_cast<UINT>(flags), &outNumModes, NULL));

    return outNumModes;
}

array<ModeDescription>^ Output::GetDisplayModeList(Format colorFormat, EnumModes flags)
{
    UINT numModes = GetNumberOfDisplayModes(colorFormat, flags);
    array<ModeDescription>^ descriptions = nullptr;

    if (numModes > 0)
    {
        descriptions = gcnew array<ModeDescription>(numModes);
        pin_ptr<ModeDescription> ptr = &descriptions[0];

        CommonUtils::VerifyResult(
            GetInterface<IDXGIOutput>()->GetDisplayModeList(
            static_cast<DXGI_FORMAT>(colorFormat), static_cast<UINT>(flags), &numModes, (DXGI_MODE_DESC*) ptr));
    }

    return descriptions;
}
OutputDescription Output::Description::get()
{

    DXGI_OUTPUT_DESC desc; 
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->GetDesc(&desc));

    return OutputDescription(desc);
}

void Output::GetDisplaySurfaceData(Surface^ Destination)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->GetDisplaySurfaceData(Destination->GetInterface<IDXGISurface>()));
    
    // Since the native function increase the ref count, we need to make sure 
    // it's decreased again so we don't get a memory leak
    
    Destination->GetInterface<IDXGISurface>()->Release();
}

FrameStatistics Output::GetRenderedFrameStatistics()
{
    DXGI_FRAME_STATISTICS tempoutStats;
    
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->GetFrameStatistics(&tempoutStats));
    
    return FrameStatistics(tempoutStats);
}

GammaControl Output::GetGammaControl()
{
    DXGI_GAMMA_CONTROL ctrl = {0};

    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->GetGammaControl(&ctrl));

    return GammaControl(ctrl);
}

void Output::SetGammaControl(GammaControl gammaControl)
{
    DXGI_GAMMA_CONTROL ctrl = {0};
    gammaControl.CopyTo(&ctrl);
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->SetGammaControl(&ctrl));
}

GammaControlCapabilities Output::GetGammaControlCapabilities()
{
    DXGI_GAMMA_CONTROL_CAPABILITIES caps = {0};
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->GetGammaControlCapabilities(&caps));
    return GammaControlCapabilities(caps);
}

void Output::SetDisplaySurface(Surface^ ScanoutSurface)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->SetDisplaySurface(ScanoutSurface->GetInterface<IDXGISurface>()));
}

void Output::ReleaseOwnership()
{
    GetInterface<IDXGIOutput>()->ReleaseOwnership();
}
void Output::TakeOwnership(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice^ device, Boolean exclusive)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->TakeOwnership(device->GetInterface<IUnknown>(), safe_cast<BOOL>(exclusive)));
}

void Output::TakeOwnership(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ device, Boolean exclusive)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->TakeOwnership(device->GetInterface<IUnknown>(), safe_cast<BOOL>(exclusive)));
}

void Output::TakeOwnership(DXGIDevice^ device, Boolean exclusive)
{
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->TakeOwnership(device->GetInterface<IDXGIDevice>(), safe_cast<BOOL>(exclusive)));
}
void Output::WaitForVBlank()
{
    CommonUtils::VerifyResult(GetInterface<IDXGIOutput>()->WaitForVBlank());
}

