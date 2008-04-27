#include <resource/ShaderResource.h>


ShaderResource::ShaderResource(ResourceManager &m, const char *name)
:	Resource(m, name, RT_SHADER)
{

}

ShaderResource::~ShaderResource()
{

}

int ShaderResource::LoadFromStorage()
{
	return -1;
}
