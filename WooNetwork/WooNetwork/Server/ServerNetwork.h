#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <map>
#include "..\Base\NetworkCommunication.h"

namespace Woo {
	namespace Server {

#define DEFAULT_PORT "1000"
#define MAX_PACKAGE_SIZE 1000000

		class ServerNetwork {
		protected:			
			SOCKET m_listenSocket;
			SOCKET m_connectSocket;
			u_long m_blockingMode;
			
		public:	
			std::map<unsigned int, SOCKET> m_socketList;
			ServerNetwork(u_long blockingMode);
			bool AcceptClient(unsigned int clientID);
			int ReceiveData(unsigned int clientID, char* receBuffer);
			void SendDataToAll(char* data, int size);
		};
	}
}