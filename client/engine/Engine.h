#ifndef __ENGINE_H
#define __ENGINE_H

class Renderer;
class ResourceManager;

namespace Engine {

class SceneNode;
class Camera;
class Spatial;

class Engine {
public:
	Engine();
	virtual ~Engine();

	void SetRenderer(Renderer &r);
	void SetupDefaultScene();

	// accessors
	Renderer &GetRenderer() { return *mRenderer; }
	ResourceManager &GetResources() { return *mResources; }

	int InnerLoop();

	// debug stuff
	SceneNode *GetRootNode() { return mNodeTree; }
	Camera *GetCamera() { return mMainCamera; }

private:
	Renderer *mRenderer;
	ResourceManager *mResources;
	SceneNode *mNodeTree;
	Camera *mMainCamera;
	Spatial *mCameraTarget;
};

extern Engine *gEngine;

}

#endif
