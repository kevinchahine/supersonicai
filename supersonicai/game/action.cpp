#include "action.h"

#include "supersonicai/util/random.h"

using namespace std;

namespace supersonicai
{
	namespace game
	{
		// Index of each possible move.
		// These values are constant and should not be change at runtime.
		const size_t BUTTON_A = 0;
		const size_t STICK_UP = 4;
		const size_t STICK_DOWN = 5;
		const size_t STICK_LEFT = 6;
		const size_t STICK_RIGHT = 7;

		const std::array<std::bitset<12>, 8> Action::buttonTable = 
		{
			//0123456789TE
			//--- J><v^ --JJ
			0b000'00000'0000, // 0 - stand still
			0b000'00100'0000, // 1 - left
			0b000'01000'0000, // 2 - right
			0b000'11000'0000, // 3 - jump right
			0b000'10000'0000, // 4 - jump		
			0b000'10100'0000, // 5 - jump left
			0b000'00010'0000, // 6 - crouch/roll
			0b000'00001'0000, // 7 - lookup
		};

		Action::Action(int index) {
			buttons = buttonTable[index];
		}
		
		void Action::reset() { buttons.reset(); }

		void Action::standStill() { buttons.reset(); }

		void Action::jump() { buttons[BUTTON_A] = 1; }
		
		void Action::lookUp() { buttons[STICK_UP] = 1; }

		void Action::runRight() { buttons[STICK_RIGHT] = 1; }

		void Action::crouch() { buttons[STICK_DOWN] = 1; }
		
		void Action::runLeft() { buttons[STICK_LEFT] = 1; }

		void Action::random() {
			uniform_int_distribution<int> dist(0, buttons.size());

			int value = dist(util::g_dre);

			buttons = buttonTable[value];
		}
	} // namespace game
} // namespace supersonicai