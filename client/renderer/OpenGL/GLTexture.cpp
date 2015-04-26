#include <assert.h>
#include <iostream>
#include <renderer/OpenGL/GLTexture.h>
#include <resource/TextureResource.h>

#include "glinc.h"
#include "SDL.h"

GLTexture::GLTexture()
    :   Texture(),
        m_GLtex(0)
{
}

GLTexture::~GLTexture()
{
}

Texture *Texture::CreateFromResource(Resource *_r)
{
    TextureResource *r = dynamic_cast<TextureResource *>(_r);
    assert(r);

    SDL_Surface *s = r->GetSurface();

    SDL_LockSurface(s);

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    GLint internalFormat;
    GLenum imageFormat;
    GLenum imageType;

    switch (s->format->BitsPerPixel) {
        case 32:
            imageFormat = GL_RGBA;
            imageType = GL_UNSIGNED_BYTE;
            internalFormat = GL_RGBA8;
            break;
        case 24:
            imageFormat = GL_RGB;
            imageType = GL_UNSIGNED_BYTE;
            internalFormat = GL_RGB8;
            break;
        default:
            assert(0);
    }

//  glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, s->w, s->h, 0, imageFormat, imageType, s->pixels);

    // build mipmaps for the texture
    gluBuild2DMipmaps(GL_TEXTURE_2D, internalFormat, s->w, s->h, imageFormat, imageType, s->pixels);

    SDL_UnlockSurface(s);

    GLTexture *p = new GLTexture();
    p->SetResource(r);

    p->m_GLtex = tex;

    return p;
}

void GLTexture::Bind(Renderer *r, int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_GLtex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,  GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,  GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
}
