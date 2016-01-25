#include "NetworkCommunication.h"

namespace Woo {
	namespace Base {
		int NetworkCommunication::SendInfo(SOCKET s, char* info, int infoSize)
		{
			return send(s, info, infoSize, 0);
		}
		int NetworkCommunication::ReceiveInfo(SOCKET s, char* info, int infoSize)
		{
			return recv(s, info, infoSize, 0);
		}
	}
}