#ifndef __FILE_MANAGER_H
#define __FILE_MANAGER_H

class File;

class FileManager {
public:
	FileManager();
	virtual ~FileManager();

	File *OpenFile(const char *name);

private:
	char *mLeadingPath;
};

#endif
