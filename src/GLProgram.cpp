#include "GLProgram.h"


engine::GLProgram::GLProgram() 
{
	
	Prog = glCreateProgram();	
	
}

engine::GLProgram::~GLProgram() 
{
	glDeleteProgram(Prog);
}

unsigned int engine::GLProgram::GetProgram() 
{
	return Prog;
}

void engine::GLProgram::LinkProgram() const
{
	glLinkProgram(Prog);
}

void engine::GLProgram::UseProgram() const 
{
	glUseProgram(Prog);
}