#pragma once
#include <vector>
#include "Actor.h"


namespace engine {
	class World {
	private:
		World();

	public:
		static World& Get();
		std::vector<engine::Actor> Actors;
		~World();	
		World(World& InWorld) = delete;
	
	};
}
