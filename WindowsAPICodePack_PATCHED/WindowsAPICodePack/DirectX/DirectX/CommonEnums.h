//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

// This is defined in DX SDK
#ifndef D2DERR_WRONG_RESOURCE_DOMAIN
    #define D2DERR_WRONG_RESOURCE_DOMAIN MAKE_D2DHR_ERR(0x015)
#endif

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX {

/// <summary>
/// Error codes that can be returned by DXGI, Direct3D, Direct2D, DirectWrite or WIC
/// </summary>
public enum class ErrorCode
{
    /// <summary>
    /// The method succeeded without an error. 
    /// </summary>
    Success = S_OK ,

    /// <summary>
    /// Alternate success value, indicating a successful but nonstandard completion (the precise meaning depends on context).
    /// </summary>
    FalseSuccess =  S_FALSE,

    /// <summary>
    /// An invalid parameter was passed to the returning function.
    /// </summary>
    InvalidArgument = E_INVALIDARG,

    /// <summary>
    /// Could not allocate sufficient memory to complete the call.
    /// </summary>
    OutOfMemory = E_OUTOFMEMORY,

    /// <summary>
    /// Unspecified or generic error.
    /// </summary>
    Fail = E_FAIL,
    
    /// <summary>
    /// Not implemented.
    /// </summary>
    NotImplemented = E_NOTIMPL,
    

    /// <summary>
    /// Aborted.
    /// </summary>
    Aborted = E_ABORT,    

    /// <summary>
    /// Access Denied.
    /// </summary>
    AccessDenied = E_ACCESSDENIED,
    
    /// <summary>
    /// The application's device failed due to badly formed commands sent by the application. This is an design-time issue that should be investigated and fixed. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DEVICE_HUNG )</para>
    /// </summary>
    DXGIErrorDeviceHung = DXGI_ERROR_DEVICE_HUNG,

    /// <summary>
    /// The video card has been physically removed from the system, or a driver upgrade for the video card has occurred. The application should destroy and recreate the device. For help debugging the problem, call Device.GetDeviceRemovedReason(). 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DEVICE_REMOVED )</para>
    /// </summary>
    DXGIErrorDeviceRemoved = DXGI_ERROR_DEVICE_REMOVED ,

    /// <summary>
    /// The device failed due to a badly formed command. This is a run-time issue; The application should destroy and recreate the device. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DEVICE_RESET )</para>
    /// </summary>
    DXGIErrorDeviceReset = DXGI_ERROR_DEVICE_RESET ,
   
    /// <summary>
    /// The driver encountered a problem and was put into the device removed state. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DRIVER_INTERNAL_ERROR )</para>
    /// </summary>
    DXGIErrorDriverInternalError = DXGI_ERROR_DRIVER_INTERNAL_ERROR ,
    
    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_FRAME_STATISTICS_DISJOINT )</para>
    /// </summary>    
    DXGIErrorFrameStatisticsDisjoint = DXGI_ERROR_FRAME_STATISTICS_DISJOINT ,

    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE )</para>
    /// </summary>
    DXGIErrorGraphicsVidpnSourceInUse = DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE ,
    
    /// <summary>
    /// The application provided invalid parameter data; this must be debugged and fixed before the application is released. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_INVALID_CALL )</para>
    /// </summary>
    DXGIErrorInvalidCcall = DXGI_ERROR_INVALID_CALL ,
    
    /// <summary>
    /// The buffer supplied by the application is not big enough to hold the requested data. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_MORE_DATA )</para>
    /// </summary>
    DXGIErrorMoreData = DXGI_ERROR_MORE_DATA ,
   
    /// <summary>
    /// The application attempted to acquire exclusive ownership of an output, but failed because some other application (or device within the application) has already acquired ownership. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_NONEXCLUSIVE )</para>
    /// </summary>
    DXGIErrorNonExclusive = DXGI_ERROR_NONEXCLUSIVE ,
    
    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_NOT_CURRENTLY_AVAILABLE )</para>
    /// </summary>
    DXGIErrorNotCurrentlyAvailable = DXGI_ERROR_NOT_CURRENTLY_AVAILABLE ,

    /// <summary>
    /// When calling DXGIObject.GetPrivateData, the GUID passed in is not recognized as one previously passed to DXGIObject::SetPrivateData or DXGIObject::SetPrivateDataInterface. 
    /// When calling DXGIFactory::EnumAdapters or Adapter::EnumOutputs, the enumerated ordinal is out of range. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_NOT_FOUND )</para>
    /// </summary>
    DXGIErrorNotFound = DXGI_ERROR_NOT_FOUND ,
   
    /// <summary>
    /// The application's remote device has been removed due to session disconnect or network disconnect. The application should call IDXGIFactory1::IsCurrent to find out when the remote device becomes available again. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED )</para>
    /// </summary>
    DXGIErrorRemoteClientDisconnected = DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED ,

    /// <summary>
    /// The application's remote device has failed due to lack of memory or machine error. The application should destroy and recreate resources using less memory. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_REMOTE_OUTOFMEMORY )</para>
    /// </summary>
    DXGIErrorRemoteOutOfMemory = DXGI_ERROR_REMOTE_OUTOFMEMORY ,
    
    /// <summary>
    /// The device was busy, and did not schedule the requested task. This error only applies to asynchronous queries in Direct3D 10. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_WAS_STILL_DRAWING )</para>
    /// </summary>
    DXGIErrorWasStillDrawing = DXGI_ERROR_WAS_STILL_DRAWING ,
   
    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_UNSUPPORTED )</para>
    /// </summary>
    DXGIErrorUnsupported = DXGI_ERROR_UNSUPPORTED ,   

    /// <summary>
    /// The file was not found. 
    /// <para>(Also see DirectX SDK:  D3D11_ERROR_FILE_NOT_FOUND )</para>
    /// </summary>
    Direct3D11ErrorFileNotFound =  D3D11_ERROR_FILE_NOT_FOUND,

    /// <summary>
    /// There are too many unique instances of a particular type of state object.
    /// <para>(Also see DirectX SDK:  D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS )</para>
    /// </summary>
    Direct3D11ErrorTooManyUniqueInstances =  D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS,

    /// <summary>
    /// There are too many unique instances of a particular type of state object.
    /// <para>(Also see DirectX SDK:  D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS )</para>
    /// </summary>
    Direct3D10ErrorTooManyUniqueInstances =  D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS,

    /// <summary>
    /// The file was not found. 
    /// <para>(Also see DirectX SDK:  D3D10_ERROR_FILE_NOT_FOUND )</para>
    /// </summary>
    Direct3D10ErrorFileNotFound =  D3D10_ERROR_FILE_NOT_FOUND,


    /// <summary>
    /// The number is invalid
    /// </summary>
    Direct2DErrorBadNumber = D2DERR_BAD_NUMBER,
        

    /// <summary>
    /// The display format to render is not supported by the hardware device
    /// </summary>
    Direct2DErrorDisplayFormatNotSupported =  D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED, 
        

    /// <summary>
    /// A valid display state could not be determined
    /// </summary>
    Direct2DErrorDisplayStateInvalid = D2DERR_DISPLAY_STATE_INVALID, 
        

    /// <summary>
    /// The requested size is larger than the guaranteed supported texture size
    /// </summary>
    Direct2DErrorExceedsMaxBitmapSize = D2DERR_EXCEEDS_MAX_BITMAP_SIZE, 
        

    /// <summary>
    /// The brush types are incompatible for the call
    /// </summary>
    Direct2DErrorIncompatibleBrushTypes = D2DERR_INCOMPATIBLE_BRUSH_TYPES, 
        

    /// <summary>
    /// The supplied buffer is too small to accommodate the data
    /// </summary>
    Direct2DErrorInsufficientBuffer = ERROR_INSUFFICIENT_BUFFER, 
        

    /// <summary>
    /// The application should close this instance of Direct2D and restart it as a new process
    /// </summary>
    Direct2DErrorInternalError = D2DERR_INTERNAL_ERROR, 
        

    /// <summary>
    /// A call to this method is invalid
    /// </summary>
    Direct2DErrorInvalidCall = D2DERR_INVALID_CALL, 
        

    /// <summary>
    /// The application attempted to reuse a layer resource that has not yet been popped off the stack
    /// </summary>
    Direct2DErrorLayerAlreadyInUse = D2DERR_LAYER_ALREADY_IN_USE, 
        

    /// <summary>
    /// The requested DX surface size exceeds the maximum texture size
    /// </summary>
    Direct2DErrorMaxTextureSizeExceeded = D2DERR_MAX_TEXTURE_SIZE_EXCEEDED, 
        

    /// <summary>
    /// There is no hardware rendering device available for this operation
    /// </summary>
    Direct2DErrorNO_HARDWARE_DEVICE = D2DERR_NO_HARDWARE_DEVICE, 
        
    
    /// <summary>
    /// The object has not yet been initialized
    /// </summary>
    Direct2DErrorNotInitialized = D2DERR_NOT_INITIALIZED, 
        
    
    /// <summary>
    /// The application attempted to pop a layer off the stack when a clip was at the top, or pop a clip off the stack when a layer was at the top
    /// </summary>
    Direct2DErrorPopCallDidNotMatchPush = D2DERR_POP_CALL_DID_NOT_MATCH_PUSH, 
        
    
    /// <summary>
    /// The application did not pop all clips and layers off the stack, or it attempted to pop too many clips or layers off the stack.
    /// </summary>
    Direct2DErrorPushPopUnbalanced = D2DERR_PUSH_POP_UNBALANCED, 
        
    
    /// <summary>
    /// A presentation error has occurred that may be recoverable. The caller needs to re-create the render target, render the entire frame again, and reattempt presentation
    /// </summary>
    Direct2DErrorRecreateTarget = D2DERR_RECREATE_TARGET, 
        
    
    /// <summary>
    /// The application attempted to copy the contents of a render target before popping all layers and clips off the stack
    /// </summary>
    Direct2DErrorRenderTargetHasLayerOrCliprect = D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT, 
        
    
    /// <summary>
    /// The geomery scanner failed to process the data
    /// </summary>
    Direct2DErrorScannerFailed = D2DERR_SCANNER_FAILED, 
        
    
    /// <summary>
    /// Direct2D could not access the screen
    /// </summary>
    Direct2DErrorScreenAccessDenied = D2DERR_SCREEN_ACCESS_DENIED, 
        
    
    /// <summary>
    /// Shader compilation failed
    /// </summary>
    Direct2DErrorShaderCompileFailed = D2DERR_SHADER_COMPILE_FAILED, 
        
    
    /// <summary>
    /// The render target is not compatible with GDI
    /// </summary>
    Direct2DErrorTargetNotGdiCompatible = D2DERR_TARGET_NOT_GDI_COMPATIBLE, 
        
    
    /// <summary>
    /// A text client drawing effect object is of the wrong type
    /// </summary>
    Direct2DErrorTextEffectIsWrongType = D2DERR_TEXT_EFFECT_IS_WRONG_TYPE, 
        
    
    /// <summary>
    /// An application is holding a reference to the IDWriteTextRenderer interface after the corresponding DrawText or DrawTextLayout call has returned
    /// </summary>
    Direct2DErrorTextRendererNotReleased = D2DERR_TEXT_RENDERER_NOT_RELEASED, 
        
    
    /// <summary>
    /// Shader construction failed because it was too complex
    /// </summary>
    Direct2DErrorTooManyShaderElements = D2DERR_TOO_MANY_SHADER_ELEMENTS, 
        
    
    /// <summary>
    /// The requested operation is not supported
    /// </summary>
    Direct2DErroUnsupportedOperation = D2DERR_UNSUPPORTED_OPERATION, 
        
    
    /// <summary>
    /// The requested Direct2D version is not supported
    /// </summary>
    Direct2DErrorUnsupportedVersion = D2DERR_UNSUPPORTED_VERSION, 
        
    
    /// <summary>
    /// An unknown Win32 failure occurred
    /// </summary>
    Direct2DErrorWin32Error = D2DERR_WIN32_ERROR, 
        
    
    /// <summary>
    /// Objects used together were not all created from the same factory instance
    /// </summary>
    Direct2DErrorWrongFactory = D2DERR_WRONG_FACTORY, 
        
    
    /// <summary>
    /// The resource used was created by a render target in a different resource domain
    /// </summary>
    Direct2DErrorWrongResourceDomain = D2DERR_WRONG_RESOURCE_DOMAIN, 
        
    
    /// <summary>
    /// The object was not in the correct state to process the method
    /// </summary>
    Direct2DErrorWrongState = D2DERR_WRONG_STATE, 
        
    
    /// <summary>
    /// The supplied vector is zero
    /// </summary>
    Direct2DErrorZeroVector = D2DERR_ZERO_VECTOR, 
        
    /// <summary>
    /// Already locked.
    /// </summary>
    WICErrorAlreadyLocked =  WINCODEC_ERR_ALREADYLOCKED , 
    
    
    /// <summary>
    /// Bad header.
    /// </summary>
    WICErrorBadHeader =  WINCODEC_ERR_BADHEADER  ,
    
    
    /// <summary>
    /// Bad image.
    /// </summary>
    WICErrorBadImage =  WINCODEC_ERR_BADIMAGE  ,
    
    
    /// <summary>
    /// Bad meta data header.
    /// </summary>
    WICErrorBadMetaDataHeader =  WINCODEC_ERR_BADMETADATAHEADER , 
    
    
    /// <summary>
    /// Bad stream data.
    /// </summary>
    WICErrorBadStreamData =  WINCODEC_ERR_BADSTREAMDATA  ,
    
    
    /// <summary>
    /// Codec no Thumbnail.
    /// </summary>
    WICErrorCodecNoThumbnail =  WINCODEC_ERR_CODECNOTHUMBNAIL  ,
    
    
    /// <summary>
    /// Codec present.
    /// </summary>
    WICErrorCodecPresent =  WINCODEC_ERR_CODECPRESENT , 
    
    
    /// <summary>
    /// codectoomanyscanlines.
    /// </summary>
    WICErrorCodecTooManyScanLines =  WINCODEC_ERR_CODECTOOMANYSCANLINES , 
    
    
    /// <summary>
    /// Component Initialize Failure.
    /// </summary>
    WICErrorComponentInitializeFailure =  WINCODEC_ERR_COMPONENTINITIALIZEFAILURE , 
    
    
    /// <summary>
    /// ComponentNotFound.
    /// </summary>
    WICErrorComponentNotFound =  WINCODEC_ERR_COMPONENTNOTFOUND , 
    
    
    /// <summary>
    /// Duplicate meta data present.
    /// </summary>
    WICErrorDuplicateMetaDataPresent =  WINCODEC_ERR_DUPLICATEMETADATAPRESENT  ,
    
    
    /// <summary>
    /// Frame missing.
    /// </summary>
    WICErrorFrameMissing =  WINCODEC_ERR_FRAMEMISSING  ,
    
    
    /// <summary>
    /// Generic Error.
    /// </summary>
    WICErrorGeneric =  WINCODEC_ERR_GENERIC_ERROR  ,
    
    
    /// <summary>
    /// Image size out of range.
    /// </summary>
    WICErrorImageSizeOutOfRange =  WINCODEC_ERR_IMAGESIZEOUTOFRANGE  ,
    
    
    /// <summary>
    /// Insufficient buffer.
    /// </summary>
    WICErrorInsufficientBuffer =  WINCODEC_ERR_INSUFFICIENTBUFFER  ,
    
    
    /// <summary>
    /// Internal error.
    /// </summary>
    WICErrorInternal =  WINCODEC_ERR_INTERNALERROR  ,
    
    /// <summary>
    /// invalidquerycharacter.
    /// </summary>
    WICErrorinvalidquerycharacter =  WINCODEC_ERR_INVALIDQUERYCHARACTER  ,
    
    
    /// <summary>
    /// Invalid query request.
    /// </summary>
    WICErrorInvalidQueryRequest =  WINCODEC_ERR_INVALIDQUERYREQUEST  ,
    
    
    /// <summary>
    /// Invalid registration.
    /// </summary>
    WICErrorInvalidRegistration =  WINCODEC_ERR_INVALIDREGISTRATION  ,
    

    /// <summary>
    /// Not initialized.
    /// </summary>
    WICErrorNotInitialized =  WINCODEC_ERR_NOTINITIALIZED  ,
    
        
    /// <summary>
    /// Palette unavailable.
    /// </summary>
    WICErrorPaletteUnavailable =  WINCODEC_ERR_PALETTEUNAVAILABLE  ,
    
    
    /// <summary>
    /// Property not found.
    /// </summary>
    WICErrorPropertyNotFound =  WINCODEC_ERR_PROPERTYNOTFOUND  ,
    
    
    /// <summary>
    /// Property not supported.
    /// </summary>
    WICErrorPropertyNotSupported =  WINCODEC_ERR_PROPERTYNOTSUPPORTED  ,
    
    
    /// <summary>
    /// Property size.
    /// </summary>
    WICErrorPropertySize =  WINCODEC_ERR_PROPERTYSIZE , 
    
    
    /// <summary>
    /// Property unexpected type.
    /// </summary>
    WICErrorPropertyUnexpectedType =  WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE  ,
    
    
    /// <summary>
    /// Request only valid at meta data root.
    /// </summary>
    WICErrorRequestOnlyValidAtMetaDataRoot =  WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT , 
    
    
    /// <summary>
    /// Source rectangle does not match dimensions.
    /// </summary>
    WICErrorSourceRectDoesNotMatchDimensions =  WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS  ,
    
    
    /// <summary>
    /// Stream write.
    /// </summary>
    WICErrorStreamWrite =  WINCODEC_ERR_STREAMWRITE  ,
    
    
    /// <summary>
    /// Stream read.
    /// </summary>
    WICErrorStreamRead =  WINCODEC_ERR_STREAMREAD , 
    
    
    /// <summary>
    /// Stream not available.
    /// </summary>
    WICErrorStreamNotAvailable =  WINCODEC_ERR_STREAMNOTAVAILABLE  ,
    
    
    /// <summary>
    /// Too much meta data.
    /// </summary>
    WICErrorTooMuchMetaData =  WINCODEC_ERR_TOOMUCHMETADATA  ,
    
    
    /// <summary>
    /// Unknown image format.
    /// </summary>
    WICErrorUnknownImageFormat =  WINCODEC_ERR_UNKNOWNIMAGEFORMAT  ,
    
    
    /// <summary>
    /// Unexpected meta data type.
    /// </summary>
    WICErrorUnexpectedMetaDataType =  WINCODEC_ERR_UNEXPECTEDMETADATATYPE  ,
    
    
    /// <summary>
    /// Unexpected size.
    /// </summary>
    WICErrorUnexpectedSize =  WINCODEC_ERR_UNEXPECTEDSIZE  ,
    
    
    /// <summary>
    /// Onsupported operation.
    /// </summary>
    WICErroruUsupportedOperation =  WINCODEC_ERR_UNSUPPORTEDOPERATION  ,
    
    
    /// <summary>
    /// Unsupported Pixel Format.
    /// </summary>
    WICErrorUnsupportedPixelFormat =  WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT  ,
    
    
    /// <summary>
    /// Unsupported Version.
    /// </summary>
    WICErrorUnsupportedVersion =  WINCODEC_ERR_UNSUPPORTEDVERSION , 
    
    
    /// <summary>
    /// Value Out Of Range.
    /// </summary>
    WICErrorValueOutOfRange =  WINCODEC_ERR_VALUEOUTOFRANGE  ,
    
    /// <summary>
    /// Value Overflow.
    /// </summary>
    WICErrorValueOverflow =  WINCODEC_ERR_VALUEOVERFLOW  ,
    
    
    /// <summary>
    /// Wrong state.
    /// </summary>
    WICErrorWrongState =  WINCODEC_ERR_WRONGSTATE  ,
    

};

/// <summary>
/// Defines a set of predefined colors.
/// </summary>
public enum class Colors
{
    AliceBlue = 0xF0F8FF,
    AntiqueWhite = 0xFAEBD7,
    Aqua = 0x00FFFF,
    Aquamarine = 0x7FFFD4,
    Azure = 0xF0FFFF,
    Beige = 0xF5F5DC,
    Bisque = 0xFFE4C4,
    Black = 0x000000,
    BlanchedAlmond = 0xFFEBCD,
    Blue = 0x0000FF,
    BlueViolet = 0x8A2BE2,
    Brown = 0xA52A2A,
    BurlyWood = 0xDEB887,
    CadetBlue = 0x5F9EA0,
    Chartreuse = 0x7FFF00,
    Chocolate = 0xD2691E,
    Coral = 0xFF7F50,
    CornflowerBlue = 0x6495ED,
    Cornsilk = 0xFFF8DC,
    Crimson = 0xDC143C,
    Cyan = 0x00FFFF,
    DarkBlue = 0x00008B,
    DarkCyan = 0x008B8B,
    DarkGoldenrod = 0xB8860B,
    DarkGray = 0xA9A9A9,
    DarkGreen = 0x006400,
    DarkKhaki = 0xBDB76B,
    DarkMagenta = 0x8B008B,
    DarkOliveGreen = 0x556B2F,
    DarkOrange = 0xFF8C00,
    DarkOrchid = 0x9932CC,
    DarkRed = 0x8B0000,
    DarkSalmon = 0xE9967A,
    DarkSeaGreen = 0x8FBC8F,
    DarkSlateBlue = 0x483D8B,
    DarkSlateGray = 0x2F4F4F,
    DarkTurquoise = 0x00CED1,
    DarkViolet = 0x9400D3,
    DeepPink = 0xFF1493,
    DeepSkyBlue = 0x00BFFF,
    DimGray = 0x696969,
    DodgerBlue = 0x1E90FF,
    Firebrick = 0xB22222,
    FloralWhite = 0xFFFAF0,
    ForestGreen = 0x228B22,
    Fuchsia = 0xFF00FF,
    Gainsboro = 0xDCDCDC,
    GhostWhite = 0xF8F8FF,
    Gold = 0xFFD700,
    Goldenrod = 0xDAA520,
    Gray = 0x808080,
    Green = 0x008000,
    GreenYellow = 0xADFF2F,
    Honeydew = 0xF0FFF0,
    HotPink = 0xFF69B4,
    IndianRed = 0xCD5C5C,
    Indigo = 0x4B0082,
    Ivory = 0xFFFFF0,
    Khaki = 0xF0E68C,
    Lavender = 0xE6E6FA,
    LavenderBlush = 0xFFF0F5,
    LawnGreen = 0x7CFC00,
    LemonChiffon = 0xFFFACD,
    LightBlue = 0xADD8E6,
    LightCoral = 0xF08080,
    LightCyan = 0xE0FFFF,
    LightGoldenrodYellow = 0xFAFAD2,
    LightGreen = 0x90EE90,
    LightGray = 0xD3D3D3,
    LightPink = 0xFFB6C1,
    LightSalmon = 0xFFA07A,
    LightSeaGreen = 0x20B2AA,
    LightSkyBlue = 0x87CEFA,
    LightSlateGray = 0x778899,
    LightSteelBlue = 0xB0C4DE,
    LightYellow = 0xFFFFE0,
    Lime = 0x00FF00,
    LimeGreen = 0x32CD32,
    Linen = 0xFAF0E6,
    Magenta = 0xFF00FF,
    Maroon = 0x800000,
    MediumAquamarine = 0x66CDAA,
    MediumBlue = 0x0000CD,
    MediumOrchid = 0xBA55D3,
    MediumPurple = 0x9370DB,
    MediumSeaGreen = 0x3CB371,
    MediumSlateBlue = 0x7B68EE,
    MediumSpringGreen = 0x00FA9A,
    MediumTurquoise = 0x48D1CC,
    MediumVioletRed = 0xC71585,
    MidnightBlue = 0x191970,
    MintCream = 0xF5FFFA,
    MistyRose = 0xFFE4E1,
    Moccasin = 0xFFE4B5,
    NavajoWhite = 0xFFDEAD,
    Navy = 0x000080,
    OldLace = 0xFDF5E6,
    Olive = 0x808000,
    OliveDrab = 0x6B8E23,
    Orange = 0xFFA500,
    OrangeRed = 0xFF4500,
    Orchid = 0xDA70D6,
    PaleGoldenrod = 0xEEE8AA,
    PaleGreen = 0x98FB98,
    PaleTurquoise = 0xAFEEEE,
    PaleVioletRed = 0xDB7093,
    PapayaWhip = 0xFFEFD5,
    PeachPuff = 0xFFDAB9,
    Peru = 0xCD853F,
    Pink = 0xFFC0CB,
    Plum = 0xDDA0DD,
    PowderBlue = 0xB0E0E6,
    Purple = 0x800080,
    Red = 0xFF0000,
    RosyBrown = 0xBC8F8F,
    RoyalBlue = 0x4169E1,
    SaddleBrown = 0x8B4513,
    Salmon = 0xFA8072,
    SandyBrown = 0xF4A460,
    SeaGreen = 0x2E8B57,
    SeaShell = 0xFFF5EE,
    Sienna = 0xA0522D,
    Silver = 0xC0C0C0,
    SkyBlue = 0x87CEEB,
    SlateBlue = 0x6A5ACD,
    SlateGray = 0x708090,
    Snow = 0xFFFAFA,
    SpringGreen = 0x00FF7F,
    SteelBlue = 0x4682B4,
    Tan = 0xD2B48C,
    Teal = 0x008080,
    Thistle = 0xD8BFD8,
    Tomato = 0xFF6347,
    Turquoise = 0x40E0D0,
    Violet = 0xEE82EE,
    Wheat = 0xF5DEB3,
    White = 0xFFFFFF,
    WhiteSmoke = 0xF5F5F5,
    Yellow = 0xFFFF00,
    YellowGreen = 0x9ACD32,
};

} }  }
