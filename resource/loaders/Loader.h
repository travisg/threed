#ifndef __RESOURCE_LOADER_H
#define __RESOURCE_LOADER_H

#include <engine/Geometry.h>

class Loader {
public:
	enum RESOURCE_TYPE {
		RESOURCE_TYPE_MESH,
		RESOURCE_TYPE_TEXTURE,
		MAX_RESOURCE_TYPE
	};

	virtual ~Loader();

	static Loader *CreateLoader(const char *resource, enum RESOURCE_TYPE type);

	virtual Engine::Geometry *ConstructGeometry() = 0;

	virtual int OpenResource(const char *resource) = 0;

protected:
	Loader();
};

#endif
