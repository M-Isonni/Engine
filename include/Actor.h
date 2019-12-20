#pragma once
#include "Component.h"
#include <memory>
#include <iostream>
#include <vector>

namespace engine {
	class Actor {
	public:
		Actor(){};
		~Actor(){};		
		virtual void BeginPlay(){};
		virtual void Tick(float DeltaTime);		

		template<typename T>
		std::shared_ptr<T> AddComponent() {			
			std::shared_ptr<T> NewComponent = std::make_shared<T>();
			InternalAddComponent(NewComponent);
			NewComponent->ComponentType = T::Type;
			NewComponent->Owner = this;
			return NewComponent;
		}

		template<typename T>
		std::vector<std::shared_ptr<T>> GetComponents() const {
			std::vector<std::shared_ptr<T>> components;
			for (int i = 0; i < Components.size(); i++) {
				if (T::Type == Components[i]->ComponentType) {
					auto FoundComponent = Components[i];
					components.push_back(std::dynamic_pointer_cast<T>(FoundComponent));
				}
			}
			return components;
		}

		template<typename T>
		std::shared_ptr<T> GetComponent() const {
			for (int i = 0; i < Components.size(); i++) {
				if (T::Type == Components[i]->ComponentType) {
					auto FoundComponent = Components[i];
					return std::dynamic_pointer_cast<T>(FoundComponent);
				}
			}
		}

	protected:		
		std::vector<std::shared_ptr<Component>> Components;
		void InternalAddComponent(std::shared_ptr<Component> Component);
	};
}