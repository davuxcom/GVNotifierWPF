// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Runtime.ConstrainedExecution;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.ExtendedLinguisticServices
{

    /// <summary>
    /// Converts byte arrays into Unicode (UTF-16) strings.
    /// </summary>
    public class StringFormatter : IMappingFormatter<string>
    {
        /// <summary>
        /// Converts a single <see cref="MappingDataRange">MappingDataRange</see> into a string.
        /// </summary>
        /// <param name="dataRange">The <see cref="MappingDataRange">MappingDataRange</see> to convert</param>
        /// <returns>The resulting string</returns>
        public string Format(MappingDataRange dataRange)
        {
            byte[] data = dataRange.GetData();
            string resultText = Encoding.Unicode.GetString(data);
            return resultText;
        }

        /// <summary>
        /// Uses <see cref="Format(MappingDataRange)">Format</see> to format all the ranges of the supplied
        /// MappingPropertyBag.
        /// </summary>
        /// <param name="bag">The property bag to convert.</param>
        /// <returns>An array of strings, one per <see cref="MappingDataRange">MappingDataRange</see>.</returns>
        public string[] FormatAll(MappingPropertyBag bag)
        {
            MappingDataRange[] dataRanges = bag.GetResultRanges();
            string[] results = new string[dataRanges.Length];
            for (int i = 0; i < results.Length; ++i)
            {
                results[i] = Format(dataRanges[i]);
            }
            return results;
        }
    }

}
