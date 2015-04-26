#ifndef __OBJECT_RESOURCE_H
#define __OBJECT_RESOURCE_H

#include <resource/Resource.h>

struct object_resource_set {
    Resource *shader;
    Resource *mesh;
    ResourceList textures;
};

typedef std::list<object_resource_set *> ObjectResourceList;
typedef std::list<object_resource_set *>::const_iterator ObjectResourceListConstIterator;

class ObjectResource : public Resource {
protected:
    ObjectResource(ResourceManager &m, const char *name);
    ~ObjectResource();

    virtual int LoadFromStorage();

public:
    const ObjectResourceList getObjectResourceList() const { return mResourceSets; }

private:
    ObjectResourceList mResourceSets;

    // only Resource can construct us
    friend class Resource;
};


#endif
