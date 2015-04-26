#include <utils/FileManager.h>

#include <cstring>
#include <utils/HostFile.h>

FileManager::FileManager()
{
    mLeadingPath = "../";
}

FileManager::~FileManager()
{
}

File *FileManager::OpenFile(const char *name)
{
    HostFile *file = new HostFile();

    std::string path;

    path = mLeadingPath + name;
    if (file->Open(path.c_str()) < 0) {
        file->RemoveRef();
        return 0;
    }

    return file;
}
