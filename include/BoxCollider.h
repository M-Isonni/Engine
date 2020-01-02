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
};
} // namespace engine