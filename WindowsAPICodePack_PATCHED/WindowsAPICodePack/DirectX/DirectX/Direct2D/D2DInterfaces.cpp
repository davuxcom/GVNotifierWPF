// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include <vector>

#include "WIC/WICBitmapSource.h"
#include "WIC/WICBitmap.h"
#include "WIC/WICBitmapLock.h"
#include "DXGI/DXGISurface.h"
#include "DirectWrite/DWriteTextFormat.h"
#include "DirectWrite/DWriteTextLayout.h"
#include "DirectWrite/DWriteRenderingParams.h"

using namespace std;
using namespace Microsoft::WindowsAPICodePack::DirectX::WindowsImagingComponent;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

namespace Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct2D1 {

D2DResource::D2DResource(
    ) : DirectUnknown()
{
}

D2DResource::D2DResource(
    IUnknown *pInner
    ) : DirectUnknown(pInner)
{
}

D2DFactory ^
D2DResource::GetFactory(
    )
{
    ID2D1Factory * factory = NULL;
    GetInterface<ID2D1Resource>()->GetFactory(&factory);
    return factory ? gcnew D2DFactory(factory) : nullptr;
}

D2DBitmap::D2DBitmap(
    ) : D2DResource()
{
}

D2DBitmap::D2DBitmap(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

SizeF
D2DBitmap::Size::get()
{
    D2D1_SIZE_F returnCopy;

    returnCopy =
        GetInterface<ID2D1Bitmap>()->GetSize(
            );


    SizeF returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

SizeU
D2DBitmap::PixelSize::get()
{
    D2D1_SIZE_U returnCopy;

    returnCopy =
        GetInterface<ID2D1Bitmap>()->GetPixelSize(
            );


    SizeU returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

D2D::PixelFormat
D2DBitmap::PixelFormat::get(
    )
{
    D2D1_PIXEL_FORMAT returnCopy;

    returnCopy =
        GetInterface<ID2D1Bitmap>()->GetPixelFormat(
            );


    D2D::PixelFormat returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

DpiF
D2DBitmap::Dpi::get(
    )
{
    ::FLOAT dpiXCopy;
    ::FLOAT dpiYCopy;

        GetInterface<ID2D1Bitmap>()->GetDpi(
            &dpiXCopy,
            &dpiYCopy
            );

    return DpiF(dpiXCopy, dpiYCopy);
}


void
D2DBitmap::CopyFromBitmap(
    D2DBitmap ^ bitmap,
    Point2U destPoint,
    RectU srcRect
    )
{
    D2D1_POINT_2U destPointCopy;
    destPoint.CopyTo(&destPointCopy);

    D2D1_RECT_U srcRectCopy;
    srcRect.CopyTo(&srcRectCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromBitmap(
            &destPointCopy,
            bitmap->GetInterface<ID2D1Bitmap>(),
            &srcRectCopy
            ));
}

void
D2DBitmap::CopyFromBitmap(
    D2DBitmap ^ bitmap,
    Point2U destPoint
    )
{
    D2D1_POINT_2U destPointCopy;
    destPoint.CopyTo(&destPointCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromBitmap(
            &destPointCopy,
            bitmap->GetInterface<ID2D1Bitmap>(),
            NULL
            ));
}

void
D2DBitmap::CopyFromBitmap(
    D2DBitmap ^ bitmap,
    RectU srcRect
    )
{
    D2D1_RECT_U srcRectCopy;
    srcRect.CopyTo(&srcRectCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromBitmap(
            NULL,
            bitmap->GetInterface<ID2D1Bitmap>(),
            &srcRectCopy
            ));
}

void
D2DBitmap::CopyFromBitmap(
    D2DBitmap ^ bitmap
    )
{
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromBitmap(
            NULL,
            bitmap->GetInterface<ID2D1Bitmap>(),
            NULL
            ));
}

void
D2DBitmap::CopyFromRenderTarget(
    RenderTarget ^ renderTarget,
    Point2U destPoint,
    RectU srcRect
    )
{
    D2D1_POINT_2U destPointCopy;
    destPoint.CopyTo(&destPointCopy);

    D2D1_RECT_U srcRectCopy;
    srcRect.CopyTo(&srcRectCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromRenderTarget(
            &destPointCopy,
            renderTarget->GetInterface<ID2D1RenderTarget>(),
            &srcRectCopy
            ));
}

void
D2DBitmap::CopyFromRenderTarget(
    RenderTarget ^ renderTarget
    )
{
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromRenderTarget(
            NULL,
            renderTarget->GetInterface<ID2D1RenderTarget>(),
            NULL
            ));
}

void
D2DBitmap::CopyFromRenderTarget(
    RenderTarget ^ renderTarget,
    Point2U destPoint
    )
{
    D2D1_POINT_2U destPointCopy;
    destPoint.CopyTo(&destPointCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromRenderTarget(
            &destPointCopy,
            renderTarget->GetInterface<ID2D1RenderTarget>(),
            NULL
            ));
}

void
D2DBitmap::CopyFromRenderTarget(
    RenderTarget ^ renderTarget,
    RectU srcRect
    )
{
    D2D1_RECT_U srcRectCopy;
    srcRect.CopyTo(&srcRectCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromRenderTarget(
            NULL,
            renderTarget->GetInterface<ID2D1RenderTarget>(),
            &srcRectCopy
            ));
}

void
D2DBitmap::CopyFromMemory(
    RectU dstRect,
    IntPtr srcData,
    UINT32 pitch
    )
{
    D2D1_RECT_U dstRectCopy;
    dstRect.CopyTo(&dstRectCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromMemory(
            &dstRectCopy,
            srcData.ToPointer(),
            pitch
            ));
}

void
D2DBitmap::CopyFromMemory(
    IntPtr srcData,
    UINT32 pitch
    )
{
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromMemory(
            NULL,
            srcData.ToPointer(),
            pitch
            ));
}

void
D2DBitmap::CopyFromMemory(
    RectU dstRect,
    array<unsigned char>^ srcData,
    UINT32 pitch
    )
{
    D2D1_RECT_U dstRectCopy;
    dstRect.CopyTo(&dstRectCopy);

    pin_ptr<unsigned char> srcDataPtr = &srcData[0];

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromMemory(
            &dstRectCopy,
            srcDataPtr,
            pitch
            ));
}

void
D2DBitmap::CopyFromMemory(
    array<unsigned char>^ srcData,
    UINT32 pitch
    )
{
    pin_ptr<unsigned char> srcDataPtr = &srcData[0];

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Bitmap>()->CopyFromMemory(
            NULL,
            srcDataPtr,
            pitch
            ));
}

GradientStopCollection::GradientStopCollection(
    ) : D2DResource()
{
}

GradientStopCollection::GradientStopCollection(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

UINT32
GradientStopCollection::GradientStopCount::get(
    )
{
    return GetInterface<ID2D1GradientStopCollection>()->GetGradientStopCount();
}

ReadOnlyCollection<GradientStop>^
GradientStopCollection::GetGradientStops(
    )
{
    D2D1_GRADIENT_STOP *gradientStopsCopy = NULL;
    List<GradientStop> ^ gradientStops = gcnew List<GradientStop>();

    UINT32 count = GetInterface<ID2D1GradientStopCollection>()->GetGradientStopCount();
    
    if (count > 0)
    {
        vector<D2D1_GRADIENT_STOP> gradientStopsCopy(count);
        ZeroMemory(&gradientStopsCopy[0], sizeof(D2D1_GRADIENT_STOP) * (count));
        
        GetInterface<ID2D1GradientStopCollection>()->GetGradientStops(
            &gradientStopsCopy[0],
            count
            );

        for(UINT i = 0; i <  count; ++i)
        {
            GradientStop gradientStop;
            gradientStop.CopyFrom(gradientStopsCopy[i]);
            gradientStops->Add(gradientStop);
        }
    }

    return gcnew ReadOnlyCollection<GradientStop>(gradientStops);
}

Gamma
GradientStopCollection::ColorInterpolationGamma::get(
    )
{
    return static_cast<Gamma>(GetInterface<ID2D1GradientStopCollection>()->GetColorInterpolationGamma());
}

D2D::ExtendMode
GradientStopCollection::ExtendMode::get(
    )
{
    return static_cast<D2D::ExtendMode>(GetInterface<ID2D1GradientStopCollection>()->GetExtendMode());
}

Brush::Brush(
    ) : D2DResource()
{
}

Brush::Brush(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

void
Brush::Opacity::set(
    FLOAT opacity)
{
        GetInterface<ID2D1Brush>()->SetOpacity(
            opacity
            );
}

void
Brush::Transform::set(
    Matrix3x2F transform
    )
{
    D2D1_MATRIX_3X2_F transformCopy;
    transform.CopyTo(&transformCopy);

        GetInterface<ID2D1Brush>()->SetTransform(
            &transformCopy
            );
}

FLOAT
Brush::Opacity::get(
    )
{
    return GetInterface<ID2D1Brush>()->GetOpacity(
            );
}

Matrix3x2F
Brush::Transform::get(
    )
{
    D2D1_MATRIX_3X2_F transformCopy;

    GetInterface<ID2D1Brush>()->GetTransform(
        &transformCopy
        );

    Matrix3x2F transform;
    transform.CopyFrom(transformCopy);

    return transform;

}

BitmapBrush::BitmapBrush(
    ) : Brush()
{
}

BitmapBrush::BitmapBrush(
    IUnknown *pInner
    ) : Brush(pInner)
{
}

void
BitmapBrush::ExtendModeX::set(
    ExtendMode extendModeX
    )
{
    GetInterface<ID2D1BitmapBrush>()->SetExtendModeX(
        static_cast<D2D1_EXTEND_MODE>(extendModeX)
        );
}

void
BitmapBrush::ExtendModeY::set(
    ExtendMode extendModeY
    )
{
    GetInterface<ID2D1BitmapBrush>()->SetExtendModeY(
        static_cast<D2D1_EXTEND_MODE>(extendModeY)
        );
}

void
BitmapBrush::InterpolationMode::set(
    BitmapInterpolationMode interpolationMode
    )
{
    GetInterface<ID2D1BitmapBrush>()->SetInterpolationMode(
        static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(interpolationMode)
        );
}

void
BitmapBrush::SetBitmap(
    D2DBitmap ^ bitmap
    )
{
    GetInterface<ID2D1BitmapBrush>()->SetBitmap(
        bitmap->GetInterface<ID2D1Bitmap>()
        );
}

ExtendMode
BitmapBrush::ExtendModeX::get(
    )
{
    return static_cast<ExtendMode>(GetInterface<ID2D1BitmapBrush>()->GetExtendModeX());
}

ExtendMode
BitmapBrush::ExtendModeY::get(
    )
{
    return static_cast<ExtendMode>(GetInterface<ID2D1BitmapBrush>()->GetExtendModeY());
}

BitmapInterpolationMode
BitmapBrush::InterpolationMode::get(
    )
{
    return static_cast<BitmapInterpolationMode>(GetInterface<ID2D1BitmapBrush>()->GetInterpolationMode());
}

D2DBitmap ^
BitmapBrush::GetBitmap(
    )
{
    ID2D1Bitmap * ptr = NULL;
    GetInterface<ID2D1BitmapBrush>()->GetBitmap(&ptr);
    return ptr ? gcnew D2DBitmap(ptr) : nullptr;

}

SolidColorBrush::SolidColorBrush(
    ) : Brush()
{
}

SolidColorBrush::SolidColorBrush(
    IUnknown *pInner
    ) : Brush(pInner)
{
}

void
SolidColorBrush::Color::set(
    ColorF color
    )
{
    D2D1_COLOR_F colorCopy;
    color.CopyTo(&colorCopy);

    GetInterface<ID2D1SolidColorBrush>()->SetColor(
        &colorCopy
        );
}

ColorF
SolidColorBrush::Color::get(
    )
{
    D2D1_COLOR_F returnCopy;

    returnCopy =
        GetInterface<ID2D1SolidColorBrush>()->GetColor(
            );


    ColorF returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

LinearGradientBrush::LinearGradientBrush(
    ) : Brush()
{
}

LinearGradientBrush::LinearGradientBrush(
    IUnknown *pInner
    ) : Brush(pInner)
{
}

void
LinearGradientBrush::StartPoint::set(
    Point2F startPoint
    )
{
    D2D1_POINT_2F startPointCopy;
    startPoint.CopyTo(&startPointCopy);

    GetInterface<ID2D1LinearGradientBrush>()->SetStartPoint(
        startPointCopy
        );
}

void
LinearGradientBrush::EndPoint::set(
    Point2F endPoint
    )
{
    D2D1_POINT_2F endPointCopy;
    endPoint.CopyTo(&endPointCopy);

    GetInterface<ID2D1LinearGradientBrush>()->SetEndPoint(
        endPointCopy
        );
}

Point2F
LinearGradientBrush::StartPoint::get(
    )
{
    D2D1_POINT_2F returnCopy =
        GetInterface<ID2D1LinearGradientBrush>()->GetStartPoint(
            );


    Point2F returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

Point2F
LinearGradientBrush::EndPoint::get(
    )
{
    D2D1_POINT_2F returnCopy =
        GetInterface<ID2D1LinearGradientBrush>()->GetEndPoint(
            );

    Point2F returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

GradientStopCollection ^
LinearGradientBrush::GetGradientStopCollection(
    )
{
    ID2D1GradientStopCollection * ptr = NULL;
    GetInterface<ID2D1LinearGradientBrush>()->GetGradientStopCollection(&ptr);
    return ptr ? gcnew GradientStopCollection(ptr) : nullptr;

}

RadialGradientBrush::RadialGradientBrush(
    ) : Brush()
{
}

RadialGradientBrush::RadialGradientBrush(
    IUnknown *pInner
    ) : Brush(pInner)
{
}

void
RadialGradientBrush::Center::set(
    Point2F center
    )
{
    D2D1_POINT_2F centerCopy;
    center.CopyTo(&centerCopy);

        GetInterface<ID2D1RadialGradientBrush>()->SetCenter(
            centerCopy
            );
}

void
RadialGradientBrush::GradientOriginOffset::set(
    Point2F gradientOriginOffset
    )
{
    D2D1_POINT_2F gradientOriginOffsetCopy;
    gradientOriginOffset.CopyTo(&gradientOriginOffsetCopy);

    GetInterface<ID2D1RadialGradientBrush>()->SetGradientOriginOffset(
        gradientOriginOffsetCopy
        );
}

void
RadialGradientBrush::RadiusX::set(
    FLOAT radiusX
    )
{

    GetInterface<ID2D1RadialGradientBrush>()->SetRadiusX(
        radiusX
        );


}

void
RadialGradientBrush::RadiusY::set(
    FLOAT radiusY
    )
{

    GetInterface<ID2D1RadialGradientBrush>()->SetRadiusY(
        radiusY
        );


}

Point2F
RadialGradientBrush::Center::get(
    )
{
    D2D1_POINT_2F returnCopy =
        GetInterface<ID2D1RadialGradientBrush>()->GetCenter(
            );

    Point2F returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

Point2F
RadialGradientBrush::GradientOriginOffset::get(
    )
{
    D2D1_POINT_2F returnCopy =
        GetInterface<ID2D1RadialGradientBrush>()->GetGradientOriginOffset(
            );

    Point2F returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

FLOAT
RadialGradientBrush::RadiusX::get(
    )
{
    return GetInterface<ID2D1RadialGradientBrush>()->GetRadiusX();
}

FLOAT
RadialGradientBrush::RadiusY::get(
    )
{
    return GetInterface<ID2D1RadialGradientBrush>()->GetRadiusY();
}

GradientStopCollection ^
RadialGradientBrush::GetGradientStopCollection(
    )
{
    ID2D1GradientStopCollection * ptr = NULL;
    GetInterface<ID2D1RadialGradientBrush>()->GetGradientStopCollection(&ptr);
    return ptr ? gcnew GradientStopCollection(ptr) : nullptr;
}

DrawingStateBlock::DrawingStateBlock(
    ) : D2DResource()
{
}

DrawingStateBlock::DrawingStateBlock(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

DrawingStateDescription
DrawingStateBlock::Description::get(
    )
{
    D2D1_DRAWING_STATE_DESCRIPTION stateDescriptionCopy;

        GetInterface<ID2D1DrawingStateBlock>()->GetDescription(
            &stateDescriptionCopy
            );

    DrawingStateDescription stateDescription;
    stateDescription.CopyFrom(stateDescriptionCopy);

    return stateDescription;

}

void
DrawingStateBlock::Description::set(
    DrawingStateDescription stateDescription
    )
{
    D2D1_DRAWING_STATE_DESCRIPTION stateDescriptionCopy;
    stateDescription.CopyTo(&stateDescriptionCopy);

        GetInterface<ID2D1DrawingStateBlock>()->SetDescription(
            &stateDescriptionCopy
            );
}

RenderingParams^ DrawingStateBlock::GetTextRenderingParams()
{
    IDWriteRenderingParams* renderingParams = NULL;
    GetInterface<ID2D1DrawingStateBlock>()->GetTextRenderingParams(&renderingParams);

    return renderingParams ? gcnew RenderingParams(renderingParams) : nullptr;
}

void DrawingStateBlock::SetTextRenderingParams(RenderingParams^ textRenderingParams)
{
    GetInterface<ID2D1DrawingStateBlock>()->SetTextRenderingParams(
        textRenderingParams == nullptr ? NULL : textRenderingParams->GetInterface<IDWriteRenderingParams>()
        );
}

RenderTarget::RenderTarget(
    ) : D2DResource()
{
}

RenderTarget::RenderTarget(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

D2DBitmap ^
RenderTarget::CreateBitmap(
    SizeU size,
    BitmapProperties bitmapProperties
    )
{
    D2D1_SIZE_U sizeCopy;
    size.CopyTo(&sizeCopy);

    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    ID2D1Bitmap * bitmapPtr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmap(
            sizeCopy,
            NULL,
            0,
            &bitmapPropertiesCopy,
            &bitmapPtr
            ));

    return bitmapPtr ? gcnew D2DBitmap(bitmapPtr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateBitmap(
    SizeU size,
    IntPtr sourceData,
    UINT32 pitch,
    BitmapProperties bitmapProperties
    )
{
    D2D1_SIZE_U sizeCopy;
    size.CopyTo(&sizeCopy);

    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    ID2D1Bitmap * bitmapPtr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmap(
            sizeCopy,
            sourceData.ToPointer(),
            pitch,
            &bitmapPropertiesCopy,
            &bitmapPtr
            ));

    return bitmapPtr ? gcnew D2DBitmap(bitmapPtr): nullptr;
}


D2DBitmap ^
RenderTarget::CreateBitmap(
    SizeU size,
    array<unsigned char>^ sourceBytes,
    UINT32 pitch,
    BitmapProperties bitmapProperties
    )
{
    D2D1_SIZE_U sizeCopy;
    size.CopyTo(&sizeCopy);

    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    pin_ptr<unsigned char> bytePtr = &sourceBytes[0];

    ID2D1Bitmap * bitmapPtr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmap(
            sizeCopy,
            bytePtr,
            pitch,
            &bitmapPropertiesCopy,
            &bitmapPtr
            ));

    return bitmapPtr ? gcnew D2DBitmap(bitmapPtr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateBitmapFromWicBitmap(
    BitmapSource^ wicBitmapSource,
    BitmapProperties bitmapProperties
    )
{
    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    ID2D1Bitmap * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmapFromWicBitmap(
            wicBitmapSource->GetInterface<IWICBitmapSource>(),
            &bitmapPropertiesCopy,
            &ptr
            ));

    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}


D2DBitmap ^
RenderTarget::CreateBitmapFromWicBitmap(
    BitmapSource^ wicBitmapSource
    )
{
    ID2D1Bitmap * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmapFromWicBitmap(
            wicBitmapSource->GetInterface<IWICBitmapSource>(),
            NULL,
            &ptr
            ));

    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateSharedBitmap(
    WICBitmapLock^ wicBitmap,
    BitmapProperties bitmapProperties
    )
{
    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    ID2D1Bitmap * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSharedBitmap(
            __uuidof(IWICBitmapLock),
            (void*) wicBitmap->GetInterface<IWICBitmapLock>(),
            &bitmapPropertiesCopy,
            &ptr
            ));
    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateSharedBitmap(
    WICBitmapLock^ wicBitmap
    )
{
ID2D1Bitmap * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSharedBitmap(
            __uuidof(IWICBitmapLock),
            (void*) wicBitmap->GetInterface<IWICBitmapLock>(),
            NULL,
            &ptr
            ));
    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateSharedBitmap(
    Surface^ surface,
    BitmapProperties bitmapProperties
    )
{
    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    ID2D1Bitmap * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSharedBitmap(
            __uuidof(IDXGISurface),
            (void*) surface->GetInterface<IDXGISurface>(),
            &bitmapPropertiesCopy,
            &ptr
            ));
    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateSharedBitmap(
    Surface^ surface
    )
{
    ID2D1Bitmap * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSharedBitmap(
            __uuidof(IDXGISurface),
            (void*) surface->GetInterface<IDXGISurface>(),
            NULL,
            &ptr
            ));
    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateSharedBitmap(
    D2DBitmap ^ bitmap,
    BitmapProperties bitmapProperties
    )
{
    D2D1_BITMAP_PROPERTIES bitmapPropertiesCopy;
    bitmapProperties.CopyTo(&bitmapPropertiesCopy);

    ID2D1Bitmap * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSharedBitmap(
            __uuidof(ID2D1Bitmap),
            (void*) bitmap->GetInterface<ID2D1Bitmap>(),
            &bitmapPropertiesCopy,
            &ptr
            ));
    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}

D2DBitmap ^
RenderTarget::CreateSharedBitmap(
    D2DBitmap ^ bitmap
    )
{
    ID2D1Bitmap * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSharedBitmap(
            __uuidof(ID2D1Bitmap),
            (void*) bitmap->GetInterface<ID2D1Bitmap>(),
            NULL,
            &ptr
            ));
    return ptr ? gcnew D2DBitmap(ptr): nullptr;
}


BitmapBrush ^
RenderTarget::CreateBitmapBrush(
    D2DBitmap ^ bitmap,
    BitmapBrushProperties bitmapBrushProperties,
    BrushProperties brushProperties
    )
{
    D2D1_BITMAP_BRUSH_PROPERTIES bitmapBrushPropertiesCopy;
    bitmapBrushProperties.CopyTo(&bitmapBrushPropertiesCopy);

    D2D1_BRUSH_PROPERTIES brushPropertiesCopy;
    brushProperties.CopyTo(&brushPropertiesCopy);

    ID2D1BitmapBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmapBrush(
            bitmap->GetInterface<ID2D1Bitmap>(),
            &bitmapBrushPropertiesCopy,
            &brushPropertiesCopy,
            &ptr
            ));


    return ptr ? gcnew BitmapBrush(ptr): nullptr;
}

BitmapBrush ^
RenderTarget::CreateBitmapBrush(
    D2DBitmap ^ bitmap,
    BitmapBrushProperties bitmapBrushProperties
    )
{
    D2D1_BITMAP_BRUSH_PROPERTIES bitmapBrushPropertiesCopy;
    bitmapBrushProperties.CopyTo(&bitmapBrushPropertiesCopy);

    ID2D1BitmapBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmapBrush(
            bitmap->GetInterface<ID2D1Bitmap>(),
            &bitmapBrushPropertiesCopy,
            NULL,
            &ptr
            ));


    return ptr ? gcnew BitmapBrush(ptr): nullptr;
}
BitmapBrush ^
RenderTarget::CreateBitmapBrush(
    D2DBitmap ^ bitmap,
    BrushProperties brushProperties
    )
{
    D2D1_BRUSH_PROPERTIES brushPropertiesCopy;
    brushProperties.CopyTo(&brushPropertiesCopy);

    ID2D1BitmapBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmapBrush(
            bitmap->GetInterface<ID2D1Bitmap>(),
            NULL,
            &brushPropertiesCopy,
            &ptr
            ));


    return ptr ? gcnew BitmapBrush(ptr): nullptr;
}
BitmapBrush ^
RenderTarget::CreateBitmapBrush(
    D2DBitmap ^ bitmap
    )
{
    ID2D1BitmapBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateBitmapBrush(
            bitmap->GetInterface<ID2D1Bitmap>(),
            NULL,
            NULL,
            &ptr
            ));


    return ptr ? gcnew BitmapBrush(ptr): nullptr;
}

SolidColorBrush ^
RenderTarget::CreateSolidColorBrush(
    ColorF color,
    BrushProperties brushProperties
    )
{
    D2D1_COLOR_F colorCopy;
    color.CopyTo(&colorCopy);
    D2D1_BRUSH_PROPERTIES brushPropertiesCopy;
    brushProperties.CopyTo(&brushPropertiesCopy);

    ID2D1SolidColorBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSolidColorBrush(
            &colorCopy,
            &brushPropertiesCopy,
            &ptr
            ));

    return ptr ? gcnew SolidColorBrush(ptr): nullptr;
}

SolidColorBrush ^
RenderTarget::CreateSolidColorBrush(
    ColorF color
    )
{
    D2D1_COLOR_F colorCopy;
    color.CopyTo(&colorCopy);

    ID2D1SolidColorBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateSolidColorBrush(
            &colorCopy,
            NULL,
            &ptr
            ));

    return ptr ? gcnew SolidColorBrush(ptr): nullptr;
}

GradientStopCollection ^
RenderTarget::CreateGradientStopCollection(
    IEnumerable<GradientStop> ^ gradientStops,
    Gamma colorInterpolationGamma,
    ExtendMode extendMode
    )
{
    vector<D2D1_GRADIENT_STOP> gradientStopsVector;
    ID2D1GradientStopCollection * ptr = NULL;

    for each (GradientStop gradientStop in gradientStops)
    {
        D2D1_GRADIENT_STOP gradientStopsCopy;
        gradientStop.CopyTo(&gradientStopsCopy);
        gradientStopsVector.push_back(gradientStopsCopy);
    }


    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateGradientStopCollection(
            gradientStopsVector.size() > 0 ? &gradientStopsVector[0] : NULL,
            static_cast<UINT>(gradientStopsVector.size()),
            static_cast<D2D1_GAMMA>(colorInterpolationGamma),
            static_cast<D2D1_EXTEND_MODE>(extendMode),
            &ptr
            ));


    return ptr ? gcnew GradientStopCollection(ptr) : nullptr;
}

LinearGradientBrush ^
RenderTarget::CreateLinearGradientBrush(
    LinearGradientBrushProperties linearGradientBrushProperties,
    GradientStopCollection ^ gradientStopCollection,
    BrushProperties brushProperties
    )
{
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES linearGradientBrushPropertiesCopy;
    linearGradientBrushProperties.CopyTo(&linearGradientBrushPropertiesCopy);

    D2D1_BRUSH_PROPERTIES brushPropertiesCopy;
    brushProperties.CopyTo(&brushPropertiesCopy);

    ID2D1LinearGradientBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateLinearGradientBrush(
            &linearGradientBrushPropertiesCopy,
            &brushPropertiesCopy,
            gradientStopCollection->GetInterface<ID2D1GradientStopCollection>(),
            &ptr
            ));

    return ptr ? gcnew LinearGradientBrush(ptr): nullptr;
}


LinearGradientBrush ^
RenderTarget::CreateLinearGradientBrush(
    LinearGradientBrushProperties linearGradientBrushProperties,
    GradientStopCollection ^ gradientStopCollection
    )
{
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES linearGradientBrushPropertiesCopy;
    linearGradientBrushProperties.CopyTo(&linearGradientBrushPropertiesCopy);

    ID2D1LinearGradientBrush * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateLinearGradientBrush(
            &linearGradientBrushPropertiesCopy,
            NULL,
            gradientStopCollection->GetInterface<ID2D1GradientStopCollection>(),
            &ptr
            ));

    return ptr ? gcnew LinearGradientBrush(ptr): nullptr;
}


RadialGradientBrush ^
RenderTarget::CreateRadialGradientBrush(
    RadialGradientBrushProperties radialGradientBrushProperties,
    GradientStopCollection ^ gradientStopCollection,
    BrushProperties brushProperties
    )
{
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES radialGradientBrushPropertiesCopy;
    radialGradientBrushProperties.CopyTo(&radialGradientBrushPropertiesCopy);

    D2D1_BRUSH_PROPERTIES brushPropertiesCopy;
    brushProperties.CopyTo(&brushPropertiesCopy);

    ID2D1RadialGradientBrush * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateRadialGradientBrush(
            &radialGradientBrushPropertiesCopy,
            &brushPropertiesCopy,
            gradientStopCollection->GetInterface<ID2D1GradientStopCollection>(),
            &ptr
            ));

    return ptr ? gcnew RadialGradientBrush(ptr) : nullptr;
}


RadialGradientBrush ^
RenderTarget::CreateRadialGradientBrush(
    RadialGradientBrushProperties radialGradientBrushProperties,
    GradientStopCollection ^ gradientStopCollection
    )
{
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES radialGradientBrushPropertiesCopy;
    radialGradientBrushProperties.CopyTo(&radialGradientBrushPropertiesCopy);

    ID2D1RadialGradientBrush * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateRadialGradientBrush(
            &radialGradientBrushPropertiesCopy,
            NULL,
            gradientStopCollection->GetInterface<ID2D1GradientStopCollection>(),
            &ptr
            ));

    return ptr ? gcnew RadialGradientBrush(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    SizeF desiredSize,
    SizeU desiredPixelSize
    )
{
    D2D1_SIZE_F desiredSizeCopy;
    desiredSize.CopyTo(&desiredSizeCopy);

    D2D1_SIZE_U desiredPixelSizeCopy;
    desiredPixelSize.CopyTo(&desiredPixelSizeCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            &desiredSizeCopy,
            &desiredPixelSizeCopy,
            NULL,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    SizeF desiredSize
    )
{
    D2D1_SIZE_F desiredSizeCopy;
    desiredSize.CopyTo(&desiredSizeCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            &desiredSizeCopy,
            NULL,
            NULL,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    SizeU desiredPixelSize
    )
{
    D2D1_SIZE_U desiredPixelSizeCopy;
    desiredPixelSize.CopyTo(&desiredPixelSizeCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            NULL,
            &desiredPixelSizeCopy,
            NULL,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options
    )
{
    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            NULL,
            NULL,
            NULL,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget()
{
    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            NULL,
            NULL,
            NULL,
            D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE,
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    D2D::PixelFormat desiredFormat,
    SizeF desiredSize,
    SizeU desiredPixelSize
    )
{
    D2D1_SIZE_F desiredSizeCopy;
    desiredSize.CopyTo(&desiredSizeCopy);

    D2D1_SIZE_U desiredPixelSizeCopy;
    desiredPixelSize.CopyTo(&desiredPixelSizeCopy);

    D2D1_PIXEL_FORMAT desiredFormatCopy;
    desiredFormat.CopyTo(&desiredFormatCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            &desiredSizeCopy,
            &desiredPixelSizeCopy,
            &desiredFormatCopy,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    D2D::PixelFormat desiredFormat,
    SizeF desiredSize
    )
{
    D2D1_SIZE_F desiredSizeCopy;
    desiredSize.CopyTo(&desiredSizeCopy);

    D2D1_PIXEL_FORMAT desiredFormatCopy;
    desiredFormat.CopyTo(&desiredFormatCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            &desiredSizeCopy,
            NULL,
            &desiredFormatCopy,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    D2D::PixelFormat desiredFormat,
    SizeU desiredPixelSize
    )
{
    D2D1_SIZE_U desiredPixelSizeCopy;
    desiredPixelSize.CopyTo(&desiredPixelSizeCopy);

    D2D1_PIXEL_FORMAT desiredFormatCopy;
    desiredFormat.CopyTo(&desiredFormatCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            NULL,
            &desiredPixelSizeCopy,
            &desiredFormatCopy,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

BitmapRenderTarget ^
RenderTarget::CreateCompatibleRenderTarget(
    CompatibleRenderTargetOptions options,
    D2D::PixelFormat desiredFormat
    )
{

    D2D1_PIXEL_FORMAT desiredFormatCopy;
    desiredFormat.CopyTo(&desiredFormatCopy);

    ID2D1BitmapRenderTarget * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateCompatibleRenderTarget(
            NULL,
            NULL,
            &desiredFormatCopy,
            static_cast<D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS>(options),
            &ptr
            ));

    return ptr ? gcnew BitmapRenderTarget(ptr) : nullptr;
}

Layer ^
RenderTarget::CreateLayer(
    SizeF size
    )
{
    D2D1_SIZE_F sizeCopy;
    size.CopyTo(&sizeCopy);

    ID2D1Layer * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateLayer(
            &sizeCopy,
            &ptr
            ));


    return ptr ? gcnew Layer(ptr) : nullptr;
}

Layer ^
RenderTarget::CreateLayer(
    )
{
    ID2D1Layer * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateLayer(
            NULL ,
            &ptr
            ));


    return ptr ? gcnew Layer(ptr) : nullptr;
}

Mesh ^
RenderTarget::CreateMesh(
    )
{

    ID2D1Mesh * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1RenderTarget>()->CreateMesh(
            &ptr
            ));
    return ptr ? gcnew Mesh(ptr) : nullptr;
}

void
RenderTarget::DrawLine(
    Point2F point0,
    Point2F point1,
    Brush ^ brush,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{

    pin_ptr<Point2F> point0Copy = &point0;
    pin_ptr<Point2F> point1Copy = &point1;

    GetInterface<ID2D1RenderTarget>()->DrawLine(
        *((D2D1_POINT_2F*)point0Copy),
        *((D2D1_POINT_2F*)point1Copy),
        brush->GetInterface<ID2D1Brush>(),
        strokeWidth,
        strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL
        );
}

void
RenderTarget::DrawLine(
    Point2F point0,
    Point2F point1,
    Brush ^ brush,
    FLOAT strokeWidth
    )
{
    DrawLine(point0, point1, brush, strokeWidth, nullptr);
}
void
RenderTarget::DrawRectangle(
    RectF rect,
    Brush ^ brush,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{
    pin_ptr<const RectF> rectPtr = &rect; 

    GetInterface<ID2D1RenderTarget>()->DrawRectangle(
        (D2D1_RECT_F*)(rectPtr),
        brush->GetInterface<ID2D1Brush>(),
        strokeWidth,
        strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL
        );
}

void
RenderTarget::DrawRectangle(
    RectF rect,
    Brush ^ brush,
    FLOAT strokeWidth
    )
{
    DrawRectangle(rect, brush, strokeWidth, nullptr);
}
void
RenderTarget::FillRectangle(
    RectF rect,
    Brush ^ brush
    )
{
    pin_ptr<const RectF> rectCopy = &rect; 

    GetInterface<ID2D1RenderTarget>()->FillRectangle(
        (D2D1_RECT_F*)rectCopy,
        brush->GetInterface<ID2D1Brush>()
        );
}

void
RenderTarget::DrawRoundedRectangle(
    RoundedRect roundedRect,
    Brush ^ brush,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{
    pin_ptr<const RoundedRect> roundedRectCopy = &roundedRect; 

    GetInterface<ID2D1RenderTarget>()->DrawRoundedRectangle(
        (D2D1_ROUNDED_RECT*)roundedRectCopy,
        brush->GetInterface<ID2D1Brush>(),
        strokeWidth,
        strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL
        );
}

void
RenderTarget::DrawRoundedRectangle(
    RoundedRect roundedRect,
    Brush ^ brush,
    FLOAT strokeWidth    
    )
{
    DrawRoundedRectangle(roundedRect, brush, strokeWidth, nullptr);
}
void
RenderTarget::FillRoundedRectangle(
    RoundedRect roundedRect,
    Brush ^ brush
    )
{
    pin_ptr<const RoundedRect> roundedRectCopy = &roundedRect; 

    GetInterface<ID2D1RenderTarget>()->FillRoundedRectangle(
        (D2D1_ROUNDED_RECT*)roundedRectCopy,
        brush->GetInterface<ID2D1Brush>()
        );


}

void
RenderTarget::DrawEllipse(
    Ellipse ellipse,
    Brush ^ brush,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{
    D2D1_ELLIPSE ellipseCopy;
    ellipse.CopyTo(&ellipseCopy);

        GetInterface<ID2D1RenderTarget>()->DrawEllipse(
            &ellipseCopy,
            brush->GetInterface<ID2D1Brush>(),
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL
            );
}

void
RenderTarget::DrawEllipse(
    Ellipse ellipse,
    Brush ^ brush,
    FLOAT strokeWidth
    )
{
    DrawEllipse(ellipse, brush, strokeWidth, nullptr);
}
void
RenderTarget::FillEllipse(
    Ellipse ellipse,
    Brush ^ brush
    )
{
    D2D1_ELLIPSE ellipseCopy;
    ellipse.CopyTo(&ellipseCopy);

        GetInterface<ID2D1RenderTarget>()->FillEllipse(
            &ellipseCopy,
            brush->GetInterface<ID2D1Brush>()
            );
}

void
RenderTarget::DrawGeometry(
    Geometry ^ geometry,
    Brush ^ brush,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{
    GetInterface<ID2D1RenderTarget>()->DrawGeometry(
        geometry->GetInterface<ID2D1Geometry>(),
        brush->GetInterface<ID2D1Brush>(),
        strokeWidth,
        strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL
        );
}

void
RenderTarget::DrawGeometry(
    Geometry ^ geometry,
    Brush ^ brush,
    FLOAT strokeWidth
    )
{
    DrawGeometry(geometry, brush, strokeWidth, nullptr);
}

void
RenderTarget::FillGeometry(
    Geometry ^ geometry,
    Brush ^ brush,
    Brush ^ opacityBrush
    )
{

    GetInterface<ID2D1RenderTarget>()->FillGeometry(
        geometry->GetInterface<ID2D1Geometry>(),
        brush->GetInterface<ID2D1Brush>(),
        opacityBrush ? opacityBrush->GetInterface<ID2D1Brush>() : NULL
        );
}

void
RenderTarget::FillGeometry(
    Geometry ^ geometry,
    Brush ^ brush
    )
{
    FillGeometry(geometry, brush, nullptr);
}

void
RenderTarget::FillMesh(
    Mesh ^ mesh,
    Brush ^ brush
    )
{
    GetInterface<ID2D1RenderTarget>()->FillMesh(
        mesh->GetInterface<ID2D1Mesh>(),
        brush->GetInterface<ID2D1Brush>()
        );
}

void
RenderTarget::FillOpacityMask(
    D2DBitmap ^ opacityMask,
    Brush ^ brush,
    OpacityMaskContent content,
    RectF destinationRectangle,
    RectF sourceRectangle
    )
{
    D2D1_RECT_F destinationRectangleCopy;
    destinationRectangle.CopyTo(&destinationRectangleCopy);

    D2D1_RECT_F sourceRectangleCopy;
    sourceRectangle.CopyTo(&sourceRectangleCopy);

    GetInterface<ID2D1RenderTarget>()->FillOpacityMask(
        opacityMask->GetInterface<ID2D1Bitmap>(),
        brush->GetInterface<ID2D1Brush>(),
        static_cast<D2D1_OPACITY_MASK_CONTENT>(content),
        &destinationRectangleCopy,
        &sourceRectangleCopy
        );
}

void
RenderTarget::FillOpacityMaskAtOrigin(
    D2DBitmap ^ opacityMask,
    Brush ^ brush,
    OpacityMaskContent content,
    RectF sourceRectangle
    )
{
    D2D1_RECT_F sourceRectangleCopy;
    sourceRectangle.CopyTo(&sourceRectangleCopy);

    GetInterface<ID2D1RenderTarget>()->FillOpacityMask(
        opacityMask->GetInterface<ID2D1Bitmap>(),
        brush->GetInterface<ID2D1Brush>(),
        static_cast<D2D1_OPACITY_MASK_CONTENT>(content),
        NULL,
        &sourceRectangleCopy
        );
}

void
RenderTarget::FillOpacityMask(
    D2DBitmap ^ opacityMask,
    Brush ^ brush,
    OpacityMaskContent content,
    RectF destinationRectangle
    )
{
    D2D1_RECT_F destinationRectangleCopy;
    destinationRectangle.CopyTo(&destinationRectangleCopy);

    GetInterface<ID2D1RenderTarget>()->FillOpacityMask(
        opacityMask->GetInterface<ID2D1Bitmap>(),
        brush->GetInterface<ID2D1Brush>(),
        static_cast<D2D1_OPACITY_MASK_CONTENT>(content),
        &destinationRectangleCopy,
        NULL
        );
}

void
RenderTarget::FillOpacityMask(
    D2DBitmap ^ opacityMask,
    Brush ^ brush,
    OpacityMaskContent content
    )
{
    GetInterface<ID2D1RenderTarget>()->FillOpacityMask(
        opacityMask->GetInterface<ID2D1Bitmap>(),
        brush->GetInterface<ID2D1Brush>(),
        static_cast<D2D1_OPACITY_MASK_CONTENT>(content),
        NULL,
        NULL
        );
}

void
RenderTarget::DrawBitmap(
    D2DBitmap ^ bitmap,
    FLOAT opacity,
    BitmapInterpolationMode interpolationMode,
    RectF destinationRectangle,
    RectF sourceRectangle
    )
{
    D2D1_RECT_F destinationRectangleCopy;
    destinationRectangle.CopyTo(&destinationRectangleCopy);
        
    D2D1_RECT_F sourceRectangleCopy;
    sourceRectangle.CopyTo(&sourceRectangleCopy);

    GetInterface<ID2D1RenderTarget>()->DrawBitmap(
        bitmap->GetInterface<ID2D1Bitmap>(),
        &destinationRectangleCopy,
        opacity,
        static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(interpolationMode),
        &sourceRectangleCopy
        );
}

void
RenderTarget::DrawBitmap(
    D2DBitmap ^ bitmap
    )
{
    GetInterface<ID2D1RenderTarget>()->DrawBitmap(
        bitmap->GetInterface<ID2D1Bitmap>(),
        NULL,
        1.0,
        D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
        NULL
        );
}

void
RenderTarget::DrawBitmap(
    D2DBitmap ^ bitmap,
    FLOAT opacity,
    BitmapInterpolationMode interpolationMode,
    RectF destinationRectangle
    )
{
    D2D1_RECT_F destinationRectangleCopy;
    destinationRectangle.CopyTo(&destinationRectangleCopy);
        
    GetInterface<ID2D1RenderTarget>()->DrawBitmap(
        bitmap->GetInterface<ID2D1Bitmap>(),
        &destinationRectangleCopy,
        opacity,
        static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(interpolationMode),
        NULL
        );
}

void
RenderTarget::DrawBitmapAtOrigin(
    D2DBitmap ^ bitmap,
    FLOAT opacity,
    BitmapInterpolationMode interpolationMode,
    RectF sourceRectangle
    )
{
    D2D1_RECT_F sourceRectangleCopy;
    sourceRectangle.CopyTo(&sourceRectangleCopy);

    GetInterface<ID2D1RenderTarget>()->DrawBitmap(
        bitmap->GetInterface<ID2D1Bitmap>(),
        NULL,
        opacity,
        static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(interpolationMode),
        &sourceRectangleCopy
        );
}

void
RenderTarget::DrawBitmap(
    D2DBitmap ^ bitmap,
    FLOAT opacity,
    BitmapInterpolationMode interpolationMode
    )
{
    GetInterface<ID2D1RenderTarget>()->DrawBitmap(
        bitmap->GetInterface<ID2D1Bitmap>(),
        NULL,
        opacity,
        static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(interpolationMode),
        NULL
        );
}

GdiInteropRenderTarget^ RenderTarget::GetGdiInteropRenderTarget()
{
    ID2D1GdiInteropRenderTarget* gdiRenderTargt = NULL;
    GetInterface<IUnknown>()->QueryInterface(__uuidof(ID2D1GdiInteropRenderTarget), (void**) &gdiRenderTargt);

    return gdiRenderTargt ? gcnew GdiInteropRenderTarget(gdiRenderTargt) : nullptr;
}

void
RenderTarget::Transform::set(
    Matrix3x2F transform
    )
{
    D2D1_MATRIX_3X2_F transformCopy;
    transform.CopyTo(&transformCopy);

    GetInterface<ID2D1RenderTarget>()->SetTransform(
        &transformCopy
        );
}

Matrix3x2F
RenderTarget::Transform::get(
    )
{
    D2D1_MATRIX_3X2_F transformCopy;

        GetInterface<ID2D1RenderTarget>()->GetTransform(
            &transformCopy
            );

    Matrix3x2F transform;
    transform.CopyFrom(transformCopy);
    return transform;
}

void
RenderTarget::AntialiasMode::set(
    D2D::AntialiasMode antialiasMode
    )
{
    GetInterface<ID2D1RenderTarget>()->SetAntialiasMode(
        static_cast<D2D1_ANTIALIAS_MODE>(antialiasMode)
        );
}

D2D::AntialiasMode
RenderTarget::AntialiasMode::get(
    )
{
    return static_cast<D2D::AntialiasMode>(GetInterface<ID2D1RenderTarget>()->GetAntialiasMode());
}

void
RenderTarget::TextAntialiasMode::set(
    D2D::TextAntialiasMode textAntialiasMode
    )
{
    GetInterface<ID2D1RenderTarget>()->SetTextAntialiasMode(
        static_cast<D2D1_TEXT_ANTIALIAS_MODE>(textAntialiasMode)
        );
}

D2D::TextAntialiasMode
RenderTarget::TextAntialiasMode::get(
    )
{
    return static_cast<D2D::TextAntialiasMode>(GetInterface<ID2D1RenderTarget>()->GetTextAntialiasMode());
}

void
RenderTarget::Tags::set(
    D2D::Tags tags
    )
{
    GetInterface<ID2D1RenderTarget>()->SetTags(
        static_cast<D2D1_TAG>(tags.Tag1),
        static_cast<D2D1_TAG>(tags.Tag2)
        );
}

D2D::Tags
RenderTarget::Tags::get(
    )
{
    D2D1_TAG tag1, tag2;

    GetInterface<ID2D1RenderTarget>()->GetTags(
        &tag1,
        &tag2
        );

    return D2D::Tags(static_cast<UINT64>(tag1), static_cast<UINT64>(tag2));
}

void
RenderTarget::PushLayer(
    LayerParameters layerParameters,
    Layer ^ layer
    )
{
    D2D1_LAYER_PARAMETERS layerParametersCopy;
    layerParameters.CopyTo(&layerParametersCopy);

    GetInterface<ID2D1RenderTarget>()->PushLayer(
        &layerParametersCopy,
        layer->GetInterface<ID2D1Layer>()
        );
}

void
RenderTarget::PopLayer(
    )
{
    GetInterface<ID2D1RenderTarget>()->PopLayer(
        );
}

D2D::Tags
RenderTarget::Flush(
    )
{
    D2D1_TAG tag1, tag2;

    HRESULT hr = 
        GetInterface<ID2D1RenderTarget>()->Flush(
            &tag1,
            &tag2
            );

    if (!SUCCEEDED(hr))
    {
        Exception^ e = CommonUtils::GetExceptionForHR(hr);

        throw gcnew Direct2DException(
            String::Format("Flush has failed with error: {0} Tags=({1}, {2}).",
                e->Message, static_cast<UInt64>(tag1), static_cast<UInt64>(tag2)),
                e);

    }
    else
    {
        return D2D::Tags(static_cast<UINT64>(tag1), static_cast<UINT64>(tag2));
    }
}

bool
RenderTarget::TryFlush([System::Runtime::InteropServices::Out] D2D::Tags % tags, [System::Runtime::InteropServices::Out] ErrorCode % errorCode)
{
    D2D1_TAG tag1, tag2;

    HRESULT hr =
        GetInterface<ID2D1RenderTarget>()->Flush(
            &tag1,
            &tag2
            );
    errorCode = static_cast<ErrorCode>(hr);
    tags = D2D::Tags(static_cast<UINT64>(tag1), static_cast<UINT64>(tag2));
    
    return SUCCEEDED(hr) ? true : false;

}

void
RenderTarget::SaveDrawingState(
    DrawingStateBlock ^ drawingStateBlock
    )
{
    GetInterface<ID2D1RenderTarget>()->SaveDrawingState(
        drawingStateBlock->GetInterface<ID2D1DrawingStateBlock>()
        );
}

void
RenderTarget::RestoreDrawingState(
    DrawingStateBlock ^ drawingStateBlock
    )
{
    GetInterface<ID2D1RenderTarget>()->RestoreDrawingState(
        drawingStateBlock->GetInterface<ID2D1DrawingStateBlock>()
        );
}

void
RenderTarget::PushAxisAlignedClip(
    RectF clipRect,
    D2D::AntialiasMode antialiasMode
    )
{
    D2D1_RECT_F clipRectCopy;
    clipRect.CopyTo(&clipRectCopy);

    GetInterface<ID2D1RenderTarget>()->PushAxisAlignedClip(
        &clipRectCopy,
        static_cast<D2D1_ANTIALIAS_MODE>(antialiasMode)
        );
}

void
RenderTarget::PopAxisAlignedClip(
    )
{
    GetInterface<ID2D1RenderTarget>()->PopAxisAlignedClip(
        );
}

void
RenderTarget::Clear(
    ColorF  clearColor
    )
{
    D2D1_COLOR_F clearColorCopy;
    clearColor.CopyTo(&clearColorCopy);

    GetInterface<ID2D1RenderTarget>()->Clear(
        &clearColorCopy
        );
}

void
RenderTarget::Clear(
    )
{

    GetInterface<ID2D1RenderTarget>()->Clear(
        NULL
        );
}

void
RenderTarget::BeginDraw(
    )
{
        GetInterface<ID2D1RenderTarget>()->BeginDraw(
            );
}

D2D::Tags
RenderTarget::EndDraw(
    )
{
    D2D1_TAG tag1, tag2;

    HRESULT hr = 
        GetInterface<ID2D1RenderTarget>()->EndDraw(
            &tag1,
            &tag2
            );

    if (!SUCCEEDED(hr))
    {
        Exception^ e = CommonUtils::GetExceptionForHR(hr);

        throw gcnew Direct2DException(
            String::Format("EndDraw has failed with error: {0} Tags=({1},{2}).",
                e->Message, static_cast<UInt64>(tag1), static_cast<UInt64>(tag2)),
                e);
    }
    else
    {
        return D2D::Tags(static_cast<UINT64>(tag1), static_cast<UINT64>(tag2));
    }
    
}

bool
RenderTarget::TryEndDraw([System::Runtime::InteropServices::Out] D2D::Tags % tags, [System::Runtime::InteropServices::Out] ErrorCode % errorCode)
{
    D2D1_TAG tag1, tag2;

    HRESULT hr =
        GetInterface<ID2D1RenderTarget>()->EndDraw(
            &tag1,
            &tag2
            );
    errorCode = static_cast<ErrorCode>(hr);
    tags = D2D::Tags(static_cast<UINT64>(tag1), static_cast<UINT64>(tag2));
    
    return SUCCEEDED(hr) ? true : false;
}


D2D::PixelFormat
RenderTarget::PixelFormat::get(
    )
{
    D2D1_PIXEL_FORMAT returnCopy;

    returnCopy =
        GetInterface<ID2D1RenderTarget>()->GetPixelFormat(
            );


    D2D::PixelFormat returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

void
RenderTarget::Dpi::set(DpiF dpi)
{
    GetInterface<ID2D1RenderTarget>()->SetDpi(
        dpi.X,
        dpi.Y
        );
}

DpiF
RenderTarget::Dpi::get()
{
    ::FLOAT dpiXCopy;
    ::FLOAT dpiYCopy;

        GetInterface<ID2D1RenderTarget>()->GetDpi(
            &dpiXCopy,
            &dpiYCopy
            );

   return DpiF(dpiXCopy, dpiYCopy);

}

SizeF
RenderTarget::Size::get(
    )
{
    D2D1_SIZE_F returnCopy;

    returnCopy =
        GetInterface<ID2D1RenderTarget>()->GetSize(
            );


    SizeF returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

SizeU
RenderTarget::PixelSize::get(
    )
{
    D2D1_SIZE_U returnCopy;

    returnCopy =
        GetInterface<ID2D1RenderTarget>()->GetPixelSize(
            );


    SizeU returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

UINT32
RenderTarget::MaximumBitmapSize::get(
    )
{
    return GetInterface<ID2D1RenderTarget>()->GetMaximumBitmapSize();
}

Boolean
RenderTarget::IsSupported(
    RenderTargetProperties renderTargetProperties
    )
{
    D2D1_RENDER_TARGET_PROPERTIES renderTargetPropertiesCopy;
    renderTargetProperties.CopyTo(&renderTargetPropertiesCopy);

    return 
        GetInterface<ID2D1RenderTarget>()->IsSupported(
            &renderTargetPropertiesCopy
            ) != 0;
}

void RenderTarget::DrawText(
    String^ text,
    TextFormat^ textFormat,
    RectF layoutRect,
    Brush^ defaultForegroundBrush,
    DrawTextOptions options,
    MeasuringMode measuringMode)
{
    UINT strLen = text->Length;
    D2D1_RECT_F rectCopy;
    layoutRect.CopyTo(&rectCopy);

    IntPtr chars = Marshal::StringToCoTaskMemUni( text );
    try
    {
        GetInterface<ID2D1RenderTarget>()->DrawText(
            (WCHAR *)chars.ToPointer(),
            strLen,
            textFormat->GetInterface<IDWriteTextFormat>(),
            &rectCopy,
            defaultForegroundBrush->GetInterface<ID2D1Brush>(),
            static_cast<D2D1_DRAW_TEXT_OPTIONS>(options),
            static_cast<DWRITE_MEASURING_MODE>(measuringMode));
    }
    finally
    {
        Marshal::FreeCoTaskMem(chars);
    }
}


void RenderTarget::DrawText(
    String^ text,
    TextFormat^ textFormat,
    RectF layoutRect,
    Brush^ defaultForegroundBrush,
    DrawTextOptions options
    )
{
    DrawText(text, textFormat, layoutRect, defaultForegroundBrush, options, MeasuringMode::Natural);
}

void RenderTarget::DrawText(
    String^ text,
    TextFormat^ textFormat,
    RectF layoutRect,
    Brush^ defaultForegroundBrush,    
    MeasuringMode measuringMode)
{
    DrawText(text, textFormat, layoutRect, defaultForegroundBrush, DrawTextOptions::None, measuringMode);
}

void RenderTarget::DrawText(
    String^ text,
    TextFormat^ textFormat,
    RectF layoutRect,
    Brush^ defaultForegroundBrush)
{
    DrawText(text, textFormat, layoutRect, defaultForegroundBrush, DrawTextOptions::None, MeasuringMode::Natural);
}

void RenderTarget::DrawGlyphRun(
    Point2F baselineOrigin,
    array<GlyphRun>^ glyphRun,
    Brush^ foregroundBrush,
    MeasuringMode measuringMode)
{
    D2D1_POINT_2F originCopy;
    baselineOrigin.CopyTo(&originCopy);

    DWRITE_GLYPH_RUN * pGlyphRun = new DWRITE_GLYPH_RUN[glyphRun->Length];
    for (int i = 0; i < glyphRun->Length; i++)
    {
        glyphRun[i].CopyTo(&pGlyphRun[i]); 
    }

    try
    {
        GetInterface<ID2D1RenderTarget>()->DrawGlyphRun(
            originCopy,
            pGlyphRun,
            foregroundBrush ? foregroundBrush->GetInterface<ID2D1Brush>() : NULL,
            static_cast<DWRITE_MEASURING_MODE>(measuringMode));
    }
    finally
    {
        if (glyphRun->Length > 0)
        {
            for (int i = 0; i < glyphRun->Length; i++)
            {
                delete [] pGlyphRun[i].glyphAdvances;
                delete [] pGlyphRun[i].glyphIndices;
                delete [] pGlyphRun[i].glyphOffsets;
            }
            
            delete [] pGlyphRun;
        }
    }
}

void RenderTarget::DrawGlyphRun(
    Point2F baselineOrigin,
    array<GlyphRun>^ glyphRun,
    Brush^ foregroundBrush)
{
    DrawGlyphRun(baselineOrigin, glyphRun, foregroundBrush, MeasuringMode::Natural);
}

RenderingParams^ RenderTarget::GetTextRenderingParams()
{
    IDWriteRenderingParams* renderingParams = NULL;
    GetInterface<ID2D1RenderTarget>()->GetTextRenderingParams(&renderingParams);

    return renderingParams ? gcnew RenderingParams(renderingParams) : nullptr;
}

void RenderTarget::SetTextRenderingParams(RenderingParams^ textRenderingParams)
{
    GetInterface<ID2D1RenderTarget>()->SetTextRenderingParams(
        textRenderingParams == nullptr ? NULL : textRenderingParams->GetInterface<IDWriteRenderingParams>()
        );
}

void RenderTarget::DrawTextLayout(
    Point2F origin,
    TextLayout^ textLayout,
    Brush^ defaultForegroundBrush,
    DrawTextOptions options)
{
    D2D1_POINT_2F originCopy;
    origin.CopyTo(&originCopy);

    GetInterface<ID2D1RenderTarget>()->DrawTextLayout(
        originCopy, 
        textLayout->GetInterface<IDWriteTextLayout>(), 
        defaultForegroundBrush->GetInterface<ID2D1Brush>(),
        static_cast<D2D1_DRAW_TEXT_OPTIONS>(options));
}

void RenderTarget::DrawTextLayout(
    Point2F origin,
    TextLayout^ textLayout,
    Brush^ defaultForegroundBrush)
{
    D2D1_POINT_2F originCopy;
    origin.CopyTo(&originCopy);

    GetInterface<ID2D1RenderTarget>()->DrawTextLayout(
        originCopy, 
        textLayout->GetInterface<IDWriteTextLayout>(), 
        defaultForegroundBrush->GetInterface<ID2D1Brush>());
}

BitmapRenderTarget::BitmapRenderTarget(
    ) : RenderTarget()
{
}

BitmapRenderTarget::BitmapRenderTarget(
    IUnknown *pInner
    ) : RenderTarget(pInner)
{
}

D2DBitmap ^
BitmapRenderTarget::GetBitmap(
    )
{
    ID2D1Bitmap * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1BitmapRenderTarget>()->GetBitmap(
            &ptr
            ));

    return ptr ? gcnew D2DBitmap(ptr) : nullptr;
}

HwndRenderTarget::HwndRenderTarget(
    ) : RenderTarget()
{
}

HwndRenderTarget::HwndRenderTarget(
    IUnknown *pInner
    ) : RenderTarget(pInner)
{
}

Boolean HwndRenderTarget::IsOccluded::get()
{
    if (GetInterface<ID2D1HwndRenderTarget>()->CheckWindowState() & D2D1_WINDOW_STATE_OCCLUDED)
        return true;
    else
        return false;
}

WindowState
HwndRenderTarget::CheckWindowState(
    )
{
    return static_cast<WindowState>(GetInterface<ID2D1HwndRenderTarget>()->CheckWindowState());
}

void
HwndRenderTarget::Resize(
    SizeU pixelSize
    )
{
    D2D1_SIZE_U pixelSizeCopy;
    pixelSize.CopyTo(&pixelSizeCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1HwndRenderTarget>()->Resize(
            &pixelSizeCopy
            ));
}

IntPtr
HwndRenderTarget::WindowHandle::get(
    )
{
    return IntPtr(GetInterface<ID2D1HwndRenderTarget>()->GetHwnd());
}

GdiInteropRenderTarget::GdiInteropRenderTarget(
    ) : DirectUnknown()
{
}

GdiInteropRenderTarget::GdiInteropRenderTarget(
    IUnknown *pInner
    ) : DirectUnknown(pInner)
{
}

IntPtr
GdiInteropRenderTarget::GetDC(
    DCInitializeMode mode
    )
{

    HDC hdc;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1GdiInteropRenderTarget>()->GetDC(
            static_cast<D2D1_DC_INITIALIZE_MODE>(mode),
            &hdc
            ));

    return IntPtr(hdc);
}

void
GdiInteropRenderTarget::ReleaseDC(
    Rect updaterect
    )
{
    ::RECT updateCopy;
    updaterect.CopyTo(&updateCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1GdiInteropRenderTarget>()->ReleaseDC(
            &updateCopy
            ));
}

void
GdiInteropRenderTarget::ReleaseDC(
    )
{
    CommonUtils::VerifyResult(
        GetInterface<ID2D1GdiInteropRenderTarget>()->ReleaseDC(
            NULL
            ));
}

DCRenderTarget::DCRenderTarget(
    ) : RenderTarget()
{
}

DCRenderTarget::DCRenderTarget(
    IUnknown *pInner
    ) : RenderTarget(pInner)
{
}

void
DCRenderTarget::BindDC(
    IntPtr hDC,
    Rect pSubRect
    )
{
    ::RECT pSubRectCopy;
    pSubRect.CopyTo(&pSubRectCopy);

    CommonUtils::VerifyResult(
        GetInterface<ID2D1DCRenderTarget>()->BindDC(
            static_cast<HDC>(hDC.ToPointer()),
            &pSubRectCopy
            ));
}

StrokeStyle::StrokeStyle(
    ) : D2DResource()
{
}

StrokeStyle::StrokeStyle(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

CapStyle
StrokeStyle::StartCap::get(
    )
{
    return static_cast<CapStyle>(GetInterface<ID2D1StrokeStyle>()->GetStartCap());
}

CapStyle
StrokeStyle::EndCap::get(
    )
{
    return static_cast<CapStyle>(GetInterface<ID2D1StrokeStyle>()->GetEndCap());
}

CapStyle
StrokeStyle::DashCap::get(
    )
{
    return static_cast<CapStyle>(GetInterface<ID2D1StrokeStyle>()->GetDashCap());
}

FLOAT
StrokeStyle::MiterLimit::get(
    )
{
    return GetInterface<ID2D1StrokeStyle>()->GetMiterLimit();
}

D2D::LineJoin
StrokeStyle::LineJoin::get(
    )
{
    return static_cast<D2D::LineJoin>(GetInterface<ID2D1StrokeStyle>()->GetLineJoin());
}

FLOAT
StrokeStyle::DashOffset::get(
    )
{
    return GetInterface<ID2D1StrokeStyle>()->GetDashOffset();
}

D2D::DashStyle
StrokeStyle::DashStyle::get(
    )
{
    return static_cast<D2D::DashStyle>(GetInterface<ID2D1StrokeStyle>()->GetDashStyle());
}

UINT32
StrokeStyle::DashesCount::get(
    )
{
    return GetInterface<ID2D1StrokeStyle>()->GetDashesCount();
}

cli::array<FLOAT> ^
StrokeStyle::Dashes::get(
    )
{
    cli::array<FLOAT> ^dashes = nullptr;

    UINT count = GetInterface<ID2D1StrokeStyle>()->GetDashesCount();;

    dashes = gcnew cli::array<FLOAT>(count);

    pin_ptr<FLOAT> dashesCopy = &dashes[0];

    GetInterface<ID2D1StrokeStyle>()->GetDashes(
        dashesCopy,
        dashes->Length
        );

    return dashes;
}

Geometry::Geometry(
    ) : D2DResource()
{
}

Geometry::Geometry(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

RectF
Geometry::GetBounds(
    Matrix3x2F worldTransform
    )
{
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);

    D2D1_RECT_F boundsCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->GetBounds(
            &worldTransformCopy,
            &boundsCopy
            ));

    RectF bounds;
    bounds.CopyFrom(boundsCopy);

    return bounds;

}

RectF
Geometry::GetBounds(
    )
{
    D2D1_RECT_F boundsCopy;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->GetBounds(
            NULL,
            &boundsCopy
            ));

    RectF bounds;
    bounds.CopyFrom(boundsCopy);

    return bounds;

}
RectF
Geometry::GetWidenedBounds(
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle,
    FLOAT flatteningTolerance,
    Matrix3x2F worldTransform
    )
{
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);
    D2D1_RECT_F boundsCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->GetWidenedBounds(
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL,
            &worldTransformCopy,
            flatteningTolerance,
            &boundsCopy
            ));

    RectF bounds;
    bounds.CopyFrom(boundsCopy);
    return bounds;

}

RectF
Geometry::GetWidenedBounds(
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle,
    FLOAT flatteningTolerance
    )
{
    D2D1_RECT_F boundsCopy;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->GetWidenedBounds(
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL,
            NULL,
            flatteningTolerance,
            &boundsCopy
            ));

    RectF bounds;
    bounds.CopyFrom(boundsCopy);
    return bounds;

}


RectF
Geometry::GetWidenedBounds(
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{
    D2D1_RECT_F boundsCopy;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->GetWidenedBounds(
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL,
            NULL,
            &boundsCopy
            ));

    RectF bounds;
    bounds.CopyFrom(boundsCopy);
    return bounds;
}

Boolean
Geometry::StrokeContainsPoint(
    Point2F point,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle,
    FLOAT flatteningTolerance,
    Matrix3x2F worldTransform
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);
    BOOL contains;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->StrokeContainsPoint(
            pointCopy,
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL,
            &worldTransformCopy,
            flatteningTolerance,
            &contains
            ));
    return contains != 0;
}

Boolean
Geometry::StrokeContainsPoint(
    Point2F point,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle,
    FLOAT flatteningTolerance
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);
    BOOL contains;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->StrokeContainsPoint(
            pointCopy,
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL,
            NULL ,
            flatteningTolerance,
            &contains
            ));

    return contains != 0;
}

Boolean
Geometry::StrokeContainsPoint(
    Point2F point,
    FLOAT strokeWidth,
    StrokeStyle ^ strokeStyle
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);
    BOOL contains;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->StrokeContainsPoint(
            pointCopy,
            strokeWidth,
            strokeStyle ? strokeStyle->GetInterface<ID2D1StrokeStyle>() : NULL,
            NULL ,
            &contains
            ));

    return contains != 0;
}

Boolean
Geometry::FillContainsPoint(
    Point2F point,
    FLOAT flatteningTolerance,
    Matrix3x2F worldTransform
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);
    BOOL contains;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->FillContainsPoint(
            pointCopy,
            &worldTransformCopy,
            flatteningTolerance,
            &contains
            ));


    return contains != 0;
}

Boolean
Geometry::FillContainsPoint(
    Point2F point,
    FLOAT flatteningTolerance
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);

    BOOL contains;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->FillContainsPoint(
            pointCopy,
            NULL ,
            flatteningTolerance,
            &contains
            ));


    return contains != 0;
}

Boolean
Geometry::FillContainsPoint(
    Point2F point
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);

    BOOL contains;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->FillContainsPoint(
            pointCopy,
            NULL ,
            &contains
            ));


    return contains != 0;
}

GeometryRelation
Geometry::CompareWithGeometry(
    Geometry ^ inputGeometry,
    FLOAT flatteningTolerance,
    Matrix3x2F inputGeometryTransform
    )
{
    D2D1_MATRIX_3X2_F inputGeometryTransformCopy;
    inputGeometryTransform.CopyTo(&inputGeometryTransformCopy);
    GeometryRelation relation;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->CompareWithGeometry(
            inputGeometry->GetInterface<ID2D1Geometry>(),
            &inputGeometryTransformCopy,
            flatteningTolerance,
            reinterpret_cast<D2D1_GEOMETRY_RELATION *>(static_cast<GeometryRelation *>(&relation))
            ));


    return relation;
}

GeometryRelation
Geometry::CompareWithGeometry(
    Geometry ^ inputGeometry,
    FLOAT flatteningTolerance
    )
{
    D2D1_GEOMETRY_RELATION relation;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->CompareWithGeometry(
            inputGeometry->GetInterface<ID2D1Geometry>(),
            NULL,
            flatteningTolerance,
            &relation
            ));


    return static_cast<GeometryRelation>(relation);
}

GeometryRelation
Geometry::CompareWithGeometry(
    Geometry ^ inputGeometry
    )
{
    D2D1_GEOMETRY_RELATION relation;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->CompareWithGeometry(
            inputGeometry->GetInterface<ID2D1Geometry>(),
            NULL,
            &relation
            ));

    return static_cast<GeometryRelation>(relation);
}

FLOAT
Geometry::ComputeArea(
    FLOAT flatteningTolerance,
    Matrix3x2F worldTransform
    )
{
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);
    
    ::FLOAT areaCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputeArea(
            &worldTransformCopy,
            flatteningTolerance,
            &areaCopy
            ));

   return areaCopy;
}

FLOAT
Geometry::ComputeArea(
    FLOAT flatteningTolerance
    )
{
    ::FLOAT areaCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputeArea(
            NULL,
            flatteningTolerance,
            &areaCopy
            ));

   return areaCopy;
}

FLOAT
Geometry::ComputeArea(
    )
{
    ::FLOAT areaCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputeArea(
            NULL,
            &areaCopy
            ));

   return areaCopy;
}

FLOAT
Geometry::ComputeLength(
    FLOAT flatteningTolerance,
    Matrix3x2F worldTransform
    )
{
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);

    ::FLOAT lengthCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputeLength(
            &worldTransformCopy,
            flatteningTolerance,
            &lengthCopy
            ));

   return lengthCopy;

}

FLOAT
Geometry::ComputeLength(
    FLOAT flatteningTolerance
    )
{
    ::FLOAT lengthCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputeLength(
            NULL,
            flatteningTolerance,
            &lengthCopy
            ));

   return lengthCopy;
}

FLOAT
Geometry::ComputeLength(
    )
{
    ::FLOAT lengthCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputeLength(
            NULL,
            &lengthCopy
            ));

   return lengthCopy;
}

Point2F
Geometry::ComputePointAtLength(
    FLOAT length,
    [System::Runtime::InteropServices::Out] Point2F % unitTangentVector,
    FLOAT flatteningTolerance,
    Matrix3x2F worldTransform
    )
{
    D2D1_MATRIX_3X2_F worldTransformCopy;
    worldTransform.CopyTo(&worldTransformCopy);

    D2D1_POINT_2F pointCopy;
    D2D1_POINT_2F unitTangentVectorCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputePointAtLength(
            length,
            &worldTransformCopy,
            flatteningTolerance,
            &pointCopy,
            &unitTangentVectorCopy
            ));

    unitTangentVector.CopyFrom(unitTangentVectorCopy);

    Point2F point;
    point.CopyFrom(pointCopy);
    return point;
}

Point2F
Geometry::ComputePointAtLength(
    FLOAT length,
    [System::Runtime::InteropServices::Out] Point2F % unitTangentVector,
    FLOAT flatteningTolerance
    )
{
    D2D1_POINT_2F pointCopy;
    D2D1_POINT_2F unitTangentVectorCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputePointAtLength(
            length,
            NULL,
            flatteningTolerance,
            &pointCopy,
            &unitTangentVectorCopy
            ));

    unitTangentVector.CopyFrom(unitTangentVectorCopy);

    Point2F point;
    point.CopyFrom(pointCopy);
    return point;
}

Point2F
Geometry::ComputePointAtLength(
    FLOAT length,
    [System::Runtime::InteropServices::Out] Point2F % unitTangentVector
    )
{
    D2D1_POINT_2F pointCopy;
    D2D1_POINT_2F unitTangentVectorCopy;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Geometry>()->ComputePointAtLength(
            length,
            NULL,
            &pointCopy,
            &unitTangentVectorCopy
            ));

    unitTangentVector.CopyFrom(unitTangentVectorCopy);

    Point2F point;
    point.CopyFrom(pointCopy);
    return point;
}

RectangleGeometry::RectangleGeometry(
    ) : Geometry()
{
}

RectangleGeometry::RectangleGeometry(
    IUnknown *pInner
    ) : Geometry(pInner)
{
}

RectF
RectangleGeometry::Rectangle::get(
    )
{
    D2D1_RECT_F rectCopy;

    GetInterface<ID2D1RectangleGeometry>()->GetRect(
        &rectCopy
        );

    RectF rect;
    rect.CopyFrom(rectCopy);
    return rect;

}

RoundedRectangleGeometry::RoundedRectangleGeometry(
    ) : Geometry()
{
}

RoundedRectangleGeometry::RoundedRectangleGeometry(
    IUnknown *pInner
    ) : Geometry(pInner)
{
}

D2D::RoundedRect
RoundedRectangleGeometry::RoundedRectangle::get(    
    )
{
    D2D1_ROUNDED_RECT roundedRectCopy;

    GetInterface<ID2D1RoundedRectangleGeometry>()->GetRoundedRect(
        &roundedRectCopy
        );

    D2D::RoundedRect roundedRect;
    roundedRect.CopyFrom(roundedRectCopy);
    return roundedRect;

}

EllipseGeometry::EllipseGeometry(
    ) : Geometry()
{
}

EllipseGeometry::EllipseGeometry(
    IUnknown *pInner
    ) : Geometry(pInner)
{
}

D2D::Ellipse
EllipseGeometry::Ellipse::get(
    )
{
    D2D1_ELLIPSE ellipseCopy;

    GetInterface<ID2D1EllipseGeometry>()->GetEllipse(
        &ellipseCopy
        );

    D2D::Ellipse ellipse;
    ellipse.CopyFrom(ellipseCopy);
    return ellipse;
}

SimplifiedGeometrySink::SimplifiedGeometrySink(
    ) : DirectUnknown()
{
}

SimplifiedGeometrySink::SimplifiedGeometrySink(
    IUnknown *pInner
    ) : DirectUnknown(pInner)
{
}

void
SimplifiedGeometrySink::SetFillMode(
    FillMode fillMode
    )
{

    GetInterface<ID2D1SimplifiedGeometrySink>()->SetFillMode(
        static_cast<D2D1_FILL_MODE>(fillMode)
        );
}

void
SimplifiedGeometrySink::SetSegmentFlags(
    PathSegment vertexFlags
    )
{
    GetInterface<ID2D1SimplifiedGeometrySink>()->SetSegmentFlags(
        static_cast<D2D1_PATH_SEGMENT>(vertexFlags)
        );
}

void
SimplifiedGeometrySink::BeginFigure(
    Point2F startPoint,
    FigureBegin figureBegin
    )
{
    D2D1_POINT_2F startPointCopy;
    startPoint.CopyTo(&startPointCopy);

    GetInterface<ID2D1SimplifiedGeometrySink>()->BeginFigure(
        startPointCopy,
        static_cast<D2D1_FIGURE_BEGIN>(figureBegin)
        );
}

void
SimplifiedGeometrySink::AddLines(
    IEnumerable<Point2F> ^ points
    )
{
    vector<D2D1_POINT_2F> pointsVector;
    
    for each(Point2F point in points)
    {
        pointsVector.push_back(D2D1_POINT_2F());
        point.CopyTo(&pointsVector.back());
    }
    
    GetInterface<ID2D1SimplifiedGeometrySink>()->AddLines(
        pointsVector.size() > 0 ? &pointsVector[0] : NULL,
        static_cast<UINT>(pointsVector.size())
        );
}

void
SimplifiedGeometrySink::AddBeziers(
    IEnumerable<BezierSegment> ^ beziers
    )
{
    vector<D2D1_BEZIER_SEGMENT> beziersVector;
    
    for each(BezierSegment bezier in beziers)
    {
        beziersVector.push_back(D2D1_BEZIER_SEGMENT());
        bezier.CopyTo(&beziersVector.back());
    }

    GetInterface<ID2D1SimplifiedGeometrySink>()->AddBeziers(
        beziersVector.size() > 0 ? &beziersVector[0] : NULL,
        static_cast<UINT>(beziersVector.size())
        );
}

void
SimplifiedGeometrySink::EndFigure(
    FigureEnd figureEnd
    )
{
    GetInterface<ID2D1SimplifiedGeometrySink>()->EndFigure(
        static_cast<D2D1_FIGURE_END>(figureEnd)
        );
}

void
SimplifiedGeometrySink::Close(
    )
{

CommonUtils::VerifyResult(
    GetInterface<ID2D1SimplifiedGeometrySink>()->Close(
    ));
}

GeometrySink::GeometrySink(
    ) : SimplifiedGeometrySink()
{
}

GeometrySink::GeometrySink(
    IUnknown *pInner
    ) : SimplifiedGeometrySink(pInner)
{
}

void
GeometrySink::AddLine(
    Point2F point
    )
{
    D2D1_POINT_2F pointCopy;
    point.CopyTo(&pointCopy);

    GetInterface<ID2D1GeometrySink>()->AddLine(
        pointCopy
        );
}

void
GeometrySink::AddBezier(
    BezierSegment bezier
    )
{
    D2D1_BEZIER_SEGMENT bezierCopy;
    bezier.CopyTo(&bezierCopy);

    GetInterface<ID2D1GeometrySink>()->AddBezier(
        &bezierCopy
        );
}

void
GeometrySink::AddQuadraticBezier(
    QuadraticBezierSegment bezier
    )
{
    D2D1_QUADRATIC_BEZIER_SEGMENT bezierCopy;
    bezier.CopyTo(&bezierCopy);

    GetInterface<ID2D1GeometrySink>()->AddQuadraticBezier(
        &bezierCopy
        );
}

void
GeometrySink::AddQuadraticBeziers(
    IEnumerable<QuadraticBezierSegment> ^ beziers
    )
{
    vector<D2D1_QUADRATIC_BEZIER_SEGMENT> beziersVector;
    
    for each(QuadraticBezierSegment bezier in beziers)
    {
        beziersVector.push_back(D2D1_QUADRATIC_BEZIER_SEGMENT());
        bezier.CopyTo(&beziersVector.back());
    }

    GetInterface<ID2D1GeometrySink>()->AddQuadraticBeziers(
        beziersVector.size() > 0 ? &beziersVector[0] : NULL,
        static_cast<UINT>(beziersVector.size())
        );
}

void
GeometrySink::AddArc(
    ArcSegment arc
    )
{
    D2D1_ARC_SEGMENT arcCopy;
    arc.CopyTo(&arcCopy);

    GetInterface<ID2D1GeometrySink>()->AddArc(
        &arcCopy
        );
}

TessellationSink::TessellationSink(
    ) : DirectUnknown()
{
}

TessellationSink::TessellationSink(
    IUnknown *pInner
    ) : DirectUnknown(pInner)
{
}

void
TessellationSink::AddTriangles(
    IEnumerable<Triangle> ^ triangles
    )
{
    vector<D2D1_TRIANGLE> trianglesVector;
    
    for each(Triangle triangle in triangles)
    {
        trianglesVector.push_back(D2D1_TRIANGLE());
        triangle.CopyTo(&trianglesVector.back());
    }

    GetInterface<ID2D1TessellationSink>()->AddTriangles(
        trianglesVector.size() > 0 ? &trianglesVector[0] : NULL,
        static_cast<UINT>(trianglesVector.size())
        );
}

void
TessellationSink::Close(
    )
{
    CommonUtils::VerifyResult(
        GetInterface<ID2D1TessellationSink>()->Close(
        ));
}

PathGeometry::PathGeometry(
    ) : Geometry()
{
}

PathGeometry::PathGeometry(
    IUnknown *pInner
    ) : Geometry(pInner)
{
}

GeometrySink ^
PathGeometry::Open(
    )
{
    ID2D1GeometrySink * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1PathGeometry>()->Open(
            &ptr
            ));

    return ptr ? gcnew GeometrySink(ptr) : nullptr;
}

UINT32
PathGeometry::SegmentCount::get(
    )
{
    UINT32 count;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1PathGeometry>()->GetSegmentCount(
            &count
            ));


    return count;
}

UINT32
PathGeometry::FigureCount::get(
    )
{
    UINT32 count;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1PathGeometry>()->GetFigureCount(
            &count
            ));


    return count;
}

GeometryGroup::GeometryGroup(
    ) : Geometry()
{
}

GeometryGroup::GeometryGroup(
    IUnknown *pInner
    ) : Geometry(pInner)
{
}

D2D::FillMode
GeometryGroup::FillMode::get(
    )
{
    return static_cast<D2D::FillMode>(GetInterface<ID2D1GeometryGroup>()->GetFillMode());
}

UINT32
GeometryGroup::SourceGeometryCount::get(
    )
{
    return GetInterface<ID2D1GeometryGroup>()->GetSourceGeometryCount();
}

ReadOnlyCollection<Geometry ^> ^
GeometryGroup::GetSourceGeometries(
    )
{

    UINT count = GetInterface<ID2D1GeometryGroup>()->GetSourceGeometryCount();
    vector<ID2D1Geometry*> sourcesVector(count);

    if (count > 0)
    {
        GetInterface<ID2D1GeometryGroup>()->GetSourceGeometries(
            &sourcesVector[0],
            count
            );
    }

    return CommonUtils::GetCollection<Geometry, ID2D1Geometry>(count, sourcesVector);
}

TransformedGeometry::TransformedGeometry(
    ) : Geometry()
{
}

TransformedGeometry::TransformedGeometry(
    IUnknown *pInner
    ) : Geometry(pInner)
{
}

Geometry ^
TransformedGeometry::GetSourceGeometry(
    )
{
    ID2D1Geometry * ptr = NULL;

    GetInterface<ID2D1TransformedGeometry>()->GetSourceGeometry(
        &ptr
        );
    return ptr ? gcnew Geometry(ptr) : nullptr;
}

Matrix3x2F
TransformedGeometry::Transform::get(
    )
{
    D2D1_MATRIX_3X2_F transformCopy;

        GetInterface<ID2D1TransformedGeometry>()->GetTransform(
            &transformCopy
            );

    Matrix3x2F transform;
    transform.CopyFrom(transformCopy);

    return transform;

}

Mesh::Mesh(
    ) : D2DResource()
{
}

Mesh::Mesh(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

TessellationSink ^
Mesh::Open(
    )
{
    ID2D1TessellationSink * ptr = NULL;
    CommonUtils::VerifyResult(GetInterface<ID2D1Mesh>()->Open(&ptr));
    return ptr ? gcnew TessellationSink(ptr) : nullptr;
}

Layer::Layer(
    ) : D2DResource()
{
}

Layer::Layer(
    IUnknown *pInner
    ) : D2DResource(pInner)
{
}

SizeF
Layer::Size::get(
    )
{
    D2D1_SIZE_F returnCopy;

    returnCopy =
        GetInterface<ID2D1Layer>()->GetSize(
            );

    SizeF returnValue;
    returnValue.CopyFrom(returnCopy);
    return returnValue;
}

D2DFactory::D2DFactory(
    ) : DirectUnknown()
{
}

D2DFactory::D2DFactory(
    IUnknown *pInner
    ) : DirectUnknown(pInner)
{
}

void
D2DFactory::ReloadSystemMetrics(
    )
{
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->ReloadSystemMetrics(
            ));
}

DpiF
D2DFactory::DesktopDpi::get(
    )
{
    ::FLOAT dpiXCopy;
    ::FLOAT dpiYCopy;

    GetInterface<ID2D1Factory>()->GetDesktopDpi(
        &dpiXCopy,
        &dpiYCopy
        );

   return DpiF(dpiXCopy, dpiYCopy);

}

RectangleGeometry ^
D2DFactory::CreateRectangleGeometry(
    RectF rectangle
    )
{
    D2D1_RECT_F rectangleCopy;
    rectangle.CopyTo(&rectangleCopy);

    ID2D1RectangleGeometry * ptr = NULL;

    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateRectangleGeometry(
            &rectangleCopy,
            &ptr
            ));

    return ptr ? gcnew RectangleGeometry(ptr) : nullptr;
}

RoundedRectangleGeometry ^
D2DFactory::CreateRoundedRectangleGeometry(
    RoundedRect roundedRectangle
    )
{
    D2D1_ROUNDED_RECT roundedRectangleCopy;
    roundedRectangle.CopyTo(&roundedRectangleCopy);

    ID2D1RoundedRectangleGeometry * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateRoundedRectangleGeometry(
            &roundedRectangleCopy,
            &ptr
            ));

    return ptr ? gcnew RoundedRectangleGeometry(ptr) : nullptr;
}

EllipseGeometry ^
D2DFactory::CreateEllipseGeometry(
    Ellipse ellipse
    )
{
    D2D1_ELLIPSE ellipseCopy;
    ellipse.CopyTo(&ellipseCopy);

    ID2D1EllipseGeometry * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateEllipseGeometry(
            &ellipseCopy,
            &ptr
            ));

    return ptr ? gcnew EllipseGeometry(ptr): nullptr;
}

GeometryGroup ^
D2DFactory::CreateGeometryGroup(
    FillMode fillMode,
    IEnumerable<Geometry ^> ^ geometries
    )
{

    vector<ID2D1Geometry*> geometryVector;
    UINT count = CommonUtils::FillIUnknownsVector<Geometry,ID2D1Geometry>(geometries, geometryVector);

    ID2D1GeometryGroup * ptr = NULL;
    
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateGeometryGroup(
            static_cast<D2D1_FILL_MODE>(fillMode),
            count > 0 ? &geometryVector[0] : NULL,
            count,
            &ptr
            ));

    return ptr ? gcnew GeometryGroup(ptr): nullptr;
}

TransformedGeometry ^
D2DFactory::CreateTransformedGeometry(
    Geometry ^ sourceGeometry,
    Matrix3x2F transform
    )
{
    D2D1_MATRIX_3X2_F transformCopy;
    transform.CopyTo(&transformCopy);

    ID2D1TransformedGeometry * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateTransformedGeometry(
            sourceGeometry->GetInterface<ID2D1Geometry>(),
            &transformCopy,
            &ptr
            ));

    return ptr ? gcnew TransformedGeometry(ptr): nullptr;
}

PathGeometry ^
D2DFactory::CreatePathGeometry(
    )
{
    ID2D1PathGeometry * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreatePathGeometry(
            &ptr
            ));

    return ptr ? gcnew PathGeometry(ptr): nullptr;
}

StrokeStyle ^
D2DFactory::CreateStrokeStyle(
    StrokeStyleProperties strokeStyleProperties,
    cli::array<FLOAT> ^ dashes
    )
{
    D2D1_STROKE_STYLE_PROPERTIES strokeStylePropertiesCopy;
    strokeStyleProperties.CopyTo(&strokeStylePropertiesCopy);
    ::FLOAT *dashesCopy = NULL;
    pin_ptr<FLOAT> dashesInner = dashes ? &dashes[0] : nullptr;
    dashesCopy = static_cast<::FLOAT *>(dashesInner);

    ID2D1StrokeStyle * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateStrokeStyle(
            &strokeStylePropertiesCopy,
            dashes ? dashesCopy : NULL,
            dashes ? dashes->Length : 0,
            &ptr
            ));

    return ptr ? gcnew StrokeStyle(ptr): nullptr;
}

StrokeStyle ^
D2DFactory::CreateStrokeStyle(
    StrokeStyleProperties strokeStyleProperties
    )
{
    return CreateStrokeStyle(strokeStyleProperties, nullptr);
}
RenderTarget ^
D2DFactory::CreateWicBitmapRenderTarget(
    WICBitmap^ target,
    RenderTargetProperties renderTargetProperties
    )
{
    D2D1_RENDER_TARGET_PROPERTIES renderTargetPropertiesCopy;
    renderTargetProperties.CopyTo(&renderTargetPropertiesCopy);

    ID2D1RenderTarget * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateWicBitmapRenderTarget(
            target->GetInterface<IWICBitmap>(),
            &renderTargetPropertiesCopy,
            &ptr
            ));

    return ptr ? gcnew RenderTarget(ptr): nullptr;
}

HwndRenderTarget ^
D2DFactory::CreateHwndRenderTarget(
    RenderTargetProperties renderTargetProperties,
    HwndRenderTargetProperties hwndRenderTargetProperties
    )
{
    D2D1_RENDER_TARGET_PROPERTIES renderTargetPropertiesCopy;
    renderTargetProperties.CopyTo(&renderTargetPropertiesCopy);
    D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRenderTargetPropertiesCopy;
    hwndRenderTargetProperties.CopyTo(&hwndRenderTargetPropertiesCopy);

    ID2D1HwndRenderTarget * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateHwndRenderTarget(
            &renderTargetPropertiesCopy,
            &hwndRenderTargetPropertiesCopy,
            &ptr
            ));

    return ptr ? gcnew HwndRenderTarget(ptr): nullptr;
}

RenderTarget ^
D2DFactory::CreateDxgiSurfaceRenderTarget(
    Surface^ dxgiSurface,
    RenderTargetProperties renderTargetProperties
    )
{
    D2D1_RENDER_TARGET_PROPERTIES renderTargetPropertiesCopy;
    renderTargetProperties.CopyTo(&renderTargetPropertiesCopy);

    ID2D1RenderTarget * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateDxgiSurfaceRenderTarget(
            dxgiSurface->GetInterface<IDXGISurface>(),
            &renderTargetPropertiesCopy,
            &ptr
            ));

    return ptr ? gcnew RenderTarget(ptr): nullptr;
}

DCRenderTarget ^
D2DFactory::CreateDCRenderTarget(
    RenderTargetProperties renderTargetProperties
    )
{
    D2D1_RENDER_TARGET_PROPERTIES renderTargetPropertiesCopy;
    renderTargetProperties.CopyTo(&renderTargetPropertiesCopy);

    ID2D1DCRenderTarget * ptr = NULL;
    CommonUtils::VerifyResult(
        GetInterface<ID2D1Factory>()->CreateDCRenderTarget(
            &renderTargetPropertiesCopy,
            &ptr
            ));

    return ptr ? gcnew DCRenderTarget(ptr): nullptr;
}

} } } }

