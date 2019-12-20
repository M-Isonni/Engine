#pragma once
#include <vector>
#include "Actor.h"
#include <iostream>


namespace engine {
	class World {
	private:
		World();

	public:
		static World& Get();
		std::vector<std::shared_ptr<engine::Actor>> Actors;
		~World();	
		World(World& InWorld) = delete;

		//Creates an Actors, Adds it to Actors vector and returns a shared pointer to it
		template<typename T>
		std::shared_ptr<T> AddActor() {
			std::shared_ptr<T> NewActor = std::make_shared<T>();
			InternalAddActor(NewActor);
			return NewActor;
		}

	private:
		void InternalAddActor(std::shared_ptr<engine::Actor> Actor);			
	
	};
}
