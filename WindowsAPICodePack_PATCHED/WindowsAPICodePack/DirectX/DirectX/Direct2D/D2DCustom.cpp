// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "CommonUtils.h"
#include "LibraryLoader.h"
#include "DirectWrite/DWriteRenderingParams.h"

using namespace System::Runtime::InteropServices;

typedef HRESULT (*D2D1CreateFactoryFuncPtr)(
  D2D1_FACTORY_TYPE factoryType,
  REFIID riid,
  const D2D1_FACTORY_OPTIONS *pFactoryOptions,
  void **ppIFactory
    );

namespace Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct2D1 {

    namespace D2D = Microsoft::WindowsAPICodePack::DirectX::Direct2D1;

    D2DFactory ^
    D2DFactory::CreateFactory() 
    {
        return CreateFactory(D2DFactoryType::SingleThreaded, FactoryOptions(DebugLevel::None));
    };

    D2DFactory ^
    D2DFactory::CreateFactory(
        D2DFactoryType factoryType
        ) 
    {
        return CreateFactory(factoryType, FactoryOptions(DebugLevel::None));
    };

    D2DFactory ^
    D2DFactory::CreateFactory(
        D2DFactoryType factoryType,
        FactoryOptions factoryOptions
        ) 
    {
        D2D1CreateFactoryFuncPtr createFuncPtr = 
            (D2D1CreateFactoryFuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
                D2DLibrary, "D2D1CreateFactory");

        ID2D1Factory *pIFactory = NULL;
        D2D1_FACTORY_OPTIONS factoryOptionsCopy;
        factoryOptions.CopyTo(&factoryOptionsCopy);

        CommonUtils::VerifyResult(
            (*createFuncPtr)(
                static_cast<D2D1_FACTORY_TYPE>(factoryType),
                __uuidof(ID2D1Factory),
                &factoryOptionsCopy,
                (void**)&pIFactory));                        

        return pIFactory ? gcnew D2DFactory(pIFactory) : nullptr;
    };

    DrawingStateBlock ^
    D2DFactory::CreateDrawingStateBlock(
        DrawingStateDescription drawingStateDescription,
        RenderingParams^ textRenderingParams
        )
    {
        D2D1_DRAWING_STATE_DESCRIPTION drawingStateDescriptionCopy;
        drawingStateDescription.CopyTo(&drawingStateDescriptionCopy);

        ID2D1DrawingStateBlock * ptr = NULL;
        CommonUtils::VerifyResult(
            GetInterface<ID2D1Factory>()->CreateDrawingStateBlock(
                &drawingStateDescriptionCopy,
                textRenderingParams == nullptr ? NULL : textRenderingParams->GetInterface<IDWriteRenderingParams>(),
                &ptr
                ));
    
        return ptr ? gcnew DrawingStateBlock(ptr) : nullptr;
    }

    DrawingStateBlock ^
    D2DFactory::CreateDrawingStateBlock(
        DrawingStateDescription drawingStateDescription
        )
    {
        D2D1_DRAWING_STATE_DESCRIPTION drawingStateDescriptionCopy;
        drawingStateDescription.CopyTo(&drawingStateDescriptionCopy);


        ID2D1DrawingStateBlock * ptr = NULL;
        CommonUtils::VerifyResult(
            GetInterface<ID2D1Factory>()->CreateDrawingStateBlock(
                &drawingStateDescriptionCopy,
                NULL,
                &ptr
                ));
    
        return ptr ? gcnew DrawingStateBlock(ptr) : nullptr;
    }

    DrawingStateBlock ^
    D2DFactory::CreateDrawingStateBlock(
        )
    {
        ID2D1DrawingStateBlock * ptr = NULL;
        CommonUtils::VerifyResult(
            GetInterface<ID2D1Factory>()->CreateDrawingStateBlock(
                NULL,
                NULL,
                &ptr
                ));
    
        return ptr ? gcnew DrawingStateBlock(ptr) : nullptr;
    }

    //
    // Implement methods for sink interfaces
    // 
    void
    Geometry::Simplify(
        GeometrySimplificationOption simplificationOption,
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance,
        Matrix3x2F pWorldTransform
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        D2D1_MATRIX_3X2_F copyWorldTransform;
        pWorldTransform.CopyTo(&copyWorldTransform);

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Simplify(
                static_cast<D2D1_GEOMETRY_SIMPLIFICATION_OPTION>(simplificationOption),
                &copyWorldTransform,
                flatteningTolerance,
                pGeometrySinkCallback
                )); 
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::Simplify(
        GeometrySimplificationOption simplificationOption,
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Simplify(
                static_cast<D2D1_GEOMETRY_SIMPLIFICATION_OPTION>(simplificationOption),
                NULL,
                flatteningTolerance,
                pGeometrySinkCallback
                )); 
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::Simplify(
        GeometrySimplificationOption simplificationOption,
        ISimplifiedGeometrySink ^ pIGeometrySink
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Simplify(
                static_cast<D2D1_GEOMETRY_SIMPLIFICATION_OPTION>(simplificationOption),
                NULL,
                pGeometrySinkCallback
                )); 
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::CombineWithGeometry(
        Geometry ^ pInputGeometry,
        CombineMode combineMode,
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance,
        Matrix3x2F pInputGeometryTransform
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        D2D1_MATRIX_3X2_F copyInputGeometryTransform;
        pInputGeometryTransform.CopyTo(&copyInputGeometryTransform);

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->CombineWithGeometry(
                pInputGeometry->GetInterface<ID2D1Geometry>(),
                static_cast<D2D1_COMBINE_MODE>(combineMode),
                &copyInputGeometryTransform,
                flatteningTolerance,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }
    

    void
    Geometry::CombineWithGeometry(
        Geometry ^ pInputGeometry,
        CombineMode combineMode,
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->CombineWithGeometry(
                pInputGeometry->GetInterface<ID2D1Geometry>(),
                static_cast<D2D1_COMBINE_MODE>(combineMode),
                NULL,
                flatteningTolerance,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }
    
    void
    Geometry::CombineWithGeometry(
        Geometry ^ pInputGeometry,
        CombineMode combineMode,
        ISimplifiedGeometrySink ^ pIGeometrySink
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->CombineWithGeometry(
                pInputGeometry->GetInterface<ID2D1Geometry>(),
                static_cast<D2D1_COMBINE_MODE>(combineMode),
                NULL,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::Outline(
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance,
        Matrix3x2F pWorldTransform
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        D2D1_MATRIX_3X2_F copyWorldTransform;
        pWorldTransform.CopyTo(&copyWorldTransform);

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Outline(
                &copyWorldTransform,
                flatteningTolerance,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::Outline(
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Outline(
                NULL,
                flatteningTolerance,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::Outline(
        ISimplifiedGeometrySink ^ pIGeometrySink
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Outline(
                NULL,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }
    }

    void
    Geometry::Widen(
        FLOAT strokeWidth,
        StrokeStyle ^ pIStrokeStyle,
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance,
        Matrix3x2F pWorldTransform
        )
    {
        D2D1_MATRIX_3X2_F copyWorldTransform;
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        pWorldTransform.CopyTo(&copyWorldTransform);

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Widen(
                strokeWidth,
                pIStrokeStyle->GetInterface<ID2D1StrokeStyle>(),
                &copyWorldTransform,
                flatteningTolerance,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }        
    }

    void
    Geometry::Widen(
        FLOAT strokeWidth,
        StrokeStyle ^ pIStrokeStyle,
        ISimplifiedGeometrySink ^ pIGeometrySink,
        FLOAT flatteningTolerance
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Widen(
                strokeWidth,
                pIStrokeStyle->GetInterface<ID2D1StrokeStyle>(),
                NULL,
                flatteningTolerance,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }        
    }

    void
    Geometry::Widen(
        FLOAT strokeWidth,
        StrokeStyle ^ pIStrokeStyle,
        ISimplifiedGeometrySink ^ pIGeometrySink
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Widen(
                strokeWidth,
                pIStrokeStyle->GetInterface<ID2D1StrokeStyle>(),
                NULL,
                pGeometrySinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }        
    }

    void
    Geometry::Tessellate(
        ITessellationSink ^ pITessellationSink,
        FLOAT flatteningTolerance,
        Matrix3x2F pWorldTransform
        )
    {
        D2D::TessellationSinkCallback *pTessellationSinkCallback = NULL;

        D2D1_MATRIX_3X2_F copyWorldTransform;
        pWorldTransform.CopyTo(&copyWorldTransform);

        try
        {
            pTessellationSinkCallback = new D2D::TessellationSinkCallback(
                pITessellationSink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Tessellate(
                &copyWorldTransform,
                flatteningTolerance,
                pTessellationSinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pTessellationSinkCallback);
        }        
    }


    void
    Geometry::Tessellate(
        ITessellationSink ^ pITessellationSink,
        FLOAT flatteningTolerance
        )
    {
        D2D::TessellationSinkCallback *pTessellationSinkCallback = NULL;

        try
        {
            pTessellationSinkCallback = new D2D::TessellationSinkCallback(
                pITessellationSink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Tessellate(
                NULL,
                flatteningTolerance,
                pTessellationSinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pTessellationSinkCallback);
        }        
    }

    void
    Geometry::Tessellate(
        ITessellationSink ^ pITessellationSink
        )
    {
        D2D::TessellationSinkCallback *pTessellationSinkCallback = NULL;

        try
        {
            pTessellationSinkCallback = new D2D::TessellationSinkCallback(
                pITessellationSink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1Geometry>()->Tessellate(
                NULL,
                pTessellationSinkCallback
                ));
        }
        __finally
        {
            ReleaseInterface(pTessellationSinkCallback);
        }        
    }

    void
    PathGeometry::Stream(
        IGeometrySink ^ pIGeometrySink
        )
    {
        D2D::GeometrySinkCallback *pGeometrySinkCallback = NULL;

        try
        {
            pGeometrySinkCallback = new D2D::GeometrySinkCallback(
                pIGeometrySink
                );

            CommonUtils::VerifyResult(GetInterface<ID2D1PathGeometry>()->Stream(
                pGeometrySinkCallback
                ));            
        }
        __finally
        {
            ReleaseInterface(pGeometrySinkCallback);
        }        
    }

} } } }
