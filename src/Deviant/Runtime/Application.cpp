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

#include "Deviant/Runtime/Application.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
std::string     Application::_header;
unsigned        Application::_width;
unsigned        Application::_height;
unsigned        Application::_defaultWidth;
unsigned        Application::_defaultHeight;
float           Application::_widthRatio;
float           Application::_heightRatio;
unsigned        Application::_framerate;
bool            Application::_running;
int             Application::_verbosity;
SDL_Window*     Application::_window    = NULL;
Timer           Application::_timer;

/*-----------------------------------------------------------------*/
bool Application::Initialize(std::string header, unsigned width, unsigned height, unsigned defaultWidth, unsigned defaultHeight, unsigned framerate, int verbosity) {
    Debug::out("Initializing Deviant. Please wait for awesome things to happen.", ANSI_COLOR_CYAN);
    _header = header;
    _width = width;
    _height = height;
    _defaultWidth = defaultWidth;
    _defaultHeight = defaultHeight;
    _framerate = framerate;
    _verbosity = verbosity;

    // Initialize SDL
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Initializing SDL state...");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::string errString = "Application::Initialize failed to initialize SDL modules.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::err(errString, SDL_GetError());
        return false;
    }

    // Set render scale quality to '1'
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Hinting render scale quality...");
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::string warnString = "Application::Initialize couldn't set render scale quality.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::warn(warnString);
        throw warnString;
    }

    // Create a window
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Creating window...");
    _window = SDL_CreateWindow(_header.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               _width, _height, SDL_WINDOW_SHOWN);
    if (_window == NULL) {
        std::string errString = "Application::Initialize failed to generate a window.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::err(errString, SDL_GetError());
        return false;
    }

    // Create the renderer
    /*if (_verbosity >= VERBOSITY_LOG) Debug::out("Creating renderer...");
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == NULL) {
        std::string errString = "Application::Initialize failed to generate the renderer.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::err(errString, SDL_GetError());
        return false;
    }*/

    // Initialize IMG
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Initializing IMG...");
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::string errString = "Application::Initialize failed to initialize SDL_image.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::err(errString, IMG_GetError());
        throw errString; // should this be a death sentence?
        /* return false */
    }

    // Initialize TTF
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Initializing TTF...");
    if (TTF_Init() == -1) {
        std::string errString = "Application::Initialize failed to initialize SDL_ttf.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::err(errString, TTF_GetError());
        throw errString; // should this be a death sentence?
        /* return false */
    }

    // Initialize the mixer module
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Initializing Mixer...");
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::string errString = "Application::Initialize failed to initialize SDL_mixer.";
        if (_verbosity >= VERBOSITY_LIMITED) Debug::err(errString, Mix_GetError());
        throw errString; // should this be a death sentence?
        /* return false */
    }

    // Set the resolution ratios
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Setting resolution ratios...");
    if (_verbosity == VERBOSITY_ALL) Debug::out("Input calculation for width: " + std::to_string(float(_width)) + " / " + std::to_string(float(_defaultWidth)));
    if (_verbosity == VERBOSITY_ALL) Debug::out("Input calculation for height: " + std::to_string(float(_height)) + " / " + std::to_string(float(_defaultHeight)));
    _widthRatio = float(_width) / float(_defaultWidth);
    _heightRatio = float(_height) / float(_defaultHeight);

    if (_verbosity > VERBOSITY_LOG) Debug::out("Ratios set:\n\tWidth: " + std::to_string(_widthRatio) + "\n\tHeight: " + std::to_string(_heightRatio));
    if (_verbosity > VERBOSITY_LOG) Debug::out("Setting render scale...");
    //SDL_RenderSetScale(_renderer, _widthRatio, _heightRatio);

    return true;
}

/*-----------------------------------------------------------------*/
int Application::Run() {
    Debug::out("Beginning run of " + _header + ".", ANSI_COLOR_CYAN);

    // Application now running
    _running = true;

    // Calculated number of ticks per frame given the frame rate
    float tpf = 1000 / _framerate;

    // SDL event handler
    SDL_Event e;

    // Main loop
    while (_running) {
        // Start this frame's timer
        _timer.start();

        // SDL frame events
        while (SDL_PollEvent(&e) != 0) {
            // Log window events
            if (e.type == SDL_WINDOWEVENT && _verbosity >= VERBOSITY_LOG) {
                switch(e.window.event) {
                case SDL_WINDOWEVENT_MOVED:
                    Debug::out("Window " + std::to_string(e.window.windowID) + " moved to " + std::to_string(e.window.data1) + ", " + std::to_string(e.window.data2) + ".");
                    break;
                case SDL_WINDOWEVENT_MINIMIZED:
                    Debug::out("Window " + std::to_string(e.window.windowID) + " minimized.");
                    break;
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    Debug::out("Window " + std::to_string(e.window.windowID) + " focus gained.");
                    break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    Debug::out("Window " + std::to_string(e.window.windowID) + " focus lost.");
                    break;
                case SDL_WINDOWEVENT_CLOSE:
                    Debug::out("Window " + std::to_string(e.window.windowID) + " closed.");
                    break;
                }
            }

            // Handle application quit event
            else if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                _running = false;
                break;
            }

            // Handle fullscreen toggler
            else if (e.key.keysym.sym == SDLK_F5) {
                SetFullscreen(!IsFullscreen()); // TODO: fix
            }

            Input::handleInputEvents(&e);
        }

        // Render method
        /*renderStart();
        render();
        renderEnd();*/

        // FPS cap
        unsigned frameTicks = _timer.getTicks();
        if (frameTicks < tpf) {
            SDL_Delay(tpf - frameTicks);
        }
    }

    // Clean up
    exit();
    return 0;
}

/*-----------------------------------------------------------------*/
void Application::SetHeader(std::string header) {
    _header = header;
    refreshWindow();
}

/*-----------------------------------------------------------------*/
void Application::SetResolution(unsigned width, unsigned height) {
    _width = width;
    _height = height;
    refreshWindow();
}

/*-----------------------------------------------------------------*/
void Application::SetFullscreen(bool fullscreen) {
    if (fullscreen && !IsFullscreen()) {
        if (_verbosity >= VERBOSITY_LOG) Debug::out("Setting up fullscreen...");
        SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
    }

    else if (!fullscreen && IsFullscreen()) {
        if (_verbosity >= VERBOSITY_LOG) Debug::out("Turning off fullscreen...");
        SDL_SetWindowFullscreen(_window, 0);
    }
}

/*-----------------------------------------------------------------*/
std::string Application::Header() {
    return Application::_header;
}

/*-----------------------------------------------------------------*/
unsigned Application::ScreenWidth() {
    return Application::_width;
}

/*-----------------------------------------------------------------*/
unsigned Application::ScreenHeight() {
    return Application::_height;
}

/*-----------------------------------------------------------------*/
bool Application::IsFullscreen() {
    return (SDL_GetWindowFlags(_window) & SDL_WINDOW_FULLSCREEN);
}

/*-----------------------------------------------------------------*/
bool Application::IsRunning() {
    return Application::_running;
}

/*-----------------------------------------------------------------*/
void Application::refreshWindow() {
    // Destroy the current window
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Destroying window...");
    if (_window != NULL) {
        SDL_DestroyWindow(_window);
        _window = NULL;
    } else {
        throw Debug::Exception("Application window shown null.", Debug::Exception::WARN, "Application::refreshWindow");
    }

    // Create a window
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Creating new window...");
    _window = SDL_CreateWindow(_header.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               _width, _height, SDL_WINDOW_SHOWN);
    if (_window == NULL) {
        throw Debug::Exception("Failed to generate a window.", Debug::Exception::ERR, "Application::refreshWindow");
    }
}

/*-----------------------------------------------------------------*/
void Application::exit() {
    if (_verbosity >= VERBOSITY_LOG) Debug::out("Cleaning up renderer...");
    /*if (_renderer != NULL) {
        SDL_DestroyRenderer(_renderer);
        _renderer = NULL;
    }*/

    if (_verbosity >= VERBOSITY_LOG) Debug::out("Cleaning up window...");
    if (_window != NULL) {
        SDL_DestroyWindow(_window);
        _window = NULL;
    }

    Debug::out("Exiting Deviant. Bye!", ANSI_COLOR_CYAN);
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

// EOF Application.cpp
// Location at: /src/Deviant/Base/Application.cpp
