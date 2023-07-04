/**
 * Project Untitled
 */

#ifndef _CREATEUSERACCOUNT_H
#define _CREATEUSERACCOUNT_H
#include <stdio.h>
#include <cstring>
#include "UserList.h"
#include "ClientList.h"

class CreateUserAccount
{
private:
    // FILE *out_fp = fopen("output.txt", "w+");
    UserList userList;
    char* result;
    User* created;

public:
    CreateUserAccount() { result = NULL; };
    User* showResultMessage(char *name, char *personalID, char *ID, char *password);
};

#endif //_CREATEUSERACCOUNT_H