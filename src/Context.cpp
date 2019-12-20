#include "Private.h"
#include "Context.h"

engine::Context::Context(engine::Window& InWindow) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	Ctx = SDL_GL_CreateContext(reinterpret_cast<SDL_Window*>(InWindow.GetHandle()));	
	gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
}

void* engine::Context::GetContext() const {
	return Ctx;
}

engine::Context::~Context(){
	SDL_GL_DeleteContext(Ctx);
}