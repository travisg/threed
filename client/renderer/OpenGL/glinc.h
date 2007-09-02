#ifndef __GLINC_H
#define __GLINC_H

// common gl includes
#ifdef _WIN32
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glext.h>

extern PFNGLBINDBUFFERARBPROC glBindBufferARB;
extern PFNGLGENBUFFERSARBPROC glGenBuffersARB;
extern PFNGLBUFFERDATAARBPROC glBufferDataARB;
extern PFNGLMAPBUFFERARBPROC  glMapBufferARB;
extern PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;

#else

// OS X
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#endif

void InitGLExt();

#endif
