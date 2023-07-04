/**
 * Project Untitled
 */

#include "CreateUserAccountUI.h"

/**
 * CreateUserAccountUI implementation
 */

void CreateUserAccountUI::createAccount(char *name, char *personalID, char *ID, char *password)
{
    controller.showResultMessage(name, personalID, ID, password);
}

// void CreateUserAccountUI::startInterface()
// {
// }