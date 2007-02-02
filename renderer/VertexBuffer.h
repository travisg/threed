#ifndef __VERTEXBUFFER_H
#define __VERTEXBUFFER_H

class Renderer;

class VertexBuffer
{
public:
	enum VB_Type {
		VB_TYPE_POINTS,
		VB_TYPE_TRAINGLES,
		VB_TYPE_TRAINGLE_MESH,
		VB_TYPE_TRAINGLE_FAN,
		VB_TYPE_QUADS,
		MAX_VB_TYPE
	};

	VertexBuffer(VB_Type type);
	virtual ~VertexBuffer();

	static VertexBuffer *CreateVertexBuffer();

	virtual void Draw(Renderer *r) = 0;

protected:
	VB_Type m_Type;
};

#endif
