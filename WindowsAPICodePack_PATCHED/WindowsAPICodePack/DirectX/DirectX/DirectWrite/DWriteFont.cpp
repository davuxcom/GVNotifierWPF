// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteFont.h"
#include "DWriteFontFace.h"
#include "DWriteFontFamily.h"

IDictionary<CultureInfo^, System::String^>^ DWrite::Font::FaceNames::get()
{
    if (m_faceNames == nullptr)
    {
        IDWriteLocalizedStrings* names = NULL;

        try
        {
            CommonUtils::VerifyResult(GetInterface<IDWriteFont>()->GetFaceNames(&names));

            if (names)
                m_faceNames = CommonUtils::GetCultureNameDictionary(names);

        }
        finally
        {
            if (names)
                names->Release();
        }
    }


    return m_faceNames;
}

IDictionary<CultureInfo^, System::String^>^ DWrite::Font::GetInformationalStrings(InformationalStringId informationalStringID)
{
    IDWriteLocalizedStrings* names = NULL;

    try
    {
        BOOL exists = FALSE;
        CommonUtils::VerifyResult(GetInterface<IDWriteFont>()->GetInformationalStrings(
            static_cast<DWRITE_INFORMATIONAL_STRING_ID>(informationalStringID),
            &names,
            &exists));

        if (exists && names)
            return CommonUtils::GetCultureNameDictionary(names);
        else
            return nullptr;
    }
    finally
    {

        if (names)
            names->Release();
    }
}


DWrite::FontFamily^ DWrite::Font::FontFamily::get()
{
    if (m_fontFamily == nullptr)
    {
        IDWriteFontFamily* fontFamily = NULL;
        CommonUtils::VerifyResult(GetInterface<IDWriteFont>()->GetFontFamily(&fontFamily));

        m_fontFamily = fontFamily ? gcnew DWrite::FontFamily(fontFamily) : nullptr;
    }

    return m_fontFamily;
}

FontWeight DWrite::Font::Weight::get()
{
    return static_cast<FontWeight>(GetInterface<IDWriteFont>()->GetWeight());
}

FontStretch DWrite::Font::Stretch::get()
{
    return static_cast<FontStretch>(GetInterface<IDWriteFont>()->GetStretch());
}

FontStyle DWrite::Font::Style::get()
{
    return static_cast<FontStyle>(GetInterface<IDWriteFont>()->GetStyle());
}

Boolean DWrite::Font::IsSymbolFont::get()
{
    return GetInterface<IDWriteFont>()->IsSymbolFont() != 0;
}


FontSimulations DWrite::Font::Simulations::get()
{
    return static_cast<FontSimulations>(GetInterface<IDWriteFont>()->GetSimulations());
}

FontMetrics DWrite::Font::Metrics::get()
{
    DWRITE_FONT_METRICS metricsCopy;
    GetInterface<IDWriteFont>()->GetMetrics(&metricsCopy);

    FontMetrics metrics;
    metrics.CopyFrom(metricsCopy);

    return metrics;
}

Boolean DWrite::Font::HasCharacter(UInt32 unicodeValue)
{
    BOOL exists;
    CommonUtils::VerifyResult(GetInterface<IDWriteFont>()->HasCharacter(unicodeValue, &exists));

    return exists != 0;
}

Boolean DWrite::Font::HasCharacter(System::Char unicodeChar)
{
    BOOL exists;
    CommonUtils::VerifyResult(GetInterface<IDWriteFont>()->HasCharacter(Convert::ToUInt32(unicodeChar), &exists));

    return exists != 0;
}

FontFace^ DWrite::Font::CreateFontFace()
{
    IDWriteFontFace* fontFace = NULL;
    CommonUtils::VerifyResult(GetInterface<IDWriteFont>()->CreateFontFace(&fontFace));

    return fontFace ? gcnew FontFace(fontFace) : nullptr;
}
