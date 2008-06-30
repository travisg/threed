#ifndef __TEXTURE_RESOURCE_H
#define __TEXTURE_RESOURCE_H

#include <resource/Resource.h>

struct SDL_Surface;

class TextureResource : public Resource {
private:
	TextureResource(ResourceManager &m, const char *name);
	~TextureResource();

	virtual int LoadFromStorage();

public:


private:
	SDL_Surface *m_Surface;

	friend class Resource;
};

#endif
