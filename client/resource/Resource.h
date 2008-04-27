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

class Resource : public IRefcounted
{
public:
	Resource(enum ResourceType type, const char *name);

	ResourceType GetType() const { return mType; }

	// from IRefcounted
	virtual int AddRef();
	virtual int RemoveRef();

private:
	int mRefCount;
	enum ResourceType mType;
	std::string mName;

protected:
	virtual ~Resource();

	friend class ResourceManager;
};

// helpful typedefs
typedef std::list<Resource*> ResourceList;
typedef std::list<Resource*>::iterator ResourceListIterator;
typedef std::list<Resource*>::const_iterator ResourceListConstIterator;

#endif
