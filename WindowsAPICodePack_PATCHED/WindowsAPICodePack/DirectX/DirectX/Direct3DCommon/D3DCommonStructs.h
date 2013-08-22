//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D {

/// <summary>
/// This structure defines a 4 component float vector.
/// </summary>
public value struct Vector4F
{
public:
    /// <summary>
    /// Specifies the first element of the vector.
    /// </summary>
    float X;

    /// <summary>
    /// Specifies the second element of the vector.
    /// </summary>
    float Y;

    /// <summary>
    /// Specifies the third element of the vector.
    /// </summary>
    float Z;

    /// <summary>
    /// Specifies the fourth element of the vector.
    /// </summary>
    float W;


public:
    /// <summary>
    /// Initializes the vector from a set of values.
    /// </summary>
    /// <param name="x">Specifies value of x.</param>
    /// <param name="y">Specifies value of y.</param>
    /// <param name="z">Specifies value of z.</param>
    /// <param name="w">Specifies value of w.</param>
    Vector4F(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w)
    { }

    /// <summary>
    /// Initializes the vector from an array.
    /// </summary>
    /// <param name="dataSource">The vector data as an array of floats.</param>
    Vector4F( cli::array<float>^ dataSource )
    {
        if( dataSource->Length != sizeof( Vector4F ) / sizeof(float) )
            throw gcnew System::ArgumentException( gcnew System::String( L"Invalid array length" ) );

        this->X = dataSource[0];
        this->Y = dataSource[1];
        this->Z = dataSource[2];
        this->W = dataSource[3];
    }

    /// <summary>
    /// The vector equality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are equal.</returns>
    static Boolean operator ==(Vector4F a, Vector4F b )
    {
        return 
            (a.X == b.X) && 
            (a.Y == b.Y) && 
            (a.Z == b.Z) && 
            (a.W == b.W);
    }

    /// <summary>
    /// The vector inequality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are not equal.</returns>
    static Boolean operator !=( Vector4F a, Vector4F b )
    {
        return !(a == b);
    }
};


/// <summary>
/// This structure defines a 3 component float vector.
/// </summary>
public value struct Vector3F
{
public:
    /// <summary>
    /// Specifies the first element of the vector.
    /// </summary>
    float X;

    /// <summary>
    /// Specifies the second element of the vector.
    /// </summary>
    float Y;

    /// <summary>
    /// Specifies the third element of the vector.
    /// </summary>
    float Z;

public:
    /// <summary>
    /// Normalize the vector, returning a new one.
    /// </summary>
    /// <returns>The normalized vector</returns>
    Vector3F Normalize()
    {
        float length = (float)Math::Sqrt(X * X + Y * Y + Z * Z);
        if (length == 0)
            return Vector3F(0, 0, 0);
        else
            return Vector3F(X / length, Y / length, Z / length);
    }

    /// <summary>
    /// Normalize the vector.
    /// </summary>
    void NormalizeInPlace()
    {
        float length = (float)Math::Sqrt(X * X + Y * Y + Z * Z);
        
        if (length == 0)
        {
            X = Y = Z = 0;
        }
        else
        {
            X /= length;
            Y /= length;
            Z /= length;
        }
    }

    /// <summary>
    /// Compute the dot (scalar) product of the given vectors.
    /// </summary>
    /// <param name="a">Vector a.</param>
    /// <param name="b">Vector b.</param>
    /// <returns>The dot prodcut.</returns>
    static float Dot(Vector3F a, Vector3F b)
    {
        return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
    }

    /// <summary>
    /// Compute the cross product of the given vectors.
    /// </summary>
    /// <param name="a">Vector a.</param>
    /// <param name="b">Vector b.</param>
    /// <returns>The cross prodcut vector.</returns>
    static Vector3F Cross(Vector3F a, Vector3F b)
    {
        return Vector3F(
            a.Y * b.Z - a.Z * b.Y,
            a.Z * b.X - a.X * b.Z,
            a.X * b.Y - a.Y * b.X);
    }

    /// <summary>
    /// Adds two given vectors.
    /// </summary>
    /// <param name="a">Vector a.</param>
    /// <param name="b">Vector b.</param>
    /// <returns>The addition resultant vector.</returns>
    static Vector3F operator +(Vector3F a, Vector3F b)
    {
        return Vector3F(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
    }

    /// <summary>
    /// Subtracts vector b from vector a.
    /// </summary>
    /// <param name="a">Vector a.</param>
    /// <param name="b">Vector b.</param>
    /// <returns>The subtraction resultant vector.</returns>
    static Vector3F operator -(Vector3F a, Vector3F b)
    {
        return Vector3F(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
    }

public:
    /// <summary>
    /// Initializes the vector from a set of values.
    /// </summary>
    /// <param name="x">Specifies value of x.</param>
    /// <param name="y">Specifies value of y.</param>
    /// <param name="z">Specifies value of z.</param>
    Vector3F(float x, float y, float z) : X(x), Y(y), Z(z)
    { }

    /// <summary>
    /// Initializes the vector from an array.
    /// </summary>
    /// <param name="dataSource">The vector data as an array of floats.</param>
    Vector3F( cli::array<float>^ dataSource )
    {
        if( dataSource->Length != sizeof( Vector3F ) / sizeof(float) )
            throw gcnew System::ArgumentException( gcnew System::String( L"Invalid array length" ) );

        this->X = dataSource[0];
        this->Y = dataSource[1];
        this->Z = dataSource[2];
    }

    /// <summary>
    /// The vector equality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are equal.</returns>
    static Boolean operator ==( Vector3F a, Vector3F b )
    {
        return 
            (a.X == b.X) && 
            (a.Y == b.Y) && 
            (a.Z == b.Z);
    }

    /// <summary>
    /// The vector inequality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are not equal.</returns>
    static Boolean operator !=( Vector3F a, Vector3F b )
    {
        return !(a == b);
    }
};

/// <summary>
/// This structure defines a 2 component float vector.
/// </summary>
public value struct Vector2F
{
public:
    /// <summary>
    /// Specifies the first element of the vector.
    /// </summary>
    float X;

    /// <summary>
    /// Specifies the second element of the vector.
    /// </summary>
    float Y;


public:
    /// <summary>
    /// Initializes the vector from a set of values.
    /// </summary>
    /// <param name="x">Specifies value of x.</param>
    /// <param name="y">Specifies value of y.</param>
    Vector2F(float x, float y) : X(x), Y(y)
    { }

    /// <summary>
    /// Initializes the vector from an array.
    /// </summary>
    /// <param name="dataSource">The vector data as an array of floats.</param>
    Vector2F( cli::array<float>^ dataSource )
    {
        if( dataSource->Length != sizeof( Vector2F ) / sizeof(float) )
            throw gcnew System::ArgumentException( gcnew System::String( L"Invalid array length" ) );

        this->X = dataSource[0];
        this->Y = dataSource[1];
    }

    /// <summary>
    /// The vector equality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are equal.</returns>
    static Boolean operator ==( Vector2F a, Vector2F b )
    {
        return 
            (a.X == b.X) && 
            (a.Y == b.Y);
    }

    /// <summary>
    /// The vector inequality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are not equal.</returns>
    static Boolean operator !=( Vector2F a, Vector2F b )
    {
        return !(a == b);
    }
};

/// <summary>
/// This structure defines a 4 component int vector.
/// </summary>
public value struct Vector4I
{
public:
    /// <summary>
    /// Specifies the first element of the vector.
    /// </summary>
    int X;

    /// <summary>
    /// Specifies the second element of the vector.
    /// </summary>
    int Y;

    /// <summary>
    /// Specifies the third element of the vector.
    /// </summary>
    int Z;

    /// <summary>
    /// Specifies the fourth element of the vector.
    /// </summary>
    int W;


public:
    /// <summary>
    /// Initializes the vector from a set of values.
    /// </summary>
    /// <param name="x">Specifies value of x.</param>
    /// <param name="y">Specifies value of y.</param>
    /// <param name="z">Specifies value of z.</param>
    /// <param name="w">Specifies value of w.</param>
    Vector4I( int x, int y, int z, int w) : X(x), Y(y), Z(z), W(Y)
    { }

    /// <summary>
    /// Initializes the vector from an array.
    /// </summary>
    /// <param name="dataSource">The vector data as an array of floats.</param>
    Vector4I( cli::array<int>^ dataSource )
    {
        if( dataSource->Length != sizeof( Vector4I ) / sizeof(int) )
            throw gcnew System::ArgumentException( gcnew System::String( L"Invalid array length" ) );

        this->X = dataSource[0];
        this->Y = dataSource[1];
        this->Z = dataSource[2];
        this->W = dataSource[3];
    }

    /// <summary>
    /// The vector equality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are equal.</returns>
    static Boolean operator ==( Vector4I a, Vector4I b )
    {
        return 
            (a.X == b.X) && 
            (a.Y == b.Y) && 
            (a.Z == b.Z) && 
            (a.W == b.W);
    }

    /// <summary>
    /// The vector inequality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are not equal.</returns>
    static Boolean operator !=( Vector4I a, Vector4I b )
    {
        return !(a == b);
    }
};


/// <summary>
/// This structure defines a 4 component Boolean vector.
/// </summary>
public value struct Vector4B
{
public:
    /// <summary>
    /// Specifies the first element of the vector.
    /// </summary>
    Boolean X;

    /// <summary>
    /// Specifies the second element of the vector.
    /// </summary>
    Boolean Y;

    /// <summary>
    /// Specifies the third element of the vector.
    /// </summary>
    Boolean Z;

    /// <summary>
    /// Specifies the fourth element of the vector.
    /// </summary>
    Boolean W;

public:
    /// <summary>
    /// Initializes the vector from a set of values.
    /// </summary>
    /// <param name="x">Specifies value of x.</param>
    /// <param name="y">Specifies value of y.</param>
    /// <param name="z">Specifies value of z.</param>
    /// <param name="w">Specifies value of w.</param>
    Vector4B(Boolean x, Boolean y, Boolean z, Boolean w) : X(x), Y(y), Z(z), W(w)
    { }

    /// <summary>
    /// Initializes the vector from an array.
    /// </summary>
    /// <param name="dataSource">The vector data as an array of floats.</param>
    Vector4B( cli::array<Boolean>^ dataSource )
    {
        if( dataSource->Length != sizeof( Vector4B ) / sizeof(Boolean) )
            throw gcnew System::ArgumentException( gcnew System::String( L"Invalid array length" ) );

        this->X = dataSource[0];
        this->Y = dataSource[1];
        this->Z = dataSource[2];
        this->W = dataSource[3];
    }

    /// <summary>
    /// The vector equality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are equal.</returns>
    static Boolean operator ==( Vector4B a, Vector4B b )
    {
        return 
            (a.X == b.X) && 
            (a.Y == b.Y) && 
            (a.Z == b.Z) && 
            (a.W == b.W);
    }

    /// <summary>
    /// The vector inequality operator.
    /// </summary>
    /// <param name="a">The first vector.</param>
    /// <param name="b">The second vector.</param>
    /// <returns>True if the vectors are not equal.</returns>
    static Boolean operator !=( const Vector4B& a, const Vector4B& b )
    {
        return !(a == b);
    }
};


/// <summary>
/// This structure defines a 4 x 4 matrix using floats.
/// </summary>
public value struct Matrix4x4F
{
public:
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M11;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M12;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M13;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M14;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M21;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M22;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M23;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M24;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M31;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M32;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M33;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M34;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M41;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M42;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M43;
    /// <summary>
    /// Specifies the value of the matrix at a particular row and column.
    /// </summary>
    float M44;

public:
    /// <summary>
    /// Initializes the matrix from a set of values.
    /// </summary>
    /// <param name="m11">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m12">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m13">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m14">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m21">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m22">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m23">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m24">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m31">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m32">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m33">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m34">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m41">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m42">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m43">Specifies the value of the matrix at a particular row and column.</param>
    /// <param name="m44">Specifies the value of the matrix at a particular row and column.</param>
    Matrix4x4F( 
            float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44 ) 
            :
            M11(m11), M12(m12), M13(m13), M14(m14),
            M21(m21), M22(m22), M23(m23), M24(m24),
            M31(m31), M32(m32), M33(m33), M34(m34),
            M41(m41), M42(m42), M43(m43), M44(m44)

    { }

    /// <summary>
    /// Initializes the matrix from an array.
    /// </summary>
    /// <param name="dataSource">The matrix data as an array of floats.</param>
    Matrix4x4F( cli::array<float>^ dataSource )
    {
        if( dataSource->Length != sizeof( Matrix4x4F ) / sizeof(float) )
            throw gcnew System::ArgumentException( gcnew System::String( L"Invalid array length" ) );

        pin_ptr<float> destination = &this->M11;
        pin_ptr<float> source = &dataSource[0];
        memcpy( destination, source, Marshal::SizeOf(Matrix4x4F::GetType()));
    }

    /// <summary>
    /// Returns an identity matrix.
    /// </summary>
    static property Matrix4x4F Identity
    {
        Matrix4x4F get()
        {
            return Matrix4x4F( 
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
        }
    }

    /// <summary>
    /// The matrix multiplication operator (linear transformation composition).
    /// </summary>
    /// <param name="a">The first factor.</param>
    /// <param name="b">The second factor.</param>
    /// <returns>The product of the matricies.</returns>
    static Matrix4x4F operator *( Matrix4x4F a, Matrix4x4F b )
    {
        return Matrix4x4F(
            a.M11 * b.M11 + a.M12 * b.M21 + a.M13 * b.M31 + a.M14 * b.M41,
            a.M11 * b.M12 + a.M12 * b.M22 + a.M13 * b.M32 + a.M14 * b.M42,
            a.M11 * b.M13 + a.M12 * b.M23 + a.M13 * b.M33 + a.M14 * b.M43,
            a.M11 * b.M14 + a.M12 * b.M24 + a.M13 * b.M34 + a.M14 * b.M44,

            a.M21 * b.M11 + a.M22 * b.M21 + a.M23 * b.M31 + a.M24 * b.M41,
            a.M21 * b.M12 + a.M22 * b.M22 + a.M23 * b.M32 + a.M24 * b.M42,
            a.M21 * b.M13 + a.M22 * b.M23 + a.M23 * b.M33 + a.M24 * b.M43,
            a.M21 * b.M14 + a.M22 * b.M24 + a.M23 * b.M34 + a.M24 * b.M44,

            a.M31 * b.M11 + a.M32 * b.M21 + a.M33 * b.M31 + a.M34 * b.M41,
            a.M31 * b.M12 + a.M32 * b.M22 + a.M33 * b.M32 + a.M34 * b.M42,
            a.M31 * b.M13 + a.M32 * b.M23 + a.M33 * b.M33 + a.M34 * b.M43,
            a.M31 * b.M14 + a.M32 * b.M24 + a.M33 * b.M34 + a.M34 * b.M44,

            a.M41 * b.M11 + a.M42 * b.M21 + a.M43 * b.M31 + a.M44 * b.M41,
            a.M41 * b.M12 + a.M42 * b.M22 + a.M43 * b.M32 + a.M44 * b.M42,
            a.M41 * b.M13 + a.M42 * b.M23 + a.M43 * b.M33 + a.M44 * b.M43,
            a.M41 * b.M14 + a.M42 * b.M24 + a.M43 * b.M34 + a.M44 * b.M44
            );
    }

    /// <summary>
    /// The matrix equality operator.
    /// </summary>
    /// <param name="a">The first matrix.</param>
    /// <param name="b">The second matrix.</param>
    /// <returns>True if the matricies are equal.</returns>
    static Boolean operator ==( Matrix4x4F a, Matrix4x4F b )
    {
        return 
            (a.M11 == b.M11) && 
            (a.M12 == b.M12) && 
            (a.M13 == b.M13) && 
            (a.M14 == b.M14) && 

            (a.M21 == b.M21) && 
            (a.M22 == b.M22) && 
            (a.M23 == b.M23) && 
            (a.M24 == b.M24) && 

            (a.M31 == b.M31) && 
            (a.M32 == b.M32) && 
            (a.M33 == b.M33) && 
            (a.M34 == b.M34) && 

            (a.M41 == b.M41) && 
            (a.M42 == b.M42) && 
            (a.M43 == b.M43) && 
            (a.M44 == b.M44);
    }

    /// <summary>
    /// The matrix inequality operator.
    /// </summary>
    /// <param name="a">The first matrix.</param>
    /// <param name="b">The second second matrix.</param>
    /// <returns>True if the matricies are not equal.</returns>
    static Boolean operator !=( Matrix4x4F a, Matrix4x4F b )
    {
        return !(a == b);
    }

internal:
    Matrix4x4F( float* matrixArray )
    {
        pin_ptr<Matrix4x4F> self = this;
        memcpy( self, matrixArray, sizeof(Matrix4x4F) );
    }

};


/// <summary>
/// This structure defines the coordinates of the upper-left and lower-right corners of a rectangle.
/// </summary>
public value struct D3dRect 
{
public:
    /// <summary>
    /// Specifies the x-coordinate of the upper-left corner of the rectangle.
    /// </summary>
    Int32 Left;

    /// <summary>
    /// Specifies the y-coordinate of the upper-left corner of the rectangle.
    /// </summary>
    Int32 Top;

    /// <summary>
    /// Specifies the x-coordinate of the lower-right corner of the rectangle.
    /// </summary>
    Int32 Right;

    /// <summary>
    /// Specifies the y-coordinate of the lower-right corner of the rectangle.
    /// </summary>
    Int32 Bottom;

public:
    /// <summary>
    /// Explicit constructor.
    /// </summary>
    /// <param name="left">Specifies the x-coordinate of the upper-left corner of the rectangle.</param>
    /// <param name="top"> Specifies the y-coordinate of the upper-left corner of the rectangle.</param>
    /// <param name="right">Specifies the x-coordinate of the lower-right corner of the rectangle.</param>
    /// <param name="bottom">Specifies the y-coordinate of the lower-right corner of the rectangle.</param>
    D3dRect( Int32 left, Int32 top, Int32 right, Int32 bottom )
    {
        Left = left;
        Top = top;
        Right = right;
        Bottom = bottom;
    }

    /// <summary>
    /// The equality operator.
    /// </summary>
    /// <param name="a">The first rectangle.</param>
    /// <param name="b">The second second rectangle.</param>
    /// <returns>True if the rectangles are equal.</returns>
    static Boolean operator ==( D3dRect a, D3dRect b )
    {
        return
            (a.Left == b.Left) &&
            (a.Top == b.Top) &&
            (a.Bottom == b.Bottom) &&
            (a.Right == b.Right);
    }

    /// <summary>
    /// The inequality operator.
    /// </summary>
    /// <param name="a">The first rectangle.</param>
    /// <param name="b">The second second rectangle.</param>
    /// <returns>True if the rectangles are not equal.</returns>
    static Boolean operator !=( D3dRect a, D3dRect b )
    {
        return !(a == b);
    }

internal:
    D3dRect(RECT* pD3dRect)
    {
        Left = pD3dRect->left;
        Top = pD3dRect->top;
        Right = pD3dRect->right;
        Bottom = pD3dRect->bottom;
    }
    D3dRect(const RECT &rect)
    {
        Left = rect.left;
        Top = rect.top;
        Right = rect.right;
        Bottom = rect.bottom;
    }
    
    operator const RECT ()
    {
        RECT nativeRect;

        nativeRect.left = Left;
        nativeRect.top = Top;
        nativeRect.right = Right;
        nativeRect.bottom = Bottom;

        return nativeRect;
    }

};
} } } }
