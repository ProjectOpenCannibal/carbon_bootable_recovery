//
// Created by drew on 8/3/15.
//

#ifndef RECOVERY_REBOOTMENU_H
#define RECOVERY_REBOOTMENU_H

#define REBOOTMENU_MAIN 0
#define REBOOTMENU_RECOVERY 1
#define REBOOTMENU_BOOTLOADER 2


class RebootMenu {
public:
    static int StartMenu(Device* device);
};


#endif //RECOVERY_REBOOTMENU_H
