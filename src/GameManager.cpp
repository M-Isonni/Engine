#include "GameManager.h"
#include "World.h"
#include "Actor.h"
#include "Private.h"
#include "Shader.h"
#include "Context.h"
#include <iostream>
#include <stdio.h>


engine::GameManager & engine::GameManager::Get()
{
	static GameManager* Singleton = nullptr;
	if (!Singleton) 
	{
		Singleton = new GameManager();
	}

	return *Singleton;
}

engine::GameManager::~GameManager()
{
}

void engine::GameManager::BeginPlay()
{
	for (std::shared_ptr<engine::Actor> a : engine::World::Get().Actors) 
	{
		a->BeginPlay();
	}
}

void engine::GameManager::Tick(float DeltaTime) 
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	for (std::shared_ptr<engine::Actor> a : engine::World::Get().Actors) 
	{
		a->Tick(DeltaTime);
	}
}


