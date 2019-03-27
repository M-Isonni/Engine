#pragma once
#include<vector>
#include "Component.h"


namespace engine {
	class Engine {
	private:
		Engine();
		unsigned int ComponentCounter;
		std::vector<engine::Component&> Components;

	public:
		static Engine& Get();
		~Engine();
		void AddComponent(engine::Component* comp);
		void InitComponents();
		void UpdateComponents(float deltaTime);

		template<typename T>
		void RegisterComponent() {			
			T::Type = ++ComponentCounter;
		}
	};	
}
