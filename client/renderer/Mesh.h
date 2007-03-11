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
		MESH_TYPE_TRIANGLES,
		MESH_TYPE_TRIANGLE_MESH,
		MESH_TYPE_TRIANGLE_FAN,
		MAX_VB_TYPE
	};

	Mesh(MESH_Type type);
	virtual ~Mesh();

	static Mesh *CreateMesh(MESH_Type type);

	void SetIndexBuffer(IndexBuffer *ib);
	void SetVertexBuffer(VertexBuffer *vb);

	virtual void Draw(Renderer *r) = 0;
	virtual void SetDefault() = 0;

protected:
	IndexBuffer *m_IB;
	VertexBuffer *m_VB;
	MESH_Type m_Type;

	friend class Loader;
};

#endif
