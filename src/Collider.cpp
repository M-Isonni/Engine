#include "Collider.h"
#include "Actor.h"
#include "PhysicsMgr.h"

engine::Collider::Collider()
{       
    std::cout<<"COLLIDER POSITION: "<<transform->position.X<<"\n";
}  


void engine::Collider::Tick(float DeltaTime)
{    
}

void engine::Collider::UpdatePos()
{
    engine::Component::UpdatePos();    
}

void engine::Collider::UpdateScale()
{
    engine::Component::UpdateScale();
}
void engine::Collider::BeginPlay()
{
    engine::Component::BeginPlay();       
    //engine::PhysicsMgr::Get().AddCollider(std::make_shared<engine::Collider>(this));

}

void engine::Collider::SetEnabled(bool enable)
{
    if(enable&&!Enabled)
    {
        std::cout<<"Adding collider\n";
        Enabled = true;
        engine::PhysicsMgr::Get()._push_to_enabled(shared_from_this());
        //physics_manager_index = engine::PhysicsMgr::Get().colliders_num();
        return;
    }
    if(Enabled)
    {
        //REMOVING LIKE THIS REMOVES THE WRONG INDEX AFTER THE FIRST COLLIDING OBJECT IS REMOVED!!!
        //std::cout<<"Disabling\n";
        Enabled = false;
        engine::PhysicsMgr::Get().GetEnabledColliders();
        //std::cout<<"Disabled\n";
    }
}