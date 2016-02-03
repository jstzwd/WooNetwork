#pragma once

#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

namespace Woo {
	namespace Base {
		class NetworkCommunication {
		public:
			//NetworkCommunication();
			static int SendData(SOCKET s, char* buffer, int infoSize);
			static int ReceiveData(SOCKET s, char* buffer, int infoSize);
		};
	}
}