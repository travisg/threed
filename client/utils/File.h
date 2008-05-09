#ifndef __FILE_H
#define __FILE_H

#include <sys/types.h>
#include <utils/IRefcounted.h>

class File : public IRefcounted {
public:
	File();

	// file interface
	virtual int Open(const char *name) = 0;
	virtual int Read(void *buf, size_t len) = 0;
	virtual int Write(const void *buf, size_t len) = 0;
	virtual off_t Seek(off_t offset) = 0;

	// some convenience stuff
	virtual int ReadLine(char *line, size_t linelen) = 0; // read a single line of a text file

	// from IRefCounted
	virtual int AddRef();
	virtual int RemoveRef();
private:
	int mRefCount;

protected:
	virtual ~File();
};

#endif
