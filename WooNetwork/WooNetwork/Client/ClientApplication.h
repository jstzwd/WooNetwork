#pragma once

#include "ClientNetwork.h"
#include "..\Data\NetworkData.h"
#include "..\Base\NetworkCommunication.h"

namespace Woo {
	namespace Client{
		class ClientApplication {
		protected:
			ClientNetwork* m_clientNetwork;
		public:
			ClientApplication();
			~ClientApplication();
		};
	}
}