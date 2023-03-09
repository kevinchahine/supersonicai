#include "action.h"

using namespace std;

namespace supersonicai
{
	namespace game
	{
		void Action::reset() { buttons.reset(); /*pushRight();*/ }

		void Action::pushUp() { buttons[4] = 1; }
		
		void Action::pushRight() { buttons[7] = 1; }
		
		void Action::pushDown() { buttons[5] = 1; }
		
		void Action::pushLeft() { buttons[6] = 1; }
	} // namespace game
} // namespace supersonicai