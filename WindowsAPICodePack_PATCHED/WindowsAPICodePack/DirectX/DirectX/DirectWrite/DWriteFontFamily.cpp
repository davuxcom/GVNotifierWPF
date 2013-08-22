// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteFontFamily.h"
#include "DWriteFont.h"

#include <msclr/lock.h>
using namespace msclr;

FontFamily::~FontFamily()
{
    if (m_names != nullptr)
    {
        delete m_names;
        m_names = nullptr;
    }

    if (m_fonts != nullptr)
    {
        for each (Font^ font in m_fonts)
        {
            if (font != nullptr)
            {
                delete font;
            }
        }
        m_fonts = nullptr;
    }
}

IDictionary<CultureInfo^, String^>^ FontFamily::FamilyNames::get()
{ 
    lock l(this); // Make sure the collection is not being created on another thread

    if (m_names == nullptr)
    {
        IDWriteLocalizedStrings* names = NULL;

        try
        {
            CommonUtils::VerifyResult(GetInterface<IDWriteFontFamily>()->GetFamilyNames(&names));
            
            if (names)
                m_names = CommonUtils::GetCultureNameDictionary(names);
        }
        finally
        {
            if (names)
                names->Release();
        }
    }

    return m_names;
}



ReadOnlyCollection<DWrite::Font^>^ FontFamily::Fonts::get()
{
    lock l(this); // Make sure the collection is not being created on another thread

    if (m_fonts == nullptr)
    {
        List<DWrite::Font^>^ fontList = gcnew List<DWrite::Font^>();

        UINT count = GetInterface<IDWriteFontFamily>()->GetFontCount();

        for (UINT i = 0; i < count; i++)
        {
            IDWriteFont* font = NULL;
            GetInterface<IDWriteFontFamily>()->GetFont(i, &font);

            if (font)
            {
                fontList->Add(gcnew DWrite::Font(font));
            }
        }

        m_fonts = gcnew ReadOnlyCollection<DWrite::Font^>(fontList);
    }

    return m_fonts;
}