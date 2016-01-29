#include "ClientApplication.h"

namespace Woo {
	namespace Client {
		ClientApplication::ClientApplication()
		{
			m_clientNetwork = new ClientNetwork(1);
		}
	}
}