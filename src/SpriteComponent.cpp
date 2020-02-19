#include "SpriteComponent.h"
#include "Vao.h"
#include "Engine.h"

unsigned int engine::SpriteComponent::Type = 0;

engine::SpriteComponent::SpriteComponent()
{
	
	if (!sprite_vao)
	{
		std::cout<<"ENTERED\n";
		sprite_vao = new engine::Vao();
		glBindVertexArray(sprite_vao->VaoId);
	}	
	Enabled = true;
	//vao = new engine::Vao();
	//VaoId = vao->VaoId;
	std::shared_ptr<unsigned int> vbo = sprite_vao->Vbo();
	float f = 1 / ratio;

	float quad[] = {
		0.1, 0.1, 0,
		-0.1, 0.1, 0,
		-0.1, -0.1, 0,
		0.1, 0.1, 0,
		-0.1, -0.1, 0,
		0.1, -0.1, 0};

	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * 3 * sizeof(float), quad, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	x_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "x_variable");
	y_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "y_variable");
	scale_x_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "scaleX");
	scale_y_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "scaleY");
	color_uniform = glGetUniformLocation(engine::Engine::Get().Program->GetProgram(), "color");

	color = Color{1, 0, 1, 1};
	//std::cout<<"VAO: "<<vao_sprite_counter<<"\n";
	//delete _vao_ptr;
}

engine::SpriteComponent::~SpriteComponent()
{	
}

void engine::SpriteComponent::BeginPlay()
{
	Enabled = true;
	std::cout << "BeginPlay" << std::endl;
	SetRelativeScale(1, 1, 1);
}
void engine::SpriteComponent::transpose_positions(int posX, int posY)
{
	float positionX = posX;
	float positionY = posY;
	float render_pos_x = ((float)(2 * positionX / 800) - 1);
	float render_pos_y = ((float)(2 * (600 - positionY) / 600) - 1);

	this->transform->position.X = render_pos_x;
	this->transform->position.Y = render_pos_y;
}

void engine::SpriteComponent::Tick(float deltaTime)
{
	//printf("%d", *vao->Vbos[0]);
	if (Enabled)
	{
		//std::cout<<"\nScaleX: "<<transform.scale.X <<"Scale Y: "<<transform.scale.Y <<"\n";

		set_position();
		set_scale();
		set_color();
		//glBindVertexArray(VaoId);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
}

void engine::SpriteComponent::SetColor(float r, float g, float b, float a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

void engine::SpriteComponent::set_position()
{
	glUniform1f(x_uniform, transform->position.X);
	glUniform1f(y_uniform, transform->position.Y);
}

void engine::SpriteComponent::set_scale()
{
	glUniform1f(scale_x_uniform, transform->scale.X);
	glUniform1f(scale_y_uniform, transform->scale.Y);
}

void engine::SpriteComponent::set_color()
{
	glUniform4f(color_uniform, color.r, color.g, color.b, color.a);
}

void engine::SpriteComponent::UpdatePos()
{
	//std::cout<<"Updating Sprite Component pos on actor: "<<Owner->ID<<"\n";
	engine::Component::UpdatePos();
	transpose_positions(transform->position.X, transform->position.Y);
	set_position();
}
