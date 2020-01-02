#pragma once
#include "Component.h"
#include "Actor.h"

void engine::Component::BeginPlay()
{
    transform.position.X = Owner->transform.position.X + rel_transform.position.X;
    transform.position.Y = Owner->transform.position.Y + rel_transform.position.Y;
    transform.position.Z = Owner->transform.position.Z + rel_transform.position.Z;
    transform.scale.X = Owner->transform.scale.X * rel_transform.scale.X;
    transform.scale.Y = Owner->transform.scale.Y * rel_transform.scale.Y;
    transform.scale.Z = Owner->transform.scale.Z * rel_transform.scale.Z;
}

void engine::Component::Tick(float DeltaTime)
{
}

void engine::Component::UpdatePos()
{
    std::cout<<"old pos: "<<transform.position.X<<"\n";
    transform.position.X = Owner->transform.position.X + rel_transform.position.X;
    transform.position.Y = Owner->transform.position.Y + rel_transform.position.Y;
    transform.position.Z = Owner->transform.position.Z + rel_transform.position.Z;
    std::cout<<"Parent pos: "<<Owner->transform.position.X<<"\n";
    std::cout<<"Updating pos: "<<transform.position.X<<"\n";
}

void engine::Component::UpdateScale()
{
    transform.scale.X = Owner->transform.scale.X * rel_transform.scale.X;
    transform.scale.Y = Owner->transform.scale.Y * rel_transform.scale.Y;
    transform.scale.Z = Owner->transform.scale.Z * rel_transform.scale.Z;
}

void engine::Component::SetRelativeLocation(float x, float y, float z)
{
    rel_transform.position.X = x;
    rel_transform.position.Y = y;
    rel_transform.position.Z = z;

    UpdatePos();
}

void engine::Component::SetRelativeScale(float x, float y, float z)
{
    rel_transform.scale.X = x;
    rel_transform.scale.Y = y;
    rel_transform.scale.Z = z;

    UpdateScale();
}