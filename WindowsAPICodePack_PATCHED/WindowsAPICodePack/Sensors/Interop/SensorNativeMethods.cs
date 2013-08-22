// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;


namespace Microsoft.WindowsAPICodePack.Sensors
{

    internal static class SensorNativeMethods
    {
        [DllImport( "kernel32.dll" )]
        internal static extern bool SystemTimeToFileTime( ref SYSTEMTIME lpSystemTime, out System.Runtime.InteropServices.ComTypes.FILETIME lpFileTime );
    }
}
