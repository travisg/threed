#ifndef __TEXTURE_H
#define __TEXTURE_H

#include <renderer/RenderResource.h>

class Resource;
class Renderer;

class Texture : public RenderResource
{
public:
	Texture();
	virtual ~Texture();

	static Texture *CreateFromResource(Resource *r);

	virtual void Bind(Renderer *r, int slot) = 0;

protected:
};

#endif
