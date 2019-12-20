#pragma once
#include "Transform.h"

namespace engine {

class Component {

public:
	Component(){};
	virtual ~Component(){};
	bool Enabled;
	class Actor* Owner;
	Transform rel_transform;
	Transform transform;
	
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void SetRelativeLocation(float x, float y, float z=0);
	virtual void SetRelativeScale(float x, float y, float z);
	virtual void UpdatePos();
	virtual void UpdateScale();

	unsigned int ComponentType;
};
}