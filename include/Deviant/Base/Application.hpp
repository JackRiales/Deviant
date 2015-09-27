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
    \file   Application.hpp
    \author Jack Riales (jack@thatnaughtypanda.com)
    \date   September, 2015
    \ingroup Base
*/

#ifndef DVNT_APPLICATION_HPP
#define DVNT_APPLICATION_HPP

// Inclusions
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Timer.hpp"

// Log verbosity constants
#define VERBOSITY_NONE 0
#define VERBOSITY_LIMITED 1
#define VERBOSITY_ERROR 2
#define VERBOSITY_WARN 3
#define VERBOSITY_LOG 4
#define VERBOSITY_ALL 5

namespace dv {

/**
    \class Application
    \brief  Primary application-controlling class, responsible for windowing and maintaining context.
    Application is a class responsible for opening and maintaining a window and its context, as well as operate SDL's needs and perform layered rendering in a main loop.
*/
class Application {
    public:
        /**
            \brief Initializes the SDL context.
            \param Window header.
            \param Window resolution width.
            \param Window resolution height.
            \return TRUE if initialized correctly, FALSE if not.
            \throw SDL initialization messages.
        */
        static bool Initialize(std::string header = "Deviant Application",
                               unsigned width = 800, unsigned height = 600,
                               unsigned defaultWidth = 600, unsigned defaultHeight = 600,
                               unsigned framerate = 60, int verbosity = VERBOSITY_LIMITED);

        /**
            \brief Application run method.
            Runs main loop of the application.
        */
        static int Run();

        /**
            \brief Change the header.
        */
        static void SetHeader(std::string header);

        /**
            \brief Set the resolution.
        */
        static void SetResolution(unsigned width, unsigned height);

        /**
            \brief Change fullscreen to on or off.
        */
        static void SetFullscreen(bool fullscreen);

        /**
            \return header.
        */
        static std::string  Header();

        /**
            \return resolution width.
        */
        static unsigned ScreenWidth();

        /**
            \return resolution height.
        */
        static unsigned ScreenHeight();

        /**
            \return TRUE if window is fullscreen, FALSE if not.
        */
        static bool IsFullscreen();

        /**
            \return TRUE if running, FALSE if not.
        */
        static bool         IsRunning();

        /**
            \return SDL renderer.
        */
        static SDL_Renderer* GetRenderer();

    protected:
        /**
            \brief Clear the buffer for draw.
        */
        static void renderStart();

        /**
            \brief Draw all render nodes.
        */
        static void render();

        /**
            \brief Display the buffer.
        */
        static void renderEnd();

        /**
            \brief Recreate the window based on the current values.
        */
        static void refreshWindow();

        /**
            \brief Close the window and clean up all nodes.
        */
        static void exit();

    private:
        static std::string          _header;
        static unsigned             _width;
        static unsigned             _height;
        static unsigned             _defaultWidth;
        static unsigned             _defaultHeight;
        static float                _widthRatio;
        static float                _heightRatio;
        static unsigned             _framerate;
        static bool                 _running;
        static int                  _verbosity;
        static SDL_Window*          _window;
        static SDL_Renderer*        _renderer;
        static Timer                _timer;
};

} // Exit dv namespace


#endif // DVNT_APPLICATION_HPP

// EOF Application.hpp
// Location at: /include/Deviant/Base/Application.hpp
