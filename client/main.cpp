#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math/Math.h>
#include <engine/Engine.h>
#include <engine/SceneNode.h>
#include <engine/Camera.h>
#include <resource/ResourceManager.h>
#include <renderer/Renderer.h>
#include <SDL.h>

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
    for (;;) {
//      SDL_Delay(100);

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
    Math::Vector3f point(0, 1.0, -2.0);

    Math::Matrix4x4 mS;
    Math::Matrix4x4 mX;
    Math::Matrix4x4 mY;
    Math::Matrix4x4 mZ;
    Math::Matrix4x4 mT;

    mS.SetScaling(Math::Vector3f(1.0, 1.0, 1.0));
    mX.SetRotationX(1.0f);
    mY.SetRotationY(0);
    mZ.SetRotationZ(0);
    mT.SetTranslation(Math::Vector3f(0, 0, 0));

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

    Math::Vector3f translatedPoint;
    translatedPoint = mTransform.Transform(point);

    std::cout << "translated point: \n";
    std::cout << translatedPoint << std::endl;
}

extern "C"
int main(int argc, char **argv)
{
    // mathtests
//  MathTest();

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
    bool done = false;
    // mousecontrol
    enum {
        MOUSE_CONTROL_CAMERA,
        MOUSE_CONTROL_WORLD,
    } mouseControl = MOUSE_CONTROL_CAMERA;
    uint8_t mouseDown = 0;
    int w, h;

    SDL_Surface *s = SDL_GetVideoSurface();
    w = s->w;
    h = s->h;

    uint64_t count = 0;
    while (!done) {
        if (e->InnerLoop() < 0)
            break;

        // deal with any pending messages
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    done = true;
                    break;
                case SDL_VIDEORESIZE:
                    Renderer::GetRenderer()->ResizeWindow(event.resize.w, event.resize.h);
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                            mouseControl = MOUSE_CONTROL_WORLD;
                            printf("world mouse control\n");
                            break;
                        case SDLK_c:
                            mouseControl = MOUSE_CONTROL_CAMERA;
                            printf("camera mouse control\n");
                            break;

                        case SDLK_n:
                            printf("center camera\n");
                            e->GetCamera()->SetPos(Math::Vector3f(0, 0, 0));
                            e->GetCamera()->SetZoom(1);
                            break;

                        case SDLK_d:
                            e->GetResources().DumpResources();
                            break;

                        case SDLK_r:
                            e->GetResources().ReloadShaders();
                            break;

                        case SDLK_q:
                            done = true;
                            break;
                        default:
                            ;
                    }
                    break;
                case SDL_KEYUP:
                    break;
                case SDL_MOUSEMOTION:
                    // get the current mouse state
                    mouseDown = SDL_GetMouseState(NULL, NULL);

                    //std::cout << "mouse move " << event.motion.x << " " << event.motion.y << std::endl;
                    if (mouseControl == MOUSE_CONTROL_CAMERA) {
                        if (mouseDown & SDL_BUTTON_LMASK) {
                            int deltax = (w/2 - event.motion.x);
                            int deltay = (h/2 - event.motion.y);
                            e->GetCamera()->Move(Math::Vector3f(-deltax / 256.0, deltay / 256.0, 0));
                            e->GetCamera()->PrintPosition();
                        }
                        if (mouseDown & SDL_BUTTON_RMASK) {
                            e->GetCamera()->Rotate(Math::Vector3f(event.motion.yrel / 256.0, event.motion.xrel / 256.0, 0));
                            e->GetCamera()->PrintPosition();
                        }
                        if (mouseDown & SDL_BUTTON_MMASK) {
                            e->GetCamera()->Rotate(Math::Vector3f(0, 0, event.motion.xrel / 256.0));
                            e->GetCamera()->PrintPosition();
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // get the current mouse state
                    mouseDown = SDL_GetMouseState(NULL, NULL);

                    if (mouseControl == MOUSE_CONTROL_CAMERA) {
                        if (mouseDown & SDL_BUTTON_LMASK && event.button.button == SDL_BUTTON_WHEELDOWN) {
                            e->GetCamera()->Move(Math::Vector3f(0, 0, 1.0f));
                            e->GetCamera()->PrintPosition();
                        }
                        if (mouseDown & SDL_BUTTON_LMASK && event.button.button == SDL_BUTTON_WHEELUP) {
                            e->GetCamera()->Move(Math::Vector3f(0, 0, -1.0f));
                            e->GetCamera()->PrintPosition();
                        }

                        if (mouseDown & SDL_BUTTON_RMASK && event.button.button == SDL_BUTTON_WHEELDOWN) {
                            e->GetCamera()->Zoom(0.1f);
                            //e->GetCamera()->Rotate(Math::Vector3f(0, 0, 0.1f));
                        }
                        if (mouseDown & SDL_BUTTON_RMASK && event.button.button == SDL_BUTTON_WHEELUP) {
                            e->GetCamera()->Zoom(-0.1f);
                            //e->GetCamera()->Rotate(Math::Vector3f(0, 0, -0.1f));
                        }
                    }
                    break;
            }
        }

        count++;
        if ((count % 100) == 0)
            printf("%lld frames drawn\n", count);
    }

    // XXX tear everything down
    delete e;
    delete r;

    return 0;
}
