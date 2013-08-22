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
    /// A <see cref="MappingAsyncResult">MappingAsyncResult</see> subclass to be used only for asynchronous calls to text recognition.
    /// <seealso cref="MappingService.BeginDoAction">MappingService.BeginDoAction</seealso>
    /// </summary>
    public class MappingRecognizeAsyncResult : MappingAsyncResult
    {
        private string _text;
        private int _length;
        private int _index;
        private MappingOptions _options;

        internal MappingRecognizeAsyncResult(
            object callerData,
            AsyncCallback asyncCallback,
            string text,
            int length,
            int index,
            MappingOptions options)
        : base (callerData, asyncCallback)
        {
            _text = text;
            _length = length;
            _index = index;
            _options = options;
        }

        /// <summary>
        /// Gets the text parameter for MappingService.RecognizeText or MappingService.BeginRecognizeText.
        /// </summary>
        public string Text
        {
            get
            {
                return _text;
            }
        }

        /// <summary>
        /// Gets the length parameter for MappingService.RecognizeText or MappingService.BeginRecognizeText.
        /// </summary>
        public int Length
        {
            get
            {
                return _length;
            }
        }

        /// <summary>
        /// Gets the index parameter for MappingService.RecognizeText or MappingService.BeginRecognizeText.
        /// </summary>
        public int Index
        {
            get
            {
                return _index;
            }
        }

        /// <summary>
        /// Gets the options parameter for MappingService.RecognizeText or MappingService.BeginRecognizeText.
        /// </summary>
        public MappingOptions Options
        {
            get
            {
                return _options;
            }
        }
    }

}
