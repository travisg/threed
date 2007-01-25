#ifndef __VECTOR4_H
#define __VECTOR4_H

namespace Math {

template <class T>
class Vector4
{
public:
	inline Vector4() {}
	inline ~Vector4() {}

	inline Vector4(T x1, T y1, T z1, T w1) :
		x(x1), y(y1), z(z1), w(w1) {}

	/* operators */
	Vector4 operator+(const Vector4 &v) const;
	Vector4 &operator+=(const Vector4 &v);
	Vector4 operator-(const Vector4 &v) const;
	Vector4 &operator-=(const Vector4 &v);
	Vector4 operator*(const Vector4 &v) const;
	Vector4 &operator*=(const Vector4 &v);

	/* common vector stuff */
	T Length() const;
	T LengthSquared() const;
	T Dot(const Vector4 &v) const;

	/* data */
	union {
		T val[4];
		struct {
			T x, y, z, w;
		};
	};
};

typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;

}

#endif
