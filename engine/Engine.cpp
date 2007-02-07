#include <engine/Engine.h>
#include <engine/SceneNode.h>
#include <engine/Geometry.h>
#include <renderer/Renderer.h>
#include <resource/loader/Loader.h>
#include <assert.h>

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

	if (mNodeTree) {
//		mNodeTree->Move(Math::Vector3(0.1f, 0, 0));
//		mNodeTree->Rotate(Math::Vector3(0, 0.01f, 0));

		mNodeTree->Render(mRenderer);
	}

	mRenderer->EndFrame();

	return 0;
}

void Engine::SetupDefaultScene()
{
	mNodeTree = new SceneNode(1);

	Geometry *geom;
#if 0
	geom = new Geometry();
	geom->SetDefaultGeometry();

	mNodeTree->SetChild(0, geom);
#endif

#if 1
	Loader *loader = Loader::CreateLoader("balls", Loader::RESOURCE_TYPE_MESH);
	assert(loader);
	geom = loader->ConstructGeometry();
	geom->Move(Math::Vector3(.5f, .5f, 1.0f));
	mNodeTree->SetChild(0, geom);
#endif

	mNodeTree->Move(Math::Vector3(0, 0, 1.0f));
}

}
