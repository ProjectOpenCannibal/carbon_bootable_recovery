/*
* Copyright (C) 2015 Project Open Cannibal
* Copyright (C) 2015 CarbonROM
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef RECOVERY_SETTINGS_H
#define RECOVERY_SETTINGS_H

#include "iniparser/dictionary.h"
#include "iniparser/iniparser.h"

#include "../rdestl/rde_string.h"
using namespace rde;

class Settings {
public:
    static dictionary * SettingsDictionary;

    static void StartMenu(Device* device);
    static void Load();
    static void Save(const char *setting, const char *value);

    static int GetInt(const char *SettingItem, int defaultret);
    static string GetString(const char* SettingItem, char* defaultret);
    static int GetBool(const char *SettingItem, bool defaultret);
};


#endif //RECOVERY_SETTINGS_H
