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

#include "Deviant/Utilities/StringUtils.hpp"
#include "Deviant/Utilities/Debug.hpp"
#include <sstream>
using namespace dv;

/*-----------------------------------------------------------------*/
std::string StringUtils::IntToString(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

/*-----------------------------------------------------------------*/
std::string StringUtils::FloatToString(float f) {
    std::stringstream ss;
    ss << f;
    return ss.str();
}

/*-----------------------------------------------------------------*/
std::string StringUtils::BooleanToString(bool b) {
    if (b)
        return "true";
    else
        return "false";
}

/*-----------------------------------------------------------------*/
int StringUtils::StringToInt(const std::string& text) {
    std::istringstream buffer (text);
    int num;
    buffer >> num;
    return num;
}

/*-----------------------------------------------------------------*/
bool StringUtils::StringToBoolean(const std::string& text) {
    if (text == "false" || text == "FALSE" || text == "f" || text == "F")
        return false;
    else if (text == "true" || text == "TRUE" || text == "t" || text == "T")
        return true;
    else {
        Debug::warn("Could not cast text to a boolean. Returning false. String given: " + text);
        return false;
    }
}
