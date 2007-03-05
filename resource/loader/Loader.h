#ifndef __RESOURCE_LOADER_H
#define __RESOURCE_LOADER_H

#include <engine/Spatial.h>
#include <resource/Resource.h>

class Loader {
public:
	virtual ~Loader();

	static Loader *CreateLoader(const char *resource, enum ResourceType type);

	virtual Engine::Spatial *ConstructSpatial() = 0;

	virtual int OpenResource(const char *resource) = 0;

protected:
	Loader();
};

#endif
