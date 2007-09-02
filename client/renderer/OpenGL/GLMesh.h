#ifndef __GL_MESH_H
#define __GL_MESH_H

class Renderer;

#include <renderer/Mesh.h>

class GLMesh : public Mesh
{
public:
	GLMesh(Mesh_Type type);
	virtual ~GLMesh();

	virtual void Draw(Renderer *r);

	virtual void SetDefault();


protected:
//	D3DPRIMITIVETYPE m_D3DType;
//	D3DMATERIAL9 m_D3DMaterial;
};

#endif
