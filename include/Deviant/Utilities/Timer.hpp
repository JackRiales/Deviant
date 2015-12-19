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

#ifndef DVNT_TIMER_HPP
#define DVNT_TIMER_HPP

#include <SDL2/SDL.h>

namespace dv {

class Timer {
    public:
        /**
            \brief Constructor.
         */
        Timer();

        /**
            \brief Start the timer.
         */
        void start();

        /**
            \brief Stop the timer.
         */
        void stop();

        /**
            \brief Pause the timer without stopping it.
         */
        void pause();

        /**
            \brief Unpause the timer.
         */
        void unpause();

        /**
            \brief Get the current ticks.
        */
        Uint32 getTicks();

        /**
            \brief Is the timer started?
        */
        bool isStarted();

        /**
            \brief Is the timer paused?
        */
        bool isPaused();
    private:
        Uint32 _start;
        Uint32 _pause;
        bool _started;
        bool _paused;
};

}

#endif // DVNT_TIMER_HPP


// EOF Timer.hpp
// Location at: /include/Deviant/Base/Timer.hpp
