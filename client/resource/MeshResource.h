#ifndef __MESH_RESOURCE_H
#define __MESH_RESOURCE_H

#include <resource/Resource.h>
#include <shared/mesh.h>

class MeshResource : public Resource {
public:
	MeshResource(const char *name);
protected:
	~MeshResource();

public:
	enum Mesh_Type getMeshType() const { return mMeshType; }
	enum Vertex_Format getVertexFormat() const { return mVertexFormat; }

	int getIndexCount() const { return mIndexCount; }
	int getVertexCount() const { return mVertexCount; }

	const unsigned int *getIndexes() const { return mIndexes; }
	const float *getVertexes() const { return mVertexes; }

private:
	enum Mesh_Type mMeshType;
	enum Vertex_Format mVertexFormat;

	int mIndexCount;
	int mVertexCount;

	unsigned int *mIndexes;
	float *mVertexes;

	// constructor classes, will punch data directly in
	friend class MeshLoader;
	friend class AC3DLoader;
};

#endif
