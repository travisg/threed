#include <renderer/OpenGL/GLMesh.h>
#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLIndexBuffer.h>
#include <renderer/OpenGL/GLVertexBuffer.h>
#include <assert.h>

#include "glinc.h"

struct Vertex {
	float x, y, z;
};
static struct Vertex aTriangle[] = {
                         { 0.0f, 1.0f, 0.0f }, // top
                         { 1.0f, 0.0f, 0.0f }, // right
						 {-1.0f, 0.0f, 0.0f }, // left
                         { 0.0f,-1.0f, 0.0f }, // bottom
};
static unsigned int indexes[] = {
	0, 1, 2, 3, 
};

Mesh *Mesh::CreateMesh(Mesh_Type type)
{
	Mesh *m = new GLMesh(type);

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

void GLMesh::SetDefault()
{
	m_VB = VertexBuffer::CreateVertexBuffer();
	m_IB = IndexBuffer::CreateIndexBuffer();

	m_VB->LoadSimpleVertexes((float *)aTriangle, 4);
	m_IB->LoadIndexes(indexes, 6);
}

void GLMesh::Draw(Renderer *r)
{
	GLRenderer *dr = (GLRenderer *)r;

	assert(m_IB);
	assert(m_VB);

	m_IB->Bind(r);
	m_VB->Bind(r);
	glDrawElements(m_Type, m_IB->Count(), GL_UNSIGNED_INT, 0);
}
