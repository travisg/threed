#include <assert.h>
#include <stdio.h>
#include <iostream>

#include <resource/loader/Loader.h>
#include <resource/loader/MeshLoader.h>
#include <resource/loader/ObjectLoader.h>

Loader::Loader(ResourceManager &m)
:	mResourceManager(m)
{
}

Loader::~Loader()
{
}

Loader *Loader::CreateLoader(ResourceManager &m, const char *resource, enum ResourceType type)
{
	Loader *loader;

	switch (type) {
		case RT_OBJECT:
			loader = new ObjectLoader(m);
			break;
		case RT_MESH:
			loader = new MeshLoader(m);
			break;
		case RT_SHADER:
			assert(0);
			break;
		case RT_TEXTURE:
			assert(0);
			break;
		default:
			assert(0);
	}

	return loader;
}
