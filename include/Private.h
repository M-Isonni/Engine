#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <glad/glad.h>

enum ShaderType
{
	Vertex_Shader = GL_VERTEX_SHADER,
	Fragment_Shader = GL_FRAGMENT_SHADER,
	Geometry_Shader = GL_GEOMETRY_SHADER,
	Compute_Shader = GL_COMPUTE_SHADER,
	Tess_Shader = GL_TESS_CONTROL_SHADER
};

enum ColliderType
{
	Square2D,
	Circle2D,
	Box3D,
	Sphere3D,
	Capsule3D,
	Cylinder3D

};
