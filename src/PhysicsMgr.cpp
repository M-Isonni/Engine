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

void engine::PhysicsMgr::AddCollider(engine::Collider in_cmp)
{
    p_colliders.push_back(std::make_shared<engine::Collider>(in_cmp));
}

bool engine::PhysicsMgr::AABBBox2DCollision(std::shared_ptr<engine::BoxCollider> a, std::shared_ptr<engine::BoxCollider> b)
{
    float top_a = a->Y - a->height * 0.5f;
    float bottom_a = a->Y + a->height * 0.5f;
    float left_a = a->X - a->width * 0.5f;
    float right_a = a->X + a->width * 0.5f;

    float top_b = b->Y - b->height * 0.5f;
    float bottom_b = b->Y + b->height * 0.5f;
    float left_b = b->X - b->width * 0.5f;
    float right_b = b->X + b->width * 0.5f;

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
        for (int j = 0; j < cmp_num; j++)
        {
            if (i == j)
                continue;

            switch (p_colliders[i]->Coll_type)
            {
            case ColliderType::Square2D:
                switch (p_colliders[j]->Coll_type)
                {
                case ColliderType::Square2D:
                    if (AABBBox2DCollision(std::dynamic_pointer_cast<engine::BoxCollider>(p_colliders[i]), std::dynamic_pointer_cast<engine::BoxCollider>(p_colliders[j])))
                    {
                        p_colliders[i]->OnCollision(p_colliders[j]);
                        p_colliders[j]->OnCollision(p_colliders[i]);
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