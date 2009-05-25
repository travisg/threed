#ifndef __SPATIAL_H
#define __SPATIAL_H

#include <math/Vector3.h>
#include <math/Matrix4x4.h>
#include <list>

class Renderer;

namespace Engine {

class Spatial {
public:
	Spatial();
	virtual ~Spatial();

	virtual void UpdateTransform(bool force);
	virtual void Render(Renderer *r) = 0;

	void SetPos(const Math::Vector3f &pos);
	void SetRotation(const Math::Vector3f &rot);
	void SetScale(float scale);

	void Move(const Math::Vector3f &trans);
	void Rotate(const Math::Vector3f &rot);
	void Scale(float scale);

	Math::Vector3f GetLocalPos() const { return mLocalTranslate; }
	Math::Vector3f GetLocalRotation() const { return mLocalRotationAngles; }
	float GetLocalScale() const { return mLocalScale; }

	Math::Vector3f GetGlobalPos();

	Spatial *mParent;

	// debug
	void PrintPosition();

protected:
	// recalculate the world matrix based on the spatial transforms
	void UpdateWorldMatrix();

	bool				mDirty;
	float				mLocalScale;
	Math::Vector3f		mLocalTranslate;
	Math::Matrix4x4		mLocalRotation;

	Math::Vector3f		mLocalRotationAngles;

	float				mWorldScale;
	Math::Vector3f		mWorldTranslate;
	Math::Matrix4x4		mWorldRotation;

	// the world translation matrix
	Math::Matrix4x4		mWorldTransform;
};

// typedefs
typedef std::list<Spatial*> SpatialList;
typedef std::list<Spatial*>::iterator SpatialListIterator;

}

#endif
