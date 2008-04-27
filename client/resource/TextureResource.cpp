#include <resource/TextureResource.h>


TextureResource::TextureResource(ResourceManager &m, const char *name)
:	Resource(m, name, RT_TEXTURE)
{

}

TextureResource::~TextureResource()
{

}

int TextureResource::LoadFromStorage()
{
	return -1;
}
