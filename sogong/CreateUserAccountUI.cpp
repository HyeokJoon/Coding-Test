/**
 * Project Untitled
 */

#include "CreateUserAccountUI.h"
#include "User.h"

/**
 * CreateUserAccountUI implementation
 */

void CreateUserAccountUI::createAccount(char *name, char *personalID, char *ID, char *password)
{
    result = controller_cua.showResultMessage(name, personalID, ID, password);
    startInterface();
}

void CreateUserAccountUI::startInterface()
{
    printf("1.1. 회원가입\n");
    printf(" > 2 %s %s %s %s\n", result->getName(), result->getPersonalID(), result->getID(), result->getPW());
    // fprintf(out_fp, "%s", result);
}