#pragma once
#include "Collider.h"

namespace engine
{
class BoxCollider : public Collider
{
public:
    BoxCollider();
    ~BoxCollider();    
    
    void SetScale(float width, float height);
    void OnCollision(std::shared_ptr<Collider> other_collider) override;

public:        
		float width = 1;
		float height = 1;        
};
} // namespace engine