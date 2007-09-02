#ifndef __GL_MESH_H
#define __GL_MESH_H

class Renderer;

#include <renderer/Mesh.h>
#include "glinc.h"

class GLMesh : public Mesh
{
public:
	GLMesh(Mesh_Type type);
	virtual ~GLMesh();

	virtual void Draw(Renderer *r);

	virtual void SetDefault();


protected:
	GLenum m_Type;
};

#endif
