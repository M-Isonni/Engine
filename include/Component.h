#pragma once


namespace engine {

class Component {

public:
	bool Enabled;
	class Actor* Owner;
	
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);

	unsigned int ComponentType;
};
}