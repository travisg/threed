#include <renderer/D3DRenderer.h>
#include <renderer/D3DVertexBuffer.h>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dtypes.h>
#include <assert.h>


VertexBuffer *VertexBuffer::CreateVertexBuffer()
{
	return new D3DVertexBuffer();
}

D3DVertexBuffer::D3DVertexBuffer()
:	VertexBuffer(),
	m_buffer(0)
{
}

// simple xyz vertexes
int D3DVertexBuffer::LoadSimpleVertexes(const float *vertexes, unsigned int count)
{
	UINT FVF = (D3DFVF_XYZ|D3DFVF_DIFFUSE);

	assert(!m_buffer);

	D3DRenderer::GetD3DRenderer()->GetD3DDevice()->CreateVertexBuffer(count * sizeof(float) * 3,
										D3DUSAGE_WRITEONLY,
										FVF,
										D3DPOOL_MANAGED, &m_buffer, NULL);

	FLOAT *pData;
	m_buffer->Lock(0, sizeof(pData), (void**)&pData, 0);
	for (unsigned i = 0; i < count; i++) {
		pData[i*4] = vertexes[i*3];
		pData[i*4+1] = vertexes[i*3+1];
		pData[i*4+2] = vertexes[i*3+2];
		*((unsigned int *)&pData[i*4+3]) = D3DCOLOR_XRGB(rand() & 0xff, rand() & 0xff, rand() & 0xff);
	}
	m_buffer->Unlock();
	
	m_vertexStride = 16;
	m_FVF = FVF;
	m_vertexCount = count;

	return 0;
}

D3DVertexBuffer::~D3DVertexBuffer()
{
}

void D3DVertexBuffer::Bind(Renderer *r)
{
	D3DRenderer *dr = (D3DRenderer *)r;

	assert(m_buffer);

	dr->GetD3DDevice()->SetFVF(D3DFVF_XYZ|D3DFVF_DIFFUSE);
	dr->GetD3DDevice()->SetStreamSource(0, m_buffer, 0, m_vertexStride);
}

