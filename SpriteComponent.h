#pragma once
#include "Private.h"
#include "Component.h"
#include <iostream>
#include <vector>
#include "Vao.h"


namespace engine {	
	class SpriteComponent : public Component {
	public:		
		SpriteComponent();
		~SpriteComponent();
		engine::Vao* vao;
		int VaoId;
		static unsigned int Type;
		unsigned int vertices_num;
		virtual void Tick(float deltaTime) override;
	};
}