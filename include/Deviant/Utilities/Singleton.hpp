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
    \file   Singleton.hpp
    \author Jack Riales (jack@thatnaughtypanda.com)
    \date   November, 2015
    \ingroup Utilities
*/

#ifndef DVNT_SINGLETON_HPP
#define DVNT_SINGLETON_HPP

namespace dv {

template<class T>
class Singleton {
    public:
        /**
            \return the Singleton instance.
        */
        static T* instance();

        /**
            \return TRUE if the singleton instance exists, FALSE if not.
        */
        static bool exists();
    protected:
        Singleton();
        virtual ~Singleton();
    private:
        Singleton(Singleton const&);
        Singleton& operator=(Singleton const&);
        static T* _instance;
};

}

#endif // DVNT_SINGLETON_HPP

// EOF Singleton.hpp
// Location at: /include/Deviant/Management/Singleton.hpp
