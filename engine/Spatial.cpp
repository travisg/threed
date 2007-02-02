#include <engine/Spatial.h>

namespace Engine {

Spatial::Spatial()
:	mParent(0)
{
	SetPos(Math::Vector3(0, 0, 0));
	SetRotation(Math::Vector3(0, 0, 0));
	SetScale(1.0f);
}

Spatial::~Spatial()
{
}

void Spatial::SetPos(const Math::Vector3 &pos)
{
	mLocalTranslate = pos;
}

void Spatial::SetRotation(const Math::Vector3 &rot)
{
	// XXX make faster
	Math::Matrix4x4 rotx;
	Math::Matrix4x4 roty;
	Math::Matrix4x4 rotz;

	rotx.SetRotationX(rot.x);
	roty.SetRotationY(rot.y);
	rotz.SetRotationZ(rot.z);

	mLocalRotationAngles = rot;
	mLocalRotation = rotx * roty * rotz;
}

void Spatial::SetScale(float scale)
{
	mLocalScale = scale;
}

void Spatial::Move(const Math::Vector3 &trans)
{
	mLocalTranslate += trans;
}

void Spatial::Rotate(const Math::Vector3 &rot)
{
	SetRotation(mLocalRotationAngles + rot);
}

void Spatial::Scale(float scale)
{
	mLocalScale *= scale;
}

void Spatial::UpdateWorldMatrix()
{
	// calculate the local transformation matrix
	Math::Matrix4x4 localTransform;

	// this is super lame
	Math::Matrix4x4 localTranslate;
	Math::Matrix4x4 localScaling;
	localTranslate.SetTranslation(mLocalTranslate);
	localScaling.SetScaling(Math::Vector3(mLocalScale, mLocalScale, mLocalScale));

	localTransform = localTranslate * mLocalRotation * localScaling;

	if (mParent) {
		mWorldScale = mParent->mWorldScale * mLocalScale;
		mWorldTranslate = mParent->mWorldTranslate + mParent->mWorldScale * mParent->mWorldRotation.Transform(mLocalTranslate);
		mWorldRotation = mParent->mWorldRotation * mLocalRotation;
		mWorldTransform = mParent->mWorldTransform * localTransform; // the full transformation
	} else {
		// we're the top of the world
		mWorldScale = mLocalScale;
		mWorldTranslate = mLocalTranslate;
		mWorldRotation = mLocalRotation;
		mWorldTransform = localTransform;
	}

//	std::cout << "UpdateWorldMatrix: mWorldTransform \n" << mWorldTransform << "\n";
}

}

