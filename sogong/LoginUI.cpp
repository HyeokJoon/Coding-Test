/**
 * Project Untitled
 */


#include "LoginUI.h"

/**
 * LoginUI implementation
 */


void LoginUI::login(char* ID, char* password) {
	control_login.checkClient(ID, password);
}