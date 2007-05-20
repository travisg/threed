#ifndef __MATH_H
#define __MATH_H

#include <shared/defines.h>
#include <math/Vector4.h>
#include <math/Vector3.h>
#include <math/Matrix4x4.h>

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

}

#endif

