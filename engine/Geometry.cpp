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

void Geometry::SetVertices(const float *vertices, unsigned int count)
{
#if 0
	if (mVertices)
		delete[] mVertices;

	mNumVertices = count;
	mVertices = new Math::Vector3[mNumVertices];

	for (unsigned int i = 0; i < count; i++)
		mVertices[i] = Math::Vector3(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
#endif
}

void Geometry::Render(Renderer *r)
{
//	std::cout << "Geometry::Render\n";

	Move(Math::Vector3(0, 0, 0.001f));
	Rotate(Math::Vector3(0.01f, 0.01f, 0.02f));
	UpdateWorldMatrix();

	r->SetWorldMatrix(mWorldTransform);

	m_Mesh->Draw(r);
}

void Geometry::SetDefaultGeometry()
{
	m_Mesh = Mesh::CreateMesh(Mesh::MESH_TYPE_TRIANGLE_MESH);
	m_Mesh->SetDefault();
}

}
