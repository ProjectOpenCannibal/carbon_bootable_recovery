//
// Created by drew on 8/6/15.
//

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