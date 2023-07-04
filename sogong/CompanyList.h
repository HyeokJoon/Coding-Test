/**
 * Project Untitled
 */

#ifndef _COMPANYLIST_H
#define _COMPANYLIST_H

#include "Company.h"

class CompanyList
{
public:
    CompanyList() { countComp = 0; };
    void getCompanyForm();
    Company* addCompany( char* name, char* personalID, char* ID, char* password);

private:
    Company *companies[100];
    int countComp;
};

#endif //_COMPANYLIST_H