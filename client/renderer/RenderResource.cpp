#include <assert.h>
#include <resource/Resource.h>
#include <renderer/RenderResource.h>
#include <renderer/Mesh.h>
#include <renderer/Program.h>

RenderResource *RenderResource::CreateRenderResource(Resource *r)
{
	RenderResource *resource = NULL;

	switch (r->GetType()) {
		case RT_MESH:
			resource = Mesh::CreateMeshFromResource(r);
			break;
		case RT_TEXTURE:
			break;
		case RT_SHADER:
			resource = Program::CreateProgramFromResource(r);
			break;
		case RT_OBJECT:
			// do nothing here
			break;
		default:
			assert(0);
	}

	return resource;
}

