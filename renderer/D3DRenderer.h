#ifndef __RENDER_D3DRENDERER_H
#define __RENDER_D3DRENDERER_H

#include <renderer/Renderer.h>

class D3DRenderer : public Renderer 
{
public:
	virtual int StartFrame();
	virtual int EndFrame();
	virtual void Draw();

	D3DRenderer();
	virtual ~D3DRenderer();

protected:
	virtual int Initialize();

private:
	struct SDL_Surface *mSurface;
	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mDepth;
	unsigned int mSize;

	struct IDirect3D9 *mD3DObject;
	struct IDirect3DDevice9 *mD3DDevice;
};

#endif