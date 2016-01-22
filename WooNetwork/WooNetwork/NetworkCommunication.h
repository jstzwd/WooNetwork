#pragma once

#include <WinSock2.h>

namespace Woo {
	namespace Base {
		class NetworkCommunication {
		public:
			static int Send();
			static int Receive();
		};
	}
}