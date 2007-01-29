#ifndef __SCENENODE_H
#define __SCENENODE_H

#include <engine/Spatial.h>

namespace Engine {

class SceneNode : public Spatial {
public:
	SceneNode(unsigned int numChildren);
	virtual ~SceneNode();

	virtual void Render(Renderer *r);

	Spatial *GetChild(unsigned int child) const { return mChildren[child]; }
	void SetChild(unsigned int child, Spatial *node) { mChildren[child] = node; }

protected:
	Spatial **mChildren;
	unsigned int mNumChildren;
};

}

#endif
