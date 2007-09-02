#include <renderer/OpenGL/GLMesh.h>
#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLIndexBuffer.h>
#include <renderer/OpenGL/GLVertexBuffer.h>
#include <assert.h>

#include "glinc.h"

struct Vertex {
	FLOAT x, y, z;
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
#if 0
	switch (type) {
		case MESH_TYPE_TRIANGLE_LIST:
			m_D3DType = D3DPT_TRIANGLELIST;
			break;
		case MESH_TYPE_TRIANGLE_MESH:
			m_D3DType = D3DPT_TRIANGLESTRIP;
			break;
		case MESH_TYPE_TRIANGLE_FAN:
			m_D3DType = D3DPT_TRIANGLEFAN;
			break;
		default:
			assert(0);
	}

	ZeroMemory(&m_D3DMaterial, sizeof(D3DMATERIAL9));
	m_D3DMaterial.Diffuse.r = 1.0f;
	m_D3DMaterial.Diffuse.g = 1.0f;
	m_D3DMaterial.Diffuse.b = 1.0f;
	m_D3DMaterial.Ambient.r = 1.0f;
	m_D3DMaterial.Ambient.g = 1.0f;
	m_D3DMaterial.Ambient.b = 1.0f;
#endif
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

	glColor3f(1.0f, 0.5f, 1.0f);
	m_IB->Bind(r);
	m_VB->Bind(r);
	((GLIndexBuffer *)m_IB)->Draw(GL_TRIANGLES);
}
