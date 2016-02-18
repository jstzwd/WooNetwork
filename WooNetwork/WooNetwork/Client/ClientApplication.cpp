#include "ClientApplication.h"

namespace Woo {
	namespace Client {
		ClientApplication::ClientApplication()
		{
			m_clientNetwork = new ClientNetwork(1);
			const unsigned int packageSize = sizeof(Data::Package);
			char testPack[packageSize];

			Data::Package testPackage;
			testPackage.m_chatString = "I am connected";
			testPackage.m_packageType = Data::PackageType::INIT_CONNECTION;
			testPackage.Serialize(testPack);
			
			Base::NetworkCommunication::SendData(m_clientNetwork->m_clientSocket, testPack, packageSize);
		}
		void ClientApplication::ReceiveDataFromServer()
		{
		
		}
		void ClientApplication::SendActionPackage() 
		{
			const unsigned int packageSize = sizeof(Data::Package);
			char newData[packageSize];

			Data::Package newPackage;
			newPackage.m_packageType = Data::PackageType::ACTION_EVENT;
			newPackage.Serialize(newData);

			Base::NetworkCommunication::SendData(m_clientNetwork->m_clientSocket, newData, packageSize);
		}
		void ClientApplication::Update()
		{
			Data::Package newPackage;
			int dataSize = m_clientNetwork->ReceiveData(m_dataBuffer);

			if (dataSize <= 0)
				return;
			int i = 0;
			while (i<(unsigned int)dataSize)
			{
					newPackage.DeSerialize(&m_dataBuffer[i]);
					i += sizeof(newPackage);
					switch (newPackage.m_packageType)
					{
					case Data::PackageType::ACTION_EVENT:
						std::cout << "Client received ACTION EVENT data from server" << std::endl;
						std::cout << newPackage.m_chatString << std::endl;
						//SendActionPackage();
						break;
					default:
						std::cout << "No such package type!" << std::endl;
						break;
					}

				}
			}
	}
}