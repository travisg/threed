#ifndef __RENDERER_H
#define __RENDERER_H

class Renderer
{
public:
	static int CreateRenderer();

	virtual int StartFrame() = 0;
	virtual int EndFrame() = 0;
	virtual void Draw() = 0;

protected:
	Renderer(void);
	virtual ~Renderer(void);
	virtual int Initialize() = 0;
};

extern Renderer *theRenderer;

#endif
