#include <iostream>
#include <renderer/OpenGL/GLRenderer.h>
#include <SDL.h>
#include <SDL_thread.h>

#include <assert.h>
#include "glinc.h"

static GLRenderer *sRenderer;

Renderer *Renderer::CreateRenderer()
{
	Renderer *r;

	r = new GLRenderer();
	if (r->Initialize() < 0) {
		delete r;
		return NULL;
	}

	sRenderer = (GLRenderer *)r;

	return r;
}

Renderer *Renderer::GetRenderer()
{
	return sRenderer;
}

GLRenderer *GLRenderer::GetGLRenderer()
{
	return sRenderer;
}

GLRenderer::GLRenderer()
:	mSurface(NULL)
{
}

GLRenderer::~GLRenderer()
{
}

int GLRenderer::Initialize()
{
	// set up sdl
	std::cout << "initializing SDL" << std::endl;
	atexit(SDL_Quit);
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

	// create a window
	mWidth = 800;
	mHeight = 600;
	mDepth = 32;
	mSize = mWidth * mHeight * (mDepth / 8);

	int ret = SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );								// In order to use SDL_OPENGLBLIT we have to
	ret = SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );							// set GL attributes first
	ret = SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	ret = SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
	ret = SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );							// colors and doublebuffering

	mSurface = SDL_SetVideoMode(mWidth, mHeight, mDepth, SDL_HWSURFACE|SDL_OPENGLBLIT|SDL_RESIZABLE);
	if (!mSurface) {
		std::cout << "error creating sdl/gl window\n" << std::endl;
		return -1;
	}

	SDL_FillRect(mSurface, NULL, SDL_MapRGBA(mSurface->format,0,0,0,0));	

	SDL_WM_SetCaption("ThreeD","ThreeD");

	InitGLExt();

	const char *str = (const char *)glGetString(GL_VERSION);
	std::cout << "GL Version String: " << str << std::endl;

	str = (const char *)glGetString(GL_EXTENSIONS);
	std::cout << "GL Extension String: " << str << std::endl;

	str = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cout << "GL Shader Version String: " << str << std::endl;

	glClearColor(0.0f,0.0f,0.0f,0.5f);							// Black Background
//	glClearDepth(1.0f);											// Depth Buffer Setup
	glDepthFunc(GL_LEQUAL);										// The Type Of Depth Testing (Less Or Equal)
	glEnable(GL_DEPTH_TEST);									// Enable Depth Testing
//	glShadeModel(GL_SMOOTH);									// Select Smooth Shading
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Set Perspective Calculations To Most Accurate

	return 0;
}

void GLRenderer::ResizeWindow(int width, int height)
{
//	assert(0);
	std::cout << __FUNCTION__ << " " << width << " " << height << std::endl;
	mWidth = width;
	mHeight = height;
}

static void dumpmatrix(GLenum mat)
{
	float m[16];
	glGetFloatv(mat, m);
	Math::Matrix4x4 m4(m);
	std::cout << m4 << std::endl;
}

int GLRenderer::StartFrame()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0,0,(GLsizei)(mWidth),(GLsizei)(mHeight));						// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	dumpmatrix(GL_PROJECTION_MATRIX);
//	glOrtho(0, mWidth, 0, mHeight, 1.0f, 1000.0f);
//	gluPerspective(45.0f,(GLfloat)(mWidth)/(GLfloat)(mHeight),1.0f,1000.0f);	// Calculate The Aspect Ratio Of The Window
//	dumpmatrix(GL_PROJECTION_MATRIX);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

//	dumpmatrix(GL_MODELVIEW_MATRIX);
//	gluLookAt(10.0f, 10.f, 10.f, 0, 0, 0, 0, 1, 0);
//	dumpmatrix(GL_MODELVIEW_MATRIX);

//	glLoadIdentity();
//	glTranslatef(1, 0, 0);
//	dumpmatrix(GL_MODELVIEW_MATRIX);

	return 0;
}

int GLRenderer::EndFrame()
{
#if 0
	static float rot = 0.0f;
	rot += 0.5f;

	glPushMatrix();
	glRotatef(rot, 1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);								// Begin Drawing Triangles
	glColor3f (1.f, 0.f, 0.f);						// 1st Color (Red) ...
	glVertex3f( 0.0f, 1.0f, 0.0f);				// ...For The 1st Vertex
	glColor3f (0.f, 1.f, 0.f);						// 2nd Color (Green) ...
	glVertex3f(-1.0f,-1.0f, 1.0f);				// ...For The 2nd Vertex
	glColor3f (0.f, 0.f, 1.f);						// And 3rd Color (Blue) ...
	glVertex3f( 1.0f,-1.0f, 1.0f);				// ...For The 3rd Vertex
	glEnd();											// Done Drawing Triangles
	glPopMatrix();

	glPushMatrix();
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(-rot, 1.0f, 1.0f, 1.0f);
	//glTranslatef(2.0f, 2.0f, 2.0f);
	glBegin(GL_TRIANGLES);								// Begin Drawing Triangles
	glColor3f (1.f, 0.f, 0.f);						// 1st Color (Red) ...
	glVertex3f( 0.0f, 1.0f, 0.0f);				// ...For The 1st Vertex
	glColor3f (0.f, 1.f, 0.f);						// 2nd Color (Green) ...
	glVertex3f(-1.0f,-1.0f, 1.0f);				// ...For The 2nd Vertex
	glColor3f (0.f, 0.f, 1.f);						// And 3rd Color (Blue) ...
	glVertex3f( 1.0f,-1.0f, 1.0f);				// ...For The 3rd Vertex
	glEnd();											// Done Drawing Triangles
	glPopMatrix();
#endif

	//glFlush();
	//glFinish();

	SDL_GL_SwapBuffers();
	return 0;
}

void GLRenderer::SetProjMatrix(const Math::Matrix4x4 &mat)
{
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(mat);
	glMatrixMode(GL_MODELVIEW);
}

void GLRenderer::SetViewMatrix(const Math::Matrix4x4 &mat)
{
	glMultMatrixf(mat);
}

void GLRenderer::SetWorldMatrix(const Math::Matrix4x4 &mat)
{
	glPushMatrix();
	glMultMatrixf(mat);
}

void GLRenderer::UnsetWorldMatrix()
{
	glPopMatrix();
}
