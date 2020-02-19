
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
    std::vector<std::shared_ptr<class Collider>> enabled_colliders;
    bool AABBBox2DCollision(std::shared_ptr<class Collider> a, std::shared_ptr<class Collider> b);
    void collisions_check();

public:
    static PhysicsMgr &Get();
    ~PhysicsMgr();
    void AddCollider(std::shared_ptr<engine::Collider> in_col);
    void GetEnabledColliders();
    void _push_to_enabled(std::shared_ptr<engine::Collider> in_col);
    void Tick(float DeltaTime);
    inline int colliders_num(){return p_colliders.size();};
};
} // namespace engine