#pragma once
#include "Window.h"

namespace engine {
	class Context {
	public:
		Context(Window& InWindow);
		~Context();
		Context(Context& InContext) = delete;

		void* GetContext() const;

	protected:
		void* Ctx;
	};
}