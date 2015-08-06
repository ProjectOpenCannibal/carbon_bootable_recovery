//
// Created by drew on 8/6/15.
//

#ifndef RECOVERY_THEMES_H
#define RECOVERY_THEMES_H

class Themes {
public:
    static void StartMenu(Device* device);
    static char* GetName(const char * themepath);
    static int Load(Device* device);
    static int Save();
};


#endif //RECOVERY_THEMES_H
