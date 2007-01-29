#include <math/Math.h>

namespace Math {

std::ostream &operator<<(std::ostream &os, Vector3 &v)
{
	os << "[ " << v.x << " " << v.y << " " << v.z << " ]";
	return os;
}

Vector3 Vector3::operator+(const Vector3 &v) const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 &Vector3::operator+=(const Vector3 &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3 &f) const
{
	return Vector3(x - f.x, y - f.y, z - f.z);
}

Vector3 &Vector3::operator-=(const Vector3 &f)
{
	x -= f.x;
	y -= f.y;
	z -= f.z;
	return *this;
}

Vector3 Vector3::operator*(const Vector3 &f) const
{
	return Vector3(x * f.x, y * f.y, z * f.z);
}

Vector3 &Vector3::operator*=(const Vector3 &f)
{ 
	x *= f.x;
	y *= f.y;
	z *= f.z;
	return *this;
}

float Vector3::Length() const
{
	return Math<float>::sqrt(x*x + y*y + z*z);
}

float Vector3::LengthSquared() const
{
	return (x*x + y*y + z*z);
}

float Vector3::Dot(const Vector3 &v) const
{
	return (x*v.x + y*v.y + z*v.z);
}

}

