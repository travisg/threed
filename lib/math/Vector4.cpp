#include <iostream>
#include "Math.h"
#include "Vector4.h"

namespace Math {

std::ostream &operator<<(std::ostream &os, const Vector4 &v)
{
	os << "[ " << v.getx() << " " << v.gety() << " " << v.getz() << " " << v.getw() << " ]";
	return os;
}

void Vector4::Normalize()
{
	float lenSquared = LengthSquared();

	if (lenSquared == 0.0f) {
		x = y = z = w = 0;
	} else {
		float invsqrt = 1.0f / Math<float>::sqrt(lenSquared);

		x *= invsqrt;
		y *= invsqrt;
		z *= invsqrt;
		w *= invsqrt;
	}
}

void Vector4::Normalize(float n)
{
	float lenSquared = LengthSquared();

	if (lenSquared == 0.0f) {
		x = y = z = w = 0;
	} else {
		float invsqrt = n / Math<float>::sqrt(lenSquared);

		x *= invsqrt;
		y *= invsqrt;
		z *= invsqrt;
		w *= invsqrt;
	}
}

}

