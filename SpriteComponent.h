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
		GLint x_uniform;
		GLint y_uniform;
		float X = 0;
		float Y = 0;		
		virtual void Tick(float deltaTime) override;
		
	private:
		void set_position();
	};
}