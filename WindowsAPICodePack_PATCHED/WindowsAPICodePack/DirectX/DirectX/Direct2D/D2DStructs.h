// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct2D1 {

    namespace D2D = Microsoft::WindowsAPICodePack::DirectX::Direct2D1;

    /// <summary>
    /// Represents an x-coordinate and y-coordinate pair, expressed as floating-point values, in two-dimensional space.
    /// <para>(Also see DirectX SDK: D2D1_POINT_2F)</para>
    /// </summary>
    public value struct Point2F
    {
    public:


        /// <summary>
        /// Constructor for the Point2F value type
        /// </summary>
        /// <param name="x">Initializes the x field.</param>
        /// <param name="y">Initializes the y field.</param>
        Point2F(
            FLOAT x,
            FLOAT y
            );


        /// <summary>
        /// The x-coordinate of the point.
        /// </summary>
        FLOAT X;

        /// <summary>
        /// The y-coordinate of the point.
        /// </summary>
        FLOAT Y;

        static Boolean operator == ( Point2F a, Point2F b )
        {
            return 
                (a.X == b.X)  &&
                (a.Y == b.Y);
        }

        static Boolean operator != ( Point2F a, Point2F b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_POINT_2F &point_2f
            );

        void CopyTo(
            __out D2D1_POINT_2F *ppoint_2f
            );

    };

    /// <summary>
    /// Stores an ordered pair of integers, typically the width and height of a rectangle.
    /// <para>(Also see DirectX SDK: D2D1_SIZE_F)</para>
    /// </summary>
    public value struct SizeF
    {
    public:

        /// <summary>
        /// Constructor for the SizeF value type
        /// </summary>
        /// <param name="width">Initializes the width field.</param>
        /// <param name="height">Initializes the height field.</param>
        SizeF(
            FLOAT width,
            FLOAT height
            );


        /// <summary>
        /// The horizontal component of this size.
        /// </summary>
        FLOAT Width;

        /// <summary>
        /// The vertical component of this size.
        /// </summary>
        FLOAT Height;

        static Boolean operator == ( SizeF a, SizeF b )
        {
            return 
                (a.Width == b.Width)  &&
                (a.Height == b.Height);
        }

        static Boolean operator != ( SizeF a, SizeF b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_SIZE_F &size_f
            );

        void CopyTo(
            __out D2D1_SIZE_F *psize_f
            );

    };


    /// <summary>
    /// Describes an elliptical arc between two points.
    /// <para>(Also see DirectX SDK: D2D1_ARC_SEGMENT)</para>
    /// </summary>
    public value struct ArcSegment
    {
    public:


        /// <summary>
        /// Constructor for the ArcSegment value type
        /// </summary>
        /// <param name="point">Initializes the point field.</param>
        /// <param name="size">Initializes the size field.</param>
        /// <param name="rotationangle">Initializes the rotationAngle field.</param>
        /// <param name="sweepdirection">Initializes the sweepDirection field.</param>
        /// <param name="arcsize">Initializes the arcSize field.</param>
        ArcSegment(
            Point2F point,
            SizeF size,
            FLOAT rotationangle,
            D2D::SweepDirection sweepdirection,
            D2D::ArcSize arcsize
            );


        /// <summary>
        /// The end point of the arc.
        /// </summary>
        Point2F Point;

        /// <summary>
        /// The x-radius and y-radius of the arc.
        /// </summary>
        SizeF Size;

        /// <summary>
        /// A value that specifies how many degrees in the clockwise direction the ellipse 
        /// is rotated relative to the current coordinate system.
        /// </summary>
        FLOAT RotationAngle;

        /// <summary>
        /// A value that specifies whether the arc sweep is clockwise or counterclockwise.
        /// </summary>
        D2D::SweepDirection SweepDirection;

        /// <summary>
        /// A value that specifies whether the given arc is larger than 180 degrees.
        /// </summary>
        D2D::ArcSize ArcSize;

        static Boolean operator == ( ArcSegment a, ArcSegment b )
        {
            return 
                (a.Point == b.Point)  &&
                (a.Size == b.Size)  &&
                (a.RotationAngle == b.RotationAngle)  &&
                (a.SweepDirection == b.SweepDirection)  &&
                (a.ArcSize == b.ArcSize);
        }

        static Boolean operator != ( ArcSegment a, ArcSegment b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_ARC_SEGMENT &arc_segment
            );

        void CopyTo(
            __out D2D1_ARC_SEGMENT *parc_segment
            );

    };


    /// <summary>
    /// Represents a cubic bezier segment drawn between two points.
    /// <para>(Also see DirectX SDK: D2D1_BEZIER_SEGMENT)</para>
    /// </summary>
    public value struct BezierSegment
    {
    public:


        /// <summary>
        /// Constructor for the BezierSegment value type
        /// </summary>
        /// <param name="point1">Initializes the point1 field.</param>
        /// <param name="point2">Initializes the point2 field.</param>
        /// <param name="point3">Initializes the point3 field.</param>
        BezierSegment(
            Point2F point1,
            Point2F point2,
            Point2F point3
            );


        /// <summary>
        /// The first control point for the Bezier segment.
        /// </summary>
        Point2F Point1;

        /// <summary>
        /// The second control point for the Bezier segment.
        /// </summary>
        Point2F Point2;

        /// <summary>
        /// The end point for the Bezier segment.
        /// </summary>
        Point2F Point3;

        static Boolean operator == ( BezierSegment a, BezierSegment b )
        {
            return 
                (a.Point1 == b.Point1)  &&
                (a.Point2 == b.Point2)  &&
                (a.Point3 == b.Point3);
        }

        static Boolean operator != ( BezierSegment a, BezierSegment b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_BEZIER_SEGMENT &bezier_segment
            );

        void CopyTo(
            __out D2D1_BEZIER_SEGMENT *pbezier_segment
            );

    };


    /// <summary>
    /// Contains the three vertices that describe a triangle.
    /// <para>(Also see DirectX SDK: D2D1_TRIANGLE)</para>
    /// </summary>
    public value struct Triangle
    {
    public:


        /// <summary>
        /// Constructor for the Triangle value type
        /// </summary>
        /// <param name="point1">Initializes the point1 field.</param>
        /// <param name="point2">Initializes the point2 field.</param>
        /// <param name="point3">Initializes the point3 field.</param>
        Triangle(
            Point2F point1,
            Point2F point2,
            Point2F point3
            );

        /// <summary>
        /// The first vertex of a triangle.
        /// </summary>
        Point2F Point1;

        /// <summary>
        /// The second vertex of a triangle.
        /// </summary>
        Point2F Point2;

        /// <summary>
        /// The third vertex of a triangle.
        /// </summary>
        Point2F Point3;

        static Boolean operator == ( Triangle a, Triangle b )
        {
            return 
                (a.Point1 == b.Point1)  &&
                (a.Point2 == b.Point2)  &&
                (a.Point3 == b.Point3);
        }

        static Boolean operator != ( Triangle a, Triangle b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_TRIANGLE &triangle
            );

        void CopyTo(
            __out D2D1_TRIANGLE *ptriangle
            );

    };


    /// <summary>
    /// Represents a 3-by-2 matrix.
    /// <para>(Also see DirectX SDK: D2D1_MATRIX_3X2_F)</para>
    /// </summary>
    public value struct Matrix3x2F
    {
    public:

        /// <summary>
        /// Constructor for the Matrix3x2F value type
        /// </summary>
        /// <param name="m11">Initializes the _11 field.</param>
        /// <param name="m12">Initializes the _12 field.</param>
        /// <param name="m21">Initializes the _21 field.</param>
        /// <param name="m22">Initializes the _22 field.</param>
        /// <param name="m31">Initializes the _31 field.</param>
        /// <param name="m32">Initializes the _32 field.</param>
        Matrix3x2F(
            FLOAT m11,
            FLOAT m12,
            FLOAT m21,
            FLOAT m22,
            FLOAT m31,
            FLOAT m32
            );


        /// <summary>
        /// The value in the first row and first column of the matrix.
        /// </summary>
        FLOAT M11;

        /// <summary>
        /// The value in the first row and second column of the matrix.
        /// </summary>
        FLOAT M12;

        /// <summary>
        /// The value in the second row and first column of the matrix.
        /// </summary>
        FLOAT M21;

        /// <summary>
        /// The value in the second row and second column of the matrix.
        /// </summary>
        FLOAT M22;

        /// <summary>
        /// The value in the third row and first column of the matrix.
        /// </summary>
        FLOAT M31;

        /// <summary>
        /// The value in the third row and second column of the matrix.
        /// </summary>
        FLOAT M32;

    public:

        static Boolean operator == ( Matrix3x2F a, Matrix3x2F b )
        {
            return 
                (a.M11 == b.M11)  &&
                (a.M12 == b.M12)  &&
                (a.M21 == b.M21)  &&
                (a.M22 == b.M22)  &&
                (a.M31 == b.M31)  &&
                (a.M32 == b.M32);
        }

        static Boolean operator != ( Matrix3x2F a, Matrix3x2F b )
        {
            return !(a == b);
        }

        /// <summary>
        /// Creates a translation transformation that has the specified displacement.
        /// </summary>
        /// <param name="size">Contains the x and y displacements.</param>
        /// <returns>A transformation matrix that translates an object the specified horizontal and vertical distance.</returns>
        static Matrix3x2F Translation( SizeF size );

        /// <summary>
        /// Creates a translation transformation that has the specified x and y displacements.
        /// </summary>
        /// <param name="x">The distance to translate along the x-axis.</param>
        /// <param name="y">The distance to translate along the y-axis.</param>
        /// <returns>A transformation matrix that translates an object the specified horizontal and vertical distance.</returns>
        static Matrix3x2F Translation( float x, float y);

        /// <summary>
        /// Creates a scale transformation that has the specified scale factors and center point. 
        /// </summary>
        /// <param name="size">Contains the x and y factors of scale transformation.</param>
        /// <param name="center">The point about which the scale is performed.</param>
        /// <returns>The new scale transformation.</returns>
        static Matrix3x2F Scale(SizeF size, Point2F center);

        /// <summary>
        /// Creates a scale transformation that has the specified scale factors at point (0, 0). 
        /// </summary>
        /// <param name="size">Contains the x and y factors of scale transformation.</param>
        /// <returns>The new scale transformation.</returns>
        static Matrix3x2F Scale(SizeF size);

        /// <summary>
        /// Creates a scale transformation that has the specified scale factors and center point. 
        /// </summary>
        /// <param name="x">The x-axis scale factor of the scale transformation.</param>
        /// <param name="y">The y-axis scale factor of the scale transformation.</param>
        /// <param name="center">The point about which the scale is performed.</param>
        /// <returns>The new scale transformation.</returns>
        static Matrix3x2F Scale(FLOAT x, FLOAT y, Point2F center);

        /// <summary>
        /// Creates a scale transformation that has the specified scale factors at point (0, 0). 
        /// </summary>
        /// <param name="x">The x-axis scale factor of the scale transformation.</param>
        /// <param name="y">The y-axis scale factor of the scale transformation.</param>
        /// <returns>The new scale transformation.</returns>
        static Matrix3x2F Scale(FLOAT x, FLOAT y);

        /// <summary>
        /// Creates a rotation transformation that has the specified angle and center point.
        /// </summary>
        /// <param name="angle">The rotation angle in degrees. 
        /// A positive angle creates a clockwise rotation, and a negative angle creates a counterclockwise rotation.</param>
        /// <param name="center">The point about which the rotation is performed.</param>
        /// <returns>The new rotation transformation.</returns>
        static Matrix3x2F Rotation(FLOAT angle, Point2F center);

        /// <summary>
        /// Creates a rotation transformation that has the specified angle and rotates around Point (0, 0).
        /// </summary>
        /// <param name="angle">The rotation angle in degrees. 
        /// A positive angle creates a clockwise rotation, and a negative angle creates a counterclockwise rotation.</param>
        /// <returns>The new rotation transformation.</returns>
        static Matrix3x2F Rotation(FLOAT angle);

        /// <summary>
        /// Creates a skew transformation that has the specified x-axis and y-axis values and center point.
        /// </summary>
        /// <param name="center">The point about which the skew is performed.</param>
        /// <param name="angleX">The x-axis skew angle, which is measured in degrees counterclockwise from the y-axis.</param>
        /// <param name="angleY">The y-axis skew angle, which is measured in degrees clockwise from the x-axis.</param>
        /// <returns>The new skew transformation.</returns>
        static Matrix3x2F Skew(FLOAT angleX, FLOAT angleY, Point2F center);

        /// <summary>
        /// Creates a skew transformation that has the specified x-axis and y-axis values at point (0, 0).
        /// </summary>
        /// <param name="angleX">The x-axis skew angle, which is measured in degrees counterclockwise from the y-axis.</param>
        /// <param name="angleY">The y-axis skew angle, which is measured in degrees clockwise from the x-axis.</param>
        /// <returns>The new skew transformation.</returns>
        static Matrix3x2F Skew(FLOAT angleX, FLOAT angleY);


        /// <summary>
        /// The Idenitity Matrix
        /// </summary>
        static property Matrix3x2F Identity
        {
            Matrix3x2F get();        
        }

        /// <summary>
        /// Indicates whether this matrix is the identity matrix.
        /// </summary>
        property bool IsIdentity
        {
            bool get();
        }

    internal:
        void CopyFrom(
            __in const D2D1_MATRIX_3X2_F &matrix_3x2_f
            );

        void CopyTo(
            __out D2D1_MATRIX_3X2_F *pmatrix_3x2_f
            );

    };


    /// <summary>
    /// Defines a two-tag element, which contains two application-defined 64-bit unsigned integer values used to mark a set of rendering operations. 
    /// </summary>
    public value struct Tags
    {
    public:

        /// <summary>
        /// Constructor for the Tags struct.
        /// </summary>
        /// <param name="tag1">Initializes the first tag element.</param>
        /// <param name="tag2">Initializes the second tag element.</param>
        Tags(
            UINT64 tag1,
            UINT64 tag2
            ) : Tag1(tag1), Tag2(tag2)
        {
        }

        /// <summary>
        /// First tag element.
        /// </summary>
        UINT64 Tag1;

        /// <summary>
        /// Second tag element.
        /// </summary>
        UINT64 Tag2;


        static Boolean operator == ( Tags a, Tags b )
        {
            return 
                (a.Tag1 == b.Tag1)  &&
                (a.Tag2 == b.Tag2);
        }

        static Boolean operator != ( Tags a, Tags b )
        {
            return !(a == b);
        }

    };  


    /// <summary>
    /// Describes the drawing state of a render target. 
    /// This also specifies the drawing state that is saved into a DrawingStateBlock object.
    /// <para>(Also see DirectX SDK: D2D1_DRAWING_STATE_DESCRIPTION)</para>
    /// </summary>
    public value struct DrawingStateDescription
    {
    public:

        /// <summary>
        /// Constructor for the DrawingStateDescription value type
        /// </summary>
        /// <param name="antialiasmode">Initializes the antialiasMode field.</param>
        /// <param name="textantialiasmode">Initializes the textAntialiasMode field.</param>
        /// <param name="tags">Initializes the tags field.</param>
        /// <param name="transform">Initializes the transform field.</param>
        DrawingStateDescription(
            D2D::AntialiasMode antialiasmode,
            D2D::TextAntialiasMode textantialiasmode,
            D2D::Tags tags,
            Matrix3x2F transform
            );


        /// <summary>
        /// The antialiasing mode for subsequent nontext drawing operations.
        /// </summary>
        D2D::AntialiasMode AntialiasMode;

        /// <summary>
        /// The antialiasing mode for subsequent text and glyph drawing operations.
        /// </summary>
        D2D::TextAntialiasMode TextAntialiasMode;

        /// <summary>
        /// The tags for subsequent drawing operations.
        /// </summary>
        D2D::Tags Tags;

        /// <summary>
        /// The transformation to apply to subsequent drawing operations.
        /// </summary>
        Matrix3x2F Transform;

    internal:

        void CopyFrom(
            __in const D2D1_DRAWING_STATE_DESCRIPTION &drawing_state_description
            );

        void CopyTo(
            __out D2D1_DRAWING_STATE_DESCRIPTION *pdrawing_state_description
            );

    };


    /// <summary>
    /// Contains the center point, x-radius, and y-radius of an ellipse.
    /// <para>(Also see DirectX SDK: D2D1_ELLIPSE)</para>
    /// </summary>
    public value struct Ellipse
    {
    public:

        /// <summary>
        /// Constructor for the Ellipse value type
        /// </summary>
        /// <param name="point">Initializes the point field.</param>
        /// <param name="radiusx">Initializes the radiusX field.</param>
        /// <param name="radiusy">Initializes the radiusY field.</param>
        Ellipse(
            Point2F point,
            FLOAT radiusx,
            FLOAT radiusy
            );


        /// <summary>
        /// The center point of the ellipse.
        /// </summary>
        Point2F Point;

        /// <summary>
        /// The X-radius of the ellipse.
        /// </summary>
        FLOAT RadiusX;

        /// <summary>
        /// The Y-radius of the ellipse.
        /// </summary>
        FLOAT RadiusY;


        static Boolean operator == ( Ellipse a, Ellipse b )
        {
            return 
                (a.Point == b.Point)  &&
                (a.RadiusX == b.RadiusX)  &&
                (a.RadiusY == b.RadiusY);
        }

        static Boolean operator != ( Ellipse a, Ellipse b )
        {
            return !(a == b);
        }


    internal:

        void CopyFrom(
            __in const D2D1_ELLIPSE &ellipse
            );

        void CopyTo(
            __out D2D1_ELLIPSE *pellipse
            );

    };


    /// <summary>
    /// Allows additional parameters for factory creation.
    /// <para>(Also see DirectX SDK: D2D1_FACTORY_OPTIONS)</para>
    /// </summary>
    public value struct FactoryOptions
    {
    public:


        /// <summary>
        /// Constructor for the FactoryOptions value type
        /// </summary>
        /// <param name="debuglevel">Initializes the debugLevel field.</param>
        FactoryOptions(
            D2D::DebugLevel debuglevel
            );

        /// <summary>
        /// Requests a certain level of debugging information from the debug layer. This parameter
        /// is ignored if the debug layer DLL is not present.
        /// </summary>
        D2D::DebugLevel DebugLevel;

    internal:

        void CopyFrom(
            __in const D2D1_FACTORY_OPTIONS &factory_options
            );

        void CopyTo(
            __out D2D1_FACTORY_OPTIONS *pfactory_options
            );
    };


    /// <summary>
    /// Describes the red, green, blue, and alpha components of a color.
    /// <para>(Also see DirectX SDK: D2D1_COLOR_F)</para>
    /// </summary>
    public value struct ColorF
    {
    public:
        /// <summary>
        /// Constructor for the ColorF value type
        /// </summary>
        /// <param name="r">Initializes the r field.</param>
        /// <param name="g">Initializes the g field.</param>
        /// <param name="b">Initializes the b field.</param>
        /// <param name="a">Initializes the a field.</param>
        ColorF(
            FLOAT r,
            FLOAT g,
            FLOAT b,
            FLOAT a
            );


        /// <summary>
        /// Constructor for the ColorF using a predefined color. Alpha = 1.0
        /// </summary>
        /// <param name="color">A predefined color enumeration to initialize the red, green and blue components.</param>
        ColorF(
            Colors color
            );

        /// <summary>
        /// Constructor for the ColorF using a predefined color.
        /// </summary>
        /// <param name="color">A predefined color enumeration to initialize the red, green and blue components.</param>
        /// <param name="alpha">Initializes the alpha channel value.</param>
        ColorF(
            Colors color,
            FLOAT alpha
            );


        /// <summary>
        /// Floating-point value specifying the red component of a color. This value generally is in the range from 0.0 through 1.0, with 0.0 being black. 
        /// </summary>
        FLOAT R;

        /// <summary>
        /// Floating-point value specifying the green component of a color. This value generally is in the range from 0.0 through 1.0, with 0.0 being black.
        /// </summary>
        FLOAT G;

        /// <summary>
        /// Floating-point value specifying the blue component of a color. This value generally is in the range from 0.0 through 1.0, with 0.0 being black. 
        /// </summary>
        FLOAT B;

        /// <summary>
        /// Floating-point value specifying the alpha component of a color. This value generally is in the range from 0.0 through 1.0, with 0.0 being completely transparent.
        /// </summary>
        FLOAT A;


        static Boolean operator == ( ColorF a, ColorF b )
        {
            return 
                (a.R == b.R)  &&
                (a.G == b.G)  &&
                (a.B == b.B)  &&
                (a.A == b.A);
        }

        static Boolean operator != ( ColorF a, ColorF b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_COLOR_F &color_f
            );

        void CopyTo(
            __out D2D1_COLOR_F *pcolor_f
            );

    private:
        static const UINT32 sc_redShift   = 16;
        static const UINT32 sc_greenShift = 8;
        static const UINT32 sc_blueShift  = 0;    

        static const UINT32 sc_redMask = 0xff << sc_redShift;
        static const UINT32 sc_greenMask = 0xff << sc_greenShift;
        static const UINT32 sc_blueMask = 0xff << sc_blueShift;      
    };


    /// <summary>
    /// Contains the position and color of a gradient stop.
    /// <para>(Also see DirectX SDK: D2D1_GRADIENT_STOP)</para>
    /// </summary>
    /// <remarks>
    /// <para>
    /// Gradient stops can be specified in any order if they are at different positions. Two stops may share a position. 
    /// In this case, the first stop specified is treated as the "low" stop (nearer 0.0f) and subsequent stops are treated as "higher" (nearer 1.0f). 
    /// This behavior is useful if a caller wants an instant transition in the middle of a stop.
    /// </para>
    /// <para>
    /// Typically, there are at least two points in a collection, although creation with only one stop is permitted. 
    /// For example, one point is at position 0.0f, another point is at position 1.0f, and additional points 
    /// are distributed in the [0, 1] range. Where the gradient progression is beyond the range of [0, 1], 
    /// the stops are stored, but may affect the gradient. 
    /// </para>
    /// <para>
    /// When drawn, the [0, 1] range of positions is mapped to the brush, in a brush-dependent way. 
    /// </para>
    /// <para>
    /// Gradient stops with a position outside the [0, 1] range can not be seen explicitly, 
    /// but they can still affect the colors produced in the [0, 1] range. 
    /// For example, a two-stop gradient {{0.0f, Black}, {2.0f, White}} is indistinguishable visually from 
    /// {{0.0f, Black}, {1.0f, Mid-level gray}}. Also, the colors are clamped before interpolation.
    /// </para>
    /// </remarks>
    public value struct GradientStop
    {
    public:

        /// <summary>
        /// Constructor for the GradientStop value type
        /// </summary>
        /// <param name="position">Initializes the position field.</param>
        /// <param name="color">Initializes the color field.</param>
        GradientStop(
            FLOAT position,
            ColorF color
            );

        /// <summary>
        /// A value that indicates the relative position of the gradient stop in the brush. 
        /// This value must be in the [0.0f, 1.0f] range if the gradient stop is to be seen explicitly.
        /// </summary>
        FLOAT Position;

        /// <summary>
        /// The color of the gradient stop.
        /// </summary>
        ColorF Color;

        static Boolean operator == ( GradientStop a, GradientStop b )
        {
            return 
                (a.Position == b.Position)  &&
                (a.Color == b.Color);
        }

        static Boolean operator != ( GradientStop a, GradientStop b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_GRADIENT_STOP &gradient_stop
            );

        void CopyTo(
            __out D2D1_GRADIENT_STOP *pgradient_stop
            );

    };


    /// <summary>
    /// Stores an ordered pair of integers, typically the width and height of a rectangle.
    /// <para>(Also see DirectX SDK: D2D1_SIZE_U)</para>
    /// </summary>
    public value struct SizeU
    {
    public:


        /// <summary>
        /// Constructor for the SizeU value type
        /// </summary>
        /// <param name="width">Initializes the width field.</param>
        /// <param name="height">Initializes the height field.</param>
        SizeU(
            UINT32 width,
            UINT32 height
            );


        /// <summary>
        /// The horizontal component of this size.
        /// </summary>
        UINT32 Width;

        /// <summary>
        /// The vertical component of this size.
        /// </summary>
        UINT32 Height;

        static Boolean operator == ( SizeU a, SizeU b )
        {
            return 
                (a.Width == b.Width)  &&
                (a.Height == b.Height);
        }

        static Boolean operator != ( SizeU a, SizeU b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_SIZE_U &size_u
            );

        void CopyTo(
            __out D2D1_SIZE_U *psize_u
            );

    };


    /// <summary>
    /// Contains the window handle, pixel size, and presentation options for an HwndRenderTarget.
    /// <para>(Also see DirectX SDK: D2D1_HWND_RENDER_TARGET_PROPERTIES)</para>
    /// </summary>
    public value struct HwndRenderTargetProperties
    {
    public:

        /// <summary>
        /// Constructor for the HwndRenderTargetProperties value type
        /// </summary>
        /// <param name="windowHandle">Initializes the hwnd field.</param>
        /// <param name="pixelsize">Initializes the pixelSize field.</param>
        /// <param name="presentoptions">Initializes the presentOptions field.</param>
        HwndRenderTargetProperties(
            IntPtr windowHandle,
            SizeU pixelsize,
            D2D::PresentOptions presentoptions
            );


        /// <summary>
        /// A handle to the windows to which the render target issues the output from its drawing commands.
        /// </summary>
        IntPtr WindowHandle;

        /// <summary>
        /// The size of the render target, in pixels.
        /// </summary>
        SizeU PixelSize;

        /// <summary>
        /// A value that specifies whether the render target retains the frame after it is presented and whether the render target waits for the device to refresh before presenting.
        /// </summary>
        D2D::PresentOptions PresentOptions;

    internal:

        void CopyFrom(
            __in const D2D1_HWND_RENDER_TARGET_PROPERTIES &hwnd_render_target_properties
            );

        void CopyTo(
            __out D2D1_HWND_RENDER_TARGET_PROPERTIES *phwnd_render_target_properties
            );

    };


    /// <summary>
    /// Represents a rectangle defined by the coordinates of the upper-left corner (left, top) and the coordinates of the lower-right corner (right, bottom). 
    /// <para>(Also see DirectX SDK: D2D1_RECT_F)</para>
    /// </summary>
    public value struct RectF
    {
    public:

        /// <summary>
        /// Constructor for the RectF value type
        /// </summary>
        /// <param name="left">Initializes the left field.</param>
        /// <param name="top">Initializes the top field.</param>
        /// <param name="right">Initializes the right field.</param>
        /// <param name="bottom">Initializes the bottom field.</param>
        RectF(
            FLOAT left,
            FLOAT top,
            FLOAT right,
            FLOAT bottom
            );

        /// <summary>
        /// The x-coordinate of the upper-left corner of the rectangle.
        /// </summary>
        FLOAT Left;

        /// <summary>
        /// The y-coordinate of the upper-left corner of the rectangle. 
        /// </summary>
        FLOAT Top;

        /// <summary>
        /// The x-coordinate of the lower-right corner of the rectangle. 
        /// </summary>
        FLOAT Right;

        /// <summary>
        /// The y-coordinate of the lower-right corner of the rectangle. 
        /// </summary>
        FLOAT Bottom;

        /// <summary>
        /// The height of this rectangle. 
        /// </summary>
        /// <remarks>
        /// Changing the Height property will also cause a change in the Bottom value.
        /// </remarks>
        property FLOAT Height
        {
            FLOAT get()
            {
                return Math::Abs(Bottom - Top);
            }

            void set(FLOAT value)
            {
                Bottom = Top + value;
            }

        }

        /// <summary>
        /// Retrieve the width of this rectangle. 
        /// </summary>
        /// <remarks>
        /// Changing the Width property will also cause a change in the Right value.
        /// </remarks>
        property FLOAT Width
        {
            FLOAT get()
            {
                return Math::Abs(Left - Right);
            }

            void set(FLOAT value)
            {
                Right = Left + value;
            }
        }


        static Boolean operator == ( RectF a, RectF b )
        {
            return 
                (a.Left == b.Left)  &&
                (a.Top == b.Top)  &&
                (a.Right == b.Right)  &&
                (a.Bottom == b.Bottom);
        }

        static Boolean operator != ( RectF a, RectF b )
        {
            return !(a == b);
        }


    internal:

        void CopyFrom(
            __in const D2D1_RECT_F &rect_f
            );

        void CopyTo(
            __out D2D1_RECT_F *prect_f
            );

    };


    /// <summary>
    /// Contains the content bounds, mask information, opacity settings, and other options for a layer resource. 
    /// <para>(Also see DirectX SDK: D2D1_LAYER_PARAMETERS)</para>
    /// </summary>
    public value struct LayerParameters
    {
    public:


        /// <summary>
        /// Constructor for the LayerParameters value type
        /// </summary>
        /// <param name="contentbounds">Initializes the contentBounds field.</param>
        /// <param name="geometricmask">Initializes the geometricMask field.</param>
        /// <param name="maskantialiasmode">Initializes the maskAntialiasMode field.</param>
        /// <param name="masktransform">Initializes the maskTransform field.</param>
        /// <param name="opacity">Initializes the opacity field.</param>
        /// <param name="opacitybrush">Initializes the opacityBrush field.</param>
        /// <param name="layeroptions">Initializes the layerOptions field.</param>
        LayerParameters(
            RectF contentbounds,
            Geometry ^geometricmask,
            AntialiasMode maskantialiasmode,
            Matrix3x2F masktransform,
            FLOAT opacity,
            Brush ^opacitybrush,
            LayerOptions layeroptions
            );


        /// <summary>
        /// The rectangular clip that will be applied to the layer. The clip is affected by the
        /// world transform. Content outside these bounds is not guaranteed to render.
        /// </summary>
        RectF ContentBounds;

        /// <summary>
        /// The geometric mask specifies the area of the layer that is composited into the render target.
        /// </summary>
        Geometry ^GeometricMask;

        /// <summary>
        /// A value that specifies the antialiasing mode for the geometricMask. 
        /// </summary>
        AntialiasMode MaskAntialiasMode;

        /// <summary>
        /// A value that specifies the transform that is applied to the geometric mask when composing the layer.
        /// </summary>
        Matrix3x2F MaskTransform;

        /// <summary>
        /// An opacity value that is applied uniformly to all resources in the layer when compositing to the target.
        /// </summary>
        FLOAT Opacity;

        /// <summary>
        /// A brush that is used to modify the opacity of the layer. The brush is mapped to the layer, 
        /// and the alpha channel of each mapped brush pixel is multiplied against the corresponding layer pixel.
        /// </summary>
        Brush ^OpacityBrush;

        /// <summary>
        /// A value that specifies whether the layer intends to render text with ClearType antialiasing
        /// </summary>
        LayerOptions Options;

    internal:

        void CopyFrom(
            __in const D2D1_LAYER_PARAMETERS &layer_parameters
            );

        void CopyTo(
            __out D2D1_LAYER_PARAMETERS *player_parameters
            );

    };

    /// <summary>
    /// Contains the control point and end point for a quadratic Bezier segment.
    /// <para>(Also see DirectX SDK: D2D1_QUADRATIC_BEZIER_SEGMENT)</para>
    /// </summary>
    public value struct QuadraticBezierSegment
    {
    public:


        /// <summary>
        /// Constructor for the QuadraticBezierSegment value type
        /// </summary>
        /// <param name="point1">Initializes the point1 field.</param>
        /// <param name="point2">Initializes the point2 field.</param>
        QuadraticBezierSegment(
            Point2F point1,
            Point2F point2
            );


        /// <summary>
        /// The control point of the quadratic Bezier segment.
        /// </summary>
        Point2F Point1;

        /// <summary>
        /// The end point of the quadratic Bezier segment.
        /// </summary>
        Point2F Point2;

        static Boolean operator == ( QuadraticBezierSegment a, QuadraticBezierSegment b )
        {
            return 
                (a.Point1 == b.Point1)  &&
                (a.Point2 == b.Point2);
        }

        static Boolean operator != ( QuadraticBezierSegment a, QuadraticBezierSegment b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_QUADRATIC_BEZIER_SEGMENT &quadratic_bezier_segment
            );

        void CopyTo(
            __out D2D1_QUADRATIC_BEZIER_SEGMENT *pquadratic_bezier_segment
            );

    };


    /// <summary>
    /// Contains the dimensions and corner radii of a rounded rectangle.
    /// <para>(Also see DirectX SDK: D2D1_ROUNDED_RECT)</para>
    /// </summary>
    public value struct RoundedRect
    {
    public:

        /// <summary>
        /// Constructor for the RoundedRect value type
        /// </summary>
        /// <param name="rect">Initializes the rect field.</param>
        /// <param name="radiusx">Initializes the radiusX field.</param>
        /// <param name="radiusy">Initializes the radiusY field.</param>
        RoundedRect(
            RectF rect,
            FLOAT radiusx,
            FLOAT radiusy
            );


        /// <summary>
        /// The coordinates of the rectangle.
        /// </summary>
        RectF Rect;

        /// <summary>
        /// The x-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.
        /// </summary>
        FLOAT RadiusX;

        /// <summary>
        /// The y-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.
        /// </summary>
        FLOAT RadiusY;

        static Boolean operator == ( RoundedRect a, RoundedRect b )
        {
            return 
                (a.Rect == b.Rect)  &&
                (a.RadiusX == b.RadiusX)  &&
                (a.RadiusY == b.RadiusY);
        }

        static Boolean operator != ( RoundedRect a, RoundedRect b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_ROUNDED_RECT &rounded_rect
            );

        void CopyTo(
            __out D2D1_ROUNDED_RECT *prounded_rect
            );

    };


    /// <summary>
    /// Describes the opacity and transformation of a brush.
    /// <para>(Also see DirectX SDK: D2D1_BRUSH_PROPERTIES)</para>
    /// </summary>
    public value struct BrushProperties
    {
    public:


        /// <summary>
        /// Constructor for the BrushProperties value type
        /// </summary>
        /// <param name="opacity">Initializes the opacity field.</param>
        /// <param name="transform">Initializes the transform field.</param>
        BrushProperties(
            FLOAT opacity,
            Matrix3x2F transform
            );


        /// <summary>
        /// A value between 0.0f and 1.0f, inclusive, that specifies the degree of opacity of the brush.
        /// </summary>
        FLOAT Opacity;

        /// <summary>
        /// The transformation that is applied to the brush.
        /// </summary>
        Matrix3x2F Transform;

    internal:

        void CopyFrom(
            __in const D2D1_BRUSH_PROPERTIES &brush_properties
            );

        void CopyTo(
            __out D2D1_BRUSH_PROPERTIES *pbrush_properties
            );

    };


    /// <summary>
    /// Contains the starting point and endpoint of the gradient axis for a LinearGradientBrush.
    /// <para>(Also see DirectX SDK: D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES)</para>
    /// </summary>
    public value struct LinearGradientBrushProperties
    {
    public:


        /// <summary>
        /// Constructor for the LinearGradientBrushProperties value type
        /// </summary>
        /// <param name="startpoint">Initializes the startPoint field.</param>
        /// <param name="endpoint">Initializes the endPoint field.</param>
        LinearGradientBrushProperties(
            Point2F startpoint,
            Point2F endpoint
            );


        /// <summary>
        /// In the brush's coordinate space, the starting point of the gradient axis.
        /// </summary>
        Point2F StartPoint;

        /// <summary>
        /// In the brush's coordinate space, the endpoint of the gradient axis.
        /// </summary>
        Point2F EndPoint;

    internal:

        void CopyFrom(
            __in const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES &linear_gradient_brush_properties
            );

        void CopyTo(
            __out D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *plinear_gradient_brush_properties
            );

    };


    /// <summary>
    /// Describes the extend modes and the interpolation mode of a BitmapBrush.
    /// <para>(Also see DirectX SDK: D2D1_BITMAP_BRUSH_PROPERTIES)</para>
    /// </summary>
    public value struct BitmapBrushProperties
    {
    public:


        /// <summary>
        /// Constructor for the BitmapBrushProperties value type
        /// </summary>
        /// <param name="extendmodex">Initializes the extendModeX field.</param>
        /// <param name="extendmodey">Initializes the extendModeY field.</param>
        /// <param name="interpolationmode">Initializes the interpolationMode field.</param>
        BitmapBrushProperties(
            ExtendMode extendmodex,
            ExtendMode extendmodey,
            BitmapInterpolationMode interpolationmode
            );


        /// <summary>
        /// A value that describes how the brush horizontally tiles those areas that extend past its bitmap.
        /// </summary>
        ExtendMode ExtendModeX;

        /// <summary>
        /// A value that describes how the brush vertically tiles those areas that extend past its bitmap.
        /// </summary>
        ExtendMode ExtendModeY;

        /// <summary>
        /// A value that specifies how the bitmap is interpolated when it is scaled or rotated.
        /// </summary>
        BitmapInterpolationMode InterpolationMode;

    internal:

        void CopyFrom(
            __in const D2D1_BITMAP_BRUSH_PROPERTIES &bitmap_brush_properties
            );

        void CopyTo(
            __out D2D1_BITMAP_BRUSH_PROPERTIES *pbitmap_brush_properties
            );

    };


    /// <summary>
    /// Contains the data format and alpha mode for a bitmap or render target. 
    /// <para>(Also see DirectX SDK: D2D1_PIXEL_FORMAT)</para>
    /// </summary>
    public value struct PixelFormat
    {
    public:

        /// <summary>
        /// Constructor for the PixelFormat value type
        /// </summary>
        /// <param name="format">Initializes the format field.</param>
        /// <param name="alphamode">Initializes the alphaMode field.</param>
        PixelFormat(
            Microsoft::WindowsAPICodePack::DirectX::DXGI::Format format,
            D2D::AlphaMode alphamode
            );


        /// <summary>
        /// A value that specifies the size and arrangement of channels in each pixel.
        /// </summary>
        Microsoft::WindowsAPICodePack::DirectX::DXGI::Format Format;

        /// <summary>
        /// A value that specifies whether the alpha channel is using pre-multiplied alpha, straight alpha, whether it should be ignored and considered opaque, or whether it is unknown. 
        /// </summary>
        D2D::AlphaMode AlphaMode;

        static Boolean operator == ( PixelFormat a, PixelFormat b )
        {
            return 
                (a.Format == b.Format)  &&
                (a.AlphaMode == b.AlphaMode);
        }

        static Boolean operator != ( PixelFormat a, PixelFormat b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_PIXEL_FORMAT &pixel_format
            );

        void CopyTo(
            __out D2D1_PIXEL_FORMAT *ppixel_format
            );

    };


    /// <summary>
    /// Properties, aside from the width, that allow geometric penning to be specified.
    /// <para>(Also see DirectX SDK: D2D1_STROKE_STYLE_PROPERTIES)</para>
    /// </summary>
    public value struct StrokeStyleProperties
    {
    public:


        /// <summary>
        /// Constructor for the StrokeStyleProperties value type
        /// </summary>
        /// <param name="startcap">Initializes the startCap field.</param>
        /// <param name="endcap">Initializes the endCap field.</param>
        /// <param name="dashcap">Initializes the dashCap field.</param>
        /// <param name="linejoin">Initializes the lineJoin field.</param>
        /// <param name="miterlimit">Initializes the miterLimit field.</param>
        /// <param name="dashstyle">Initializes the dashStyle field.</param>
        /// <param name="dashoffset">Initializes the dashOffset field.</param>
        StrokeStyleProperties(
            CapStyle startcap,
            CapStyle endcap,
            CapStyle dashcap,
            LineJoin linejoin,
            FLOAT miterlimit,
            DashStyle dashstyle,
            FLOAT dashoffset
            );


        /// <summary>
        /// The cap applied to the start of all the open figures in a stroked geometry.
        /// </summary>
        CapStyle StartCap;

        /// <summary>
        /// The cap applied to the end of all the open figures in a stroked geometry.
        /// </summary>
        CapStyle EndCap;

        /// <summary>
        /// The shape at either end of each dash segment.
        /// </summary>
        CapStyle DashCap;

        /// <summary>
        /// A value that describes how segments are joined. This value is ignored for a vertex if the segment flags specify that the segment should have a smooth join.
        /// </summary>
        LineJoin LineJoin;

        /// <summary>
        /// The limit of the thickness of the join on a mitered corner. This value is always treated as though it is greater than or equal to 1.0f.
        /// </summary>
        FLOAT MiterLimit;

        /// <summary>
        /// A value that specifies whether the stroke has a dash pattern and, if so, the dash style.
        /// </summary>
        DashStyle DashStyle;

        /// <summary>
        /// A value that specifies an offset in the dash sequence. A positive dash offset value shifts the dash pattern, in units of stroke width, toward the start of the stroked geometry. A negative dash offset value shifts the dash pattern, in units of stroke width, toward the end of the stroked geometry.
        /// </summary>
        FLOAT DashOffset;

    internal:

        void CopyFrom(
            __in const D2D1_STROKE_STYLE_PROPERTIES &stroke_style_properties
            );

        void CopyTo(
            __out D2D1_STROKE_STYLE_PROPERTIES *pstroke_style_properties
            );

    };


    /// <summary>
    /// Contains the gradient origin offset and the size and position of the gradient ellipse for a RadialGradientBrush.
    /// <para>(Also see DirectX SDK: D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES)</para>
    /// </summary>
    public value struct RadialGradientBrushProperties
    {
    public:

        /// <summary>
        /// Constructor for the RadialGradientBrushProperties value type
        /// </summary>
        /// <param name="center">Initializes the center field.</param>
        /// <param name="gradientoriginoffset">Initializes the gradientOriginOffset field.</param>
        /// <param name="radiusx">Initializes the radiusX field.</param>
        /// <param name="radiusy">Initializes the radiusY field.</param>
        RadialGradientBrushProperties(
            Point2F center,
            Point2F gradientoriginoffset,
            FLOAT radiusx,
            FLOAT radiusy
            );


        /// <summary>
        /// In the brush's coordinate space, the center of the gradient ellipse.
        /// </summary>
        Point2F Center;

        /// <summary>
        /// In the brush's coordinate space, the offset of the gradient origin relative to the gradient ellipse's center.
        /// </summary>
        Point2F GradientOriginOffset;

        /// <summary>
        /// In the brush's coordinate space, the x-radius of the gradient ellipse.
        /// </summary>
        FLOAT RadiusX;

        /// <summary>
        /// In the brush's coordinate space, the y-radius of the gradient ellipse.
        /// </summary>
        FLOAT RadiusY;

    internal:

        void CopyFrom(
            __in const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES &radial_gradient_brush_properties
            );

        void CopyTo(
            __out D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *pradial_gradient_brush_properties
            );

    };


    /// <summary>
    /// Contains rendering options (hardware or software), pixel format, DPI information, remoting options, and Direct3D support requirements for a render target. 
    /// <para>(Also see DirectX SDK: D2D1_RENDER_TARGET_PROPERTIES)</para>
    /// </summary>
    public value struct RenderTargetProperties
    {
    public:

        /// <summary>
        /// Constructor for the RenderTargetProperties value type
        /// </summary>
        /// <param name="type">Initializes the type field.</param>
        /// <param name="pixelformat">Initializes the pixelFormat field.</param>
        /// <param name="dpix">Initializes the dpiX field.</param>
        /// <param name="dpiy">Initializes the dpiY field.</param>
        /// <param name="usage">Initializes the usage field.</param>
        /// <param name="minlevel">Initializes the minLevel field.</param>
        RenderTargetProperties(
            RenderTargetType type,
            PixelFormat pixelformat,
            FLOAT dpix,
            FLOAT dpiy,
            RenderTargetUsage usage,
            FeatureLevel minlevel
            );


        /// <summary>
        /// A value that specifies whether the render target should force hardware or software rendering. 
        /// A value of Default specifies that the render target should use hardware rendering if it is available; 
        /// otherwise, it uses software rendering. Note that WIC bitmap render targets do not support hardware rendering.
        /// </summary>
        RenderTargetType Type;

        /// <summary>
        /// The pixel format and alpha mode of the render target.
        /// </summary>
        PixelFormat PixelFormat;

        /// <summary>
        /// The horizontal DPI of the render target. To use the default DPI, set dpiX and dpiY to 0.
        /// </summary>
        FLOAT DpiX;

        /// <summary>
        /// The verical DPI of the render target. To use the default DPI, set dpiX and dpiY to 0.
        /// </summary>
        FLOAT DpiY;

        /// <summary>
        /// A value that specifies how the render target is remoted and whether it should be GDI-compatible. 
        /// Set to None to create a render target that is not compatible with GDI and uses Direct3D command-stream 
        /// remoting if it is available.
        /// </summary>
        RenderTargetUsage Usage;

        /// <summary>
        /// A value that specifies the minimum Direct3D feature level required for hardware rendering. 
        /// If the specified minimum level is not available, the render target uses software rendering 
        /// if the type member is set to Default; if type is set to to Hardware, render target creation fails. 
        /// A value of Default indicates that Direct2D should determine whether the Direct3D feature level of 
        /// the device is adequate. 
        /// This field is used only when creating HwndRenderTarget and DCRenderTarget objects.
        /// </summary>
        FeatureLevel MinLevel;

    internal:

        void CopyFrom(
            __in const D2D1_RENDER_TARGET_PROPERTIES &render_target_properties
            );

        void CopyTo(
            __out D2D1_RENDER_TARGET_PROPERTIES *prender_target_properties
            );

    };

    /// <summary>
    /// Describes the pixel format and dpi of a bitmap.
    /// <para>(Also see DirectX SDK: D2D1_BITMAP_PROPERTIES)</para>
    /// </summary>
    public value struct BitmapProperties
    {
    public:


        /// <summary>
        /// Constructor for the BitmapProperties value type
        /// </summary>
        /// <param name="pixelformat">Initializes the pixelFormat field.</param>
        /// <param name="dpix">Initializes the dpiX field.</param>
        /// <param name="dpiy">Initializes the dpiY field.</param>
        BitmapProperties(
            PixelFormat pixelformat,
            FLOAT dpix,
            FLOAT dpiy
            );


        /// <summary>
        /// The bitmap's pixel format and alpha mode.
        /// </summary>
        PixelFormat PixelFormat;

        /// <summary>
        /// The horizontal dpi of the bitmap.
        /// </summary>
        FLOAT DpiX;

        /// <summary>
        /// The vertical dpi of the bitmap.
        /// </summary>
        FLOAT DpiY;

    internal:

        void CopyFrom(
            __in const D2D1_BITMAP_PROPERTIES &bitmap_properties
            );

        void CopyTo(
            __out D2D1_BITMAP_PROPERTIES *pbitmap_properties
            );

    };

    /// <summary>
    /// Represents an x-coordinate and y-coordinate pair, expressed as an unsigned 32-bit integer value, in two-dimensional space.
    /// <para>(Also see DirectX SDK: D2D1_POINT_2U)</para>
    /// </summary>
    public value struct Point2U
    {
    public:


        /// <summary>
        /// Constructor for the Point2U value type
        /// </summary>
        /// <param name="x">Initializes the x field.</param>
        /// <param name="y">Initializes the y field.</param>
        Point2U(
            UINT32 x,
            UINT32 y
            );


        /// <summary>
        /// The x-coordinate value of the point. 
        /// </summary>
        UINT32 X;

        /// <summary>
        /// The y-coordinate value of the point. 
        /// </summary>
        UINT32 Y;

        static Boolean operator == ( Point2U a, Point2U b )
        {
            return 
                (a.X == b.X)  &&
                (a.Y == b.Y);
        }

        static Boolean operator != ( Point2U a, Point2U b )
        {
            return !(a == b);
        }

    internal:

        void CopyFrom(
            __in const D2D1_POINT_2U &point_2u
            );

        void CopyTo(
            __out D2D1_POINT_2U *ppoint_2u
            );

    };

    /// <summary>
    /// Represents a rectangle defined by the upper-left corner pair of coordinates (left,top) 
    /// and the lower-right corner pair of coordinates (right, bottom). 
    /// These coordinates are expressed as a 32-bit unsigned integer values.
    /// <para>(Also see DirectX SDK: D2D1_RECT_U)</para>
    /// </summary>
    public value struct RectU
    {
    public:

        /// <summary>
        /// Constructor for the RectU value type
        /// </summary>
        /// <param name="left">Initializes the left field.</param>
        /// <param name="top">Initializes the top field.</param>
        /// <param name="right">Initializes the right field.</param>
        /// <param name="bottom">Initializes the bottom field.</param>
        RectU(
            UINT32 left,
            UINT32 top,
            UINT32 right,
            UINT32 bottom
            );


        /// <summary>
        /// The x-coordinate of the upper-left corner of the rectangle.
        /// </summary>
        UINT32 Left;

        /// <summary>
        /// The y-coordinate of the upper-left corner of the rectangle. 
        /// </summary>
        UINT32 Top;

        /// <summary>
        /// The x-coordinate of the lower-right corner of the rectangle. 
        /// </summary>
        UINT32 Right;

        /// <summary>
        /// The y-coordinate of the lower-right corner of the rectangle. 
        /// </summary>
        UINT32 Bottom;

        /// <summary>
        /// The height of this rectangle. 
        /// </summary>
        /// <remarks>
        /// Changing the Height property will also cause a change in the Bottom value.
        /// </remarks>
        property UINT32 Height
        {
            UINT32 get()
            {
                return static_cast<UINT32>(Math::Abs((int)(Bottom - Top)));
            }

            void set(UINT32 value)
            {
                Bottom = Top + value;
            }

        }

        /// <summary>
        /// Retrieve the width of this rectangle. 
        /// </summary>
        /// <remarks>
        /// Changing the Width property will also cause a change in the Right value.
        /// </remarks>
        property UINT32 Width
        {
            UINT32 get()
            {
                return static_cast<UINT32>(Math::Abs((int)(Left - Right)));
            }

            void set(UINT32 value)
            {
                Right = Left + value;
            }
        }

        static Boolean operator == ( RectU a, RectU b )
        {
            return 
                (a.Left == b.Left)  &&
                (a.Top == b.Top)  &&
                (a.Right == b.Right)  &&
                (a.Bottom == b.Bottom);
        }

        static Boolean operator != ( RectU a, RectU b )
        {
            return !(a == b);
        }


    internal:

        void CopyFrom(
            __in const D2D1_RECT_U &rect_u
            );

        void CopyTo(
            __out D2D1_RECT_U *prect_u
            );

    };


    /// <summary>
    /// Represents a rectangle defined by the upper-left corner pair of coordinates (left,top) 
    /// and the lower-right corner pair of coordinates (right, bottom). 
    /// These coordinates are expressed as a 32-bit signed integer values.
    /// </summary>
    public value struct Rect
    {
    public:

        /// <summary>
        /// Constructor for the Rect value type
        /// </summary>
        /// <param name="left">Initializes the left field.</param>
        /// <param name="top">Initializes the top field.</param>
        /// <param name="right">Initializes the right field.</param>
        /// <param name="bottom">Initializes the bottom field.</param>
        Rect(
            int left,
            int top,
            int right,
            int bottom
            );


        /// <summary>
        /// The x-coordinate of the upper-left corner of the rectangle.
        /// </summary>
        int Left;

        /// <summary>
        /// The y-coordinate of the upper-left corner of the rectangle. 
        /// </summary>
        int Top;

        /// <summary>
        /// The x-coordinate of the lower-right corner of the rectangle. 
        /// </summary>
        int Right;

        /// <summary>
        /// The y-coordinate of the lower-right corner of the rectangle. 
        /// </summary>
        int Bottom;

        /// <summary>
        /// The height of this rectangle. 
        /// </summary>
        /// <remarks>
        /// Changing the Height property will also cause a change in the Bottom value.
        /// </remarks>
        property int Height
        {
            int get()
            {
                return Math::Abs(Bottom - Top);
            }

            void set(int value)
            {
                Bottom = Top + value;
            }

        }

        /// <summary>
        /// Retrieve the width of this rectangle. 
        /// </summary>
        /// <remarks>
        /// Changing the Width property will also cause a change in the Right value.
        /// </remarks>
        property int Width
        {
            int get()
            {
                return Math::Abs(Left - Right);
            }

            void set(int value)
            {
                Right = Left + value;
            }
        }


        static Boolean operator == ( Rect a, Rect b )
        {
            return 
                (a.Left == b.Left)  &&
                (a.Top == b.Top)  &&
                (a.Right == b.Right)  &&
                (a.Bottom == b.Bottom);
        }

        static Boolean operator != ( Rect a, Rect b )
        {
            return !(a == b);
        }


    internal:

        void CopyFrom(
            __in const ::RECT &rect
            );

        void CopyTo(
            __out ::RECT *prect
            );

    };


    /// <summary>
    /// Define horizontal and vertical Dpi settings.
    /// </summary>
    public value struct DpiF
    {
    public:


        /// <summary>
        /// Constructor for the DpiF value type
        /// </summary>
        /// <param name="x">Initializes the x field.</param>
        /// <param name="y">Initializes the y field.</param>
        DpiF(
            FLOAT x,
            FLOAT y
            );


        /// <summary>
        /// The horizontal Dpi setting.
        /// </summary>
        FLOAT X;

        /// <summary>
        /// The vertical Dpi setting.
        /// </summary>
        FLOAT Y;


        static Boolean operator == ( DpiF a, DpiF b )
        {
            return 
                (a.X == b.X)  &&
                (a.Y == b.Y);
        }

        static Boolean operator != ( DpiF a, DpiF b )
        {
            return !(a == b);
        }

    };

} } } }

