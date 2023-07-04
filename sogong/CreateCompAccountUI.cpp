/**
 * Project Untitled
 */

#include "CreateCompAccountUI.h"
#include "Company.h"

/**
 * CreateCompAccountUI implementation
 */

void CreateCompAccountUI::createAccount(ClientList *clientList, char *name, char *personalID, char *ID, char *password)
{
    result = controller_cca.showResultMessage(clientList, name, personalID, ID, password);
    startInterface();
}

void CreateCompAccountUI::startInterface()
{

    printf("1.1. 회원가입\n");
    printf(" > 1 %s %s %s %s\n", result->getName(), result->getbusinessNumber(), result->getID(), result->getPW());
    // fprintf(out_fp, "%s", result);
}