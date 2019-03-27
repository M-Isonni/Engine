#include "InputManager.h"
#include "Window.h"


engine::Window::Window(int width, int height) {
	Handle = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
}

engine::Window::~Window() {
	SDL_DestroyWindow(reinterpret_cast<SDL_Window *>(Handle));
}

void* engine::Window::GetHandle() const {
	return Handle;
}

int engine::Window::DequeueEvent() const {
	SDL_Event Event;
	while (SDL_PollEvent(&Event)) {
		if (Event.type == SDL_QUIT)
		{
			return engine::Quit();
		}
		manageInput(Event);
	}
	return 1;
}