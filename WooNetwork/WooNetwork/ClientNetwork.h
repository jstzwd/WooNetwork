#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include "NetworkCommunication.h"
#include <iostream>

namespace Woo {
	namespace Client {

#define DEFAULT_PORT "10000"

		class ClientNetwork {
		public:
			SOCKET m_serverSocket;
			u_long m_blockingMode;
			ClientNetwork(u_long blockingMode);
			~ClientNetwork();

		};
	}
}
