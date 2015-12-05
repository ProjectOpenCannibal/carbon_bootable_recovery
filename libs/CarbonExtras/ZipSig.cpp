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
#include "ZipSig.h"

extern RecoveryUI* ui;

void ZipSig::StartMenu(Device *device) {
    static const char *MenuHeaders[] = {"Zip Verification","",NULL};
    static const char *MenuItems[] = {"Enable Zip Verification",
									  "Disable Zip Verification",
									  NULL
	};
	#define ZIP_VERIFY_ON 0
	#define ZIP_VERIFY_OFF 1

	for (;;) {
		int MenuSelection = get_menu_selection(MenuHeaders, MenuItems, 0, 0, device);
		switch (MenuSelection) {
			case ZIP_VERIFY_ON:
				Settings::Save("settings:zip_sigverif", "1");
				return;

			case ZIP_VERIFY_OFF:
				Settings::Save("settings:zip_sigverif", "0");
				return;

			case Device::kGoBack:
				return;
		}
	}
}