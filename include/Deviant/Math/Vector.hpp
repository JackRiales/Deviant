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
    \file   Vector.hpp
    \author Jack Riales (jack@thatnaughtypanda.com)
    \date   September, 2015
    \ingroup Math
*/

#ifndef DVNT_VECTOR_HPP
#define DVNT_VECTOR_HPP

#include <cmath>

namespace dv {

template<typename T = int>
struct Vector2D {
    T   x;
    T   y;

    Vector2D(T _x = 0, T _y = 0);

    const T magnitude() const;
    Vector2D<T> normalized() const;

    const T dot(const Vector2D& v) const;

    Vector2D& operator=(const Vector2D& v);
    Vector2D& operator=(const T& v);
    Vector2D& operator+(const Vector2D& v);
    Vector2D& operator+(const T& v);
    Vector2D& operator-(const Vector2D& v);
    Vector2D& operator-(const T& v);
};

}

#endif // DVNT_VECTOR_HPP

// EOF Vector.hpp
// Location at: /include/Deviant/Math/Vector.hpp
