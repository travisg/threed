#include <engine/Camera.h>
#include <renderer/Renderer.h>

namespace Engine {

	Camera::Camera()
		:	mPos(0,0,0),
		mUp(0,1,0),
		mZoom(1.0f),
		dirty(true)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Update()
	{
		if (dirty) {
			// move the Camera

			mTransform.SetTranslation(-mPos);

			Math::Matrix4x4 rotx;
			Math::Matrix4x4 roty;
			Math::Matrix4x4 rotz;

			rotx.SetRotationX(mUp.getx());
			roty.SetRotationY(mUp.gety());
			rotz.SetRotationZ(mUp.getz());

			mTransform = mTransform * rotx * roty * rotz;
			dirty = false;
		}
	}

	void Camera::Render(Renderer *r)
	{	
		r->SetViewMatrix(mTransform);
	}

	void Camera::SetPos(const Math::Vector3 &pos)
	{
		mPos = pos;
		dirty = true;
	}

	void Camera::Move(const Math::Vector3 &trans)
	{
		mPos += trans;
		dirty = true;
	}

	void Camera::Rotate(const Math::Vector3 &rot)
	{
		mUp += rot;
		dirty = true;
	}

	void Camera::LookAt(Spatial &obj)
	{
//		std::cout << __FUNCTION__ << " object at " << obj.GetGlobalPos() << " cam " << mPos << std::endl;

		// essentially gluLookAt
		Math::Vector3 f = obj.GetGlobalPos() - mPos;
		f.Normalize();

		Math::Vector3 up = mUp;
		up.Normalize();

		Math::Vector3 s = Cross(f, up);
		Math::Vector3 u = Cross(s, f);

		Math::Matrix4x4 M;
		M.SetIdentity();
		M.SetCol(0, s);
		M.SetCol(1, u);
		M.SetCol(2, -f);

		Math::Matrix4x4 trans;
		trans.SetTranslation(-mPos);
		mTransform = M * trans;

		// we're setting the transformation matrix directly, don't recalculate in Update()
		dirty = false;
	}

	void Camera::PrintPosition()
	{
		std::cout << "Camera pos: " << mPos << " up " << mUp << std::endl;
	}

}

