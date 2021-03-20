#pragma once
#include "Private.h"

namespace engine
{
	class GLProgram
	{
	public:
		GLProgram();
		~GLProgram();
		GLProgram(const GLProgram &InProgram) = delete;

		unsigned int GetProgram();
		void LinkProgram() const;
		void UseProgram() const;

	protected:
		unsigned int Prog;
	};
}