/**
 * Project Untitled
 */

#ifndef _CLIENT_H
#define _CLIENT_H

class Client
{
public:
    void getClient();

    void deleteAccount();

    void check();

private:
    char *ID;
    char *PW;
};

#endif //_CLIENT_H