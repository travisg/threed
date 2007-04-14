#ifndef __RESOURCE_AC3DLOADER_H
#define __RESOURCE_AC3DLOADER_H

#include <resource/loader/Loader.h>
#include <shared/mesh.h>
#include <stdio.h>

class MeshLoader : public Loader {
public:
	MeshLoader();
	virtual ~MeshLoader();

	virtual int OpenResource(const char *resource);

	virtual Engine::Spatial *ConstructSpatial();

private:
	FILE *m_fp;
	mesh_header m_header;
};

#endif
