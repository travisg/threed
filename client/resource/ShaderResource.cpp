#include <resource/ShaderResource.h>
#include <tinyxml/tinyxml.h>


ShaderResource::ShaderResource(ResourceManager &m, const char *name)
:	Resource(m, name, RT_SHADER)
{

}

ShaderResource::~ShaderResource()
{

}

int ShaderResource::LoadFromStorage()
{
	TiXmlDocument doc;

	char path[4096];
	sprintf(path, "resources/shader/%s.xml", mName.c_str());
	if (!doc.LoadFile(path))
		return -1;
	
	// load the vertex shader
	const TiXmlElement *vertexroot = doc.FirstChildElement("vertexshader");
	if (!vertexroot)
		return -1;

	// load the body
	const TiXmlElement *vertexbody = vertexroot->FirstChildElement("body");
	if (!vertexbody)
		return -1;

	const char *body = vertexbody->GetText();
	if (!body)
		return -1;

	m_VertexSource = body;

	// load the fragment shader
	const TiXmlElement *fragmentroot = doc.FirstChildElement("fragmentshader");
	if (!fragmentroot)
		return -1;

	// load the body
	const TiXmlElement *fragmentbody = fragmentroot->FirstChildElement("body");
	if (!fragmentbody)
		return -1;

	body = fragmentbody->GetText();
	if (!body)
		return -1;

	m_FragmentSource = body;

	return 0;
}
