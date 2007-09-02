#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math/Math.h>
#include <engine/Engine.h>
#include <renderer/Renderer.h>
#include <SDL/SDL.h>

#if 0
class Window : public Surface {
public:
	Window() {}
	virtual ~Window() {}

	int CreateWindow(unsigned int width, unsigned int height, unsigned int depth);

	virtual void *Pixels() { return mSurface->pixels; }
	virtual void Lock() { SDL_LockSurface(mSurface); }
	virtual void UnLock() { SDL_UnlockSurface(mSurface); }

	virtual void Flip() { SDL_Flip(mSurface); }

	// SDL specific stuff
	SDL_Surface *GetSDLSurface() { return mSurface; }

private:
	SDL_Surface *mSurface;
};

int Window::CreateWindow(unsigned int width, unsigned int height, unsigned int depth)
{
	mSurface = SDL_SetVideoMode(width, height, depth, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (!mSurface) {
		printf("error creating sdl window\n");
		return -1;
	}

	mWidth = width;
	mHeight = height;
	mDepth = depth;
	mSize = width * height * (depth / 8);

	SDL_WM_SetCaption("ThreeD","ThreeD");

	return 0;
}

// main display loop
static int display_thread_entry(Window *win)
{
	int i = 0;
	for(;;) {
//		SDL_Delay(100);
	
		// is the surface dirty?
		// redraw the entire window
		win->Lock();
			
		win->Fill(rand());
			
		win->UnLock();
		win->Flip();

		i++;
		if ((i % 32) == 0)
			printf("%d flips\n", i);
	}

	return 0;
}
#endif

void MathTest()
{
	Math::Vector3 point(0, 1.0, -2.0);

	Math::Matrix4x4 mS;
	Math::Matrix4x4 mX;
	Math::Matrix4x4 mY;
	Math::Matrix4x4 mZ;
	Math::Matrix4x4 mT;

	mS.SetScaling(Math::Vector3(1.0, 1.0, 1.0));
	mX.SetRotationX(1.0f);
	mY.SetRotationY(0);
	mZ.SetRotationZ(0);
	mT.SetTranslation(Math::Vector3(0, 0, 0));

	std::cout << "scaling matrix: \n";
	std::cout << mS << std::endl;

	std::cout << "translation matrix: \n";
	std::cout << mT << std::endl;

	std::cout << "x rotation matrix: \n";
	std::cout << mX << std::endl;
	std::cout << "y rotation matrix: \n";
	std::cout << mY << std::endl;
	std::cout << "z rotation matrix: \n";
	std::cout << mZ << std::endl;

	Math::Matrix4x4 mTransform = mT * mZ * mY * mX * mS;
	std::cout << "transformation matrix: \n";
	std::cout << mTransform << std::endl;

	std::cout << "point: \n";
	std::cout << point << std::endl;

	Math::Vector3 translatedPoint;
	translatedPoint = mTransform.Transform(point);

	std::cout << "translated point: \n";
	std::cout << translatedPoint << std::endl;
}

extern "C"
int main(int argc, char **argv)
{
	// mathtests
	MathTest();

	// create a screen
	Renderer *r = Renderer::CreateRenderer();
	if (!r) {
		std::cout << "unable to create renderer\n" << std::endl;
		return 1;
	}

	// create a game engine
	Engine::Engine *e = new Engine::Engine();
	e->SetRenderer(*r);

	e->SetupDefaultScene();

	// main loop
	for (;;) {
		// deal with any pending messages
		SDL_Event event;
		if (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				break;
			case SDL_VIDEORESIZE:
				Renderer::GetRenderer()->ResizeWindow(event.resize.w, event.resize.h);
				break;
			case SDL_KEYDOWN:
				printf("keydown\n");
				break;
			case SDL_KEYUP:
				printf("keyup\n");
				break;
			}
		}

		if (e->InnerLoop() < 0)
			break;
	}

	// XXX tear everything down
	delete e;
	delete r;

	return 0;
}
