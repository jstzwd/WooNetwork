#pragma once

#include "ClientNetwork.h"

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