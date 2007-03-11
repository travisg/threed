#include <resource/Resource.h>

Resource::Resource(ResourceType type)
:	mRefCount(0),
	m_Type(type)
{
	AddRef();
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
