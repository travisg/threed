#include <cstdio>
#include <cassert>
#include "glinc.h"

#ifdef GL_EXT_POINTERS

/* OGL 1.5 */
PFNGLBINDBUFFERARBPROC glBindBuffer = NULL;
PFNGLGENBUFFERSARBPROC glGenBuffers = NULL;
PFNGLBUFFERDATAARBPROC glBufferData = NULL;
PFNGLMAPBUFFERARBPROC  glMapBuffer = NULL;
PFNGLUNMAPBUFFERARBPROC glUnmapBuffer = NULL;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffers = NULL;

/* OGL 2.0 */
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
PFNGLCREATESHADERPROC glCreateShader = NULL;
PFNGLDELETESHADERPROC glDeleteShader = NULL;
PFNGLDETACHSHADERPROC glDetachShader = NULL;
PFNGLATTACHSHADERPROC glAttachShader = NULL;
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = NULL;
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
PFNGLUSEPROGRAMPROC glUseProgram = NULL;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = NULL;
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = NULL;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
PFNGLUNIFORM1FPROC glUniform1f = NULL;
PFNGLUNIFORM2FPROC glUniform2f = NULL;
PFNGLUNIFORM3FPROC glUniform3f = NULL;
PFNGLUNIFORM4FPROC glUniform4f = NULL;
PFNGLUNIFORM1IPROC glUniform1i = NULL;
PFNGLUNIFORM2IPROC glUniform2i = NULL;
PFNGLUNIFORM3IPROC glUniform3i = NULL;
PFNGLUNIFORM4IPROC glUniform4i = NULL;
PFNGLUNIFORM1FVPROC glUniform1fv = NULL;
PFNGLUNIFORM2FVPROC glUniform2fv = NULL;
PFNGLUNIFORM3FVPROC glUniform3fv = NULL;
PFNGLUNIFORM4FVPROC glUniform4fv = NULL;
PFNGLUNIFORM1IVPROC glUniform1iv = NULL;
PFNGLUNIFORM2IVPROC glUniform2iv = NULL;
PFNGLUNIFORM3IVPROC glUniform3iv = NULL;
PFNGLUNIFORM4IVPROC glUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
PFNGLGETUNIFORMFVPROC glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glGetUniformiv = NULL;
PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture = NULL;

#endif

void InitGLExt()
{
#ifdef GL_EXT_POINTERS
	glBindBuffer = (PFNGLBINDBUFFERARBPROC) wglGetProcAddress("glBindBufferARB");
	glGenBuffers = (PFNGLGENBUFFERSARBPROC) wglGetProcAddress("glGenBuffersARB");
	glBufferData = (PFNGLBUFFERDATAARBPROC) wglGetProcAddress("glBufferDataARB");
	glMapBuffer = (PFNGLMAPBUFFERARBPROC) wglGetProcAddress("glMapBufferARB");
	glUnmapBuffer = (PFNGLUNMAPBUFFERARBPROC) wglGetProcAddress("glUnmapBufferARB");
	glDeleteBuffers = (PFNGLDELETEBUFFERSARBPROC ) wglGetProcAddress("glDeleteBuffersARB");

	glCreateProgram = (PFNGLCREATEPROGRAMPROC) wglGetProcAddress("glCreateProgram");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC) wglGetProcAddress("glDeleteProgram");
	glCreateShader = (PFNGLCREATESHADERPROC) wglGetProcAddress("glCreateShader");
	glDeleteShader = (PFNGLDELETESHADERPROC) wglGetProcAddress("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC) wglGetProcAddress("glDetachShader"); 
	glAttachShader = (PFNGLATTACHSHADERPROC) wglGetProcAddress("glAttachShader");
	glShaderSource = (PFNGLSHADERSOURCEPROC) wglGetProcAddress("glShaderSourceARB");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) wglGetProcAddress("glGetShaderSourceARB");
	glCompileShader = (PFNGLCOMPILESHADERPROC) wglGetProcAddress("glCompileShaderARB");
	glLinkProgram  = (PFNGLLINKPROGRAMPROC) wglGetProcAddress("glLinkProgramARB");
	glUseProgram = (PFNGLUSEPROGRAMPROC) wglGetProcAddress("glUseProgram");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) wglGetProcAddress("glValidateProgramARB");
	glGetShaderiv = (PFNGLGETSHADERIVPROC) wglGetProcAddress("glGetShaderiv");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC) wglGetProcAddress("glGetProgramiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) wglGetProcAddress("glGetShaderInfoLog");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) wglGetProcAddress("glGetProgramInfoLog");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) wglGetProcAddress("glGetActiveUniform");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) wglGetProcAddress("glGetUniformLocation");
	glUniform1f = (PFNGLUNIFORM1FPROC) wglGetProcAddress("glUniform1fARB");
	glUniform2f = (PFNGLUNIFORM2FPROC) wglGetProcAddress("glUniform2fARB");
	glUniform3f = (PFNGLUNIFORM3FPROC) wglGetProcAddress("glUniform3fARB");
	glUniform4f = (PFNGLUNIFORM4FPROC) wglGetProcAddress("glUniform4fARB");
	glUniform1i = (PFNGLUNIFORM1IPROC) wglGetProcAddress("glUniform1iARB");
	glUniform2i = (PFNGLUNIFORM2IPROC) wglGetProcAddress("glUniform2iARB");
	glUniform3i = (PFNGLUNIFORM3IPROC) wglGetProcAddress("glUniform3iARB");
	glUniform4i = (PFNGLUNIFORM4IPROC) wglGetProcAddress("glUniform4iARB");
	glUniform1fv = (PFNGLUNIFORM1FVPROC) wglGetProcAddress("glUniform1fvARB");
	glUniform2fv = (PFNGLUNIFORM2FVPROC) wglGetProcAddress("glUniform2fvARB");
	glUniform3fv = (PFNGLUNIFORM3FVPROC) wglGetProcAddress("glUniform3fvARB");
	glUniform4fv = (PFNGLUNIFORM4FVPROC) wglGetProcAddress("glUniform4fvARB");
	glUniform1iv = (PFNGLUNIFORM1IVPROC) wglGetProcAddress("glUniform1ivARB");
	glUniform2iv = (PFNGLUNIFORM2IVPROC) wglGetProcAddress("glUniform2ivARB");
	glUniform3iv = (PFNGLUNIFORM3IVPROC) wglGetProcAddress("glUniform3ivARB");
	glUniform4iv = (PFNGLUNIFORM4IVPROC) wglGetProcAddress("glUniform4ivARB");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) wglGetProcAddress("glUniformMatrix2fvARB");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) wglGetProcAddress("glUniformMatrix3fvARB");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) wglGetProcAddress("glUniformMatrix4fvARB");
	glGetUniformfv = (PFNGLGETUNIFORMFVARBPROC) wglGetProcAddress("glGetUniformfvARB");
	glGetUniformiv = (PFNGLGETUNIFORMIVARBPROC) wglGetProcAddress("glGetUniformivARB");
	glActiveTexture = (PFNGLACTIVETEXTUREPROC) wglGetProcAddress("glActiveTextureARB");
	glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC) wglGetProcAddress("glClientActiveTextureARB");
#endif

#if WITH_GLEW
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "error initializing GLEW: %s\n", glewGetErrorString(err));
		assert(0);
	}

	printf("GLEW version %s\n", glewGetString(GLEW_VERSION));
#endif
}
