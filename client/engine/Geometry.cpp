#include <iostream>
#include <engine/Geometry.h>
#include <renderer/Renderer.h>

namespace Engine {

Geometry::Geometry()
:	m_Mesh(0)
{
}

Geometry::~Geometry()
{
}

void Geometry::Render(Renderer *r)
{
//	std::cout << "Geometry::Render\n";

	r->SetWorldMatrix(mWorldTransform);

	m_Mesh->Draw(r);
}

void Geometry::SetDefaultGeometry()
{
	m_Mesh = Mesh::CreateMesh(MESH_TYPE_TRIANGLE_MESH);
	m_Mesh->SetDefault();
}

}
