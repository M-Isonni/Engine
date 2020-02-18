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
	this->transform->position.X = x;
	this->transform->position.Y = y;
	this->transform->position.Z = z;
	int i = 0;
	for (auto c : this->Components)
	{
		i++;
		//std::cout<<"Component "<<i<<" from actor "<<ID<<" updating...\n";
		c->UpdatePos();
	}
}

void engine::Actor::SetPosition(Vector3 in_vec)
{
	this->transform->position.X = in_vec.X;
	this->transform->position.Y = in_vec.Y;
	this->transform->position.Z = in_vec.Z;
	int i = 0;
	for (auto c : this->Components)
	{
		i++;
		//std::cout<<"Component "<<i<<" from actor "<<ID<<" updating...\n";
		c->UpdatePos();
	}
}

void engine::Actor::SetScale(float x, float y, float z)
{
	transform->scale.X = x;
	transform->scale.Y = y;
	transform->scale.Z = z;	
	for (auto c : Components)
		c->UpdateScale();
}