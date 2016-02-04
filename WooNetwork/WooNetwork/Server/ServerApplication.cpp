#include "ServerApplication.h"

namespace Woo {
	namespace Server {
		ServerApplication::ServerApplication()
		{
			m_serverNetwork = new ServerNetwork(1);
			m_clientID = 0;
		}
		void ServerApplication::UpdateConnection()
		{
			if (m_serverNetwork->AcceptClient(m_clientID)) {
				std::cout << "Accept Client: " << m_clientID << std::endl;
				m_clientID++;
			}
			ReceiveDataFromClients();
		}
		void ServerApplication::ReceiveDataFromClients() 
		{
			Data::Package newPackage;
			std::map<unsigned int, SOCKET>::iterator myIterator;
			for (myIterator = m_serverNetwork->m_socketList.begin(); myIterator != m_serverNetwork->m_socketList.end();myIterator++)
			{
				int dataSize = m_serverNetwork->ReceiveData(myIterator->first, m_dataBuffer);
				if (dataSize < 0)
					continue;
				int i = 0;
				while(i<(unsigned int)dataSize)
				{
					newPackage.DeSerialize(&m_dataBuffer[i]);
					i += sizeof(newPackage);
					switch(newPackage.m_packageType)
					{
					case Data::PackageType::INIT_CONNECTION:
						std::cout << "Server received INIT CONNECTION data from client " << myIterator->first << std::endl;
						SendActionPackage();
						break;
					case Data::PackageType::ACTION_EVENT:
						std::cout << "Server received ACTION EVENT data from client " << myIterator->first << std::endl;
						SendActionPackage();
						break;
					default:
						std::cout << "No such package type!" << std::endl;
						break;
					}

				}
			}
		}
		void ServerApplication::SendActionPackage()
		{
			const unsigned int packageSize = sizeof(Data::Package);
			char newData[packageSize];

			Data::Package newPackage;
			newPackage.m_packageType = Data::PackageType::ACTION_EVENT;
			newPackage.Serialize(newData);

			m_serverNetwork->SendDataToAll(newData, packageSize);
		}
	}

}