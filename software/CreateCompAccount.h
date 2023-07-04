/**
 * Project Untitled
 */

#ifndef _CREATECOMPACCOUNT_H
#define _CREATECOMPACCOUNT_H
#include <stdio.h>
#include <string>
#include "Company.h"

class CreateCompAccount
{
private:
    Company CompanyList[100];
    int countCompany;
    char *result;

public:
    CreateCompAccount() { countCompany = 0; };
    char *showResultMessage(char *name, char *personalID, char *ID, char *password);
};

#endif //_CREATECOMPACCOUNT_H