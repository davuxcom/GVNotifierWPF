// Copyright (c) Microsoft Corporation.  All rights reserved.

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// Represents a 3D accelerometer.
    /// </summary>
    [SensorDescription( "C2FB0F5F-E2D2-4C78-BCD0-352A9582819D" )]
    public class Accelerometer3D : Sensor
    {
        /// <summary>
        /// Gets the current acceleration in G's. 
        /// </summary>
        public Acceleration3D CurrentAcceleration
        {
            get
            {
                return new Acceleration3D( this.DataReport );
            }
        }
    }

    /// <summary>
    /// Specifies the axis of the acceleration measurement.
    /// </summary>
    public enum AccelerationAxis
    {
        /// <summary>
        /// The x-axis.
        /// </summary>
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704:IdentifiersShouldBeSpelledCorrectly", MessageId = "X")]
        X = 0,
        /// <summary>
        /// The y-axis.
        /// </summary>
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704:IdentifiersShouldBeSpelledCorrectly", MessageId = "Y")]
        Y = 1,
        /// <summary>
        /// THe z-axis.
        /// </summary>
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704:IdentifiersShouldBeSpelledCorrectly", MessageId = "Z")]
        Z = 2
    }

    /// <summary>
    /// Creates an acceleration measurement from the data in the report.
    /// </summary>
    public class Acceleration3D
    {
        /// <summary>
        /// Creates a new instance of this class.
        /// </summary>
        /// <param name="report">The sensor report to evaluate.</param>
        public Acceleration3D ( SensorReport report )
        {
            this.acceleration[ (int)AccelerationAxis.X ] =
                (float)report.Values[ SensorPropertyKeys.SENSOR_DATA_TYPE_ACCELERATION_X_G.FormatId ][ 0 ];
            this.acceleration[ (int)AccelerationAxis.Y ] =
                (float)report.Values[ SensorPropertyKeys.SENSOR_DATA_TYPE_ACCELERATION_Y_G.FormatId ][ 1 ];
            this.acceleration[ (int)AccelerationAxis.Z ] =
                (float)report.Values[ SensorPropertyKeys.SENSOR_DATA_TYPE_ACCELERATION_Z_G.FormatId ][ 2 ];
        }

        /// <summary>
        /// Gets the acceleration reported by the sensor.
        /// </summary>
        /// <param name="axis">The axis of the acceleration.</param>
        /// <returns></returns>
        public float this[AccelerationAxis axis]
        {
            get { return acceleration[(int)axis]; }
        }
        private float[] acceleration = new float[3];
    }
}
