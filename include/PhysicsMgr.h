
#pragma once
#include <vector>
#include <memory>

namespace engine
{
class PhysicsMgr
{
private:
    PhysicsMgr();
    std::vector<std::shared_ptr<class Collider>> p_colliders;
    bool AABBBox2DCollision(std::shared_ptr<class BoxCollider> a, std::shared_ptr<class BoxCollider> b);
    void collisions_check();

public:
    static PhysicsMgr &Get();
    ~PhysicsMgr();
    void AddCollider(std::shared_ptr<engine::Collider> in_col);
    void Tick(float DeltaTime);
};
} // namespace engine