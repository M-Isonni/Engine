#pragma once

namespace engine {
	class Window {
	public:
		Window(int width, int height);
		~Window();

		Window(const Window& rhs) = delete;

		void* GetHandle() const;

		int DequeueEvent() const;
	protected:
		void* Handle;
	};
}
