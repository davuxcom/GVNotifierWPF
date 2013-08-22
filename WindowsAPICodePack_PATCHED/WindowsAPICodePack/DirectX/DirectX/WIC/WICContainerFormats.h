//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace WindowsImagingComponent {

using namespace System;

/// <summary>
/// Container formats supported by the Windows Imaging Component.
/// </summary>
public ref class ContainerFormats
{
public:

    /// <summary>
    /// The BMP container format GUID.
    /// </summary>
    static Guid Bmp =  Guid(0x0af1d87e, (short)0xfcfe, 0x4188, 0xbd, 0xeb, 0xa7, 0x90, 0x64, 0x71, 0xcb, 0xe3);

    /// <summary>
    /// The PNG container format GUID.
    /// </summary>
    static Guid Png =  Guid(0x1b7cfaf4, 0x713f, 0x473c, 0xbb, 0xcd, 0x61, 0x37, 0x42, 0x5f, 0xae, 0xaf);

    /// <summary>
    /// The ICO container format GUID.
    /// </summary>
    static Guid Ico =  Guid(0xa3a860c4, 0x338f, 0x4c17, 0x91, 0x9a, 0xfb, 0xa4, 0xb5, 0x62, 0x8f, 0x21);

    /// <summary>
    /// The JPEG container format GUID.
    /// </summary>
    static Guid Jpeg = Guid(0x19e4a5aa, 0x5662, 0x4fc5, 0xa0, 0xc0, 0x17, 0x58, 0x02, 0x8e, 0x10, 0x57);

    /// <summary>
    /// The TIFF container format GUID.
    /// </summary>
    static Guid Tiff = Guid(0x163bcc30, (short)(0xe2e9), 0x4f0b, 0x96, 0x1d, 0xa3, 0xe9, 0xfd, 0xb7, 0x88, 0xa3);

    /// <summary>
    /// The GIF container format GUID.
    /// </summary>
    static Guid Gif =  Guid(0x1f8a5601, 0x7d4d, 0x4cbd, 0x9c, 0x82, 0x1b, 0xc8, 0xd4, 0xee, 0xb9, 0xa5);

    /// <summary>
    /// The HD Photo container format GUID.
    /// </summary>
    static Guid Wmp =  Guid(0x57a37caa, 0x367a, 0x4540, 0x91, 0x6b, 0xf1, 0x83, 0xc5, 0x09, 0x3a, 0x4b);

};

} } } }