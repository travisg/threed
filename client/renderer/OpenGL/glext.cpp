#include "glinc.h"

#ifdef _WIN32
PFNGLBINDBUFFERARBPROC glBindBuffer = NULL;
PFNGLGENBUFFERSARBPROC glGenBuffers = NULL;
PFNGLBUFFERDATAARBPROC glBufferData = NULL;
PFNGLMAPBUFFERARBPROC  glMapBuffer = NULL;
PFNGLUNMAPBUFFERARBPROC glUnmapBuffer = NULL;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffers = NULL;

PFNGLDELETEOBJECTARBPROC glDeleteObject = NULL;
PFNGLGETHANDLEARBPROC glGetHandle = NULL;
PFNGLDETACHOBJECTARBPROC glDetachObject = NULL;
PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObject = NULL;
PFNGLSHADERSOURCEARBPROC glShaderSource = NULL;
PFNGLCOMPILESHADERARBPROC glCompileShader = NULL;
PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObject = NULL;
PFNGLATTACHOBJECTARBPROC glAttachObject = NULL;
PFNGLLINKPROGRAMARBPROC glLinkProgram = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObject = NULL;
PFNGLVALIDATEPROGRAMARBPROC glValidateProgram = NULL;
PFNGLUNIFORM1FARBPROC glUniform1f = NULL;
PFNGLUNIFORM2FARBPROC glUniform2f = NULL;
PFNGLUNIFORM3FARBPROC glUniform3f = NULL;
PFNGLUNIFORM4FARBPROC glUniform4f = NULL;
PFNGLUNIFORM1IARBPROC glUniform1i = NULL;
PFNGLUNIFORM2IARBPROC glUniform2i = NULL;
PFNGLUNIFORM3IARBPROC glUniform3i = NULL;
PFNGLUNIFORM4IARBPROC glUniform4i = NULL;
PFNGLUNIFORM1FVARBPROC glUniform1fv = NULL;
PFNGLUNIFORM2FVARBPROC glUniform2fv = NULL;
PFNGLUNIFORM3FVARBPROC glUniform3fv = NULL;
PFNGLUNIFORM4FVARBPROC glUniform4fv = NULL;
PFNGLUNIFORM1IVARBPROC glUniform1iv = NULL;
PFNGLUNIFORM2IVARBPROC glUniform2iv = NULL;
PFNGLUNIFORM3IVARBPROC glUniform3iv = NULL;
PFNGLUNIFORM4IVARBPROC glUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fv = NULL;
PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfv = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameteriv = NULL;
PFNGLGETINFOLOGARBPROC glGetInfoLog = NULL;
PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObject = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocation = NULL;
PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniform = NULL;
PFNGLGETUNIFORMFVARBPROC glGetUniformfv = NULL;
PFNGLGETUNIFORMIVARBPROC glGetUniformiv = NULL;
PFNGLGETSHADERSOURCEARBPROC glGetShaderSource = NULL;

#endif

void InitGLExt()
{
#ifdef _WIN32
	glBindBuffer = (PFNGLBINDBUFFERARBPROC) wglGetProcAddress("glBindBufferARB");
	glGenBuffers = (PFNGLGENBUFFERSARBPROC) wglGetProcAddress("glGenBuffersARB");
	glBufferData = (PFNGLBUFFERDATAARBPROC) wglGetProcAddress("glBufferDataARB");
	glMapBuffer = (PFNGLMAPBUFFERARBPROC) wglGetProcAddress("glMapBufferARB");
	glUnmapBuffer = (PFNGLUNMAPBUFFERARBPROC) wglGetProcAddress("glUnmapBufferARB");
	glDeleteBuffers = (PFNGLDELETEBUFFERSARBPROC ) wglGetProcAddress("glDeleteBuffersARB");

	glDeleteObject = (PFNGLDELETEOBJECTARBPROC) wglGetProcAddress("glDeleteObjectARB");
	glGetHandle = (PFNGLGETHANDLEARBPROC) wglGetProcAddress("glGetHandleARB");
	glDetachObject = (PFNGLDETACHOBJECTARBPROC) wglGetProcAddress("glDetachObjectARB");
	glCreateShaderObject = (PFNGLCREATESHADEROBJECTARBPROC) wglGetProcAddress("glCreateShaderObjectARB");
	glShaderSource = (PFNGLSHADERSOURCEARBPROC) wglGetProcAddress("glShaderSourceARB");
	glCompileShader = (PFNGLCOMPILESHADERARBPROC) wglGetProcAddress("glCompileShaderARB");
	glCreateProgramObject = (PFNGLCREATEPROGRAMOBJECTARBPROC) wglGetProcAddress("glCreateProgramObjectARB");
	glAttachObject = (PFNGLATTACHOBJECTARBPROC) wglGetProcAddress("glAttachObjectARB");
	glLinkProgram  = (PFNGLLINKPROGRAMARBPROC) wglGetProcAddress("glLinkProgramARB");
	glUseProgramObject = (PFNGLUSEPROGRAMOBJECTARBPROC) wglGetProcAddress("glUseProgramObjectARB");
	glValidateProgram = (PFNGLVALIDATEPROGRAMARBPROC) wglGetProcAddress("glValidateProgramARB");
	glUniform1f = (PFNGLUNIFORM1FARBPROC) wglGetProcAddress("glUniform1fARB");
	glUniform2f = (PFNGLUNIFORM2FARBPROC) wglGetProcAddress("glUniform2fARB");
	glUniform3f = (PFNGLUNIFORM3FARBPROC) wglGetProcAddress("glUniform3fARB");
	glUniform4f = (PFNGLUNIFORM4FARBPROC) wglGetProcAddress("glUniform4fARB");
	glUniform1i = (PFNGLUNIFORM1IARBPROC) wglGetProcAddress("glUniform1iARB");
	glUniform2i = (PFNGLUNIFORM2IARBPROC) wglGetProcAddress("glUniform2iARB");
	glUniform3i = (PFNGLUNIFORM3IARBPROC) wglGetProcAddress("glUniform3iARB");
	glUniform4i = (PFNGLUNIFORM4IARBPROC) wglGetProcAddress("glUniform4iARB");
	glUniform1fv = (PFNGLUNIFORM1FVARBPROC) wglGetProcAddress("glUniform1fvARB");
	glUniform2fv = (PFNGLUNIFORM2FVARBPROC) wglGetProcAddress("glUniform2fvARB");
	glUniform3fv = (PFNGLUNIFORM3FVARBPROC) wglGetProcAddress("glUniform3fvARB");
	glUniform4fv = (PFNGLUNIFORM4FVARBPROC) wglGetProcAddress("glUniform4fvARB");
	glUniform1iv = (PFNGLUNIFORM1IVARBPROC) wglGetProcAddress("glUniform1ivARB");
	glUniform2iv = (PFNGLUNIFORM2IVARBPROC) wglGetProcAddress("glUniform2ivARB");
	glUniform3iv = (PFNGLUNIFORM3IVARBPROC) wglGetProcAddress("glUniform3ivARB");
	glUniform4iv = (PFNGLUNIFORM4IVARBPROC) wglGetProcAddress("glUniform4ivARB");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVARBPROC) wglGetProcAddress("glUniformMatrix2fvARB");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVARBPROC) wglGetProcAddress("glUniformMatrix3fvARB");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVARBPROC) wglGetProcAddress("glUniformMatrix4fvARB");
	glGetObjectParameterfv = (PFNGLGETOBJECTPARAMETERFVARBPROC) wglGetProcAddress("glGetObjectParameterfvARB");
	glGetObjectParameteriv = (PFNGLGETOBJECTPARAMETERIVARBPROC) wglGetProcAddress("glGetObjectParameterivARB");
	glGetInfoLog = (PFNGLGETINFOLOGARBPROC) wglGetProcAddress("glGetInfoLogARB");
	glGetAttachedObject = (PFNGLGETATTACHEDOBJECTSARBPROC) wglGetProcAddress("glGetAttachedObjectARB");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONARBPROC) wglGetProcAddress("glGetUniformLocationARB");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMARBPROC) wglGetProcAddress("glGetActiveUniformARB");
	glGetUniformfv = (PFNGLGETUNIFORMFVARBPROC) wglGetProcAddress("glGetUniformfvARB");
	glGetUniformiv = (PFNGLGETUNIFORMIVARBPROC) wglGetProcAddress("glGetUniformivARB");
	glGetShaderSource = (PFNGLGETSHADERSOURCEARBPROC) wglGetProcAddress("glGetShaderSourceARB");

#endif
}
