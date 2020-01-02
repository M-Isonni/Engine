#include "Collider.h"
#include "Actor.h"

engine::Collider::Collider()
{   
    Enabled = true;  
    std::cout<<"COLLIDER POSITION: "<<transform.position.X<<"\n";
}  


void engine::Collider::Tick(float DeltaTime)
{    
}