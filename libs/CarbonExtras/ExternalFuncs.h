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

#ifndef RECOVERY_EXTERNALFUNCS_H
#define RECOVERY_EXTERNALFUNCS_H

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

#include "iniparser/iniparser.h"
#include "iniparser/dictionary.h"

int get_menu_selection(const char* const * headers, const char* const * items, int menu_only, int initial_selection, Device* device);
void wipe_data(int confirm, Device* device);
int erase_volume_wrapper(const char *volume);
void ensure_directory_exists(const char* dir);
int is_path_mounted(const char* path);

#endif //RECOVERY_EXTERNALFUNCS_H