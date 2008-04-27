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
public:
	ObjectResource(const char *name);
protected:
	~ObjectResource();

public:
	const ObjectResourceList getObjectResourceList() const { return mResourceSets; }

private:
	ObjectResourceList mResourceSets;

	friend class ObjectLoader;
};


#endif
