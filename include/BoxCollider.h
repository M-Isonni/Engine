#pragma once
#include "Collider.h"

namespace engine
{
class BoxCollider : public Collider
{
public:
    BoxCollider();
    ~BoxCollider(); 
    static unsigned int Type; 
    void OnCollision(std::shared_ptr<Collider> other_collider) override;
};
} // namespace engine