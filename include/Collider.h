#pragma once
#include "Component.h"
#include <memory>
#include "Private.h"

namespace engine
{
class Collider : public Component
{
public:
    virtual ~Collider() = default;
    ColliderType Coll_type;    
    virtual void OnCollision(std::shared_ptr<Collider> other_collider){};
    virtual void Tick(float DeltaTime) override;
    
protected:
    Collider();  
};
} // namespace engine