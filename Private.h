#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <glad/glad.h>

enum ShaderType
{
	Vertex_Shader = 0x8B31,
	Fragment_Shader = GL_FRAGMENT_SHADER,
	Geometry_Shader = GL_GEOMETRY_SHADER,
	Compute_Shader = GL_COMPUTE_SHADER,
	Tess_Shader = GL_TESS_CONTROL_SHADER
};
