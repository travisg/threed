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
