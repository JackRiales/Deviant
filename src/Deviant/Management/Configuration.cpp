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

#include "Deviant/Management/Configuration.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
std::map<std::string, ConfigMap> ConfigManager::_configTable;
std::string ConfigManager::_activeSet = "Default";

/*-----------------------------------------------------------------*/
void ConfigManager::AddConfig(const std::string& setName, const std::string& key, const std::string& value) {
    // Search if the set name is already in place
    if (_configTable.find(setName) == _configTable.end()) {
        // Not found, create a new one
        ConfigMap newMap;
        newMap.insert(std::pair<std::string, std::string>(key, value));
        _configTable.insert(std::pair<std::string, ConfigMap>(setName, newMap));
    } else {
        // Found, add it to that set's config map
        _configTable[setName].insert(std::pair<std::string, std::string>(key, value));
    }
}

/*-----------------------------------------------------------------*/
void ConfigManager::AddConfig(const std::string& key, const std::string& value) {
    AddConfig(_activeSet, key, value);
}

/*-----------------------------------------------------------------*/
bool ConfigManager::Read(std::string fileName) {
    return 0;
}

/*-----------------------------------------------------------------*/
bool ConfigManager::WriteAll(std::string fileName) {
    return 0;
}
