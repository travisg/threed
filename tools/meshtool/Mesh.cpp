#include "Mesh.h"


Mesh::Mesh()
:	m_Name("default")
{
}

Mesh::~Mesh()
{
}

void Mesh::SetName(const std::string &name)
{
	m_Name = name;
}

void Mesh::AddVert(const Vertex &v)
{
	m_Verts.push_back(v);
}

void Mesh::AddNormalVert(const Vertex &v)
{
	m_NormalVerts.push_back(v);
}

void Mesh::AddTangentVert(const Vertex &v)
{
	m_TangentVerts.push_back(v);
}

void Mesh::AddUVVert(const Vertex &v)
{
	m_UVVerts.push_back(v);
}

void Mesh::AddSurface(Surface *s)
{
	m_Surfaces.push_back(s);
}


