#include "SpriteComponent.h"
#include "Vao.h"
#include "Engine.h"

unsigned int engine::SpriteComponent::Type = 0;

engine::SpriteComponent::SpriteComponent()
{
	Enabled = true;	
	vao = new engine::Vao();
	VaoId = vao->VaoId;
	std::shared_ptr<unsigned int> vbo = vao->Vbo();
	//printf("%d", *vao->Vbos[0]);

	float quad[] = {
		0.1,0.1,0,
		-0.1,0.1,0,
		-0.1,-0.1,0,
		0.1,0.1,0,
		-0.1,-0.1,0,
		0.1,-0.1,0
	};
	
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * 3 * sizeof(float), quad, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	

	x_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "x_variable");
	y_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "y_variable");
	scale_x_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "scaleX");
	scale_y_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "scaleY");
	
}

engine::SpriteComponent::~SpriteComponent() {
	delete(vao);
}

void engine::SpriteComponent::Init(int posX, int posY)
{
	float positionX = posX;
	float positionY = posY;
	float render_pos_x = ((float)(2 * positionX / 800) - 1);
	float render_pos_y = ((float)(2 * (600 - positionY) / 600) - 1);

	this->X = render_pos_x;
	this->Y = render_pos_y;	
}

void engine::SpriteComponent::Tick(float deltaTime) {
	//printf("%d", *vao->Vbos[0]);
	set_position();
	set_scale();
	glBindVertexArray(VaoId);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void engine::SpriteComponent::set_position() {
	glUniform1f(x_uniform, X);
	glUniform1f(y_uniform, Y);
}

//multiplies the width and height of the sprite
void engine::SpriteComponent::SetScale(float scaleX, float scaleY) {
	this->width = scaleX;
	this->height = scaleY;	
}

void engine::SpriteComponent::set_scale() {
	glUniform1f(scale_x_uniform, width);
	glUniform1f(scale_y_uniform, height);
}
