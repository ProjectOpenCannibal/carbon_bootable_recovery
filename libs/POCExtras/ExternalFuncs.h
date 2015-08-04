//
// Created by drew on 8/3/15.
//

#ifndef RECOVERY_EXTERNALFUNCS_H
#define RECOVERY_EXTERNALFUNCS_H

int get_menu_selection(const char* const * headers, const char* const * items, int menu_only, int initial_selection, Device* device);
void wipe_data(int confirm, Device* device);
int erase_volume_wrapper(const char *volume);
void ensure_directory_exists(const char* dir);
int is_path_mounted(const char* path);

#endif //RECOVERY_EXTERNALFUNCS_H
