/**
 * Project Untitled
 */

#ifndef _CLIENTLIST_H
#define _CLIENTLIST_H

#include "Client.h"

class ClientList
{
public:
    ClientList() { countClient = 0; };
    void addClient(Client* client);

private:
    Client* clients[100];
    int countClient;
    char* cur;
};

#endif //_CLIENTLIST_H