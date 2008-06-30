#include <resource/ObjectResource.h>
#include <resource/ResourceManager.h>
#include <tinyxml/tinyxml.h>

ObjectResource::ObjectResource(ResourceManager &m, const char *name)
:	Resource(m, name, RT_OBJECT)
{

}

ObjectResource::~ObjectResource()
{

}

int ObjectResource::LoadFromStorage()
{
	TiXmlDocument doc;

	char path[4096];
	sprintf(path, "resources/object/%s.xml", mName.c_str());
	if (!doc.LoadFile(path))
		return NULL;

	const TiXmlElement *root = doc.FirstChildElement("object");
	if (!root)
		return -1;

	const TiXmlElement *e = root->FirstChildElement();

	Resource *shader = NULL;
	Resource *mesh = NULL;
	ResourceList textures;

	for (; e; e = e->NextSiblingElement()) {
		std::cout << *e << std::endl;

		const std::string value = e->ValueStr();
		const char *name = e->Attribute("name");
		if (!name)
			continue;

		if (value.compare("shader") == 0) {
			// set new shader
			shader = mResourceManager.GetResource(name, RT_SHADER);
		} else if (value.compare("texture") == 0) {
			Resource *t = mResourceManager.GetResource(name, RT_TEXTURE);
			textures.push_back(t);
		} else if (value.compare("mesh") == 0) {
			// get new mesh
			mesh = mResourceManager.GetResource(name, RT_MESH);
			if (!mesh)
				continue;

			// create a new resource set and stuff it in our list
			object_resource_set *set = new object_resource_set;
			set->mesh = mesh;
			set->shader = shader;
			set->textures = textures;

			mResourceSets.push_back(set);

			textures.clear();
		}
	}

	return 0;
}
