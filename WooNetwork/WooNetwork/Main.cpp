#include "Base\NetworkCommunication.h"
#include "Client\ClientApplication.h"
#include "Server\ServerApplication.h"
#include <process.h>

using namespace Woo;
using namespace Server;
using namespace Client;

Server::ServerApplication* testServer;
ClientApplication* client;

void serverLoop(void *) 
{
	while(true)
	{
		testServer->UpdateConnection();
	}
}
void clientLoop(void) 
{
	while(true)
	{
	
	}
}


int main()
{
	testServer = new Server::ServerApplication();
	_beginthread(serverLoop, 0, (void*)12);
	client = new ClientApplication();
	clientLoop();
}