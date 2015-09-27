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

#include "Deviant/Base/Timer.hpp"
#include "Deviant/Base/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
Timer::Timer():
_start(0),
_pause(0),
_started(false),
_paused(false) {
    ;
}

/*-----------------------------------------------------------------*/
void Timer::start() {
    _started = true;
    _paused = false;

    _start = SDL_GetTicks();
    _pause = 0;
}

/*-----------------------------------------------------------------*/
void Timer::stop() {
    _started = false;
    _paused = false;

    _start = 0;
    _pause = 0;
}

/*-----------------------------------------------------------------*/
void Timer::pause() {
    if (_started) {
        if (!_paused) {
            _paused = true;
            _pause = SDL_GetTicks() - _start;
            _start = 0;
        } else
            Debug::warn("Timer::pause(): Attempted timer pause while already paused.");
    } else
        Debug::warn("Timer::pause(): Attempted timer pause while not started.");
}

/*-----------------------------------------------------------------*/
void Timer::unpause() {
    if (_started) {
        if (_paused) {
            _paused = false;
            _start = SDL_GetTicks() - _pause;
            _pause = 0;
        } else
            Debug::warn("Timer::unpause(): Attempted timer unpause while not paused.");
    } else
        Debug::warn("Timer::unpause(): Attempted timer unpause while not started.");
}

/*-----------------------------------------------------------------*/
Uint32 Timer::getTicks() {
    Uint32 time = 0;

    if (_started) {
        if (_paused) {
            time = _pause;
        } else {
            time = SDL_GetTicks() - _start;
        }
    } else
        Debug::warn("Timer::getTicks(): Attempted to get ticks while not started. Returning 0.");

    return time;
}

/*-----------------------------------------------------------------*/
bool Timer::isStarted() {
    return _started;
}

/*-----------------------------------------------------------------*/
bool Timer::isPaused() {
    return _paused;
}

// EOF Timer.cpp
// Location at: /src/Deviant/Base/Timer.cpp
