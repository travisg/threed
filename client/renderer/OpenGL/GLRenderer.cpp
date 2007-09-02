#include <iostream>
#include <renderer/OpenGL/GLRenderer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>

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

	glClearColor(0.0f,0.0f,0.0f,0.5f);							// Black Background
	glClearDepth(1.0f);											// Depth Buffer Setup
	glDepthFunc(GL_LEQUAL);										// The Type Of Depth Testing (Less Or Equal)
	glEnable(GL_DEPTH_TEST);									// Enable Depth Testing
	glShadeModel(GL_SMOOTH);									// Select Smooth Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Set Perspective Calculations To Most Accurate

#if 0
	// set up D3D
	mD3DObject = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS   present_parameters;
	ZeroMemory(&present_parameters, sizeof(present_parameters));
	present_parameters.Windowed = true;
	present_parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	present_parameters.EnableAutoDepthStencil = true;
	present_parameters.AutoDepthStencilFormat = D3DFMT_D24X8;
	present_parameters.hDeviceWindow = GetActiveWindow();
	present_parameters.BackBufferWidth = 800;
	present_parameters.BackBufferHeight = 600;
	present_parameters.BackBufferFormat = D3DFMT_UNKNOWN; // use the current format (windowed only)
	present_parameters.BackBufferCount = 1;
	present_parameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	present_parameters.MultiSampleQuality = 0;

	mD3DObject->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
           GetActiveWindow(), D3DCREATE_HARDWARE_VERTEXPROCESSING,
		   &present_parameters, &mD3DDevice);

	mProjectionMatrix.SetProjectionPerspective(D3DX_PI / 4.0f, (float) mWidth/mHeight, 1, 1000);
	mD3DDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(256,256,256));
	mD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	mD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	mD3DDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);

	// Fill in a light structure defining our light
	static D3DLIGHT9 light;
	ZeroMemory( &light, sizeof(D3DLIGHT9) );
	light.Type = D3DLIGHT_POINT;
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Ambient.r = 0.1f;
	light.Ambient.g = 0.1f;
	light.Ambient.b = 0.1f;
//	light.Specular = light.Diffuse;

	// Point lights have no direction but do have a position
	light.Position.x = 5;
	light.Position.y = 5;
	light.Position.z = 5;

	// Tell the device about the light and turn it on
	light.Attenuation0 = 1.0f;
	light.Range = 1000.0f;

	HRESULT hr;
	hr = mD3DDevice->SetLight( 0, &light );
	assert(SUCCEEDED(hr));
	hr = mD3DDevice->LightEnable( 0, TRUE );
	assert(SUCCEEDED(hr));
#endif
	return 0;
}

void GLRenderer::ResizeWindow(int width, int height)
{
//	assert(0);
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
//	glOrtho(0, mWidth, 0, mHeight, 1.0f, 100.0f);
	gluPerspective(45.0f,(GLfloat)(mWidth)/(GLfloat)(mHeight),1.0f,1000.0f);	// Calculate The Aspect Ratio Of The Window
//	dumpmatrix(GL_PROJECTION_MATRIX);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0f, 10.f, 10.f, 0, 0, 0, 0, 1, 0);

	static float rot = 0.0f;
	rot += 0.5f;

//	glLoadIdentity();
//	glTranslatef(1, 0, 0);
//	dumpmatrix(GL_MODELVIEW_MATRIX);

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
	glTranslatef(2.0f, 2.0f, 2.0f);
	glBegin(GL_TRIANGLES);								// Begin Drawing Triangles
	glColor3f (1.f, 0.f, 0.f);						// 1st Color (Red) ...
	glVertex3f( 0.0f, 1.0f, 0.0f);				// ...For The 1st Vertex
	glColor3f (0.f, 1.f, 0.f);						// 2nd Color (Green) ...
	glVertex3f(-1.0f,-1.0f, 1.0f);				// ...For The 2nd Vertex
	glColor3f (0.f, 0.f, 1.f);						// And 3rd Color (Blue) ...
	glVertex3f( 1.0f,-1.0f, 1.0f);				// ...For The 3rd Vertex
	glEnd();											// Done Drawing Triangles
	glPopMatrix();


	return 0;
}

int GLRenderer::EndFrame()
{
	glFlush();
	glFinish();

	SDL_GL_SwapBuffers();
	return 0;
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

#if 0
void GLRenderer::Draw(Engine::Geometry *geo)
{
   struct IDirect3DVertexBuffer9 *tri_buffer = NULL;  //data buffer which the Direct3D_device can draw from
   VOID* pData;                                //pointer to beginning of vertex buffer
   //actual data to be fed to the vertex buffer
   struct Vertex {
		FLOAT x, y, z;
		unsigned int diffuse;
		unsigned int pad[4];
   };
   static struct Vertex aTriangle[] = {
							 {-2.0f,1.0f,10.0f,D3DCOLOR_XRGB(0xff,0,0)},
                             {-3.0f,-1.0f,10.0f,D3DCOLOR_XRGB(0,0xff,0)},
                             {-1.0f,-1.0f,10.0f,D3DCOLOR_XRGB(0,0,0xff)},
                             {-0.0f,-2.0f,10.0f,D3DCOLOR_XRGB(0xff,0,0xff)},
                             {1.0f,-3.0f,10.0f,D3DCOLOR_XRGB(0xff,0xff,0xff)},
   };

//	aTriangle[2].y += 0.1f;

	mD3DDevice->CreateVertexBuffer(sizeof(aTriangle),D3DUSAGE_WRITEONLY,
										(D3DFVF_XYZ|D3DFVF_DIFFUSE),
										D3DPOOL_MANAGED,&tri_buffer,NULL);
	tri_buffer->Lock(0,sizeof(pData),(void**)&pData,0);
	memcpy(pData,aTriangle,sizeof(aTriangle));
	tri_buffer->Unlock();

	mD3DDevice->SetStreamSource(0,tri_buffer,0,sizeof(D3DVERTEX));
	mD3DDevice->DrawPrimitive(D3DPT_TRIANGLEFAN,0,3);
}
#endif