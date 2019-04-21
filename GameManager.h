#pragma once
#include "Window.h"
#include "Private.h"
#include "GLProgram.h"



namespace engine {
	class GameManager {
	public:
		GameManager();
		static GameManager& Get();
		~GameManager();
		engine::GLProgram Program;
		void Tick(float DeltaTime);
		void ClearWindow();	
		void Init(Window& InWindow);
		void compile_shader(ShaderType shader_type, const char* name);
	};
}