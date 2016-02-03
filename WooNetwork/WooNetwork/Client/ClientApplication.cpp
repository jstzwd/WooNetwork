#include "ClientApplication.h"

namespace Woo {
	namespace Client {
		ClientApplication::ClientApplication()
		{
			m_clientNetwork = new ClientNetwork(1);
			const unsigned int packageSize = sizeof(Data::Package);
			char testPack[packageSize];

			Data::Package testPackage;
			testPackage.m_packageType = Data::PackageType::INIT_CONNECTION;
			testPackage.Serialize(testPack);
			
			Base::NetworkCommunication::SendData(m_clientNetwork->m_clientSocket, testPack, packageSize);
		}
	}
}