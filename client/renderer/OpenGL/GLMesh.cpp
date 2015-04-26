#include <resource/MeshResource.h>
#include <renderer/OpenGL/GLMesh.h>
#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLIndexBuffer.h>
#include <renderer/OpenGL/GLVertexBuffer.h>
#include <assert.h>

#include "glinc.h"

Mesh *Mesh::Create(Mesh_Type type)
{
	Mesh *m = new GLMesh(type);

	return m;
}

Mesh *Mesh::CreateFromResource(Resource *_r)
{
	MeshResource *r = dynamic_cast<MeshResource *>(_r);
	assert(r);

	Mesh *m = new GLMesh(r->getMeshType());
	m->SetResource(r);

	IndexBuffer *ib = IndexBuffer::CreateIndexBuffer();
	ib->LoadIndexes(r->getIndexes(), r->getIndexCount());
	m->SetIndexBuffer(ib);

	VertexBuffer *vb = VertexBuffer::CreateVertexBuffer();
	vb->LoadVertexes(r->getVertexes(), r->getVertexFormat(), r->getVertexCount());
	m->SetVertexBuffer(vb);

	return m;
}

GLMesh::GLMesh(Mesh_Type type)
:	Mesh(type)
{
	switch (type) {
		case MESH_TYPE_TRIANGLE_LIST:
			m_Type = GL_TRIANGLES;
			break;
		case MESH_TYPE_TRIANGLE_MESH:
			m_Type = GL_TRIANGLE_STRIP;
			break;
		case MESH_TYPE_TRIANGLE_FAN:
			m_Type = GL_TRIANGLE_FAN;
			break;
		default:
			assert(0);
	}
}

GLMesh::~GLMesh()
{
	delete m_VB;
	delete m_IB;
}

void GLMesh::Draw(Renderer *r)
{
	assert(m_IB);
	assert(m_VB);

	m_IB->Bind(r);
	m_VB->Bind(r);
	glDrawElements(m_Type, m_IB->Count(), GL_UNSIGNED_INT, 0);
}
