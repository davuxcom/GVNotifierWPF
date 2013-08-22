// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteFontFamilyCollection.h"
#include "DWriteFontFamily.h"

#include <msclr/lock.h>
using namespace msclr;

FontFamilyCollection::FontFamilyCollection(IDWriteFontCollection* pFontCollection) : DirectUnknown(pFontCollection)
{
    UINT count = GetInterface<IDWriteFontCollection>()->GetFontFamilyCount();

    if (count > 0)
    {
        m_families = gcnew array<FontFamily^>(count);
    }
}


FontFamilyCollection::~FontFamilyCollection()
{
    if (m_families != nullptr)
    {
        for each (FontFamily^ family in m_families)
        {
            if (family != nullptr)
            {
                delete family;
            }
        }
        m_families = nullptr;
    }
}

FontFamily^ FontFamilyCollection::InitializeElement(int i)
{
    lock l(this); // Make sure the array is not being modified on another thread, 
                  // otherwise we might get an exception

    if (m_families[i] == nullptr || m_families[i]->GetInterface<IUnknown>() == NULL)
    {
        IDWriteFontFamily* fontFamily = NULL;
        CommonUtils::VerifyResult(
            GetInterface<IDWriteFontCollection>()->GetFontFamily(i, &fontFamily));

        m_families[i] = gcnew FontFamily(fontFamily);
    }
    
    return m_families[i];
}

FontFamily^ FontFamilyCollection::default::get(int index)
{
    if (index >= 0 && index < m_families->Length)
    {        
        return InitializeElement(index);
    }
    else
    {
        throw gcnew IndexOutOfRangeException();
    }
}

void FontFamilyCollection::default::set(int i, FontFamily^ feature)
{
    throw gcnew NotSupportedException("This collection is readonly.");
}

void FontFamilyCollection::Add(FontFamily^ feature)
{
    throw gcnew NotSupportedException("This collection is readonly.");
}

int FontFamilyCollection::Count::get()
{
    return m_families->Length; 
}

bool FontFamilyCollection::IsReadOnly::get()
{
    return true;
}

System::Collections::Generic::IEnumerator<FontFamily^>^ FontFamilyCollection::GetGenericEnumerator()
{
    return gcnew FontFamilyEnum(GetInterface<IDWriteFontCollection>(), this);
}

System::Collections::IEnumerator^ FontFamilyCollection::GetEnumerator()
{
    throw gcnew NotImplementedException();
}

int FontFamilyCollection::IndexOf(FontFamily^ item)
{
    if (item == nullptr)
    {
        throw gcnew ArgumentNullException("item");
    }

    for each (String^ value in item->FamilyNames->Values)
    {
        return this->IndexOf(value);
    }

    return false;
}

void FontFamilyCollection::Insert(int index, FontFamily^ item)
{
    throw gcnew NotSupportedException("This collection is readonly.");
}

void FontFamilyCollection::RemoveAt(int index)
{
    throw gcnew NotSupportedException("This collection is readonly.");
}

void FontFamilyCollection::Clear()
{
    throw gcnew NotSupportedException("This collection is readonly.");
}

bool FontFamilyCollection::Contains(FontFamily^ item)
{
    if (item == nullptr)
    {
        throw gcnew ArgumentNullException("item");
    }

    for each (String^ value in item->FamilyNames->Values)
    {
        return this->Contains(value);
    }

    return false;
}

void FontFamilyCollection::CopyTo(array<FontFamily^>^, int arrayIndex)
{
    throw gcnew NotSupportedException();
}

bool FontFamilyCollection::Remove(FontFamily^ item)
{
    throw gcnew NotSupportedException("This collection is readonly.");
}

bool FontFamilyCollection::Contains(String^ fontFamilyName)
{
    if (String::IsNullOrEmpty(fontFamilyName))
    {
        throw gcnew ArgumentNullException("fontFamilyName", "fontFamilyName cannot be null or empty.");
    }

    UINT32 index;
    BOOL exists;
    pin_ptr<const WCHAR> familyName = PtrToStringChars(fontFamilyName);

    CommonUtils::VerifyResult(GetInterface<IDWriteFontCollection>()->FindFamilyName(familyName, &index, &exists));
    
    return exists ? true : false;
}

int FontFamilyCollection::IndexOf(String^ fontFamilyName)
{
    if (String::IsNullOrEmpty(fontFamilyName))
    {
        throw gcnew ArgumentNullException("fontFamilyName", "fontFamilyName cannot be null or empty.");
    }

    UINT32 index;
    BOOL exists;
    pin_ptr<const WCHAR> familyName = PtrToStringChars(fontFamilyName);

    CommonUtils::VerifyResult(GetInterface<IDWriteFontCollection>()->FindFamilyName(familyName, &index, &exists));
    
    if (exists)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

FontFamilyEnum::FontFamilyEnum(IDWriteFontCollection* pFontCollection, FontFamilyCollection^ familyCollection) : DirectUnknown(pFontCollection), m_current(-1), m_familyCollection(familyCollection)
{ 
    GetInterface<IUnknown>()->AddRef();
}

FontFamily^ FontFamilyEnum::Current::get()
{ 
    return m_familyCollection[m_current];
}
        
System::Object^ FontFamilyEnum::CurrentObject::get()
{
    throw gcnew NotImplementedException();
}

 bool FontFamilyEnum::MoveNext()
{
    if (m_current + 1 < static_cast<int>(m_familyCollection->Count))
    {
        m_current++;
        return true;
    }

    return false;
}

void FontFamilyEnum::Reset()
{
    m_current = -1;
}
