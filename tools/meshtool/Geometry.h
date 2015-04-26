#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include "Mesh.h"

class Geometry {
public:
	Geometry();
	~Geometry();

	void AddVert(const Vertex &v);
	void AddNormalVert(const Vertex &v);
	void AddTangentVert(const Vertex &v);
	void AddUVVert(const Vertex &v);
	void AddMesh(Mesh *m);

	Mesh *CreateMesh();

	MeshListIteratorConst ListIterator() { return m_Meshes.begin(); }
	MeshListIteratorConst ListEnd() { return m_Meshes.end(); }

private:
	MeshList m_Meshes;

	// shared verts
	VertexList m_Verts;
	VertexList m_NormalVerts;
	VertexList m_TangentVerts;
	VertexList m_UVVerts;
};

#endif
