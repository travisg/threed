#ifndef __PROGRAM_H
#define __PROGRAM_H

#include <renderer/RenderResource.h>

class Resource;
class Renderer;

class Program : public RenderResource
{
public:
	Program();
	virtual ~Program();

	static Program *CreateFromResource(Resource *r);

	virtual void Bind(Renderer *r) = 0;

	virtual int Reload() = 0;

protected:
};

#endif
