#include "ServerNetwork.h"

namespace Woo {
	namespace Server {
		ServerNetwork::ServerNetwork(u_long blockingMode)
			:m_blockingMode(blockingMode)
		{
			WSADATA serverwsadata;
			m_connectSocket = INVALID_SOCKET;
			m_listenSocket = INVALID_SOCKET;
			struct addrinfo* result = NULL;
			struct addrinfo hints;

			if (WSAStartup(MAKEWORD(2, 0), &serverwsadata) != 0)
			{
				std::cout << "Failed to initialize the Winsock library!" << std::endl;
				return;
			}
			else {
				std::cout << "Succeeded to initialize the Winsock library!" << std::endl;
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
				char value = 1;
				setsockopt(m_connectSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
				m_socketList.insert(std::pair<unsigned int, SOCKET>(clientID, m_connectSocket));
				std::cout << "Accept the client!" << std::endl;
				return true;
			}
			return false;

		}
		int ServerNetwork::ReceiveData(unsigned int clientID, char* receBuffer)
		{
			if(m_socketList.find(clientID)!=m_socketList.end())
			{
				SOCKET clientSocket = m_socketList[clientID];
				int result = Base::NetworkCommunication::ReceiveData(clientSocket, receBuffer, MAX_PACKAGE_SIZE);
				if(result==0)
				{
					std::cout << "Connect failed!" << std::endl;
					closesocket(clientSocket);	
				}
				return result;
			}
			return 0;
		}
		void ServerNetwork::SendDataToAll(char* data, int size)
		{
			SOCKET currentSocket;
			std::map<unsigned int, SOCKET>::iterator myIterator;
			int result;
			for (myIterator = m_socketList.begin(); myIterator != m_socketList.end();myIterator++)
			{
				currentSocket = myIterator->second;
				result = Base::NetworkCommunication::SendData(currentSocket, data, size);

				if(result==SOCKET_ERROR)
				{
					std::cout << "Server failed to send data to client " << myIterator->first << std::endl;
					closesocket(currentSocket);
					continue;
				}
				else {
					std::cout << "Server succeeded to send data to client " << myIterator->first << std::endl;
				}
			}
		}
	}
}