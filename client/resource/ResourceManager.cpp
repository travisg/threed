#include <assert.h>
#include <resource/ResourceManager.h>
#include <resource/loader/Loader.h>
#include <resource/loader/MeshLoader.h>
#include <resource/MeshResource.h>
#include <resource/ShaderResource.h>
#include <resource/TextureResource.h>
#include <resource/ObjectResource.h>

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

Resource *ResourceManager::GetResource(const char *name, ResourceType type)
{
	// XXX make better
	ResourceListIterator i;
	for (ResourceListIterator i = mResources.begin(); i != mResources.end(); i++) {
		if ((*i)->mType == type && (*i)->mName.compare(name) == 0) {
			(*i)->AddRef();
			return (*i);
		}
	} 

	// couldn't find it, build a new one
	Loader *loader = Loader::CreateLoader(*this, name, type);
	if (!loader)
		return NULL;

	Resource *r = loader->LoadResource(name);
	if (r) {
		AddResource(r);
	}

	delete loader;

	r->AddRef();

	return r;
}
