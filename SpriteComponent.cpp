#include "SpriteComponent.h"
#include "Vao.h"

unsigned int engine::SpriteComponent::Type = 0;

engine::SpriteComponent::SpriteComponent()
{
	Enabled = true;
	engine::Vao vao;
	VaoId = vao.VaoId;
	vao.Vbo();

	float quad[] = {
		1,1,0,
		-1,1,0,
		-1,-1,0,
		1,1,0,
		-1,-1,0,
		1,-1,0
	};
	
	glBindBuffer(GL_ARRAY_BUFFER, *vao.Vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, 6 * 3 * sizeof(float), quad, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	
}

void engine::SpriteComponent::Tick(float deltaTime) {
	glBindVertexArray(VaoId);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
