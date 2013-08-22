//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DirectUnknown.h"
#include "DWriteEnums.h"
#include "DWriteStructs.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DirectWrite {

    namespace DWrite = Microsoft::WindowsAPICodePack::DirectX::DirectWrite;


    /// <summary>
    /// Wraps an inline graphic.
    /// <para>(Also see DirectX SDK: IDWriteInlineObject)</para>
    /// </summary>
    public ref class InlineObject : public DirectUnknown
    {
    public: 

    internal:
        InlineObject() 
        { }
    
        InlineObject(IDWriteInlineObject* pNativeIDWriteInlineObject) : DirectUnknown(pNativeIDWriteInlineObject)
        { }

    };
} } } }
