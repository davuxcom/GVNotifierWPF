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
    /// A <see cref="MappingAsyncResult">MappingAsyncResult</see> subclass to be used only for asynchronous calls to service actions.
    /// <seealso cref="MappingService.BeginDoAction">MappingService.BeginDoAction</seealso>
    /// </summary>
    public class MappingActionAsyncResult : MappingAsyncResult
    {
        private int _rangeIndex;
        private string _actionId;

        internal MappingActionAsyncResult(
            object callerData,
            AsyncCallback asyncCallback,
            MappingPropertyBag bag,
            int rangeIndex,
            string actionId)
        : base(callerData, asyncCallback)
        {
            base.SetResult(bag, new MappingResultState());
            _rangeIndex = rangeIndex;
            _actionId = actionId;
        }

        /// <summary>
        /// Gets the range index parameter for <see cref="MappingService.DoAction">MappingService.DoAction</see> or <see cref="MappingService.BeginDoAction">MappingService.BeginDoAction</see>.
        /// </summary>
        public int RangeIndex
        {
            get
            {
                return _rangeIndex;
            }
        }

        /// <summary>
        /// Gets the action ID parameter for <see cref="MappingService.DoAction">MappingService.DoAction</see> or <see cref="MappingService.BeginDoAction">MappingService.BeginDoAction</see>.
        /// </summary>
        public string ActionId
        {
            get
            {
                return _actionId;
            }
        }
    }

}
