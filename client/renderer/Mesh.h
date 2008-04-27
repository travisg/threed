#ifndef __MESH_H
#define __MESH_H

#include <shared/mesh.h>

class Renderer;

class IndexBuffer;
class VertexBuffer;
class Resource;

class Mesh
{
public:
	Mesh(Mesh_Type type);
	virtual ~Mesh();

	static Mesh *CreateMesh(Mesh_Type type);
	static Mesh *CreateMeshFromResource(Resource *r);

	void SetIndexBuffer(IndexBuffer *ib);
	void SetVertexBuffer(VertexBuffer *vb);

	virtual void Draw(Renderer *r) = 0;
	virtual void SetDefault() = 0;

protected:
	IndexBuffer *m_IB;
	VertexBuffer *m_VB;
	Mesh_Type m_Type;

	friend class Loader;
};

#endif
