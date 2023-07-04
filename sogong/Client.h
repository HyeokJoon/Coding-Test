/**
 * Project Untitled
 */

#ifndef _CLIENT_H
#define _CLIENT_H

class Client
{
public:
    void getClient(char *ID);

    void deleteAccount();

    void check();
    char *getID();
    char *getPW();

    Client(){};

protected:
    char *ID;
    char *PW;
};

#endif //_CLIENT_H