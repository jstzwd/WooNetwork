#include "NetworkCommunication.h"

namespace Woo {
	namespace Base {
		int NetworkCommunication::SendData(SOCKET s, char* buffer, int infoSize)
		{
			return send(s, buffer, infoSize, 0);
		}
		int NetworkCommunication::ReceiveData(SOCKET s, char* buffer, int infoSize)
		{
			return recv(s, buffer, infoSize, 0);
		}
	}
}