//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace WindowsImagingComponent {

using namespace System;

/// <summary>
/// Describes size of the bitmap.
/// </summary>
public value struct BitmapSize
{
public:
    /// <summary>
    /// The width of the bitmap in pixels.
    /// </summary>
    unsigned int Width;

    /// <summary>
    /// The height of the bitmap in pixels.
    /// </summary>
    unsigned int Height;

    /// <summary>
    /// Constructor
    /// </summary>
    BitmapSize( unsigned int width, unsigned int height ) :
        Width(width),
        Height(height)
    {
    }

};


/// <summary>
/// Describes dots per inch resolution of the bitmap.
/// </summary>
public value struct BitmapResolution
{
public:
    /// <summary>
    /// The horizontal resolution of the bitmap.
    /// </summary>
    double DpiX;

    /// <summary>
    /// The vertical resolution of the bitmap.
    /// </summary>
    double DpiY;

    /// <summary>
    /// Constructor
    /// </summary>
    BitmapResolution( double dpiX, double dpiY )
        : DpiX(dpiX), DpiY(dpiY)
    {
    }
    
};

/// <summary>
/// Describes a rectangle of bitmap data.
/// </summary>
public value struct BitmapRectangle
{
public:
    /// <summary>
    /// The horizontal component of the top left corner of the rectangle.
    /// </summary>
    int X;

    /// <summary>
    /// The vertical component of the top left corner of the rectangle.
    /// </summary>
    int Y;

    /// <summary>
    /// The width of the rectangle.
    /// </summary>
    int Width;

    /// <summary>
    /// The height of the rectangle.
    /// </summary>
    int Height;

    /// <summary>
    /// Constructor.
    /// </summary>
    BitmapRectangle( int x, int y, int width, int height ) :
        X(x),
        Y(y),
        Width(width),
        Height(height)

    {
    }
};

} } } }
