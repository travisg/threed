#include <math/Math.h>

namespace Math {



template <class T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &v) const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

template <class T>
Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template <class T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &f) const
{
	return Vector3(x - f.x, y - f.y, z - f.z);
}

template <class T>
Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &f)
{
	x -= f.x;
	y -= f.y;
	z -= f.z;
	return *this;
}

template <class T>
Vector3<T> Vector3<T>::operator*(const Vector3<T> &f) const
{
	return Vector3(x * f.x, y * f.y, z * f.z);
}

template <class T>
Vector3<T> &Vector3<T>::operator*=(const Vector3<T> &f)
{ 
	x *= f.x;
	y *= f.y;
	z *= f.z;
	return *this;
}

template <class T>
T Vector3<T>::Length() const
{
	return Math<T>::sqrt(x*x + y*y + z*z);
}

template <class T>
T Vector3<T>::LengthSquared() const
{
	return (x*x + y*y + z*z);
}

template <class T>
T Vector3<T>::Dot(const Vector3<T> &v) const
{
	return (x*v.x + y*v.y + z*v.z);
}

/* instantiation of some common versions */
template class Vector3<float>;
template class Vector3<double>;

}

