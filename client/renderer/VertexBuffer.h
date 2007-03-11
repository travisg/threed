#ifndef __VERTEXBUFFER_H
#define __VERTEXBUFFER_H

class Renderer;

class VertexBuffer
{
public:
	VertexBuffer();
	virtual ~VertexBuffer();

	static VertexBuffer *CreateVertexBuffer();

	virtual void Bind(Renderer *r) = 0;

	// accessors
	unsigned int Size() { return m_bufferSize; }
	unsigned int Count() { return m_vertexCount; }

	// load external vertex data
	virtual int LoadSimpleVertexes(const float *vertexes, unsigned int count) = 0; // xyz

protected:
	unsigned int m_bufferSize;
	unsigned int m_vertexCount;
};

#endif
