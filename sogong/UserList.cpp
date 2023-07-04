/**
 * Project Untitled
 */


#include "UserList.h"
 /**
  * Company implementation
  */


void UserList::getUserForm() {

}

User* UserList::addUser(char* name, char* personalID, char* ID, char* password) {
	users[countUser] = new User(name, personalID, ID, password);
	return users[countUser++];
}