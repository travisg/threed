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

	void SetPos(const Math::Vector3 &pos);
	void SetRotation(const Math::Vector3 &rot);
	void SetScale(float scale);

	void Move(const Math::Vector3 &trans);
	void Rotate(const Math::Vector3 &rot);
	void Scale(float scale);

	void UpdateWorldMatrix();

	Spatial *mParent;

protected:
	float				mLocalScale;
	Math::Vector3		mLocalTranslate;
	Math::Matrix4x4		mLocalRotation;

	Math::Vector3		mLocalRotationAngles;

	float				mWorldScale;
	Math::Vector3		mWorldTranslate;
	Math::Matrix4x4		mWorldRotation;

	// the world translation matrix
	Math::Matrix4x4		mWorldTransform;
};

}

#endif
