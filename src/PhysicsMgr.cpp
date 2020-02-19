#include "PhysicsMgr.h"
#include "Engine.h"
#include "Actor.h"
#include "BoxCollider.h"

engine::PhysicsMgr::PhysicsMgr()
{
}

engine::PhysicsMgr &engine::PhysicsMgr::Get()
{
    static PhysicsMgr *Singleton = nullptr;
    if (!Singleton)
    {
        Singleton = new PhysicsMgr();
    }

    return *Singleton;
}
engine::PhysicsMgr::~PhysicsMgr()
{
}

void engine::PhysicsMgr::AddCollider(std::shared_ptr<engine::Collider> in_coll)
{    
    p_colliders.push_back(in_coll);
}

void engine::PhysicsMgr::_push_to_enabled(std::shared_ptr<engine::Collider> in_coll)
{    
    enabled_colliders.push_back(in_coll);
}

void engine::PhysicsMgr::GetEnabledColliders()
{    
    enabled_colliders.clear();
    int len = p_colliders.size();
    for(auto c : p_colliders)
    {
        if(c->Enabled)
            enabled_colliders.push_back(c);
    }
    //p_colliders.remove(in_coll);
    return;
}

bool engine::PhysicsMgr::AABBBox2DCollision(std::shared_ptr<engine::Collider> a, std::shared_ptr<engine::Collider> b)
{
    std::shared_ptr<engine::BoxCollider> a1 = std::dynamic_pointer_cast<engine::BoxCollider>(a);
    std::shared_ptr<engine::BoxCollider> b1 = std::dynamic_pointer_cast<engine::BoxCollider>(b);
    float top_a = a1->transform->position.Y - a1->Height() * 0.5f;
    float bottom_a = a1->transform->position.Y + a1->Height() * 0.5f;
    float left_a = a1->transform->position.X - a1->Width() * 0.5f;
    float right_a = a1->transform->position.X + a1->Width() * 0.5f;

    float top_b = b1->transform->position.Y - b1->Height() * 0.5f;
    float bottom_b = b1->transform->position.Y + b1->Height() * 0.5f;
    float left_b = b1->transform->position.X - b1->Width() * 0.5f;
    float right_b = b1->transform->position.X + b1->Width() * 0.5f;

    bool y_true;
    bool x_true;

    y_true = bottom_a >= top_b && bottom_a <= bottom_b || top_a >= top_b && top_a <= bottom_b;
    x_true = left_a >= left_b && left_a <= right_b || right_a <= right_b && right_a >= left_b;
    if (y_true && x_true)
        return true;
    return false;
}

void engine::PhysicsMgr::collisions_check()
{
    std::vector<std::shared_ptr<engine::Collider>> enabled(enabled_colliders);
    int cmp_num = enabled.size();
    for (int i = 0; i < cmp_num; i++)
    {
        for (int j = i + 1; j < cmp_num; j++)
        {
            if (i == j)
                continue;
            switch (enabled[i]->Coll_type)
            {
            case ColliderType::Square2D:
                switch (enabled[j]->Coll_type)
                {
                case ColliderType::Square2D:
                    if (AABBBox2DCollision((enabled[i]), (enabled[j])))
                    {
                        std::cout << "Calling Collision\n";
                        std::cout<<"First Collision Call\n";
                            enabled[i]->OnCollision.Call(enabled[i]->Owner, enabled[j]);
                            std::cout<<"Second Collision Call\n";
                            enabled[j]->OnCollision.Call(enabled[j]->Owner, enabled[i]);
                    }
                    break;
                case ColliderType::Circle2D:
                    break;
                case ColliderType::Box3D:
                    break;
                case ColliderType::Sphere3D:
                    break;
                case ColliderType::Capsule3D:
                    break;
                case ColliderType::Cylinder3D:
                    break;
                default:
                    break;
                }
                break;
            case ColliderType::Circle2D:
                break;
            case ColliderType::Box3D:
                break;
            case ColliderType::Sphere3D:
                break;
            case ColliderType::Capsule3D:
                break;
            case ColliderType::Cylinder3D:
                break;
            default:
                break;
            }
        }
    }
    enabled.clear();
}

void engine::PhysicsMgr::Tick(float DeltaTime)
{
    collisions_check();
}