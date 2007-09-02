#include <iostream>
#include <renderer/Direct3D/D3DRenderer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <assert.h>

static D3DRenderer *sRenderer;

Renderer *Renderer::CreateRenderer()
{
	Renderer *r;

	r = new D3DRenderer();
	if (r->Initialize() < 0) {
		delete r;
		return NULL;
	}

	sRenderer = (D3DRenderer *)r;

	return r;
}

Renderer *Renderer::GetRenderer()
{
	return sRenderer;
}

D3DRenderer *D3DRenderer::GetD3DRenderer()
{
	return sRenderer;
}

D3DRenderer::D3DRenderer()
:	mSurface(NULL)
{
}

D3DRenderer::~D3DRenderer()
{
}

int D3DRenderer::Initialize()
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

	mSurface = SDL_SetVideoMode(mWidth, mHeight, mDepth, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (!mSurface) {
		std::cout << "error creating sdl window\n" << std::endl;
		return -1;
	}

	SDL_WM_SetCaption("ThreeD","ThreeD");

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

	return 0;
}

int D3DRenderer::StartFrame()
{
	// deal with any pending messages
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			return -1;
			break;
	}

	mD3DDevice->SetTransform(D3DTS_PROJECTION, (D3DXMATRIX *)&mProjectionMatrix);

	mD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,0), 1.0f, 0);
	mD3DDevice->BeginScene();

	return 0;
}

int D3DRenderer::EndFrame()
{
	mD3DDevice->EndScene();
	mD3DDevice->Present(NULL,NULL,NULL,NULL);

	return 0;
}

void D3DRenderer::SetWorldMatrix(const Math::Matrix4x4 &mat)
{
	mD3DDevice->SetTransform(D3DTS_WORLD, (D3DMATRIX *)&mat);
}

#if 0
void D3DRenderer::Draw(Engine::Geometry *geo)
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