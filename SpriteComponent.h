#pragma once
#include "Private.h"
#include "Component.h"
#include <iostream>
#include <vector>

namespace engine {	
	class SpriteComponent : public Component {
	public:		
		SpriteComponent();
		int VaoId;
		static unsigned int Type;
		unsigned int vertices_num;
		virtual void Tick(float deltaTime) override;
	};
}