//
// Created by drew on 8/3/15.
//

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