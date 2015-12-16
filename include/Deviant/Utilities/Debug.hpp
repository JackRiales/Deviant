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

#ifndef DVNT_DEBUG_HPP
#define DVNT_DEBUG_HPP

#include <stdio.h>
#include <string>

/**
    \def Console coloring. Unix systems only.
*/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define ANSI_COLOR_RED ""
#define ANSI_COLOR_GREEN ""
#define ANSI_COLOR_YELLOW ""
#define ANSI_COLOR_BLUE ""
#define ANSI_COLOR_MAGENTA ""
#define ANSI_COLOR_CYAN ""
#define ANSI_COLOR_RESET ""
#else
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#endif

/**
    \def Verbosity constants
*/
#define VERBOSITY_NONE 0
#define VERBOSITY_LIMITED 1
#define VERBOSITY_ERROR 2
#define VERBOSITY_WARN 3
#define VERBOSITY_LOG 4
#define VERBOSITY_ALL 5

namespace dv {

/**
    \namespace Debug
    \ingroup Utilities
    \brief Defines functions for logging debug information to console.
*/
namespace Debug {

/**
    \brief Outputs a message with a given color.
*/
void out(std::string message, std::string color = ANSI_COLOR_RESET);

/**
    \brief Outputs a message with a yellow color (by default).
*/
void warn(std::string message, std::string color = ANSI_COLOR_YELLOW);

/**
    \brief Outputs a message and a given error with a red console color (by default).
*/
void err(std::string message, std::string error, std::string color = ANSI_COLOR_RED);

/**
    \class
*/
class Exception {
    public:
        /**
            \enum Log Level
            \brief Used for exceptions to determine nature of issue.
        */
        enum LogLevel {
            LOG,
            WARN,
            ERR,
            FATAL
        };

        /**
            \brief Constructor.
        */
        Exception(std::string message, LogLevel level = LogLevel::LOG, std::string location = "");

        /**
            \brief Outputs formatted message to console.
        */
        void output();
    private:
        LogLevel _ll;
        std::string _message;
        std::string _locale;
};

}   // Exit dv
}   // Exit Debug

#endif // DVNT_DEBUG_HPP

// EOF Debug.hpp
// Location at: /src/Deviant/Base/Debug.hpp
