#pragma once
#include "Component.h"
#include <memory>
#include "Private.h"
#include "event.h"

namespace engine
{
class Collider : public Component
{
private:

public:
    virtual ~Collider() = default;
    ColliderType Coll_type;
    virtual void Tick(float DeltaTime) override;
    typedef void (Actor::*Collision)(std::shared_ptr<class engine::Collider> other_collider);
    Event<Collision*> OnCollision;

protected:    
    Collider();
};
} // namespace engine