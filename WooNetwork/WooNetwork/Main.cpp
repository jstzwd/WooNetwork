#include "Base\NetworkCommunication.h"
#include "Client\ClientApplication.h"
#include "Server\ServerApplication.h"
#include <process.h>

using namespace Woo;
using namespace Server;
using namespace Client;

Server::ServerApplication* testServer;
ClientApplication* client;

void serverLoop(void*) 
{
	while(true)
	{
		testServer->UpdateConnection();
	}
}
void clientLoop() 
{
	while(true)
	{
		client->Update();
	}
}


int main()
{
	bool isServer = false;
	std::cout << "Is Server?" << std::endl;
	std::cin >> isServer;
	if (isServer) {
		testServer = new Server::ServerApplication();
		serverLoop(0);
	}
	else {
		client = new ClientApplication();
		clientLoop();
	}
	//_beginthread(serverLoop, 0, (void*)12);
	
}