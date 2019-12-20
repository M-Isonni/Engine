#include "BoxCollider.h"
#include "PhysicsMgr.h"

unsigned int engine::BoxCollider::Type = 0;

engine::BoxCollider::BoxCollider()
{    
    engine::PhysicsMgr::Get().AddCollider(*this);
    Coll_type = ColliderType::Square2D;
}

engine::BoxCollider::~BoxCollider()
{

}
void engine::BoxCollider::OnCollision(std::shared_ptr<Collider> other_collider)
{
    //do stuff
}

