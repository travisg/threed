#ifndef __ENGINE_H
#define __ENGINE_H

class Renderer;

namespace Engine {

class SceneNode;

class Engine {
public:
	Engine();
	virtual ~Engine();

	void SetRenderer(Renderer *r);
	void SetupDefaultScene();

	int InnerLoop();

private:
	Renderer *mRenderer;
	SceneNode *mNodeTree;
};

}

#endif
