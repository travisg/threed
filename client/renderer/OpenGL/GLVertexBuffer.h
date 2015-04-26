#ifndef __GL_VERTEXBUFFER_H
#define __GL_VERTEXBUFFER_H

#include <renderer/VertexBuffer.h>
#include "glinc.h"

class GLVertexBuffer : public VertexBuffer {
public:
    GLVertexBuffer();
    virtual ~GLVertexBuffer();

    virtual void Bind(Renderer *r);

    // load external vertex data
    virtual int LoadSimpleVertexes(const float *vertexes, unsigned int count); // xyz
    virtual int LoadVertexes(const float *vertexes, Vertex_Format format, unsigned int count);

    // called from GLProgram at link time to bind attribute locations based on the particular vertex format
    static int BindAttribLocations(GLuint program, Vertex_Format format);

protected:
    unsigned int m_VertexStride;
    Vertex_Format m_Format;
    GLuint m_BufferHandle;
    char *m_Buffer;
};

#endif
