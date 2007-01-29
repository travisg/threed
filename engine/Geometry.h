#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include <engine/Spatial.h>
#include <math/Vector3.h>

namespace Engine {

class Geometry : public Spatial {
public:
	Geometry();
	virtual ~Geometry();

	virtual void Render(Renderer *r);

	void SetVertices(const float *vertices, unsigned int count);

protected:
	Math::Vector3 *mVertices;
	unsigned int mNumVertices;
};

}

#endif
