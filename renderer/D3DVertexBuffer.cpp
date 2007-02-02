#include <renderer/D3DRenderer.h>
#include <renderer/D3DVertexBuffer.h>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dtypes.h>

VertexBuffer *VertexBuffer::CreateVertexBuffer()
{
	return new D3DVertexBuffer(VB_TYPE_TRAINGLES);
}

D3DVertexBuffer::D3DVertexBuffer(VB_Type type)
:	VertexBuffer(type),
	m_buffer(0)
{
	/* XXX move this somewhere else */
	struct Vertex {
		FLOAT x, y, z;
		unsigned int diffuse;
		unsigned int pad[4];
   };
   static struct Vertex aTriangle[] = {
                             { 0.0f, 1.0f, 0.0f,D3DCOLOR_XRGB(0,0xff,0)}, // top
                             { 1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(0,0,0xff)}, // right
							 {-1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(0xff,0,0)}, // left
                             { 0.0f,-1.0f, 0.0f,D3DCOLOR_XRGB(0,0xff,0)}, // bottom

//                             {-0.0f,-2.0f,10.0f,D3DCOLOR_XRGB(0xff,0,0xff)},
//                             {1.0f,-3.0f,10.0f,D3DCOLOR_XRGB(0xff,0xff,0xff)},
   };
	void *pData;

//	aTriangle[2].y += 0.1f;

   D3DRenderer::GetD3DRenderer()->GetD3DDevice()->CreateVertexBuffer(sizeof(aTriangle),D3DUSAGE_WRITEONLY,
										(D3DFVF_XYZ|D3DFVF_DIFFUSE),
										D3DPOOL_MANAGED, &m_buffer, NULL);

	m_buffer->Lock(0,sizeof(pData),(void**)&pData,0);
	memcpy(pData,aTriangle,sizeof(aTriangle));
	m_buffer->Unlock();
}

D3DVertexBuffer::~D3DVertexBuffer()
{
}

void D3DVertexBuffer::Draw(Renderer *r)
{
	D3DRenderer *dr = (D3DRenderer *)r;

	dr->GetD3DDevice()->SetStreamSource(0, m_buffer, 0, sizeof(D3DVERTEX));
	dr->GetD3DDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

