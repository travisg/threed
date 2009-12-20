#include <resource/MeshResource.h>
#include <cstdio>
#include <cstring>

MeshResource::MeshResource(ResourceManager &m, const char *name)
:	Resource(m, name, RT_MESH),
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

int MeshResource::LoadFromStorage()
{
	// open and validate the mesh is present
	char path[4096];

	sprintf(path, "resources/mesh/%s.mesh", mName.c_str());

	FILE *fp = fopen(path, "rb");
	if (!fp)
		return -1;

	mesh_header header;
	fread(&header, sizeof(header), 1, fp);

	// verify it has a correct magic
	if (memcmp(&header.magic, MESH_HEADER_MAGIC, 4) != 0)
		return -1;

	// we can only deal with one version
	if (header.version != MESH_HEADER_CURRENT_VERSION)
		return -1;

	mMeshType = (Mesh_Type)header.mesh_type;

	// load in the indexes
	mIndexCount = header.indexcount;
	mIndexes = new unsigned int[mIndexCount];
	fseek(fp, header.indexoffset, SEEK_SET);
	fread(mIndexes, sizeof(unsigned int), header.indexcount, fp);

	// load in the vertexes
	mVertexFormat = (Vertex_Format)header.vert_format;
	mVertexCount = header.vertcount;
	mVertexes = new float[header.vertlen / sizeof(float)];
	fseek(fp, header.vertoffset, SEEK_SET);
	fread(mVertexes, header.vertlen, 1, fp);

	fclose(fp);

	return 0;
}
