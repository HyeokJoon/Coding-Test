/**
 * Project Untitled
 */
#ifndef _CREATEUSERACCOUNTUI_H
#define _CREATEUSERACCOUNTUI_H
#include "CreateUserAccount.h"
class CreateUserAccountUI
{
private:
    CreateUserAccount controller_cua;
    User* result;

public:
    CreateUserAccountUI() {};
    void createAccount(char *name, char *personalID, char *ID, char *password);

    void startInterface();
};

#endif //_CREATEUSERACCOUNTUI_H