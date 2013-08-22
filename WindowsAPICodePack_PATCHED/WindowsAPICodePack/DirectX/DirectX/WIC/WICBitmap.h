//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "WICBitmapSource.h"
#include "WICContainerFormats.h"

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace WindowsImagingComponent {

    ref class WICBitmapLock;
    ref class ImagingFactory;

/// <summary>
/// Defines methods that add the concept of writeability and static in-memory representations 
/// of bitmaps to WICBitmapSource. 
/// <para>(Also see IWICBitmap interface)</para>
/// </summary>
public ref class WICBitmap :  public BitmapSource
{
public:
    /// <summary>
    /// Changes the physical resolution of the image.
    /// </summary>
    /// <param name="resolution">The new bitmap resolution.</param>
    void SetResolution(BitmapResolution resolution);

    /// <summary>
    /// Provides locked access to a rectangular area of the bitmap.
    /// </summary>
    /// <param name="lockRectangle">The rectangle to be accessed.</param>
    /// <param name="flags">The access mode you wish to obtain for the lock. 
    /// This is a bitwise combination of BitmapLockFlags for read, write, or read and write access.</param>
    /// <returns>A WICBitmapLock object that represents locked memory location.</returns>
    /// <remarks>
    /// Locks are exclusive for writing but can be shared for reading. 
    /// You cannot call BitmapSource.CopyPixels() while the WICBitmap is locked for writing. 
    /// Doing so will return an error, since locks are exclusive.
    /// </remarks>
    WICBitmapLock^ Lock(BitmapRectangle lockRectangle, BitmapLockFlags flags);

    /// <summary>
    /// Save the bitmap to a file given a container format.
    /// </summary>
    /// <param name="imagingFactory">The imaging factory that created this bitmap.</param>
    /// <param name="containerFormat">One of the predefined container formats in <see cref="ContainerFormats"/> to use when creating the bitmap.</param>
    /// <param name="fileName">The file path to save to.<B>If the file already exists, it will be overwritten</B></param>
    void SaveToFile(ImagingFactory^ imagingFactory, System::Guid containerFormat, System::String^ fileName);

internal:
    WICBitmap()
    { }  

    WICBitmap(IWICBitmap* _bitmap) : BitmapSource(_bitmap)
    { }    
};

} } } }
