/**
 * Project Untitled
 */

#include "CreateUserAccount.h"

/**
 * CreateUserAccount implementation
 */

User* CreateUserAccount::showResultMessage(char *name, char *personalID, char *ID, char *password)
{
    //result = name;
    //strcat(result, personalID);
    //strcat(result, ID);
    //strcat(result, password);

    created = userList.addUser(name, personalID, ID, password);
    return created;
    //출력?�식
    // fprintf(out_fp, "1.1. ?�원가??n");
    // fprintf(out_fp, "2 %s %s %s %s\n", name, personalID, ID, password);
}