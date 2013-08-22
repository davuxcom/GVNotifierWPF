// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// An attribute which is applied on <see cref="Sensor"/>-derived types. Provides essential metadata
    /// such as the GUID of the sensor type for which this wrapper was written.
    /// </summary>
    [AttributeUsage( AttributeTargets.Class, Inherited = false, AllowMultiple = false )]
    public class SensorDescriptionAttribute : Attribute
    {
        private string sensorTypeGuid;

        /// <summary>
        /// Constructs the attribue with a string represening the sensor type GUID and the type of the data report class.
        /// </summary>
        /// <param name="sensorTypeGuid">String representing the sensor type GUID.</param>
        public SensorDescriptionAttribute( string sensorTypeGuid )
        {
            this.sensorTypeGuid = sensorTypeGuid;
        }

        /// <summary>
        /// Gets or sets a string representing the sensor type GUID.
        /// </summary>
        public string SensorType
        {
            get { return this.sensorTypeGuid; }
            set { this.sensorTypeGuid = value; }
        }

        /// <summary>
        /// Gets the GUID of the sensor type.
        /// </summary>
        internal Guid SensorTypeGuid
        {
            get { return new Guid( this.sensorTypeGuid ); }
        }
    }
}