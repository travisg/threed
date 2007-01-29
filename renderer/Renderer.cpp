#include <stdio.h>
#include <renderer/Renderer.h>

#define USE_D3D 1

#if USE_D3D
#include <renderer/D3DRenderer.h>
#endif

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

Renderer *Renderer::CreateRenderer()
{
	Renderer *r;
#if USE_D3D

	r = new D3DRenderer();
	if (r->Initialize() < 0) {
		delete r;
		return NULL;
	}

#endif

	return r;
}
