#include "Base\NetworkCommunication.h"
#include "Client\ClientApplication.h"
#include "Server\ServerApplication.h"
#include <process.h>

using namespace Woo;
using namespace Server;
using namespace Client;

Server::ServerApplication* testServer;
ClientApplication* client;
std::string clientChatString;
std::string serverChatString="hello";

void serverLoop(void*) 
{
	while(true)
	{
		testServer->UpdateConnection();
		//testServer->SendActionPackage(serverChatString);
		//std::cin >> serverChatString;
		if(!serverChatString.empty())
		{
			//testServer->SendActionPackage(serverChatString);
		}
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