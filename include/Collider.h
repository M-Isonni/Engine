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
        
    Event<engine::Actor*, void(const Actor*, std::shared_ptr<Collider>)> OnCollision;

protected:    
    Collider();
};
} // namespace engine