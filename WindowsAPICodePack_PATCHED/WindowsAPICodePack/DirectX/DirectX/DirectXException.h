// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX {

/// <summary>
/// Base class for all DirectX exceptions.
/// </summary>
public ref class DirectXException : public Exception
{
public:

    /// <summary>
    /// Default constructor
    /// </summary>
    DirectXException(void) : System::Exception() {}
    
    DirectXException(String^ message, int hr) : Exception(message) 
    {
        HResult = hr;
    }
        
    DirectXException(String^ message, Exception^ innerException, int hr) : 
        System::Exception(message, innerException)
    {
        HResult = hr;
    }

public:
    /// <summary>
    /// The error code returned by a DirectX API
    /// </summary>
    property int ErrorCode
    {
    public:
        int get()
        { 
            return Exception::HResult;
        }
    }
};

} } }
