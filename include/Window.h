#pragma once

namespace engine
{
	class Window
	{
	public:
		Window(int width, int height);
		~Window();

		Window(const Window &rhs) = delete;

		void *GetHandle() const;

		int DequeueEvent() const;
		void ClearWindow() const;
		void SetClearColor(float r, float g, float b);

	protected:
		void *Handle;
	};
}
