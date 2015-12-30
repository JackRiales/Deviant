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

#include "Deviant/Rendering/Renderer.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
SDL_Renderer* Renderer::_renderer = NULL;

/*-----------------------------------------------------------------*/
bool Renderer::Initialize(SDL_Window* window, unsigned widthRatio, unsigned heightRatio, int verbosity) {
    if (verbosity >= VERBOSITY_LOG) Debug::out("Initializing Renderer...");
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == NULL) {
        std::string errString = "Application::Initialize failed to generate the renderer.";
        if (verbosity >= VERBOSITY_LIMITED) Debug::err(errString, SDL_GetError());
        return false;
    }
    SDL_RenderSetScale(_renderer, widthRatio, heightRatio);
    return true;
}

/*-----------------------------------------------------------------*/
void Renderer::StartRender() {
    SDL_SetRenderDrawColor(_renderer, 0x45, 0x45, 0x45, 0xFF);
    SDL_RenderClear(_renderer);
}

/*-----------------------------------------------------------------*/
void Renderer::Render(Batcher* batch) {
    batch->render();
}

/*-----------------------------------------------------------------*/
void Renderer::EndRender() {
    SDL_RenderPresent(_renderer);
}

/*-----------------------------------------------------------------*/
void Renderer::Exit() {
    if (_renderer != NULL) {
        SDL_DestroyRenderer(_renderer);
        _renderer = NULL;
    }
}
