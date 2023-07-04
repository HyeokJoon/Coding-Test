/**
 * Project Untitled
 */
#include "CreateCompAccount.h"
#include <cstring>

#ifndef _CREATECOMPACCOUNTUI_H
#define _CREATECOMPACCOUNTUI_H

class CreateCompAccountUI
{
private:
    CreateCompAccount controller_cca;
    // FILE *out_fp = fopen("output.txt", "w+");
    char *result;

public:
    CreateCompAccountUI();
    void createAccount(char *name, char *personalID, char *ID, char *password);

    void startInterface();
};

#endif //_CREATECOMPACCOUNTUI_H