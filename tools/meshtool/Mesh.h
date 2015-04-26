#ifndef __MESH_H
#define __MESH_H

#include "Vertex.h"
#include "Surface.h"
#include <string>

class Mesh {
public:
    Mesh(const VertexList &posVerts, const VertexList &normalVerts, const VertexList &tangentVerts, const VertexList &uvVerts);
    virtual ~Mesh();

    void AddSurface(Surface *s);

    void SetName(const std::string &name);
    std::string GetName() { return m_Name; }

    void SetVertexLists();

private:
    std::string m_Name;

    // vertex list, probably shared between multiple meshes
    const VertexList &m_Verts;
    const VertexList &m_NormalVerts;
    const VertexList &m_TangentVerts;
    const VertexList &m_UVVerts;

    SurfaceList m_Surfaces;

    friend class UnifiedMesh;
};

typedef std::vector<Mesh*> MeshList;
typedef std::vector<Mesh*>::iterator MeshListIterator;
typedef std::vector<Mesh*>::const_iterator MeshListIteratorConst;

#endif
