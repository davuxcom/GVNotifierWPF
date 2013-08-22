//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DWriteTextFormat.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DirectWrite {

    interface class ICustomInlineObject;
    ref class InlineObject;
    ref class Typography;

    namespace DWrite = Microsoft::WindowsAPICodePack::DirectX::DirectWrite;

    /// <summary>
    /// Represents a block of text after it has been fully analyzed and formatted.
    /// <para>All coordinates are in device independent pixels (DIPs).</para>
    /// <para>(Also see DirectX SDK: IDWriteTextLayout)</para>
    /// </summary>
    public ref class TextLayout : public TextFormat
    {
    public: 
    /// <summary>
    /// The text that was used to create this TextLayout.
    /// </summary>
    property String^ Text
    {
        String^ get();
    }

    /// <summary>
    /// Get or set layout maximum width
    /// </summary>
    property FLOAT MaxWidth
    {
        FLOAT get();
        void set(FLOAT);
    }
        
    /// <summary>
    /// Get or set layout maximum height
    /// </summary>
    property FLOAT MaxHeight
    {
        FLOAT get();
        void set(FLOAT);
    }

    /// <summary>
    /// Set font family name.
    /// </summary>
    /// <param name="fontFamilyName">Font family name</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetFontFamilyName(
        System::String^  fontFamilyName,
        TextRange textRange
        );

    /// <summary>
    /// Set font weight.
    /// </summary>
    /// <param name="fontWeight">Font weight</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetFontWeight(
        DWrite::FontWeight fontWeight,
        TextRange textRange
        );

    /// <summary>
    /// Set font style.
    /// </summary>
    /// <param name="fontStyle">Font style</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetFontStyle(
        DWrite::FontStyle fontStyle,
        TextRange textRange
        );

    /// <summary>
    /// Set font stretch.
    /// </summary>
    /// <param name="fontStretch">font stretch</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetFontStretch(
        DWrite::FontStretch fontStretch,
        TextRange textRange
        );

    /// <summary>
    /// Set font em height.
    /// </summary>
    /// <param name="fontSize">Font em height</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetFontSize(
        FLOAT fontSize,
        TextRange textRange
        );

    /// <summary>
    /// Set underline.
    /// </summary>
    /// <param name="hasUnderline">The Boolean flag indicates whether underline takes place</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetUnderline(
        Boolean hasUnderline,
        TextRange textRange
        );

    /// <summary>
    /// Set strikethrough.
    /// </summary>
    /// <param name="hasStrikethrough">The Boolean flag indicates whether strikethrough takes place</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetStrikethrough(
        Boolean hasStrikethrough,
        TextRange textRange
        );


    /// <summary>
    /// Set a custom inline object.
    /// </summary>
    /// <param name="inlineObject">An application-implemented inline object.</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    /// <remarks>
    /// This inline object applies to the specified range and will be passed back
    /// to the application via the DrawInlineObject callback when the range is drawn.
    /// Any text in that range will be suppressed.
    /// </remarks>
    void SetInlineObject(
        ICustomInlineObject^ inlineObject,
        TextRange textRange
        );

    /// <summary>
    /// Set inline object.
    /// </summary>
    /// <param name="inlineObject">An application-implemented inline object.</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    /// <remarks>
    /// This inline object applies to the specified range and will be passed back
    /// to the application via the DrawInlineObject callback when the range is drawn.
    /// Any text in that range will be suppressed.
    /// </remarks>
    void SetInlineObject(
        InlineObject^ inlineObject,
        TextRange textRange
        );

    /// <summary>
    /// Set CultureInfo.
    /// </summary>
    /// <param name="cultureInfo">Culture Info</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetCultureInfo(
        System::Globalization::CultureInfo^ cultureInfo,
        TextRange textRange
        );

    /// <summary>
    /// Sets font typography features for text within a specified text range.
    /// </summary>
    /// <param name="typography">Font typography settings collection.</param>
    /// <param name="textRange">Text range to which this change applies.</param>
    void SetTypography(
        Typography^ typography,
        TextRange textRange
        );    
    
    /// <summary>
    /// Get the font family name of the text where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>The current font family name</returns>
    System::String^ GetFontFamilyName(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Get the font family name of the text where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>The current font family name</returns>
    System::String^ GetFontFamilyName(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the font weight where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>The current font weight</returns>
    DWrite::FontWeight GetFontWeight(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Get the font weight where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>The current font weight</returns>
    DWrite::FontWeight GetFontWeight(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the font style where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The current font style.
    /// </returns>
    DWrite::FontStyle GetFontStyle(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Get the font style where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The current font style.
    /// </returns>
    DWrite::FontStyle GetFontStyle(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the font stretch where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The current font stretch.
    /// </returns>
    DWrite::FontStretch GetFontStretch(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );


    /// <summary>
    /// Get the font stretch where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The current font stretch.
    /// </returns>
    DWrite::FontStretch GetFontStretch(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the font em height where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The current font em height.
    /// </returns>
    FLOAT GetFontSize(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Get the font em height where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The current font em height.
    /// </returns>
    FLOAT GetFontSize(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the underline presence where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The Boolean flag indicates whether text is underlined.
    /// </returns>
    Boolean GetUnderline(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );


    /// <summary>
    /// Get the underline presence where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The Boolean flag indicates whether text is underlined.
    /// </returns>
    Boolean GetUnderline(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the strikethrough presence where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The Boolean flag indicates whether text has strikethrough.
    /// </returns>
    Boolean GetStrikethrough(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Get the strikethrough presence where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The Boolean flag indicates whether text has strikethrough.
    /// </returns>
    Boolean GetStrikethrough(
        UINT32 currentPosition
        );

    /// <summary>
    /// Get the culture info where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The current culture info.
    /// </returns>
    System::Globalization::CultureInfo^ GetCultureInfo(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Get the culture info where the current position is at.
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The current culture info.
    /// </returns>
    System::Globalization::CultureInfo^ GetCultureInfo(
        UINT32 currentPosition
        );

    /// <summary>
    /// Gets the typography setting of the text at the specified position. 
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <param name="textRange">The position range of the current format.</param>
    /// <returns>
    /// The current typography collection, or null if no typography has been set.
    /// </returns>
    Typography^ GetTypography(
        UINT32 currentPosition,
        [System::Runtime::InteropServices::Out] TextRange % textRange
        );

    /// <summary>
    /// Gets the typography setting of the text at the specified position. 
    /// </summary>
    /// <param name="currentPosition">The current text position.</param>
    /// <returns>
    /// The current typography collection, or null if no typography has been set.
    /// </returns>
    Typography^ GetTypography(
        UINT32 currentPosition
        );

    /// <summary>
    /// Retrieves the information about each individual text line of the text string. 
    /// </summary>
    /// <returns>Properties of each line.</returns>
    array<DWrite::LineMetrics>^ GetLineMetrics();

    /// <summary>
    /// Retrieves overall metrics for the formatted string.
    /// </summary>
    /// <remarks>
    /// Drawing effects like underline and strikethrough do not contribute
    /// to the text size, which is essentially the sum of advance widths and
    /// line heights. Additionally, visible swashes and other graphic
    /// adornments may extend outside the returned width and height.
    /// </remarks>
    property TextMetrics Metrics
    {
        TextMetrics get();
    }

    /// <summary>
    /// GetOverhangMetrics returns the overhangs (in DIPs) of the layout and all
    /// objects contained in it, including text glyphs and inline objects.
    /// </summary>
    /// <remarks>
    /// Any underline and strikethrough do not contribute to the black box
    /// determination, since these are actually drawn by the renderer, which
    /// is allowed to draw them in any variety of styles.
    /// </remarks>
    property DWrite::OverhangMetrics OverhangMetrics
    {
        DWrite::OverhangMetrics get();
    }


    /// <summary>
    /// Retrieves logical properties and measurements of each glyph cluster. 
    /// </summary>
    /// <returns>
    /// Array of Cluster Metrics such as line-break or total advance width, for each glyph cluster.
    /// </returns>
    array<ClusterMetrics>^ GetClusterMetrics();

    /// <summary>
    /// Determines the minimum possible width the layout can be set to without
    /// emergency breaking between the characters of whole words.
    /// </summary>
    /// <returns>
    /// Minimum width.
    /// </returns>
    FLOAT DetermineMinWidth(
        );

    /// <summary>
    /// Given a coordinate (in DIPs) relative to the top-left of the layout box,
    /// this returns the corresponding hit-test metrics of the text string where
    /// the hit-test has occurred. This is useful for mapping mouse clicks to caret
    /// positions. When the given coordinate is outside the text string, the function
    /// sets the output value *isInside to false but returns the nearest character
    /// position.
    /// </summary>
    /// <param name="pointX">X coordinate to hit-test, relative to the top-left location of the layout box.</param>
    /// <param name="pointY">Y coordinate to hit-test, relative to the top-left location of the layout box.</param>
    /// <param name="isInside">Output flag indicating whether the hit-test location is inside the text string.
    ///     When false, the position nearest the text's edge is returned.</param>
    /// <param name="isTrailingHit">Output flag indicating whether the hit-test location is at the leading or the trailing
    ///     side of the character. When the output *isInside value is set to false, this value is set according to the output
    ///     *position value to represent the edge closest to the hit-test location. </param>
    /// <returns>Output geometry fully enclosing the hit-test location. When the output isInside value
    ///     is set to false, this structure represents the geometry enclosing the edge closest to the hit-test location.</returns>
    HitTestMetrics HitTestPoint(
        FLOAT pointX,
        FLOAT pointY,
        [System::Runtime::InteropServices::Out] Boolean % isTrailingHit,
        [System::Runtime::InteropServices::Out] Boolean % isInside
        );

    /// <summary>
    /// Given a text position and whether the caret is on the leading or trailing
    /// edge of that position, this returns the corresponding coordinate (in DIPs)
    /// relative to the top-left of the layout box. This is most useful for drawing
    /// the caret's current position, but it could also be used to anchor an IME to the
    /// typed text or attach a floating menu near the point of interest. It may also be
    /// used to programmatically obtain the geometry of a particular text position
    /// for UI automation.
    /// </summary>
    /// <param name="textPosition">Text position to get the coordinate of.</param>
    /// <param name="isTrailingHit">Flag indicating whether the location is of the leading or the trailing side of the specified text position. </param>
    /// <param name="pointX">Output caret X, relative to the top-left of the layout box.</param>
    /// <param name="pointY">Output caret Y, relative to the top-left of the layout box.</param>
    /// <returns>
    /// Output geometry fully enclosing the specified text position.
    /// </returns>
    /// <remarks>
    /// When drawing a caret at the returned X,Y, it should should be centered on X
    /// and drawn from the Y coordinate down. The height will be the size of the
    /// hit-tested text (which can vary in size within a line).
    /// Reading direction also affects which side of the character the caret is drawn.
    /// However, the returned X coordinate will be correct for either case.
    /// You can get a text length back that is larger than a single character.
    /// This happens for complex scripts when multiple characters form a single cluster,
    /// when diacritics join their base character, or when you test a surrogate pair.
    /// </remarks>
    HitTestMetrics HitTestTextPosition(
        UINT32 textPosition,
        Boolean isTrailingHit,
        [System::Runtime::InteropServices::Out] FLOAT % pointX,
        [System::Runtime::InteropServices::Out] FLOAT % pointY        
        );

    /// <summary>
    /// The application calls this function to get a set of hit-test metrics
    /// corresponding to a range of text positions. The main usage for this
    /// is to draw highlighted selection of the text string.
    /// </summary>
    /// <param name="textPosition">First text position of the specified range.</param>
    /// <param name="textLength">Number of positions of the specified range.</param>
    /// <param name="originX">Offset of the X origin (left of the layout box) which is added to each of the hit-test metrics returned.</param>
    /// <param name="originY">Offset of the Y origin (top of the layout box) which is added to each of the hit-test metrics returned.</param>
    /// <returns>
    /// Aarray of the output geometry fully enclosing the specified position range.
    /// </returns>
    /// <remarks>
    /// There are no gaps in the returned metrics. While there could be visual gaps,
    /// depending on bidi ordering, each range is contiguous and reports all the text,
    /// including any hidden characters and trimmed text.
    /// The height of each returned range will be the same within each line, regardless
    /// of how the font sizes vary.
    /// </remarks>
    array<HitTestMetrics>^ HitTestTextRange(
        UINT32 textPosition,
        UINT32 textLength,
        FLOAT originX,
        FLOAT originY
        );

    private:
        String^ _text;

    internal:
        TextLayout() : TextFormat()
        { }
    
        TextLayout(IDWriteTextLayout* pNativeIDWriteTextLayout, String^ text) : TextFormat(pNativeIDWriteTextLayout), _text(text)
        { }

        TextLayout(IDWriteTextLayout* pNativeIDWriteTextLayout) : TextFormat(pNativeIDWriteTextLayout)
        { }
    };
} } } }
