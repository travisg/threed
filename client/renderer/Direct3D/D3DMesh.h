#ifndef __D3DMESH_H
#define __D3DMESH_H

class Renderer;

#include <renderer/Mesh.h>
#include <d3d9.h>
#include <d3dx9.h>

class D3DMesh : public Mesh {
public:
    D3DMesh(Mesh_Type type);
    virtual ~D3DMesh();

    virtual void Draw(Renderer *r);

    virtual void SetDefault();


protected:
    D3DPRIMITIVETYPE m_D3DType;
    D3DMATERIAL9 m_D3DMaterial;
};

#endif
