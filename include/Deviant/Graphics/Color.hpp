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

#ifndef DVNT_COLOR_HPP
#define DVNT_COLOR_HPP

#include <string>
#include <list>

namespace dv {

class Color {
    public:
        Color (uint8_t R = 0x0, uint8_t G = 0x0, uint8_t B = 0x0, float A = 0xFF);

        /**
            \brief Returns formatted string of color.
        */
        std::string toString() const;

        /**
            \brief Returns a color that is a mix of this and the given color.
            \param c1 The color to start with.
            \param c2 The color to mix c1 with.
            \param ratio The ratio of the two colors, normalized between 0 and 1.
            \return A color that is a mix of this and the given color.
        */
        static Color GetMix (const Color& c1, const Color& c2, float ratio = 0.5f);

        /**
            \brief Returns an array of colors in between start and end.
            \param start The color to start the range.
            \param end the color to end the range.
            \param steps The amount of steps in between the two. Determines size of array.
            \return Array of colors.
        */
        static std::list<Color> GetRange(const Color& start, const Color& end, int steps);

        /// Red component
        uint8_t r;

        /// Green component
        uint8_t g;

        /// Blue component
        uint8_t b;

        /// Alpha component
        uint8_t a;

        /*
            Operator overloads
        */
        Color& operator=(const Color& arg);
        Color& operator+(const Color& arg);
        Color& operator-(const Color& arg);
        Color& operator*(const Color& arg);
        Color& operator/(const Color& arg);

        /*
            Static color values
        */
        static const Color black;
        static const Color white;
        static const Color grey;
        static const Color red;
        static const Color blue;
        static const Color green;
        static const Color yellow;
        static const Color cyan;
        static const Color magenta;
        static const Color transparent;
};

}

#endif // DVNT_COLOR_HPP
