#pragma once
#include "ServerNetwork.h"
#include "..\Data\NetworkData.h"
#include "..\Base\NetworkCommunication.h"

namespace Woo{
	namespace Server {
#define MAX_PACKAGE_SIZE 1000000
		class ServerApplication {
		protected:
			ServerNetwork* m_serverNetwork;
			unsigned int m_clientID;
			char m_dataBuffer[MAX_PACKAGE_SIZE];
		public:
			ServerApplication();
			~ServerApplication();

			void UpdateConnection();
			void ReceiveDataFromClients();
			void SendActionPackage(std::string& chatString);
		};
	}
}