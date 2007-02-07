#include <renderer/Mesh.h>

Mesh::Mesh(MESH_Type type)
:	m_IB(0),
	m_VB(0),
	m_Type(type)
{
}

Mesh::~Mesh()
{
}

