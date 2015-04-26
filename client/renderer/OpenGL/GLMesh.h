#ifndef __GL_MESH_H
#define __GL_MESH_H

class Renderer;

#include <renderer/Mesh.h>
#include "glinc.h"

class GLMesh : public Mesh {
public:
    virtual ~GLMesh();

    virtual void Draw(Renderer *r);

private:
    friend class Mesh;
    GLMesh(Mesh_Type type);

    GLenum m_Type;

};

#endif
