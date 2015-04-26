#include <assert.h>
#include <iostream>
#include <cstdio>
#include <renderer/OpenGL/GLProgram.h>
#include <renderer/OpenGL/GLVertexBuffer.h>
#include <resource/ShaderResource.h>

#include "glinc.h"

GLProgram::GLProgram()
{
}

GLProgram::~GLProgram()
{
}

int GLProgram::_CreateFromResource()
{
	const GLchar *shaderptr;
	GLint success;
	char resultstr[1024];
	GLsizei len;
	ShaderResource *r = GetShaderResource();
	assert(r);

	// compile the vertex shader
	m_GLvshader = glCreateShader(GL_VERTEX_SHADER);
	shaderptr = r->GetVertexSource().c_str();
	glShaderSource(m_GLvshader, 1, &shaderptr, NULL);
	glCompileShader(m_GLvshader);
	glGetShaderiv(m_GLvshader, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(m_GLvshader, sizeof(resultstr), &len, resultstr);

	if (success != GL_TRUE) {
		std::cout << "failed to compile vertex shader: " << resultstr << std::endl;
	}

	assert(success == GL_TRUE);

	// compile the fragment shader
	m_GLfshader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderptr = r->GetFragmentSource().c_str();
	glShaderSource(m_GLfshader, 1, &shaderptr, NULL);
	glCompileShader(m_GLfshader);
	glGetShaderiv(m_GLfshader, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(m_GLfshader, sizeof(resultstr), &len, resultstr);

	if (success != GL_TRUE) {
		std::cout << "failed to compile fragment shader: " << resultstr << std::endl;
	}

	assert(success == GL_TRUE);


	// assemble the program
	m_GLprogram = glCreateProgram();
	glAttachShader(m_GLprogram, m_GLvshader);
	glAttachShader(m_GLprogram, m_GLfshader);

	// set the attribute locations based on our vertex format
	GLVertexBuffer::BindAttribLocations(m_GLprogram, r->GetVertexFormat());

	// link it
	glLinkProgram(m_GLprogram);
	glGetProgramiv(m_GLprogram, GL_LINK_STATUS, &success);
	glGetProgramInfoLog(m_GLprogram, sizeof(resultstr), &len, resultstr);

	if (success != GL_TRUE) {
		std::cout << "failed to link program: " << resultstr << std::endl;
	}
	assert(success == GL_TRUE);

#if 1
	GLint uniforms;
	glGetProgramiv(m_GLprogram, GL_ACTIVE_UNIFORMS, &uniforms);

    printf("active uniforms:\n");
	for (int i = 0; i < uniforms; i++) {
		char uname[1024];
		GLsizei len;
		GLint size;
		GLenum type;
		glGetActiveUniform(m_GLprogram, i, sizeof(uname), &len, &size, &type, uname);
        printf("\t name '%s' size %d type 0x%x\n", uname, size, type);
	}

	GLint attributes;
	glGetProgramiv(m_GLprogram, GL_ACTIVE_ATTRIBUTES, &attributes);

    printf("active attributes:\n");
	for (int i = 0; i < attributes; i++) {
		char uname[1024];
		GLsizei len;
		GLint size;
		GLenum type;
		glGetActiveAttrib(m_GLprogram, i, sizeof(uname), &len, &size, &type, uname);
        printf("\t name '%s' size %d type 0x%x\n", uname, size, type);
	}
#endif

	return 0;
}

Program *Program::CreateFromResource(Resource *_r)
{
	ShaderResource *r = dynamic_cast<ShaderResource *>(_r);
	assert(r);

	GLProgram *p = new GLProgram();

	p->SetResource(r);
	r->SetProgram(p);

	if (p->_CreateFromResource() < 0) {
		delete p;
		return NULL;
	}

	return p;
}

void GLProgram::Bind(Renderer *r)
{
	glUseProgram(m_GLprogram);

	// XXX total hack until we have a shader constant database
	GLint location = glGetUniformLocation(m_GLprogram, "sunvec");
    if (location >= 0)
	    glUniform3f(location, 1.0, 1.0, 1.0);

	location = glGetUniformLocation(m_GLprogram, "ambient");
    if (location >= 0)
	    glUniform3f(location, 1.0, 1.0, 1.0);

	location = glGetUniformLocation(m_GLprogram, "ambient_level");
    if (location >= 0)
	    glUniform1f(location, 0.5);
}

int GLProgram::Reload()
{
	// free all the old shader resources
	glDeleteProgram(m_GLprogram);
	glDeleteShader(m_GLvshader);
	glDeleteShader(m_GLfshader);

	return _CreateFromResource();
}
