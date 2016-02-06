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

#ifndef DVNT_RECT_HPP
#define DVNT_RECT_HPP

#include "Vector.hpp"

namespace dv {

/**
    \struct Rect
    \brief Defines a geometrical rectangle.
*/
template<typename T = int>
struct Rect {
    /**
        Constructor
    */
    Rect(T _x = 0, T _y = 0, T _w = 0, T _h = 0);

    /**
        Copy constructor
    */
    Rect(const Rect& cpy);

    /**
        \return Whether or not the rectangle is intersecting rectangle r.
        \param r The rectangle to check against.
    */
    bool intersect(Rect r);

    /**
        \return If the point vector v is inside the rectangle.
        \param v The vector to check.
    */
    template<typename V>
    bool contains(Vector2D<V> v);

    T   x;
    T   y;
    T   w;
    T   h;
};

// Shorthand type definitions
typedef Rect<int> IntRect;
typedef Rect<unsigned> UIntRect;
typedef Rect<float> FloatRect;
typedef Rect<double> DoubleRect;

}

#endif // DVNT_RECT_HPP
