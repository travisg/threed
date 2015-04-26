#include "Geometry.h"

Geometry::Geometry()
{
}

Geometry::~Geometry()
{
}

void Geometry::AddMesh(Mesh *m)
{
	m_Meshes.push_back(m);
}

void Geometry::AddVert(const Vertex &v)
{
	m_Verts.push_back(v);
}

void Geometry::AddNormalVert(const Vertex &v)
{
	m_NormalVerts.push_back(v);
}

void Geometry::AddTangentVert(const Vertex &v)
{
	m_TangentVerts.push_back(v);
}

void Geometry::AddUVVert(const Vertex &v)
{
	m_UVVerts.push_back(v);
}

Mesh *Geometry::CreateMesh()
{
	return new Mesh(m_Verts, m_NormalVerts, m_TangentVerts, m_UVVerts);
}
