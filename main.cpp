#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <math/Vector4.h>

SDL_Surface *thescreen;

class Surface {
public:
	Surface() {}
	virtual ~Surface() {}

	// accessors
	size_t GetSize() { return mSize; }
	unsigned int GetWidth() { return mWidth; }
	unsigned int GetHeight() { return mHeight; }
	unsigned int GetDepth() { return mDepth; }

	virtual void *Pixels() = 0;
	virtual void Lock() {}
	virtual void UnLock() {}

	// operations
	void Fill(unsigned int color);

protected:
	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mDepth;
	size_t mSize;
};

void Surface::Fill(unsigned int color)
{
	Lock();

	unsigned int *ptr = (unsigned int *)Pixels();
	for (unsigned int i = 0; i < mSize / 4; i++) {
		ptr[i] = color;
	}

	UnLock();
}

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

void MathTest()
{
	Math::Vector4f f, f2, f3;

	f3 = f - f2;
	f3 += f2;

	printf("%f\n", f.Length());
	printf("%f\n", f.Dot(f2));
}

extern "C"
int main(int argc, char **argv)
{

	// initialize SDL
	printf("initializing SDL\n");
	atexit(SDL_Quit);
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

	// create a window
	Window win;
	if (win.CreateWindow(800, 600, 32) < 0) {
		printf("error creating sdl window\n");
		return 1;
	}

	// create a display thread
	SDL_CreateThread((int (*)(void *))&display_thread_entry, &win);

	// mathtests
	MathTest();

	// enter the message loop
	bool quit = false;
	while (!quit) {
		SDL_Event event;
		SDL_WaitEvent(&event);

		switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
		}
	}

	printf("exiting\n");

	return 0;
}
