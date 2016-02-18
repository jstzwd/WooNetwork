#include "NetworkData.h"

namespace Woo {
	namespace Data{
		void Package::Serialize(char* data)
		{
			//memcpy(data, &(this->m_chatString), sizeof(Package));
			memcpy(data, this, sizeof(Package));
		}
		void Package::DeSerialize(char* data)
		{
			//memcpy(&(this->m_chatString), data, sizeof(Package));
			memcpy(this, data, sizeof(Package));
		}
	}
}