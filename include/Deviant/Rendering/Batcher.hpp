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

#ifndef DVNT_BATCHER_HPP
#define DVNT_BATCHER_HPP

#include "Deviant/Rendering/IRenderNode.hpp"
#include <vector>

namespace dv {

/**
    \class
    \brief Defines a sprite batch used to order render passes
*/
class Batcher {
    public:
        /**
            \brief Deallocates the render node pointers.
            \todo Convert to smart pointers, for safety.
        */
        ~Batcher();

        /**
            \brief Mounts a render node onto the batch.
            \todo Automatically sort nodes by some index.
        */
        void mount(IRenderNode& node);

        /**
            \brief Draws the batch onto the buffer.
            \todo Order draw calls by some ordered index in the nodes.
        */
        void draw();
    private:
        std::vector<IRenderNode*> _batch;
};

}

#endif // DVNT_BATCHER_HPP
