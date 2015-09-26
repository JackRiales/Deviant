/*
    Deviant - SFML Game Library
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

#include "Deviant/Base/Application.hpp"
#include "Deviant/Base/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
std::string     Application::_header;
unsigned int    Application::_width;
unsigned int    Application::_height;
unsigned int    Application::_framerate;
bool            Application::_running;
SDL_Window*     Application::_window    = NULL;
SDL_Renderer*   Application::_renderer  = NULL;

/*-----------------------------------------------------------------*/
bool Application::Initialize(std::string header, unsigned int width, unsigned int height) {
    Debug::out("Initializing Deviant. Please wait for awesome things to happen.\n", ANSI_COLOR_CYAN);
    _header = header;
    _width = width;
    _header = height;
}

/*-----------------------------------------------------------------*/
int Application::Run() {
    return 0;
}

/*-----------------------------------------------------------------*/
void Application::SetHeader(std::string header) {

}

/*-----------------------------------------------------------------*/
void Application::SetResolution(unsigned int width, unsigned int height) {

}

/*-----------------------------------------------------------------*/
void Application::SetFullscreen(bool fullscreen) {

}

/*-----------------------------------------------------------------*/
std::string Application::Header() {
    return Application::_header;
}

/*-----------------------------------------------------------------*/
unsigned int Application::ScreenWidth() {
    return Application::_width;
}

/*-----------------------------------------------------------------*/
unsigned int Application::ScreenHeight() {
    return Application::_height;
}

/*-----------------------------------------------------------------*/
bool Application::IsFullscreen() {
    return false;
}

/*-----------------------------------------------------------------*/
bool Application::IsRunning() {
    return Application::_running;
}

/*-----------------------------------------------------------------*/
SDL_Renderer* Application::GetRenderer() {
    return Application::_renderer;
}

/*-----------------------------------------------------------------*/
void Application::renderStart() {

}

/*-----------------------------------------------------------------*/
void Application::render() {

}

/*-----------------------------------------------------------------*/
void Application::renderEnd() {

}

/*-----------------------------------------------------------------*/
void Application::refreshWindow() {

}

/*-----------------------------------------------------------------*/
void Application::exit() {

}

// EOF Application.cpp
// Location at: /src/Deviant/Base/Application.cpp
