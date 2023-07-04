/**
 * Project Untitled
 */

#include "CreateCompAccountUI.h"

/**
 * CreateCompAccountUI implementation
 */

void CreateCompAccountUI::createAccount(char *name, char *personalID, char *ID, char *password)
{
    result = controller_cca.showResultMessage(name, personalID, ID, password);
}

void CreateCompAccountUI::startInterface()
{
    printf("1.1. 회원가입\n");
    printf("%s\n", result);
    // fprintf(out_fp, "%s", result);
}