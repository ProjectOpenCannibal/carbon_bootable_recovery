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

#include "ExternalFuncs.h"
#include "Settings.h"
#include "Themes.h"
#include "ThemeVar.h"
#include "Storage.h"

extern RecoveryUI* ui;

void Themes::StartMenu(Device *device) {
    static const char* MenuHeaders[] = {"Select Theme","",NULL};
    static const char* MenuItems[] = { "Default Theme",
                                       "Custom Themes",
                                       NULL
    };
    #define DEFAULT_THEME 0
    #define CUSTOM_THEMES 1

    for (;;) {
        int MenuSelection = get_menu_selection(MenuHeaders, MenuItems, 0, 0, device);
        switch (MenuSelection) {
            case DEFAULT_THEME:
            {
                ThemeVar::CurrentTheme = "default";
                Themes::Load("default");
                Settings::Save("settings:theme", "default");
                break;
            }
            case CUSTOM_THEMES:
                Themes::List(device);
                break;
            case Device::kGoBack:
                return;
            default:break;
        }
    }
}

char* Themes::GetName(const char *themepath) {
    dictionary * ThemeDict;
    string ThemeFile(COT_THEMES_LOC);
    ThemeFile.append(themepath);
    ThemeFile.append("/theme.ini");
    ThemeDict = iniparser_load(ThemeFile.c_str());
    if (ThemeDict == NULL) {
        return NULL;
    }
    return iniparser_getstring(ThemeDict, "theme:name", NULL);
}

void Themes::Load(const char *themename) {
    LOGI("Loading theme %s...\n", themename);

    /* Mount internal storage if possible */
    Storage::MountCache();

    dictionary * ThemeDict;
    if (strcmp(themename, "default")) {
        string ThemeFile(COT_THEMES_LOC);
        ThemeFile.append(themename);
        ThemeFile.append("/theme.ini");
        ThemeDict = iniparser_load(ThemeFile.c_str());
        if (ThemeDict == NULL) {
            LOGI("Can't load theme %s from %s, switching to default!\n", themename, ThemeFile.c_str());
            Load("default");
            return;
        }
        LOGI("Theme %s loaded from %s!\n", themename, ThemeFile.c_str());
        ThemeVar::CurrentTheme = themename;
        ui->ResetIcons();
    } else {
        char * ini_file = "/res/images/default_theme.ini";
        ThemeDict = iniparser_load(ini_file);
        if (ThemeDict == NULL) {
            /* WE SHOULD NEVER GET HERE */
            LOGE("Whoops! Theme error 00001\n");
            return;
        }
        ThemeVar::CurrentTheme = "default";
        ui->ResetIcons();
    }

    ThemeVar::C_HEADER[0] = iniparser_getint(ThemeDict, "theme:header_r", 111);
    ThemeVar::C_HEADER[1] = iniparser_getint(ThemeDict, "theme:header_g", 111);
    ThemeVar::C_HEADER[2] = iniparser_getint(ThemeDict, "theme:header_b", 111);
    ThemeVar::C_HEADER[3] = iniparser_getint(ThemeDict, "theme:header_a", 255);

    ThemeVar::C_TOP[0] = iniparser_getint(ThemeDict, "theme:top_r", 208);
    ThemeVar::C_TOP[1] = iniparser_getint(ThemeDict, "theme:top_g", 208);
    ThemeVar::C_TOP[2] = iniparser_getint(ThemeDict, "theme:top_b", 208);
    ThemeVar::C_TOP[3] = iniparser_getint(ThemeDict, "theme:top_a", 255);

    ThemeVar::C_MENU_SEL_FG[0] = iniparser_getint(ThemeDict, "theme:menufg_r", 25);
    ThemeVar::C_MENU_SEL_FG[1] = iniparser_getint(ThemeDict, "theme:menufg_g", 160);
    ThemeVar::C_MENU_SEL_FG[2] = iniparser_getint(ThemeDict, "theme:menufg_b", 210);
    ThemeVar::C_MENU_SEL_FG[3] = iniparser_getint(ThemeDict, "theme:menufg_a", 255);

    ThemeVar::C_MENU_SEL_BG[0] = iniparser_getint(ThemeDict, "theme:menubg_r", 60);
    ThemeVar::C_MENU_SEL_BG[1] = iniparser_getint(ThemeDict, "theme:menubg_g", 60);
    ThemeVar::C_MENU_SEL_BG[2] = iniparser_getint(ThemeDict, "theme:menubg_b", 61);
    ThemeVar::C_MENU_SEL_BG[3] = iniparser_getint(ThemeDict, "theme:menubg_a", 255);

    ThemeVar::C_LOG[0] = iniparser_getint(ThemeDict, "theme:log_r", 76);
    ThemeVar::C_LOG[1] = iniparser_getint(ThemeDict, "theme:log_g", 76);
    ThemeVar::C_LOG[2] = iniparser_getint(ThemeDict, "theme:log_b", 76);
    ThemeVar::C_LOG[3] = iniparser_getint(ThemeDict, "theme:log_a", 255);

    ThemeVar::C_TEXT_FILL[0] = iniparser_getint(ThemeDict, "theme:textfill_r", 0);
    ThemeVar::C_TEXT_FILL[1] = iniparser_getint(ThemeDict, "theme:textfill_g", 0);
    ThemeVar::C_TEXT_FILL[2] = iniparser_getint(ThemeDict, "theme:textfill_b", 0);
    ThemeVar::C_TEXT_FILL[3] = iniparser_getint(ThemeDict, "theme:textfill_a", 255);

    ThemeVar::C_ERROR_TEXT[0] = iniparser_getint(ThemeDict, "theme:errortext_r", 255);
    ThemeVar::C_ERROR_TEXT[1] = iniparser_getint(ThemeDict, "theme:errortext_g", 0);
    ThemeVar::C_ERROR_TEXT[2] = iniparser_getint(ThemeDict, "theme:errortext_b", 0);
    ThemeVar::C_ERROR_TEXT[3] = iniparser_getint(ThemeDict, "theme:errortext_a", 255);

    ThemeVar::C_DEFAULT[0] = iniparser_getint(ThemeDict, "theme:default_r", 255);
    ThemeVar::C_DEFAULT[1] = iniparser_getint(ThemeDict, "theme:default_g", 255);
    ThemeVar::C_DEFAULT[2] = iniparser_getint(ThemeDict, "theme:default_b", 255);
    ThemeVar::C_DEFAULT[3] = iniparser_getint(ThemeDict, "theme:default_a", 255);

    ThemeVar::BatteryIndicator = iniparser_getstring(ThemeDict, "theme:batteryindicator", (char *) "false");
    ThemeVar::BatteryXPos = iniparser_getint(ThemeDict, "theme:battery_x", 0);
    ThemeVar::BatteryYPos = iniparser_getint(ThemeDict, "theme:battery_y", 0);

    ThemeVar::CenterText = iniparser_getint(ThemeDict, "theme:center_text", 0);
    return;
}

void Themes::List(Device *device) {
    Storage::MountCache();

    static const char* headers[] = {"Choose Theme","",NULL};
    DIR* d;
    struct dirent* de;
    string BasePath("/cache/cot/themes");
    d = opendir(BasePath.c_str());
    if (d == NULL) {
        LOGE("error opening %s: %s\n", BasePath.c_str(), strerror(errno));
        return;
    }

    int b_size = 0;
    int b_alloc = 10;
    char** base = (char**)malloc(b_alloc * sizeof(char*));
    int th_size = 0;
    int th_alloc = 10;
    char** themes = (char**)malloc(th_alloc * sizeof(char*));

    int d_size = 0;
    int d_alloc = 10;
    char** dirs = (char**)malloc(d_alloc * sizeof(char*));
    int z_size = 0;
    int z_alloc = 10;
    char** zips = (char**)malloc(z_alloc * sizeof(char*));


    while ((de = readdir(d)) != NULL) {
        int name_len = strlen(de->d_name);

        if (de->d_type == DT_DIR) {
            // skip "." and ".." entries
            if (name_len == 1 && de->d_name[0] == '.') continue;
            if (name_len == 2 && de->d_name[0] == '.' &&
                de->d_name[1] == '.') continue;

            int theme_len = strlen(GetName(de->d_name));

            if (d_size >= d_alloc) {
                d_alloc *= 2;
                dirs = (char**)realloc(dirs, d_alloc * sizeof(char*));
            }

            if (b_size >= b_alloc) {
                b_alloc *= 2;
                base = (char**)realloc(base, b_alloc * sizeof(char*));
            }

            dirs[d_size] = (char*)malloc(name_len + 2);
            strcpy(dirs[d_size], de->d_name);
            dirs[d_size][name_len] = '\0';
            ++d_size;

            base[b_size] = (char*)malloc(theme_len + 2);
            strcpy(base[b_size], GetName(de->d_name));
            base[b_size][theme_len] = '\0';
            ++b_size;
        }
    }
    closedir(d);

    // append dirs to the zips list
    if (d_size + z_size + 1 > z_alloc) {
        z_alloc = d_size + z_size + 1;
        zips = (char**)realloc(zips, z_alloc * sizeof(char*));
    }

    // append themes
    if (b_size + th_size + 1 > th_alloc) {
        th_alloc = b_size + th_size + 1;
        themes = (char**)realloc(themes, th_alloc * sizeof(char*));
    }

    memcpy(zips + z_size, dirs, d_size * sizeof(char*));
    memcpy(themes + th_size, base, b_size * sizeof(char*));

    free(dirs);
    free(base);

    z_size += d_size;
    th_size = b_size;

    zips[z_size] = NULL;
    themes[th_size] = NULL;

    int result;
    int ChosenItem = 0;
    for (;;) {
        ChosenItem = get_menu_selection(headers, (const char *const *) themes, 1, ChosenItem, device);
        if (ChosenItem == Device::kGoBack) {
            return;
        }

        char* item = zips[ChosenItem];
        int item_len = strlen(item);

        char new_path[PATH_MAX];
        strlcpy(new_path, item, PATH_MAX);

        int i;
        ThemeVar::CurrentTheme = item;
        Load(ThemeVar::CurrentTheme.c_str());

        Settings::Save("settings:theme", ThemeVar::CurrentTheme.c_str());

        for (i = 0; i < z_size; ++i) free(zips[i]);
        for (i = 0; i < th_size; ++i) free(themes[i]);

        free(zips);
        free(themes);

        return;
    }
}
