#ifndef __RENDERER_H
#define __RENDERER_H

#include <math/Matrix4x4.h>

class Renderer
{
public:
	Renderer() = 0;
	virtual ~Renderer() = 0;

	static Renderer *CreateRenderer();
	static Renderer *GetRenderer();

	virtual int StartFrame() = 0;
	virtual int EndFrame() = 0;

	virtual void SetWorldMatrix(const Math::Matrix4x4 &mat) = 0;	

protected:
	virtual int Initialize() = 0;
};

#endif
