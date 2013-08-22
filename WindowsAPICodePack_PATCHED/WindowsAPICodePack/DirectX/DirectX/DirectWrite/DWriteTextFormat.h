//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectUnknown.h"
#include "DWriteEnums.h"
#include "DWriteStructs.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DirectWrite {


    interface class ICustomInlineObject;
    ref class InlineObject;

    /// <summary>
    /// The format of text used for text layout purpose.
    /// <para>(Also see DirectX SDK: IDWriteTextFormat)</para>
    /// </summary>
    public ref class TextFormat : public DirectUnknown
    {
    public: 

    /// <summary>
    /// Get or Set alignment option of text relative to layout box's leading and trailing edge.
    /// </summary>
    property DWrite::TextAlignment TextAlignment
    {
        DWrite::TextAlignment get();
        void set (DWrite::TextAlignment);
    }

    /// <summary>
    /// Get or Set alignment option of paragraph relative to layout box's top and bottom edge.
    /// </summary>
    property DWrite::ParagraphAlignment ParagraphAlignment {
        DWrite::ParagraphAlignment get();
        void set (DWrite::ParagraphAlignment);
    }

    /// <summary>
    /// Get or Set word wrapping option.
    /// </summary>
    property DWrite::WordWrapping WordWrapping {
        DWrite::WordWrapping get();
        void set (DWrite::WordWrapping);
    }

    /// <summary>
    /// Get or Set paragraph reading direction.
    /// </summary>
    property DWrite::ReadingDirection ReadingDirection {
        DWrite::ReadingDirection get();
        void set (DWrite::ReadingDirection);
    }

    /// <summary>
    /// Get or Set paragraph flow direction.
    /// </summary>
    property DWrite::FlowDirection FlowDirection {
        DWrite::FlowDirection get();
        void set (DWrite::FlowDirection);
    }

    /// <summary>
    /// Set incremental tab stop position.
    /// </summary>
    property Single IncrementalTabStop {
        Single get();
        void set (Single);
    }

    /// <summary>
    /// Get or Set line spacing.
    /// </summary>
    property DWrite::LineSpacing LineSpacing {
        DWrite::LineSpacing get();
        void set (DWrite::LineSpacing);
    }

    /// <summary>
    /// Get or Set trimming options.
    /// </summary>
    property DWrite::Trimming Trimming {
        DWrite::Trimming get();
        void set (DWrite::Trimming);
    }

    /// <summary>
    /// Set trimming options for any trailing text exceeding the layout width
    /// or for any far text exceeding the layout height.
    /// </summary>
    /// <param name="trimmingOptions">Text trimming options.</param>
    /// <param name="trimmingSign">Application-defined omission sign.</param>
    /// <remarks>
    /// Any inline object can be used for the trimming sign, but DWriteFactory.CreateEllipsisTrimmingSign
    /// provides a typical ellipsis symbol. Trimming is also useful vertically for hiding
    /// partial lines.
    /// </remarks>
    void SetTrimming(
        DWrite::Trimming trimmingOptions,
        ICustomInlineObject^ trimmingSign
        );

    /// <summary>
    /// Set trimming options for any trailing text exceeding the layout width
    /// or for any far text exceeding the layout height.
    /// </summary>
    /// <param name="trimmingOptions">Text trimming options.</param>
    /// <param name="trimmingSign">Application-defined omission sign.</param>
    /// <remarks>
    /// Any inline object can be used for the trimming sign, but DWriteFactory.CreateEllipsisTrimmingSign
    /// provides a typical ellipsis symbol. Trimming is also useful vertically for hiding
    /// partial lines.
    /// </remarks>
    void SetTrimming(
        DWrite::Trimming trimmingOptions,
        InlineObject^ trimmingSign
        );

    /// <summary>
    /// Get trimming options for text overflowing the layout width.
    /// </summary>
    /// <param name="trimmingSign">Trimming omission sign.</param>
    /// <returns>
    /// Text trimming options.
    /// </returns>
    DWrite::Trimming GetTrimming(
        [System::Runtime::InteropServices::Out] InlineObject^ % trimmingSign
        );

    property String^ FontFamilyName
    {
        String^ get();
    }

    /// <summary>
    /// Get the font weight.
    /// </summary>
    property DWrite::FontWeight FontWeight
    {
        DWrite::FontWeight get();
    }

    /// <summary>
    /// Get the font style.
    /// </summary>
    property DWrite::FontStyle FontStyle
    {
        DWrite::FontStyle get();
    }

    /// <summary>
    /// Get the font stretch.
    /// </summary>
    property DWrite::FontStretch FontStretch
    {
        DWrite::FontStretch get();
    }

    /// <summary>
    /// Get the font em height.
    /// </summary>
    property Single FontSize
    {
        Single get();
    }

    /// <summary>
    /// Get the CultureInfo for this object.
    /// </summary>
    property System::Globalization::CultureInfo^ CultureInfo
    {
        System::Globalization::CultureInfo^ get();
    }

    internal:
        TextFormat() 
        { }
    
        TextFormat(IDWriteTextFormat* pNativeIDWriteTextFormat) : DirectUnknown(pNativeIDWriteTextFormat)
        { }

    };
} } } }
