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
		void BeginPlay();	
	};
}