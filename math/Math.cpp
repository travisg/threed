#include <math.h>
#include <math/Math.h>

namespace Math {

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
