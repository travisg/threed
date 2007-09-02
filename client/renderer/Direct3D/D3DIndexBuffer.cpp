#include <renderer/D3DRenderer.h>
#include <renderer/D3DIndexBuffer.h>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <assert.h>

IndexBuffer *IndexBuffer::CreateIndexBuffer()
{
	return new D3DIndexBuffer();
}

D3DIndexBuffer::D3DIndexBuffer()
:	IndexBuffer(),
	m_buffer(0)
{

}

D3DIndexBuffer::~D3DIndexBuffer()
{
}

int D3DIndexBuffer::LoadIndexes(unsigned int *indexes, unsigned int count)
{	
	assert(!m_buffer);

	D3DRenderer::GetD3DRenderer()->GetD3DDevice()->CreateIndexBuffer(count * 4, 
										D3DUSAGE_WRITEONLY,
										D3DFMT_INDEX32 ,
										D3DPOOL_MANAGED, &m_buffer, NULL);

	assert(m_buffer);

	void *pData;
	m_buffer->Lock(0, 0, (void**)&pData, D3DLOCK_DISCARD);
	memcpy(pData, indexes, count * 4);
	m_buffer->Unlock();

	m_Count = count;

	return 0;
}


void D3DIndexBuffer::Bind(Renderer *r)
{
	D3DRenderer *dr = (D3DRenderer *)r;

	assert(m_buffer);

	HRESULT res = dr->GetD3DDevice()->SetIndices(m_buffer);

	assert(res == D3D_OK);
}

