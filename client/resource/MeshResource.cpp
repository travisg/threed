#include <resource/MeshResource.h>
#include <resource/loader/Loader.h>

MeshResource::MeshResource(const char *name)
:	Resource(RT_MESH, name),
	mMeshType(MESH_TYPE_NULL),
	mVertexFormat(VERT_FORMAT_NULL),
	mIndexCount(0),
	mVertexCount(0),
	mIndexes(0),
	mVertexes(0)	
{
}

MeshResource::~MeshResource()
{
	if (mIndexes)
		delete[] mIndexes;
	if (mVertexes)
		delete[] mVertexes;
}

