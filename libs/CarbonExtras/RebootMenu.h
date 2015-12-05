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
