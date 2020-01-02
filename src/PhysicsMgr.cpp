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
    // std::cout<<"In Pos: "<<a->transform.position.Y<<"\n";
    float top_a = a->transform.position.Y - (a->transform.scale.Y * 0.5f);
    float bottom_a = a->transform.position.Y + a->transform.scale.Y * 0.5f;
    float left_a = a->transform.position.X - a->transform.scale.X  * 0.5f;
    float right_a = a->transform.position.X + a->transform.scale.X  * 0.5f;

    float top_b = b->transform.position.Y - b->transform.scale.Y * 0.5f;
    float bottom_b = b->transform.position.Y + b->transform.scale.Y * 0.5f;
    float left_b = b->transform.position.X - b->transform.scale.X * 0.5f;
    float right_b = b->transform.position.X + b->transform.scale.X  * 0.5f;

    bool y_true;
    bool x_true;

    y_true = bottom_a >= top_b && bottom_a <= bottom_b || top_a >= top_b && top_a <= bottom_b;
    x_true = left_a >= left_b && left_a <= right_b || right_a <= right_b && right_a >= right_b;

    if (y_true && x_true)
        return true;
    return false;
}

void engine::PhysicsMgr::collisions_check()
{
    int cmp_num = p_colliders.size();
    for (int i = 0; i < cmp_num; i++)
    {
        for (int j = i+1; j < cmp_num; j++)
        {
            if (i == j)
                continue;

            switch (p_colliders[i]->Coll_type)
            {
            case ColliderType::Square2D:
                switch (p_colliders[j]->Coll_type)
                {
                case ColliderType::Square2D:
                    if (AABBBox2DCollision((p_colliders[i]), (p_colliders[j])))
                    {                        
                        p_colliders[i]->OnCollision.Call(p_colliders[i]->Owner,p_colliders[j]);
                        p_colliders[j]->OnCollision.Call(p_colliders[j]->Owner,p_colliders[i]);
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
}

void engine::PhysicsMgr::Tick(float DeltaTime)
{
    collisions_check();
}