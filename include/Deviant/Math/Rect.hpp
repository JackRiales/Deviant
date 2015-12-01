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

/**
    \file   Rect.hpp
    \author Jack Riales (jack@thatnaughtypanda.com)
    \date   November, 2015
    \ingroup Math
*/

#ifndef DVNT_RECT_HPP
#define DVNT_RECT_HPP

namespace dv {

template<typename T = int>
struct Rect {
    Rect(T _x = 0, T _y = 0, T _w = 0, T _h = 0);

    bool intersect(Rect r);

    T   x;
    T   y;
    T   w;
    T   h;
};

typedef Rect<int> IntRect;
typedef Rect<float> FloatRect;

}

#endif // DVNT_RECT_HPP

// EOF Rect.hpp
// Location at: /include/Deviant/Math/Rect.hpp
