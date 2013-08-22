//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectUnknown.h"
#include "WICStructs.h"

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace WindowsImagingComponent {

/// <summary>
/// Defines methods that add the concept of writeability and static in-memory representations 
/// of bitmaps to WICBitmapSource. 
/// <para>(Also see IWICBitmap interface)</para>
/// </summary>
    public ref class WICBitmapLock :  public DirectUnknown
{
public:

    /// <summary>
    /// Gets the pointer to the top left pixel in the locked rectangle.
    /// </summary>
    /// <param name="bufferSize">The size of the buffer.</param>
    /// <returns>
    /// A pointer to the top left pixel in the locked rectangle.
    /// </returns>
    /// <remarks>
    /// The pointer provided by this method should not be used outside of the lifetime of the lock itself.
    /// GetDataPointer is not available in multi-threaded apartment applications.
    /// </remarks>
    IntPtr GetDataPointer([System::Runtime::InteropServices::Out] UInt32 % bufferSize);

    /// <summary>
    /// Retrieves a copy of the buffer data.
    /// </summary>
    /// <returns>
    /// A byte array containing the buffer data.
    /// </returns>
    array<unsigned char>^ CopyData();

    /// <summary>
    /// Retrieves the pixel width and height of the locked rectangle.
    /// </summary>
    property BitmapSize Size
    {
        BitmapSize get();
    }

    /// <summary>
    /// Gets the pixel format of for the locked area of pixels. This can be used to compute the number of bytes-per-pixel in the locked area.
    /// </summary>
    property Guid PixelFormat
    {
        Guid get();
    }

    /// <summary>
    /// Provides access to the stride value for the memory. 
    /// </summary>
    /// <remarks>
    /// Note the stride value is specific to the IWICBitmapLock, not the bitmap. 
    /// For example, two consecutive locks on the same rectangle of a bitmap may 
    /// return different pointers and stride values, depending on internal implementation. 
    /// </remarks>
    property UInt32 Stride
    {
        UInt32 get();
    }

internal:
    WICBitmapLock()
    { }  

    WICBitmapLock(IWICBitmapLock* _bitmapLock) : DirectUnknown(_bitmapLock)
    { }    
};

} } } }
