#pragma once
#include "Private.h"
#include "Actor.h"
#include "Component.h"
#include <iostream>
#include <vector>
#include "Vao.h"
#include "Actor.h"

struct Color
{
	float r;
	float g;
	float b;
	float a;
};

namespace engine
{
class SpriteComponent : public Component
{
public:
	SpriteComponent();
	~SpriteComponent();
	engine::Vao *vao;
	int VaoId;
	static unsigned int Type;
	Color color;		
	void transpose_positions(int posX, int posY);
	virtual void BeginPlay()override;
	virtual void Tick(float deltaTime) override;
	void SetColor(float r, float g, float b, float a);
	virtual void UpdatePos() override;

	inline int get_2D_width(){return (engine::Engine::Get().window_width/ratio * Owner->GetScale().X);};
	inline int get_2D_height(){return (engine::Engine::Get().window_height/ratio * Owner->GetScale().Y);};

private:	
	int ratio = 10;
	GLint x_uniform;
	GLint y_uniform;
	GLint scale_x_uniform;
	GLint scale_y_uniform;
	GLint color_uniform;
	void set_position();
	void set_scale();
	void set_color();
};
} // namespace engine