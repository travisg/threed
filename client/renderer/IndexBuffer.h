#ifndef __INDEXBUFFER_H
#define __INDEXBUFFER_H

class Renderer;

class IndexBuffer {
public:
    IndexBuffer();
    virtual ~IndexBuffer();

    static IndexBuffer *CreateIndexBuffer();

    virtual void Bind(Renderer *r) = 0;

    // accessors
    unsigned int Count() { return m_Count; }

    // load indexes
    virtual int LoadIndexes(const unsigned int *indexes, unsigned int count) = 0;

protected:
    unsigned int m_Count;
};

#endif
