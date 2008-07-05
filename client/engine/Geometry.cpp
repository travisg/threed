#include <assert.h>
#include <iostream>
#include <engine/Geometry.h>
#include <engine/SceneNode.h>
#include <renderer/Renderer.h>
#include <renderer/Mesh.h>
#include <renderer/Program.h>
#include <renderer/Texture.h>
#include <resource/ObjectResource.h>
#include <resource/MeshResource.h>

namespace Engine {

Geometry::Geometry()
:	m_Mesh(0),
	m_Program(0),
	m_Texture(0)
{
}

Geometry::~Geometry()
{
}

void Geometry::Render(Renderer *r)
{
//	std::cout << "Geometry::Render\n";

	r->SetWorldMatrix(mWorldTransform);

	m_Program->Bind(r);
	if (m_Texture)
		m_Texture->Bind(r, 0);
	m_Mesh->Draw(r);

	r->UnsetWorldMatrix();
}

Spatial *Geometry::BuildFromResource(Resource *_r)
{
	ObjectResource *r;

	r = dynamic_cast<ObjectResource *>(_r);
	assert(r);

	ObjectResourceList list = r->getObjectResourceList();

	Spatial *rootSpatial;
	SceneNode *sceneNode;

	if (list.size() > 1) {
		sceneNode = new Engine::SceneNode();
		rootSpatial = sceneNode;
	} else {
		sceneNode = 0;
		rootSpatial = 0;
	}

	for (ObjectResourceListConstIterator i = list.begin(); i != list.end(); i++) {
		Engine::Geometry *geom = new Engine::Geometry();
		
		object_resource_set *set = (*i);

		geom->m_Mesh = dynamic_cast<Mesh *>(set->mesh->GetRenderResource());
		assert(geom->m_Mesh);
		geom->m_Program = dynamic_cast<Program *>(set->shader->GetRenderResource());
		assert(geom->m_Program);

		for	(ResourceListConstIterator i2 = set->textures.begin(); i2 != set->textures.end(); i2++) {
			// xxx
			Resource *r = (*i2);
			geom->m_Texture = dynamic_cast<Texture *>(r->GetRenderResource());
		}

		if (sceneNode)
			sceneNode->AddChild(geom);

		if (!rootSpatial)
			rootSpatial = geom;
	}

	return rootSpatial;
}

}

