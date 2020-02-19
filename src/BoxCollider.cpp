#include "BoxCollider.h"
#include "PhysicsMgr.h"
#include <iostream>
#include "Actor.h"
#include "SpriteComponent.h"

unsigned int engine::BoxCollider::Type = 0;

engine::BoxCollider::BoxCollider()
{        
    Coll_type = ColliderType::Square2D;    
}

engine::BoxCollider::~BoxCollider()
{

}

void engine::BoxCollider::Tick(float DeltaTime)
{
    
}

void engine::BoxCollider::UpdatePos()
{
    //std::cout<<"Updating collider position for actor: "<<Owner->ID<<" to "<< transform->position.X<<", "<<transform->position.Y<<", "<<transform->position.Z<<"\n";
    engine::Collider::UpdatePos();
}

void engine::BoxCollider::UpdateScale()
{
    engine::Collider::UpdateScale();
    collider_width = Owner->GetComponent<engine::SpriteComponent>()->get_2D_width();
    collider_height = Owner->GetComponent<engine::SpriteComponent>()->get_2D_height();
}

void engine::BoxCollider::BeginPlay()
{
    SetEnabled(true);
    UpdatePos();
    collider_width = Owner->GetComponent<engine::SpriteComponent>()->get_2D_width();
    collider_height = Owner->GetComponent<engine::SpriteComponent>()->get_2D_height();
}
