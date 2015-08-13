/* Copyright (C) 2015 Project Open Cannibal
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

#ifndef RECOVERY_THEMES_H
#define RECOVERY_THEMES_H

#include "../rdestl/rde_string.h"
using namespace rde;

class Themes {
public:
    static void StartMenu(Device* device);
    static void List(Device* device);
    static char* GetName(const char * themepath);
    static void Load(const char *themename);
};


#endif //RECOVERY_THEMES_H
