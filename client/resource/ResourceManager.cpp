#include <resource/ResourceManager.h>
#include <resource/loader/Loader.h>

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::AddResource(Resource *r)
{
	r->AddRef();
	mResources.push_front(r);
}

void ResourceManager::RemoveResource(Resource *r)
{
	mResources.remove(r);

	r->RemoveRef();
}

Engine::Spatial *ResourceManager::ConstructModel(const char *name)
{
	Loader *loader = Loader::CreateLoader(name, RT_MESH);
	if (!loader) {
		return 0;
	}
	Engine::Spatial *spatial = loader->ConstructSpatial();
	delete loader;

	return spatial;
}

