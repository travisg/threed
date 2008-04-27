#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <resource/loader/MeshLoader.h>
#include <resource/MeshResource.h>
#include <renderer/VertexBuffer.h>
#include <renderer/IndexBuffer.h>
#include <engine/Geometry.h>
#include <engine/SceneNode.h>

#include <shared/mesh.h>

#include <tinyxml/tinyxml.h>

MeshLoader::MeshLoader(ResourceManager &m)
:	Loader(m)
{

}

MeshLoader::~MeshLoader()
{
}

Resource *MeshLoader::LoadResource(const char *resource)
{
	// open and validate the mesh is present
	char path[4096];

	sprintf(path, "resources/mesh/%s.mesh", resource);

	FILE *fp = fopen(path, "rb");
	if (!fp)
		return NULL;

	mesh_header header;
	fread(&header, sizeof(header), 1, fp);

	// verify it has a correct magic
	if (memcmp(&header.magic, MESH_HEADER_MAGIC, 4) != 0)
		return NULL;

	// we can only deal with one version
	if (header.version != MESH_HEADER_CURRENT_VERSION)
		return NULL;

	// do the construct here
	MeshResource *r = new MeshResource(resource);

	r->mMeshType = (Mesh_Type)header.mesh_type;

	// load in the indexes
	r->mIndexCount = header.indexcount;
	r->mIndexes = new unsigned int[r->mIndexCount];
	fseek(fp, header.indexoffset, SEEK_SET);
	fread(r->mIndexes, sizeof(unsigned int), header.indexcount, fp);

	// load in the vertexes
	r->mVertexFormat = (Vertex_Format)header.vert_format;
	r->mVertexCount = header.vertcount;
	r->mVertexes = new float[header.vertlen / sizeof(float)];
	fseek(fp, header.vertoffset, SEEK_SET);
	fread(r->mVertexes, header.vertlen, 1, fp);

	fclose(fp);

	return r;
}

