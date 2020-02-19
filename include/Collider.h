#pragma once
#include "Component.h"
#include <memory>
#include "Private.h"
#include "event.h"

namespace engine
{
class Collider : public Component, public std::enable_shared_from_this<engine::Collider>
{
private:
int physics_manager_index;

public:
    virtual ~Collider() = default;
    ColliderType Coll_type;    
    virtual void Tick(float DeltaTime) override;
    virtual void UpdatePos()override;
    virtual void UpdateScale()override;
    virtual void BeginPlay()override;
    virtual void SetEnabled(bool enable);        
    Event<engine::Actor*, void(const Actor*, std::shared_ptr<Collider>)> OnCollision;


protected:    
    Collider();
};
} // namespace engine