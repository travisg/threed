#include <resource/Resource.h>

Resource::Resource()
:	m_refcount(0)
{
}

Resource::~Resource()
{
}

int Resource::AddRef()
{
	return m_refcount++;
}

int Resource::RemoveRef()
{
	if (--m_refcount == 0) {
		delete this;
		return 0;
	}
	return m_refcount;
}
