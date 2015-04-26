#ifndef __D3D_INDEXBUFFER_H
#define __D3D_INDEXBUFFER_H

#include <renderer/IndexBuffer.h>

class D3DIndexBuffer : public IndexBuffer {
public:
    D3DIndexBuffer();
    virtual ~D3DIndexBuffer();

    virtual void Bind(Renderer *r);

    // load indexes
    virtual int LoadIndexes(unsigned int *indexes, unsigned int count);

protected:
    struct IDirect3DIndexBuffer9 *m_buffer;
};

#endif
