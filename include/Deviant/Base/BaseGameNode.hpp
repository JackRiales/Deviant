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

#ifndef DVNT_BASEGAMENODE_HPP
#define DVNT_BASEGAMENODE_HPP

#include <vector>
#include "Deviant/Math/Vector.hpp"

namespace dv {

/**
    \class BaseGameNode
    \brief Abstract definition for a basic game node.
*/
class BaseGameNode {
    public:
        /**
            Base constructor. Initializes object at position (0,0)
        */
        BaseGameNode();

        /**
            Positional constructor. Initializes object at given position.
            \param position The position.
        */
        BaseGameNode(Vector2D<float> position);

        /**
            Destructor.
        */
        virtual ~BaseGameNode();

        /* === EVENTS === */
        virtual void start();
        virtual void update();
        virtual void draw();

    private:
        /**
            The designated unique node id. Used for indexing.
        */
        int _id;

        /**
            The node's on-screen position. Usable even if the object is non-rendered.
        */
        Vector2D<float> _position;

        /**
            Determines if the object is considered static.
            A static node does not perform updates.
        */
        bool _static;

        /**
            Determines if the node is able to perform its draw call (if applicable).
        */
        bool _rendered;

        /**
            Transform parent.
        */
        BaseGameNode* _parent;

        /**
            Transform children.
        */
        std::vector<BaseGameNode*> _children;
};

}

#endif // DVNT_BASEGAMENODE_HPP

// EOF BaseGameNode.hpp
// Location at: /include/Deviant/Base/BaseGameNode.hpp
