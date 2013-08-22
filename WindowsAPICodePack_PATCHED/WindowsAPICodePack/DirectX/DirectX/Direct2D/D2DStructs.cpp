// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "LibraryLoader.h"

typedef void (*D2D1MakeRotateMatrixFuncPtr)
(
 FLOAT angle,
 D2D1_POINT_2F center,
 D2D1_MATRIX_3X2_F *matrix
 );

typedef void (*D2D1MakeSkewMatrixFuncPtr)
(
 FLOAT angleX,
 FLOAT angleY,
 D2D1_POINT_2F center,
 D2D1_MATRIX_3X2_F *matrix
 );

namespace Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct2D1 {

    namespace D2D = Microsoft::WindowsAPICodePack::DirectX::Direct2D1;


    ArcSegment::ArcSegment(
        Point2F point,
        SizeF size,
        FLOAT rotationangle,
        D2D::SweepDirection sweepdirection,
        D2D::ArcSize arcsize
        ) : 
    Point(point),
        Size(size),
        RotationAngle(rotationangle),
        SweepDirection(sweepdirection),
        ArcSize(arcsize)
    {
    }

    void ArcSegment::CopyFrom(
        __in const D2D1_ARC_SEGMENT &arc_segment
        )
    {
        Point.CopyFrom(arc_segment.point);
        Size.CopyFrom(arc_segment.size);
        RotationAngle = arc_segment.rotationAngle;
        SweepDirection = static_cast<D2D::SweepDirection>(static_cast<D2D1_SWEEP_DIRECTION>(arc_segment.sweepDirection));
        ArcSize = static_cast<D2D::ArcSize>(static_cast<D2D1_ARC_SIZE>(arc_segment.arcSize));
    }

    void ArcSegment::CopyTo(
        __out D2D1_ARC_SEGMENT *parc_segment
        )
    {
        Point.CopyTo(&parc_segment->point);
        Size.CopyTo(&parc_segment->size);
        parc_segment->rotationAngle = RotationAngle;
        parc_segment->sweepDirection = static_cast<D2D1_SWEEP_DIRECTION>(SweepDirection);
        parc_segment->arcSize = static_cast<D2D1_ARC_SIZE>(ArcSize);
    }

    BezierSegment::BezierSegment(
        Point2F point1,
        Point2F point2,
        Point2F point3
        ) : 
    Point1(point1),
        Point2(point2),
        Point3(point3)
    {
    }

    void BezierSegment::CopyFrom(
        __in const D2D1_BEZIER_SEGMENT &bezier_segment
        )
    {
        Point1.CopyFrom(bezier_segment.point1);
        Point2.CopyFrom(bezier_segment.point2);
        Point3.CopyFrom(bezier_segment.point3);
    }

    void BezierSegment::CopyTo(
        __out D2D1_BEZIER_SEGMENT *pbezier_segment
        )
    {
        Point1.CopyTo(&pbezier_segment->point1);
        Point2.CopyTo(&pbezier_segment->point2);
        Point3.CopyTo(&pbezier_segment->point3);
    }

    Triangle::Triangle(
        Point2F point1,
        Point2F point2,
        Point2F point3
        ) : 
    Point1(point1),
        Point2(point2),
        Point3(point3)
    {
    }

    void Triangle::CopyFrom(
        __in const D2D1_TRIANGLE &triangle
        )
    {
        Point1.CopyFrom(triangle.point1);
        Point2.CopyFrom(triangle.point2);
        Point3.CopyFrom(triangle.point3);
    }

    void Triangle::CopyTo(
        __out D2D1_TRIANGLE *ptriangle
        )
    {
        Point1.CopyTo(&ptriangle->point1);
        Point2.CopyTo(&ptriangle->point2);
        Point3.CopyTo(&ptriangle->point3);
    }

    DrawingStateDescription::DrawingStateDescription(
        D2D::AntialiasMode antialiasmode,
        D2D::TextAntialiasMode textantialiasmode,
        D2D::Tags tags,
        Matrix3x2F transform
        ) : 
    AntialiasMode(antialiasmode),
        TextAntialiasMode(textantialiasmode),
        Tags(tags),
        Transform(transform)
    {
    }

    void DrawingStateDescription::CopyFrom(
        __in const D2D1_DRAWING_STATE_DESCRIPTION &drawing_state_description
        )
    {
        AntialiasMode = static_cast<D2D::AntialiasMode>(static_cast<D2D1_ANTIALIAS_MODE>(drawing_state_description.antialiasMode));
        TextAntialiasMode = static_cast<D2D::TextAntialiasMode>(static_cast<D2D1_TEXT_ANTIALIAS_MODE>(drawing_state_description.textAntialiasMode));
        Tags = D2D::Tags(static_cast<UINT64>(drawing_state_description.tag1),static_cast<UINT64>(drawing_state_description.tag2));
        Transform.CopyFrom(drawing_state_description.transform);
    }

    void DrawingStateDescription::CopyTo(
        __out D2D1_DRAWING_STATE_DESCRIPTION *pdrawing_state_description
        )
    {
        pdrawing_state_description->antialiasMode = static_cast<D2D1_ANTIALIAS_MODE>(AntialiasMode);
        pdrawing_state_description->textAntialiasMode = static_cast<D2D1_TEXT_ANTIALIAS_MODE>(TextAntialiasMode);
        pdrawing_state_description->tag1 = static_cast<D2D1_TAG>(Tags.Tag1);
        pdrawing_state_description->tag2 = static_cast<D2D1_TAG>(Tags.Tag2);
        Transform.CopyTo(&pdrawing_state_description->transform);
    }

    Ellipse::Ellipse(
        Point2F point,
        FLOAT radiusx,
        FLOAT radiusy
        ) : 
    Point(point),
        RadiusX(radiusx),
        RadiusY(radiusy)
    {
    }

    void Ellipse::CopyFrom(
        __in const D2D1_ELLIPSE &ellipse
        )
    {
        Point.CopyFrom(ellipse.point);
        RadiusX = ellipse.radiusX;
        RadiusY = ellipse.radiusY;
    }

    void Ellipse::CopyTo(
        __out D2D1_ELLIPSE *pellipse
        )
    {
        Point.CopyTo(&pellipse->point);
        pellipse->radiusX = RadiusX;
        pellipse->radiusY = RadiusY;
    }

    FactoryOptions::FactoryOptions(
        D2D::DebugLevel debuglevel
        ) : 
    DebugLevel(debuglevel)
    {
    }

    void FactoryOptions::CopyFrom(
        __in const D2D1_FACTORY_OPTIONS &factory_options
        )
    {
        DebugLevel = static_cast<D2D::DebugLevel>(static_cast<D2D1_DEBUG_LEVEL>(factory_options.debugLevel));
    }

    void FactoryOptions::CopyTo(
        __out D2D1_FACTORY_OPTIONS *pfactory_options
        )
    {
        pfactory_options->debugLevel = static_cast<D2D1_DEBUG_LEVEL>(DebugLevel);
    }

    GradientStop::GradientStop(
        FLOAT position,
        ColorF color
        ) : 
    Position(position),
        Color(color)
    {
    }

    void GradientStop::CopyFrom(
        __in const D2D1_GRADIENT_STOP &gradient_stop
        )
    {
        Position = gradient_stop.position;
        Color.CopyFrom(gradient_stop.color);
    }

    void GradientStop::CopyTo(
        __out D2D1_GRADIENT_STOP *pgradient_stop
        )
    {
        pgradient_stop->position = Position;
        Color.CopyTo(&pgradient_stop->color);
    }

    HwndRenderTargetProperties::HwndRenderTargetProperties(
        IntPtr windowHandle,
        SizeU pixelsize,
        D2D::PresentOptions presentoptions
        ) : 
    WindowHandle(windowHandle),
        PixelSize(pixelsize),
        PresentOptions(presentoptions)
    {
    }

    void HwndRenderTargetProperties::CopyFrom(
        __in const D2D1_HWND_RENDER_TARGET_PROPERTIES &hwnd_render_target_properties
        )
    {
        WindowHandle = IntPtr(hwnd_render_target_properties.hwnd);
        PixelSize.CopyFrom(hwnd_render_target_properties.pixelSize);
        PresentOptions = static_cast<D2D::PresentOptions>(hwnd_render_target_properties.presentOptions);
    }

    void HwndRenderTargetProperties::CopyTo(
        __out D2D1_HWND_RENDER_TARGET_PROPERTIES *phwnd_render_target_properties
        )
    {
        phwnd_render_target_properties->hwnd = static_cast<HWND>(WindowHandle.ToPointer());
        PixelSize.CopyTo(&phwnd_render_target_properties->pixelSize);
        phwnd_render_target_properties->presentOptions = static_cast<D2D1_PRESENT_OPTIONS>(PresentOptions);
    }

    LayerParameters::LayerParameters(
        RectF contentbounds,
        Geometry ^geometricmask,
        AntialiasMode maskantialiasmode,
        Matrix3x2F masktransform,
        FLOAT opacity,
        Brush ^opacitybrush,
        LayerOptions layeroptions
        ) : 
    ContentBounds(contentbounds),
        GeometricMask(geometricmask),
        MaskAntialiasMode(maskantialiasmode),
        MaskTransform(masktransform),
        Opacity(opacity),
        OpacityBrush(opacitybrush),
        Options(layeroptions)
    {
    }

    void LayerParameters::CopyFrom(
        __in const D2D1_LAYER_PARAMETERS &layer_parameters
        )
    {
        ContentBounds.CopyFrom(layer_parameters.contentBounds);
        GeometricMask = layer_parameters.geometricMask ? gcnew Geometry(layer_parameters.geometricMask) : nullptr;
        MaskAntialiasMode = static_cast<AntialiasMode>(static_cast<D2D1_ANTIALIAS_MODE>(layer_parameters.maskAntialiasMode));
        MaskTransform.CopyFrom(layer_parameters.maskTransform);
        Opacity = layer_parameters.opacity;
        OpacityBrush = layer_parameters.opacityBrush ? gcnew Brush(layer_parameters.opacityBrush) : nullptr;
        Options = static_cast<LayerOptions>(static_cast<D2D1_LAYER_OPTIONS>(layer_parameters.layerOptions));
    }

    void LayerParameters::CopyTo(
        __out D2D1_LAYER_PARAMETERS *player_parameters
        )
    {
        ContentBounds.CopyTo(&player_parameters->contentBounds);
        OverwriteInterface(player_parameters->geometricMask, GeometricMask ? GeometricMask->GetInterface<ID2D1Geometry>() : NULL);
        player_parameters->maskAntialiasMode = static_cast<D2D1_ANTIALIAS_MODE>(MaskAntialiasMode);
        MaskTransform.CopyTo(&player_parameters->maskTransform);
        player_parameters->opacity = Opacity;
        OverwriteInterface(player_parameters->opacityBrush, OpacityBrush ? OpacityBrush->GetInterface<ID2D1Brush>() : NULL);
        player_parameters->layerOptions = static_cast<D2D1_LAYER_OPTIONS>(Options);
    }

    QuadraticBezierSegment::QuadraticBezierSegment(
        Point2F point1,
        Point2F point2
        ) : 
    Point1(point1),
        Point2(point2)
    {
    }

    void QuadraticBezierSegment::CopyFrom(
        __in const D2D1_QUADRATIC_BEZIER_SEGMENT &quadratic_bezier_segment
        )
    {
        Point1.CopyFrom(quadratic_bezier_segment.point1);
        Point2.CopyFrom(quadratic_bezier_segment.point2);
    }

    void QuadraticBezierSegment::CopyTo(
        __out D2D1_QUADRATIC_BEZIER_SEGMENT *pquadratic_bezier_segment
        )
    {
        Point1.CopyTo(&pquadratic_bezier_segment->point1);
        Point2.CopyTo(&pquadratic_bezier_segment->point2);
    }

    RoundedRect::RoundedRect(
        RectF rect,
        FLOAT radiusx,
        FLOAT radiusy
        ) : 
    Rect(rect),
        RadiusX(radiusx),
        RadiusY(radiusy)
    {
    }

    void RoundedRect::CopyFrom(
        __in const D2D1_ROUNDED_RECT &rounded_rect
        )
    {
        Rect.CopyFrom(rounded_rect.rect);
        RadiusX = rounded_rect.radiusX;
        RadiusY = rounded_rect.radiusY;
    }

    void RoundedRect::CopyTo(
        __out D2D1_ROUNDED_RECT *prounded_rect
        )
    {
        Rect.CopyTo(&prounded_rect->rect);
        prounded_rect->radiusX = RadiusX;
        prounded_rect->radiusY = RadiusY;
    }

    BrushProperties::BrushProperties(
        FLOAT opacity,
        Matrix3x2F transform
        ) : 
    Opacity(opacity),
        Transform(transform)
    {
    }

    void BrushProperties::CopyFrom(
        __in const D2D1_BRUSH_PROPERTIES &brush_properties
        )
    {
        Opacity = brush_properties.opacity;
        Transform.CopyFrom(brush_properties.transform);
    }

    void BrushProperties::CopyTo(
        __out D2D1_BRUSH_PROPERTIES *pbrush_properties
        )
    {
        pbrush_properties->opacity = Opacity;
        Transform.CopyTo(&pbrush_properties->transform);
    }

    LinearGradientBrushProperties::LinearGradientBrushProperties(
        Point2F startpoint,
        Point2F endpoint
        ) : 
    StartPoint(startpoint),
        EndPoint(endpoint)
    {
    }

    void LinearGradientBrushProperties::CopyFrom(
        __in const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES &linear_gradient_brush_properties
        )
    {
        StartPoint.CopyFrom(linear_gradient_brush_properties.startPoint);
        EndPoint.CopyFrom(linear_gradient_brush_properties.endPoint);
    }

    void LinearGradientBrushProperties::CopyTo(
        __out D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *plinear_gradient_brush_properties
        )
    {
        StartPoint.CopyTo(&plinear_gradient_brush_properties->startPoint);
        EndPoint.CopyTo(&plinear_gradient_brush_properties->endPoint);
    }

    BitmapBrushProperties::BitmapBrushProperties(
        ExtendMode extendmodex,
        ExtendMode extendmodey,
        BitmapInterpolationMode interpolationmode
        ) : 
    ExtendModeX(extendmodex),
        ExtendModeY(extendmodey),
        InterpolationMode(interpolationmode)
    {
    }

    void BitmapBrushProperties::CopyFrom(
        __in const D2D1_BITMAP_BRUSH_PROPERTIES &bitmap_brush_properties
        )
    {
        ExtendModeX = static_cast<ExtendMode>(static_cast<D2D1_EXTEND_MODE>(bitmap_brush_properties.extendModeX));
        ExtendModeY = static_cast<ExtendMode>(static_cast<D2D1_EXTEND_MODE>(bitmap_brush_properties.extendModeY));
        InterpolationMode = static_cast<BitmapInterpolationMode>(static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(bitmap_brush_properties.interpolationMode));
    }

    void BitmapBrushProperties::CopyTo(
        __out D2D1_BITMAP_BRUSH_PROPERTIES *pbitmap_brush_properties
        )
    {
        pbitmap_brush_properties->extendModeX = static_cast<D2D1_EXTEND_MODE>(ExtendModeX);
        pbitmap_brush_properties->extendModeY = static_cast<D2D1_EXTEND_MODE>(ExtendModeY);
        pbitmap_brush_properties->interpolationMode = static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(InterpolationMode);
    }

    PixelFormat::PixelFormat(
        Microsoft::WindowsAPICodePack::DirectX::DXGI::Format format,
        D2D::AlphaMode alphamode
        ) : 
    Format(format),
        AlphaMode(alphamode)
    {
    }

    void PixelFormat::CopyFrom(
        __in const D2D1_PIXEL_FORMAT &pixel_format
        )
    {
        Format = static_cast<Microsoft::WindowsAPICodePack::DirectX::DXGI::Format>(pixel_format.format);
        AlphaMode = static_cast<D2D::AlphaMode>(pixel_format.alphaMode);
    }

    void PixelFormat::CopyTo(
        __out D2D1_PIXEL_FORMAT *ppixel_format
        )
    {
        ppixel_format->format = static_cast<::DXGI_FORMAT>(Format);
        ppixel_format->alphaMode = static_cast<D2D1_ALPHA_MODE>(AlphaMode);
    }

    StrokeStyleProperties::StrokeStyleProperties(
        CapStyle startcap,
        CapStyle endcap,
        CapStyle dashcap,
        D2D::LineJoin linejoin,
        FLOAT miterlimit,
        D2D::DashStyle dashstyle,
        FLOAT dashoffset
        ) : 
    StartCap(startcap),
        EndCap(endcap),
        DashCap(dashcap),
        LineJoin(linejoin),
        MiterLimit(miterlimit),
        DashStyle(dashstyle),
        DashOffset(dashoffset)
    {
    }

    void StrokeStyleProperties::CopyFrom(
        __in const D2D1_STROKE_STYLE_PROPERTIES &stroke_style_properties
        )
    {
        StartCap = static_cast<CapStyle>(static_cast<D2D1_CAP_STYLE>(stroke_style_properties.startCap));
        EndCap = static_cast<CapStyle>(static_cast<D2D1_CAP_STYLE>(stroke_style_properties.endCap));
        DashCap = static_cast<CapStyle>(static_cast<D2D1_CAP_STYLE>(stroke_style_properties.dashCap));
        this->LineJoin = static_cast<D2D::LineJoin>(static_cast<D2D1_LINE_JOIN>(stroke_style_properties.lineJoin));
        MiterLimit = stroke_style_properties.miterLimit;
        this->DashStyle = static_cast<D2D::DashStyle>(static_cast<D2D1_DASH_STYLE>(stroke_style_properties.dashStyle));
        DashOffset = stroke_style_properties.dashOffset;
    }

    void StrokeStyleProperties::CopyTo(
        __out D2D1_STROKE_STYLE_PROPERTIES *pstroke_style_properties
        )
    {
        pstroke_style_properties->startCap = static_cast<D2D1_CAP_STYLE>(StartCap);
        pstroke_style_properties->endCap = static_cast<D2D1_CAP_STYLE>(EndCap);
        pstroke_style_properties->dashCap = static_cast<D2D1_CAP_STYLE>(DashCap);
        pstroke_style_properties->lineJoin = static_cast<D2D1_LINE_JOIN>(LineJoin);
        pstroke_style_properties->miterLimit = MiterLimit;
        pstroke_style_properties->dashStyle = static_cast<D2D1_DASH_STYLE>(DashStyle);
        pstroke_style_properties->dashOffset = DashOffset;
    }

    RadialGradientBrushProperties::RadialGradientBrushProperties(
        Point2F center,
        Point2F gradientoriginoffset,
        FLOAT radiusx,
        FLOAT radiusy
        ) : 
    Center(center),
        GradientOriginOffset(gradientoriginoffset),
        RadiusX(radiusx),
        RadiusY(radiusy)
    {
    }

    void RadialGradientBrushProperties::CopyFrom(
        __in const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES &radial_gradient_brush_properties
        )
    {
        Center.CopyFrom(radial_gradient_brush_properties.center);
        GradientOriginOffset.CopyFrom(radial_gradient_brush_properties.gradientOriginOffset);
        RadiusX = radial_gradient_brush_properties.radiusX;
        RadiusY = radial_gradient_brush_properties.radiusY;
    }

    void RadialGradientBrushProperties::CopyTo(
        __out D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *pradial_gradient_brush_properties
        )
    {
        Center.CopyTo(&pradial_gradient_brush_properties->center);
        GradientOriginOffset.CopyTo(&pradial_gradient_brush_properties->gradientOriginOffset);
        pradial_gradient_brush_properties->radiusX = RadiusX;
        pradial_gradient_brush_properties->radiusY = RadiusY;
    }

    RenderTargetProperties::RenderTargetProperties(
        RenderTargetType type,
        D2D::PixelFormat pixelformat,
        FLOAT dpix,
        FLOAT dpiy,
        RenderTargetUsage usage,
        FeatureLevel minlevel
        ) : 
    Type(type),
        PixelFormat(pixelformat),
        DpiX(dpix),
        DpiY(dpiy),
        Usage(usage),
        MinLevel(minlevel)
    {
    }

    void RenderTargetProperties::CopyFrom(
        __in const D2D1_RENDER_TARGET_PROPERTIES &render_target_properties
        )
    {
        Type = static_cast<RenderTargetType>(static_cast<D2D1_RENDER_TARGET_TYPE>(render_target_properties.type));
        this->PixelFormat.CopyFrom(render_target_properties.pixelFormat);
        DpiX = render_target_properties.dpiX;
        DpiY = render_target_properties.dpiY;
        Usage = static_cast<RenderTargetUsage>(static_cast<D2D1_RENDER_TARGET_USAGE>(render_target_properties.usage));
        MinLevel = static_cast<FeatureLevel>(static_cast<D2D1_FEATURE_LEVEL>(render_target_properties.minLevel));
    }

    void RenderTargetProperties::CopyTo(
        __out D2D1_RENDER_TARGET_PROPERTIES *prender_target_properties
        )
    {
        prender_target_properties->type = static_cast<D2D1_RENDER_TARGET_TYPE>(Type);
        this->PixelFormat.CopyTo(&prender_target_properties->pixelFormat);
        prender_target_properties->dpiX = DpiX;
        prender_target_properties->dpiY = DpiY;
        prender_target_properties->usage = static_cast<D2D1_RENDER_TARGET_USAGE>(Usage);
        prender_target_properties->minLevel = static_cast<D2D1_FEATURE_LEVEL>(MinLevel);
    }

    BitmapProperties::BitmapProperties(
        D2D::PixelFormat pixelformat,
        FLOAT dpix,
        FLOAT dpiy
        ) : 
    PixelFormat(pixelformat),
        DpiX(dpix),
        DpiY(dpiy)
    {
    }

    void BitmapProperties::CopyFrom(
        __in const D2D1_BITMAP_PROPERTIES &bitmap_properties
        )
    {
        PixelFormat.CopyFrom(bitmap_properties.pixelFormat);
        DpiX = bitmap_properties.dpiX;
        DpiY = bitmap_properties.dpiY;
    }

    void BitmapProperties::CopyTo(
        __out D2D1_BITMAP_PROPERTIES *pbitmap_properties
        )
    {
        PixelFormat.CopyTo(&pbitmap_properties->pixelFormat);
        pbitmap_properties->dpiX = DpiX;
        pbitmap_properties->dpiY = DpiY;
    }

    ColorF::ColorF(
        FLOAT r,
        FLOAT g,
        FLOAT b,
        FLOAT a
        ) : 
    R(r),
        G(g),
        B(b),
        A(a)
    {
    }

    ColorF::ColorF(
        Colors color
        ) : R(static_cast<FLOAT>((static_cast<UINT32>(color) & sc_redMask) >> sc_redShift) / 255.f),
        G(static_cast<FLOAT>((static_cast<UINT32>(color) & sc_greenMask) >> sc_greenShift) / 255.f),
        B(static_cast<FLOAT>((static_cast<UINT32>(color) & sc_blueMask) >> sc_blueShift) / 255.f),
        A(1.0f)
    {
    }

    ColorF::ColorF(
        Colors color,
        FLOAT a
        ) : R(static_cast<FLOAT>((static_cast<UINT32>(color) & sc_redMask) >> sc_redShift) / 255.f),
        G(static_cast<FLOAT>((static_cast<UINT32>(color) & sc_greenMask) >> sc_greenShift) / 255.f),
        B(static_cast<FLOAT>((static_cast<UINT32>(color) & sc_blueMask) >> sc_blueShift) / 255.f),
        A(a)
    {
    }

    void ColorF::CopyFrom(
        __in const D2D1_COLOR_F &color_f
        )
    {
        R = color_f.r;
        G = color_f.g;
        B = color_f.b;
        A = color_f.a;
    }

    void ColorF::CopyTo(
        __out D2D1_COLOR_F *pcolor_f
        )
    {
        pcolor_f->r = R;
        pcolor_f->g = G;
        pcolor_f->b = B;
        pcolor_f->a = A;
    }

    Matrix3x2F::Matrix3x2F(
        FLOAT m11,
        FLOAT m12,
        FLOAT m21,
        FLOAT m22,
        FLOAT m31,
        FLOAT m32
        ) : 
    M11(m11),
        M12(m12),
        M21(m21),
        M22(m22),
        M31(m31),
        M32(m32)
    {
    }


    Matrix3x2F Matrix3x2F::Translation(
        SizeF size
        )
    {
        return Matrix3x2F(
            1.0f, 0.0f,
            0.0f, 1.0f,
            size.Width, size.Height);
    }

    Matrix3x2F Matrix3x2F::Translation(
        float x,
        float y
        )
    {
        return Translation(SizeF(x, y));
    }

    Matrix3x2F Matrix3x2F::Identity::get()
    {
        return Matrix3x2F(1, 0, 0, 1, 0, 0);
    }

    Matrix3x2F
        Matrix3x2F::Scale(
        SizeF size,
        Point2F center
        )
    {

        return Matrix3x2F(
            size.Width,
            0.0,
            0.0,
            size.Height,
            center.X - size.Width * center.X,
            center.Y - size.Height * center.Y);
    }

    Matrix3x2F
        Matrix3x2F::Scale(
        SizeF size
        )
    {
        return Scale(size,Point2F(0,0));
    }

    Matrix3x2F
        Matrix3x2F::Scale(
        FLOAT x,
        FLOAT y,
        Point2F center
        )
    {
        return Scale(SizeF(x, y), center);
    }

    Matrix3x2F
        Matrix3x2F::Scale(
        FLOAT x,
        FLOAT y
        )
    {
        return Scale(SizeF(x, y), Point2F(0, 0));
    }

    Matrix3x2F
        Matrix3x2F::Rotation(
        FLOAT angle,
        Point2F center
        )
    {
        D2D1_POINT_2F ptCopy;
        center.CopyTo(&ptCopy);

        Matrix3x2F rotation;
        pin_ptr<Matrix3x2F> ptr = &rotation;

        D2D1MakeRotateMatrixFuncPtr funcPtr = 
            (D2D1MakeRotateMatrixFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D2DLibrary, "D2D1MakeRotateMatrix");

        (*funcPtr)(angle, ptCopy, (D2D_MATRIX_3X2_F*) ptr);

        return rotation;
    }

    Matrix3x2F
        Matrix3x2F::Rotation(
        FLOAT angle
        )
    {
        return Rotation(angle, Point2F(0,0));
    }

    Matrix3x2F
        Matrix3x2F::Skew(
        FLOAT angleX,
        FLOAT angleY,
        Point2F center
        )
    {
        D2D1_POINT_2F ptCopy;
        center.CopyTo(&ptCopy);

        Matrix3x2F skew;
        pin_ptr<Matrix3x2F> ptr = &skew;

        D2D1MakeSkewMatrixFuncPtr funcPtr = 
            (D2D1MakeSkewMatrixFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            D2DLibrary, "D2D1MakeSkewMatrix");

        (*funcPtr)(angleX, angleY, ptCopy, (D2D_MATRIX_3X2_F*) ptr);

        return skew;
    }

    Matrix3x2F
        Matrix3x2F::Skew(
        FLOAT angleX,
        FLOAT angleY            
        )
    {
        return Skew(angleX, angleY, Point2F(0,0));
    }

    bool Matrix3x2F::IsIdentity::get()
    {
        return     M11 == 1 && M12 == 0
            && M21 == 0 && M22 == 1
            && M31 == 0 && M32 == 0;
    }

    void Matrix3x2F::CopyFrom(
        __in const D2D1_MATRIX_3X2_F &matrix_3x2_f
        )
    {
        pin_ptr<Matrix3x2F> pinned = this;
        memcpy(pinned, &matrix_3x2_f, sizeof(D2D1_MATRIX_3X2_F));
    }

    void Matrix3x2F::CopyTo(
        __out D2D1_MATRIX_3X2_F *pmatrix_3x2_f
        )
    {
        pin_ptr<Matrix3x2F> pinned = this;
        memcpy(pmatrix_3x2_f, pinned, sizeof(D2D1_MATRIX_3X2_F));
    }

    Point2U::Point2U(
        UINT32 x,
        UINT32 y
        ) : 
    X(x),
        Y(y)
    {
    }

    void Point2U::CopyFrom(
        __in const D2D1_POINT_2U &point_2u
        )
    {
        X = point_2u.x;
        Y = point_2u.y;
    }

    void Point2U::CopyTo(
        __out D2D1_POINT_2U *ppoint_2u
        )
    {
        ppoint_2u->x = X;
        ppoint_2u->y = Y;
    }

    Point2F::Point2F(
        FLOAT x,
        FLOAT y
        ) : 
    X(x),
        Y(y)
    {
    }

    void Point2F::CopyFrom(
        __in const D2D1_POINT_2F &point_2f
        )
    {
        X = point_2f.x;
        Y = point_2f.y;
    }

    void Point2F::CopyTo(
        __out D2D1_POINT_2F *ppoint_2f
        )
    {
        ppoint_2f->x = X;
        ppoint_2f->y = Y;
    }

    DpiF::DpiF(
        FLOAT x,
        FLOAT y
        ) : 
    X(x),
        Y(y)
    {
    }

    RectF::RectF(
        FLOAT left,
        FLOAT top,
        FLOAT right,
        FLOAT bottom
        ) : 
    Left(left),
        Top(top),
        Right(right),
        Bottom(bottom)
    {
    }

    void RectF::CopyFrom(
        __in const D2D1_RECT_F &rect_f
        )
    {
        pin_ptr<RectF> pinned = this;
        memcpy(pinned, &rect_f, sizeof(D2D1_RECT_F));
    }

    void RectF::CopyTo(
        __out D2D1_RECT_F *prect_f
        )
    {
        pin_ptr<RectF> pinned = this;
        memcpy(prect_f, pinned, sizeof(D2D1_RECT_F));
    }

    RectU::RectU(
        UINT32 left,
        UINT32 top,
        UINT32 right,
        UINT32 bottom
        ) : 
    Left(left),
        Top(top),
        Right(right),
        Bottom(bottom)
    {
    }

    void RectU::CopyFrom(
        __in const D2D1_RECT_U &rect_u
        )
    {
        Left = rect_u.left;
        Top = rect_u.top;
        Right = rect_u.right;
        Bottom = rect_u.bottom;
    }

    void RectU::CopyTo(
        __out D2D1_RECT_U *prect_u
        )
    {
        prect_u->left = Left;
        prect_u->top = Top;
        prect_u->right = Right;
        prect_u->bottom = Bottom;
    }

    SizeF::SizeF(
        FLOAT width,
        FLOAT height
        ) : 
    Width(width),
        Height(height)
    {
    }

    void SizeF::CopyFrom(
        __in const D2D1_SIZE_F &size_f
        )
    {
        Width = size_f.width;
        Height = size_f.height;
    }

    void SizeF::CopyTo(
        __out D2D1_SIZE_F *psize_f
        )
    {
        psize_f->width = Width;
        psize_f->height = Height;
    }

    SizeU::SizeU(
        UINT32 width,
        UINT32 height
        ) : 
    Width(width),
        Height(height)
    {
    }

    void SizeU::CopyFrom(
        __in const D2D1_SIZE_U &size_u
        )
    {
        Width = size_u.width;
        Height = size_u.height;
    }

    void SizeU::CopyTo(
        __out D2D1_SIZE_U *psize_u
        )
    {
        psize_u->width = Width;
        psize_u->height = Height;
    }

    Rect::Rect(
        int left,
        int top,
        int right,
        int bottom
        ) : 
    Left(left),
        Top(top),
        Right(right),
        Bottom(bottom)
    {
    }

    void Rect::CopyFrom(
        __in const ::RECT &rect
        )
    {
        Left = rect.left;
        Top = rect.top;
        Right = rect.right;
        Bottom = rect.bottom;
    }

    void Rect::CopyTo(
        __out ::RECT *prect
        )
    {
        prect->left = Left;
        prect->top = Top;
        prect->right = Right;
        prect->bottom = Bottom;
    }

} } } }

