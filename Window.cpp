#include "Private.h";
#include "Window.h";

engine::Window::Window(int width, int height) {
	Handle = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
}

engine::Window::~Window() {
	SDL_DestroyWindow(reinterpret_cast<SDL_Window *>(Handle));
}

void* engine::Window::GetHandle() const {
	return Handle;
}

void engine::Window::DequeueEvent() const {
	SDL_Event Event;
	while (SDL_PollEvent(&Event)) {

	}
}