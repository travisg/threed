#ifndef __RENDERRESOURCE_H
#define __RENDERRESOURCE_H

#include <resource/Resource.h>

class RenderResource
{
public:
	RenderResource();
	virtual ~RenderResource();

	void SetResource(Resource *r);

	static RenderResource *CreateRenderResource(Resource *r);

protected:
	Resource *m_Resource;
};

#endif
