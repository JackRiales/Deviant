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
#include "Deviant/Utilities/StringUtils.hpp"
#include "Deviant/Utilities/Debug.hpp"
using namespace dv;

/*-----------------------------------------------------------------*/
/* Static Declarations --------------------------------------------*/
/*-----------------------------------------------------------------*/
std::map<std::string, ConfigMap> ConfigManager::_configTable;
std::string ConfigManager::_defaultSet = "Default";
std::string ConfigManager::_defaultFileExt = ".conf";

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
    AddConfig(_defaultSet, key, value);
}

/*-----------------------------------------------------------------*/
std::vector<ConfigManager::Config> ConfigManager::GetConfigSet(const std::string& setName) {
    ConfigMap* cSet = 0;

    // Iterate through the table to get the set
    for (auto itr = _configTable.begin(); itr != _configTable.end(); ++itr) {
        if (itr->first == setName) {
            // This is the set we want.
            cSet = &itr->second;
        }
    }

    if (cSet == 0) {
        // We couldn't fine the set by that name
        Debug::warn("Set name " + setName + " was not found. Returning empty config set.");
        return std::vector<Config>();
    } else {
        // Create a vector of configs
        std::vector<Config> configs;
        for (auto itr = cSet->begin(); itr != cSet->end(); ++itr) {
            Config c;
            c.key = itr->first;
            c.value = itr->second;
            configs.push_back(c);
        }
        return configs;
    }
}

/*-----------------------------------------------------------------*/
std::string ConfigManager::GetConfig(const std::string& setName, const std::string& key) {
    std::vector<Config> setConfigs = GetConfigSet(setName);
    for (auto itr = setConfigs.begin(); itr != setConfigs.end(); ++itr) {
        if (itr->key == key) {
            return itr->value;
        }
    }
    Debug::warn("Could not find config with the key " + key + " in the set " + setName);
    return "";
}

/*-----------------------------------------------------------------*/

int ConfigManager::GetIntConfig(const std::string& setName, const std::string& key) {
    return StringUtils::StringToInt(GetConfig(setName, key));
}

/*-----------------------------------------------------------------*/
bool ConfigManager::Read(const std::string& fileName, bool append) {
    // Start the input stream
    std::ifstream in ((fileName + _defaultFileExt).c_str());

    // Check the file stream
    if (!in) {
        Debug::err("Output stream could not be created.", "");
        return false;
    }

    // If we're not appending, go ahead and clear the map.
    if (!append) _configTable.clear();

    // Begin reading from the file line by line
    std::string line;
    std::string currentSet;
    while (getline (in, line)) {
        // Check if we're getting a set name or a value
        std::size_t foundSet = line.find('[');
        if (foundSet != std::string::npos) {
            // We found a set. Replace the brackets with null strings and use the line as a set name.
            currentSet = line;
            currentSet.erase(std::remove(currentSet.begin(), currentSet.end(), '['), currentSet.end());
            currentSet.erase(std::remove(currentSet.begin(), currentSet.end(), ']'), currentSet.end());

            // If we're appending, we need to be careful not to have duplicate sets.
            if (append && _configTable.find(currentSet) != _configTable.end()) {
                // We're reading in a set name that already exists. That can't happen.
                Debug::warn("Attempting to append a set name that already exists. Reading cannot continue.");
                return false;
            }
        } else {
            // We didn't get a new set, so let's find a variable instead
            std::size_t foundValue = line.find('=');
            if (foundValue != std::string::npos) {
                // We need to make sure that there's a set that this value belongs to.
                if (currentSet == "") {
                    Debug::err("Could not read file " + fileName + _defaultFileExt + ".", "Syntax error. No set defined for variable.");
                    return false;
                }

                // Split the string and get the key and value strings
                std::string key, value;
                for (unsigned i = 0; i < line.length(); ++i) {
                    if (line[i] == '=') {
                        // Found the delimiter, get all chars before and after
                        std::string tmp_line = line;
                        key = line.replace(i, line.length() - i, "");
                        value = tmp_line.replace(0, i + 1, "");
                        Debug::out("Parsed out key = " + key);
                        Debug::out("Parsed out value = " + value);
                    }
                }

                // It's time to add to the table.
                Debug::out ("Adding config (" + key + "," + value + ") into the set " + currentSet);
                AddConfig(currentSet, key, value);

            } else {
                // Found a newline, or a syntax error. Either way, do nothing.
            }
        }
    }

    return true;
}

/*-----------------------------------------------------------------*/
bool ConfigManager::WriteAll(const std::string& fileName) {
    // Start the output stream
    std::ofstream out((fileName + _defaultFileExt).c_str());

    // Check file stream
    if (!out) {
        Debug::err("Output stream could not be created.", "");
        return false;
    }

    // Iterate through the config table.
    for (auto itr = _configTable.begin(); itr != _configTable.end(); ++itr) {
        // Begin a set by writing its key name
        out << "[" << itr->first << "]" << std::endl;

        // Iterate over its configuration map and write each variable
        for (auto var_itr = itr->second.begin(); var_itr != itr->second.end(); ++var_itr) {
            out << var_itr->first << "=" << var_itr->second << std::endl;
        }

        // Separate each set, so it looks nicer
        out << std::endl;
    }

    // Close the output stream.
    out.close();
    return true;
}

/*-----------------------------------------------------------------*/
void ConfigManager::SetDefaultFileExtension(const std::string& ext) {
    _defaultFileExt = ext;
}

/*-----------------------------------------------------------------*/
std::string ConfigManager::DefaultFileExtension() {
    return _defaultFileExt;
}
