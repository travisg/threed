#ifndef __VECTOR3_H
#define __VECTOR3_H

#include <ostream>

namespace Math {

class Vector3
{
public:
	inline Vector3() {}
	inline ~Vector3() {}

	inline Vector3(float x1, float y1, float z1) :
		x(x1), y(y1), z(z1) {}

	/* constructors */
	inline Vector3(const Vector3 &v);
	inline Vector3 &operator=(const Vector3 &v);

	/* operators */
	Vector3 operator+(const Vector3 &v) const;
	Vector3 &operator+=(const Vector3 &v);
	Vector3 operator-(const Vector3 &v) const;
	Vector3 &operator-=(const Vector3 &v);
	Vector3 operator*(const Vector3 &v) const;
	Vector3 &operator*=(const Vector3 &v);

	/* scalar ops */
	Vector3 operator*(float scalar) const;
	friend Vector3 operator*(float scalar, const Vector3 &v);
	Vector3 &operator*=(float scalar);
	Vector3 operator/(float scalar) const;
	Vector3 &operator/=(float scalar);

	/* common vector stuff */
	float Length() const;
	float LengthSquared() const;
	float Dot(const Vector3 &v) const;
	friend float Dot(const Vector3 &v1, const Vector3 &v2);

	/* data */
	union {
		float val[4];
		struct {
			float x, y, z, _w;
		};
	};
};

/* debugging */
std::ostream &operator<<(std::ostream &os, Vector3 &v);

/* inline constructors */
inline Vector3::Vector3(const Vector3 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline Vector3 &Vector3::operator=(const Vector3 &v)
{
	if (this == &v)
		return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

}

#endif

