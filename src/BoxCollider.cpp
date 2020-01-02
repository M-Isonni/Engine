#include "BoxCollider.h"
#include "PhysicsMgr.h"
#include <iostream>

unsigned int engine::BoxCollider::Type = 0;

engine::BoxCollider::BoxCollider()
{        
    Coll_type = ColliderType::Square2D;    
}

engine::BoxCollider::~BoxCollider()
{

}
