#ifndef __MATH_H
#define __MATH_H

#include <math.h>

namespace Math {

template<class T>
class Math {
public:
	static T sqrt(T root);

private:
	Math<T>() {}
};

/* some common math routines */
template <>
float Math<float>::sqrt(float root)
{
	return ::sqrtf(root);
}

template <>
double Math<double>::sqrt(double root)
{
	return ::sqrt(root);
}


}

#endif

