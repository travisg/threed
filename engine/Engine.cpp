#include <engine/Engine.h>
#include <engine/SceneNode.h>
#include <engine/Geometry.h>
#include <renderer/Renderer.h>

namespace Engine {

Engine::Engine()
:	mRenderer(0),
	mNodeTree(0)
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

	if (mNodeTree)
		mNodeTree->Render(mRenderer);

	mRenderer->EndFrame();

	return 0;
}

void Engine::SetupDefaultScene()
{
	mNodeTree = new SceneNode(1);

	Geometry *geom = new Geometry();
	const float vertices[] = { 0.0f, 1.0f, 2.0f };
	
	geom->SetVertices(vertices, 3);

	mNodeTree->SetChild(0, geom);
}

}
