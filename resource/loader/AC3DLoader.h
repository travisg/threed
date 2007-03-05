#ifndef __RESOURCE_AC3DLOADER_H
#define __RESOURCE_AC3DLOADER_H

#include <resource/loader/Loader.h>
#include <stdio.h>

struct AC3DObject;

class AC3DLoader : public Loader {
public:
	AC3DLoader();
	virtual ~AC3DLoader();

	virtual int OpenResource(const char *resource);

	virtual Engine::Spatial *ConstructSpatial();

private:
	int ParseObject(AC3DObject *parent);

	FILE *m_fp;

	// object data

	AC3DObject *m_objects;
};

#endif
