#pragma once
#include "Private.h"
#include "GLProgram.h"

namespace engine
{
	class Shader
	{
	public:
		Shader(ShaderType type, const char *name);
		~Shader();

		void AttachShader(GLProgram &InProgram) const;
		void DetachShader(GLProgram &InProgram) const;

	protected:
		unsigned int shaderID;
	};
}