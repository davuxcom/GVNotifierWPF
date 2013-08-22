//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DWriteEnums.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace DWrite = Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DirectWrite { 

    /// <summary>
    /// Line spacing parameters.
    /// </summary>
    /// <remarks>
    /// For the default line spacing method, spacing depends solely on the content.
    /// For uniform line spacing, the given line height will override the content.
    /// </remarks>    
    public value struct LineSpacing
    {
    public:

        /// <summary>
        /// Constructor for LineSpacing
        /// </summary>
        /// <param name="lineSpacingMethod">Initializes the LineSpaceingMethod field.</param>
        /// <param name="height">Initializes the Height field.</param>
        /// <param name="baseline">Initializes the Baseline field.</param>
        LineSpacing(
            DWrite::LineSpacingMethod lineSpacingMethod,
            Single height,
            Single baseline
            ) : LineSpacingMethod(lineSpacingMethod), Height(height), Baseline(baseline)
        { }


        /// <summary>
        /// How line height is determined.
        /// </summary>
        DWrite::LineSpacingMethod LineSpacingMethod;

        /// <summary>
        /// The line height, or rather distance between one baseline to another.
        /// </summary>
        Single Height;

        /// <summary>
        /// Distance from top of line to baseline. A reasonable ratio to Height is 80%.
        /// </summary>
        Single Baseline;

    };
    /// <summary>
    /// Specifies a range of text positions where format is applied.
    /// </summary>
    public value struct TextRange
    {
    public:
        /// <summary>
        /// Constructor for TextRange
        /// </summary>
        TextRange (
            UINT32 startPosition,
            UINT32 length
            ) : StartPosition(startPosition), Length(length)
        { }

        /// <summary>
        /// The start text position of the range.
        /// </summary>
        UINT32 StartPosition;

        /// <summary>
        /// The number of text positions in the range.
        /// </summary>
        UINT32 Length;
    internal:
        void CopyFrom(
            const DWRITE_TEXT_RANGE & nativeStruct
            )
        {
            StartPosition = nativeStruct.startPosition;
            Length = nativeStruct.length;
        }

        void CopyTo(
            DWRITE_TEXT_RANGE *pNativeStruct
            )
        {
            pNativeStruct->startPosition = StartPosition;
            pNativeStruct->length = Length;
        }    
    };

    /// <summary>
    /// Geometry enclosing of text positions.
    /// </summary>
    public value struct HitTestMetrics
    {
    public:
        /// <summary>
        /// Constructor for HitTestMetrics
        /// </summary>
        HitTestMetrics(
            UINT32 textPosition,
            UINT32 length,
            FLOAT left,
            FLOAT top,
            FLOAT width,
            FLOAT height,
            UINT32 bidiLevel,
            Boolean isText,
            Boolean isTrimmed
            ) : 
        TextPosition(textPosition),
            Length(length),
            Left(left),
            Top(top),
            Width(width),
            Height(height),
            BidiLevel(bidiLevel),
            IsText(isText),
            IsTrimmed(isTrimmed)
        { }

        /// <summary>
        /// First text position within the geometry.
        /// </summary>
        UINT32 TextPosition;

        /// <summary>
        /// Number of text positions within the geometry.
        /// </summary>
        UINT32 Length;

        /// <summary>
        /// Left position of the top-left coordinate of the geometry.
        /// </summary>
        FLOAT Left;

        /// <summary>
        /// Top position of the top-left coordinate of the geometry.
        /// </summary>
        FLOAT Top;

        /// <summary>
        /// Geometry's width.
        /// </summary>
        FLOAT Width;

        /// <summary>
        /// Geometry's height.
        /// </summary>
        FLOAT Height;

        /// <summary>
        /// Bidi level of text positions enclosed within the geometry.
        /// </summary>
        UINT32 BidiLevel;

        /// <summary>
        /// Geometry encloses text?
        /// </summary>
        Boolean IsText;

        /// <summary>
        /// Range is trimmed.
        /// </summary>
        Boolean IsTrimmed;

    internal:
        void CopyFrom(
            const DWRITE_HIT_TEST_METRICS & nativeStruct
            )
        {
            TextPosition = nativeStruct.textPosition;
            Length = nativeStruct.length;
            Left = nativeStruct.left;
            Top = nativeStruct.top;
            Width = nativeStruct.width;
            Height = nativeStruct.height;
            BidiLevel = nativeStruct.bidiLevel;
            IsText = nativeStruct.isText != 0;
            IsTrimmed = nativeStruct.isTrimmed != 0;
        }

        void CopyTo(
            DWRITE_HIT_TEST_METRICS *pNativeStruct
            )
        {
            pNativeStruct->textPosition = TextPosition;
            pNativeStruct->length = Length;
            pNativeStruct->left = Left;
            pNativeStruct->top = Top;
            pNativeStruct->width = Width;
            pNativeStruct->height = Height;
            pNativeStruct->bidiLevel = BidiLevel;
            pNativeStruct->isText = IsText;
            pNativeStruct->isTrimmed = IsTrimmed;
        }
    };


    /// <summary>
    /// Contains information about a formatted line of text.
    /// </summary>
    public value struct LineMetrics
    {
    public:
        /// <summary>
        /// Constructor for LineMetrics
        /// </summary>
        LineMetrics(
            UINT32 length,
            UINT32 trailingWhitespaceLength,
            UINT32 newlineLength,
            FLOAT height,
            FLOAT baseline,
            Boolean isTrimmed
            ) : 
        Length(length),
            TrailingWhitespaceLength(trailingWhitespaceLength),
            NewlineLength(newlineLength),
            Height(height),
            Baseline(baseline),
            IsTrimmed(isTrimmed)
        { }
        /// <summary>
        /// The number of total text positions in the line.
        /// This includes any trailing whitespace and newline characters.
        /// </summary>
        UINT32 Length;

        /// <summary>
        /// The number of whitespace positions at the end of the line.  Newline
        /// sequences are considered whitespace.
        /// </summary>
        UINT32 TrailingWhitespaceLength;

        /// <summary>
        /// The number of characters in the newline sequence at the end of the line.
        /// If the count is zero, then the line was either wrapped or it is the
        /// end of the text.
        /// </summary>
        UINT32 NewlineLength;

        /// <summary>
        /// Height of the line as measured from top to bottom.
        /// </summary>
        FLOAT Height;

        /// <summary>
        /// Distance from the top of the line to its baseline.
        /// </summary>
        FLOAT Baseline;

        /// <summary>
        /// The line is trimmed.
        /// </summary>
        Boolean IsTrimmed;

    internal:
        void CopyFrom(
            const DWRITE_LINE_METRICS & nativeStruct
            )
        {
            Length = nativeStruct.length;
            TrailingWhitespaceLength = nativeStruct.trailingWhitespaceLength;
            NewlineLength = nativeStruct.newlineLength;
            Height = nativeStruct.height;
            Baseline = nativeStruct.baseline;
            IsTrimmed = nativeStruct.isTrimmed != 0;
        }

        void CopyTo(
            DWRITE_LINE_METRICS *pNativeStruct
            )
        {
            pNativeStruct->length = Length;

            pNativeStruct->trailingWhitespaceLength = TrailingWhitespaceLength;
            pNativeStruct->newlineLength = NewlineLength;
            pNativeStruct->height = Height;
            pNativeStruct->baseline = Baseline;
            pNativeStruct->isTrimmed = IsTrimmed;
        }
    };

    /// <summary>
    /// Overall metrics associated with text after layout.
    /// All coordinates are in device independent pixels (DIPs).
    /// </summary>
    public value struct TextMetrics
    {
    public:
        /// <summary>
        /// Constructor for TextMetrics
        /// </summary>
        TextMetrics(
            FLOAT left,
            FLOAT top,
            FLOAT width,
            FLOAT widthIncludingTrailingWhitespace,
            FLOAT height,
            FLOAT layoutWidth,
            FLOAT layoutHeight,
            UINT32 maxBidiReorderingDepth,
            UINT32 lineCount)
            : 
        Left(left),
            Top(top),
            Width(width),
            WidthIncludingTrailingWhitespace(widthIncludingTrailingWhitespace),
            Height(height),
            LayoutWidth(layoutWidth),
            LayoutHeight(layoutHeight),
            MaxBidiReorderingDepth(maxBidiReorderingDepth),
            LineCount(lineCount)
        { }

        /// <summary>
        /// Left-most point of formatted text relative to layout box
        /// (excluding any glyph overhang).
        /// </summary>
        FLOAT Left;

        /// <summary>
        /// Top-most point of formatted text relative to layout box
        /// (excluding any glyph overhang).
        /// </summary>
        FLOAT Top;

        /// <summary>
        /// The width of the formatted text ignoring trailing whitespace
        /// at the end of each line.
        /// </summary>
        FLOAT Width;

        /// <summary>
        /// The width of the formatted text taking into account the
        /// trailing whitespace at the end of each line.
        /// </summary>
        FLOAT WidthIncludingTrailingWhitespace;

        /// <summary>
        /// The height of the formatted text. The height of an empty string
        /// is determined by the size of the default font's line height.
        /// </summary>
        FLOAT Height;

        /// <summary>
        /// Initial width given to the layout. Depending on whether the text
        /// was wrapped or not, it can be either larger or smaller than the
        /// text content width.
        /// </summary>
        FLOAT LayoutWidth;

        /// <summary>
        /// Initial height given to the layout. Depending on the length of the
        /// text, it may be larger or smaller than the text content height.
        /// </summary>
        FLOAT LayoutHeight;

        /// <summary>
        /// The maximum reordering count of any line of text, used
        /// to calculate the most number of hit-testing boxes needed.
        /// If the layout has no bidirectional text or no text at all,
        /// the minimum level is 1.
        /// </summary>
        UINT32 MaxBidiReorderingDepth;

        /// <summary>
        /// Total number of lines.
        /// </summary>
        UINT32 LineCount;


    internal:
        void CopyFrom(
            const DWRITE_TEXT_METRICS & nativeStruct
            )
        {
            Left = nativeStruct.left;
            Top = nativeStruct.top;
            Width = nativeStruct.width;
            WidthIncludingTrailingWhitespace = nativeStruct.widthIncludingTrailingWhitespace;
            Height = nativeStruct.height;
            LayoutWidth = nativeStruct.layoutWidth;
            LayoutHeight = nativeStruct.layoutHeight;
            MaxBidiReorderingDepth = nativeStruct.maxBidiReorderingDepth;
            LineCount = nativeStruct.lineCount;
        }

        void CopyTo(
            DWRITE_TEXT_METRICS *pNativeStruct
            )
        {
            pNativeStruct->left = Left ;
            pNativeStruct->top = Top;
            pNativeStruct->width = Width;
            pNativeStruct->widthIncludingTrailingWhitespace = WidthIncludingTrailingWhitespace;
            pNativeStruct->height = Height;
            pNativeStruct->layoutWidth = LayoutWidth;
            pNativeStruct->layoutHeight = LayoutHeight;
            pNativeStruct->maxBidiReorderingDepth = MaxBidiReorderingDepth;
            pNativeStruct->lineCount = LineCount;
        }
    };

    /// <summary>
    /// Holds information about how much any visible pixels
    /// (in DIPs) overshoot each side of the layout or inline objects.
    /// </summary>
    /// <remarks>
    /// Positive overhangs indicate that the visible area extends outside the layout
    /// box or inline object, while negative values mean there is whitespace inside.
    /// The returned values are unaffected by rendering transforms or pixel snapping.
    /// Additionally, they may not exactly match final target's pixel bounds after
    /// applying grid fitting and hinting.
    /// </remarks>
    [StructLayout(LayoutKind::Sequential)]
    public value struct OverhangMetrics
    {
    public:
        /// <summary>
        /// Constructor for OverhangMetrics
        /// </summary>
        OverhangMetrics (
            FLOAT left,
            FLOAT top,
            FLOAT right,
            FLOAT bottom ) 
            :
        Left(left),
            Top(top),
            Right(right),
            Bottom(bottom)
        { }

        /// <summary>
        /// The distance from the left-most visible DIP to its left alignment edge.
        /// </summary>
        FLOAT Left;

        /// <summary>
        /// The distance from the top-most visible DIP to its top alignment edge.
        /// </summary>
        FLOAT Top;

        /// <summary>
        /// The distance from the right-most visible DIP to its right alignment edge.
        /// </summary>
        FLOAT Right;

        /// <summary>
        /// The distance from the bottom-most visible DIP to its bottom alignment edge.
        /// </summary>
        FLOAT Bottom;

    internal:
        void CopyFrom(
            const DWRITE_OVERHANG_METRICS & nativeStruct
            )
        {
            Left = nativeStruct.left;
            Top = nativeStruct.top;
            Right = nativeStruct.right;
            Bottom = nativeStruct.bottom;
        }

        void CopyTo(
            DWRITE_OVERHANG_METRICS *pNativeStruct
            )
        {
            pNativeStruct->left = Left ;
            pNativeStruct->top = Top;
            pNativeStruct->right = Right;
            pNativeStruct->bottom = Bottom;
        }
    };


    /// <summary>
    /// Contains information about a glyph cluster.
    /// </summary>
    public value struct ClusterMetrics
    {
    public:
        /// <summary>
        /// Constructor for ClusterMetrics
        /// </summary>
        ClusterMetrics (
            FLOAT width,
            UINT16 length,
            Boolean canWrapLineAfter,
            Boolean isWhitespace,
            Boolean isNewline,
            Boolean isSoftHyphen,
            Boolean isRightToLeft) 
            :
        Width(width),
            Length(length),
            CanWrapLineAfter(canWrapLineAfter),
            IsWhitespace(isWhitespace),
            IsNewline(isNewline),
            IsSoftHyphen(isSoftHyphen),
            IsRightToLeft(isRightToLeft)
        { }

        /// <summary>
        /// The total advance width of all glyphs in the cluster.
        /// </summary>
        FLOAT Width;

        /// <summary>
        /// The number of text positions in the cluster.
        /// </summary>
        UINT16 Length;

        /// <summary>
        /// Indicate whether line can be broken right after the cluster.
        /// </summary>
        Boolean CanWrapLineAfter;

        /// <summary>
        /// Indicate whether the cluster corresponds to whitespace character.
        /// </summary>
        Boolean IsWhitespace;

        /// <summary>
        /// Indicate whether the cluster corresponds to a newline character.
        /// </summary>
        Boolean IsNewline;

        /// <summary>
        /// Indicate whether the cluster corresponds to soft hyphen character.
        /// </summary>
        Boolean IsSoftHyphen;

        /// <summary>
        /// Indicate whether the cluster is read from right to left.
        /// </summary>
        Boolean IsRightToLeft;

    internal:
        void CopyFrom(
            const DWRITE_CLUSTER_METRICS & nativeStruct
            )
        {
            Width = nativeStruct.width;
            Length = nativeStruct.length;
            CanWrapLineAfter = nativeStruct.canWrapLineAfter != 0;
            IsWhitespace = nativeStruct.isWhitespace != 0;
            IsNewline = nativeStruct.isNewline != 0;
            IsSoftHyphen = nativeStruct.isSoftHyphen != 0;
            IsRightToLeft = nativeStruct.isRightToLeft != 0;
        }

        void CopyTo(
            DWRITE_CLUSTER_METRICS *pNativeStruct
            )
        {
            pNativeStruct->width = Width;
            pNativeStruct->length = Length;
            pNativeStruct->canWrapLineAfter = CanWrapLineAfter ? 1 : 0;
            pNativeStruct->isWhitespace = IsWhitespace ? 1 : 0;
            pNativeStruct->isNewline = IsNewline ? 1 : 0;
            pNativeStruct->isSoftHyphen = IsSoftHyphen ? 1 : 0;
            pNativeStruct->isRightToLeft = IsRightToLeft ? 1 : 0;
        }

    };

    /// <summary>
    /// Specifies the trimming option for text overflowing the layout box.
    /// </summary>
    public value struct Trimming
    {
    public:
        /// <summary>
        /// Constructor for Trimming
        /// </summary>
        Trimming (
            TrimmingGranularity granularity,
            UINT32 delimiter,
            UINT32 delimiterCount) 
            :
        Granularity(granularity),
            Delimiter(delimiter),
            DelimiterCount(delimiterCount)
        { }

        /// <summary>
        /// Text granularity of which trimming applies.
        /// </summary>
        TrimmingGranularity Granularity;

        /// <summary>
        /// Character code used as the delimiter signaling the beginning of the portion of text to be preserved,
        /// most useful for path ellipsis, where the delimeter would be a slash.
        /// </summary>
        UINT32 Delimiter;

        /// <summary>
        /// How many occurences of the delimiter to step back.
        /// </summary>
        UINT32 DelimiterCount;

    internal:
        void CopyFrom(
            const DWRITE_TRIMMING & nativeStruct
            )
        {
            Granularity = static_cast<TrimmingGranularity>(nativeStruct.granularity);
            Delimiter = nativeStruct.delimiter;
            DelimiterCount = nativeStruct.delimiterCount;
        }

        void CopyTo(
            DWRITE_TRIMMING *pNativeStruct
            )
        {
            pNativeStruct->granularity = static_cast<DWRITE_TRIMMING_GRANULARITY>(Granularity);
            pNativeStruct->delimiter = Delimiter;
            pNativeStruct->delimiterCount = DelimiterCount;
        }
    };


    /// <summary>
    /// Specifies the metrics of a font face that are applicable to all glyphs within the font face.
    /// </summary>
    public value struct FontMetrics
    {
    public:
        /// <summary>
        /// Constructor for FontMetrics
        /// </summary>
        FontMetrics (
            UINT16 designUnitsPerEm,
            UINT16 ascent,
            UINT16 descent,
            INT16 lineGap,
            UINT16 capHeight,
            UINT16 xHeight,
            INT16 underlinePosition,
            UINT16 underlineThickness,
            INT16 strikethroughPosition,
            UINT16 strikethroughThickness
            )
            :
        DesignUnitsPerEm(designUnitsPerEm),
            Ascent(ascent),
            Descent(descent),
            LineGap(lineGap),
            CapHeight(capHeight),
            XHeight(xHeight),
            UnderlinePosition(underlinePosition),
            UnderlineThickness(underlineThickness),
            StrikethroughPosition(strikethroughPosition),
            StrikethroughThickness(strikethroughThickness)
        { }
    internal:
        /// <summary>
        /// Internal Constructor for FontMetrics
        /// </summary>
        FontMetrics (const DWRITE_FONT_METRICS & native)
            :
        DesignUnitsPerEm(native.designUnitsPerEm),
            Ascent(native.ascent),
            Descent(native.descent),
            LineGap(native.lineGap),
            CapHeight(native.capHeight),
            XHeight(native.xHeight),
            UnderlinePosition(native.underlinePosition),
            UnderlineThickness(native.underlineThickness),
            StrikethroughPosition(native.strikethroughPosition),
            StrikethroughThickness(native.strikethroughThickness)
        { }
    public:
        /// <summary>
        /// The number of font design units per em unit.
        /// Font files use their own coordinate system of font design units.
        /// A font design unit is the smallest measurable unit in the em square,
        /// an imaginary square that is used to size and align glyphs.
        /// The concept of em square is used as a reference scale factor when defining font size and device transformation semantics.
        /// The size of one em square is also commonly used to compute the paragraph identation value.
        /// </summary>
        UINT16 DesignUnitsPerEm;

        /// <summary>
        /// Ascent value of the font face in font design units.
        /// Ascent is the distance from the top of font character alignment box to English baseline.
        /// </summary>
        UINT16 Ascent;

        /// <summary>
        /// Descent value of the font face in font design units.
        /// Descent is the distance from the bottom of font character alignment box to English baseline.
        /// </summary>
        UINT16 Descent;

        /// <summary>
        /// Line gap in font design units.
        /// Recommended additional white space to add between lines to improve legibility. The recommended line spacing 
        /// (baseline-to-baseline distance) is thus the sum of ascent, descent, and lineGap. The line gap is usually 
        /// positive or zero but can be negative, in which case the recommended line spacing is less than the height
        /// of the character alignment box.
        /// </summary>
        INT16 LineGap;

        /// <summary>
        /// Cap height value of the font face in font design units.
        /// Cap height is the distance from English baseline to the top of a typical English capital.
        /// Capital "H" is often used as a reference character for the purpose of calculating the cap height value.
        /// </summary>
        UINT16 CapHeight;

        /// <summary>
        /// x-height value of the font face in font design units.
        /// x-height is the distance from English baseline to the top of lowercase letter "x", or a similar lowercase character.
        /// </summary>
        UINT16 XHeight;

        /// <summary>
        /// The underline position value of the font face in font design units.
        /// Underline position is the position of underline relative to the English baseline.
        /// The value is usually made negative in order to place the underline below the baseline.
        /// </summary>
        INT16 UnderlinePosition;

        /// <summary>
        /// The suggested underline thickness value of the font face in font design units.
        /// </summary>
        UINT16 UnderlineThickness;

        /// <summary>
        /// The strikethrough position value of the font face in font design units.
        /// Strikethrough position is the position of strikethrough relative to the English baseline.
        /// The value is usually made positive in order to place the strikethrough above the baseline.
        /// </summary>
        INT16 StrikethroughPosition;

        /// <summary>
        /// The suggested strikethrough thickness value of the font face in font design units.
        /// </summary>
        UINT16 StrikethroughThickness;

    internal:
        void CopyFrom(const DWRITE_FONT_METRICS & native)
        {
            DesignUnitsPerEm = native.designUnitsPerEm;
            Ascent = native.ascent;
            Descent = native.descent;
            LineGap = native.lineGap;
            CapHeight = native.capHeight;
            XHeight = native.xHeight;
            UnderlinePosition = native.underlinePosition;
            UnderlineThickness = native.underlineThickness;
            StrikethroughPosition = native.strikethroughPosition;
            StrikethroughThickness = native.strikethroughThickness;
        }

        void CopyTo(DWRITE_FONT_METRICS *pNativeStruct)
        {
            pNativeStruct->designUnitsPerEm = DesignUnitsPerEm;
            pNativeStruct->ascent = Ascent;
            pNativeStruct->descent = Descent;
            pNativeStruct->lineGap = LineGap;
            pNativeStruct->capHeight = CapHeight;
            pNativeStruct->xHeight = XHeight;
            pNativeStruct->underlinePosition = UnderlinePosition;
            pNativeStruct->underlineThickness = UnderlineThickness;
            pNativeStruct->strikethroughPosition = StrikethroughPosition;
            pNativeStruct->strikethroughThickness = StrikethroughThickness;
        }
    };


    /// <summary>
    /// Properties describing the geometric measurement of an
    /// application-defined inline object.
    /// </summary>
    public value struct InlineObjectMetrics
    {
        /// <summary>
        /// Constructor for InlineObjectMetrics
        /// </summary>
        InlineObjectMetrics (
            Single width,
            Single height,
            Single baseline,
            Boolean supportsSideways
            )
            :
        Width(width),
            Height(height),
            Baseline(baseline),
            SupportsSideways(supportsSideways)
        { }

        /// <summary>
        /// Width of the inline object.
        /// </summary>
        Single Width;

        /// <summary>
        /// Height of the inline object as measured from top to bottom.
        /// </summary>
        Single Height;

        /// <summary>
        /// Distance from the top of the object to the baseline where it is lined up with the adjacent text.
        /// If the baseline is at the bottom, baseline simply equals height.
        /// </summary>
        Single Baseline;

        /// <summary>
        /// Flag indicating whether the object is to be placed upright or alongside the text baseline
        /// for vertical text.
        /// </summary>
        Boolean SupportsSideways;

    internal:
        void CopyTo(DWRITE_INLINE_OBJECT_METRICS *pNativeStruct)
        {
            pNativeStruct->width = Width;
            pNativeStruct->height = Height;
            pNativeStruct->baseline = Baseline;
            pNativeStruct->supportsSideways = SupportsSideways ? 1 : 0;
        }
    };


    /// <summary>
    /// The FontFeature structure specifies properties used to identify and execute typographic feature in the font.
    /// </summary>
    /// <remarks>
    /// <para>A non-zero value generally enables the feature execution, while the zero value disables it. 
    /// A feature requiring a selector uses this value to indicate the selector index.</para>
    /// <para>The OpenType standard provides access to typographic features available in the font by means 
    /// of a feature tag with the associated parameters. The OpenType feature tag is a 4-byte identifier of 
    /// the registered name of a feature. For example, the ‘kern’ feature name tag is used to identify 
    /// the ‘Kerning’ feature in OpenType font. Similarly, the OpenType feature tag for ‘Standard Ligatures’ and 
    /// ‘Fractions’ is ‘liga’ and ‘frac’ respectively. Since a single run can be associated with more than one 
    /// typographic features, the Text String API accepts typographic settings for a run as a list of features 
    /// and are executed in the order they are specified.</para>
    /// <para>The value of the Tag member represents the OpenType name tag of the feature, while the param value 
    /// represents additional parameter for the execution of the feature referred by the tag member. 
    /// Both nameTag and param are stored as little endian, the same convention followed by GDI. 
    /// Most features treat the Param value as a binary value that indicates whether to turn the 
    /// execution of the feature on or off, with it being off by default in the majority of cases. 
    /// Some features, however, treat this value as an integral value representing the integer index to 
    /// the list of alternate results it may produce during the execution; for instance, the feature 
    /// ‘Stylistic Alternates’ or ‘salt’ uses the param value as an index to the list of alternate substituting 
    /// glyphs it could produce for a specified glyph. </para>
    /// </remarks>
    public value struct FontFeature
    {
    public:
        /// <summary>
        /// Constructor for FontFeature
        /// </summary>
        FontFeature (
            FontFeatureTag nameTag,
            UINT32 parameter
            )
            :
        NameTag(nameTag),
            Parameter(parameter)
        { }

        /// <summary>
        /// The feature OpenType name identifier.
        /// </summary>
        FontFeatureTag NameTag;

        /// <summary>
        /// Execution parameter of the feature.
        /// </summary>
        /// <remarks>
        /// The parameter should be non-zero to enable the feature.  Once enabled, a feature can't be disabled again within
        /// the same range.  Features requiring a selector use this value to indicate the selector index. 
        /// </remarks>
        UINT32 Parameter;

    internal:
        void CopyFrom(const DWRITE_FONT_FEATURE & native)
        {
            NameTag = static_cast<FontFeatureTag>(native.nameTag);
            Parameter = native.parameter;
        }

        void CopyTo(DWRITE_FONT_FEATURE *pNativeStruct)
        {
            pNativeStruct->nameTag = static_cast<DWRITE_FONT_FEATURE_TAG>(NameTag);
            pNativeStruct->parameter = Parameter;
        }
    };

    /// <summary>
    /// The GlyphMetrics structure specifies the metrics of an individual glyph.
    /// The units depend on how the metrics are obtained.
    /// </summary>
    public value struct GlyphMetrics
    {
        /// <summary>
        /// Specifies the X offset from the glyph origin to the left edge of the black box.
        /// The glyph origin is the current horizontal writing position.
        /// A negative value means the black box extends to the left of the origin (often true for lowercase italic 'f').
        /// </summary>
        INT32 LeftSideBearing;

        /// <summary>
        /// Specifies the X offset from the origin of the current glyph to the origin of the next glyph when writing horizontally.
        /// </summary>
        UINT32 AdvanceWidth;

        /// <summary>
        /// Specifies the X offset from the right edge of the black box to the origin of the next glyph when writing horizontally.
        /// The value is negative when the right edge of the black box overhangs the layout box.
        /// </summary>
        INT32 RightSideBearing;

        /// <summary>
        /// Specifies the vertical offset from the vertical origin to the top of the black box.
        /// Thus, a positive value adds whitespace whereas a negative value means the glyph overhangs the top of the layout box.
        /// </summary>
        INT32 TopSideBearing;

        /// <summary>
        /// Specifies the Y offset from the vertical origin of the current glyph to the vertical origin of the next glyph when writing vertically.
        /// (Note that the term "origin" by itself denotes the horizontal origin. The vertical origin is different.
        /// Its Y coordinate is specified by verticalOriginY value,
        /// and its X coordinate is half the advanceWidth to the right of the horizontal origin).
        /// </summary>
        UINT32 AdvanceHeight;

        /// <summary>
        /// Specifies the vertical distance from the black box's bottom edge to the advance height.
        /// Positive when the bottom edge of the black box is within the layout box.
        /// Negative when the bottom edge of black box overhangs the layout box.
        /// </summary>
        INT32 BottomSideBearing;

        /// <summary>
        /// Specifies the Y coordinate of a glyph's vertical origin, in the font's design coordinate system.
        /// The y coordinate of a glyph's vertical origin is the sum of the glyph's top side bearing
        /// and the top (i.e. yMax) of the glyph's bounding box.
        /// </summary>
        INT32 VerticalOriginY;
    };

    /// <summary>
    /// Optional adjustment to a glyph's position. An glyph offset changes the position of a glyph without affecting
    /// the pen position. Offsets are in logical, pre-transform units.
    /// </summary>
    public value struct GlyphOffset
    {
        /// <summary>
        /// Constructor for FontFeature
        /// </summary>
        GlyphOffset (
            FLOAT advanceOffset,
            FLOAT ascenderOffset
            )
            :
            AdvanceOffset(advanceOffset),
            AscenderOffset(ascenderOffset)
        { }

        /// <summary>
        /// Offset in the advance direction of the run. A positive advance offset moves the glyph to the right
        /// (in pre-transform coordinates) if the run is left-to-right or to the left if the run is right-to-left.
        /// </summary>
        FLOAT AdvanceOffset;

        /// <summary>
        /// Offset in the ascent direction, i.e., the direction ascenders point. A positive ascender offset moves
        /// the glyph up (in pre-transform coordinates).
        /// </summary>
        FLOAT AscenderOffset;
    };

    ref class FontFace;
    /// <summary>
    /// Contains the information needed by renderers to draw glyph runs. 
    /// All coordinates are in device independent pixels (DIPs). 
    /// </summary>
    public value struct GlyphRun
    {
    public:

        /// <summary>
        /// The physical font face to draw with.
        /// </summary>
        DWrite::FontFace^ FontFace;

        /// <summary>
        /// Logical size of the font in DIPs, not points (equals 1/96 inch).
        /// </summary>
        FLOAT FontEmSize;

        /// <summary>
        /// The indices to render.
        /// </summary>    
        array<UINT16>^ GlyphIndices;

        /// <summary>
        /// Glyph advance widths.
        /// </summary>
        array<FLOAT>^ GlyphAdvances;

        /// <summary>
        /// Glyph offsets.
        /// </summary>
        array<GlyphOffset>^ GlyphOffsets;

        /// <summary>
        /// If true, specifies that glyphs are rotated 90 degrees to the left and
        /// vertical metrics are used. Vertical writing is achieved by specifying
        /// isSideways = true and rotating the entire run 90 degrees to the right
        /// via a rotate transform.
        /// </summary>
        Boolean IsSideways;

        /// <summary>
        /// The implicit resolved bidi level of the run. Odd levels indicate
        /// right-to-left languages like Hebrew and Arabic, while even levels
        /// indicate left-to-right languages like English and Japanese (when
        /// written horizontally). For right-to-left languages, the text origin
        /// is on the right, and text should be drawn to the left.
        /// </summary>
        UInt32 BidiLevel;

    internal:
        void CopyTo(DWRITE_GLYPH_RUN *pNativeStruct);
    };
} } } }