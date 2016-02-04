#pragma once

#include "ClientNetwork.h"
#include "..\Data\NetworkData.h"
#include "..\Base\NetworkCommunication.h"

namespace Woo {
	namespace Client{
		class ClientApplication {
		protected:
			ClientNetwork* m_clientNetwork;
			char m_dataBuffer[MAX_PACKAGE_SIZE];
		public:
			ClientApplication();
			~ClientApplication();
			void ReceiveDataFromServer();
			void SendActionPackage();
			void Update();
		};
	}
}