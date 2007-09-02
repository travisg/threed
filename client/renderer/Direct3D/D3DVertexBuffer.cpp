#include <renderer/D3DRenderer.h>
#include <renderer/D3DVertexBuffer.h>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
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
	struct myvertex {
		FLOAT x, y, z;
		D3DCOLOR diffuse;
		D3DCOLOR specular;
	};

	UINT FVF = (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_SPECULAR);

	assert(!m_buffer);

	m_vertexStride = sizeof(myvertex);
	m_bufferSize = count * sizeof(float) * m_vertexStride;
	m_FVF = FVF;
	m_vertexCount = count;

	D3DRenderer::GetD3DRenderer()->GetD3DDevice()->CreateVertexBuffer(m_bufferSize,
										D3DUSAGE_WRITEONLY,
										m_FVF,
										D3DPOOL_MANAGED, &m_buffer, NULL);

	assert(m_buffer);

	struct myvertex *pData;
	m_buffer->Lock(0, 0, (void**)&pData, D3DLOCK_DISCARD);
	for (unsigned i = 0; i < count; i++) {
		pData[i].x = vertexes[i*3];
		pData[i].y = vertexes[i*3+1];
		pData[i].z = vertexes[i*3+2];
		pData[i].diffuse = D3DCOLOR_XRGB(rand() & 0xff, rand() & 0xff, rand() & 0xff);
		pData[i].specular = D3DCOLOR_XRGB(rand() & 0xff, rand() & 0xff, rand() & 0xff);
	}
	m_buffer->Unlock();
	
	return 0;
}

int D3DVertexBuffer::LoadVertexes(const float *vertexes, Vertex_Format format, unsigned int count)
{
	switch (format) {
		case VERT_FORMAT_POS:
			m_FVF = D3DFVF_XYZ|D3DFVF_DIFFUSE;
			m_vertexStride = 3*4 + 4;
			break;
		case VERT_FORMAT_POS_NORM:
			m_FVF = (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE); // give it a color
			m_vertexStride = 6*4 + 4;
			break;
		case VERT_FORMAT_POS_NORM_UV:
//			m_FVF = (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX0|D3DFVF_DIFFUSE);
//			m_vertexStride = 8*4 + 4;
			m_FVF = (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX0);
			m_vertexStride = 8*4;
			break;
		default:
			assert(0);
	}

	m_bufferSize = count * m_vertexStride;
	m_vertexCount = count;

	D3DRenderer::GetD3DRenderer()->GetD3DDevice()->CreateVertexBuffer(m_bufferSize,
		D3DUSAGE_WRITEONLY,
		m_FVF,
		D3DPOOL_MANAGED, &m_buffer, NULL);

	assert(m_buffer);

	D3DCOLOR *pData;
//	D3DCOLOR color = D3DCOLOR_XRGB(rand() & 0xff, rand() & 0xff, rand() & 0xff);
	D3DCOLOR color = D3DCOLOR_XRGB(0xff, 0xff, 0xff);
	m_buffer->Lock(0, 0, (void**)&pData, D3DLOCK_DISCARD);

	if (m_FVF == (D3DFVF_XYZ|D3DFVF_DIFFUSE)) {
		for (unsigned i = 0; i < count; i++) {
			memcpy(&pData[i*4], &vertexes[i*3], 3*4);
			pData[i*4+3] = color;
		}
	} else if (m_FVF == (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE)) {
		for (unsigned i = 0; i < count; i++) {
			memcpy(&pData[i*7], &vertexes[i*6], 6*4);
			pData[i*7+6] = color;
		}
	} else if (m_FVF == (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX0|D3DFVF_DIFFUSE)) {
		for (unsigned i = 0; i < count; i++) {
			memcpy(&pData[m_vertexStride/4 * i], &vertexes[(m_vertexStride-1)/4 * i], m_vertexStride-4);
			pData[m_vertexStride/4 * i + m_vertexStride/4 - 1] = color;
		}
	} else {
		memcpy(pData, vertexes, m_vertexStride * count);
	}

	m_buffer->Unlock();

	return 0;
}

D3DVertexBuffer::~D3DVertexBuffer()
{
}

void D3DVertexBuffer::Bind(Renderer *r)
{
	D3DRenderer *dr = (D3DRenderer *)r;

	assert(m_buffer);

	HRESULT res;
	res = dr->GetD3DDevice()->SetFVF(m_FVF);
	assert(res == D3D_OK);

	res = dr->GetD3DDevice()->SetStreamSource(0, m_buffer, 0, m_vertexStride);
	assert(res == D3D_OK);
}

