#include "Shader.h"
#include "Private.h"
#include <iostream>

engine::Shader::Shader(ShaderType shader_type,const char* filename) {
	SDL_RWops* rw = SDL_RWFromFile(filename, "rb");
	if (!rw) {
		SDL_Log("unable to open file");
		exit(1);
	}

	size_t file_len = SDL_RWsize(rw);
	auto source = SDL_malloc(file_len + 1);
	if (!source) {
		SDL_Log("unable to allocate memory");
		exit(1);
	}
	if (SDL_RWread(rw, source, 1, file_len) != file_len) {
		SDL_Log("unable to read file");
		exit(1);
	}

	reinterpret_cast<char*>(source)[file_len] = 0;

	SDL_RWclose(rw);

	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, (const GLchar * *)& source, (GLint*)& file_len);
	glCompileShader(shader);

	SDL_free(source);

	GLint compile_status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if (compile_status == GL_FALSE) {
		GLint log_size;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_size);
		auto error_log = SDL_malloc(log_size + 1);
		if (!error_log) {
			SDL_Log("unable to allocato memory for log");
			exit(1);
		}
		glGetShaderInfoLog(shader, log_size, &log_size, reinterpret_cast<char*>(error_log));
		reinterpret_cast<char*>(error_log)[log_size] = 0;
		std::cout<< "shader compile error: %s" << error_log << std::endl;
		SDL_free(error_log);
		exit(1);
	}

	shaderID = shader;
}

engine::Shader::~Shader() {
	glDeleteShader(shaderID);
}

void engine::Shader::AttachShader(GLProgram& InProgram) const {
	glAttachShader(InProgram.GetProgram(), shaderID);
}

void engine::Shader::DetachShader(GLProgram& InProgram) const {
	glDetachShader(InProgram.GetProgram(), shaderID);
}