// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include <vector>
#include <map>
#include <string>

using namespace std;
using namespace msclr::interop;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace System::Runtime::InteropServices;


namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX {
ref class DirectUnknown;
ref class DirectObject;

/// <summary>
/// Utility class for DirectX wrappers
/// </summary>
private ref class CommonUtils
{
private:
    static Dictionary<System::Type^, System::Guid>^ GuidsDictionary = nullptr;
    static void FillGuidsDictionary();
    static CommonUtils()
    {
        FillGuidsDictionary();
        
    }

internal:
    static int MaxNameSize = 1024;
    
    static System::Guid SystemGuidFromGUID(REFGUID guid );
    
    static GUID GUIDFromSystemGuid( System::Guid guid );

    static GUID GetGuid(System::Type^ type);

    generic <typename T> where T : DirectUnknown
    static T CreateIUnknownWrapper(IUnknown* ptr);

    template <class T, class S>
    static ReadOnlyCollection<T^>^ GetCollection(UINT numElements, vector<S*> & buffer)
    {
        List<T^>^ items = gcnew List<T^>();
        for (UINT i = 0; i < numElements; i++)
        {
            items->Add(buffer[i] == NULL ? nullptr : gcnew T(buffer[i]));
        }

        return gcnew ReadOnlyCollection<T^>(items);
    }
    template <class T, class S>
    static UINT FillIUnknownsVector(IEnumerable<T^>^ items, vector<S*> & buffer)
    {
        if (items != nullptr)
        {
            for each (T^ item in items)
            {
                buffer.push_back(item == nullptr ? NULL : item->GetInterface<S>());
            }
        }

        return static_cast<UINT>(buffer.size());
    }

    template <class T, class S>
    static UINT FillStructsVector(IEnumerable<T^>^ items, vector<S> & buffer)
    {
        if (items != nullptr)
        {
            for each (T^ item in items)
            {
                buffer.push_back(*(item->nativeObject.Get()));
            }
        }

        return static_cast<UINT>(buffer.size());
    }

    template <class T, class S>
    static UINT FillValStructsVector(IEnumerable<T>^ items, vector<S> & buffer)
    {
        if (items != nullptr)
        {
            for each (T item in items)
            {
                buffer.push_back(item);
            }
        }

        return static_cast<UINT>(buffer.size());
    }

    template <class T, class S>
    static UINT FillValStructsVector(IEnumerable<T>^ items, vector<S> & buffer, marshal_context^ ctx)
    {
        if (items != nullptr)
        {
            for each (T item in items)
            {
                S s = {0};
                item.CopyTo(&s, ctx);
                buffer.push_back(s);
            }
        }

        return static_cast<UINT>(buffer.size());
    }

    static array<unsigned char>^ ReadStream(Stream^ stream);

    static IDictionary<System::Globalization::CultureInfo^, System::String^>^
        GetCultureNameDictionary(IDWriteLocalizedStrings* names);

    static void CheckNull(Object^ o, String^ argName);

    static Exception^ GetExceptionForHR(HRESULT hr);
    
    static void VerifyResult(HRESULT hr);

    static HINSTANCE LoadDll(String^ libraryName);

};
} } }
