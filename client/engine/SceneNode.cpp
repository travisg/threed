#include <iostream>
#include <engine/SceneNode.h>

namespace Engine {

SceneNode::SceneNode()
{
}

SceneNode::~SceneNode()
{
}

void SceneNode::AddChild(Spatial *node) 
{ 
	node->mParent = this; 
	mChildren.push_back(node);
}

size_t SceneNode::NumChildren()
{
	return mChildren.size();
}

void SceneNode::UpdateTransform(bool force)
{
	if (force || mDirty) {
		Spatial::UpdateTransform(true);
		force = true;
	}

	for (SpatialListIterator i = mChildren.begin(); i != mChildren.end(); i++) {
		(*i)->UpdateTransform(force);
	}
}

void SceneNode::Render(Renderer *r)
{
//	std::cout << "SceneNode::Render\n";

	for (SpatialListIterator i = mChildren.begin(); i != mChildren.end(); i++) {
		(*i)->Render(r);
	}
}


}
