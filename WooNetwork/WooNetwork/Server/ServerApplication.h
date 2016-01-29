#pragma once
#include "ServerNetwork.h"

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


		};
	}
}