#include <assert.h>
#include <stdio.h>
#include <iostream>

#include <resource/loader/Loader.h>
#include <resource/loader/MeshLoader.h>
#include <resource/loader/AC3DLoader.h>

Loader::Loader()
{
}

Loader::~Loader()
{
}

Loader *Loader::CreateLoader(const char *resource, enum ResourceType type)
{
	Loader *loader;

	switch (type) {
		case RT_MESH:
			loader = new MeshLoader();

			if (loader->OpenResource(resource) < 0) {
				delete loader;
				std::cerr << "CreateLoader: failed to open mesh resource " << resource << std::endl;
				return 0;
			}
#if 0
			loader = new AC3DLoader();

			if (loader->OpenResource(resource) < 0) {
				delete loader;
				std::cerr << "CreateLoader: failed to open mesh resource " << resource << std::endl;
				return 0;
			}
#endif
			break;
		default:
			assert(0);
	}

	return loader;
}
