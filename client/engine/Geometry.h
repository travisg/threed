#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include <engine/Spatial.h>
#include <math/Vector3.h>
#include <renderer/Mesh.h>

namespace Engine {

class Geometry : public Spatial {
public:
	Geometry();
	virtual ~Geometry();

	virtual void Render(Renderer *r);

	// temporary hack
	void SetDefaultGeometry();

//protected:
	Mesh *m_Mesh;
};

}

#endif
