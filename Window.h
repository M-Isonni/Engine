#pragma once

namespace engine {
	class Window {
	public:
		Window(int width, int height);
		~Window();

		Window(const Window& rhs) = delete;

		void* GetHandle() const;

		void DequeueEvent() const;
	protected:
		void* Handle;
	};
}
