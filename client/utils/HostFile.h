#ifndef __HOST_FILE_H
#define __HOST_FILE_H

#include <utils/File.h>
#include <stdio.h>

class HostFile : public File {
public:
	HostFile();

	// file interface
	virtual int Open(const char *name);
	virtual int Read(void *buf, size_t len);
	virtual int Write(const void *buf, size_t len);
	virtual off_t Seek(off_t offset);
	virtual int ReadLine(char *line, size_t linelen); // read a single line of a text file


private:
	FILE *m_fp;

protected:
	virtual ~HostFile();
};

#endif
