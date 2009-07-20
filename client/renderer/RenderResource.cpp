#include <assert.h>
#include <resource/Resource.h>
#include <renderer/RenderResource.h>
#include <renderer/Mesh.h>
#include <renderer/Program.h>
#include <renderer/Texture.h>

RenderResource::RenderResource()
:	m_Resource(NULL)
{
}

RenderResource::~RenderResource()
{
	if (m_Resource)
		m_Resource->RemoveRef();
}

void RenderResource::SetResource(Resource *r)
{
	assert(!m_Resource);

	r->AddRef();
	m_Resource = r;
}

RenderResource *RenderResource::CreateRenderResource(Resource *r)
{
	RenderResource *resource = NULL;

	switch (r->GetType()) {
		case RT_MESH:
			resource = Mesh::CreateFromResource(r);
			break;
		case RT_TEXTURE:
			resource = Texture::CreateFromResource(r);
			break;
		case RT_SHADER:
			resource = Program::CreateFromResource(r);
			break;
		case RT_OBJECT:
			// do nothing here
			break;
		default:
			assert(0);
	}

	return resource;
}

