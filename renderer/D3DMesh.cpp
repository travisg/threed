#include <renderer/D3DMesh.h>
#include <renderer/D3DRenderer.h>
#include <renderer/D3DIndexBuffer.h>
#include <renderer/D3DVertexBuffer.h>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dtypes.h>
#include <assert.h>

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

Mesh *Mesh::CreateMesh(MESH_Type type)
{
	Mesh *m = new D3DMesh(type);

	return m;
}

D3DMesh::D3DMesh(MESH_Type type)
:	Mesh(type)
{
	switch (type) {
		case MESH_TYPE_TRIANGLES:
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
}

D3DMesh::~D3DMesh()
{
	delete m_VB;
	delete m_IB;
}

void D3DMesh::SetDefault()
{
	m_VB = VertexBuffer::CreateVertexBuffer();
	m_IB = IndexBuffer::CreateIndexBuffer();

	m_VB->LoadSimpleVertexes((float *)aTriangle, 4);
	m_IB->LoadIndexes(indexes, 6);
}

void D3DMesh::Draw(Renderer *r)
{
	D3DRenderer *dr = (D3DRenderer *)r;

	assert(m_IB);
	assert(m_VB);

	m_IB->Bind(r);
	m_VB->Bind(r);
	dr->GetD3DDevice()->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_VB->Count(), 0, m_IB->Count() / 3);
}
