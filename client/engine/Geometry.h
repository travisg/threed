#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include <engine/Spatial.h>
#include <math/Vector3.h>
#include <resource/Resource.h>
#include <renderer/Mesh.h>
#include <renderer/Program.h>

namespace Engine {

class Geometry : public Spatial {
public:
	Geometry();
	virtual ~Geometry();

	static Spatial *BuildFromResource(Resource *r);

	virtual void Render(Renderer *r);

	Mesh *m_Mesh;
	Program *m_Program;
};

}

#endif
