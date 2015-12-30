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

#ifndef DVNT_RENDERER_HPP
#define DVNT_RENDERER_HPP

#include "Deviant/Rendering/Batcher.hpp"
#include "Deviant/Utilities/Debug.hpp"
#include <SDL2/SDL.h>

namespace dv {

/**
    \class
    \brief Defines the deviant render engine to be used in runtime.
*/
class Renderer {
    public:
        /**
            \brief Initializes the renderer module.
        */
        static bool Initialize(SDL_Window* window, unsigned widthRatio, unsigned heightRatio, int verbosity = VERBOSITY_LIMITED);

        /**
            \brief Begins a render pass
        */
        static void StartRender();

        /**
            \brief Renders the given batch. May be run multiple times during a pass.
            \param batch The batch of nodes to render.
        */
        static void Render(Batcher* batch);

        /**
            \brief Displays the render buffer to the screen.
        */
        static void EndRender();

        /**
            \brief Disables and frees the memory from the module.
        */
        static void Exit();
    private:
        static SDL_Renderer* _renderer;
};

}

#endif // DVNT_RENDERER_HPP
