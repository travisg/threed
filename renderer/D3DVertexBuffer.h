#ifndef __D3D_VERTEXBUFFER_H
#define __D3D_VERTEXBUFFER_H

#include <renderer/VertexBuffer.h>

class D3DVertexBuffer : public VertexBuffer
{
public:
	D3DVertexBuffer(VB_Type type);
	virtual ~D3DVertexBuffer();

	virtual void Draw(Renderer *r);

protected:
	struct IDirect3DVertexBuffer9 *m_buffer;
};

#endif
