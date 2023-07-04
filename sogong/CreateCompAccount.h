/**
 * Project Untitled
 */

#ifndef _CREATECOMPACCOUNT_H
#define _CREATECOMPACCOUNT_H
#include <stdio.h>
#include <cstring>
#include "CompanyList.h"
#include "ClientList.h"

class CreateCompAccount
{
private:
    CompanyList compList;
    char *result;
    Company *created;

public:
    CreateCompAccount() { result = NULL; };
    Company *showResultMessage(ClientList *clientList, char *name, char *personalID, char *ID, char *password);
};

#endif //_CREATECOMPACCOUNT_H