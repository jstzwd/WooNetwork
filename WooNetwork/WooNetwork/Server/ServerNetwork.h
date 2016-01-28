#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <map>
#include "..\Base\NetworkCommunication.h"

namespace Woo {
	namespace Server {

#define DEFAULT_PORT "1000"

		class ServerNetwork {
		protected:			
			SOCKET m_listenSocket;
			SOCKET m_connectSocket;
			u_long m_blockingMode;
			std::map<unsigned int, SOCKET> m_socketList;
		public:	
			ServerNetwork();
			bool AcceptClient(unsigned int clientID);
		};
	}
}