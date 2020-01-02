#pragma once
#include "Component.h"
#include <memory>
#include <iostream>
#include <vector>
#include "Transform.h"

namespace engine
{
class Actor
{
public:
	Actor(){};
	~Actor(){};

	friend class engine::Component;
	
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);

	virtual void SetPosition(float x, float y,float z=0);
	virtual void SetPosition(Vector3 new_pos);
	virtual void SetScale(float x, float y,float z=0);
	inline virtual Vector3 GetPosition(){return transform.position;};
	inline virtual Vector3 GetScale(){return transform.scale;};

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> NewComponent = std::make_shared<T>();
		InternalAddComponent(NewComponent);
		NewComponent->Owner = this;
		NewComponent->ComponentType = T::Type;
		return NewComponent;
	}

	template <typename T>
	std::vector<std::shared_ptr<T>> GetComponents() const
	{
		std::vector<std::shared_ptr<T>> components;
		for (int i = 0; i < Components.size(); i++)
		{
			if (T::Type == Components[i]->ComponentType)
			{
				auto FoundComponent = Components[i];
				components.push_back(std::dynamic_pointer_cast<T>(FoundComponent));
			}
		}
		return components;
	}

	template <typename T>
	std::shared_ptr<T> GetComponent() const
	{
		for (int i = 0; i < Components.size(); i++)
		{
			if (T::Type == Components[i]->ComponentType)
			{
				auto FoundComponent = Components[i];
				return std::dynamic_pointer_cast<T>(FoundComponent);
			}
		}
	}

protected:
	Transform transform;
	std::vector<std::shared_ptr<Component>> Components;
	void InternalAddComponent(std::shared_ptr<Component> Component);
};
} // namespace engine