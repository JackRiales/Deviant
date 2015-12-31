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

#ifndef DVNT_RENDER_NODE_HPP
#define DVNT_RENDER_NODE_HPP

namespace dv {

/**
    \interface
    \brief An interface used to contract a class to define a method for a draw call.
*/
class IRenderNode {
    public:
        /**
            \brief Destructor.

            Called during deallocation in the Batcher it's attached to.
            Subclasses of IRenderNode must define a destructor to have
            consistent behavior during the garbage collection process.
         */
        virtual ~IRenderNode() { ; }

        /**
            \brief Used to draw something onto the draw buffer.

            Subclasses of IRenderNode will define their own draw methods
            to be called during a batched render.

            \example A sprite would use a texture, texture region, and a transform
            to draw a part of a loaded image in at the correct position.
        */
        virtual void draw() = 0;
};

}

#endif // DVNT_BATCHER_HPP

