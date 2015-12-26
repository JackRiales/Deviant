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

#include "Deviant/Utilities/Transform.hpp"
#include "Deviant/Utilities/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
Transform2D::Transform2D():
_parent (0) {
    ;
}

/*-----------------------------------------------------------------*/
Transform2D::Transform2D(Vector2D<float> position):
_position (position),
_parent (0) {
    ;
}

/*-----------------------------------------------------------------*/
Transform2D::Transform2D(const Transform2D& cpy):
_position (cpy._position),
_scale (cpy._scale),
_angle (cpy._angle),
_parent (0) {
    ;
}

/*-----------------------------------------------------------------*/
Transform2D::~Transform2D() {
    if (_parent != 0) {
        delete _parent;
        _parent = 0;
    }

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        if ((*itr) != 0) delete (*itr);
    }

    _children.clear();
}

/*-----------------------------------------------------------------*/
void Transform2D::translate(Vector2D<float> deltaPosition) {
    _position = _position + deltaPosition;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->translate(deltaPosition);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::translate(float deltaX, float deltaY) {
    _position.x += deltaX;
    _position.y += deltaY;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->translate(deltaX, deltaY);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::scale(float xScale, float yScale) {
    _scale.x *= xScale;
    _scale.y *= yScale;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->scale(xScale, yScale);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::rotate(float theta) {
    _angle += theta;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->rotate(theta);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::setPosition(Vector2D<float> position) {
    _position = position;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->setPosition((*itr)->position() + position);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::setPosition(float x, float y) {
    _position.x = x;
    _position.y = y;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->setPosition((*itr)->position().x + x, (*itr)->position().y + y);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::setScale(Vector2D<float> scale) {
    _scale = scale;

    for(auto itr = _children.begin(); itr != _children.end(); ++itr) {
        (*itr)->setScale((*itr)->scale() + scale);
    }
}

/*-----------------------------------------------------------------*/
void Transform2D::setScale(float x, float y) {
    _scale.x = x;
    _scale.y = y;
}

/*-----------------------------------------------------------------*/
void Transform2D::setRotation(float rotation) {
    _angle = rotation;
}

/*-----------------------------------------------------------------*/
void Transform2D::setParent(Transform2D& parent) {
    _parent = &parent;
    parent._children.push_back(this);
}

/*-----------------------------------------------------------------*/
void Transform2D::removeParent() {
    if (_parent == 0) {
        Debug::warn("Can't remove parent from a transform with no parent.");
    } else {
        for(auto itr = _parent->_children.begin(); itr != _parent->_children.end(); ++itr) {
            if ((*itr) == this) {
                _parent->_children.erase(itr);
                break;
            }
        }
        _parent = 0;
    }
}

/*-----------------------------------------------------------------*/
Vector2D<float> Transform2D::position() const {
    return _position;
}

/*-----------------------------------------------------------------*/
Vector2D<float> Transform2D::scale() const {
    return _scale;
}

/*-----------------------------------------------------------------*/
float Transform2D::angle() const {
    return _angle;
}

/*-----------------------------------------------------------------*/
int Transform2D::childCount() const {
    return _children.size();
}
