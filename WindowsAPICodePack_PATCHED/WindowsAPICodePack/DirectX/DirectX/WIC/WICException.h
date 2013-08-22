// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectXException.h"

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace WindowsImagingComponent { 

/// <summary>
/// An exception thrown by a WIC (Windows Imaging Component) method.
/// </summary>
public ref class WICException : public DirectXException
{
public:
    WICException(void) : DirectXException() {}
    
    WICException(int hr) : DirectXException("WIC Error was returned. Check ErrorCode.", hr)
    { }

    WICException(String^ message, int hr) : DirectXException(message, hr)
    { }

    WICException(String^ message, Exception^ innerException, int hr) : 
        DirectXException(message, innerException, hr) 
    { }
};
} } } }
