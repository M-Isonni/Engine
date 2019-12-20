#pragma once
#include "Actor.h"
#include "World.h"

void engine::Actor::InternalAddComponent(std::shared_ptr<engine::Component> Component)
{
	this->Components.push_back(Component);
}

void engine::Actor::BeginPlay()
{
	for (auto Comp : Components)
	{
		Comp->BeginPlay();
	}
}

void engine::Actor::Tick(float DeltaTime)
{
	for (auto Comp : Components)
	{
		Comp->Tick(DeltaTime);
	}
}

void engine::Actor::SetPosition(float x, float y, float z)
{
	transform.position.X = x;
	transform.position.Y = y;
	transform.position.Z = z;
	for (auto c : Components)
		c->UpdatePos();
}

void engine::Actor::SetScale(float x, float y, float z)
{
	transform.scale.X = x;
	transform.scale.Y = y;
	transform.scale.Z = z;	
	for (auto c : Components)
		c->UpdateScale();
}