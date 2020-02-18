#pragma once
#include<vector>
#include "Component.h"
#include "Window.h"
#include "GLProgram.h"
#include "Context.h"
#include "Shader.h"
#include <iostream>


namespace engine {
	class Engine {
	private:
		Engine();
		unsigned int ComponentCounter;
		

	public:		
		static Engine& Get();
		~Engine();	

		int window_width;
		int window_height;

		engine::GLProgram* Program;
		engine::Context* Context;

		
		
		void Init(Window& InWindow);
		void compile_shader(std::vector<ShaderType> shader_types, std::vector<const char*> names) const;

		template<typename T>
		void RegisterComponent() {			
			T::Type = ++ComponentCounter;
		}
	};	
}
