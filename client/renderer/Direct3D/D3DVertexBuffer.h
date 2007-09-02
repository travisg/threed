#ifndef __D3D_VERTEXBUFFER_H
#define __D3D_VERTEXBUFFER_H

#include <renderer/VertexBuffer.h>

class D3DVertexBuffer : public VertexBuffer
{
public:
	D3DVertexBuffer();
	virtual ~D3DVertexBuffer();

	virtual void Bind(Renderer *r);

	// load external vertex data
	virtual int LoadSimpleVertexes(const float *vertexes, unsigned int count); // xyz
	virtual int LoadVertexes(const float *vertexes, Vertex_Format format, unsigned int count);

protected:
	struct IDirect3DVertexBuffer9 *m_buffer;
	unsigned int m_vertexStride;
	unsigned int m_FVF; // vertex type
};

#endif
