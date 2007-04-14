#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include "Mesh.h"

class Geometry {
public:
	Geometry();
	~Geometry();

	void AddMesh(Mesh *m);

	MeshListIteratorConst ListIterator() { return m_Meshes.begin(); }
	MeshListIteratorConst ListEnd() { return m_Meshes.end(); }

private:
	MeshList m_Meshes;
};

#endif
