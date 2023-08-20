#pragma once

#include <array>
#include <iostream>
#include <bitset>

#define NPY_NO_DEPRECIATED_API NPY_1_7_API_VERSION
#include "Python.h"

namespace supersonicai
{
	namespace game
	{
		class Action
		{
		public:

			Action() = default;
			Action(int index);
			Action(const Action &) = default;
			Action(Action &&) noexcept = default;
			~Action() noexcept = default;
			Action & operator=(const Action &) = default;
			Action & operator=(Action &&) noexcept = default;

			// Releases all buttons
			void reset();

			void standStill();

			void jump();

			void lookUp();

			void runRight();

			void crouch();

			void runLeft();

			void random();

			bool operator[](int index) const { return this->buttons[index]; }

			friend std::ostream & operator<<(std::ostream & os, const Action & action) {
				os << action.buttons;

				return os;
			}

			friend std::istream & operator>>(std::istream & is, Action & action) {
				is >> action.buttons;

				return is;
			}

		private:
			std::bitset<12> buttons;

			// look up table which maps action specified by an index [0, 7]
			// to a combination of button presses.
			// *** There is no way to control rolling left or right. ***
			// *** Momentum determines direction of roll. ***
			// *** Spin Dash doesn't come until SonicTheHedgehog2
			const static std::array<std::bitset<12>, 8> buttonTable;
		};
	} // namespace game
} // namespace supersonicai