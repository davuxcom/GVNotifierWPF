// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteTextFormat.h"
#include "ICustomInlineObject.h"
#include "DWriteInlineObject.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

namespace DWrite = Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

DWrite::TextAlignment TextFormat::TextAlignment::get() 
{
    return static_cast<DWrite::TextAlignment>(GetInterface<IDWriteTextFormat>()->GetTextAlignment());
}

void TextFormat::TextAlignment::set(DWrite::TextAlignment value) 
{
    GetInterface<IDWriteTextFormat>()->SetTextAlignment(static_cast<DWRITE_TEXT_ALIGNMENT>(value));
}

DWrite::ParagraphAlignment TextFormat::ParagraphAlignment::get() 
{
    return static_cast<DWrite::ParagraphAlignment>(GetInterface<IDWriteTextFormat>()->GetParagraphAlignment());
}

void TextFormat::ParagraphAlignment::set(DWrite::ParagraphAlignment value) 
{
    GetInterface<IDWriteTextFormat>()->SetParagraphAlignment(static_cast<DWRITE_PARAGRAPH_ALIGNMENT>(value));
}


DWrite::WordWrapping TextFormat::WordWrapping::get() 
{
    return static_cast<DWrite::WordWrapping>(GetInterface<IDWriteTextFormat>()->GetWordWrapping());
}

void TextFormat::WordWrapping::set(DWrite::WordWrapping value) 
{
    GetInterface<IDWriteTextFormat>()->SetWordWrapping(static_cast<DWRITE_WORD_WRAPPING>(value));
}


DWrite::ReadingDirection TextFormat::ReadingDirection::get() 
{
    return static_cast<DWrite::ReadingDirection>(GetInterface<IDWriteTextFormat>()->GetReadingDirection());
}

void TextFormat::ReadingDirection::set(DWrite::ReadingDirection value) 
{
    GetInterface<IDWriteTextFormat>()->SetReadingDirection(static_cast<DWRITE_READING_DIRECTION>(value));
}


DWrite::FlowDirection TextFormat::FlowDirection::get() 
{
    return static_cast<DWrite::FlowDirection>(GetInterface<IDWriteTextFormat>()->GetFlowDirection());
}

void TextFormat::FlowDirection::set(DWrite::FlowDirection value) 
{
    GetInterface<IDWriteTextFormat>()->SetFlowDirection(static_cast<DWRITE_FLOW_DIRECTION>(value));
}


Single TextFormat::IncrementalTabStop::get() 
{
    return GetInterface<IDWriteTextFormat>()->GetIncrementalTabStop();
}

void TextFormat::IncrementalTabStop::set(Single value) 
{
    GetInterface<IDWriteTextFormat>()->SetIncrementalTabStop(value);
}


DWrite::LineSpacing TextFormat::LineSpacing::get() 
{
    DWRITE_LINE_SPACING_METHOD method;
    FLOAT lineSpacing;
    FLOAT baseline;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextFormat>()->GetLineSpacing(&method, &lineSpacing, &baseline));

    return DWrite::LineSpacing(static_cast<LineSpacingMethod>(method), lineSpacing, baseline);
}

void TextFormat::LineSpacing::set(DWrite::LineSpacing value) 
{
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextFormat>()->SetLineSpacing(static_cast<DWRITE_LINE_SPACING_METHOD>(value.LineSpacingMethod), value.Height, value.Baseline));
}

DWrite::Trimming TextFormat::Trimming::get()
{
    DWRITE_TRIMMING trimmingCopy;
    ::IDWriteInlineObject* inlineObject = NULL;
    try 
    {
        CommonUtils::VerifyResult(
            GetInterface<IDWriteTextFormat>()->GetTrimming(&trimmingCopy, &inlineObject));
    }
    finally
    {
        if (inlineObject)
        {
            inlineObject->Release();
        }
    }
    
    DWrite::Trimming returnValue;
    returnValue.CopyFrom(trimmingCopy);
    return returnValue;
}

void TextFormat::Trimming::set(DWrite::Trimming value)
{
    DWRITE_TRIMMING trimmingCopy;
    ::IDWriteInlineObject* inlineObject = NULL;

    try
    {
        // First get a copy of the inline object,
        // The method may fail, so don't throw.
        GetInterface<IDWriteTextFormat>()->GetTrimming(&trimmingCopy, &inlineObject);

        // Copy the trimming
        value.CopyTo(&trimmingCopy);

        CommonUtils::VerifyResult(
            GetInterface<IDWriteTextFormat>()->SetTrimming(&trimmingCopy, inlineObject));    
    }
    finally
    {
        if (inlineObject) // We won't need it, so release
        {
            inlineObject->Release();
        }
    }
}

DWrite::Trimming TextFormat::GetTrimming([System::Runtime::InteropServices::Out] InlineObject^ % trimmingSign)
{
    DWRITE_TRIMMING trimmingCopy;
    ::IDWriteInlineObject* inlineObject = NULL;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextFormat>()->GetTrimming(&trimmingCopy, &inlineObject));

    trimmingSign = inlineObject ? gcnew InlineObject(inlineObject) : nullptr;
    
    DWrite::Trimming returnValue;
    returnValue.CopyFrom(trimmingCopy);
    return returnValue;

}

void TextFormat::SetTrimming(DWrite::Trimming trimmingOptions, ICustomInlineObject^ trimmingSign)
{
    DWRITE_TRIMMING trimmingCopy;
    trimmingOptions.CopyTo(&trimmingCopy);

    CustomInlineObject *pInlineObject = NULL;

     try
     {
         pInlineObject = new CustomInlineObject(
            trimmingSign
            );

        CommonUtils::VerifyResult(
            GetInterface<IDWriteTextFormat>()->SetTrimming(
            &trimmingCopy, 
            pInlineObject));
     }
     finally
     {
         if (pInlineObject)
             pInlineObject->Release();
     }
}

void TextFormat::SetTrimming(DWrite::Trimming trimmingOptions, InlineObject^ trimmingSign)
{
    DWRITE_TRIMMING trimmingCopy;
    trimmingOptions.CopyTo(&trimmingCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextFormat>()->SetTrimming(
        &trimmingCopy, 
        trimmingSign ? trimmingSign->GetInterface<::IDWriteInlineObject>() : NULL));
}

String^ TextFormat::FontFamilyName::get() 
{
    UINT32 len = GetInterface<IDWriteTextFormat>()->GetFontFamilyNameLength() + 1;
    wchar_t* name = new wchar_t[len];

    try
    {        
        CommonUtils::VerifyResult(GetInterface<IDWriteTextFormat>()->GetFontFamilyName(name, len));
        return gcnew String(name);
    }
    finally
    {
        delete [] name;
    }
}


DWrite::FontWeight TextFormat::FontWeight::get() 
{
    return static_cast<DWrite::FontWeight>(GetInterface<IDWriteTextFormat>()->GetFontWeight());
}


DWrite::FontStyle TextFormat::FontStyle::get() 
{
    return static_cast<DWrite::FontStyle>(GetInterface<IDWriteTextFormat>()->GetFontStyle());
}


DWrite::FontStretch TextFormat::FontStretch::get() 
{
    return static_cast<DWrite::FontStretch>(GetInterface<IDWriteTextFormat>()->GetFontStretch());
}


Single TextFormat::FontSize::get() 
{
    return GetInterface<IDWriteTextFormat>()->GetFontSize();
}


System::Globalization::CultureInfo^ TextFormat::CultureInfo::get() 
{
    UINT32 len = GetInterface<IDWriteTextFormat>()->GetLocaleNameLength() + 1;
    wchar_t* name = new wchar_t[len];

    try
    {        
        CommonUtils::VerifyResult(GetInterface<IDWriteTextFormat>()->GetLocaleName(name, len));
        return gcnew System::Globalization::CultureInfo(gcnew String(name));
    }
    finally
    {
        delete [] name;
    }
}

