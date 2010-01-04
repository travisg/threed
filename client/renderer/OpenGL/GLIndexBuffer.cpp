#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLIndexBuffer.h>
#include <assert.h>
#include <cstring>

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
	glDeleteBuffers(1, &m_BufferHandle);
	m_BufferHandle = 0;
}

int GLIndexBuffer::LoadIndexes(const unsigned int *indexes, unsigned int count)
{
	glGenBuffers(1, &m_BufferHandle);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferHandle);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * 4, indexes, GL_STATIC_DRAW);

	m_Count = count;

	return 0;
}

void GLIndexBuffer::Bind(Renderer *r)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferHandle);
}
