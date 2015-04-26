#include <cstdio>
#include <cassert>
#include "glinc.h"

void InitGLExt()
{
#if WITH_GLEW
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "error initializing GLEW: %s\n", glewGetErrorString(err));
		assert(0);
	}

	printf("GLEW version %s\n", glewGetString(GLEW_VERSION));
#endif
}
