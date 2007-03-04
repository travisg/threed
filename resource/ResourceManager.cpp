#include <resource/ResourceManager.h>

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
