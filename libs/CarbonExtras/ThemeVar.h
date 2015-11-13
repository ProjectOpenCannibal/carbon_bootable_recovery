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

#ifndef RECOVERY_THEMEVAR_H
#define RECOVERY_THEMEVAR_H

#define COT_SETTINGS_LOC "/cache/cot/settings.ini"
#define COT_THEMES_LOC "/cache/cot/themes/"

#include "../rdestl/rde_string.h"
using namespace rde;

class ThemeVar {
public:
    /* Variables */
    static string CurrentTheme;
    static string ThemePath;
    static int C_HEADER[4];
    static int C_TOP[4];
    static int C_MENU_SEL_FG[4];
    static int C_MENU_SEL_BG[4];
    static int C_LOG[4];
    static int C_TEXT_FILL[4];
    static int C_ERROR_TEXT[4];
    static int C_DEFAULT[4];
    static int BatteryXPos;
    static int BatteryYPos;
    static string BatteryIndicator;
    static string BatteryLevel;
    static int CenterText;
};


#endif //RECOVERY_THEMEVAR_H
