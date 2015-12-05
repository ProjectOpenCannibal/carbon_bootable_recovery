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
#include "Battery.h"
#include "ThemeVar.h"

extern RecoveryUI* ui;

void Battery::SetLevel() {
    static int level = -1;

    char value[4];
    FILE * capacity = fopen(BOARD_BATTERY_CAP_FILE, "rt");
    if (capacity) {
        fgets(value, 4, capacity);
        fclose(capacity);
        level = atoi(value);

        /* normalize levels */
        if (level > 100) {
            level = 100;
        }
        if (level < 0) {
            level = 0;
        }

        /* set ThemeVar::BatteryLevel depending on percentage gap */
        if (level == 100) {
            ThemeVar::BatteryLevel = "bat_100";
        }
        if (level > 89 && level != 100) {
            ThemeVar::BatteryLevel = "bat_90";
        }
        if (level > 79 && level < 90) {
            ThemeVar::BatteryLevel = "bat_80";
        }
        if (level > 69 && level < 80) {
            ThemeVar::BatteryLevel = "bat_70";
        }
        if (level > 59 && level < 70) {
            ThemeVar::BatteryLevel = "bat_60";
        }
        if (level > 49 && level < 60) {
            ThemeVar::BatteryLevel = "bat_50";
        }
        if (level > 39 && level < 50) {
            ThemeVar::BatteryLevel = "bat_40";
        }
        if (level > 29 && level < 40) {
            ThemeVar::BatteryLevel = "bat_30";
        }
        if (level > 19 && level < 30) {
            ThemeVar::BatteryLevel = "bat_20";
        }
        if (level > 9 && level < 20) {
            ThemeVar::BatteryLevel = "bat_10";
        }
        if (level > 1 && level < 10) {
            ThemeVar::BatteryLevel = "bat_0";
        }
    } else {
        ThemeVar::BatteryLevel = "bat_50";
    }
    return;
}