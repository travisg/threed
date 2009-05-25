#ifndef __MATH_MATH_H
#define __MATH_MATH_H

#include <math.h>

namespace Math {

template<class T>
class Math {
public:
	static T sqrt(T root);
	static T sin(T val);
	static T cos(T val);
	static T tan(T val);

private:
	Math<T>();
};

#define F_PI 3.14159f

inline float DegreeToRadians(float deg)
{
	return (deg * F_PI) / 180.0f;
}

inline double DegreeToRadians(double deg)
{
	return (deg * F_PI) / 180.0f;
}

/* specialization for float,double */

/* float */
template <>
inline float Math<float>::sqrt(float root)
{
	return ::sqrtf(root);
}

template <>
inline float Math<float>::sin(float root)
{
	return ::sinf(root);
}

template <>
inline float Math<float>::cos(float root)
{
	return ::cosf(root);
}

template <>
inline float Math<float>::tan(float root)
{
	return ::tanf(root);
}

/* double */
template <>
inline double Math<double>::sqrt(double root)
{
	return ::sqrt(root);
}

template <>
inline double Math<double>::sin(double root)
{
	return ::sin(root);
}

template <>
inline double Math<double>::cos(double root)
{
	return ::cos(root);
}

template <>
inline double Math<double>::tan(double root)
{
	return ::tan(root);
}


}

#endif

