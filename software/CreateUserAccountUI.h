/**
 * Project Untitled
 */
#include "CreateUserAccount.h"

#ifndef _CREATEUSERACCOUNTUI_H
#define _CREATEUSERACCOUNTUI_H

class CreateUserAccountUI
{
private:
    CreateUserAccount controller;

public:
    CreateUserAccountUI();
    void createAccount(char *name, char *personalID, char *ID, char *password);

    // void startInterface();
};

#endif //_CREATEUSERACCOUNTUI_H