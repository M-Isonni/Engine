#pragma once
#include "Window.h"

namespace engine {
	class Renderer {
	public:
		Renderer(Window& InWindow);
		~Renderer();

		Renderer(const Renderer& rhs) = delete;

		virtual void Tick() = 0;

		void Clear() const;
		void Present() const;

		void ChangeColor(int r, int g, int b, int a);

		void DrawLine(int X, int Y, int x1, int y2);
	protected:
		Window& Window;
		void *Handle;
	};
}