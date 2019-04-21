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
		ptr.reset();
	}
	Vbos.~vector();
}

std::shared_ptr<GLuint> engine::Vao::Vbo() {
	
	GLuint vbo;
	glGenBuffers(1, &vbo);
	
	std::shared_ptr<GLuint> pointer_to_vbo = std::make_shared<GLuint>(vbo);

	Vbos.push_back(pointer_to_vbo);

	return pointer_to_vbo;
}

