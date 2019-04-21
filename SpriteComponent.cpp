#include "SpriteComponent.h"
#include "Vao.h"

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
}

engine::SpriteComponent::~SpriteComponent() {
	delete(vao);
}

void engine::SpriteComponent::Tick(float deltaTime) {
	//printf("%d", *vao->Vbos[0]);
	glBindVertexArray(VaoId);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
