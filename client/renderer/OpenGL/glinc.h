#ifndef __GLINC_H
#define __GLINC_H

// common gl includes
#ifdef _WIN32
#include <windows.h>

#include <GL/glew.h>
#include <GL/glu.h>

#define WITH_GLEW 1

#elif __DARWIN

// OS X
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#elif __LINUX

#include <GL/glew.h>
#include <GL/glu.h>

#define WITH_GLEW 1

#else
#error I dont know what platform I am!
#endif

void InitGLExt();

#endif
