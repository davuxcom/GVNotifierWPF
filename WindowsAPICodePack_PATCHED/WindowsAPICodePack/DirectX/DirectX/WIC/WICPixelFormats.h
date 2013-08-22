//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace WindowsImagingComponent {

using namespace System;

/// <summary>
/// A listing of pixel formats supported by the Windows Imaging Component.
/// </summary>
public ref class PixelFormats
{
public:
    /* undefined pixel formats */

    /// <summary>
    /// A pixel format used when the actual pixelformat is unimportant to an image operation.
    /// </summary>
    static Guid DontCare = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x00);

    
    /* indexed pixel formats */

    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 1, Bits Per Pixel = 1, Storage Type = uint
    /// The value for each pixel is an index into a color palette.
    /// </summary>
    static Guid Pf1bppIndexed = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x01);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 2, Bits Per Pixel = 2, Storage Type = uint
    /// The value for each pixel is an index into a color palette.
    /// </summary>
    static Guid Pf2bppIndexed = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x02);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 4, Bits Per Pixel = 4, Storage Type = uint
    /// The value for each pixel is an index into a color palette.
    /// </summary>
    static Guid Pf4bppIndexed = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x03);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 8, Bits Per Pixel = 8, Storage Type = uint
    /// The value for each pixel is an index into a color palette.
    /// </summary>
    static Guid Pf8bppIndexed = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x04);

    
    /* Packed Bit Pixel Formats */ 

    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 5, Bits Per Pixel = 16, Storage Type = uint
    /// Color-channel data crosses byte boundaries.
    /// </summary>
    static Guid Pf16bppBGR555 = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x09);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel =     5(B)/6(G)/5(R), Bits Per Pixel = 16, Storage Type = uint
    /// Color-channel data crosses byte boundaries.
    /// </summary>
    static Guid Pf16bppBGR565 = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x0a);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 10, Bits Per Pixel = 32, Storage Type = uint
    /// Color-channel data crosses byte boundaries.
    /// </summary>
    static Guid Pf32bppBGR101010 = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x14);


    /* Grayscale Pixel Formats */

    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 1, Bits Per Pixel = 1, Storage Type = uint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid PfBlackWhite = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x05);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 2, Bits Per Pixel = 2, Storage Type = uint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf2bppGray = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x06);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 4, Bits Per Pixel = 4, Storage Type = uint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf4bppGray = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x07);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 8, Bits Per Pixel = 8, Storage Type = uint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf8bppGray = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x08);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 16, Bits Per Pixel = 16, Storage Type = uint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf16bppGray = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x0b);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 16, Bits Per Pixel = 16, Storage Type = FixedPoint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf16bppGrayFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x13);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 16, Bits Per Pixel = 16, Storage Type = float
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf16bppGrayHalf = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x3e);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 32, Bits Per Pixel = 32, Storage Type = float
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf32bppGrayFloat = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x11);
    /// <summary>
    /// Channel Count = 1, Bits Per Channel = 32, Bits Per Pixel = 32, Storage Type = FixedPoint
    /// Color data represents shades of gray.
    /// </summary>
    static Guid Pf32bppGrayFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x3f);

    
    /* RGB/BGR Pixel formats */

    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 8, Bits Per Pixel = 24, Storage Type = uint
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf24bppBGR = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x0c);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 8, Bits Per Pixel = 24, Storage Type = uint
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf24bppRGB = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x0d);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf32bppBGR = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x0e);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 16, Bits Per Pixel = 48, Storage Type = uint
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf48bppRGB = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x15);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 16, Bits Per Pixel = 48, Storage Type = Fixed
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf48bppRGBFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x12);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 16, Bits Per Pixel = 48, Storage Type = float
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf48bppRGBHalf = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x3b);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = Fixed
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf64bppRGBFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x40);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = float
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf64bppRGBHalf = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x42);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 32, Bits Per Pixel = 96, Storage Type = Fixed
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf96bppRGBFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x18);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 32, Bits Per Pixel = 128, Storage Type = float
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf128bppRGBFloat = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x1b);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 32, Bits Per Pixel = 128, Storage Type = Fixed
    /// Color data is separated into red(R), green(G), and blue(B) channels.
    /// </summary>
    static Guid Pf128bppRGBFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x41);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf32bppBGRA = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x0f);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf32bppRGBA = Guid(0xf5c7ad2d, 0x6a8d, 0x43dd, 0xa7, 0xa8, 0xa2, 0x99, 0x35, 0x26, 0x1a, 0xe9);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and exponent(E) channels.
    /// This format has an additional byte for shared exponent information. This provides 
    /// additional floating-point precision without the additional memory needed for a true 
    /// floating-point format.
    /// </summary>
    static Guid Pf32bppRGBE = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x3d);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf32bppPBGRA = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x10);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf32bppPRGBA = Guid(0x3cc4a650, 0xa527u, 0x4d37, 0xa9, 0x16, 0x31, 0x42, 0xc7, 0xeb, 0xed, 0xba);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf64bppRGBA = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x16);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = uint
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf64bppPRGBA = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x17);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = Fixed
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf64bppRGBAFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x1d);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = float
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf64bppRGBAHalf = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x3a);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 32, Bits Per Pixel = 128, Storage Type = float
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf128bppRGBAFloat = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x19);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 32, Bits Per Pixel = 128, Storage Type = float
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf128bppPRGBAFloat = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x1a);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 32, Bits Per Pixel = 128, Storage Type = Fixed
    /// Color data is separated into red(R), green(G), blue(B), and alpha(A) channels.
    /// </summary>
    static Guid Pf128bppRGBAFixedPoint = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x1e);


    /* CMYK Pixel Formats */

    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = Fixed
    /// Color data is separated into cyan(C), magenta(M), yellow(Y), and black(K) channels.
    /// </summary>
    static Guid Pf32bppCMYK = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x1c);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = Fixed
    /// Color data is separated into cyan(C), magenta(M), yellow(Y), and black(K) channels.
    /// </summary>
    static Guid Pf64bppCMYK = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x1f);
    /// <summary>
    /// Channel Count = 5, Bits Per Channel = 8, Bits Per Pixel = 40, Storage Type = Fixed
    /// Color data is separated into cyan(C), magenta(M), yellow(Y), black(K), and alpha channels.
    /// </summary>
    static Guid Pf40bppCMYKAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x2c);
    /// <summary>
    /// Channel Count = 5, Bits Per Channel = 16, Bits Per Pixel = 80, Storage Type = Fixed
    /// Color data is separated into cyan(C), magenta(M), yellow(Y), black(K), and alpha channels.
    /// </summary>
    static Guid Pf80bppCMYKAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x2d);


    /* n-channel Pixel Formats */

    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 8, Bits Per Pixel = 24, Storage Type = uint
    /// </summary>
    static Guid Pf24bpp3Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x20);
    /// <summary>
    /// Channel Count = 3, Bits Per Channel = 16, Bits Per Pixel = 48, Storage Type = uint
    /// </summary>
    static Guid Pf48bpp3Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x26);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// </summary>
    static Guid Pf32bpp3ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x2e);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = uint
    /// </summary>
    static Guid Pf64bpp3ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x34);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 8, Bits Per Pixel = 32, Storage Type = uint
    /// </summary>
    static Guid Pf32bpp4Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x21);
    /// <summary>
    /// Channel Count = 4, Bits Per Channel = 16, Bits Per Pixel = 64, Storage Type = uint
    /// </summary>
    static Guid Pf64bpp4Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x27);
    /// <summary>
    /// Channel Count = 5, Bits Per Channel = 8, Bits Per Pixel = 40, Storage Type = uint
    /// </summary>
    static Guid Pf40bpp4ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x2f);
    /// <summary>
    /// Channel Count = 5, Bits Per Channel = 16, Bits Per Pixel = 80, Storage Type = uint
    /// </summary>
    static Guid Pf80bpp4ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x35);
    /// <summary>
    /// Channel Count = 5, Bits Per Channel = 8, Bits Per Pixel = 40, Storage Type = uint
    /// </summary>
    static Guid Pf40bpp5Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x22);
    /// <summary>
    /// Channel Count = 5, Bits Per Channel = 16, Bits Per Pixel = 80, Storage Type = uint
    /// </summary>
    static Guid Pf80bpp5Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x28);
    /// <summary>
    /// Channel Count = 6, Bits Per Channel = 8, Bits Per Pixel = 48, Storage Type = uint
    /// </summary>
    static Guid Pf48bpp5ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x30);
    /// <summary>
    /// Channel Count = 6, Bits Per Channel = 16, Bits Per Pixel = 96, Storage Type = uint
    /// </summary>
    static Guid Pf96bpp5ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x36);
    /// <summary>
    /// Channel Count = 6, Bits Per Channel = 8, Bits Per Pixel = 48, Storage Type = uint
    /// </summary>
    static Guid Pf48bpp6Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x23);
    /// <summary>
    /// Channel Count = 6, Bits Per Channel = 16, Bits Per Pixel = 96, Storage Type = uint
    /// </summary>
    static Guid Pf96bpp6Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x29);
    /// <summary>
    /// Channel Count = 7, Bits Per Channel = 8, Bits Per Pixel = 56, Storage Type = uint
    /// </summary>
    static Guid Pf56bpp6ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x31);
    /// <summary>
    /// Channel Count = 7, Bits Per Channel = 16, Bits Per Pixel = 112, Storage Type = uint
    /// </summary>
    static Guid Pf112bpp6ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x37);
    /// <summary>
    /// Channel Count = 7, Bits Per Channel = 8, Bits Per Pixel = 56, Storage Type = uint
    /// </summary>
    static Guid Pf56bpp7Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x24);
    /// <summary>
    /// Channel Count = 7, Bits Per Channel = 16, Bits Per Pixel = 112, Storage Type = uint
    /// </summary>
    static Guid Pf112bpp7Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x2a);
    /// <summary>
    /// Channel Count = 8, Bits Per Channel = 8, Bits Per Pixel = 64, Storage Type = uint
    /// </summary>
    static Guid Pf64bpp7ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x32);
    /// <summary>
    /// Channel Count = 8, Bits Per Channel = 16, Bits Per Pixel = 128, Storage Type = uint
    /// </summary>
    static Guid Pf128bpp7ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x38);
    /// <summary>
    /// Channel Count = 8, Bits Per Channel = 8, Bits Per Pixel = 64, Storage Type = uint
    /// </summary>
    static Guid Pf64bpp8Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x25);
    /// <summary>
    /// Channel Count = 8, Bits Per Channel = 16, Bits Per Pixel = 128, Storage Type = uint
    /// </summary>
    static Guid Pf128bpp8Channels = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x2b);
    /// <summary>
    /// Channel Count = 9, Bits Per Channel = 8, Bits Per Pixel = 72, Storage Type = uint
    /// </summary>
    static Guid Pf72bpp8ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x33);
    /// <summary>
    /// Channel Count = 9, Bits Per Channel = 16, Bits Per Pixel = 144, Storage Type = uint
    /// </summary>
    static Guid Pf144bpp8ChannelsAlpha = Guid(0x6fddc324, 0x4e03, 0x4bfe, 0xb1, 0x85, 0x3d, 0x77, 0x76, 0x8d, 0xc9, 0x39);


};

} } } }