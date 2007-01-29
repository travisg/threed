#include <iostream>
#include <engine/Geometry.h>

namespace Engine {

Geometry::Geometry()
:	mVertices(0),
	mNumVertices(0)
{
}

Geometry::~Geometry()
{
	delete[] mVertices;
}

void Geometry::SetVertices(const float *vertices, unsigned int count)
{
	if (mVertices)
		delete[] mVertices;

	mNumVertices = count;
	mVertices = new Math::Vector3[mNumVertices];

	for (unsigned int i = 0; i < count; i++)
		mVertices[i] = Math::Vector3(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
}

void Geometry::Render(Renderer *r)
{
	std::cout << "Geometry::Render\n";


}

}
