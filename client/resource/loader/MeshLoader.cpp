#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <resource/loader/MeshLoader.h>
#include <renderer/VertexBuffer.h>
#include <renderer/IndexBuffer.h>
#include <engine/Geometry.h>

#include <shared/mesh.h>

MeshLoader::MeshLoader()
:	m_fp(0)
{

}

MeshLoader::~MeshLoader()
{
	if (m_fp)
		fclose(m_fp);
}

int MeshLoader::OpenResource(const char *resource)
{
	char path[4096];

	sprintf(path, "../resources/mesh/%s.mesh", resource);
	
	m_fp = fopen(path, "rb");
	if (!m_fp)
		return -1;

	fread(&m_header, sizeof(m_header), 1, m_fp);

	// verify it has a correct magic
	if (memcmp(&m_header.magic, MESH_HEADER_MAGIC, 4) != 0)
		return -1;

	// we can only deal with one version
	if (m_header.version != MESH_HEADER_CURRENT_VERSION)
		return -1;

	return 0;
}


Engine::Spatial *MeshLoader::ConstructSpatial()
{
	Engine::Geometry *geom = new Engine::Geometry();

	geom->m_Mesh = Mesh::CreateMesh((Mesh_Type)m_header.mesh_type);

	// load the index buffer
	IndexBuffer *ib = IndexBuffer::CreateIndexBuffer();

	unsigned int *indexes = new unsigned int[m_header.indexcount];
	fseek(m_fp, m_header.indexoffset, SEEK_SET);
	fread(indexes, sizeof(unsigned int), m_header.indexcount, m_fp);
	ib->LoadIndexes(indexes, m_header.indexcount);
	delete[] indexes;
	geom->m_Mesh->SetIndexBuffer(ib);

	// create and load the vertex buffer
	VertexBuffer *vb = VertexBuffer::CreateVertexBuffer();
	float *verts = new float[m_header.vertlen / sizeof(float)];
	fseek(m_fp, m_header.vertoffset, SEEK_SET);
	fread(verts, m_header.vertlen, 1, m_fp);
	vb->LoadVertexes(verts, (Vertex_Format)m_header.vert_format, m_header.vertcount);
	delete[] verts;
	geom->m_Mesh->SetVertexBuffer(vb);

	return geom;
}

