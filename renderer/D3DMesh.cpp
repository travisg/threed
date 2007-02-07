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
	0, 1, 2, 3
};

Mesh *Mesh::CreateMesh()
{
	Mesh *m = new D3DMesh(MESH_TYPE_TRAINGLE_MESH);
	m->m_VB = VertexBuffer::CreateVertexBuffer();
	m->m_IB = IndexBuffer::CreateIndexBuffer();

	m->m_VB->LoadSimpleVertexes((float *)aTriangle, 4);
	m->m_IB->LoadIndexes(indexes, 4);

	return m;
}

D3DMesh::D3DMesh(MESH_Type type)
:	Mesh(type)
{
	switch (type) {
		case MESH_TYPE_TRAINGLES:
			m_D3DType = D3DPT_TRIANGLELIST;
			break;
		case MESH_TYPE_TRAINGLE_MESH:
			m_D3DType = D3DPT_TRIANGLESTRIP;
			break;
		case MESH_TYPE_TRAINGLE_FAN:
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

void D3DMesh::Draw(Renderer *r)
{
	D3DIndexBuffer *ib = (D3DIndexBuffer *)m_IB;
	D3DVertexBuffer *vb = (D3DVertexBuffer *)m_VB;
	D3DRenderer *dr = (D3DRenderer *)r;

	assert(ib);
	assert(vb);

	ib->Bind(r);
	vb->Bind(r);
	dr->GetD3DDevice()->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, m_VB->Count(), 0, m_IB->Count() - 2);
}
