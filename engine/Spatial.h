#ifndef __SPATIAL_H
#define __SPATIAL_H

#include <math/Vector3.h>
#include <math/Matrix4x4.h>

class Renderer;

namespace Engine {

class Spatial {
public:
	Spatial();
	virtual ~Spatial();

	virtual void Render(Renderer *r) = 0;

	Spatial *mParent;

	float				mLocalScale;
	Math::Vector3		mLocalXYZ;
	Math::Matrix4x4		mLocalRotation;

	float				mWorldScale;
	Math::Vector3		mWorldXYZ;
	Math::Matrix4x4		mWorldRotation;
};

}

#endif
