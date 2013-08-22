// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIFactory1.h"
#include "DXGIAdapter1.h"
#include "LibraryLoader.h"

using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;

typedef HRESULT (*CreateDXGIFactory1FuncPtr)(REFIID riid, void **ppFactory);

DXGIFactory1^ DXGIFactory1::CreateFactory1()
{
    CreateDXGIFactory1FuncPtr createFuncPtr = 
        (CreateDXGIFactory1FuncPtr) LibraryLoader::Instance()->GetFunctionfromDll(
            DXGILibrary, "CreateDXGIFactory1");

    IDXGIFactory1 * factory = NULL;

    CommonUtils::VerifyResult(
        (*createFuncPtr)(__uuidof(IDXGIFactory1), (void**)(&factory)));

    return gcnew DXGIFactory1(factory);
}

ReadOnlyCollection<Adapter1^>^ DXGIFactory1::GetAdapters1()
{
    IList<Adapter1^>^ adapters1Cache = gcnew List<Adapter1^>();

    int i = 0;
    while (true)
    {
        IDXGIAdapter1* tempAdapter;

        if (DXGI_ERROR_NOT_FOUND != GetInterface<IDXGIFactory1>()->EnumAdapters1(i++, &tempAdapter))
            adapters1Cache->Add(gcnew Adapter1(tempAdapter));
        else
            break;
    }

    return gcnew ReadOnlyCollection<Adapter1^>(adapters1Cache);
}

Adapter1^ DXGIFactory1::GetAdapter1(UInt32 index)
{    
    IDXGIAdapter1* tempAdapter = NULL;

    CommonUtils::VerifyResult(GetInterface<IDXGIFactory1>()->EnumAdapters1(index, &tempAdapter));
    return tempAdapter == NULL ? nullptr : gcnew Adapter1(tempAdapter);
}

Boolean DXGIFactory1::IsCurrent::get()
{
    return GetInterface<IDXGIFactory1>()->IsCurrent() != 0;
}

