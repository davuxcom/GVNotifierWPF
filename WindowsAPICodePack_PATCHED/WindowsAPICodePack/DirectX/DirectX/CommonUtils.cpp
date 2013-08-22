//Copyright (c) Microsoft Corporation.  All rights reserved.

#include "StdAfx.h"
#include "CommonUtils.h"
#include "AllTypes.h"

using namespace System::IO;

using namespace Microsoft::WindowsAPICodePack::DirectX;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct2D1;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D;

GUID CommonUtils::GetGuid(System::Type^ type)
{
    return GUIDFromSystemGuid(GuidsDictionary[type]);
}

generic <typename T> where T : DirectUnknown
T CommonUtils::CreateIUnknownWrapper(IUnknown* ptr)
{
#ifdef _DEBUG
    System::Diagnostics::Debug::Assert(ptr != NULL);
#endif

    T wrapper = safe_cast<T>( Activator::CreateInstance(T::typeid, true) );
    (safe_cast<DirectUnknown^>(wrapper))->Attach(ptr);
    return wrapper;
}

System::Guid CommonUtils::SystemGuidFromGUID(REFGUID guid ) 
{
   return Guid( 
       guid.Data1, guid.Data2, guid.Data3, 
       guid.Data4[ 0 ], guid.Data4[ 1 ], 
       guid.Data4[ 2 ], guid.Data4[ 3 ], 
       guid.Data4[ 4 ], guid.Data4[ 5 ], 
       guid.Data4[ 6 ], guid.Data4[ 7 ] );
}

GUID CommonUtils::GUIDFromSystemGuid( System::Guid guid ) 
{
   pin_ptr<Byte> data = &(guid.ToByteArray()[ 0 ]);
   return *(GUID *)data;
}

HINSTANCE CommonUtils::LoadDll(String^ libraryName)
{
    HINSTANCE softwareModule = NULL;

    String^ fullPath = Path::GetFullPath(libraryName);
    
    if (!File::Exists(fullPath) && !Path::IsPathRooted(libraryName))
    {
        fullPath = Path::Combine(System::Environment::GetFolderPath(
            Environment::SpecialFolder::System),
            libraryName);
    }

    if (!File::Exists(fullPath))
    {
        throw gcnew FileNotFoundException(String::Format("Unable to find library \"{0}\".", libraryName));
    }
    
    pin_ptr<const wchar_t> libName = PtrToStringChars(fullPath);
    softwareModule = LoadLibrary(libName);

    if (softwareModule == 0)
    {
        throw gcnew  System::ComponentModel::Win32Exception(Marshal::GetLastWin32Error()); 
    }
    
    return softwareModule;
}
void CommonUtils::VerifyResult(HRESULT hr)
{
    if (SUCCEEDED(hr))
        return;
    else
        throw GetExceptionForHR(hr);
}

Exception^ CommonUtils::GetExceptionForHR(HRESULT hr)
{
    switch (hr)
    {
    // General Errors
    case E_INVALIDARG: 
        return gcnew ArgumentException ("An invalid parameter was passed to the returning function.");

    case E_OUTOFMEMORY: 
        return gcnew OutOfMemoryException("Could not allocate sufficient memory to complete the call.");

    // D3D 10 Errors
    case D3D10_ERROR_FILE_NOT_FOUND: 
        return gcnew FileNotFoundException();

    case D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS: 
        return gcnew Direct3DException("Too many unique instances", hr);

    // D3D 11 Errors
    case D3D11_ERROR_FILE_NOT_FOUND:
        return gcnew FileNotFoundException();

    case D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS:
        return gcnew Direct3DException("Too many unique instances", hr);

    // DXGI Errors
    case DXGI_ERROR_DEVICE_HUNG: 
        return gcnew DXGIException("The application's device failed due to badly formed commands sent by the application. This is an design-time issue that should be investigated and fixed.", hr);

    case DXGI_ERROR_DEVICE_REMOVED: 
        return gcnew DXGIException("The video card has been physically removed from the system, or a driver upgrade for the video card has occurred. The application should destroy and recreate the device. For help debugging the problem, call Device.GetDeviceRemovedReason().", hr);

    case DXGI_ERROR_DEVICE_RESET: 
        return gcnew DXGIException("The device failed due to a badly formed command. This is a run-time issue; The application should destroy and recreate the device. ", hr);

    case DXGI_ERROR_DRIVER_INTERNAL_ERROR: 
        return gcnew DXGIException("The driver encountered a problem and was put into the device removed state. ", hr);

    case DXGI_ERROR_FRAME_STATISTICS_DISJOINT: 
        return gcnew NotSupportedException("The requested functionality is not supported by the device or the driver. ", gcnew DXGIException(hr));

    case DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE: 
        return gcnew DXGIException("The requested functionality is not supported by the device or the driver. ", hr);

    case DXGI_ERROR_INVALID_CALL: 
        return gcnew ArgumentOutOfRangeException("The application provided invalid parameter data; this must be debugged and fixed before the application is released. ", gcnew DXGIException(hr));

    case DXGI_ERROR_MORE_DATA: 
        return gcnew DXGIException("The buffer supplied by the application is not big enough to hold the requested data. ", hr);

    case DXGI_ERROR_NONEXCLUSIVE: 
        return gcnew DXGIException("The application attempted to acquire exclusive ownership of an output, but failed because some other application (or device within the application) has already acquired ownership. ", hr);

    case DXGI_ERROR_NOT_CURRENTLY_AVAILABLE: 
        return gcnew DXGIException("The requested functionality is not supported by the device or the driver. ", hr);

    case DXGI_ERROR_NOT_FOUND: 
        return gcnew DXGIException("When calling DXGIObject.GetPrivateData(), the GUID passed in is not recognized as one previously passed to DXGIObject.SetPrivateData() or DXGIObject.SetPrivateDataInterface(). ", hr);

    case DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED: 
        return gcnew DXGIException("The application's remote device has been removed due to session disconnect or network disconnect. The application should call DXGI.DXGIFactory1.IsCurrent() to find out when the remote device becomes available again. ", hr);
    
    case DXGI_ERROR_REMOTE_OUTOFMEMORY: 
        return gcnew OutOfMemoryException("The application's remote device has failed due to lack of memory or machine error. The application should destroy and recreate resources using less memory. ", gcnew DXGIException(hr));
    
    case DXGI_ERROR_WAS_STILL_DRAWING: 
        return gcnew DXGIException("The device was busy, and did not schedule the requested task. This error only applies to Asynchronous queries in Direct3D 10.", hr); 
    
    case DXGI_ERROR_UNSUPPORTED: 
        return gcnew NotSupportedException("The requested functionality is not supported by the device or the driver. ", gcnew DXGIException(hr));

    // D2D Errors
    case D2DERR_BAD_NUMBER: 
        return gcnew Direct2DException("The number is invalid.", hr);

    case D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED: 
        return gcnew Direct2DException("The display format to render is not supported by the hardware device.", hr);

    case D2DERR_DISPLAY_STATE_INVALID: 
        return gcnew Direct2DException("A valid display state could not be determined.", hr);

    case D2DERR_EXCEEDS_MAX_BITMAP_SIZE: 
        return gcnew Direct2DException("The requested size is larger than the guaranteed supported texture size.", hr);

    case D2DERR_INCOMPATIBLE_BRUSH_TYPES: 
        return gcnew Direct2DException("The brush types are incompatible for the call.", hr);

    case ERROR_INSUFFICIENT_BUFFER: 
        return gcnew Direct2DException("The supplied buffer is too small to accommodate the data.", hr);

    case D2DERR_INTERNAL_ERROR: 
        return gcnew Direct2DException("The application should close this instance of Direct2D and restart it as a new process.", hr);

    case D2DERR_INVALID_CALL: 
        return gcnew Direct2DException("A call to this method is invalid.", hr);

    case D2DERR_LAYER_ALREADY_IN_USE: 
        return gcnew Direct2DException("The application attempted to reuse a layer resource that has not yet been popped off the stack.", hr);

    case D2DERR_MAX_TEXTURE_SIZE_EXCEEDED: 
        return gcnew Direct2DException("The requested DX surface size exceeds the maximum texture size.", hr);

    case D2DERR_NO_HARDWARE_DEVICE: 
        return gcnew Direct2DException("There is no hardware rendering device available for this operation.", hr);
    
    case D2DERR_NOT_INITIALIZED: 
        return gcnew Direct2DException("The object has not yet been initialized.", hr);
    
    case D2DERR_POP_CALL_DID_NOT_MATCH_PUSH: 
        return gcnew Direct2DException("The application attempted to pop a layer off the stack when a clip was at the top, or pop a clip off the stack when a layer was at the top.", hr);
    
    case D2DERR_PUSH_POP_UNBALANCED: 
        return gcnew Direct2DException("The application did not pop all clips and layers off the stack, or it attempted to pop too many clips or layers off the stack.", hr);
    
    case D2DERR_RECREATE_TARGET: 
        return gcnew Direct2DException("A presentation error has occurred that may be recoverable. The caller needs to re-create the render target, render the entire frame again, and reattempt presentation.", hr);
    
    case D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT: 
        return gcnew Direct2DException("The application attempted to copy the contents of a render target before popping all layers and clips off the stack.", hr);
    
    case D2DERR_SCANNER_FAILED: 
        return gcnew Direct2DException("The geomery scanner failed to process the data.", hr);
    
    case D2DERR_SCREEN_ACCESS_DENIED: 
        return gcnew Direct2DException("Direct2D could not access the screen.", hr);
    
    case D2DERR_SHADER_COMPILE_FAILED: 
        return gcnew Direct2DException("Shader compilation failed.", hr);
    
    case D2DERR_TARGET_NOT_GDI_COMPATIBLE: 
        return gcnew Direct2DException("The render target is not compatible with GDI.", hr);
    
    case D2DERR_TEXT_EFFECT_IS_WRONG_TYPE: 
        return gcnew Direct2DException("A text client drawing effect object is of the wrong type.", hr);
    
    case D2DERR_TEXT_RENDERER_NOT_RELEASED: 
        return gcnew Direct2DException("An application is holding a reference to the IDWriteTextRenderer interface after the corresponding DrawText or DrawTextLayout call has: returned.", hr);
    
    case D2DERR_TOO_MANY_SHADER_ELEMENTS: 
        return gcnew Direct2DException("Shader construction failed because it was too complex.", hr);
    
    case D2DERR_UNSUPPORTED_OPERATION: 
        return gcnew Direct2DException("The requested operation is not supported.", hr);
    
    case D2DERR_UNSUPPORTED_VERSION: 
        return gcnew Direct2DException("The requested Direct2D version is not supported.", hr);
    
    case D2DERR_WIN32_ERROR: 
        return gcnew Direct2DException("An unknown Win32 failure occurred.", hr);
    
    case D2DERR_WRONG_FACTORY: 
        return gcnew Direct2DException("Objects used together were not all created from the same factory instance.", hr);
    
    case D2DERR_WRONG_RESOURCE_DOMAIN: 
        return gcnew Direct2DException("The resource used was created by a render target in a different resource domain.", hr);
    
    case D2DERR_WRONG_STATE: 
        return gcnew Direct2DException("The object was not in the correct state to process the method.", hr);
    
    case D2DERR_ZERO_VECTOR: 
        return gcnew Direct2DException("The supplied vector is zero.", hr);

    // WIC Errors
    case WINCODEC_ERR_ALREADYLOCKED :   
        return gcnew WICException("WIC Error was returned: Already locked .", hr);
    
    case WINCODEC_ERR_BADHEADER :   
        return gcnew WICException("WIC Error was returned: Bad header.", hr);
    
    case WINCODEC_ERR_BADIMAGE :   
        return gcnew WICException("WIC Error was returned: Bad image.", hr);
    
    case WINCODEC_ERR_BADMETADATAHEADER :   
        return gcnew WICException("WIC Error was returned: Bad meta data header.", hr);
    
    case WINCODEC_ERR_BADSTREAMDATA :   
        return gcnew WICException("WIC Error was returned: Bad stream data.", hr);
    
    case WINCODEC_ERR_CODECNOTHUMBNAIL :   
        return gcnew WICException("WIC Error was returned: Codec no thumbnail.", hr);
    
    case WINCODEC_ERR_CODECPRESENT :   
        return gcnew WICException("WIC Error was returned: Codec present.", hr);
    
    case WINCODEC_ERR_CODECTOOMANYSCANLINES :   
        return gcnew WICException("WIC Error was returned: Codec too many scan lines.", hr);
    
    case WINCODEC_ERR_COMPONENTINITIALIZEFAILURE :   
        return gcnew WICException("WIC Error was returned: Component initialize failure.", hr);
    
    case WINCODEC_ERR_COMPONENTNOTFOUND :   
        return gcnew WICException("WIC Error was returned: Component not found.", hr);
    
    case WINCODEC_ERR_DUPLICATEMETADATAPRESENT :   
        return gcnew WICException("WIC Error was returned: Duplicate meta data present.", hr);
    
    case WINCODEC_ERR_FRAMEMISSING :   
        return gcnew WICException("WIC Error was returned: Frame missing.", hr);
    
    case WINCODEC_ERR_IMAGESIZEOUTOFRANGE :   
        return gcnew WICException("WIC Error was returned: Image size out of range.", hr);
    
    case WINCODEC_ERR_INSUFFICIENTBUFFER :   
        return gcnew WICException("WIC Error was returned: Insufficient buffer.", hr);
    
    case WINCODEC_ERR_INTERNALERROR :   
        return gcnew WICException("WIC Error was returned: Internal error.", hr);
    
    case WINCODEC_ERR_INVALIDQUERYCHARACTER :   
        return gcnew WICException("WIC Error was returned: Invalid query character.", hr);
    
    case WINCODEC_ERR_INVALIDQUERYREQUEST :   
        return gcnew WICException("WIC Error was returned: Invalid query request.", hr);
    
    case WINCODEC_ERR_INVALIDREGISTRATION :   
        return gcnew WICException("WIC Error was returned: Invalid registration.", hr);
    
    case WINCODEC_ERR_NOTINITIALIZED :   
        return gcnew WICException("WIC Error was returned: Not initialized.", hr);
    
    case WINCODEC_ERR_PALETTEUNAVAILABLE :   
        return gcnew WICException("WIC Error was returned: Palette unavailable.", hr);
    
    case WINCODEC_ERR_PROPERTYNOTFOUND :   
        return gcnew WICException("WIC Error was returned: Property not found.", hr);
    
    case WINCODEC_ERR_PROPERTYNOTSUPPORTED :   
        return gcnew WICException("WIC Error was returned: Property not supported.", hr);
    
    case WINCODEC_ERR_PROPERTYSIZE :   
        return gcnew WICException("WIC Error was returned: Property size.", hr);
    
    case WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE :   
        return gcnew WICException("WIC Error was returned: Property unexpected type.", hr);
    
    case WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT :   
        return gcnew WICException("WIC Error was returned: Request only valid at meta data root.", hr);
    
    case WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS :   
        return gcnew WICException("WIC Error was returned: Source rectangle does not match dimensions.", hr);
    
    case WINCODEC_ERR_STREAMWRITE :   
        return gcnew WICException("WIC Error was returned: Stream write.", hr);
    
    case WINCODEC_ERR_STREAMREAD :   
        return gcnew WICException("WIC Error was returned: Stream read.", hr);
    
    case WINCODEC_ERR_STREAMNOTAVAILABLE :   
        return gcnew WICException("WIC Error was returned: Stream not available.", hr);
    
    case WINCODEC_ERR_TOOMUCHMETADATA :   
        return gcnew WICException("WIC Error was returned: Too much meta data.", hr);
    
    case WINCODEC_ERR_UNKNOWNIMAGEFORMAT :   
        return gcnew WICException("WIC Error was returned: Unknown image format.", hr);
    
    case WINCODEC_ERR_UNEXPECTEDMETADATATYPE :   
        return gcnew WICException("WIC Error was returned: Unexpected meta data type.", hr);
    
    case WINCODEC_ERR_UNEXPECTEDSIZE :   
        return gcnew WICException("WIC Error was returned: Unexpected size.", hr);
    
    case WINCODEC_ERR_UNSUPPORTEDOPERATION :   
        return gcnew WICException("WIC Error was returned: Unsupported operation.", hr);
    
    case WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT :   
        return gcnew WICException("WIC Error was returned: Unsupported pixel format.", hr);
    
    case WINCODEC_ERR_UNSUPPORTEDVERSION :   
        return gcnew WICException("WIC Error was returned: Unsupported version.", hr);
    
    case WINCODEC_ERR_VALUEOUTOFRANGE :   
        return gcnew WICException("WIC Error was returned: Value out of range.", hr);
    
    case WINCODEC_ERR_VALUEOVERFLOW :   
        return gcnew WICException("WIC Error was returned: Value overflow.", hr);
    
    case WINCODEC_ERR_WRONGSTATE :   
        return gcnew WICException("WIC Error was returned: Wrong state.", hr);

    default:
        return Marshal::GetExceptionForHR(hr);
    }    
}
void CommonUtils::CheckNull(Object^ obj, String^ argName)
{
    if (obj == nullptr)
    {
        throw gcnew ArgumentNullException(argName);
    }
}


array<unsigned char>^ CommonUtils::ReadStream(Stream^ stream)
{
    BinaryReader^ reader = gcnew BinaryReader(stream);
    array<unsigned char>^ data = reader->ReadBytes( (int)stream->Length);

    return data;
}


IDictionary<System::Globalization::CultureInfo^, System::String^>^ CommonUtils::GetCultureNameDictionary(IDWriteLocalizedStrings* names)
{
    Dictionary<System::Globalization::CultureInfo^, System::String^>^ namesDictionary =
        gcnew Dictionary<System::Globalization::CultureInfo^, System::String^>();

    UINT count = names->GetCount();
    for (UINT i = 0 ; i < count ; i++)
    {
        UINT localeLength;
        CommonUtils::VerifyResult(names->GetLocaleNameLength(i, &localeLength));

        UINT nameLength;
        CommonUtils::VerifyResult(names->GetStringLength(i, &nameLength));

        WCHAR* locale = new WCHAR[localeLength + 1];
        WCHAR* name = new WCHAR[nameLength + 1];

        try
        {
            CommonUtils::VerifyResult(names->GetLocaleName(i, locale, localeLength + 1));
            CommonUtils::VerifyResult(names->GetString(i, name, nameLength + 1));

            namesDictionary->Add(gcnew System::Globalization::CultureInfo(gcnew String(locale)), gcnew String(name));
        }
        finally
        {
            delete [] locale;
            delete [] name;
        }
    }

    return namesDictionary;
}

// TODO: Replace with reflected properties
void CommonUtils::FillGuidsDictionary()
{
    GuidsDictionary = gcnew Dictionary<System::Type^, System::Guid>();

    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::BlendState::typeid, SystemGuidFromGUID(__uuidof(ID3D11BlendState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DBuffer::typeid, SystemGuidFromGUID(__uuidof(ID3D11Buffer)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassInstance::typeid, SystemGuidFromGUID(__uuidof(ID3D11ClassInstance)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassLinkage::typeid, SystemGuidFromGUID(__uuidof(ID3D11ClassLinkage)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::CommandList::typeid, SystemGuidFromGUID(__uuidof(ID3D11CommandList)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ComputeShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11ComputeShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDebug::typeid, SystemGuidFromGUID(__uuidof(ID3D11Debug)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilState::typeid, SystemGuidFromGUID(__uuidof(ID3D11DepthStencilState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilView::typeid, SystemGuidFromGUID(__uuidof(ID3D11DepthStencilView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice::typeid, SystemGuidFromGUID(__uuidof(ID3D11Device)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild::typeid, SystemGuidFromGUID(__uuidof(ID3D11DeviceChild)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceContext::typeid, SystemGuidFromGUID(__uuidof(ID3D11DeviceContext)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DomainShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11DomainShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::GeometryShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11GeometryShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::HullShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11HullShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InputLayout::typeid, SystemGuidFromGUID(__uuidof(ID3D11InputLayout)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::PixelShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11PixelShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RasterizerState::typeid, SystemGuidFromGUID(__uuidof(ID3D11RasterizerState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RenderTargetView::typeid, SystemGuidFromGUID(__uuidof(ID3D11RenderTargetView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource::typeid, SystemGuidFromGUID(__uuidof(ID3D11Resource)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SamplerState::typeid, SystemGuidFromGUID(__uuidof(ID3D11SamplerState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ShaderResourceView::typeid, SystemGuidFromGUID(__uuidof(ID3D11ShaderResourceView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SwitchToRef::typeid, SystemGuidFromGUID(__uuidof(ID3D11SwitchToRef)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture1D::typeid, SystemGuidFromGUID(__uuidof(ID3D11Texture1D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture2D::typeid, SystemGuidFromGUID(__uuidof(ID3D11Texture2D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture3D::typeid, SystemGuidFromGUID(__uuidof(ID3D11Texture3D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::UnorderedAccessView::typeid, SystemGuidFromGUID(__uuidof(ID3D11UnorderedAccessView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::VertexShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11VertexShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View::typeid, SystemGuidFromGUID(__uuidof(ID3D11View)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory::typeid, SystemGuidFromGUID(__uuidof(IDXGIFactory)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory1::typeid, SystemGuidFromGUID(__uuidof(IDXGIFactory1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter::typeid, SystemGuidFromGUID(__uuidof(IDXGIAdapter)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter1::typeid, SystemGuidFromGUID(__uuidof(IDXGIAdapter1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice::typeid, SystemGuidFromGUID(__uuidof(IDXGIDevice)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice1::typeid, SystemGuidFromGUID(__uuidof(IDXGIDevice1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DeviceSubObject::typeid, SystemGuidFromGUID(__uuidof(IDXGIDeviceSubObject)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::KeyedMutex::typeid, SystemGuidFromGUID(__uuidof(IDXGIKeyedMutex)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIObject::typeid, SystemGuidFromGUID(__uuidof(IDXGIObject)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Output::typeid, SystemGuidFromGUID(__uuidof(IDXGIOutput)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIResource::typeid, SystemGuidFromGUID(__uuidof(IDXGIResource)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface::typeid, SystemGuidFromGUID(__uuidof(IDXGISurface)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface1::typeid, SystemGuidFromGUID(__uuidof(IDXGISurface1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::SwapChain::typeid, SystemGuidFromGUID(__uuidof(IDXGISwapChain)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::BlendState::typeid, SystemGuidFromGUID(__uuidof(ID3D10BlendState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::BlendState1::typeid, SystemGuidFromGUID(__uuidof(ID3D10BlendState1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DBuffer::typeid, SystemGuidFromGUID(__uuidof(ID3D10Buffer)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDebug::typeid, SystemGuidFromGUID(__uuidof(ID3D10Debug)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DepthStencilState::typeid, SystemGuidFromGUID(__uuidof(ID3D10DepthStencilState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DepthStencilView::typeid, SystemGuidFromGUID(__uuidof(ID3D10DepthStencilView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice::typeid, SystemGuidFromGUID(__uuidof(ID3D10Device)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DDevice1::typeid, SystemGuidFromGUID(__uuidof(ID3D10Device1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::DeviceChild::typeid, SystemGuidFromGUID(__uuidof(ID3D10DeviceChild)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::GeometryShader::typeid, SystemGuidFromGUID(__uuidof(ID3D10GeometryShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::InputLayout::typeid, SystemGuidFromGUID(__uuidof(ID3D10InputLayout)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::Multithread::typeid, SystemGuidFromGUID(__uuidof(ID3D10Multithread)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::PixelShader::typeid, SystemGuidFromGUID(__uuidof(ID3D10PixelShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::RasterizerState::typeid, SystemGuidFromGUID(__uuidof(ID3D10RasterizerState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::RenderTargetView::typeid, SystemGuidFromGUID(__uuidof(ID3D10RenderTargetView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::D3DResource::typeid, SystemGuidFromGUID(__uuidof(ID3D10Resource)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::SamplerState::typeid, SystemGuidFromGUID(__uuidof(ID3D10SamplerState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::ShaderResourceView::typeid, SystemGuidFromGUID(__uuidof(ID3D10ShaderResourceView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::ShaderResourceView1::typeid, SystemGuidFromGUID(__uuidof(ID3D10ShaderResourceView1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::SwitchToRef::typeid, SystemGuidFromGUID(__uuidof(ID3D10SwitchToRef)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::Texture1D::typeid, SystemGuidFromGUID(__uuidof(ID3D10Texture1D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::Texture2D::typeid, SystemGuidFromGUID(__uuidof(ID3D10Texture2D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::Texture3D::typeid, SystemGuidFromGUID(__uuidof(ID3D10Texture3D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::VertexShader::typeid, SystemGuidFromGUID(__uuidof(ID3D10VertexShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D10::View::typeid, SystemGuidFromGUID(__uuidof(ID3D10View)));
}

