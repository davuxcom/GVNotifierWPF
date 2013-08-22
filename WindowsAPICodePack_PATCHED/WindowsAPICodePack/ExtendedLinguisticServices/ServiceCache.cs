// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;
using System.Threading;
using System.Collections;
using System.Runtime.ConstrainedExecution;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.ExtendedLinguisticServices
{

    // This singleton object is correctly finalized on appdomain unload.
    internal class ServiceCache : CriticalFinalizerObject
    {
        private static ServiceCache staticInstance = null;

        // Guid -> IntPtr
        private Dictionary<Guid, IntPtr> _guidToService = null;
        // IntPtr -> this (serves as a set)
        private List<IntPtr> _servicePointers = new List<IntPtr>();
        // The lock
        private ReaderWriterLockSlim _cacheLock = new ReaderWriterLockSlim();
        // Active resources refcount, signed 64-bit
        private Int64 _resourceRefCount = 0;
        // Specifies if the object has been finalized:
        private int _finalized = 0;

        private ServiceCache()
        {
        }

        ~ServiceCache()
        {
            ReleaseHandle();
        }

        internal IntPtr GetCachedService(ref Guid guid)
        {
            _cacheLock.EnterReadLock();
            try
            {
                if (_guidToService == null)
                {
                    return IntPtr.Zero;
                }
                IntPtr result;
                _guidToService.TryGetValue(guid, out result);
                return result;
            }
            finally
            {
                _cacheLock.ExitReadLock();
            }
        }

        internal void RegisterServices(ref IntPtr originalPtr, IntPtr[] services)
        {
            bool addedToCache = false;
            bool succeeded = false;
            int length = services.Length;
            // We are taking the write lock to make this function atomic.
            // Thus, enumerating services will generally be a slow operation
            // because of this bottleneck. However, creating a service
            // by GUID should still be relatively fast, since this function
            // will be called only the first time(s) the service is initialized.
            // Note that the write lock is being released in the Cleanup() method.
            _cacheLock.EnterWriteLock();
            try
            {
                TryRegisterServices(originalPtr, services, ref addedToCache);
                succeeded = true;
                if (addedToCache)
                {
                    // Added to cache means that we have added at least one
                    // of the services to the service cache. In this case,
                    // we need to set the originalPtr to IntPtr.Zero, in order
                    // to tell the caller not to free the native pointer.
                    originalPtr = IntPtr.Zero;
                }
            }
            finally
            {
                // Succeeded is false in case there's an exception
                // being thrown at the moment.
                Cleanup(originalPtr, length, succeeded);
            }
        }

        private void Cleanup(IntPtr originalPtr, int length, bool succeeded)
        {
            // Here, we'll try to rollback the cache state in case an exception
            // has been thrown. Also, at the end, we'll release the write lock.
            try
            {
                // Succeeded is false in case there's an exception
                // being thrown at the moment.
                if (!succeeded)
                {
                    // We will try to rollback the cache, removing
                    // any pointers derived from originalPtr
                    RollBack(originalPtr, length);
                }
            }
            finally
            {
                _cacheLock.ExitWriteLock();
            }
        }

        private void TryRegisterServices(IntPtr originalPtr, IntPtr[] services, ref bool addedToCache)
        {
            // Here, we will try to add the newly enumerated
            // services to the service cache.
            if (_guidToService == null)
            {
                _guidToService = new Dictionary<Guid, IntPtr>();
            }
            IntPtr pServices = originalPtr;
            for (int i = 0; i < services.Length; ++i)
            {
                Guid guid = (Guid)Marshal.PtrToStructure(
                    (IntPtr)((UInt64)pServices + InteropTools.OffsetOfGuidInService), InteropTools.TypeOfGuid);
                IntPtr cachedValue;
                _guidToService.TryGetValue(guid, out cachedValue);
                if (cachedValue == IntPtr.Zero)
                {
                    _guidToService.Add(guid, pServices);
                    cachedValue = pServices;
                    addedToCache = true;
                }
                System.Diagnostics.Debug.Assert(cachedValue != IntPtr.Zero, "Cached value is NULL");
                services[i] = cachedValue;
                pServices = (IntPtr)((UInt64)pServices + InteropTools.SizeOfService);
            }
            if (addedToCache)
            {
                // This means that at least one of the services was stored in the cache.
                // So we must keep the original pointer in our cleanup list.
                _servicePointers.Add(originalPtr);
            }
        }

        private void RollBack(IntPtr pServices, int length)
        {
            if (_guidToService != null)
            {
                bool succeeded = false;
                try
                {
                    // First, remove the original pointer from the cleanup list.
                    // The caller of RegisterServices() will take care
                    // of freeing it.
                    _servicePointers.Remove(pServices);
                    // Then, attempt to recover the state of the _guidToService Dictionary.
                    // This should not fail.
                    for (int i = 0; i < length; ++i)
                    {
                        Guid guid = (Guid)Marshal.PtrToStructure(
                            (IntPtr)((UInt64)pServices + InteropTools.OffsetOfGuidInService), InteropTools.TypeOfGuid);
                        _guidToService.Remove(guid);
                        pServices = (IntPtr)((UInt64)pServices + InteropTools.SizeOfService);
                    }
                    succeeded = true;
                }
                finally
                {
                    if (!succeeded)
                    {
                        // This should never happen, as none of the above functions
                        // should be allocating any memory, and this rollback
                        // should generally happen in a low-memory condition.
                        // In this case, keep the _servicePointers cleanup list,
                        // but invalidate the whole cache, since we may still have
                        // traces of the original pointer there.
                        _guidToService = null;
                    }
                }
            }
        }

        internal bool RegisterResource()
        {
            // The correctness of this code relies on the
            // fact that there can be no Int64.MaxValue / 2
            // executing this code at the same time.
            if (Interlocked.Increment(ref _resourceRefCount) > Int64.MaxValue / 2)
            {
                Interlocked.Decrement(ref _resourceRefCount);
                return false;
            }
            return true;
        }

        internal void UnregisterResource()
        {
            if (Interlocked.Decrement(ref _resourceRefCount) == 0 && IsInvalid)
            {
                FreeAllServices();
            }
        }

        private bool IsInvalid
        {
            get
            {
                return Interlocked.CompareExchange(ref _finalized, 1, 1) != 0;
            }
        }

        private void ReleaseHandle()
        {
            if (!IsInvalid)
            {
                if (Interlocked.Read(ref _resourceRefCount) == 0)
                {
                    FreeAllServices();
                }
                Interlocked.CompareExchange(ref _finalized, 1, 0);
            }
        }

        private void FreeAllServices()
        {
            // Don't use synchronization here.
            // This will only be called during finalization
            // and at that point synchronization doesn't matter.
            // Also, the lock object might have already been finalized.
            if (_servicePointers != null)
            {
                foreach (IntPtr servicePtr in _servicePointers)
                {
                    // Ignore the result, we need to continue anyway.
                    Win32Methods.MappingFreeServices(servicePtr);
                }
                _servicePointers = null;
                _guidToService = null;
            }
        }

        internal static ServiceCache Instance
        {
            get
            {
                if (Interlocked.CompareExchange(ref staticInstance, null, null) == null)
                {
                    ServiceCache cache = new ServiceCache();
                    ServiceCache previousValue = Interlocked.CompareExchange(ref staticInstance, cache, null);
                    if (previousValue != null)
                    {
                        System.GC.SuppressFinalize(cache);
                    }
                }
                return Interlocked.CompareExchange(ref staticInstance, null, null);
            }
        }

    }

}
