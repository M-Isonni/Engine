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
		float X = 0;
		float Y = 0;
		float width = 1;
		float height = 1;
		void SetScale(float width, float height);
		void Init(int posX, int posY);
		virtual void Tick(float deltaTime) override;
		
	private:
		GLint x_uniform;
		GLint y_uniform;
		GLint scale_x_uniform;
		GLint scale_y_uniform;
		void set_position();
		void set_scale();
	};
}