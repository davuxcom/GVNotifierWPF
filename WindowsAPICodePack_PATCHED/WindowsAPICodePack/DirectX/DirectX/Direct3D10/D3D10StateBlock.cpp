// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10StateBlock.h"

#include "D3D10Device.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

void StateBlock::Apply()
{
    CommonUtils::VerifyResult(GetInterface<ID3D10StateBlock>()->Apply());
}

void StateBlock::Capture()
{
    CommonUtils::VerifyResult(GetInterface<ID3D10StateBlock>()->Capture());
}

D3DDevice^ StateBlock::GetDevice()
{
    ID3D10Device* tempoutDevice;
    CommonUtils::VerifyResult(GetInterface<ID3D10StateBlock>()->GetDevice(&tempoutDevice));
    
    return tempoutDevice == NULL ? nullptr : gcnew D3DDevice(tempoutDevice);
}

void StateBlock::ReleaseAllDeviceObjects()
{
    CommonUtils::VerifyResult(GetInterface<ID3D10StateBlock>()->ReleaseAllDeviceObjects());
}

