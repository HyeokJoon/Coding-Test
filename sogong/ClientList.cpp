/**
 * Project Untitled
 */


#include "ClientList.h"
 /**
  * Company implementation
  */


void ClientList::addClient(Client* client) {
	clients[countClient++] = client;
}