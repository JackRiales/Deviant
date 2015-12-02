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

#include "Deviant/Math/Rect.hpp"
#include "Deviant/Base/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
template<typename T>
Rect<T>::Rect(T _x, T _y, T _w, T _h) :
x(_x),
y(_y),
w(_w),
h(_h) {

}

/*-----------------------------------------------------------------*/
template<typename T>
Rect<T>::Rect(const Rect& cpy) :
x(cpy.x),
y(cpy.y),
w(cpy.w),
h(cpy.h) {

}

/*-----------------------------------------------------------------*/
template<typename T>
bool Rect<T>::intersect(Rect r) {
    bool touchingRight = (x + w > r.x - r.w);
    bool touchingLeft = (x - w < r.x + r.w);
    bool touchingDown = (y + h > r.y - r.h);
    bool touchingUp = (y - h < r.y + r.h);
    return (touchingRight && touchingLeft && touchingDown && touchingUp);
}

/*-----------------------------------------------------------------*/
template<typename T>
template<typename V>
bool Rect<T>::contains(Vector2D<V> v) {
    bool inVertical = (x < v.x) && (w > v.x);
    bool inHorizontal = (y > v.y) && (h < v.y);
    return inVertical && inHorizontal;
}

/*-----------------------------------------------------------------*/
template class Rect<int>;
template class Rect<float>;

// EOF Rect.cpp
// Location at: /src/Deviant/Math/Rect.cpp
