#include "Vao.h"

unsigned int engine::Vao::VaoCount = 0;

engine::Vao::Vao() {
	GLuint vao = VaoCount++;
	VaoId = vao;
	glGenVertexArrays(1, &VaoId);
	glBindVertexArray(VaoId);
}

engine::Vao::~Vao(){
	for (std::shared_ptr<unsigned int> ptr : Vbos)
	{
		ptr.~shared_ptr();
	}
	Vbos.~vector();
}

std::shared_ptr<unsigned int> engine::Vao::Vbo(unsigned int size) {
	
	GLuint vbo[3];
	glGenBuffers(3, vbo);
	
	std::shared_ptr<unsigned int> pointer_to_vbo = std::make_shared<unsigned int>(vbo);

	Vbos.push_back(pointer_to_vbo);

	return pointer_to_vbo;
}

