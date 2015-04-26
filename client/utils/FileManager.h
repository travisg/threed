#ifndef __FILE_MANAGER_H
#define __FILE_MANAGER_H

#include <string>

class File;

class FileManager {
public:
	FileManager();
	virtual ~FileManager();

	File *OpenFile(const char *name);

private:
    std::string mLeadingPath;
};

#endif
