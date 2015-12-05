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
#include "RebootMenu.h"

extern RecoveryUI* ui;

int RebootMenu::StartMenu(Device* device) {
    static const char* MenuHeaders[] = {"Reboot", "", NULL};
    static const char* MenuItems[] = {
            "Boot Android",
            "Boot Recovery",
#ifdef DOWNLOAD_MODE
            "Boot Download Mode",
#else
            "Boot Bootloader",
#endif
            NULL
    };

    for (;;) {
        int MenuSelection = get_menu_selection(MenuHeaders, MenuItems, 0, 0, device);
        switch (MenuSelection) {
            case REBOOTMENU_MAIN:
            case REBOOTMENU_RECOVERY:
            case REBOOTMENU_BOOTLOADER:
                return MenuSelection;

            case Device::kGoBack:
                return -1;
        }
    }
}