#include <assert.h>
#include <resource/Resource.h>
#include <resource/ObjectResource.h>
#include <resource/MeshResource.h>
#include <resource/ShaderResource.h>
#include <resource/TextureResource.h>

Resource::Resource(ResourceManager &m, const char *name, enum ResourceType type)
:	mRefCount(0),
	mResourceManager(m),
	mName(name),
	mType(type)
{
}

Resource::~Resource()
{
}

int Resource::AddRef()
{
	return mRefCount++;
}

int Resource::RemoveRef()
{
	if (--mRefCount == 0) {
		delete this;
		return 0;
	}
	return mRefCount;
}

Resource *Resource::LoadResource(ResourceManager &m, const char *name, enum ResourceType type)
{
	Resource *r;

	switch (type) {
		case RT_OBJECT:
			r = new ObjectResource(m, name);
			break;
		case RT_MESH:
			r = new MeshResource(m, name);
			break;
		case RT_SHADER:
			r = new ShaderResource(m, name);
			break;
		case RT_TEXTURE:
			r = new TextureResource(m, name);
			break;
		default:
			assert(0);
	}

	// pull it from file/network/whatever
	if (r->LoadFromStorage() < 0) {
		delete r;
		assert(0); // for now crash
		return NULL;
	}

	return r;
}
