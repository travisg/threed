#include <engine/Camera.h>
#include <renderer/Renderer.h>

namespace Engine {

	Camera::Camera()
		:	mPos(0,0,0),
		mZoom(1.0f)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Render(Renderer *r)
	{	
		Math::Matrix4x4 mTransform;

		// move the Camera
		mTransform.SetTranslation(-mPos);

		r->SetViewMatrix(mTransform);
	}

	void Camera::SetPos(const Math::Vector3 &pos)
	{
		mPos = pos;
	}

	void Camera::Move(const Math::Vector3 &trans)
	{
		mPos += trans;
	}

	void Camera::PrintPosition()
	{
		std::cout << mPos << std::endl;
	}

}

