#ifndef __RESOURCE_AC3DLOADER_H
#define __RESOURCE_AC3DLOADER_H

#include <resource/loader/Loader.h>
#include <shared/mesh.h>
#include <stdio.h>
#include <tinyxml/tinyxml.h>

class MeshLoader : public Loader {
public:
	MeshLoader(ResourceManager &);
	virtual ~MeshLoader();

	virtual Resource *LoadResource(const char *resource);

private:
};

#endif
