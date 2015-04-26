#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLVertexBuffer.h>

#include <assert.h>
#include "glinc.h"


#define VERTEX_POS_INDX			0
#define VERTEX_NORMAL_INDX		1
#define VERTEX_TEXCOORD0_INDX	2

#define VERTEX_POS_SIZE			3
#define VERTEX_NORMAL_SIZE		3
#define VERTEX_TEXCOORD0_SIZE	2

VertexBuffer *VertexBuffer::CreateVertexBuffer()
{
	return new GLVertexBuffer();
}

GLVertexBuffer::GLVertexBuffer()
:	VertexBuffer(),
	m_VertexStride(0),
	m_Format(VERT_FORMAT_NULL),
	m_BufferHandle(0),
	m_Buffer(0)
{
}

GLVertexBuffer::~GLVertexBuffer()
{
	glDeleteBuffers(1, &m_BufferHandle);
	m_BufferHandle = 0;
	if (m_Buffer)
		delete[] m_Buffer;
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
			m_VertexStride = VERTEX_POS_SIZE * 4;
			break;
		case VERT_FORMAT_POS_NORM:
			m_VertexStride = (VERTEX_POS_SIZE + VERTEX_NORMAL_SIZE) * 4;
			break;
		case VERT_FORMAT_POS_NORM_UV:
			m_VertexStride = (VERTEX_POS_SIZE + VERTEX_NORMAL_SIZE + VERTEX_TEXCOORD0_SIZE) * 4;
			break;
		default:
			assert(0);
	}

	m_vertexCount = count;
	m_bufferSize = m_VertexStride * m_vertexCount;
	m_Format = format;

	m_Buffer = new char[m_bufferSize];
	assert(m_Buffer);

	// convert format (XXX total hack)
	switch (format) {
		case VERT_FORMAT_POS_NORM: {
			struct target {
				float normx, normy, normz;
				float posx, posy, posz;
			};
			struct src {
				float posx, posy, posz;
				float normx, normy, normz;
			};
			
			struct target *t = (struct target *)m_Buffer;
			const struct src *s = (const struct src *)vertexes;
			for (unsigned int i = 0; i < m_vertexCount; i++) {
				t->posx = s->posx;
				t->posy = s->posy;
				t->posz = s->posz;
				t->normx = s->normx;
				t->normy = s->normy;
				t->normz = s->normz;
				s++;
				t++;
			}
			break;
		}
		case VERT_FORMAT_POS_NORM_UV: {
			struct target {
				float posx, posy, posz;
				float normx, normy, normz;
				float u, v;
			};
			struct src {
				float posx, posy, posz;
				float normx, normy, normz;
				float u, v;
			};

			struct target *t = (struct target *)m_Buffer;
			const struct src *s = (const struct src *)vertexes;
			for (unsigned int i = 0; i < m_vertexCount; i++) {
				t->posx = s->posx;
				t->posy = s->posy;
				t->posz = s->posz;
				t->normx = s->normx;
				t->normy = s->normy;
				t->normz = s->normz;
				t->u = s->u;
				t->v = s->v;
				s++;
				t++;
			}
			break;
		}
		default:
			assert(0);
	}

	glGenBuffers(1, &m_BufferHandle);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferHandle);
	glBufferData(GL_ARRAY_BUFFER, m_bufferSize, m_Buffer, GL_STATIC_DRAW);

	return 0;
}

void GLVertexBuffer::Bind(Renderer *r)
{
	GLchar *offset = 0;

	glBindBuffer(GL_ARRAY_BUFFER, m_BufferHandle);

	switch (m_Format) {
		case VERT_FORMAT_POS:
			glEnableVertexAttribArray(VERTEX_POS_INDX);
			glVertexAttribPointer(VERTEX_POS_INDX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, m_VertexStride, (const void *)offset);
			break;
		case VERT_FORMAT_POS_NORM:
			glEnableVertexAttribArray(VERTEX_POS_INDX);
			glEnableVertexAttribArray(VERTEX_NORMAL_INDX);
			glVertexAttribPointer(VERTEX_POS_INDX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, m_VertexStride, (const void *)offset);
			offset += VERTEX_POS_SIZE * sizeof(GLfloat);
			glVertexAttribPointer(VERTEX_NORMAL_INDX, VERTEX_NORMAL_SIZE, GL_FLOAT, GL_FALSE, m_VertexStride, (const void *)offset);
			break;
		case VERT_FORMAT_POS_NORM_UV:
			glEnableVertexAttribArray(VERTEX_POS_INDX);
			glEnableVertexAttribArray(VERTEX_NORMAL_INDX);
			glEnableVertexAttribArray(VERTEX_TEXCOORD0_INDX);
			glVertexAttribPointer(VERTEX_POS_INDX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, m_VertexStride, (const void *)offset);
			offset += VERTEX_POS_SIZE * sizeof(GLfloat);
			glVertexAttribPointer(VERTEX_NORMAL_INDX, VERTEX_NORMAL_SIZE, GL_FLOAT, GL_FALSE, m_VertexStride, (const void *)offset);
			offset += VERTEX_NORMAL_SIZE * sizeof(GLfloat);
			glVertexAttribPointer(VERTEX_TEXCOORD0_INDX, VERTEX_TEXCOORD0_SIZE, GL_FLOAT, GL_FALSE, m_VertexStride, (const void *)offset);
			break;
		default:
			assert(0);
	}
			
}

int GLVertexBuffer::BindAttribLocations(GLuint program, Vertex_Format format)
{
	switch (format) {
		case VERT_FORMAT_POS:
			glBindAttribLocation(program, VERTEX_POS_INDX, "v_position");
			break;
		case VERT_FORMAT_POS_NORM:
			glBindAttribLocation(program, VERTEX_POS_INDX, "v_position");
			glBindAttribLocation(program, VERTEX_NORMAL_INDX, "v_normal");
			break;
		case VERT_FORMAT_POS_NORM_UV:
			glBindAttribLocation(program, VERTEX_POS_INDX, "v_position");
			glBindAttribLocation(program, VERTEX_NORMAL_INDX, "v_normal");
			glBindAttribLocation(program, VERTEX_TEXCOORD0_INDX, "v_texcoord0");
			break;
		default:
			assert(0);
	}

	return 0;
}
