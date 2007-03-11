#ifndef __RESOURCE_MANAGER_H
#define __RESOURCE_MANAGER_H

#include <resource/Resource.h>
#include <utils/FileManager.h>
#include <engine/Spatial.h>

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	// not quite the final api, but closer
	Engine::Spatial *ConstructModel(const char *name);

private:
	void AddResource(Resource *r);
	void RemoveResource(Resource *r);

	ResourceList mResources;
	FileManager mFileManager;
};

#endif
