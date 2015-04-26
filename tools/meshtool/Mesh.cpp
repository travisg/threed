#include "Mesh.h"


Mesh::Mesh(const VertexList &posVerts, const VertexList &normalVerts, const VertexList &tangentVerts, const VertexList &uvVerts)
:	m_Name("default"),
	m_Verts(posVerts),
	m_NormalVerts(normalVerts),
	m_TangentVerts(tangentVerts),
	m_UVVerts(uvVerts)
{
}

Mesh::~Mesh()
{
	for (SurfaceListIterator surface_i = m_Surfaces.begin(); surface_i != m_Surfaces.end(); surface_i++) {
		delete *surface_i;
	}
}

void Mesh::SetName(const std::string &name)
{
	m_Name = name;
}

void Mesh::AddSurface(Surface *s)
{
	m_Surfaces.push_back(s);
}


