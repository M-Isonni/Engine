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
    virtual void SetPosition(float X, float Y);
    virtual void OnCollision(std::shared_ptr<Collider> other_collider){};

protected:
   Collider(){X = 0; Y = 0;};

public:
    float X;
    float Y;
};
} // namespace engine