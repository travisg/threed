#ifndef __MATH_H
#define __MATH_H

#include <math/Vector4.h>
#include <math/Vector3.h>
#include <math/Matrix4x4.h>

namespace Math {

template<class T>
class Math {
public:
	static T sqrt(T root);

private:
	Math<T>() {}
};

}

#endif

