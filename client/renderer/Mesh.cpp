#include <renderer/Mesh.h>
#include <assert.h>

Mesh::Mesh(Mesh_Type type)
    :   RenderResource(),
        m_IB(0),
        m_VB(0),
        m_Type(type)
{
}

Mesh::~Mesh()
{
}

void Mesh::SetIndexBuffer(IndexBuffer *ib)
{
    assert(!m_IB);
    m_IB = ib;
}

void Mesh::SetVertexBuffer(VertexBuffer *vb)
{
    assert(!m_VB);
    m_VB = vb;
}
