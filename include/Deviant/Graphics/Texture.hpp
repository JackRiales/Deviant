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
        Texture();
        Texture(const std::string& path);
        Texture(const Texture& cpy);
        ~Texture();

        bool loadFromFile(const std::string& path);

        void setSize(unsigned width, unsigned height);
        void setColor(Color *c);

        unsigned width();
        unsigned height();

    protected:
        void free();

    private:
        SDL_Texture*    _texture;
        unsigned        _width;
        unsigned        _height;
};

}

#endif // DVNT_TEXTURE_HPP
