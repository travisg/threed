#include <resource/Resource.h>

Resource::Resource(ResourceType type, const char *name)
:	mRefCount(0),
	mType(type)
{
	mName = name;
//	AddRef();
}

Resource::~Resource()
{
}

int Resource::AddRef()
{
	return mRefCount++;
}

int Resource::RemoveRef()
{
	if (--mRefCount == 0) {
		delete this;
		return 0;
	}
	return mRefCount;
}
