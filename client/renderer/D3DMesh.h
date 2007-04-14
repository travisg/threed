#ifndef __D3DMESH_H
#define __D3DMESH_H

class Renderer;

#include <renderer/Mesh.h>

class D3DMesh : public Mesh
{
public:
	D3DMesh(Mesh_Type type);
	virtual ~D3DMesh();

	virtual void Draw(Renderer *r);

	virtual void SetDefault();


protected:
	unsigned int m_D3DType;
};

#endif
