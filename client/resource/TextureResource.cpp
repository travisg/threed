#include <resource/TextureResource.h>
#include <SDL_image.h>

static const char* extensions[] = {
	"tga",
	"jpg",
	"jpeg",
	0
};

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

	const char **ptr;
	for (ptr = extensions; ptr != 0; ptr++) {
		sprintf(path, "resources/texture/%s.%s", mName.c_str(), *ptr);

		m_Surface = IMG_Load(path);
		if (m_Surface)
			break;
	}
	if (!m_Surface)
		return -1;

	return 0;
}
