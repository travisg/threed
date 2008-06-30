#ifndef __RENDER_GLRENDERER_H
#define __RENDER_GLRENDERER_H

#include <renderer/Renderer.h>
#include <math/Math.h>

class GLRenderer : public Renderer 
{
public:
	/* Renderer class stuff */
	GLRenderer();
	virtual ~GLRenderer();

	virtual int StartFrame();
	virtual int EndFrame();

	virtual void SetProjMatrix(const Math::Matrix4x4 &mat);
	virtual void SetViewMatrix(const Math::Matrix4x4 &mat);
	virtual void SetWorldMatrix(const Math::Matrix4x4 &mat);
	virtual void UnsetWorldMatrix();

	virtual void ResizeWindow(int width, int height);

	/* our stuff */
	static GLRenderer *GetGLRenderer();

	virtual unsigned int GetWindowWidth() { return mWidth; };
	virtual unsigned int GetWindowHeight() { return mHeight; } ;

protected:
	virtual int Initialize();

private:
	struct SDL_Surface *mSurface;
	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mDepth;
	unsigned int mSize;
};

#endif