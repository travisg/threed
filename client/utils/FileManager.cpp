#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <utils/FileManager.h>
#include <utils/HostFile.h>

FileManager::FileManager()
:	mLeadingPath(0)
{
	// XXX hack for now
	mLeadingPath = new char[3];
	strcpy(mLeadingPath, "../");
}

FileManager::~FileManager()
{
	if (mLeadingPath)
		delete[] mLeadingPath;
}

File *FileManager::OpenFile(const char *name)
{
	HostFile *file = new HostFile();

	// XXX totally len unsafe
	char path[1024];
	strcpy(path, mLeadingPath);
	strcat(path, name);
	if (file->Open(path) < 0) {
		file->RemoveRef();
		return 0;
	}

	return file;
}
