/**
 * Project Untitled
 */

#ifndef _COMPANY_H
#define _COMPANY_H

#include "Client.h"

class Company : public Client
{
public:
    void getCompanyForm();

    void addCompany();

private:
    char *CompanyName;
    int businessNumber;
};

#endif //_COMPANY_H