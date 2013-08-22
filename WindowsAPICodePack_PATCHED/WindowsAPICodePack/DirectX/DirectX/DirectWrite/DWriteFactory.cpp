// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include "CommonUtils.h"
#include "LibraryLoader.h"
#include "DWriteFactory.h"
#include "DWriteTextFormat.h"
#include "DWriteTextLayout.h"
#include "ICustomInlineObject.h"
#include "DWriteInlineObject.h"
#include "DWriteRenderingParams.h"
#include "DWriteFontFamily.h"
#include "DWriteTypography.h"
#include "DWriteFontFamilyCollection.h"
#include "DWriteFontFace.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

typedef HRESULT (*CreateDWriteFactoryFuncPtr)(DWRITE_FACTORY_TYPE factoryType, REFIID riid, IUnknown **factory);

DWriteFactory^ DWriteFactory::CreateFactory()
{
    return CreateFactory(DWriteFactoryType::Shared);
}

DWriteFactory^ DWriteFactory::CreateFactory(DWriteFactoryType factoryType)
{
    CreateDWriteFactoryFuncPtr createFuncPtr = 
        (CreateDWriteFactoryFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
        DWriteLibrary, "DWriteCreateFactory");

    IDWriteFactory * pNativeIDWriteFactory = NULL;

    CommonUtils::VerifyResult(
        (*createFuncPtr)(
        static_cast<DWRITE_FACTORY_TYPE>(factoryType), __uuidof(IDWriteFactory), (IUnknown**)(&pNativeIDWriteFactory)));

    return gcnew DWriteFactory(pNativeIDWriteFactory);
}


TextFormat^ DWriteFactory::CreateTextFormat(
    String^ fontFamilyName,
    Single fontSize,
    FontWeight fontWeight,
    FontStyle fontStyle,
    FontStretch fontStretch,
    CultureInfo^ cultureInfo)
{
    IDWriteTextFormat * textFormat = NULL;

    pin_ptr<const wchar_t> ciNamePtr = cultureInfo == nullptr ?  nullptr : PtrToStringChars(cultureInfo->Name);
    pin_ptr<const wchar_t> familyNamePtr = fontFamilyName == nullptr ?  nullptr : PtrToStringChars(fontFamilyName);

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateTextFormat(        
        familyNamePtr,
        NULL,
        static_cast<DWRITE_FONT_WEIGHT>(fontWeight),
        static_cast<DWRITE_FONT_STYLE>(fontStyle),
        static_cast<DWRITE_FONT_STRETCH>(fontStretch),
        fontSize,
        cultureInfo == nullptr ? L"" : ciNamePtr,            
        &textFormat));

    return textFormat ? gcnew TextFormat(textFormat) : nullptr;
}

TextFormat^ DWriteFactory::CreateTextFormat(
    String^ fontFamilyName,
    Single fontSize,
    FontWeight fontWeight,
    FontStyle fontStyle,
    FontStretch fontStretch)
{
    return CreateTextFormat(fontFamilyName, fontSize, fontWeight, fontStyle, fontStretch, nullptr);
}

TextFormat^ DWriteFactory::CreateTextFormat(
    String^ fontFamilyName,
    Single fontSize)
{
    return CreateTextFormat(fontFamilyName, fontSize, FontWeight::Normal, FontStyle::Normal, FontStretch::Normal, nullptr);
}



RenderingParams^ DWriteFactory::CreateRenderingParams()
{
    IDWriteRenderingParams * renderingParams = NULL;

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateRenderingParams(
        &renderingParams));

    return renderingParams ? gcnew RenderingParams(renderingParams) : nullptr;
}

RenderingParams^ DWriteFactory::CreateMonitorRenderingParams(
    IntPtr monitorHandle
    )
{
    IDWriteRenderingParams * renderingParams = NULL;

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateMonitorRenderingParams(
        static_cast<HMONITOR>(monitorHandle.ToPointer()),
        &renderingParams));

    return renderingParams ? gcnew RenderingParams(renderingParams) : nullptr;
}

RenderingParams^ DWriteFactory::CreateCustomRenderingParams(
    FLOAT gamma,
    FLOAT enhancedContrast,
    FLOAT clearTypeLevel,
    PixelGeometry pixelGeometry,
    RenderingMode renderingMode)
{
    IDWriteRenderingParams * renderingParams = NULL;

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateCustomRenderingParams(
        gamma,
        enhancedContrast,
        clearTypeLevel,
        static_cast<DWRITE_PIXEL_GEOMETRY>(pixelGeometry),
        static_cast<DWRITE_RENDERING_MODE>(renderingMode),
        &renderingParams));

    return renderingParams ? gcnew RenderingParams(renderingParams) : nullptr;
}

TextLayout^ DWriteFactory::CreateTextLayout(
    String^ text,
    TextFormat^ textFormat,
    FLOAT maxWidth,
    FLOAT maxHeight
    )
{
    IDWriteTextLayout* textLayout = NULL;

    pin_ptr<const wchar_t> textPtr = text == nullptr ?  nullptr : PtrToStringChars(text);

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateTextLayout(
        textPtr, text->Length, textFormat->GetInterface<IDWriteTextFormat>(),
        maxWidth, maxHeight, &textLayout));

    return textLayout ? gcnew TextLayout(textLayout, text) : nullptr;
}

TextLayout^ DWriteFactory::CreateGdiCompatibleTextLayout(
    String^ text,
    TextFormat^ textFormat,
    FLOAT layoutWidth,
    FLOAT layoutHeight,
    FLOAT pixelsPerDip,
    Boolean useGdiNatural,
    Microsoft::WindowsAPICodePack::DirectX::Direct2D1::Matrix3x2F transform        
    )
{
    IDWriteTextLayout* textLayout = NULL;

    pin_ptr<const wchar_t> textPtr = text == nullptr ?  nullptr : PtrToStringChars(text);

    DWRITE_MATRIX matrixCopy;
    transform.CopyTo((D2D1_MATRIX_3X2_F*)&matrixCopy);

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateGdiCompatibleTextLayout(
        textPtr, text->Length,textFormat->GetInterface<IDWriteTextFormat>(),
        layoutWidth, layoutHeight, pixelsPerDip, &matrixCopy, useGdiNatural ? TRUE : FALSE, &textLayout));

    return textLayout ? gcnew TextLayout(textLayout, text) : nullptr;
}

TextLayout^ DWriteFactory::CreateGdiCompatibleTextLayout(
    String^ text,
    TextFormat^ textFormat,
    FLOAT layoutWidth,
    FLOAT layoutHeight,
    FLOAT pixelsPerDip,
    Boolean useGdiNatural
    )
{
    IDWriteTextLayout* textLayout = NULL;
    pin_ptr<const wchar_t> textPtr = text == nullptr ?  nullptr : PtrToStringChars(text);

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateGdiCompatibleTextLayout(
        textPtr, text->Length,textFormat->GetInterface<IDWriteTextFormat>(),
        layoutWidth, layoutHeight, pixelsPerDip, NULL, useGdiNatural, &textLayout));

    return textLayout ? gcnew TextLayout(textLayout, text) : nullptr;
}

InlineObject^ DWriteFactory::CreateEllipsisTrimmingSign(
    TextFormat^ textFormat
    )
{
    ::IDWriteInlineObject* inlineObject = NULL;

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateEllipsisTrimmingSign(
        textFormat->GetInterface<IDWriteTextFormat>(),
        &inlineObject));

    return inlineObject ? gcnew InlineObject(inlineObject) : nullptr;
}



FontFamilyCollection^ DWriteFactory::SystemFontFamilyCollection::get()
{
    // First check the font collection for updates
    IDWriteFontCollection* newFontCollection = NULL;
    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->GetSystemFontCollection(&newFontCollection));

    // Check for updates
    if (m_sysFontFamilies == nullptr || newFontCollection != m_fontCollection)
    {
        m_fontCollection = newFontCollection;
        m_sysFontFamilies = gcnew FontFamilyCollection(m_fontCollection);
    }

    return m_sysFontFamilies;
}

Typography^ DWriteFactory::CreateTypography()
{
    IDWriteTypography * typography = NULL;

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateTypography(
        &typography
        ));

    return typography ? gcnew Typography(typography) : nullptr;
}


FontFace^ DWriteFactory::CreateFontFaceFromFontFile(
    System::String^ fontFileName, 
    FontFaceType fontFaceType, 
    UINT32 faceIndex,
    FontSimulations fontFaceSimulationFlags)
{ 
    if (!File::Exists(fontFileName))
    {
        throw gcnew FileNotFoundException("Could not find font file \"" + fontFileName + "\"");
    }

    IDWriteFontFace* pFontFace = NULL;
    IDWriteFontFile* pFontFiles = NULL;

    pin_ptr<const wchar_t> fontFolderPath = PtrToStringChars(Path::GetFullPath(fontFileName));

    CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateFontFileReference(
        fontFolderPath,
        NULL,
        &pFontFiles));

    IDWriteFontFile* fontFileArray[] = {pFontFiles};

    try
    {
        CommonUtils::VerifyResult(GetInterface<IDWriteFactory>()->CreateFontFace(
            static_cast<DWRITE_FONT_FACE_TYPE>(fontFaceType),
            1, // file count, this method supports a single file
            fontFileArray,
            faceIndex,
            static_cast<DWRITE_FONT_SIMULATIONS>(fontFaceSimulationFlags),
            &pFontFace
            ));
    }
    finally
    {
        if (pFontFiles)
        {
            pFontFiles->Release();
        }
    }

    return pFontFace ? gcnew FontFace(pFontFace) : nullptr;
}

FontFace^ DWriteFactory::CreateFontFaceFromFontFile(System::String^ fontFileName)
{
    return CreateFontFaceFromFontFile(fontFileName, FontFaceType::TrueType, 0, FontSimulations::None);
}

