// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX {

/// <summary>
/// Base class for all classes supporting internal IUnknown interfaces
/// </summary>
public ref class DirectUnknown abstract
{
internal:
    template <typename T>
    T* GetInterface()
    {
        return static_cast<T*>(nativeUnknown.Get());
    }

    void Attach(IUnknown* _right);

    void Attach(IUnknown* _right, bool _deletable);

    DirectUnknown(IUnknown* _iUnknown);
    
    DirectUnknown(IUnknown* _iUnknown, bool _deletable);

    DirectUnknown() ;

public:
    /// <summary>
    /// Get the internal native pointer for the wrapped IUnknown Interface
    /// </summary>
    /// <returns>
    /// A pointer to the wrapped native IUnknown.
    /// </returns>
    property IntPtr NativeInterface
    {
        IntPtr get()
        {
            return IntPtr(nativeUnknown.Get());
        }
    }

private:
    AutoIUnknown<IUnknown> nativeUnknown;
};
} } }
