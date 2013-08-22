// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGISurface1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

IntPtr Surface1::GetDC(Boolean Discard)
{
    HDC tempouthdc;
    CommonUtils::VerifyResult(GetInterface<IDXGISurface1>()->GetDC(safe_cast<BOOL>(Discard), &tempouthdc));
    
    return IntPtr(tempouthdc);
}

void Surface1::ReleaseDC(D3dRect DirtyRect)
{
    CommonUtils::VerifyResult(GetInterface<IDXGISurface1>()->ReleaseDC(&((RECT)DirtyRect)));
}

