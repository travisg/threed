#ifndef __GL_TEXTURE_H
#define __GL_TEXTURE_H

#include <renderer/Texture.h>
#include "glinc.h"

class ShaderResource;

class GLTexture : public Texture
{
public:
	virtual ~GLTexture();

	virtual void Bind(Renderer *r, int slot);

protected:

private:
	friend class Texture;

	GLTexture();

	// gl resources
	GLuint m_GLtex;
};

#endif
