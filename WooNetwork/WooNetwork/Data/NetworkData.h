#pragma once

#include <string>

namespace Woo {
	namespace Data {
		enum PackageType {
			INIT_CONNECTION = 0,
			ACTION_EVENT = 1,
		};
		struct Package {
			std::string m_chatString;

			unsigned int m_packageType;

			void Serialize(char* data);

			void DeSerialize(char* data);

		};
	}
}