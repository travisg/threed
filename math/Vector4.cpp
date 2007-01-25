#include <math/Math.h>
#include <math/Vector4.h>

namespace Math {


template <class T>
Vector4<T> Vector4<T>::operator+(const Vector4<T> &v) const
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

template <class T>
Vector4<T> &Vector4<T>::operator+=(const Vector4<T> &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

template <class T>
Vector4<T> Vector4<T>::operator-(const Vector4<T> &f) const
{
	return Vector4(x - f.x, y - f.y, z - f.z, w - f.w);
}


template <class T>
Vector4<T> &Vector4<T>::operator-=(const Vector4<T> &f)
{
	x -= f.x;
	y -= f.y;
	z -= f.z;
	w -= f.w;
	return *this;
}

template <class T>
Vector4<T> Vector4<T>::operator*(const Vector4<T> &f) const
{
	return Vector4(x * f.x, y * f.y, z * f.z, w * f.w);
}

template <class T>
Vector4<T> &Vector4<T>::operator*=(const Vector4<T> &f)
{ 
	x *= f.x;
	y *= f.y;
	z *= f.z;
	w *= f.w;
	return *this;
}

template <class T>
T Vector4<T>::Length() const
{
	return Math<T>::sqrt(x*x + y*y + z*z + w*w);
}

template <class T>
T Vector4<T>::LengthSquared() const
{
	return (x*x + y*y + z*z + w*w);
}

template <class T>
T Vector4<T>::Dot(const Vector4<T> &v) const
{
	return (x*v.x + y*v.y + z*v.z + w*v.w);	
}

/* instantiation of some common versions */
template class Vector4<float>;
template class Vector4<double>;

}

