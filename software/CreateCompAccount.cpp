/**
 * Project Untitled
 */

#include "CreateCompAccount.h"

/**
 * CreateCompAccount implementation
 */

char *CreateCompAccount::showResultMessage(char *name, char *personalID, char *ID, char *password)
{
    result = name;
    strcat(result, personalID);
    strcat(result, ID);
    strcat(result, password);

    CompanyList[countCompany].addCompany();
    return result;
}