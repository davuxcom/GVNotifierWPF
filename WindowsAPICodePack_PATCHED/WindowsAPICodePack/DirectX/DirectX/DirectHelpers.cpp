//Copyright (c) Microsoft Corporation.  All rights reserved.

#include "StdAfx.h"
#include "DirectObject.h"
#include "DirectUnknown.h"
#include "DirectHelpers.h"
#include "CommonUtils.h"

using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct2D1;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;



generic <typename T> where T : DirectUnknown
T DirectHelpers::CreateIUnknown(System::IntPtr nativePointer)
{
    return safe_cast<T>(CommonUtils::CreateIUnknownWrapper<T>(static_cast<IUnknown*>(nativePointer.ToPointer())));
}

generic <typename T> where T : DirectObject
T DirectHelpers::CreateInterface(System::IntPtr nativePointer)
{
    T wrapper = safe_cast<T>( Activator::CreateInstance(T::typeid, true) );
    (safe_cast<DirectObject^>(wrapper))->Attach(nativePointer.ToPointer());
    return wrapper;
}

Exception^ DirectHelpers::GetExceptionForHResult(int hr)
{
    return CommonUtils::GetExceptionForHR(static_cast<HRESULT>(hr));
}

Exception^ DirectHelpers::GetExceptionForErrorCode(ErrorCode errorCode)
{
    return CommonUtils::GetExceptionForHR(static_cast<HRESULT>(errorCode));
}

void DirectHelpers::ThrowExceptionForHResult(int hr)
{
	int val = static_cast<HRESULT>(hr);
    
	if (SUCCEEDED(val))
        return;
    else
        throw CommonUtils::GetExceptionForHR(val);
}


void DirectHelpers::ThrowExceptionForErrorCode(ErrorCode errorCode)
{
	int val = static_cast<HRESULT>(errorCode);
    
	if (SUCCEEDED(val))
        return;
    else
        throw CommonUtils::GetExceptionForHR(val);
}
