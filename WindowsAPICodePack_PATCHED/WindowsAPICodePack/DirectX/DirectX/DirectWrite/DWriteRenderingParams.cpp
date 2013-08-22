// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteRenderingParams.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

namespace DWrite = Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

FLOAT RenderingParams::Gamma::get()
{ 
    return GetInterface<IDWriteRenderingParams>()->GetGamma();
}

FLOAT RenderingParams::EnhancedContrast::get()
{ 
    return GetInterface<IDWriteRenderingParams>()->GetEnhancedContrast();
}

FLOAT RenderingParams::ClearTypeLevel::get()
{ 
    return GetInterface<IDWriteRenderingParams>()->GetClearTypeLevel();
}

DWrite::PixelGeometry RenderingParams::PixelGeometry::get()
{ 
    return static_cast<DWrite::PixelGeometry>(GetInterface<IDWriteRenderingParams>()->GetPixelGeometry());
}

DWrite::RenderingMode RenderingParams::RenderingMode::get()
{ 
    return static_cast<DWrite::RenderingMode>(GetInterface<IDWriteRenderingParams>()->GetRenderingMode());
} 
