#ifndef __UNIFIED_VERTEX_H
#define __UNIFIED_VERTEX_H

#include <stdio.h>

#include "Vertex.h"
#include <shared/mesh.h>
#include <vector>

class UnifiedVertex {
public:
	Vertex m_Pos;
	Vertex m_Normal;
	Vertex m_UV;

	void Write(FILE *outfp, Vertex_Format f) const;
};

typedef std::vector<UnifiedVertex> UnifiedVertexList;
typedef std::vector<UnifiedVertex>::iterator UnifiedVertexListIterator;
typedef std::vector<UnifiedVertex>::const_iterator UnifiedVertexListIteratorConst;

#endif
