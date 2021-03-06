#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct vertexref {
    unsigned int index;
    float u, v;
};

struct AC3DSurface {
    AC3DSurface() : vertexcount(0), refs(0) {}
    ~AC3DSurface() {
        delete[] refs;
    }

    int vertexcount;
    struct vertexref *refs;
};

struct AC3DObject {
public:
    AC3DObject() : parent(0), children(0), next(0), numverts(0), verts(0), numsurfs(0), surfs(0) {}

    ~AC3DObject() {
        delete[] verts;
        delete[] surfs;
    }

    AC3DObject *parent;
    AC3DObject *children;
    AC3DObject *next;

    int numverts;
    float *verts;
    int numsurfs;
    AC3DSurface *surfs;
};

class AC3DLoader {
public:
    AC3DLoader();
    ~AC3DLoader();

    int Load(FILE *infp);

private:
    int ParseObject(AC3DObject *parent);

    FILE *m_fp;

    // object data
    AC3DObject *m_objects;
};

AC3DLoader::AC3DLoader()
    :   m_fp(0)
{
}

AC3DLoader::~AC3DLoader()
{
    if (m_fp)
        fclose(m_fp);
}

static char *ReadLinesUntil(FILE *fp, char *line, size_t linesize, const char *leading)
{
    do {
        if (!fgets(line, (int)linesize, fp))
            return 0;
    } while (strncmp(leading, line, strlen(leading)) != 0);

    return line;
}

int AC3DLoader::ParseObject(AC3DObject *parent)
{
    char line[128];
    int i;
    AC3DObject *obj = new AC3DObject;

    // read in all the vertices
    if (!ReadLinesUntil(m_fp, line, sizeof(line), "numvert"))
        return -1;

    sscanf(line, "numvert %d\n", &obj->numverts);

    obj->verts = new float[obj->numverts * 3];

    for (i = 0; i < obj->numverts; i++) {
        if (fscanf(m_fp, "%f %f %f\n", &obj->verts[i*3], &obj->verts[i*3+1], &obj->verts[i*3+2]) < 3) {
            delete obj;
            return -1;
        }
    }

    // read in all the surfaces
    if (!ReadLinesUntil(m_fp, line, sizeof(line), "numsurf"))
        return -1;

    sscanf(line, "numsurf %d\n", &obj->numsurfs);

    obj->surfs = new AC3DSurface[obj->numsurfs];

    for (i = 0; i < obj->numsurfs; i++) {
        // get SURF
        int surfprop;
        fscanf(m_fp, "SURF 0x%x\n", &surfprop);

        // consume mat line
        if (!fgets(line, sizeof(line), m_fp))
            return -1;
        if (strncmp("mat", line, 3) == 0) {
            if (!fgets(line, sizeof(line), m_fp))
                return -1;
        }

        // get refs
        sscanf(line, "refs %d\n", &obj->surfs[i].vertexcount);

        obj->surfs[i].refs = new vertexref[obj->surfs[i].vertexcount];
        for (int ref = 0; ref < obj->surfs[i].vertexcount; ref++) {
            fscanf(m_fp, "%d %f %f\n", &obj->surfs[i].refs[ref].index, &obj->surfs[i].refs[ref].u, &obj->surfs[i].refs[ref].v);
        }
    }

    // finished parsing object, stick it in our list
    obj->parent = parent;
    if (!parent) {
        m_objects = obj;
    } else {
        obj->next = parent->children;
        parent->children = obj;
    }

    // read in the number of children
    int kids;
    fscanf(m_fp, "kids %d\n", &kids);

    for (i=0; i < kids; i++) {
        if (ParseObject(obj) < 0)
            return -1;
    }

    return 0;
}


int AC3DLoader::Load(FILE *infp)
{
    char line[128];

    assert(infp);
    m_fp = infp;

    // verify the first line has 'AC3Db' in it
    fscanf(m_fp, "%s\n", line);
    if (strcmp(line, "AC3Db") != 0)
        return -1;

    // consume stuff until 'world'
    // XXX deal with multiple kids
    ReadLinesUntil(m_fp, line, sizeof(line), "OBJECT world");
    ReadLinesUntil(m_fp, line, sizeof(line), "kids");

    if (ParseObject(0) < 0)
        return -1;

    return 0;
}

static int BuildTriangleIndex(const AC3DObject &obj, unsigned int **indexes)
{
    int count;

    // count the number of transformed indexes
    count = 0;
    for (int s = 0; s < obj.numsurfs; s++) {
        count += obj.surfs[s].vertexcount;
    }

    *indexes = new unsigned int[count];

    unsigned int *ptr = *indexes;
    for (int s = 0; s < obj.numsurfs; s++) {
        for (int ref = 0; ref < obj.surfs[s].vertexcount; ref++) {
            *ptr = obj.surfs[s].refs[ref].index;
            ptr++;
        }
    }


    return count;
}

#if 0
Engine::Spatial *AC3DLoader::ConstructSpatial()
{
    Engine::Geometry *geom = new Engine::Geometry();

    geom->m_Mesh = Mesh::CreateMesh(Mesh::MESH_TYPE_TRIANGLES);

    // load the index buffer
    IndexBuffer *ib = IndexBuffer::CreateIndexBuffer();
    unsigned int *indexes;
    unsigned int indexCount = BuildTriangleIndex(*m_objects, &indexes);
    ib->LoadIndexes(indexes, indexCount);
    delete[] indexes;
    geom->m_Mesh->SetIndexBuffer(ib);

    // create and load the vertex buffer
    VertexBuffer *vb = VertexBuffer::CreateVertexBuffer();
    vb->LoadSimpleVertexes(m_objects->verts, m_objects->numverts);
    geom->m_Mesh->SetVertexBuffer(vb);

    return geom;
}
#endif


int ac3d_load(FILE *infp)
{
    AC3DLoader loader;

    loader.Load(infp);
    return -1;
}
