#include "Surface.h"

Surface::Surface()
{
}

Surface::~Surface()
{
}

void Surface::AddIndex(int posIndex, int normIndex, int uvIndex)
{
	SurfaceIndex i;

	i.posIndex = posIndex;
	i.normIndex = normIndex;
	i.uvIndex = uvIndex;

	m_Indexes.push_back(i);
}
