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

#ifndef DVNT_CONFIGURATION_HPP
#define DVNT_CONFIGURATION_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

namespace dv {

/**
    \typedef A set of config variables organized by index (int) and var (key and value)
*/
typedef std::map<std::string, std::string> ConfigMap;

/**
    \brief Maintains the reading, writing, and containment of configuration variables and their keys.
*/
class ConfigManager {
    private:
        /**
            \struct Config struct used to return singular, properly formatted config vars.
        */
        struct Config {
            std::string key;
            std::string value;
        };

    public:
        /**
            \brief Add a configuration variable to the given set.

            If the set given does not exist, it will be created.
        */
        static void AddConfig(const std::string& setName,
                              const std::string& key,
                              const std::string& value);

        /**
            \brief Add a configuration variable to the default set.
        */
        static void AddConfig(const std::string& key,
                              const std::string& value);

        /**
            \brief Add a config variable with an int rather than a string.
        */
        static void AddIntConfig(const std::string& setName,
                                 const std::string& key,
                                 int value);

        /**
            \brief Add a config variable with an int rather than a string.
        */
        static void AddIntConfig(const std::string& key,
                                 int value);

        /**
            \brief Add a config variable with a boolean rather than a string.
        */
        static void AddBooleanConfig(const std::string& setName,
                                     const std::string& key,
                                     bool value);

        /**
            \brief Add a config variable with a boolean rather than a string.
        */
        static void AddBooleanConfig(const std::string& key,
                                     bool value);

        /**
            \return A vector array of configs from the given set.
            \throw Exception if no set by the given name is found.
        */
        static std::vector<Config> GetConfigSet(const std::string& setName);

        /**
            \return The config in the given set defined by the given key.
        */
        static std::string GetConfig(const std::string& setName, const std::string& key);

        /**
            \return the config in the given set defined by the given key, converted to an int if possible.
            \return 0 if unable to convert.
        */
        static int GetIntConfig(const std::string& setName, const std::string& key);

        /**
            \return the config in the given set defined by the given key, converted to an int if possible.
            \return False if unable to convert.
        */
        static bool GetBoolConfig(const std::string& setName, const std::string& key);

        /**
            \brief Read settings from a previously written config file.
            \warning Don't put the file extension in the file name. That is done automatically.
            \return True if the file was opened and read properly, false if not.
        */
        static bool Read(const std::string& fileName, bool append = true);

        /**
            \brief Write all current settings to a config file.
            \warning Don't put the file extension in the file name. That is done automatically.
            \return True if the stream was created and written to successfully, false if not.
        */
        static bool WriteAll(const std::string& fileName);

        /**
            \brief Sets new default file extension.
        */
        static void SetDefaultFileExtension(const std::string& ext);

        /**
            \return Default file extension. In most cases, ".conf" unless previously changed.
        */
        static std::string DefaultFileExtension();

    private:
        /**
            \brief A map container of config maps that will define a config table.

            Each map will have a name (string) that will contain a series of
            configuration variables, all grouped together.
        */
        static std::map<std::string, ConfigMap> _configTable;

        /**
            \brief The current default config set.

            Without specifying which set to add or read
            from, or write to, the default will be whatever the active is.
        */
        static std::string _defaultSet;

        /**
            \brief The default file extension that will be applied to config files.

            Without the user changing it, it will be ".conf"
        */
        static std::string _defaultFileExt;
};

}

#endif // DVNT_CONFIGURATION_HPP
