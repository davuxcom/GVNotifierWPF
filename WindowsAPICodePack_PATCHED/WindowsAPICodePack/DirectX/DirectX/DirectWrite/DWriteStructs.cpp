// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteStructs.h"
#include "DWriteFontFace.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

void GlyphRun::CopyTo(DWRITE_GLYPH_RUN *pNativeStruct)
{
    if (GlyphAdvances->Length != GlyphIndices->Length || GlyphIndices->Length != GlyphOffsets->Length)
    {
        throw gcnew NotSupportedException("GlyphAdvances, GlyphIndices and GlyphOffsets arrays must all have equal lengths.");
    }

    pNativeStruct->bidiLevel = BidiLevel;
    pNativeStruct->isSideways = IsSideways ? 1 : 0;
    pNativeStruct->fontEmSize = FontEmSize;
    pNativeStruct->fontFace = this->FontFace->GetInterface<IDWriteFontFace>();
    pNativeStruct->glyphCount = GlyphAdvances->Length;

    if (pNativeStruct->glyphCount > 0)
    {    
        pin_ptr<FLOAT> pGlyphAdvances = &GlyphAdvances[0];
        pNativeStruct->glyphAdvances = new FLOAT[pNativeStruct->glyphCount];
        memcpy((void*)pNativeStruct->glyphAdvances, pGlyphAdvances, sizeof(FLOAT) * pNativeStruct->glyphCount);

        pin_ptr<UINT16> pGlyphIndices = &GlyphIndices[0];
        pNativeStruct->glyphIndices = new UINT16[pNativeStruct->glyphCount];
        memcpy((void*)pNativeStruct->glyphIndices, pGlyphIndices, sizeof(UINT16) * pNativeStruct->glyphCount);

        pin_ptr<GlyphOffset> pGlyphOffsets = &GlyphOffsets[0];
        pNativeStruct->glyphOffsets = new DWRITE_GLYPH_OFFSET[pNativeStruct->glyphCount];
        memcpy((void*)pNativeStruct->glyphOffsets, pGlyphOffsets, sizeof(DWRITE_GLYPH_OFFSET) * pNativeStruct->glyphCount);
    }

}
