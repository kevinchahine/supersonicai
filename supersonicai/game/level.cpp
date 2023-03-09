#include "level.h"

using namespace std;

namespace supersonicai
{
	namespace game
	{
		const std::string & Level::name() const {
			return _name;
		}

		const std::string & Level::stage() const {
			return _stage;
		}
	} // namespace game
} // namespace supersonicai