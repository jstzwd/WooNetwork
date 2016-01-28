#include "ServerNetwork.h"

namespace Woo {
	namespace Server {
		ServerNetwork::ServerNetwork()
		{
			WSADATA serverwsadata;
			m_connectSocket = INVALID_SOCKET;
			struct addrinfo* result = NULL;
			struct addrinfo hints;

			if (WSAStartup(MAKEWORD(2, 0), &serverwsadata) != 0)
			{
				std::cout << "Failed to initialize the Winsock library!" << std::endl;
				return;
			}

			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_INET;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;
			hints.ai_flags = AI_PASSIVE;

			if (getaddrinfo(NULL, DEFAULT_PORT, &hints, &result) != 0)
			{
				std::cout << "Can not get address!" << std::endl;
				WSACleanup();
				return;
			}
			m_listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
			if(m_listenSocket==INVALID_SOCKET)
			{
				std::cout << "Failed to generate listen socket" << std::endl;
				freeaddrinfo(result);
				WSACleanup();
				return;
			}

			if (ioctlsocket(m_listenSocket, FIONBIO, &m_blockingMode) != 0)
			{
				std::cout << "Non-blocking failed!" << std::endl;
				closesocket(m_listenSocket);
				WSACleanup();
				return;
			}
			if(bind(m_listenSocket,result->ai_addr,(int)result->ai_addrlen)!=0)
			{
				std::cout << "Bind failed!" << std::endl;
				freeaddrinfo(result);
				closesocket(m_listenSocket);
				WSACleanup();
				return;
			}
			freeaddrinfo(result);
			if (listen(m_listenSocket, SOMAXCONN) != 0) 
			{
				std::cout << "Listen failed!" << std::endl;
				closesocket(m_listenSocket);
				WSACleanup();
				return;
			}

		}

		bool ServerNetwork::AcceptClient(unsigned int clientID)
		{
			m_connectSocket = accept(m_listenSocket, NULL, NULL);
			if (m_connectSocket != INVALID_SOCKET) {
				m_socketList.insert(std::pair<unsigned int, SOCKET>(clientID, m_connectSocket));
				return true;
			}
			return false;

		}
	}
}