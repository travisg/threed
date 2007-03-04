#ifndef __RESOURCE_H
#define __RESOURCE_H

#include <utils/IRefcounted.h>
#include <list>

class Resource : public IRefcounted
{
public:
	Resource();
	virtual ~Resource();

	// from IRefcounted
	virtual int AddRef();
	virtual int RemoveRef();

private:
	int m_refcount;
};

// helpful typedefs
typedef std::list<Resource*> ResourceList;
typedef std::list<Resource*>::iterator ResourceListIterator;
typedef std::list<Resource*>::const_iterator ResourceListConstIterator;

#endif
