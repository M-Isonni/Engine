#pragma once
#include<vector>
#include "Component.h"
#include "Window.h"
#include "GLProgram.h"


namespace engine {
	class Engine {
	private:
		Engine();
		unsigned int ComponentCounter;
		

	public:		
		static Engine& Get();
		~Engine();	

		engine::GLProgram* Program;
		
		void Init(Window& InWindow);
		void compile_shader(ShaderType shader_type, const char* name) const;		

		template<typename T>
		void RegisterComponent() {			
			T::Type = ++ComponentCounter;
		}
	};	
}
