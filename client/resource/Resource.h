#ifndef __RESOURCE_H
#define __RESOURCE_H

#include <utils/IRefcounted.h>
#include <string>
#include <list>

enum ResourceType {
	RT_NULL,
	RT_OBJECT, // a complete object, with a list of all the resources needed
	RT_MESH,
	RT_TEXTURE,
	RT_SHADER,

	RT_MAX
};

class ResourceManager;

class Resource : public IRefcounted
{
public:
	ResourceType GetType() const { return mType; }

	// load a resource from backing storage
	static Resource *LoadResource(ResourceManager &m, const char *name, enum ResourceType type);

	// from IRefcounted
	virtual int AddRef();
	virtual int RemoveRef();

protected:
	int mRefCount;
	enum ResourceType mType;
	std::string mName;
	ResourceManager &mResourceManager;

	Resource(ResourceManager &m, const char *name, enum ResourceType type);
	virtual ~Resource();

	// each type has to implement this to restore from backing store
	virtual int LoadFromStorage() = 0;

	friend class ResourceManager;
};

// helpful typedefs
typedef std::list<Resource*> ResourceList;
typedef std::list<Resource*>::iterator ResourceListIterator;
typedef std::list<Resource*>::const_iterator ResourceListConstIterator;

#endif
