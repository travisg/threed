#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLVertexBuffer.h>

#include <assert.h>
#include "glinc.h"


VertexBuffer *VertexBuffer::CreateVertexBuffer()
{
	return new GLVertexBuffer();
}

GLVertexBuffer::GLVertexBuffer()
:	VertexBuffer(),
	m_BufferHandle(0),
	m_Format(0),
	m_vertexStride(0)
{
}

GLVertexBuffer::~GLVertexBuffer()
{
	glDeleteBuffers(1, &m_BufferHandle);
	m_BufferHandle = 0;
}

// simple xyz vertexes
int GLVertexBuffer::LoadSimpleVertexes(const float *vertexes, unsigned int count)
{
	assert(0);
#if 0
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
#endif
	return 0;
}

int GLVertexBuffer::LoadVertexes(const float *vertexes, Vertex_Format format, unsigned int count)
{
	switch (format) {
		case VERT_FORMAT_POS:
			m_Format = GL_V3F;
			m_vertexStride = 3*4;
			break;
		case VERT_FORMAT_POS_NORM:
			m_Format = GL_C4F_N3F_V3F; // add a color
			m_vertexStride = 6*4 + 4 * 4;
			break;
		case VERT_FORMAT_POS_NORM_UV:
			m_Format = GL_T2F_N3F_V3F;
			m_vertexStride = 8*4;
			break;
		default:
			assert(0);
	}

	m_vertexCount = count;
	m_bufferSize = m_vertexStride * m_vertexCount;

	glGenBuffers(1, &m_BufferHandle);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferHandle);
	glBufferData(GL_ARRAY_BUFFER, m_bufferSize, NULL, GL_STATIC_DRAW);
	void *buffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	assert(buffer);

	switch (format) {
		case VERT_FORMAT_POS_NORM: {
			struct target {
				float color0, color1, color2, color3;
				float normx, normy, normz;
				float posx, posy, posz;
			};
			struct src {
				float posx, posy, posz;
				float normx, normy, normz;
			};
			
			struct target *t = (struct target *)buffer;
			const struct src *s = (const struct src *)vertexes;
			for (unsigned int i = 0; i < m_vertexCount; i++) {
				t->posx = s->posx;
				t->posy = s->posy;
				t->posz = s->posz;
				t->normx = s->normx;
				t->normy = s->normy;
				t->normz = s->normz;
				t->color0 = (rand() & 0xff) / 256.0f;
				t->color1 = (rand() & 0xff) / 256.0f;
				t->color2 = (rand() & 0xff) / 256.0f;
				t->color3 = 1.0f;
				s++;
				t++;
			}
			break;
		}
		default:
			assert(0);
	}

	glUnmapBuffer(GL_ARRAY_BUFFER);

	return 0;
}

void GLVertexBuffer::Bind(Renderer *r)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferHandle);	
	glInterleavedArrays(m_Format, 0, 0);
}

