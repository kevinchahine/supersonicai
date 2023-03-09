#pragma once

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
			// Releases all buttons
			void reset();

			void pushA();

			void pushUp();

			void pushUpRight();

			void pushRight();

			void pushDownRight();

			void pushDown();

			void pushDownLeft();

			void pushLeft();

			void pushUpLeft();

			bool operator[](int index) const { return this->buttons[index]; }

		private:
			std::bitset<12> buttons;
		};
	} // namespace game
} // namespace supersonicai