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
	unsigned int currInSurf = 0;
	unsigned int currOutSurf = 0;

	// start by building a non optimized list
	for (SurfaceListIteratorConst surface_i = mesh.m_Surfaces.begin(); surface_i != mesh.m_Surfaces.end(); surface_i++) {
		Surface *surface = *surface_i;

		// see if we need to split this surface into triangles
		if (surface->m_Indexes.size() < 3) {
			assert(0); // can't deal with this
		}

		// for each surface that has > 3 elements, build a triangle fan with a root of the first index
		// assumes the surface is convex
		for (unsigned int surfaceoffset = 0; surfaceoffset < surface->m_Indexes.size() - 2; surfaceoffset++) {
			UnifiedSurface *usurface = new UnifiedSurface;

			SurfaceIndexListIteratorConst index_i = surface->m_Indexes.begin();

			// push the root vert
			{
				SurfaceIndex rootindex = *index_i;

				UnifiedVertex uvert;
				uvert.m_Pos = (rootindex.posIndex >= 0) ? mesh.m_Verts[rootindex.posIndex] : Vertex::EmptyVertex;
				uvert.m_Normal = (rootindex.normIndex >= 0) ? mesh.m_NormalVerts[rootindex.normIndex] : Vertex::EmptyVertex;
				uvert.m_UV = (rootindex.uvIndex >= 0) ? mesh.m_UVVerts[rootindex.uvIndex] : Vertex::EmptyVertex;

				m_Verts.push_back(uvert);
				usurface->m_Indexes.push_back(currVert);
				currVert++;
				index_i++;
			}

			// push the other 2 verts
			index_i += surfaceoffset;
			for (int i = 0; i < 2; i++) {
				SurfaceIndex index = *index_i;

				UnifiedVertex uvert;
				uvert.m_Pos = (index.posIndex >= 0) ? mesh.m_Verts[index.posIndex] : Vertex::EmptyVertex;
				uvert.m_Normal = (index.normIndex >= 0) ? mesh.m_NormalVerts[index.normIndex] : Vertex::EmptyVertex;
				uvert.m_UV = (index.uvIndex >= 0) ? mesh.m_UVVerts[index.uvIndex] : Vertex::EmptyVertex;

				m_Verts.push_back(uvert);
				usurface->m_Indexes.push_back(currVert);
				currVert++;
				index_i++;
			}

			m_Surfaces.push_back(usurface);
			currOutSurf++;
		}
		currInSurf++;
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
