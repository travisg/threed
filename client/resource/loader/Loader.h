#ifndef __RESOURCE_LOADER_H
#define __RESOURCE_LOADER_H

#include <engine/Spatial.h>
#include <resource/Resource.h>

class ResourceManager;

class Loader {
public:
	virtual ~Loader() = 0;

	static Loader *CreateLoader(ResourceManager &m, const char *resource, enum ResourceType type);

	virtual Resource *LoadResource(const char *name) = 0;

protected:
	Loader(ResourceManager &);

	ResourceManager &mResourceManager;
};

#endif
