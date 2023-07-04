/**
 * Project Untitled
 */


#include "CompanyList.h"
 /**
  * Company implementation
  */


void CompanyList::getCompanyForm() {

}

Company* CompanyList::addCompany(char* name, char* personalID, char* ID, char* password) {
	companies[countComp] = new Company(name, personalID, ID, password);
	return companies[countComp++];
}