#ifndef __SHADER_RESOURCE_H
#define __SHADER_RESOURCE_H

#include <resource/Resource.h>

class ShaderResource : public Resource {
private:
	ShaderResource(ResourceManager &m, const char *name);
	~ShaderResource();

	virtual int LoadFromStorage();

public:


private:
	std::string m_VertexSource;
	std::string m_FragmentSource;

	friend class Resource;
};

#endif
