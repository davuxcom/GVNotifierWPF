// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include "WICBitmapFrameDecode.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::WindowsImagingComponent;


BitmapSource^ BitmapFrameDecode::ToBitmapSource()
{
    IWICBitmapSource* pBitmapSource = NULL;
    CommonUtils::VerifyResult(
        GetInterface<IUnknown>()->QueryInterface(__uuidof(IWICBitmapSource), (void **)&pBitmapSource));
    return gcnew BitmapSource( pBitmapSource );
}
