#ifndef __GLINC_H
#define __GLINC_H

// common gl includes
#ifdef _WIN32
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glext.h>

/* buffer objects */
extern PFNGLBINDBUFFERARBPROC glBindBuffer;
extern PFNGLGENBUFFERSARBPROC glGenBuffers;
extern PFNGLBUFFERDATAARBPROC glBufferData;
extern PFNGLMAPBUFFERARBPROC  glMapBuffer;
extern PFNGLUNMAPBUFFERARBPROC glUnmapBuffer;
extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffers;

/* shader stuff */
extern PFNGLDELETEOBJECTARBPROC glDeleteObject;
extern PFNGLGETHANDLEARBPROC glGetHandle;
extern PFNGLDETACHOBJECTARBPROC glDetachObject;
extern PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObject;
extern PFNGLSHADERSOURCEARBPROC glShaderSource;
extern PFNGLCOMPILESHADERARBPROC glCompileShader;
extern PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObject;
extern PFNGLATTACHOBJECTARBPROC glAttachObject;
extern PFNGLLINKPROGRAMARBPROC glLinkProgram;
extern PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObject;
extern PFNGLVALIDATEPROGRAMARBPROC glValidateProgram;
extern PFNGLUNIFORM1FARBPROC glUniform1f;
extern PFNGLUNIFORM2FARBPROC glUniform2f;
extern PFNGLUNIFORM3FARBPROC glUniform3f;
extern PFNGLUNIFORM4FARBPROC glUniform4f;
extern PFNGLUNIFORM1IARBPROC glUniform1i;
extern PFNGLUNIFORM2IARBPROC glUniform2i;
extern PFNGLUNIFORM3IARBPROC glUniform3i;
extern PFNGLUNIFORM4IARBPROC glUniform4i;
extern PFNGLUNIFORM1FVARBPROC glUniform1fv;
extern PFNGLUNIFORM2FVARBPROC glUniform2fv;
extern PFNGLUNIFORM3FVARBPROC glUniform3fv;
extern PFNGLUNIFORM4FVARBPROC glUniform4fv;
extern PFNGLUNIFORM1IVARBPROC glUniform1iv;
extern PFNGLUNIFORM2IVARBPROC glUniform2iv;
extern PFNGLUNIFORM3IVARBPROC glUniform3iv;
extern PFNGLUNIFORM4IVARBPROC glUniform4iv;
extern PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fv;
extern PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfv;
extern PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameteriv;
extern PFNGLGETINFOLOGARBPROC glGetInfoLog;
extern PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObject;
extern PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocation;
extern PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniform;
extern PFNGLGETUNIFORMFVARBPROC glGetUniformfv;
extern PFNGLGETUNIFORMIVARBPROC glGetUniformiv;
extern PFNGLGETSHADERSOURCEARBPROC glGetShaderSource;

#else

// OS X
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#endif

void InitGLExt();

#endif
