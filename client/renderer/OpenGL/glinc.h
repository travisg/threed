#ifndef __GLINC_H
#define __GLINC_H

// common gl includes
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

void InitGLExt();

#endif
