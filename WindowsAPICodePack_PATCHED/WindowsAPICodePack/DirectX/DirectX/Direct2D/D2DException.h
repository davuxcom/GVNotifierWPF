// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectXException.h"

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct2D1 {

/// <summary>
/// Base class for all Direct2D exceptions
/// </summary>
public ref class Direct2DException : public DirectXException
{

public:
    Direct2DException(void) : DirectXException() {}
    
    Direct2DException(String^ message, int hr) : DirectXException(message, hr) 
    {
    }
    
    Direct2DException(int hr) : DirectXException("Direct2D Error was returned. Check ErrorCode.", hr) 
    {
        HResult = hr;
        
    }
    
    Direct2DException(String^ message, Exception^ innerException, int hr) : 
        DirectXException(message, innerException, hr) 
    {
    }

    Direct2DException(String^ message, Exception^ innerException) : 
        DirectXException(message, innerException, 0) 
    {        
    }

};
} } } }
