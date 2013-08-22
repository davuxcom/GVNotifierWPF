// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX {

/// <summary>
/// Base for classes supporting an internal interface that is not an IUnknown
/// </summary>
public ref class DirectObject abstract
{
internal:

    template <typename T>
    T* GetInterface()
    {
        return static_cast<T*>(nativeObject.Get());
    }

    void Attach(void* _right);

    void Attach(void* _right, bool _deletable);

    DirectObject();
    
    DirectObject(void* _ptr);

    DirectObject(void* _ptr, bool _deletable);

public:
    /// <summary>
    /// Get the internal native pointer for the wrapped native object
    /// </summary>
    /// <returns>
    /// A pointer to the wrapped native interfac.
    /// </returns>
    property IntPtr NativeObject
    {
        IntPtr get()
        {
            return IntPtr(nativeObject.Get());
        }
    }

private:
    AutoPointer<void> nativeObject;

};
} } }
