#include <engine/Camera.h>
#include <renderer/Renderer.h>

namespace Engine {

	Camera::Camera()
		:	mPos(0,0,0),
		mUp(0,1,0),
		mZoom(1.0f)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Render(Renderer *r)
	{	
		// move the Camera
		mTransform.SetTranslation(-mPos);

		Math::Matrix4x4 rotx;
		Math::Matrix4x4 roty;
		Math::Matrix4x4 rotz;

		rotx.SetRotationX(mUp.getx());
		roty.SetRotationY(mUp.gety());
		rotz.SetRotationZ(mUp.getz());

		r->SetViewMatrix(mTransform * rotx * roty * rotz);
	}

	void Camera::SetPos(const Math::Vector3 &pos)
	{
		mPos = pos;
	}

	void Camera::Move(const Math::Vector3 &trans)
	{
		mPos += trans;
	}

	void Camera::Rotate(const Math::Vector3 &rot)
	{
		mUp += rot;
	}

	void Camera::PrintPosition()
	{
		std::cout << "Camera pos: " << mPos << " up " << mUp << std::endl;
	}

}

