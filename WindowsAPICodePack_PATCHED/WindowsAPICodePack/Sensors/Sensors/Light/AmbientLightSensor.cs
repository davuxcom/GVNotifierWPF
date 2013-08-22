// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// Represents a generic ambient light sensor.
    /// </summary>
    [SensorDescription( "97F115C8-599A-4153-8894-D2D12899918A" )]
    public class AmbientLightSensor : Sensor
    {
        /// <summary>
        /// Gets an array representing the light response curve.
        /// </summary>
        /// <returns>Array representing the light response curve.</returns>
        public uint[] GetLightResponseCurve()
        {
            return (uint[])GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_LIGHT_RESPONSE_CURVE );
        }

        /// <summary>
        /// Gets the current luminous intensity of the sensor.
        /// </summary>
        public LuminousIntensity CurrentLuminousIntensity
        {
            get
            {
                return new LuminousIntensity( this.DataReport );
            }
        }

    }

    /// <summary>
    /// Defines a luminous intensity measurement. 
    /// </summary>
    public class LuminousIntensity
    {
        /// <summary>
        /// Initializes a sensor report to obtain a luminous intensity value.
        /// </summary>
        /// <param name="report">The report name.</param>
        /// <returns></returns>
        public LuminousIntensity(SensorReport report)
        {
            if (report.Values.ContainsKey(SensorPropertyKeys.SENSOR_DATA_TYPE_LIGHT_LUX.FormatId))
            {
                this.intensity =
                    (float)report.Values[SensorPropertyKeys.SENSOR_DATA_TYPE_LIGHT_LUX.FormatId][0];
            }
        }
        /// <summary>
        /// Gets the intensity of the light in lumens.
        /// </summary>
        public float Intensity
        {
            get
            {
                return intensity;
            }
        }
        float intensity = 0;
    }
}
