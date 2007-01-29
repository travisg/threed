#include <stdio.h>
#include <renderer/Renderer.h>

#define USE_D3D 1

#if USE_D3D
#include <renderer/D3DRenderer.h>
#endif

/* global renderer */
Renderer *theRenderer;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

int Renderer::CreateRenderer()
{
	Renderer *r;
#if USE_D3D

	r = new D3DRenderer();
	if (r->Initialize() < 0) {
		delete r;
		return -1;
	}

#endif

	theRenderer = r;

	return 0;
}
