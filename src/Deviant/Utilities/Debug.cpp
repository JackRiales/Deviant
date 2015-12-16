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

#include "Deviant/Utilities/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
void Debug::out(std::string message, std::string color) {
    std::string output = color + message + ANSI_COLOR_RESET + "\n";
    printf(output.c_str());
}

/*-----------------------------------------------------------------*/
void Debug::warn(std::string message, std::string color) {
    std::string output = color + "Warning: " + message + ANSI_COLOR_RESET + "\n";
    printf(output.c_str());
}

/*-----------------------------------------------------------------*/
void Debug::err(std::string message, std::string error, std::string color) {
    std::string output = color + message + "\n\tError Message: " + error + ANSI_COLOR_RESET + "\n";
    printf(output.c_str());
}

/*-----------------------------------------------------------------*/
Debug::Exception::Exception(std::string message, LogLevel level, std::string location) :
_ll (level),
_message (message),
_locale (location) {

}

/*-----------------------------------------------------------------*/
void Debug::Exception::output() {
    std::string out = _locale + " : " + _message;
    switch(_ll) {
    case LOG:
        Debug::out(out);
        break;
    case WARN:
        Debug::warn(out);
        break;
    case ERR:
        Debug::err("A serious error has occurred.", out);
        break;
    case FATAL:
        Debug::err("A fatal error has occurred.", out);
        break;
    }
}

// EOF Debug.cpp
// Location at: /src/Deviant/Base/Debug.cpp
