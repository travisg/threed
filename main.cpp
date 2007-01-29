#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math/Math.h>
#include <renderer/Renderer.h>

#if 0
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>

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
#endif

void MathTest()
{
	Math::Vector4f f(1.0f, 2.0f, 3.0f, 4.0f), f2(2.0f, 3.0f, 4.0f, 5.0f), f3;

	f3 = f + f2;
	f3 += f2;

	std::cout << f << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << f.Length() << std::endl;
	std::cout << f.Dot(f2) << std::endl;

	Math::Matrix4x4f m;
	Math::Matrix4x4f m2;

	m.SetIdentity();
	m2.SetScaling(4.0f);

	std::cout << "identity matrix: " << std::endl;
	std::cout << m << std::endl;
	std::cout << "scaling matrix: " << std::endl;
	std::cout << m2 << std::endl;

	Math::Matrix4x4f m3 = m * m2;

	std::cout << "multiplied matrix: " << std::endl;
	std::cout << m3 << std::endl;
}

extern "C"
int main(int argc, char **argv)
{
	// mathtests
	MathTest();

	// create a screen
	if (Renderer::CreateRenderer() < 0) {
		std::cout << "unable to create renderer\n" << std::endl;
		return 1;
	}

	// main loop
	for (;;) {
		if (theRenderer->StartFrame() < 0)
			break;

		theRenderer->Draw();

		theRenderer->EndFrame();
	}

	// XXX tear everything down

	return 0;
}
