#ifndef __RESOURCE_OBJECT_LOADER_H
#define __RESOURCE_OBJECT_LOADER_H

#include <resource/loader/Loader.h>

class ObjectLoader : public Loader {
public:
	ObjectLoader(ResourceManager &m);
	virtual ~ObjectLoader();

	virtual Resource *LoadResource(const char *name);

private:
};



#endif
