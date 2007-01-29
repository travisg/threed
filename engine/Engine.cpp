#include <engine/Engine.h>
#include <renderer/Renderer.h>

Engine::Engine()
:	mRenderer(0)
{
}

Engine::~Engine()
{
}

void Engine::SetRenderer(Renderer *r)
{
	mRenderer = r;
}

int Engine::InnerLoop()
{
	if (mRenderer->StartFrame() < 0)
		return -1;

	mRenderer->Draw();

	mRenderer->EndFrame();

	return 0;
}
