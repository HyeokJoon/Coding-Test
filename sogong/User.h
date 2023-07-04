/**
 * Project Untitled
 */

#ifndef _USER_H
#define _USER_H

#include "Client.h"

class User : public Client
{
public:
    User() {};
    User(char* name, char* personalID, char* ID, char* password) { this->name = name; this->personalID = personalID; this->ID = ID, this->PW = password; };
    void getUserForm();
    char* getName();
    char* getPersonalID();
    void addUser();

private:
    char* name;
    char* personalID;
};

#endif //_USER_H