#pragma once
#include<vector>
#include "Component.h"


namespace engine {
	class Engine {
	private:
		Engine();
		unsigned int ComponentCounter;

	public:
		static Engine& Get();
		~Engine();

		template<typename T>
		void RegisterComponent() {			
			T::Type = ++ComponentCounter;
		}
	};	
}
