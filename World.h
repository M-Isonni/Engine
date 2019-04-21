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
		void AddActor(std::shared_ptr<engine::Actor> InActor);
	
	};
}
