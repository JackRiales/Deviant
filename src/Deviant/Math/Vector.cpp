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

#include "Deviant/Math/Vector.hpp"
using namespace dv;

template<typename T>
Vector2D<T>::Vector2D(T _x, T _y) :
x(_x),
y(_y) {

}

/*-----------------------------------------------------------------*/
template<typename T>
const T Vector2D<T>::magnitude() const {
    return 0;
}

/*-----------------------------------------------------------------*/
template class Vector2D<int>;
template class Vector2D<float>;
template class Vector2D<double>;

// EOF Vector.cpp
// Location at: /src/Deviant/Math/Vector.cpp