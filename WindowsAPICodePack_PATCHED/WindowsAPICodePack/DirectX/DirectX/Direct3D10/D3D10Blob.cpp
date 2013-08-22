// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D10Blob.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D10;

IntPtr Blob::GetBufferPointer()
{
    return IntPtr(GetInterface<ID3D10Blob>()->GetBufferPointer());
}

UInt32 Blob::GetBufferSize()
{
    return static_cast<UInt32>(GetInterface<ID3D10Blob>()->GetBufferSize());
}

