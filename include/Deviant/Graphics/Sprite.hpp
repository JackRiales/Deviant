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

#ifndef DVNT_SPRITE_HPP
#define DVNT_SPRITE_HPP

#include "Deviant/Utilities/Math/Rect.hpp"
#include "Deviant/Graphics/Texture.hpp"

namespace dv {

/**
    \class Sprite
    \brief Contains a rect within a texture to be used in a game node.
*/
class Sprite {
    public:
        /**
            \brief Constructor.
        */
        Sprite();

        /**
            \brief Constructor.
            \param sheet The texture to take the sprite from.
            \param rect The rect within the texture. NULL will use the whole texture.
        */
        Sprite(Texture *sheet, UIntRect *rect = NULL);

        /**
            \brief Creates a texture from the given rect in the given texture.
            \param sheet The texture to take the sprite from.
            \param rect The rect within the texture. NULL will use the whole texture.
        */
        void createFromTexture(Texture *sheet, UIntRect *rect = NULL);

        /**
            \brief Returns a pointer to the texture being used.
        */
        Texture* texture();

        /**
            \brief Returns the rect local to the texture coordinates.
        */
        const UIntRect& rect() const;

    private:
        Texture *_texture;
        UIntRect _rect;
};

}

#endif // DVNT_SPRITE_HPP
