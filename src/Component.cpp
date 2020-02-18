#pragma once
#include "Component.h"
#include "Actor.h"

engine::Component::Component()
{
    std::cout<<"Creating Component\n";
    rel_transform = Transform::Base();
    transform = Transform::Base();
}

void engine::Component::BeginPlay()
{
    this->transform->position.X = Owner->GetPosition().X + rel_transform->position.X;
    this->transform->position.Y = Owner->GetPosition().Y + rel_transform->position.Y;
    this->transform->position.Z = Owner->GetPosition().Z + rel_transform->position.Z;
    this->transform->scale.X = Owner->GetScale().X * rel_transform->scale.X;
    this->transform->scale.Y = Owner->GetScale().Y * rel_transform->scale.Y;
    this->transform->scale.Z = Owner->GetScale().Z * rel_transform->scale.Z;
}

void engine::Component::Tick(float DeltaTime)
{
}

void engine::Component::UpdatePos()
{
    //std::cout<<"old pos: "<<transform.position.X<<"\n";
    this->transform->position.X = Owner->GetPosition().X + rel_transform->position.X;
    this->transform->position.Y = Owner->GetPosition().Y + rel_transform->position.Y;
    this->transform->position.Z = Owner->GetPosition().Z + rel_transform->position.Z;
    // std::cout<<"Parent pos: "<<Owner->transform.position.X<<"\n";
    // std::cout<<"Relative pos: "<<rel_transform.position.X<<"\n";
    // std::cout<<"Updating pos: "<<transform.position.X<<"\n";
}

void engine::Component::UpdateScale()
{
    this->transform->scale.X = Owner->GetScale().X * rel_transform->scale.X;
    this->transform->scale.Y = Owner->GetScale().Y * rel_transform->scale.Y;
    this->transform->scale.Z = Owner->GetScale().Z * rel_transform->scale.Z;
}

void engine::Component::SetRelativeLocation(float x, float y, float z)
{
    this->rel_transform->position.X = x;
    this->rel_transform->position.Y = y;
    this->rel_transform->position.Z = z;

    UpdatePos();
}

void engine::Component::SetRelativeScale(float x, float y, float z)
{
    this->rel_transform->scale.X = x;
    this->rel_transform->scale.Y = y;
    this->rel_transform->scale.Z = z;

    UpdateScale();
}