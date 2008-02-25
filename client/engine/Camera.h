#ifndef __CAMERA_H
#define __CAMERA_H

#include <math/Vector3.h>
#include <math/Matrix4x4.h>
#include <engine/Spatial.h>

namespace Engine {

class Camera : public Spatial {
public:
	Camera();
	virtual ~Camera();

	virtual void Render(Renderer *r);

protected:



};

}

#endif
