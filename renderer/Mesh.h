#ifndef __MESH_H
#define __MESH_H

class Renderer;

class IndexBuffer;
class VertexBuffer;

class Mesh
{
public:
	enum MESH_Type {
		MESH_TYPE_NULL,
		MESH_TYPE_POINTS,
		MESH_TYPE_TRAINGLES,
		MESH_TYPE_TRAINGLE_MESH,
		MESH_TYPE_TRAINGLE_FAN,
		MAX_VB_TYPE
	};

	Mesh(MESH_Type type);
	virtual ~Mesh();

	static Mesh *CreateMesh();

	virtual void Draw(Renderer *r) = 0;

protected:
	IndexBuffer *m_IB;
	VertexBuffer *m_VB;
	MESH_Type m_Type;
};

#endif
