#include "NetworkData.h"

namespace Woo {
	namespace Data{
		void Package::Serialize(char* data)
		{
			memcpy(data, this, sizeof(Package));
		}
		void Package::DeSerialize(char* data)
		{
			memcpy(this, data, sizeof(Package));
		}
	}
}