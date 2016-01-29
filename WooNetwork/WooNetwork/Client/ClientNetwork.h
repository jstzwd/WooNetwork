#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include "..\Base\NetworkCommunication.h"
#include <iostream>

namespace Woo {
	namespace Client {

#define DEFAULT_PORT "1000"

		class ClientNetwork {
		public:
			SOCKET m_clientSocket;
			u_long m_blockingMode;
			ClientNetwork(u_long blockingMode);
			~ClientNetwork();

		};
	}
}
