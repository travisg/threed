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

	virtual void SetWorldMatrix(const Math::Matrix4x4 &mat);
	virtual void UnsetWorldMatrix();

	virtual void ResizeWindow(int width, int height);

	/* our stuff */
	static GLRenderer *GetGLRenderer();

//	struct IDirect3DDevice9 *GetD3DDevice() { return mD3DDevice; }


protected:
	virtual int Initialize();

private:
	struct SDL_Surface *mSurface;
	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mDepth;
	unsigned int mSize;

//	struct IDirect3D9 *mD3DObject;
//	struct IDirect3DDevice9 *mD3DDevice;
};

#endif