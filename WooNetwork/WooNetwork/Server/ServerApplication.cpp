#include "ServerApplication.h"

namespace Woo {
	namespace Server {
		ServerApplication::ServerApplication()
		{
			m_serverNetwork = new ServerNetwork();
			m_clientID = 0;
		}
		void ServerApplication::UpdateConnection()
		{
			if (m_serverNetwork->AcceptClient(m_clientID)) {
				std::cout << "Accept Client" + m_clientID << std::endl;
				m_clientID++;
			}
			else
			{
				std::cout << "Failed to accept client" << std::endl;
			}
		}
	}
}