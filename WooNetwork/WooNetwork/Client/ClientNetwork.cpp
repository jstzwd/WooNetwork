#include "ClientNetwork.h"

namespace Woo {
	namespace Client {
		ClientNetwork::ClientNetwork(u_long blockingMode)
			:m_blockingMode(blockingMode)
		{
			WSADATA clientwsadata;
			m_clientSocket = INVALID_SOCKET;
			struct addrinfo* result = NULL;
			struct addrinfo hints;

			if(WSAStartup(MAKEWORD(2,0),&clientwsadata)!=0)
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
			
			if(getaddrinfo("127.0.0.1",DEFAULT_PORT,&hints,&result)!=0)
			{
				std::cout << "Can not get address!" << std::endl;
				WSACleanup();
				return;
			}

			for (struct addrinfo* addr=result; addr != NULL; addr=addr->ai_next)
			{
				m_clientSocket = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
				if(m_clientSocket==INVALID_SOCKET)
				{
					std::cout << "Failed to generate socket!" << std::endl;
					freeaddrinfo(result);
					WSACleanup();
					return;
				}
				if (connect(m_clientSocket, addr->ai_addr, addr->ai_addrlen)!=0)
				{
					std::cout << "Failed to connect this server!" << std::endl;
					closesocket(m_clientSocket);
					m_clientSocket = INVALID_SOCKET;
				}
			}

			freeaddrinfo(result);

			if (m_clientSocket == INVALID_SOCKET) 
			{
				std::cout << "No valid server!" << std::endl;
				WSACleanup();
				return;
			}

		
			if (ioctlsocket(m_clientSocket, FIONBIO, &m_blockingMode)!=0)
			{
				std::cout << "Non-blocking failed!" << std::endl;
				closesocket(m_clientSocket);
				WSACleanup();
				return;
			}

			char value = 1;
			setsockopt(m_clientSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
		}
		int ClientNetwork::ReceiveData(char* receBuffer)
		{
			int result = Base::NetworkCommunication::ReceiveData(m_clientSocket, receBuffer, MAX_PACKAGE_SIZE);
			if(result==0)
			{
				std::cout << "This connection failed!" << std::endl;
				closesocket(m_clientSocket);
				WSACleanup();
				return 0;
			}
			return result;
		}
	}
}