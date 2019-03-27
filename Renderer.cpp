#include "Renderer.h"
#include "Private.h"

engine::Renderer::Renderer(engine::Window& InWindow) :Window(InWindow) {
	SDL_Window* WindowHandle = reinterpret_cast<SDL_Window*>(Window.GetHandle());
	Handle = SDL_CreateRenderer(WindowHandle, -1, 0);
}

engine::Renderer::~Renderer() {
	SDL_DestroyRenderer(reinterpret_cast<SDL_Renderer*>(Handle));
}

void engine::Renderer::Clear() const {	
	SDL_SetRenderDrawColor(reinterpret_cast<SDL_Renderer*>(Handle), 0, 0, 0, 255);
	SDL_RenderClear(reinterpret_cast<SDL_Renderer*>(Handle));

	glClearColor(0,1,0,1);
}

void engine::Renderer::Present() const {
	SDL_RenderPresent(reinterpret_cast<SDL_Renderer*>(Handle));
}

void engine::Renderer::ChangeColor(int r, int g, int b, int a) {
	
}

void engine::Renderer::DrawLine(int x, int y, int x1, int y1) {
	SDL_SetRenderDrawColor(reinterpret_cast<SDL_Renderer*>(Handle), 255, 0, 0, 255);
	SDL_RenderDrawLine(reinterpret_cast<SDL_Renderer*>(Handle), x, y, x1, y1);
}