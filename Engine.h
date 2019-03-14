#pragma once

namespace engine {
	class Engine {
	private:
		Engine();
		~Engine();
	public:
		static Engine& Get();
	};	
}
