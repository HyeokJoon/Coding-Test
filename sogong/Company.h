/**
 * Project Untitled
 */

#ifndef _COMPANY_H
#define _COMPANY_H

#include "Client.h"

class Company : public Client
{
public:
    Company() {};
    Company(char* name, char* personalID, char* ID, char* password) { CompanyName = name; businessNumber = personalID; this->ID = ID, this->PW = password; }
    
    void getCompanyForm();
    char* getName();
    char* getbusinessNumber();
    void addCompany();

private:
    char *CompanyName;
    char *businessNumber;
};

#endif //_COMPANY_H