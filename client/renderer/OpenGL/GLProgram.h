#ifndef __GL_PROGRAM_H
#define __GL_PROGRAM_H

#include <renderer/Program.h>
#include "glinc.h"

class ShaderResource;

class GLProgram : public Program
{
public:
	GLProgram();
	virtual ~GLProgram();

	virtual void Bind(Renderer *r);

protected:
	// private constructor used by Program::CreateProgramFromResource
	int _CreateFromResource(ShaderResource *r);

	friend class Program;

private:
	// gl resources
	GLuint m_GLvshader;
	GLuint m_GLfshader;
	GLuint m_GLprogram;
};

#endif
