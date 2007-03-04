#include <engine/Engine.h>
#include <engine/SceneNode.h>
#include <engine/Geometry.h>
#include <renderer/Renderer.h>
#include <resource/loader/Loader.h>
#include <assert.h>

namespace Engine {

Engine::Engine()
:	mRenderer(0)
{
	mNodeTree = new SceneNode;
}

Engine::~Engine()
{
	delete mNodeTree;
}

void Engine::SetRenderer(Renderer *r)
{
	mRenderer = r;
}

int Engine::InnerLoop()
{
	if (mRenderer->StartFrame() < 0)
		return -1;

//	mNodeTree->Move(Math::Vector3(0, 0, 0.001f));
//	mNodeTree->Rotate(Math::Vector3(0.01f, 0.01f, 0.02f));

	mNodeTree->UpdateTransform(false);
	mNodeTree->Render(mRenderer);

	mRenderer->EndFrame();

	return 0;
}

void Engine::SetupDefaultScene()
{
#if 0
	geom = new Geometry();
	geom->SetDefaultGeometry();

	mNodeTree->SetChild(geom);
#endif

	Loader *loader;
	SceneNode *node;
	Spatial *spatial;

#if 1
	// the balls get to be a high level construct
	loader = Loader::CreateLoader("balls", Loader::RESOURCE_TYPE_MESH);
	assert(loader);
	spatial = loader->ConstructSpatial();
	spatial->Move(Math::Vector3(.5f, .5f, 15.0f));
	mNodeTree->AddChild(spatial);
	delete loader;

	// create a scene node for the next bits
	node = new SceneNode();
	node->Move(Math::Vector3(.5f, .5f, 5.0f));
	mNodeTree->AddChild(node);

	loader = Loader::CreateLoader("meh", Loader::RESOURCE_TYPE_MESH);
	assert(loader);
	spatial = loader->ConstructSpatial();
	spatial->Move(Math::Vector3(-2.0f, 0, 0));
	node->AddChild(spatial);
	delete loader;

	loader = Loader::CreateLoader("dude", Loader::RESOURCE_TYPE_MESH);
	assert(loader);
	spatial = loader->ConstructSpatial();
	spatial->Move(Math::Vector3(2.0f, 0, 0));
	node->AddChild(spatial);
	delete loader;

	loader = Loader::CreateLoader("plane", Loader::RESOURCE_TYPE_MESH);
	assert(loader);
	spatial = loader->ConstructSpatial();
	spatial->Move(Math::Vector3(-1.0f, -3.0f, 2.0f));
	spatial->Rotate(Math::Vector3(0.0f, 0.1f, -0.3f));
	spatial->Scale(0.5f);
	node->AddChild(spatial);
	delete loader;

#endif

	mNodeTree->Move(Math::Vector3(0, 0, 1.0f));
}

}
