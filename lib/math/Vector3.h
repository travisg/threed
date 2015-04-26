#ifndef __VECTOR3_H
#define __VECTOR3_H

#include <ostream>
#include "Math.h"

namespace Math {

template <class T>
class Vector3 {
public:
    inline Vector3() {}
    inline ~Vector3() {}

    Vector3(T i);
    Vector3(T x1, T y1, T z1);

    /* constructors */
    Vector3(const Vector3 &v);
    Vector3 &operator=(const Vector3 &v);

    /* accessors */
    T getx() const;
    T gety() const;
    T getz() const;

    /* operators */
    T* operator*() const;
    Vector3 operator+(const Vector3 &v) const;
    Vector3 &operator+=(const Vector3 &v);
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator-() const;
    Vector3 &operator-=(const Vector3 &v);
    Vector3 operator*(const Vector3 &v) const;
    Vector3 &operator*=(const Vector3 &v);

    /* scalar ops */
    Vector3 operator*(T scalar) const;
    template <class T2> friend Vector3<T2> operator*(T2 scalar, const Vector3<T2> &v);
    Vector3 &operator*=(T scalar);
    Vector3 operator/(T scalar) const;
    Vector3 &operator/=(T scalar);

    /* common vector stuff */
    T Length() const;
    T LengthSquared() const;
    T Dot(const Vector3 &v) const;
    template <class T2> friend T2 Dot(const Vector3<T2> &v1, const Vector3<T2> &v2);
    void Normalize();
    void Normalize(T n);

    template <class T2> friend Vector3<T2> Cross(const Vector3<T2> &v1, const Vector3<T2> &v2);

    operator const T*() const { return &x; }

private:
    /* data */
    T x, y, z, _w;
};

typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

/* debugging */
template <class T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &v);

/* inline constructors */
template <class T>
inline Vector3<T>::Vector3(T x1, T y1, T z1)
{
    x = x1;
    y = y1;
    z = z1;
}

template <class T>
inline Vector3<T>::Vector3(T val)
{
    x = val;
    y = val;
    z = val;
}

template <class T>
inline Vector3<T>::Vector3(const Vector3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

template <class T>
inline Vector3<T> &Vector3<T>::operator=(const Vector3 &v)
{
    if (this == &v)
        return *this;

    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

template <class T> inline T Vector3<T>::getx() const { return x; }
template <class T> inline T Vector3<T>::gety() const { return y; }
template <class T> inline T Vector3<T>::getz() const { return z; }

template <class T>
inline Vector3<T> Vector3<T>::operator+(const Vector3 &v) const
{
    return Vector3<T>(x + v.x, y + v.y, z + v.z);
}

template <class T>
inline Vector3<T> &Vector3<T>::operator+=(const Vector3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

template <class T>
inline Vector3<T> Vector3<T>::operator-(const Vector3 &f) const
{
    return Vector3<T>(x - f.x, y - f.y, z - f.z);
}

template <class T>
inline Vector3<T> Vector3<T>::operator-() const
{
    return Vector3<T>(-x, -y, -z);
}

template <class T>
inline Vector3<T> &Vector3<T>::operator-=(const Vector3 &f)
{
    x -= f.x;
    y -= f.y;
    z -= f.z;
    return *this;
}

template <class T>
inline Vector3<T> Vector3<T>::operator*(const Vector3 &f) const
{
    return Vector3<T>(x * f.x, y * f.y, z * f.z);
}

template <class T>
inline Vector3<T> &Vector3<T>::operator*=(const Vector3 &f)
{
    x *= f.x;
    y *= f.y;
    z *= f.z;
    return *this;
}

template <class T>
inline Vector3<T> Vector3<T>::operator*(T scalar) const
{
    return Vector3<T>(x * scalar, y * scalar, z * scalar);
}

template <class T>
inline Vector3<T> operator*(T scalar, const Vector3<T> &v)
{
    return Vector3<T>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template <class T>
inline Vector3<T> &Vector3<T>::operator*=(T scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template <class T>
inline Vector3<T> Vector3<T>::operator/(T scalar) const
{
    return Vector3<T>(x / scalar, y / scalar, z / scalar);
}

template <class T>
inline Vector3<T> &Vector3<T>::operator/=(T scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

template <class T>
inline T Vector3<T>::LengthSquared() const
{
    return (x*x + y*y + z*z);
}

template <class T>
inline T Vector3<T>::Length() const
{
    return Math<T>::sqrt(x*x + y*y + z*z);
}

template <class T>
inline T Vector3<T>::Dot(const Vector3<T> &v) const
{
    return (x*v.x + y*v.y + z*v.z);
}

template <class T2>
inline T2 Dot(const Vector3<T2> &v1, const Vector3<T2> &v2)
{
    return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

}

#endif

