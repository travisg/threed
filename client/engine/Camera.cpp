#include <engine/Camera.h>
#include <renderer/Renderer.h>

namespace Engine {

Camera::Camera()
    :   mPos(0,0,0),
        mUp(0,1,0),
        mForward(1,0,0),
        mZoom(1.0f),
        dirty(true)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
    if (dirty) {
        // normalize our up vector
        Math::Vector3f up = mUp;
        up.Normalize();

        // normalize the forward vector
        Math::Vector3f forward = mForward;
        forward.Normalize();

        // compute a vector out of the side
        Math::Vector3f side = Cross(mForward, up);

        // use forward and side to compute the new up
        up = Cross(side, mForward);

        // set up a transform matrix
        Math::Matrix4x4 M;
        M.SetIdentity();
        M.SetCol(0, side);
        M.SetCol(1, up);
        M.SetCol(2, -mForward);

        // construct a translation matrix
        Math::Matrix4x4 trans;
        trans.SetTranslation(-mPos);
        mTransform = M * trans;

        dirty = false;
    }
}

void Camera::Render(Renderer *r)
{
    r->SetViewMatrix(mTransform);
}

void Camera::SetPos(const Math::Vector3f &pos)
{
    mPos = pos;
    dirty = true;
}

void Camera::Move(const Math::Vector3f &trans)
{
    mPos += trans;
    dirty = true;
}

void Camera::Rotate(const Math::Vector3f &rot)
{
    // handle yaw
    Math::Matrix4x4 myaw;
    myaw.SetFromAxisAngle(mUp, rot.gety());
 
    // handle pitch
    Math::Vector3f side = Cross(mForward, mUp);
    Math::Matrix4x4 mpitch;
    mpitch.SetFromAxisAngle(side, rot.getx());

    // handle roll
    Math::Matrix4x4 mroll;
    mroll.SetFromAxisAngle(mForward, rot.getz());

    // transform the forward and up vectors
    mForward = (myaw * mpitch).Transform(mForward);
    mForward.Normalize();

    mUp = (mpitch * mroll).Transform(mUp);
    mUp.Normalize();

    dirty = true;
}

void Camera::LookAt(Spatial &obj)
{
    //std::cout << __FUNCTION__ << " object at " << obj.GetGlobalPos() << " cam " << mPos << std::endl;

    LookAt(obj.GetGlobalPos());
}

void Camera::LookAt(const Math::Vector3f &pos)
{
    //std::cout << __FUNCTION__ << " pos " << pos << " cam " << mPos << std::endl;

    // compute the vector towards the target    
    Math::Vector3f forward = pos - mPos;
    forward.Normalize();

    mForward = forward;

    dirty = true;
}

void Camera::PrintPosition()
{
    std::cout << "Camera pos: " << mPos << " up " << mUp << " forward " << mForward << std::endl;
}

}

