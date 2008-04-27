#include <assert.h>
#include <stdio.h>
#include <iostream>

#include <resource/loader/ObjectLoader.h>
#include <resource/ResourceManager.h>
#include <resource/ObjectResource.h>
#include <tinyxml/tinyxml.h>

ObjectLoader::ObjectLoader(ResourceManager &m)
:	Loader(m)
{
}

ObjectLoader::~ObjectLoader()
{
}

// iterate through the object's xml file and build a list of resources and attach to a new object resource
Resource *ObjectLoader::LoadResource(const char *resource)
{
	TiXmlDocument doc;

	char path[4096];
	sprintf(path, "resources/object/%s.xml", resource);
	if (!doc.LoadFile(path))
		return NULL;

	const TiXmlElement *root = doc.FirstChildElement("object");
	if (!root)
		return NULL;

	ObjectResource *r = new ObjectResource(resource);

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
//			lastshader = mResourceManager.GetResource(name, RT_SHADER);
		} else if (value.compare("texture") == 0) {
//			Resource *t = mResourceManager.GetResource(name, RT_TEXTURE);

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

			r->mResourceSets.push_back(set);

			textures.clear();
		}
	}

	return r;
}

