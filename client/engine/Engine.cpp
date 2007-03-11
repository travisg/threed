#include <engine/Engine.h>
#include <engine/SceneNode.h>
#include <engine/Geometry.h>
#include <renderer/Renderer.h>
#include <resource/ResourceManager.h>
#include <assert.h>

namespace Engine {

// the one and only game engine
Engine *gEngine;

Engine::Engine()
:	mRenderer(0),
	mResources(0)
{
	mNodeTree = new SceneNode;
	mResources = new ResourceManager;

	assert(!gEngine);
	gEngine = this;
}

Engine::~Engine()
{
	delete mNodeTree;
	gEngine = 0;
}

void Engine::SetRenderer(Renderer &r)
{
	assert(!mRenderer);
	mRenderer = &r;
}

int Engine::InnerLoop()
{
	if (mRenderer->StartFrame() < 0)
		return -1;

//	mNodeTree->Move(Math::Vector3(0, 0, 0.001f));
	mNodeTree->Rotate(Math::Vector3(0.01f, 0.01f, 0.01f));

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

	SceneNode *node;
	Spatial *spatial;

#if 1
	// the balls get to be a high level construct
	spatial = mResources->ConstructModel("balls");
	assert(spatial);
	spatial->Move(Math::Vector3(.5f, .5f, 15.0f));
	mNodeTree->AddChild(spatial);

	// create a scene node for the next bits
	node = new SceneNode();
	node->Move(Math::Vector3(.5f, .5f, 5.0f));
	mNodeTree->AddChild(node);

	spatial = mResources->ConstructModel("meh");
	assert(spatial);
	spatial->Move(Math::Vector3(-2.0f, 0, 0));
	node->AddChild(spatial);

	spatial = mResources->ConstructModel("dude");
	assert(spatial);
	spatial->Move(Math::Vector3(2.0f, 0, 0));
	node->AddChild(spatial);

	spatial = mResources->ConstructModel("plane");
	assert(spatial);
	spatial->Move(Math::Vector3(-1.0f, -3.0f, 2.0f));
	spatial->Rotate(Math::Vector3(0.0f, 0.1f, -0.3f));
	spatial->Scale(0.5f);
	node->AddChild(spatial);

	spatial = mResources->ConstructModel("meh-greeble-tri");
	assert(spatial);
	spatial->Move(Math::Vector3(0.0f, 1.0f, 0));
	node->AddChild(spatial);

#endif

	mNodeTree->Move(Math::Vector3(0, 0, 1.0f));
}

}
