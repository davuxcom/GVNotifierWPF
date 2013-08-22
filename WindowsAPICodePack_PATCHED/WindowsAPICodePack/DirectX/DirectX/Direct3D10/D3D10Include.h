//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

    /// <summary>
    /// An include interface allows an application to create user-overridable methods for opening and closing files when loading an effect from memory. This class does not inherit from anything, but does declare the following methods:
    /// <para>(Also see DirectX SDK: ID3D10Include)</para>
    /// </summary>
    public ref class Include :
        public DirectObject
    {
    public: 
        /// <summary>
        /// A user-implemented method for closing a shader #include file.
        /// <para>(Also see DirectX SDK: ID3D10Include::Close)</para>
        /// </summary>
        /// <param name="data">Pointer to the returned buffer that contains the include directives. This is the pointer that was returned by the corresponding Include.Open call.</param>
        void Close(IntPtr data);

        /// <summary>
        /// A user-implemented method for opening and reading the contents of a shader #include file.
        /// <para>(Also see DirectX SDK: ID3D10Include::Open)</para>
        /// </summary>
        /// <param name="includeType">The location of the #include file. See IncludeType.</param>
        /// <param name="fileName">Name of the #include file.</param>
        /// <param name="parentData">Pointer to the container that includes the #include file.</param>
        /// <param name="bytes">Number of bytes returned.</param>
        /// <returns>Pointer to the returned buffer that contains the include directives. This pointer remains valid until Include.Close() is called.</returns>
        IntPtr Open(IncludeType includeType, String^ fileName, IntPtr parentData, [System::Runtime::InteropServices::Out] UInt32 % bytes);
  
    internal:
        Include()
        {
        }

        Include(ID3D10Include* pNativeID3D10Include) : 
            DirectObject(pNativeID3D10Include)
        {
        }

    };
} } } }
