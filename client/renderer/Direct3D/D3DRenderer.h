#ifndef __RENDER_D3DRENDERER_H
#define __RENDER_D3DRENDERER_H

#include <renderer/Renderer.h>
#include <math/Math.h>

class D3DRenderer : public Renderer 
{
public:
	/* Renderer class stuff */
	D3DRenderer();
	virtual ~D3DRenderer();

	virtual int StartFrame();
	virtual int EndFrame();

	virtual void SetWorldMatrix(const Math::Matrix4x4 &mat);

	/* our stuff */
	static D3DRenderer *GetD3DRenderer();

	struct IDirect3DDevice9 *GetD3DDevice() { return mD3DDevice; }


protected:
	virtual int Initialize();

private:
	struct SDL_Surface *mSurface;
	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mDepth;
	unsigned int mSize;

	Math::Matrix4x4 mProjectionMatrix;

	struct IDirect3D9 *mD3DObject;
	struct IDirect3DDevice9 *mD3DDevice;
};

#endif