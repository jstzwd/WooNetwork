#pragma once
#include "ServerNetwork.h"
#include "..\Data\NetworkData.h"
#include "..\Base\NetworkCommunication.h"

namespace Woo{
	namespace Server {
		class ServerApplication {
		protected:
			ServerNetwork* m_serverNetwork;
			unsigned int m_clientID;
		public:
			ServerApplication();
			~ServerApplication();

			void UpdateConnection();
			void ReceiveDataFromClients();

		};
	}
}