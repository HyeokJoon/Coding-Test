/**
 * Project Untitled
 */

#include "CreateCompAccount.h"

/**
 * CreateCompAccount implementation
 */

Company *CreateCompAccount::showResultMessage(char *name, char *personalID, char *ID, char *password)
{
    //result = name;
    //strcat(result, personalID);
    //strcat(result, ID);
    //strcat(result, password);

    created = compList.addCompany(name, personalID, ID, password);
    return created;
}