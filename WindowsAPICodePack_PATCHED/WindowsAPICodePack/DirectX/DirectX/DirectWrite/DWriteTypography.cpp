// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteTypography.h"

FontFeature TypographyList::Current::get()
{ 
    DWRITE_FONT_FEATURE fontFeatureCopy;
    CommonUtils::VerifyResult(
        nativeInterface->GetFontFeature((UINT) m_current, &fontFeatureCopy
        ));

    FontFeature fontfeature;
    fontfeature.CopyFrom(fontFeatureCopy);

    return fontfeature;
}
        
System::Object^ TypographyList::CurrentObject::get()
{
    throw gcnew NotImplementedException();
}

 bool TypographyList::MoveNext()
{
    if (m_current + 1 < static_cast<int>(nativeInterface->GetFontFeatureCount()))
    {
        m_current++;
        return true;
    }

    return false;
}

void TypographyList::Reset()
{
    m_current = -1;
}


FontFeature Typography::default::get(int i)
{
    DWRITE_FONT_FEATURE fontFeatureCopy;
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTypography>()->GetFontFeature((UINT) i, &fontFeatureCopy
        ));

    FontFeature fontfeature;
    fontfeature.CopyFrom(fontFeatureCopy);

    return fontfeature;
}

void Typography::default::set(int i, FontFeature feature)
{
    throw gcnew NotSupportedException();
}

void Typography::Add(FontFeature feature)
{
    DWRITE_FONT_FEATURE fontFeatureCopy;
    feature.CopyTo(&fontFeatureCopy);
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTypography>()->AddFontFeature(fontFeatureCopy));
}

int Typography::Count::get()
{
    return static_cast<int>(GetInterface<IDWriteTypography>()->GetFontFeatureCount()); 
}

bool Typography::IsReadOnly::get()
{
    return false;
}

System::Collections::Generic::IEnumerator<FontFeature>^ Typography::GetGenericEnumerator()
{
    throw gcnew NotImplementedException();
}


System::Collections::IEnumerator^ Typography::GetEnumerator()
{
    return gcnew TypographyList(GetInterface<IDWriteTypography>());
}

int Typography::IndexOf(FontFeature item)
{
    throw gcnew NotSupportedException();
}

void Typography::Insert(int index, FontFeature item)
{
    throw gcnew NotSupportedException();
}

void Typography::RemoveAt(int index)
{
    throw gcnew NotSupportedException();
}

void Typography::Clear()
{
    throw gcnew NotSupportedException();
}

bool Typography::Contains(FontFeature item)
{
        throw gcnew NotSupportedException();
}

void Typography::CopyTo(array<FontFeature>^, int arrayIndex)
{
        throw gcnew NotSupportedException();
}

bool Typography::Remove(FontFeature item)
{
    throw gcnew NotSupportedException();
}



