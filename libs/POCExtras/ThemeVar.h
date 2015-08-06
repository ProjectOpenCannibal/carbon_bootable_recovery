//
// Created by drew on 8/6/15.
//

#ifndef RECOVERY_THEMEVAR_H
#define RECOVERY_THEMEVAR_H


class ThemeVar {
public:
    /* Variable getters */
    static int GetInt();
    static bool GetBool();
    static const char * GetString();

    /* Variable setters */
    static int SetInt();
    static bool SetBool();
    static const char * SetString();
};


#endif //RECOVERY_THEMEVAR_H
