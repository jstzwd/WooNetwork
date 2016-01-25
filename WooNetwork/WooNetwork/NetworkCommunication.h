#pragma once

#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

namespace Woo {
	namespace Base {
		class NetworkCommunication {
		public:
			//NetworkCommunication();
			static int SendInfo(SOCKET s, char* info, int infoSize);
			static int ReceiveInfo(SOCKET s, char* info, int infoSize);
		};
	}
}