// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10EffectPool.h"

#include "D3D10Effect.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

Effect^ EffectPool::AsEffect()
{
    ID3D10Effect* returnValue = GetInterface<ID3D10EffectPool>()->AsEffect();
    return returnValue == NULL ? nullptr : gcnew Effect(returnValue);
}

