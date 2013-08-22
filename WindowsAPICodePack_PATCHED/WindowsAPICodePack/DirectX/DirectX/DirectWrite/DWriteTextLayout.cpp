// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DWriteTextLayout.h"
#include "ICustomInlineObject.h"
#include "DWriteInlineObject.h"
#include "DWriteTypography.h"
#include <vector>

using namespace std;

#ifndef E_INSUFFICIENT_BUFFER
#define E_INSUFFICIENT_BUFFER 0x8007007A
#endif

String^ TextLayout::Text::get()
{
    return _text;
}

FLOAT TextLayout::MaxWidth::get()
{
    return GetInterface<IDWriteTextLayout>()->GetMaxWidth();
}

void TextLayout::MaxWidth::set(FLOAT value)
{
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->SetMaxWidth(value));
}

FLOAT TextLayout::MaxHeight::get()
{
    return GetInterface<IDWriteTextLayout>()->GetMaxHeight();
}

void TextLayout::MaxHeight::set(FLOAT value)
{
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->SetMaxHeight(value));
}


void TextLayout::SetFontFamilyName(
    System::String^  fontFamilyName,
    TextRange textRange
    )
{
    pin_ptr<const wchar_t> name = PtrToStringChars(fontFamilyName);
    
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);
    
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->SetFontFamilyName(name, textRangeCopy));
}

void TextLayout::SetFontWeight(
    DWrite::FontWeight fontWeight,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetFontWeight(
            static_cast<DWRITE_FONT_WEIGHT>(fontWeight), textRangeCopy));
}

void TextLayout::SetFontStyle(
    DWrite::FontStyle fontStyle,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetFontStyle(
            static_cast<DWRITE_FONT_STYLE>(fontStyle), textRangeCopy));
}

void TextLayout::SetFontStretch(
    DWrite::FontStretch fontStretch,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetFontStretch(
        static_cast<DWRITE_FONT_STRETCH>(fontStretch), textRangeCopy));
}

void TextLayout::SetFontSize(
    FLOAT fontSize,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetFontSize(
        fontSize, textRangeCopy));
}

void TextLayout::SetUnderline(
    Boolean hasUnderline,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetUnderline(
        hasUnderline ? TRUE : FALSE, textRangeCopy));
}

void TextLayout::SetStrikethrough(
    Boolean hasStrikethrough,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetStrikethrough(
        hasStrikethrough ? TRUE : FALSE, textRangeCopy));
}


void TextLayout::SetInlineObject(
    ICustomInlineObject^ inlineObject,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CustomInlineObject *pInlineObject = NULL;

     try
     {
         pInlineObject = new CustomInlineObject(
            inlineObject
            );

        CommonUtils::VerifyResult(
            GetInterface<IDWriteTextLayout>()->SetInlineObject(pInlineObject, textRangeCopy
            ));
     }
     finally
     {
         if (pInlineObject)
             pInlineObject->Release();
     }
}

void TextLayout::SetInlineObject(
    InlineObject^ inlineObject,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetInlineObject(inlineObject->GetInterface<::IDWriteInlineObject>(), textRangeCopy
        ));
}

void TextLayout::SetTypography(
    Typography^ typography,
    TextRange textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->SetTypography(typography->GetInterface<::IDWriteTypography>(), textRangeCopy
        ));
}


void TextLayout::SetCultureInfo(        
    System::Globalization::CultureInfo^ cultureInfo,
    TextRange textRange
    )
{
    pin_ptr<const wchar_t> name = PtrToStringChars(cultureInfo->Name);
    
    DWRITE_TEXT_RANGE textRangeCopy;
    textRange.CopyTo(&textRangeCopy);
    
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->SetLocaleName(name, textRangeCopy));
}

System::String^ TextLayout::GetFontFamilyName(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    // First, get the length
    UINT32 len;
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontFamilyNameLength(currentPosition, &len));

    wchar_t* name = new wchar_t[len + 1];

    try
    {        
        DWRITE_TEXT_RANGE textRangeCopy;
        CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetFontFamilyName(currentPosition, name, len, &textRangeCopy));
        textRange.CopyFrom(textRangeCopy);
        return gcnew String(name);
    }
    finally
    {
        delete [] name;
    }
}

System::String^ TextLayout::GetFontFamilyName(
    UINT32 currentPosition
    )
{
    // First, get the length
    UINT32 len;
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontFamilyNameLength(currentPosition, &len));

    wchar_t* name = new wchar_t[len + 1];

    try
    {        
        CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetFontFamilyName(currentPosition, name, len));
        return gcnew String(name);
    }
    finally
    {
        delete [] name;
    }}

FontWeight TextLayout::GetFontWeight(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    DWRITE_FONT_WEIGHT returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontWeight(
        currentPosition, &returnValue, &textRangeCopy
        ));

    textRange.CopyFrom(textRangeCopy);
    return static_cast<DWrite::FontWeight>(returnValue);
}

DWrite::FontWeight TextLayout::GetFontWeight(
    UINT32 currentPosition
    )
{
    DWRITE_FONT_WEIGHT returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontWeight(
        currentPosition, &returnValue
        ));

    return static_cast<DWrite::FontWeight>(returnValue);
}

DWrite::FontStyle TextLayout::GetFontStyle(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    DWRITE_FONT_STYLE returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontStyle(
        currentPosition, &returnValue, &textRangeCopy
        ));

    textRange.CopyFrom(textRangeCopy);
    return static_cast<DWrite::FontStyle>(returnValue);
}

DWrite::FontStyle TextLayout::GetFontStyle(
    UINT32 currentPosition
    )
{
    DWRITE_FONT_STYLE returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontStyle(
        currentPosition, &returnValue
        ));

    return static_cast<DWrite::FontStyle>(returnValue);
}

FontStretch TextLayout::GetFontStretch(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    DWRITE_FONT_STRETCH returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontStretch(
        currentPosition, &returnValue, &textRangeCopy
        ));

    textRange.CopyFrom(textRangeCopy);
    return static_cast<DWrite::FontStretch>(returnValue);
}

FontStretch TextLayout::GetFontStretch(
    UINT32 currentPosition
    )
{
    DWRITE_FONT_STRETCH returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontStretch(
        currentPosition, &returnValue
        ));

    return static_cast<DWrite::FontStretch>(returnValue);
}

FLOAT TextLayout::GetFontSize(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    FLOAT returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontSize(
        currentPosition, &returnValue, &textRangeCopy
        ));

    textRange.CopyFrom(textRangeCopy);
    return returnValue;
}

FLOAT TextLayout::GetFontSize(
    UINT32 currentPosition
    )
{
    FLOAT returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetFontSize(
        currentPosition, &returnValue
        ));

    return returnValue;
}

Boolean TextLayout::GetUnderline(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    BOOL returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetUnderline(
        currentPosition, &returnValue, &textRangeCopy
        ));

    textRange.CopyFrom(textRangeCopy);
    return returnValue != 0;
}


Boolean TextLayout::GetUnderline(
    UINT32 currentPosition
    )
{
    BOOL returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetUnderline(
        currentPosition, &returnValue
        ));

    return returnValue != 0;
}

Boolean TextLayout::GetStrikethrough(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    BOOL returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetStrikethrough(
        currentPosition, &returnValue, &textRangeCopy
        ));

    textRange.CopyFrom(textRangeCopy);
    return returnValue != 0;
}

Boolean TextLayout::GetStrikethrough(
    UINT32 currentPosition
    )
{
    BOOL returnValue;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetStrikethrough(
        currentPosition, &returnValue
        ));

    return returnValue != 0;
}

System::Globalization::CultureInfo^ TextLayout::GetCultureInfo(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    // First, get the length
    UINT32 len;
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetLocaleNameLength(currentPosition, &len));

    wchar_t* name = new wchar_t[len + 1];

    try
    {        
        DWRITE_TEXT_RANGE textRangeCopy;
        CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetLocaleName(currentPosition, name, len, &textRangeCopy));
        textRange.CopyFrom(textRangeCopy);
        return gcnew System::Globalization::CultureInfo(gcnew String(name));
    }
    finally
    {
        delete [] name;
    }
}

System::Globalization::CultureInfo^ TextLayout::GetCultureInfo(
    UINT32 currentPosition
    )
{
    // First, get the length
    UINT32 len;
    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->GetLocaleNameLength(currentPosition, &len));

    wchar_t* name = new wchar_t[len + 1];

    try
    {        
        CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetLocaleName(currentPosition, name, len));
        return gcnew System::Globalization::CultureInfo(gcnew String(name));
    }
    finally
    {
        delete [] name;
    }
}


Typography^ TextLayout::GetTypography(
    UINT32 currentPosition,
    [System::Runtime::InteropServices::Out] TextRange % textRange
    )
{
    DWRITE_TEXT_RANGE textRangeCopy;
    IDWriteTypography * typography = NULL;

    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetTypography(currentPosition, &typography, &textRangeCopy));
    textRange.CopyFrom(textRangeCopy);

    return typography ? gcnew Typography(typography) : nullptr;
}

Typography^ TextLayout::GetTypography(
    UINT32 currentPosition
    )
{
    IDWriteTypography * typography = NULL;
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetTypography(currentPosition, &typography));

    return typography ? gcnew Typography(typography) : nullptr;
}



array<DWrite::LineMetrics>^ TextLayout::GetLineMetrics()
{
    UINT32 actualLineCount;

    HRESULT hr = 
        GetInterface<IDWriteTextLayout>()->GetLineMetrics(NULL, 0, &actualLineCount);

    if (hr != E_INSUFFICIENT_BUFFER)
        CommonUtils::VerifyResult(hr);

    if (actualLineCount > 0)
    {
        array<DWrite::LineMetrics>^ metricsArray = gcnew array<DWrite::LineMetrics>(actualLineCount);
        pin_ptr<DWrite::LineMetrics> metricsPtr = &metricsArray[0];

        CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetLineMetrics(
            (DWRITE_LINE_METRICS*)metricsPtr, actualLineCount, &actualLineCount));

        return metricsArray;
    }

    // If no line metrics return nullptr
    return nullptr;
}


TextMetrics TextLayout::Metrics::get()
{
    DWRITE_TEXT_METRICS returnCopy;
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetMetrics(&returnCopy));

    TextMetrics returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

DWrite::OverhangMetrics TextLayout::OverhangMetrics::get()
{
    DWRITE_OVERHANG_METRICS returnCopy;
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->GetOverhangMetrics(&returnCopy));

    DWrite::OverhangMetrics returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}


array<DWrite::ClusterMetrics>^ TextLayout::GetClusterMetrics()
{
    UINT32 actualClusterCount;

    HRESULT hr = GetInterface<IDWriteTextLayout>()->GetClusterMetrics(NULL, 0, &actualClusterCount);

    if (hr != E_INSUFFICIENT_BUFFER)
        CommonUtils::VerifyResult(hr);

    if (actualClusterCount > 0)
    {

        vector<DWRITE_CLUSTER_METRICS> metricsVector(actualClusterCount);

        CommonUtils::VerifyResult(
            GetInterface<IDWriteTextLayout>()->GetClusterMetrics(
            &metricsVector[0], actualClusterCount, &actualClusterCount));

        array<DWrite::ClusterMetrics>^ metricsArray = gcnew array<DWrite::ClusterMetrics>(actualClusterCount);

        for (UINT i =0; i < actualClusterCount; i++)
        {
            metricsArray[i] =  DWrite::ClusterMetrics(
                metricsVector[i].width,
                metricsVector[i].length,
                metricsVector[i].canWrapLineAfter != 0,
                metricsVector[i].isWhitespace != 0,
                metricsVector[i].isNewline != 0,
                metricsVector[i].isSoftHyphen != 0,
                metricsVector[i].isRightToLeft != 0);
        }

        return metricsArray;
    }

    return nullptr;
}

FLOAT TextLayout::DetermineMinWidth(
    )
{
    FLOAT returnValue;
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->DetermineMinWidth(&returnValue));
    return returnValue;
}

HitTestMetrics TextLayout::HitTestPoint(
    FLOAT pointX,
    FLOAT pointY,
    [System::Runtime::InteropServices::Out] Boolean % isTrailingHit,
    [System::Runtime::InteropServices::Out] Boolean % isInside
    )
{
    DWRITE_HIT_TEST_METRICS metrics;
    BOOL isTrailingHitCopy, isInsideCopy;

    CommonUtils::VerifyResult(
        GetInterface<IDWriteTextLayout>()->HitTestPoint(pointX, pointY, &isTrailingHitCopy, &isInsideCopy, &metrics));

    isTrailingHit = isTrailingHitCopy != 0;
    isInside = isInsideCopy != 0;

    HitTestMetrics returnValue;
    returnValue.CopyFrom(metrics);

    return returnValue;
}

HitTestMetrics TextLayout::HitTestTextPosition(
    UINT32 textPosition,
    Boolean isTrailingHit,
    [System::Runtime::InteropServices::Out] FLOAT % pointX,
    [System::Runtime::InteropServices::Out] FLOAT % pointY        
    )
{
    DWRITE_HIT_TEST_METRICS metrics;
    FLOAT pointXCopy, pointYCopy;
    CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->HitTestTextPosition(
        textPosition, isTrailingHit ? TRUE : FALSE, &pointXCopy, &pointYCopy, &metrics));

    pointX = pointXCopy;
    pointY = pointYCopy;

    HitTestMetrics returnValue;
    returnValue.CopyFrom(metrics);

    return returnValue;
}

array<HitTestMetrics>^ TextLayout::HitTestTextRange(
    UINT32 textPosition,
    UINT32 textLength,
    FLOAT originX,
    FLOAT originY
    )
{

    UINT32 actualCount;

    HRESULT hr = GetInterface<IDWriteTextLayout>()->HitTestTextRange(
        textPosition, textLength, originX, originY, 
        NULL, 0, &actualCount);

    if (hr != E_INSUFFICIENT_BUFFER)
        CommonUtils::VerifyResult(hr);

    if (actualCount > 0)
    {
        array<HitTestMetrics>^ metricsArray = gcnew array<HitTestMetrics>(actualCount);
        pin_ptr<HitTestMetrics> metricsPtr = &metricsArray[0];

        CommonUtils::VerifyResult(GetInterface<IDWriteTextLayout>()->HitTestTextRange(
            textPosition, textLength, originX, originY, 
            (DWRITE_HIT_TEST_METRICS*)metricsPtr,
            actualCount, &actualCount));

        return metricsArray;
    }

    return nullptr;
}
