//
// Created by drew on 8/6/15.
//

#ifndef RECOVERY_SETTINGS_H
#define RECOVERY_SETTINGS_H

#include "iniparser/dictionary.h"
#include "iniparser/iniparser.h"
#include <utils/String8.h>

class Settings {
public:
    static dictionary * settings;

    static void StartMenu(Device* device);
    static int Load();
    static int Save();
};


#endif //RECOVERY_SETTINGS_H
