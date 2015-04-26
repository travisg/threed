#ifndef __GL_INDEXBUFFER_H
#define __GL_INDEXBUFFER_H

#include <renderer/IndexBuffer.h>
#include "glinc.h"

class GLIndexBuffer : public IndexBuffer
{
public:
	GLIndexBuffer();
	virtual ~GLIndexBuffer();

	virtual void Bind(Renderer *r);

	// load indexes
	virtual int LoadIndexes(const unsigned int *indexes, unsigned int count);

protected:
	GLuint m_BufferHandle;
};

#endif
