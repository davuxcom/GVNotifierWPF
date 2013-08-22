//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

    /// <summary>
    /// An DXGIObject is the base for all DXGI classes. 
    /// <para>(Also see DirectX SDK: IDXGIObject)</para>
    /// </summary>
    public ref class DXGIObject :
        public DirectUnknown
    {
    public: 

        /// <summary>
        /// Gets the parent of this object.
        /// <para>(Also see DirectX SDK: IDXGIObject::GetParent)</para>
        /// </summary>
        /// <typeparam name="T">The type of the parent object requested. 
        /// This type has to be a DXGIObject or a subtype.</typeparam>
        /// <returns>The parent object. Or null if this object does not have a parent.</returns>
        generic <typename T> where T : DXGIObject
        T GetParent();

    internal:
        DXGIObject()
        { }

        DXGIObject(IDXGIObject* pNativeIDXGIObject) : DirectUnknown(pNativeIDXGIObject)
        { }

    };
} } } }
