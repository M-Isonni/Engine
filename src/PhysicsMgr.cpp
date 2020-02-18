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

bool engine::PhysicsMgr::AABBBox2DCollision(std::shared_ptr<engine::Collider> a, std::shared_ptr<engine::Collider> b)
{
    std::shared_ptr<engine::BoxCollider> a1 = std::dynamic_pointer_cast<engine::BoxCollider>(a);
    std::shared_ptr<engine::BoxCollider> b1 = std::dynamic_pointer_cast<engine::BoxCollider>(b);
    //std::cout<<"Actor: "<<a1->Owner->ID<<" Position X: "<<a1->transform->position.X<<" Position Y: "<<a1->transform->position.Y<<" Height: "<<a1->Height()<<" Width: "<<a1->Width()<<"\n";
    //std::cout<<"Actor: "<<b1->Owner->ID<<" Position X: "<<b1->transform->position.X<<" Position Y: "<<b1->transform->position.Y<<" Height: "<<b1->Height()<<" Width: "<<b1->Width()<<"\n";

    float top_a = a1->transform->position.Y - a1->Height() * 0.5f;
    float bottom_a = a1->transform->position.Y + a1->Height() * 0.5f;
    float left_a = a1->transform->position.X - a1->Width() * 0.5f;
    float right_a = a1->transform->position.X + a1->Width() * 0.5f;

    float top_b = b1->transform->position.Y - b1->Height() * 0.5f;
    float bottom_b = b1->transform->position.Y + b1->Height() * 0.5f;
    float left_b = b1->transform->position.X - b1->Width() * 0.5f;
    float right_b = b1->transform->position.X + b1->Width() * 0.5f;

    //std::cout<<"topA: "<<top_a<<" bottomA: "<<bottom_a<<" leftA: "<<left_a<<" rightA: "<<right_a<<"\n";
    //std::cout<<"topB: "<<top_b<<" bottomB: "<<bottom_b<<" leftB: "<<left_b<<" rightB: "<<right_b<<"\n";

    bool y_true;
    bool x_true;

    y_true = bottom_a >= top_b && bottom_a <= bottom_b || top_a >= top_b && top_a <= bottom_b;
    x_true = left_a >= left_b && left_a <= right_b || right_a <= right_b && right_a >= left_b;
    //std::cout<<"X: "<<x_true<<" Y: "<<y_true<<"\n";
    if (y_true && x_true)
        return true;
    return false;
}

void engine::PhysicsMgr::collisions_check()
{
    std::vector<std::shared_ptr<engine::Collider>> enabled_colliders;
    int total_coll = p_colliders.size();
    for (int i = 0; i < total_coll; i++)
    {
        if (p_colliders[i]->Enabled)
            enabled_colliders.push_back(p_colliders[i]);
    }
    int cmp_num = enabled_colliders.size();
    for (int i = 0; i < cmp_num; i++)
    {       
        for (int j = i + 1; j < cmp_num; j++)
        {
            if (i == j)
                continue;           
            switch (enabled_colliders[i]->Coll_type)
            {
            case ColliderType::Square2D:
                switch (enabled_colliders[j]->Coll_type)
                {
                case ColliderType::Square2D:
                    //std::cout << "Colliding: " << AABBBox2DCollision((p_colliders[i]), (p_colliders[j])) << "\n";
                    if (AABBBox2DCollision((enabled_colliders[i]), (enabled_colliders[j])))
                    {
                        //std::cout << "Calling collisions on colliders\n";
                        enabled_colliders[i]->OnCollision.Call(enabled_colliders[i]->Owner, enabled_colliders[j]);
                        enabled_colliders[j]->OnCollision.Call(enabled_colliders[j]->Owner, enabled_colliders[i]);
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
    enabled_colliders.clear();
}

void engine::PhysicsMgr::Tick(float DeltaTime)
{
    collisions_check();
}