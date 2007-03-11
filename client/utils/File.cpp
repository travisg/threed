#include <utils/File.h>

File::File()
:	mRefCount()
{
	AddRef();
}

File::~File()
{
}

int File::AddRef()
{
	return mRefCount++;
}

int File::RemoveRef()
{
	if (--mRefCount == 0) {
		delete this;
		return 0;
	}
	return mRefCount;
}
