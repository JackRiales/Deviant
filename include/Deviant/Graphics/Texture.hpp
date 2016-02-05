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

#ifndef DVNT_TEXTURE_HPP
#define DVNT_TEXTURE_HPP

#include "Deviant/Graphics/Color.hpp"
#include <SDL2/SDL_image.h>

namespace dv {

class Texture {
    public:
        /**
            \brief Constructor.
        */
        Texture();

        /**
            \brief Constructor. Immediately calls file load.
        */
        Texture(const std::string& path, Color *key = NULL);

        /**
            \brief Copy constructor.
        */
        Texture(const Texture& cpy);

        /**
            \brief Destructor. Calls `free()`
        */
        ~Texture();

        /**
            \brief Loads in a texture from an image file.
            \param path The file path to the image.
            \param key The alpha color key
            \return true if image was able to be loaded. False if not.
        */
        bool loadFromFile(const std::string& path, Color *key = NULL);

        /**
            \brief Manually sets the size of the texture.
        */
        void setSize(unsigned width, unsigned height);

        /**
            \brief Sets the color modification of the texture.
        */
        void setColor (uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        /**
            \brief Sets the color modification of the texture.
        */
        void setColor(Color *c);

        const unsigned& width();
        const unsigned& height();

    protected:
        /**
            \brief Frees sdl texture.
        */
        void free();

    private:
        SDL_Texture*    _texture;
        unsigned        _width;
        unsigned        _height;
};

}

#endif // DVNT_TEXTURE_HPP
