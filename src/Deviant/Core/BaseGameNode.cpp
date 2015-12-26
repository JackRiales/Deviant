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

#include "Deviant/Core/BaseGameNode.hpp"
#include "Deviant/Utilities/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
BaseGameNode::BaseGameNode() :
_id (-1),
_static (false),
_rendered (true),
_parent (NULL) {
    ;
}

/*-----------------------------------------------------------------*/
BaseGameNode::BaseGameNode(Vector2D<float> position) :
_id (-1),
_position (position),
_static (false),
_rendered (true),
_parent (NULL) {
    ;
}

/*-----------------------------------------------------------------*/
BaseGameNode::~BaseGameNode() {
    // Clean parent reference
    if (_parent != NULL) {
        /*delete _parent;*/
        _parent = NULL;
    }

    // Delete and clean children
    for (unsigned int i = 0; i < _children.size(); i++) {
        if (_children[i] != NULL) {
            /*delete _children[i];*/
            _children[i]->_parent = NULL;
            _children[i] = NULL;
        }
    }
}

/*-----------------------------------------------------------------*/
void BaseGameNode::start() {
    /*
        BaseGameNode Start Event

        Not to be confused with awake(), start() runs
        when the game state begins.

        This should be used for interactions with the world,
        since its performed when the world is ready for it,
        instead of for the object-centric purposes (initialization, etc).
        Use a constructor for that instead.
    */
    ;
}

/*-----------------------------------------------------------------*/
void BaseGameNode::update() {
    /*
        Game Node Update Event

        Called every update pass.
    */
    ;
}

/*-----------------------------------------------------------------*/
void BaseGameNode::draw() {
    /*
        Game Node Draw Event

        Called for the render pass. Intended to be used for
        graphical rendering.
    */
}

// EOF BaseGameNode.cpp
// Location at: /src/Deviant/Base/BaseGameNode.cpp
