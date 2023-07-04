/**
 * Project Untitled
 */

#ifndef _CREATECOMPACCOUNTUI_H
#define _CREATECOMPACCOUNTUI_H

#include "CreateCompAccount.h"
#include <cstring>

class CreateCompAccountUI
{
private:
    CreateCompAccount controller_cca;
    Company *result;

public:
    CreateCompAccountUI(){};
    void createAccount(ClientList *clientList, char *name, char *personalID, char *ID, char *password);
    void startInterface();
};

#endif //_CREATECOMPACCOUNTUI_H