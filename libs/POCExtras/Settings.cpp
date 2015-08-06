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
#include "Settings.h"
#include "Themes.h"
#include "ZipSig.h"
#include "Tests.h"

extern RecoveryUI* ui;

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

int Settings::Load() {
    return 0;
}

int Settings::Save() {
    return 0;
}