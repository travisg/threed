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

void SceneNode::Render(Renderer *r)
{
	std::cout << "SceneNode::Render\n";

	for (unsigned int i = 0; i < mNumChildren; i++) {
		mChildren[i]->Render(r);
	}
}


}
