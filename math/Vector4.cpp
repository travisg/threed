#include <iostream>
#include <math/Math.h>
#include <math/Vector4.h>

namespace Math {

std::ostream &operator<<(std::ostream &os, Vector4 &v)
{
	os << "[ " << v.x << " " << v.y << " " << v.z << " " << v.w << " ]";
	return os;
}

Vector4 Vector4::operator+(const Vector4 &v) const
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 &Vector4::operator+=(const Vector4 &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

Vector4 Vector4::operator-(const Vector4 &f) const
{
	return Vector4(x - f.x, y - f.y, z - f.z, w - f.w);
}


Vector4 &Vector4::operator-=(const Vector4 &f)
{
	x -= f.x;
	y -= f.y;
	z -= f.z;
	w -= f.w;
	return *this;
}

Vector4 Vector4::operator*(const Vector4 &f) const
{
	return Vector4(x * f.x, y * f.y, z * f.z, w * f.w);
}

Vector4 &Vector4::operator*=(const Vector4 &f)
{ 
	x *= f.x;
	y *= f.y;
	z *= f.z;
	w *= f.w;
	return *this;
}

float Vector4::Length() const
{
	return Math<float>::sqrt(x*x + y*y + z*z + w*w);
}

float Vector4::LengthSquared() const
{
	return (x*x + y*y + z*z + w*w);
}

float Vector4::Dot(const Vector4 &v) const
{
	return (x*v.x + y*v.y + z*v.z + w*v.w);	
}

}

