#pragma once
#include "Window.h"
#include "Private.h"
#include "GLProgram.h"



namespace engine {
	class GameManager {
	public:		
		static GameManager& Get();
		~GameManager();		
		void Tick(float DeltaTime);
		void ClearWindow();	
		void Setup(Window& InWindow);
		void compile_shader(ShaderType shader_type, const char* name);
	};
}