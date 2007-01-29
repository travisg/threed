#ifndef __ENGINE_H
#define __ENGINE_H

class Renderer;

class Engine {
public:
	Engine();
	virtual ~Engine();

	void SetRenderer(Renderer *r);
	
	int InnerLoop();

private:
	Renderer *mRenderer;
};

#endif
