#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include "Mesh.h"

class Geometry {
public:
	Geometry();
	~Geometry();

	void AddMesh(Mesh *m);

private:
	MeshList m_Meshes;
};

#endif
