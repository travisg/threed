#ifndef __GL_VERTEXBUFFER_H
#define __GL_VERTEXBUFFER_H

#include <renderer/VertexBuffer.h>
#include "glinc.h"

class GLVertexBuffer : public VertexBuffer
{
public:
	GLVertexBuffer();
	virtual ~GLVertexBuffer();

	virtual void Bind(Renderer *r);

	// load external vertex data
	virtual int LoadSimpleVertexes(const float *vertexes, unsigned int count); // xyz
	virtual int LoadVertexes(const float *vertexes, Vertex_Format format, unsigned int count);

protected:
	unsigned int m_vertexStride;
	unsigned int m_Format;
	GLuint m_BufferHandle;
};

#endif
