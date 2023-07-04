/**
 * Project Untitled
 */

#ifndef _USERLIST_H
#define _USERLIST_H

#include "User.h"

class UserList
{
public:
    UserList() { countUser = 0; };
    void getUserForm();
    User* addUser(char* name, char* personalID, char* ID, char* password);

private:
    User* users[100];
    int countUser;
};

#endif //_USERLIST_H