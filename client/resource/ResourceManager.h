#ifndef __RESOURCE_MANAGER_H
#define __RESOURCE_MANAGER_H

#include <resource/Resource.h>
#include <utils/FileManager.h>
#include <engine/Spatial.h>

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    // get a resource from the list
    Resource *GetResource(const char *name, ResourceType type);

    size_t GetResourceCount() const { return mResources.size(); }
    void DumpResources();

    // reload shaders
    void ReloadShaders();

private:
    void AddResource(Resource *r);
    void RemoveResource(Resource *r);

    ResourceList mResources;
    FileManager mFileManager;
};

#endif
