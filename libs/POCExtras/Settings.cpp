/* Copyright (C) 2015 Project Open Cannibal
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

#include "ExternalFuncs.h"
#include "Common.h"
#include "Settings.h"
#include "Storage.h"
#include "Themes.h"
#include "ZipSig.h"
#include "Tests.h"

#include "iniparser/dictionary.h"
#include "iniparser/iniparser.h"

extern RecoveryUI* ui;
dictionary * Settings::SettingsDictionary;

void Settings::StartMenu(Device* device) {
    static const char* MenuHeaders[] = {"Settings", "", NULL};
    static const char* MenuItems[] = {
            "Themes",
            "ZIP Signature Verification",
            "Tests",
            NULL
    };

#define THEMES 0
#define ZIPSIG 1
#define TESTS 2

    for (;;) {
        int MenuSelection = get_menu_selection(MenuHeaders, MenuItems, 0, 0, device);
        switch (MenuSelection) {
            case THEMES:
            {
                Themes::StartMenu(device);
                break;
            }

            case ZIPSIG:
            {
                ZipSig::StartMenu(device);
                break;
            }

            case TESTS:
            {
                Tests::StartMenu(device);
                break;
            }

            default:return;
        }
    }
}

void Settings::Load() {
    Storage::MountCache();

    string BasePath(COT_SETTINGS_LOC);
    SettingsDictionary = iniparser_load(BasePath.c_str());
    if (SettingsDictionary == NULL) {
        FILE * NewIni;
        string BasePath(COT_SETTINGS_LOC);
        NewIni = fopen_path(BasePath.c_str(), "w");
        fprintf(NewIni,
                "; COT Settings INI\n"
                        ";\n"
                        "\n"
                        "[settings]\n"
                        "theme = default\n"
                        "zip_sigverif = 1\n"
                        "enable_tests = 0\n"
                        "\n");
        fclose(NewIni);
        Load();
    }
    Themes::Load(GetString("settings:theme", (char *) "default").c_str());
    return;
}

void Settings::Save(const char* setting, const char* value) {
    Storage::MountCache();
    FILE * SavedIni;
    string BasePath(COT_SETTINGS_LOC);
    SavedIni = fopen_path(BasePath.c_str(), "w");
    iniparser_set(SettingsDictionary, setting, value);
    iniparser_dump_ini(SettingsDictionary, SavedIni);
    fclose(SavedIni);
    return;
}

int Settings::GetInt(const char* SettingItem, int defaultret) {
    return iniparser_getint(SettingsDictionary, SettingItem, defaultret);
}

string Settings::GetString(const char* SettingItem, char* defaultret) {
    string ret(iniparser_getstring(SettingsDictionary, SettingItem, defaultret));
    return ret;
}

int Settings::GetBool(const char* SettingItem, bool defaultret) {
    return iniparser_getboolean(SettingsDictionary, SettingItem, defaultret);
}
