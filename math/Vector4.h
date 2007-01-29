#ifndef __VECTOR4_H
#define __VECTOR4_H

#include <ostream>

namespace Math {

class Vector4
{
public:
	inline Vector4() {}
	inline ~Vector4() {}

	inline Vector4(float x1, float y1, float z1, float w1) :
		x(x1), y(y1), z(z1), w(w1) {}

	/* constructors */
	inline Vector4(const Vector4 &v);
	inline Vector4 &operator=(const Vector4 &v);

	/* operators */
	Vector4 operator+(const Vector4 &v) const;
	Vector4 &operator+=(const Vector4 &v);
	Vector4 operator-(const Vector4 &v) const;
	Vector4 &operator-=(const Vector4 &v);
	Vector4 operator*(const Vector4 &v) const;
	Vector4 &operator*=(const Vector4 &v);

	/* common vector stuff */
	float Length() const;
	float LengthSquared() const;
	float Dot(const Vector4 &v) const;

	/* data */
	union {
		float val[4];
		struct {
			float x, y, z, w;
		};
	};
};

/* debugging */
std::ostream &operator<<(std::ostream &os, Vector4 &v);

/* inline constructors */
inline Vector4::Vector4(const Vector4 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline Vector4 &Vector4::operator=(const Vector4 &v)
{
	if (this == &v)
		return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

}

#endif

