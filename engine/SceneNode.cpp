#include <iostream>
#include <engine/SceneNode.h>

namespace Engine {

SceneNode::SceneNode(unsigned int numChildren)
{
	mChildren = new Spatial*[numChildren];
	mNumChildren = numChildren;
}

SceneNode::~SceneNode()
{
	delete[] mChildren;
}

void SceneNode::SetChild(unsigned int child, Spatial *node) 
{ 
	mChildren[child] = node; 
	node->mParent = this; 
}

void SceneNode::Render(Renderer *r)
{
//	std::cout << "SceneNode::Render\n";

	UpdateWorldMatrix();
	for (unsigned int i = 0; i < mNumChildren; i++) {
		mChildren[i]->Render(r);
	}
}


}
