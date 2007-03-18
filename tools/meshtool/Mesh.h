#ifndef __MESH_H
#define __MESH_H

#include "Vertex.h"
#include "Surface.h"
#include <string>

class Mesh {
public:
	Mesh();
	virtual ~Mesh();

	void AddVert(const Vertex &v);
	void AddNormalVert(const Vertex &v);
	void AddTangentVert(const Vertex &v);
	void AddUVVert(const Vertex &v);
	void AddSurface(Surface *s);

	void SetName(const std::string &name);

private:
	std::string m_Name;

	VertexList m_Verts;
	VertexList m_NormalVerts;
	VertexList m_TangentVerts;
	VertexList m_UVVerts;

	SurfaceList m_Surfaces;
};

typedef std::vector<Mesh*> MeshList;

#endif
