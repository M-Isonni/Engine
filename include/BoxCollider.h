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
    virtual void UpdatePos()override;
    virtual void UpdateScale()override;
    virtual void Tick(float DeltaTime)override;
    void BeginPlay()override;
    inline int Width(){return collider_width;};
    inline int Height(){return collider_height;};

private:
    int collider_width;
    int collider_height;
};
} // namespace engine