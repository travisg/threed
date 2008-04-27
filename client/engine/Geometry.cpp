#include <assert.h>
#include <iostream>
#include <engine/Geometry.h>
#include <engine/SceneNode.h>
#include <renderer/Renderer.h>
#include <resource/ObjectResource.h>
#include <resource/MeshResource.h>

namespace Engine {

Geometry::Geometry()
:	m_Mesh(0)
{
}

Geometry::~Geometry()
{
}

void Geometry::Render(Renderer *r)
{
//	std::cout << "Geometry::Render\n";

	r->SetWorldMatrix(mWorldTransform);

	m_Mesh->Draw(r);

	r->UnsetWorldMatrix();
}

void Geometry::SetDefaultGeometry()
{
	m_Mesh = Mesh::CreateMesh(MESH_TYPE_TRIANGLE_MESH);
	m_Mesh->SetDefault();
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

		geom->m_Mesh = Mesh::CreateMeshFromResource(set->mesh);

		if (sceneNode)
			sceneNode->AddChild(geom);

		if (!rootSpatial)
			rootSpatial = geom;
	}

	return rootSpatial;
}

}

