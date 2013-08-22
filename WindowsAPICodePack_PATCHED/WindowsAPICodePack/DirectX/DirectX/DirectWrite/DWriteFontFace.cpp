// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteFontFace.h"
#include "DWriteFontFamily.h"

FontFaceType FontFace::FaceType::get()
{
    return static_cast<FontFaceType>(GetInterface<IDWriteFontFace>()->GetType());
}

UINT32 FontFace::Index::get()
{
    return GetInterface<IDWriteFontFace>()->GetIndex();
}

FontSimulations FontFace::Simulations::get()
{
    return static_cast<FontSimulations>(GetInterface<IDWriteFontFace>()->GetSimulations());
}

Boolean FontFace::IsSymbolFont::get()
{
    return GetInterface<IDWriteFontFace>()->IsSymbolFont() != 0;
}

FontMetrics FontFace::Metrics::get()
{
    DWRITE_FONT_METRICS metrics;
    GetInterface<IDWriteFontFace>()->GetMetrics(&metrics);

    return FontMetrics(metrics);
}

UINT16 FontFace::GlyphCount::get()
{
    return GetInterface<IDWriteFontFace>()->GetGlyphCount();
}

array<GlyphMetrics>^ FontFace::GetDesignGlyphMetrics(array<UINT16>^ glyphIndices, BOOL isSideways)
{
    array<GlyphMetrics>^ glyphMetrics = gcnew array<GlyphMetrics>(glyphIndices->Length);
    pin_ptr<UINT16> glyphIndicesPtr = &glyphIndices[0];

    pin_ptr<GlyphMetrics> glyphMetricsPtr = &glyphMetrics[0];
    
    CommonUtils::VerifyResult(GetInterface<IDWriteFontFace>()->GetDesignGlyphMetrics(glyphIndicesPtr, glyphIndices->Length, (DWRITE_GLYPH_METRICS*)glyphMetricsPtr, isSideways ? 1 : 0));

    return glyphMetrics;
}

array<GlyphMetrics>^ FontFace::GetDesignGlyphMetrics(array<UINT16>^ glyphIndices)
{
    return GetDesignGlyphMetrics(glyphIndices, false);
}

array<UINT16>^ FontFace::GetGlyphIndices(array<UINT32>^ codePoints)
{
    array<UINT16>^ glyphIndices = gcnew array<UINT16>(codePoints->Length);
    pin_ptr<UINT16> glyphIndicesPtr = &glyphIndices[0];

    pin_ptr<UINT32> codePointsPtr = &codePoints[0];    
    CommonUtils::VerifyResult(GetInterface<IDWriteFontFace>()->GetGlyphIndicesW(codePointsPtr, codePoints->Length, glyphIndicesPtr));

    return glyphIndices;
}

array<UINT16>^ FontFace::GetGlyphIndices(array<System::Char>^ chars)
{
    array<UINT16>^ glyphIndices = gcnew array<UINT16>(chars->Length);
    pin_ptr<UINT16> glyphIndicesPtr = &glyphIndices[0];

    array<UINT32>^ codePoints = gcnew array<UINT32>(chars->Length);
    for (int i = 0; i < chars->Length; i++)
    {
        codePoints[i] = Convert::ToUInt32(chars[i]);
    }

    pin_ptr<UINT32> codePointsPtr = &codePoints[0];    
    CommonUtils::VerifyResult(GetInterface<IDWriteFontFace>()->GetGlyphIndicesW(codePointsPtr, codePoints->Length, glyphIndicesPtr));

    return glyphIndices;
}

array<UINT16>^ FontFace::GetGlyphIndices(System::String^ textString)
{
    array<UINT16>^ glyphIndices = gcnew array<UINT16>(textString->Length);
    pin_ptr<UINT16> glyphIndicesPtr = &glyphIndices[0];

    array<UINT32>^ codePoints = gcnew array<UINT32>(textString->Length);
    for (int i = 0; i < textString->Length; i++)
    {
        codePoints[i] = Convert::ToUInt32(textString[i]);
    }

    pin_ptr<UINT32> codePointsPtr = &codePoints[0];    
    CommonUtils::VerifyResult(GetInterface<IDWriteFontFace>()->GetGlyphIndicesW(codePointsPtr, codePoints->Length, glyphIndicesPtr));

    return glyphIndices;
}