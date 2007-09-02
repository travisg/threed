#include <renderer/OpenGL/GLRenderer.h>
#include <renderer/OpenGL/GLIndexBuffer.h>

#include "glinc.h"

IndexBuffer *IndexBuffer::CreateIndexBuffer()
{
	return new GLIndexBuffer();
}

GLIndexBuffer::GLIndexBuffer()
:	IndexBuffer()
{

}

GLIndexBuffer::~GLIndexBuffer()
{
}

int GLIndexBuffer::LoadIndexes(unsigned int *indexes, unsigned int count)
{	
	m_Indexes = new GLuint[count];
	memcpy(m_Indexes, indexes, count * 4);

	m_Count = count;

	return 0;
}


void GLIndexBuffer::Bind(Renderer *r)
{
}

void GLIndexBuffer::Draw(GLenum mode)
{
	// actually does the draw
	glDrawElements(mode, m_Count, GL_UNSIGNED_INT, m_Indexes);
}