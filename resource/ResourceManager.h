#ifndef __RESOURCE_MANAGER_H
#define __RESOURCE_MANAGER_H

#include <resource/Resource.h>

class ResourceManager {
public:
	ResourceManager();
	virtual ~ResourceManager();

private:
	void AddResource(Resource *r);
	void RemoveResource(Resource *r);

	ResourceList mResources;
};

#endif
