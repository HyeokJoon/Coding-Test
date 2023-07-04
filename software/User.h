/**
 * Project Untitled
 */

#ifndef _USER_H
#define _USER_H

#include "Client.h"

class User : public Client
{
public:
    void getUserForm();

    void addUser();

private:
    char *name;
    char *personalID;
};

#endif //_USER_H