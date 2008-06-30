#include <resource/TextureResource.h>
#include <SDL_image.h>

TextureResource::TextureResource(ResourceManager &m, const char *name)
:	Resource(m, name, RT_TEXTURE),
	m_Surface(0)
{

}

TextureResource::~TextureResource()
{

}

int TextureResource::LoadFromStorage()
{
	// open and validate the mesh is present
	char path[4096];

	sprintf(path, "resources/texture/%s.tga", mName.c_str());

	m_Surface = IMG_Load(path);
	if (!m_Surface)
		return -1;

	return 0;
}
