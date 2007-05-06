#include <assert.h>
#include "UnifiedMesh.h"
#include "Mesh.h"

UnifiedMesh::UnifiedMesh()
{

}

UnifiedMesh::~UnifiedMesh()
{
	for (UnifiedSurfaceListIterator surface_i = m_Surfaces.begin(); surface_i != m_Surfaces.end(); surface_i++) {
		delete *surface_i;
	}
}

	
void UnifiedMesh::CreateFromMesh(const Mesh &mesh)
{
	unsigned int currVert = 0;
	unsigned int currSurf = 0;

	// start by building a non optimized list
	for (SurfaceListIteratorConst surface_i = mesh.m_Surfaces.begin(); surface_i != mesh.m_Surfaces.end(); surface_i++) {
		Surface *surface = *surface_i;

		UnifiedSurface *usurface = new UnifiedSurface;

		for (SurfaceIndexListIteratorConst index_i = surface->m_Indexes.begin(); index_i != surface->m_Indexes.end(); index_i++) {
			SurfaceIndex index = *index_i;

			UnifiedVertex uvert;
			uvert.m_Pos = mesh.m_Verts[index.posIndex];
			uvert.m_Normal = mesh.m_NormalVerts[index.normIndex];
			uvert.m_UV = mesh.m_UVVerts[index.uvIndex];

			m_Verts.push_back(uvert);
			usurface->m_Indexes.push_back(currVert);
			currVert++;
		}

		m_Surfaces.push_back(usurface);
		currSurf++;
	}
}

void UnifiedMesh::Optimize()
{
	// do something here
}

size_t UnifiedMesh::IndexCount() const
{
	size_t count = 0;

	for (UnifiedSurfaceListIteratorConst surface_i = m_Surfaces.begin(); surface_i != m_Surfaces.end(); surface_i++) {
		count += (*surface_i)->m_Indexes.size();
	}

	return count;
}


void UnifiedMesh::WriteVerts(FILE *outfp, Vertex_Format f) const
{
	for (UnifiedVertexListIteratorConst vert_i = m_Verts.begin(); vert_i != m_Verts.end(); vert_i++) {
		(*vert_i).Write(outfp, f);
	}
}

void UnifiedMesh::WriteIndexes(FILE *outfp, unsigned int indexWidth) const
{
	assert(indexWidth == 4 || indexWidth == 2);

	for (UnifiedSurfaceListIteratorConst surface_i = m_Surfaces.begin(); surface_i != m_Surfaces.end(); surface_i++) {
		for (std::vector<int>::const_iterator i = (*surface_i)->m_Indexes.begin(); i != (*surface_i)->m_Indexes.end(); i++) {
			if (indexWidth == 4) {
				unsigned int index = *i;
				fwrite(&index, sizeof(index), 1, outfp);
			} else if (indexWidth == 2) {
				unsigned short index = *i;
				fwrite(&index, sizeof(index), 1, outfp);
			}
		}
	}
}
