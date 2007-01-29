#ifndef __VECTOR3_H
#define __VECTOR3_H

namespace Math {

template <class T>
class Vector3
{
public:
	inline Vector3() {}
	inline ~Vector3() {}

	inline Vector3(T x1, T y1, T z1) :
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

	/* common vector stuff */
	T Length() const;
	T LengthSquared() const;
	T Dot(const Vector3 &v) const;

	/* data */
	union {
		T val[3];
		struct {
			T x, y, z;
		};
	};
};

/* debugging */
template <class T>
std::ostream &operator<<(std::ostream &os, Vector3<T> &v)
{
	os << "[ " << v.x << " " << v.y << " " << v.z << " ]";
	return os;
}

template <class T>
inline Vector3<T>::Vector3(const Vector3<T> &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

template <class T>
inline Vector3<T> &Vector3<T>::operator=(const Vector3<T> &v)
{
	if (this == &v)
		return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

}

#endif

