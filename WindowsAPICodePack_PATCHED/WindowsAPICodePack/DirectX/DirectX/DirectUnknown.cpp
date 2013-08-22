//Copyright (c) Microsoft Corporation.  All rights reserved.

#include "StdAfx.h"
#include "DirectUnknown.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;

DirectUnknown::DirectUnknown() { }

void DirectUnknown::Attach(IUnknown* _right)
{
    nativeUnknown.Set(_right);
}

void DirectUnknown::Attach(IUnknown* _right, bool _deletable)
{
    nativeUnknown.Set(_right, _deletable);
}


DirectUnknown::DirectUnknown(IUnknown* _iUnknown) 
{
    nativeUnknown.Set(_iUnknown);
}

DirectUnknown::DirectUnknown(IUnknown* _iUnknown, bool _deletable) 
{
    nativeUnknown.Set(_iUnknown, _deletable);
}
