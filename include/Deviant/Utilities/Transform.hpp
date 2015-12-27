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

#ifndef DVNT_TRANSFORM_HPP
#define DVNT_TRANSFORM_HPP

#include "Deviant/Utilities/Math/Vector.hpp"
#include <vector>

namespace dv {

/**
    \class Transform2D
    \brief Defines a 2 dimensional transform

    Transform2D will serve the purpose of being the origin point of sprites.
*/
class Transform2D {
    public:
        /**
            \brief Constructor.
        */
        Transform2D();

        /**
            \brief Constructor with position.
            \param position Position to default the transform to.
        */
        Transform2D(Vector2D<float> position);

        /**
            \brief Copy constructor.
            \param cpy Transform to copy from.
            \warning Will not copy children or parent data.
        */
        Transform2D(const Transform2D& cpy);

        /**
            Destructor.
        */
        ~Transform2D();

        /**
            \brief Translate the position to some new position.
            \param deltaPosition The distance to move.
        */
        void translate(Vector2D<float> deltaPosition);

        /**
            \brief Translate the position to some new position.
            \param deltaX The distance to move in the x direction.
            \param deltaY The distance to move in the y direction.
        */
        void translate(float deltaX, float deltaY);

        /**
            \brief Scale the transform by some value.
            \param xScale The <i>x</i> factor of the scale.
            \param yScale the <i>y</i> factor of the scale.
            \example Scaling it by 0.5 will half it, and by 2 will double it.
        */
        void scale(float xScale, float yScale);

        /**
            \brief Rotate the object by some offset.
            \param theta The offset angle.
        */
        void rotate(float theta);

        /**
            \brief Sets the position directly.
            \param position The new position vector.
        */
        void setPosition(Vector2D<float> position);

        /**
            \brief Sets the position directly.
            \param x The new <i>x</i> component of position.
            \param y The new <i>y</i> component of position.
        */
        void setPosition(float x, float y);

        /**
            \brief Sets the scale directly.
            \param scale The new scale vector.
        */
        void setScale(Vector2D<float> scale);

        /**
            \brief Sets the scale directly.
            \param x The new <i>x</i> component of scale.
            \param y The new <i>y</i> component of scale.
        */
        void setScale(float x, float y);

        /**
            \brief Sets the rotation angle directly.
            \param rotation The new angle.
        */
        void setRotation(float rotation);

        /**
            \brief Adds this transform as a child of the given transform.
            \param parent The parent transform to assign this of a child of.
        */
        void setParent(Transform2D& parent);

        /**
            \brief Removes this transform from its parent.
        */
        void removeParent();

        /**
            \return The position.
        */
        Vector2D<float> position() const;

        /**
            \return The scale.
        */
        Vector2D<float> scale() const;

        /**
            \return The angle of rotation.
        */
        float angle() const;

        /**
            \return The number of children.
        */
        int childCount() const;
    private:
        Vector2D<float> _position;
        Vector2D<float> _scale;
        float           _angle;
        Transform2D*    _parent;
        std::vector<Transform2D*> _children;
};

}

#endif // DVNT_TRANSFORM_HPP
