#ifndef __SCENENODE_H
#define __SCENENODE_H

#include <engine/Spatial.h>

namespace Engine {

class SceneNode : public Spatial {
public:
    SceneNode();
    virtual ~SceneNode();

    virtual void UpdateTransform(bool force);
    virtual void Render(Renderer *r);

    void AddChild(Spatial *node);
    size_t NumChildren();

protected:
    SpatialList mChildren;
};

}

#endif
