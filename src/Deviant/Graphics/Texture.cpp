/*
    Deviant - SDL Game Library
    Copyright (C) 2015 Jack Riales (jack@thatnaughtypanda.com)

    This software is provided 'as-is', without any express or implied warranty.
    In no event will the authors be held liable for any damages arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it freely,
    subject to the following restrictions:

    1. The origin of this software must not be misrepresented;
    you must not claim that you wrote the original software.
    If you use this software in a product, an acknowledgment
    in the product documentation would be appreciated but is not required.

    2. Altered source versions must be plainly marked as such,
    and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/

#include "Deviant/Graphics/Texture.hpp"
#include "Deviant/Rendering/Renderer.hpp"
#include "Deviant/Utilities/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
Texture::Texture():
_texture(NULL) {

}

/*-----------------------------------------------------------------*/
Texture::Texture(const std::string& path, Color *key) {
    loadFromFile(path, key);
}

/*-----------------------------------------------------------------*/
Texture::Texture(const Texture& cpy):
_texture(cpy._texture),
_width(cpy._width),
_height(cpy._height) {
    ;
}

/*-----------------------------------------------------------------*/
Texture::~Texture() {
    free();
}

/*-----------------------------------------------------------------*/
bool Texture::loadFromFile(const std::string& path, Color *key) {
    // Free the current texture to make way for the new one.
    free();

    SDL_Texture* new_texture = NULL;
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());

    // Ensure we have a surface to work with
    if (loaded_surface == NULL) {
        Debug::err("Unable to load image at " + path + ".", IMG_GetError());
        return false;
    } else {
        // Set the color key, if applicable
        if (key != NULL) {
            SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, key->r, key->g, key->b));
        }

        // Create a texture from the surface
        new_texture = SDL_CreateTextureFromSurface(Renderer::_renderer, loaded_surface);

        // Check if it worked properly
        if (new_texture == NULL) {
            Debug::err("Unable to create a new texture from the surface.", SDL_GetError());
            return false;
        } else {
            // Cache the height and the width
            _width = loaded_surface->w;
            _height = loaded_surface->h;
        }

        // Free up the temp surface
        SDL_FreeSurface(loaded_surface);
    }

    _texture = new_texture;
    return true;
}

/*-----------------------------------------------------------------*/
void Texture::setSize(unsigned width, unsigned height) {
    _width = width;
    _height = height;
}

/*-----------------------------------------------------------------*/
void Texture::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    if (_texture != NULL) {
        SDL_SetTextureColorMod(_texture, r, g, b);
        SDL_SetTextureAlphaMod(_texture, a);
    } else {
        Debug::warn("Can't set the color on a null texture.");
    }
}

/*-----------------------------------------------------------------*/
void Texture::setColor(Color *c) {
    if (c != NULL) {
        return;
    }

    if (_texture != NULL) {
        SDL_SetTextureColorMod(_texture, c->r, c->g, c->b);
        SDL_SetTextureAlphaMod(_texture, c->a);
    } else {
        Debug::warn("Can't set the color on a null texture.");
    }
}

/*-----------------------------------------------------------------*/
const unsigned& Texture::width() {
    return _width;
}

/*-----------------------------------------------------------------*/
const unsigned& Texture::height() {
    return _height;
}

/*-----------------------------------------------------------------*/
void Texture::free() {
    if (_texture != NULL) {
        SDL_DestroyTexture(_texture);
        _texture = NULL;
    }
}
