// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectXException.h"

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI { 

/// <summary>
/// An exception thrown by DXGI.
/// </summary>
public ref class DXGIException : public DirectXException
{
public:
    DXGIException(void) : DirectXException() {}
    
    DXGIException(int hr) : DirectXException("DXGI Error was returned. Check ErrorCode.", hr)
    { }

    DXGIException(String^ message, int hr) : DirectXException(message, hr)
    { }

    DXGIException(String^ message, Exception^ innerException, int hr) : 
        DirectXException(message, innerException, hr) 
    { }
};
} } } }
