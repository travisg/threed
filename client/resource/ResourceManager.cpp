#include <assert.h>
#include <resource/ResourceManager.h>
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
    Resource *r = Resource::LoadResource(*this, name, type);
    if (r) {
        AddResource(r);
        r->AddRef();
    }

    return r;

}

void ResourceManager::DumpResources()
{
    std::cout << "Resource List" << std::endl;
    ResourceListIterator i;
    for (ResourceListIterator i = mResources.begin(); i != mResources.end(); i++) {
        Resource *r = (*i);
        std::cout << "'" << r->mName << "' type " << r->mType << " count " << r->mRefCount << std::endl;
    }
}

void ResourceManager::ReloadShaders()
{
    ResourceListIterator i;
    for (ResourceListIterator i = mResources.begin(); i != mResources.end(); i++) {
        Resource *r = (*i);

        if (r->GetType() == RT_SHADER) {
            r->LoadFromStorage();
        }
    }
}