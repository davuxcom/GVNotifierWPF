// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11InfoQueue.h"

using namespace msclr::interop;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

void InfoQueue::AddApplicationMessage(MessageSeverity severity, String^ description)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(description);

    try
    {
        CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->AddApplicationMessage(
            static_cast<D3D11_MESSAGE_SEVERITY>(severity), 
            static_cast<char*>(ptr.ToPointer())));
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

void InfoQueue::AddMessage(MessageCategory Category, MessageSeverity Severity, MessageId ID, String^ description)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(description);

    try
    {
        CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->AddMessage(
            static_cast<D3D11_MESSAGE_CATEGORY>(Category), 
            static_cast<D3D11_MESSAGE_SEVERITY>(Severity), 
            static_cast<D3D11_MESSAGE_ID>(ID), 
            static_cast<char*>(ptr.ToPointer())));
    }
    finally
    {
        Marshal::FreeHGlobal(ptr);
    }
}

void InfoQueue::ClearStoredMessages()
{
    GetInterface<ID3D11InfoQueue>()->ClearStoredMessages();
}

Boolean InfoQueue::GetBreakOnCategory(MessageCategory Category)
{
    return GetInterface<ID3D11InfoQueue>()->GetBreakOnCategory(static_cast<D3D11_MESSAGE_CATEGORY>(Category)) != 0;
}

Boolean InfoQueue::GetBreakOnId(MessageId ID)
{
    return GetInterface<ID3D11InfoQueue>()->GetBreakOnID(static_cast<D3D11_MESSAGE_ID>(ID)) != 0;
}

Boolean InfoQueue::GetBreakOnSeverity(MessageSeverity Severity)
{
    return GetInterface<ID3D11InfoQueue>()->GetBreakOnSeverity(static_cast<D3D11_MESSAGE_SEVERITY>(Severity)) != 0;
}

Message InfoQueue::GetMessage(UInt64 messageIndex)
{
    // Get the size of the message
    SIZE_T messageLength = 0;
    CommonUtils::VerifyResult(
        GetInterface<ID3D11InfoQueue>()->GetMessage(
        messageIndex, 
        NULL, 
        &messageLength));

    // Allocate space and get the message
    D3D11_MESSAGE * pMessage = (D3D11_MESSAGE*)malloc(messageLength);
    try
    {
        CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->GetMessage(
            messageIndex, 
            pMessage, 
            &messageLength));
        
        return Message(pMessage);
    }
    finally
    {
        free(pMessage);
    }
}

 bool InfoQueue::TryGetMessage(UInt64 messageIndex, [System::Runtime::InteropServices::Out] Message % outMessage)
{
    // Get the size of the message
    SIZE_T messageLength = 0;
    
    if (FAILED(GetInterface<ID3D11InfoQueue>()->GetMessage(messageIndex, NULL, &messageLength)))
    {
        outMessage = Message(NULL);
        return false;
    }

    // Allocate space and get the message
    D3D11_MESSAGE * pMessage = (D3D11_MESSAGE*)malloc(messageLength);
    ZeroMemory(pMessage, messageLength);
    try
    {
        if (SUCCEEDED(GetInterface<ID3D11InfoQueue>()->GetMessage(static_cast<UINT64>(messageIndex), pMessage, &messageLength)))
        {
            outMessage = Message(pMessage);
            return true;
        }
        else
        {
            outMessage = Message(NULL);
            return false;
        }
    }
    finally
    {
        free(pMessage);
    }
}
 UInt64 InfoQueue::MessageCountLimit::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetMessageCountLimit();
}

Boolean InfoQueue::MuteDebugOutput::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetMuteDebugOutput() != 0;
}

UInt64 InfoQueue::NumMessagesAllowedByStorageFilter::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetNumMessagesAllowedByStorageFilter();
}

UInt64 InfoQueue::NumMessagesDeniedByStorageFilter::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetNumMessagesDeniedByStorageFilter();
}

UInt64 InfoQueue::NumMessagesDiscardedByMessageCountLimit::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetNumMessagesDiscardedByMessageCountLimit();
}

UInt64 InfoQueue::NumStoredMessages::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetNumStoredMessages();
}

UInt64 InfoQueue::NumStoredMessagesAllowedByRetrievalFilter::get()
{
    return GetInterface<ID3D11InfoQueue>()->GetNumStoredMessagesAllowedByRetrievalFilter();
}

void InfoQueue::SetBreakOnCategory(MessageCategory Category, Boolean bEnable)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->SetBreakOnCategory(static_cast<D3D11_MESSAGE_CATEGORY>(Category), safe_cast<BOOL>(bEnable)));
}

void InfoQueue::SetBreakOnId(MessageId ID, Boolean bEnable)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->SetBreakOnID(static_cast<D3D11_MESSAGE_ID>(ID), bEnable ? 1 : 0));
}

void InfoQueue::SetBreakOnSeverity(MessageSeverity Severity, Boolean bEnable)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->SetBreakOnSeverity(static_cast<D3D11_MESSAGE_SEVERITY>(Severity), safe_cast<BOOL>(bEnable)));
}

void InfoQueue::MessageCountLimit::set(UInt64 value)
{
    CommonUtils::VerifyResult(GetInterface<ID3D11InfoQueue>()->SetMessageCountLimit(value));
}

void InfoQueue::MuteDebugOutput::set(Boolean value)
{
    GetInterface<ID3D11InfoQueue>()->SetMuteDebugOutput(value ? 1 : 0);
}

