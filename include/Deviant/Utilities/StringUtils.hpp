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

#ifndef DVNT_STRING_UTILS_HPP
#define DVNT_STRING_UTILS_HPP

#include <string>

namespace dv {

class StringUtils {
public:
    static std::string IntToString(int i);
    static std::string FloatToString(float f);
    static std::string BooleanToString(bool b);
    static int StringToInt(const std::string& text);
    static bool StringToBoolean(const std::string& text);
};

}

#endif // DVNT_STRING_UTILS_HPP
