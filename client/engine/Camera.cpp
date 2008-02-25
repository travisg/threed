#include <engine/Camera.h>
#include <renderer/Renderer.h>

namespace Engine {

	Camera::Camera()
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Render(Renderer *r)
	{
		r->SetViewMatrix(mWorldTransform);
	}

}

