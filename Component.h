#pragma once

namespace engine {

class Component {

public:
	bool Enabled;
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);

	unsigned int ComponentType;
};
}