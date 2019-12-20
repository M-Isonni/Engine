#include "BoxCollider.h"
#include "PhysicsMgr.h"

engine::BoxCollider::BoxCollider()
{    
    engine::PhysicsMgr::Get().AddCollider(*this);
    Coll_type = ColliderType::Square2D;
}

engine::BoxCollider::~BoxCollider()
{

}

void engine::BoxCollider::SetScale(float width, float height)
{
    this->width = width;
    this->height = height;
}

void engine::BoxCollider::OnCollision(std::shared_ptr<Collider> other_collider)
{
    //do stuff
}

