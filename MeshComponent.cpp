#include "MeshComponent.h"

unsigned int engine::MeshComponent::Type = 0;

engine::MeshComponent::MeshComponent(std::shared_ptr<unsigned int> vbo, float vertices[], int vertices_len){	
	vertices_num = vertices_len;
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices_len * sizeof(float), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}