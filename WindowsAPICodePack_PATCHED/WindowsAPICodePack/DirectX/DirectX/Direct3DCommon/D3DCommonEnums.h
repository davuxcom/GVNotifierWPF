//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D {

/// <summary>
/// Describes the set of features targeted by a Direct3D device.
/// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL)</para>
/// <para>(Also see DirectX SDK: D2D1_FEATURE_LEVEL)</para>
/// </summary>
public enum class FeatureLevel 
{
    /// <summary>
    /// The caller does not require a particular underlying D3D device level.
    /// </summary>
    Default = 0,
    /// <summary>
    /// Targets features supported by Direct3D 9.1 including shader model 2.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_9_1)</para>
    /// </summary>
    FeatureLevel_9_1 = D3D_FEATURE_LEVEL_9_1,
    /// <summary>
    /// Targets features supported by Direct3D 9.2 including shader model 2.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_9_2)</para>
    /// </summary>
    FeatureLevel_9_2 = D3D_FEATURE_LEVEL_9_2,
    /// <summary>
    /// Targets features supported by Direct3D 9.3 including shader shader model 3.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_9_3)</para>
    /// </summary>
    FeatureLevel_9_3 = D3D_FEATURE_LEVEL_9_3,
    /// <summary>
    /// Targets features supported by Direct3D 10.0 including shader shader model 4.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_10_0)</para>
    /// </summary>
    FeatureLevel_10_0 = D3D_FEATURE_LEVEL_10_0,
    /// <summary>
    /// Targets features supported by Direct3D 10.1 including shader shader model 4.1.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_10_1)</para>
    /// </summary>
    FeatureLevel_10_1 = D3D_FEATURE_LEVEL_10_1,
    /// <summary>
    /// Targets features supported by Direct3D 11.0 including shader shader model 5.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_11_0)</para>
    /// </summary>
    FeatureLevel_11_0 = D3D_FEATURE_LEVEL_11_0,
};
/// <summary>
/// Direct3D Devices supported by this library.
/// </summary>
public enum class DeviceType
{
    /// <summary>
    /// Direct3D Device 10.0
    /// </summary>
    Direct3D_10_0 = 0,

    /// <summary>
    /// Direct3D Device 10.1
    /// </summary>
    Direct3D_10_1 = 1,
    
    /// <summary>
    /// Direct3D Device 11.0
    /// </summary>
    Direct3D_11_0 = 2,
};

} } }  }
