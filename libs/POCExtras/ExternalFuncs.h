//
// Created by drew on 8/3/15.
//

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

int get_menu_selection(const char* const * headers, const char* const * items, int menu_only, int initial_selection, Device* device);
void wipe_data(int confirm, Device* device);
int erase_volume_wrapper(const char *volume);
void ensure_directory_exists(const char* dir);
int is_path_mounted(const char* path);

#endif //RECOVERY_EXTERNALFUNCS_H
