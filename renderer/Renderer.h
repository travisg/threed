#ifndef __RENDERER_H
#define __RENDERER_H

class Renderer
{
public:
	Renderer(void) = 0;
	virtual ~Renderer(void) = 0;

	static Renderer *CreateRenderer();

	virtual int StartFrame() = 0;
	virtual int EndFrame() = 0;
	virtual void Draw() = 0;

protected:
	virtual int Initialize() = 0;
};

#endif
