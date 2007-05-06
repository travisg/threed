#ifndef __UNIFIED_MESH_H
#define __UNIFIED_MESH_H

#include <stdio.h>

#include "UnifiedVertex.h"
#include "UnifiedSurface.h"
#include <shared/mesh.h>

class Mesh;

class UnifiedMesh {
public:
	UnifiedMesh();
	~UnifiedMesh();

	// build a unified mesh from a non-unified one (separate vertexes and indexes)
	void CreateFromMesh(const Mesh &);
	void Optimize();

	size_t VertCount() const { return m_Verts.size(); }
	size_t IndexCount() const;

	void WriteVerts(FILE *outfp, Vertex_Format) const;
	void WriteIndexes(FILE *outfp, unsigned int indexWidth) const;

protected:
	UnifiedVertexList m_Verts;
	UnifiedSurfaceList m_Surfaces;
};

#endif
