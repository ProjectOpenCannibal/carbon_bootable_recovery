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


#include "ExternalFuncs.h"
#include "Settings.h"
#include "ThemeVar.h"

extern RecoveryUI* ui;

/* global vars */
string ThemeVar::CurrentTheme("default");
int ThemeVar::C_HEADER[4] = { 111, 111, 111, 255 };
int ThemeVar::C_TOP[4] = { 208, 208, 208, 255};
int ThemeVar::C_MENU_SEL_FG[4] = { 25, 160, 210, 255 };
int ThemeVar::C_MENU_SEL_BG[4] = { 60, 60, 61, 255 };
int ThemeVar::C_LOG[4] = { 76, 76, 76, 255 };
int ThemeVar::C_TEXT_FILL[4] = { 0, 0, 0, 255 };
int ThemeVar::C_ERROR_TEXT[4] = { 255, 0, 0, 255 };
int ThemeVar::C_DEFAULT[4] = { 255, 255, 255, 255 };
string ThemeVar::BatteryIndicator("false");
string ThemeVar::BatteryLevel("bat_100");
int ThemeVar::BatteryXPos = 0;
int ThemeVar::BatteryYPos = 0;
int ThemeVar::CenterText = 0;
