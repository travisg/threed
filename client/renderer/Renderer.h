#ifndef __RENDERER_H
#define __RENDERER_H

#include <math/Matrix4x4.h>

class Renderer
{
public:
	Renderer() {};
	virtual ~Renderer() {};

	static Renderer *CreateRenderer();
	static Renderer *GetRenderer();

	virtual int StartFrame() = 0;
	virtual int EndFrame() = 0;

	virtual void SetProjMatrix(const Math::Matrix4x4 &mat) = 0;
	virtual void SetViewMatrix(const Math::Matrix4x4 &mat) = 0;

	virtual void SetWorldMatrix(const Math::Matrix4x4 &mat) = 0;
	virtual void UnsetWorldMatrix() = 0;

	virtual void ResizeWindow(int width, int height) = 0;

	virtual unsigned int GetWindowWidth() = 0;
	virtual unsigned int GetWindowHeight() = 0;

protected:
	virtual int Initialize() = 0;
};

#endif
