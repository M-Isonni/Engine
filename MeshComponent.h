#pragma once
#include "Private.h"
#include "Component.h"
#include <iostream>
#include <vector>

namespace engine {
	class MeshComponent : public Component {
	public:		
		MeshComponent(std::shared_ptr<unsigned int> vbo, float vertices[], int size);
		static unsigned int Type;
		unsigned int vertices_num;
	};
}