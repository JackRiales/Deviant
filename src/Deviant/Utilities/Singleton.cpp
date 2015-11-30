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

#include "Deviant/Utilities/Singleton.hpp"
#include "Deviant/Base/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
template<class T>
T* Singleton<T>::_instance = NULL;

/*-----------------------------------------------------------------*/
template<class T>
T* Singleton<T>::instance() {
    if (_instance == NULL)
        _instance = new T;
    #ifdef __DEBUG__
    assert(_instance != NULL);
    #endif
    return _instance;
}

/*-----------------------------------------------------------------*/
template<class T>
bool Singleton<T>::exists() {
    return (_instance != NULL);
}

/*-----------------------------------------------------------------*/
