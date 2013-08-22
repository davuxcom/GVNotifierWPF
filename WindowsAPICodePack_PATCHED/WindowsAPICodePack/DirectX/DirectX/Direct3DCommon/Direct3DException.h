// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectXException.h"

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D {


/// <summary>
/// An exception thrown by Direct3D.
/// </summary>
public ref class Direct3DException : public DirectXException
{
public:
    Direct3DException(void) : DirectXException() {}
    
    Direct3DException(String^ message, int hr) : DirectXException(message, hr) 
    {
    }
    
    Direct3DException(int hr) : DirectXException("Direct3D Error was returned. Check ErrorCode.", hr) 
    {
        HResult = hr;
        
    }
    
    Direct3DException(String^ message, Exception^ innerException, int hr) : 
        DirectXException(message, innerException, hr) 
    {
    }
};
} } } }
