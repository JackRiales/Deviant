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

#include "Deviant/Graphics/Color.hpp"
#include "Deviant/Utilities/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
const Color Color::black        (0x0, 0x0, 0x0, 0xFF);
const Color Color::white        (0xFF, 0xFF, 0xFF, 0xFF);
const Color Color::grey         (0x7F, 0x7F, 0x7F, 0xFF);
const Color Color::red          (0xFF, 0x0, 0x0, 0xFF);
const Color Color::green        (0x0, 0xFF, 0x0, 0xFF);
const Color Color::blue         (0x0, 0x0, 0xFF, 0xFF);
const Color Color::yellow       (0xFF, 0xFF, 0x0, 0xFF);
const Color Color::cyan         (0x0, 0xFF, 0xFF, 0xFF);
const Color Color::magenta      (0xFF, 0x0, 0xFF, 0xFF);
const Color Color::transparent  (0x0, 0x0, 0x0, 0x0);

/*-----------------------------------------------------------------*/
Color::Color(uint8_t R, uint8_t G, uint8_t B, float A):
r (R),
g (G),
b (B),
a (A) {
    ;
}

/*-----------------------------------------------------------------*/
Color Color::GetMix(const Color& c1, const Color& c2, float ratio) {
    if (ratio > 1.0f)
        ratio = 1.0f;
    else if (ratio < 0.0f)
        ratio = 0.0f;

    if (ratio == 1.0f)
        return Color (c1.r, c1.g, c1.b, c1.a);
    else if (ratio == 0.0f)
        return Color (c2.r, c2.g, c2.b, c2.a);

    return Color (
                    (c1.r - c2.r) * ratio + c1.r,
                    (c1.g - c2.g) * ratio + c1.g,
                    (c1.b - c2.b) * ratio + c1.b,
                    (c1.a - c2.a) * ratio + c1.a
                  );
}

/*-----------------------------------------------------------------*/
std::list<Color> Color::GetRange(const Color& start, const Color& end, int steps) {
    std::list<Color> range;
    for (int i = steps; i >= 0; --i) {
        float ratio = (float) i / (float) steps;
        Debug::out("i at " + std::to_string(i) + " ratio: " + std::to_string(ratio));
        range.push_back(GetMix(start, end, ratio));
    }
    return range;
}

/*-----------------------------------------------------------------*/
std::string Color::toString() const {
    return "R: " + std::to_string(r) + "\nG: " + std::to_string(g) + "\nB: " + std::to_string(b) + "\nA: " + std::to_string(a);
}

/*-----------------------------------------------------------------*/
Color& Color::operator=(const Color& arg) {
    r = arg.r;
    g = arg.g;
    b = arg.b;
    a = arg.a;
    return *this;
}

/*-----------------------------------------------------------------*/
Color& Color::operator+(const Color& arg) {
    r += arg.r;
    g += arg.g;
    b += arg.b;
    a += arg.a;
    return *this;
}

/*-----------------------------------------------------------------*/
Color& Color::operator-(const Color& arg) {
    r -= arg.r;
    g -= arg.g;
    b -= arg.b;
    a -= arg.a;
    return *this;
}

/*-----------------------------------------------------------------*/
Color& Color::operator*(const Color& arg) {
    r *= arg.r;
    g *= arg.g;
    b *= arg.b;
    a *= arg.a;
    return *this;
}

/*-----------------------------------------------------------------*/
Color& Color::operator/(const Color& arg) {
    r /= arg.r;
    g /= arg.g;
    b /= arg.b;
    a /= arg.a;
    return *this;
}
