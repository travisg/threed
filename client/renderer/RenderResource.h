#ifndef __RENDERRESOURCE_H
#define __RENDERRESOURCE_H

#include <resource/Resource.h>

class RenderResource
{
public:
	RenderResource() {}
	virtual ~RenderResource() {}

	static RenderResource *CreateRenderResource(Resource *r);

protected:
};

#endif
