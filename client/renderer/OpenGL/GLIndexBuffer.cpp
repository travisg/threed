#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLIndexBuffer.h>
#include <assert.h>

#include "glinc.h"

IndexBuffer *IndexBuffer::CreateIndexBuffer()
{
	return new GLIndexBuffer();
}

GLIndexBuffer::GLIndexBuffer()
:	IndexBuffer()
,	m_BufferHandle(0)
{
}

GLIndexBuffer::~GLIndexBuffer()
{
	glDeleteBuffersARB(1, &m_BufferHandle);
	m_BufferHandle = 0;
}

int GLIndexBuffer::LoadIndexes(unsigned int *indexes, unsigned int count)
{	

	glGenBuffersARB(1, &m_BufferHandle);
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER, m_BufferHandle);
	glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER, count * 4, NULL, GL_STATIC_DRAW);
	void *buffer = glMapBufferARB(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
	assert(buffer);

	memcpy(buffer, indexes, count * 4);

	m_Count = count;

	glUnmapBufferARB(GL_ELEMENT_ARRAY_BUFFER);

	return 0;
}

void GLIndexBuffer::Bind(Renderer *r)
{
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER, m_BufferHandle);
}
