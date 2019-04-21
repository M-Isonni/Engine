#pragma once
#include "Private.h"
#include <vector>
#include <iostream>

namespace engine {
	class Vao {
	private:
		static unsigned int VaoCount;
		
	public:
		Vao();
		~Vao();
		Vao(Vao& InVao) = delete;

		unsigned int VaoId;
		std::vector<std::shared_ptr<unsigned int>> Vbos;
		std::shared_ptr<unsigned int> Vbo();		
	};
}