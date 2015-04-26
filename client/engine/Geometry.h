#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include <engine/Spatial.h>

class Resource;

class Mesh;
class Program;
class Texture;

namespace Engine {

class Geometry : public Spatial {
public:
	Geometry();
	virtual ~Geometry();

	static Spatial *BuildFromResource(Resource *r);

	virtual void Render(Renderer *r);

	Mesh *m_Mesh;
	Program *m_Program;
	Texture *m_Texture;
};

}

#endif
