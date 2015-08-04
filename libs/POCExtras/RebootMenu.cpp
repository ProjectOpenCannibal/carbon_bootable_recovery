//
// Created by drew on 8/3/15.
//

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>

#include "../../bootloader.h"
#include "../../common.h"
#include "cutils/properties.h"
#include "cutils/android_reboot.h"
#include "../../install.h"
#include "../../minui/minui.h"
#include "../../minzip/DirUtil.h"
#include "../../roots.h"
#include "../../ui.h"
#include "../../screen_ui.h"
#include "../../device.h"

#include "cutils/properties.h"

#include "../../voldclient/voldclient.h"

#include "ExternalFuncs.h"
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