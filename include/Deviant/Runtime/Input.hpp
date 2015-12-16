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
    \file   Input.hpp
    \author Jack Riales (jack@thatnaughtypanda.com)
    \date   September, 2015
    \ingroup Base
*/

#ifndef DVNT_INPUT_HPP
#define DVNT_INPUT_HPP

#include <queue>
#include <vector>
#include <functional>
#include <SDL2/SDL.h>
#include "Deviant/Utilities/Math/Vector.hpp"

namespace dv {

class Input {
    public:
        /**
            \brief Returns if the given key is pressed down this frame (continuous).
        */
        static bool KeyDown();

        /**
            \brief Returns if the given key is pressed down this frame (noncontinuous).
        */
        static bool KeyPressed();

        /**
            \brief Gives the mouse position.
            \return Mouse position.
        */
        static Vector2D<int> MousePosition();

        struct EventListener {
            int priority;
            /* Object reference */
            bool operator<(const EventListener& comparator);
            bool operator()() const;
        };
    private:
        /**
            \brief Event queue contains all event listeners and associated key binding, sorted by priority.
        */
        std::priority_queue< EventListener, std::vector<EventListener>, std::less<EventListener> > _eventQueue;

        /**
            \brief Handles all events in the event queue during the main poll.
            \throw Exception if unable to handle certain listener.
        */
        static void handleInputEvents(SDL_Event *e);

        // Application needs privacy access to handle input events
        friend class Application;
};

}

#endif // DVNT_INPUT_HPP

// EOF Input.hpp
// Location at: /include/Deviant/Base/Input.hpp
