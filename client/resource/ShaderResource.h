#ifndef __SHADER_RESOURCE_H
#define __SHADER_RESOURCE_H

#include <resource/Resource.h>
#include <shared/mesh.h>

class Program;

class ShaderResource : public Resource {
private:
	ShaderResource(ResourceManager &m, const char *name);
	~ShaderResource();

	virtual int LoadFromStorage();

public:
	const std::string &GetVertexSource() const { return m_VertexSource; }
	const std::string &GetFragmentSource() const { return m_FragmentSource; }
	Vertex_Format GetVertexFormat() const { return m_VertexFormat; }

	void SetProgram(Program *p) { m_Program = p; }
	Program *GetProgram() const { return m_Program; }

private:
	std::string m_VertexSource;
	std::string m_FragmentSource;
	Vertex_Format m_VertexFormat;

	Program *m_Program;

	friend class Resource;
};

#endif
