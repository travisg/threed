#ifndef __MESH_RESOURCE_H
#define __MESH_RESOURCE_H

#include <resource/Resource.h>
#include <shared/mesh.h>

class ResourceManager;

class MeshResource : public Resource {
public:
    enum Mesh_Type getMeshType() const { return mMeshType; }
    enum Vertex_Format getVertexFormat() const { return mVertexFormat; }

    int getIndexCount() const { return mIndexCount; }
    int getVertexCount() const { return mVertexCount; }

    const unsigned int *getIndexes() const { return mIndexes; }
    const float *getVertexes() const { return mVertexes; }

private:
    MeshResource(ResourceManager &m, const char *name);
    ~MeshResource();

    virtual int LoadFromStorage();

    enum Mesh_Type mMeshType;
    enum Vertex_Format mVertexFormat;

    int mIndexCount;
    int mVertexCount;

    unsigned int *mIndexes;
    float *mVertexes;

    // only Resource can construct us
    friend class Resource;
};

#endif
